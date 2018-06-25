namespace CompSciChat
{
    partial class Chat
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
            this.Output = new System.Windows.Forms.TextBox();
            this.Timer = new System.Windows.Forms.Timer(this.components);
            this.Question = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // Output
            // 
            this.Output.BackColor = System.Drawing.Color.Black;
            this.Output.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Output.ForeColor = System.Drawing.Color.DodgerBlue;
            this.Output.Location = new System.Drawing.Point(12, 150);
            this.Output.Multiline = true;
            this.Output.Name = "Output";
            this.Output.ReadOnly = true;
            this.Output.Size = new System.Drawing.Size(604, 213);
            this.Output.TabIndex = 0;
            // 
            // Timer
            // 
            this.Timer.Enabled = true;
            this.Timer.Interval = 250;
            this.Timer.Tick += new System.EventHandler(this.Timer_Tick);
            // 
            // Question
            // 
            this.Question.AcceptsReturn = true;
            this.Question.BackColor = System.Drawing.Color.Black;
            this.Question.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Question.ForeColor = System.Drawing.Color.Green;
            this.Question.Location = new System.Drawing.Point(54, 99);
            this.Question.Name = "Question";
            this.Question.Size = new System.Drawing.Size(562, 30);
            this.Question.TabIndex = 1;
            this.Question.KeyUp += new System.Windows.Forms.KeyEventHandler(this.Question_KeyUp);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.LawnGreen;
            this.label1.Location = new System.Drawing.Point(12, 99);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 32);
            this.label1.TabIndex = 2;
            this.label1.Text = "Q";
            // 
            // Chat
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.BackgroundImage = global::CompSciChat.Properties.Resources.Binary;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(628, 380);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Question);
            this.Controls.Add(this.Output);
            this.Name = "Chat";
            this.Text = "Computer Science Bot";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox Output;
        private System.Windows.Forms.Timer Timer;
        private System.Windows.Forms.TextBox Question;
        private System.Windows.Forms.Label label1;
    }
}

