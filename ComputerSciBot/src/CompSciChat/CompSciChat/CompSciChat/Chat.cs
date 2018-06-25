using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.IO;
using System.Windows.Forms;

namespace CompSciChat
{
    public partial class Chat : Form
    {
        Process chatBot = null;     //Object Representing ChatBot Python Process
        Queue<string> messageQueue; //Queue of ChatBot Output, Waiting to Be Processed to Screen
        bool botReady = false;      //Current State of Bot [Ready/Not Ready]

        public Chat()
        {
            messageQueue = new Queue<string>();
            InitiateChatBot();
            InitializeComponent();
        }

        public void InitiateChatBot()
        {
            //Setup CMD.exe Process, Redirect I/O
            chatBot = new Process();
            chatBot.StartInfo.FileName = "CMD.exe";
            chatBot.StartInfo.Arguments = "";
            chatBot.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
            chatBot.StartInfo.CreateNoWindow = true;
            chatBot.StartInfo.UseShellExecute = false;
            chatBot.StartInfo.RedirectStandardInput = true;
            chatBot.StartInfo.RedirectStandardOutput = true;
            chatBot.StartInfo.RedirectStandardError = true;
            chatBot.OutputDataReceived += ChatBot_OutputDataReceived;
            chatBot.Start();
            chatBot.StandardInput.NewLine = Environment.NewLine;
            chatBot.BeginOutputReadLine();
            //Launch Python Interpreter (ChatBot.py)
            chatBot.StandardInput.WriteLine("echo off");
            chatBot.StandardInput.WriteLine("python.exe -i C:\\ChatBot_Exe\\ChatBot.py");
        }

        private void ChatBot_OutputDataReceived(object sender, DataReceivedEventArgs e)
        {
            //Enqueue Response if Bot is Ready
            if (botReady) { messageQueue.Enqueue(e.Data); }
            else
            {
                //Flag Bot as Ready if Returns "[READY]" to Standard Output Stream
                botReady = (e.Data == "[READY]");
            }
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            //Append Queue Data to Screen (This Fixes Multi-Thread Issues)
            for (int q = 0; q < messageQueue.Count(); q++)
            {
                //Draw Message to Screen
                Output.Text = messageQueue.Dequeue() + Environment.NewLine;
            }
        }

        private void Question_KeyUp(object sender, KeyEventArgs e)
        {
            //Submit Question to ChatBot
            if (e.KeyCode == Keys.Enter)
            {
                chatBot.StandardInput.WriteLine(Question.Text);
            }
        }
    }
}
