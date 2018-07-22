using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;
using System.Windows.Forms;

namespace SmartShell
{
    public partial class SmartShell : Form
    {
        Process cmd = null;
        Process pyAI = null;
        Queue<string> messageQueue;
        string lastCMD, lastArg, lastResp;
        bool rdy = false;

        //Classifications from Python, Mapped to CMDs
        Dictionary<string, string> cmdTable = new Dictionary<string, string>()
        {
            { "Run?",                           ""                  },
            { "Open folder?",                   "cd"                },
            { "Return to parent directory?",    "cd .."             },
            { "List files in this directory?",  "dir"               },
            { "Move file?",                     "move /Y"           },
            { "Copy file?",                     "copy /Y"           },
            { "Show Current Directory?",        "echo %CD%"         },
            { "Show Environment Path?",         "echo %PATH%"       },
            { "Show Last Return Value?",        "echo %ERRORLEVEL%" },
            { "Show Help?",                     "help"              },
            { "Clear Screen?",                  "cls"               },
            { "Go Home?",                       "cd C:/"            }, 
        };

        public SmartShell()
        {
            Directory.SetCurrentDirectory("C:\\PyAI");
            messageQueue = new Queue<string>();
            lastResp = "";
            LaunchCMD();
            LaunchPyAI();
            InitializeComponent();
            InputBox.Focus();
        }

        public void LaunchCMD()
        {
            //Setup CMD.exe Process, Redirect I/O
            cmd = new Process();
            cmd.StartInfo.FileName = "CMD.exe";
            cmd.StartInfo.Arguments = "";
            cmd.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
            cmd.StartInfo.CreateNoWindow = true;
            cmd.StartInfo.UseShellExecute = false;
            cmd.StartInfo.RedirectStandardInput = true;
            cmd.StartInfo.RedirectStandardOutput = true;
            cmd.StartInfo.RedirectStandardError = true;
            cmd.OutputDataReceived += CMD_OutputDataReceived;
            cmd.Start();
            cmd.StandardInput.NewLine = Environment.NewLine;
            cmd.BeginOutputReadLine();
        }

        public void LaunchPyAI()
        {
            //Setup CMD.exe Process, Redirect I/O
            pyAI = new Process();
            pyAI.StartInfo.FileName = "CMD.exe";
            pyAI.StartInfo.Arguments = "";
            pyAI.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
            pyAI.StartInfo.CreateNoWindow = true;
            pyAI.StartInfo.UseShellExecute = false;
            pyAI.StartInfo.RedirectStandardInput = true;
            pyAI.StartInfo.RedirectStandardOutput = true;
            pyAI.StartInfo.RedirectStandardError = true;
            pyAI.OutputDataReceived += PyAI_OutputDataReceived;
            pyAI.Start();
            pyAI.StandardInput.NewLine = Environment.NewLine;
            pyAI.BeginOutputReadLine();
            //Launch Python Interpreter
            pyAI.StandardInput.WriteLine("echo off");
            pyAI.StandardInput.WriteLine("python.exe -i C:\\PyAI\\bot.py");
        }

        private void PyAI_OutputDataReceived(object sender, DataReceivedEventArgs e)
        {
            //Load Last Response Information from Python Classification Response
            if (rdy) { lastResp = e.Data; }
            else if (e.Data == "START") { rdy = true; }
        }

        private void CMD_OutputDataReceived(object sender, DataReceivedEventArgs e)
        {
            //Direct CMD Prompt Output Directly to Screen
            messageQueue.Enqueue(e.Data);
        }

        private void btnCurrentDir_Click(object sender, EventArgs e) { cmd.StandardInput.WriteLine("echo %CD%"); }

        private void btnRet_Click(object sender, EventArgs e) { cmd.StandardInput.WriteLine("echo %ERRORLEVEL%"); }

        private void btnIP_Click(object sender, EventArgs e) { cmd.StandardInput.WriteLine("ipconfig"); }

        private void btnHelp_Click(object sender, EventArgs e) { cmd.StandardInput.WriteLine("help"); }

        private void btnBack_Click(object sender, EventArgs e) { cmd.StandardInput.WriteLine("cd .."); }

        private void btnSys_Click(object sender, EventArgs e) { cmd.StandardInput.WriteLine("systeminfo"); }

        private void btnCls_Click(object sender, EventArgs e) { OutputBox.Clear(); }

        private void Timer_Tick(object sender, EventArgs e)
        {
            //Check if Python Bot Ready, Enable OutputBox
            if (!OutputBox.Enabled && rdy) { OutputBox.Enabled = true; }
            //Append Queue Data to Screen (This Fixes Multi-Thread Issues)
            for (int q = 0; q < messageQueue.Count(); q++)
            { OutputBox.AppendText(messageQueue.Dequeue() + Environment.NewLine); }

            if (lastResp != "") //Previous Interpretation Exists from Python
            {
                //Convert Python Interpretation into Usable BATCH Command
                //Send to CMD.exe ...
                if (cmdTable[lastResp] == "cls") //Special "Clear Screen CMD"
                { OutputBox.Clear(); }
                else //Normal Execute
                { cmd.StandardInput.WriteLine(cmdTable[lastResp] + " " + lastArg); }

                //Reset Fields
                lastResp = "";
                InputBox.ResetText();
                return;
            }
        }

        private void InputBox_KeyDown(object sender, KeyEventArgs e)
        {
            //Send Command to Python for 'Interpretation'/'Classification'
            if (e.KeyCode == Keys.Enter)
            {
                //On Enter, Split Input
                char[] delim = { ':', '|' };
                char[] whiteSpace = { ' ', '\n', '\r', '\t' };
                string[] vals = InputBox.Text.Split(delim);
                //Continue if InputBox is Not Empty
                if (vals.Length > 0)
                {
                    //Isolate Command and Argument Portions
                    lastCMD = vals[0];
                    lastArg = (vals.Length == 2) ? vals[1] : "";
                    //Trim Left and Right Whitespace
                    lastCMD = lastCMD.TrimStart(whiteSpace); lastCMD = lastCMD.TrimEnd(whiteSpace);
                    lastArg = lastArg.TrimStart(whiteSpace); lastArg = lastArg.TrimEnd(whiteSpace);

                    //Write to Python AI
                    pyAI.StandardInput.WriteLine(lastCMD);
                    //Suppress Key WinSound + Clear Input Box
                    e.SuppressKeyPress = true;
                    return;
                }
            }

            //Otherwise, Do Nothing, Likely Typing Normally into InputBox
            base.OnKeyDown(e);
        }
    }
}
