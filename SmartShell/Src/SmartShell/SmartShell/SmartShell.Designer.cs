namespace SmartShell
{
    partial class SmartShell
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SmartShell));
            this.OutputBox = new System.Windows.Forms.TextBox();
            this.InputBox = new System.Windows.Forms.TextBox();
            this.Verify = new System.Windows.Forms.Label();
            this.Timer = new System.Windows.Forms.Timer(this.components);
            this.label1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.btnCurrentDir = new System.Windows.Forms.Button();
            this.btnBack = new System.Windows.Forms.Button();
            this.btnHelp = new System.Windows.Forms.Button();
            this.btnRet = new System.Windows.Forms.Button();
            this.btnIP = new System.Windows.Forms.Button();
            this.btnSys = new System.Windows.Forms.Button();
            this.btnCls = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // OutputBox
            // 
            this.OutputBox.BackColor = System.Drawing.Color.Black;
            this.OutputBox.Enabled = false;
            this.OutputBox.Font = new System.Drawing.Font("Consolas", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.OutputBox.ForeColor = System.Drawing.Color.Cyan;
            this.OutputBox.Location = new System.Drawing.Point(0, 0);
            this.OutputBox.Multiline = true;
            this.OutputBox.Name = "OutputBox";
            this.OutputBox.ReadOnly = true;
            this.OutputBox.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.OutputBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.OutputBox.Size = new System.Drawing.Size(777, 689);
            this.OutputBox.TabIndex = 0;
            // 
            // InputBox
            // 
            this.InputBox.AcceptsReturn = true;
            this.InputBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.InputBox.BackColor = System.Drawing.Color.Black;
            this.InputBox.Font = new System.Drawing.Font("Consolas", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.InputBox.ForeColor = System.Drawing.Color.Cyan;
            this.InputBox.Location = new System.Drawing.Point(49, 696);
            this.InputBox.Name = "InputBox";
            this.InputBox.Size = new System.Drawing.Size(719, 29);
            this.InputBox.TabIndex = 1;
            this.InputBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.InputBox_KeyDown);
            // 
            // Verify
            // 
            this.Verify.AutoSize = true;
            this.Verify.BackColor = System.Drawing.Color.Black;
            this.Verify.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Verify.ForeColor = System.Drawing.Color.Cyan;
            this.Verify.Location = new System.Drawing.Point(12, 531);
            this.Verify.Name = "Verify";
            this.Verify.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.Verify.Size = new System.Drawing.Size(0, 23);
            this.Verify.TabIndex = 2;
            // 
            // Timer
            // 
            this.Timer.Enabled = true;
            this.Timer.Interval = 250;
            this.Timer.Tick += new System.EventHandler(this.Timer_Tick);
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Consolas", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.DarkSlateGray;
            this.label1.Location = new System.Drawing.Point(20, 692);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(30, 33);
            this.label1.TabIndex = 3;
            this.label1.Text = ">";
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.DimGray;
            this.panel1.Controls.Add(this.btnCls);
            this.panel1.Controls.Add(this.btnSys);
            this.panel1.Controls.Add(this.btnIP);
            this.panel1.Controls.Add(this.btnRet);
            this.panel1.Controls.Add(this.btnHelp);
            this.panel1.Controls.Add(this.btnBack);
            this.panel1.Controls.Add(this.btnCurrentDir);
            this.panel1.Location = new System.Drawing.Point(774, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(162, 736);
            this.panel1.TabIndex = 4;
            // 
            // btnCurrentDir
            // 
            this.btnCurrentDir.BackColor = System.Drawing.Color.DarkSlateGray;
            this.btnCurrentDir.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnCurrentDir.ForeColor = System.Drawing.Color.White;
            this.btnCurrentDir.Location = new System.Drawing.Point(9, 12);
            this.btnCurrentDir.Name = "btnCurrentDir";
            this.btnCurrentDir.Size = new System.Drawing.Size(146, 51);
            this.btnCurrentDir.TabIndex = 0;
            this.btnCurrentDir.Text = "Current Directory";
            this.btnCurrentDir.UseVisualStyleBackColor = false;
            this.btnCurrentDir.Click += new System.EventHandler(this.btnCurrentDir_Click);
            // 
            // btnBack
            // 
            this.btnBack.BackColor = System.Drawing.Color.DarkSlateGray;
            this.btnBack.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnBack.ForeColor = System.Drawing.Color.White;
            this.btnBack.Location = new System.Drawing.Point(9, 90);
            this.btnBack.Name = "btnBack";
            this.btnBack.Size = new System.Drawing.Size(146, 51);
            this.btnBack.TabIndex = 1;
            this.btnBack.Text = "Go Back Directory";
            this.btnBack.UseVisualStyleBackColor = false;
            this.btnBack.Click += new System.EventHandler(this.btnBack_Click);
            // 
            // btnHelp
            // 
            this.btnHelp.BackColor = System.Drawing.Color.DarkSlateGray;
            this.btnHelp.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnHelp.ForeColor = System.Drawing.Color.White;
            this.btnHelp.Location = new System.Drawing.Point(9, 257);
            this.btnHelp.Name = "btnHelp";
            this.btnHelp.Size = new System.Drawing.Size(146, 51);
            this.btnHelp.TabIndex = 2;
            this.btnHelp.Text = "Show Help";
            this.btnHelp.UseVisualStyleBackColor = false;
            this.btnHelp.Click += new System.EventHandler(this.btnHelp_Click);
            // 
            // btnRet
            // 
            this.btnRet.BackColor = System.Drawing.Color.DarkSlateGray;
            this.btnRet.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnRet.ForeColor = System.Drawing.Color.White;
            this.btnRet.Location = new System.Drawing.Point(9, 169);
            this.btnRet.Name = "btnRet";
            this.btnRet.Size = new System.Drawing.Size(146, 51);
            this.btnRet.TabIndex = 3;
            this.btnRet.Text = "Return Status";
            this.btnRet.UseVisualStyleBackColor = false;
            this.btnRet.Click += new System.EventHandler(this.btnRet_Click);
            // 
            // btnIP
            // 
            this.btnIP.BackColor = System.Drawing.Color.DarkSlateGray;
            this.btnIP.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnIP.ForeColor = System.Drawing.Color.White;
            this.btnIP.Location = new System.Drawing.Point(9, 399);
            this.btnIP.Name = "btnIP";
            this.btnIP.Size = new System.Drawing.Size(146, 51);
            this.btnIP.TabIndex = 4;
            this.btnIP.Text = "Tool: IPConfig";
            this.btnIP.UseVisualStyleBackColor = false;
            this.btnIP.Click += new System.EventHandler(this.btnIP_Click);
            // 
            // btnSys
            // 
            this.btnSys.BackColor = System.Drawing.Color.DarkSlateGray;
            this.btnSys.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSys.ForeColor = System.Drawing.Color.White;
            this.btnSys.Location = new System.Drawing.Point(9, 484);
            this.btnSys.Name = "btnSys";
            this.btnSys.Size = new System.Drawing.Size(146, 51);
            this.btnSys.TabIndex = 5;
            this.btnSys.Text = "Tool: SystemInfo";
            this.btnSys.UseVisualStyleBackColor = false;
            this.btnSys.Click += new System.EventHandler(this.btnSys_Click);
            // 
            // btnCls
            // 
            this.btnCls.BackColor = System.Drawing.Color.DarkSlateGray;
            this.btnCls.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnCls.ForeColor = System.Drawing.Color.White;
            this.btnCls.Location = new System.Drawing.Point(9, 674);
            this.btnCls.Name = "btnCls";
            this.btnCls.Size = new System.Drawing.Size(146, 51);
            this.btnCls.TabIndex = 6;
            this.btnCls.Text = "Clear Screen";
            this.btnCls.UseVisualStyleBackColor = false;
            this.btnCls.Click += new System.EventHandler(this.btnCls_Click);
            // 
            // SmartShell
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(937, 737);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Verify);
            this.Controls.Add(this.InputBox);
            this.Controls.Add(this.OutputBox);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "SmartShell";
            this.Text = "SmartShell";
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox OutputBox;
        private System.Windows.Forms.TextBox InputBox;
        private System.Windows.Forms.Label Verify;
        private System.Windows.Forms.Timer Timer;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button btnCurrentDir;
        private System.Windows.Forms.Button btnIP;
        private System.Windows.Forms.Button btnRet;
        private System.Windows.Forms.Button btnHelp;
        private System.Windows.Forms.Button btnBack;
        private System.Windows.Forms.Button btnSys;
        private System.Windows.Forms.Button btnCls;
    }
}

