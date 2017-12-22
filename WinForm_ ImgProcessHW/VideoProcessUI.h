#pragma once
#include<stdlib.h>
#include<cliext\vector>
typedef unsigned int uint;
namespace WinForm_ImgProcessHW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Threading;
	using namespace std;
	/// <summary>
	/// VideoProcessUI 的摘要
	/// </summary>
	enum SearchMode
	{ 
		BBM,

	};
	enum CalculateMethod
	{
		MAD,
		MSD
	};
	public ref class VideoProcessUI : public System::Windows::Forms::Form
	{
	public:
		VideoProcessUI(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~VideoProcessUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::ComponentModel::IContainer^  components;
			 int MaskSize = 64;
	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
	
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  Btn_Play;

	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::PictureBox^ pictureBox_Reference;

	private: System::Windows::Forms::Timer^  timer1;
			 unsigned int rate=60;
			 unsigned int CurrentFrameNo;
			 Thread ^thread;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	public: System::Windows::Forms::PictureBox^  pictureBox_Current;
	private:

	private:
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::PictureBox^  pictureBox_Cand;

	private: System::Windows::Forms::PictureBox^  pictureBox_target;

	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Button^  encode_btn;
			 cliext::vector<Bitmap^>Video_Bitmap;
			 int SearchCode;
	private: System::Windows::Forms::PictureBox^  pictureBox_MotionVector;

			 int MatchCode;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VideoProcessUI::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->Btn_Play = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->pictureBox_Reference = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBox_Current = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox_Cand = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_target = (gcnew System::Windows::Forms::PictureBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->encode_btn = (gcnew System::Windows::Forms::Button());
			this->pictureBox_MotionVector = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Reference))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Current))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Cand))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_target))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_MotionVector))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1104, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->openToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openToolStripMenuItem.Image")));
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &VideoProcessUI::openToolStripMenuItem_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(391, 334);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 17);
			this->label2->TabIndex = 15;
			this->label2->Text = L"/ ---";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(369, 334);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 17);
			this->label1->TabIndex = 14;
			this->label1->Text = L"---";
			// 
			// button5
			// 
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button5->Location = System::Drawing::Point(323, 375);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(47, 48);
			this->button5->TabIndex = 9;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &VideoProcessUI::button5_Click);
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Location = System::Drawing::Point(252, 375);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(47, 48);
			this->button4->TabIndex = 10;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &VideoProcessUI::button4_Click);
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Location = System::Drawing::Point(28, 375);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(50, 48);
			this->button3->TabIndex = 11;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &VideoProcessUI::button3_Click);
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(104, 375);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(49, 48);
			this->button2->TabIndex = 12;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &VideoProcessUI::button2_Click);
			// 
			// Btn_Play
			// 
			this->Btn_Play->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Btn_Play.BackgroundImage")));
			this->Btn_Play->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Btn_Play->Location = System::Drawing::Point(183, 375);
			this->Btn_Play->Name = L"Btn_Play";
			this->Btn_Play->Size = System::Drawing::Size(47, 48);
			this->Btn_Play->TabIndex = 13;
			this->Btn_Play->UseVisualStyleBackColor = true;
			this->Btn_Play->Click += gcnew System::EventHandler(this, &VideoProcessUI::Btn_Play_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(2, 334);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(368, 45);
			this->trackBar1->TabIndex = 8;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &VideoProcessUI::trackBar1_Scroll);
			// 
			// pictureBox_Reference
			// 
			this->pictureBox_Reference->Location = System::Drawing::Point(12, 61);
			this->pictureBox_Reference->Name = L"pictureBox_Reference";
			this->pictureBox_Reference->Size = System::Drawing::Size(256, 256);
			this->pictureBox_Reference->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox_Reference->TabIndex = 7;
			this->pictureBox_Reference->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &VideoProcessUI::timer1_Tick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(584, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 17);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Curreut";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label9->Location = System::Drawing::Point(948, 334);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(34, 17);
			this->label9->TabIndex = 20;
			this->label9->Text = L"/ ---";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label8->Location = System::Drawing::Point(926, 334);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(26, 17);
			this->label8->TabIndex = 19;
			this->label8->Text = L"---";
			// 
			// pictureBox_Current
			// 
			this->pictureBox_Current->Location = System::Drawing::Point(597, 61);
			this->pictureBox_Current->Name = L"pictureBox_Current";
			this->pictureBox_Current->Size = System::Drawing::Size(256, 256);
			this->pictureBox_Current->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox_Current->TabIndex = 18;
			this->pictureBox_Current->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(12, 36);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 17);
			this->label4->TabIndex = 24;
			this->label4->Text = L"Reference";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"0.Mean Absolute Difference(MAD)", L"1.Mean Square Difference(MSD)",
					L"2.Pel Difference Classification(PDC)"
			});
			this->comboBox1->Location = System::Drawing::Point(721, 372);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 20);
			this->comboBox1->TabIndex = 25;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label11->Location = System::Drawing::Point(594, 375);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(121, 17);
			this->label11->TabIndex = 26;
			this->label11->Text = L"Matching Method:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(433, 205);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(105, 17);
			this->label6->TabIndex = 29;
			this->label6->Text = L"Candidate block";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(443, 91);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(82, 17);
			this->label5->TabIndex = 30;
			this->label5->Text = L"Target block";
			// 
			// pictureBox_Cand
			// 
			this->pictureBox_Cand->Location = System::Drawing::Point(446, 241);
			this->pictureBox_Cand->Name = L"pictureBox_Cand";
			this->pictureBox_Cand->Size = System::Drawing::Size(64, 64);
			this->pictureBox_Cand->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox_Cand->TabIndex = 27;
			this->pictureBox_Cand->TabStop = false;
			// 
			// pictureBox_target
			// 
			this->pictureBox_target->Location = System::Drawing::Point(446, 122);
			this->pictureBox_target->Name = L"pictureBox_target";
			this->pictureBox_target->Size = System::Drawing::Size(64, 64);
			this->pictureBox_target->TabIndex = 28;
			this->pictureBox_target->TabStop = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label12->Location = System::Drawing::Point(594, 406);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(103, 17);
			this->label12->TabIndex = 31;
			this->label12->Text = L"Search Method:";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"0.Block Based Motion", L"1.Two Dimensional Logarithmic Search (TDL)",
					L"2.Three Step Search (TSS)", L"3.Orthogonal Search Algorithm (OSA)", L"4.Cross Search Algorithm (CSA)"
			});
			this->comboBox2->Location = System::Drawing::Point(721, 402);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 20);
			this->comboBox2->TabIndex = 32;
			// 
			// encode_btn
			// 
			this->encode_btn->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->encode_btn->Location = System::Drawing::Point(865, 372);
			this->encode_btn->Name = L"encode_btn";
			this->encode_btn->Size = System::Drawing::Size(87, 40);
			this->encode_btn->TabIndex = 33;
			this->encode_btn->Text = L"Encode";
			this->encode_btn->UseVisualStyleBackColor = true;
			this->encode_btn->Click += gcnew System::EventHandler(this, &VideoProcessUI::encode_btn_Click);
			// 
			// pictureBox_MotionVector
			// 
			this->pictureBox_MotionVector->Location = System::Drawing::Point(12, 545);
			this->pictureBox_MotionVector->Name = L"pictureBox_MotionVector";
			this->pictureBox_MotionVector->Size = System::Drawing::Size(256, 226);
			this->pictureBox_MotionVector->TabIndex = 34;
			this->pictureBox_MotionVector->TabStop = false;
			// 
			// VideoProcessUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1104, 840);
			this->Controls->Add(this->pictureBox_MotionVector);
			this->Controls->Add(this->encode_btn);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox_Cand);
			this->Controls->Add(this->pictureBox_target);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->pictureBox_Current);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->Btn_Play);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->pictureBox_Reference);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"VideoProcessUI";
			this->Text = L"VideoProcessUI";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Reference))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Current))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Cand))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_target))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_MotionVector))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
		openFileDialog1->Multiselect = true;
		openFileDialog1->FileName = nullptr;
		System::Windows::Forms::DialogResult result = openFileDialog1->ShowDialog();
		cli::array<String^>^ openFileName = openFileDialog1->FileNames;
		if (result == System::Windows::Forms::DialogResult::OK) {
			for (unsigned int i = 0; i < openFileName->Length; i++)//按照載入圖像的數量增加List的記憶體空間
			{
				Video_Bitmap.push_back(gcnew Bitmap(openFileName[i]));
			}
		}
		trackBar1->Maximum = Video_Bitmap.size();
		label2->Text="/"+Video_Bitmap.size().ToString();
	}
	private: System::Void Btn_Play_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = true;//timer1啟動
		rate = 60;//速率
		timer1->Interval = rate;//時間間隔秒數(毫秒)
	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (CurrentFrameNo >= Video_Bitmap.size())//如果計算圖像的計數大於等於圖像總張數
	{
		timer1->Enabled = false;//timer1關閉
		CurrentFrameNo = 0;//計數歸零
	}
	pictureBox_Reference->Image = Video_Bitmap[CurrentFrameNo];//picture顯示video_bitmap隨著trackBar1而變動的圖像
	label1->Text = Convert::ToString(CurrentFrameNo + 1);//顯示目前為第n張圖
	trackBar1->Value = CurrentFrameNo;//trackBar1的值隨著計算圖像的計數而變動
	CurrentFrameNo++;//累加計數
}
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	CurrentFrameNo = trackBar1->Value;//img_position等於trackBar1目前的值
	pictureBox_Reference->Image = Video_Bitmap[CurrentFrameNo];//picture顯示video_bitmap隨著trackBar1而變動的圖像
	label1->Text = Convert::ToString(CurrentFrameNo + 1);//顯示目前為第n張圖
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = false;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = false;
	timer1->Stop();
	rate = rate - 10;
	if (rate<10)
		rate = 10;
	timer1->Interval = rate;
	timer1->Enabled = true;
	timer1->Start();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = false;
	timer1->Stop();
	rate = rate + 10;
	if (rate>100)
		rate = 100;
	timer1->Interval = rate;
	timer1->Enabled = true;
	timer1->Start();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = false;
	CurrentFrameNo = 0;
	pictureBox_Reference->Image = Video_Bitmap[CurrentFrameNo];
	label1->Text = Convert::ToString(CurrentFrameNo + 1);
	trackBar1->Value = CurrentFrameNo;
}
delegate void SetPictureDelegate(System::Windows::Forms::PictureBox^ PBox, Bitmap^Image, size_t i, size_t j, bool drawRect);
public:void ShowImage(System::Windows::Forms::PictureBox^ PBox, Bitmap^b,size_t i,size_t j,bool drawRect)
{
		System::Drawing::Graphics^ graphics = PBox->CreateGraphics();
		System::Drawing::RectangleF rect(0, 0, PBox->Width, PBox->Height);
		graphics->DrawImage(b, rect);
		if (drawRect)
		{
			Pen^ ReferencePen = gcnew Pen(Color::Red, 2.0F);
			graphics->DrawRectangle(ReferencePen,i,j, MaskSize, MaskSize);
		}
		delete graphics;
}
private:uint MatchMethodCaculate(Bitmap^ %src1,Bitmap ^%src2)
{
	uint Sum = 0;
	switch (MatchCode)
	{
	case MAD:
		for (uint j = 0; j<MaskSize; j++)
			for (uint i = 0; i < MaskSize; i++)
			{
				Sum += abs(src1->GetPixel(i,j).R- src2->GetPixel(i, j).R);
			}
		break;
	case MSD:
		for (uint j = 0; j<MaskSize; j++)
			for (uint i = 0; i < MaskSize; i++)
			{
				Sum += Math::Pow(src1->GetPixel(i, j).R - src2->GetPixel(i, j).R,2);
			}
		break;
		break;
	default:
		break;
	}
	return Sum;
}
 private:void Encoding()
{
	
  for (unsigned int k = 0; k < Video_Bitmap.size()-1; k++)
	{
	  for (unsigned int targ_y_Index = 0; targ_y_Index <Video_Bitmap[0]->Height; targ_y_Index += MaskSize)
	  {
		  for (unsigned int targ_x_Index = 0; targ_x_Index <Video_Bitmap[0]->Width ; targ_x_Index += MaskSize)
		  {
			  Bitmap^ temp = gcnew Bitmap(MaskSize, MaskSize);
			  Rectangle cloneRect = Rectangle(targ_x_Index, targ_y_Index, MaskSize, MaskSize);
			  temp = Video_Bitmap[k+1]->Clone(cloneRect, Video_Bitmap[k + 1]->PixelFormat);
			  ShowImage(pictureBox_target,temp,targ_x_Index,targ_y_Index,false);
			  ShowImage(pictureBox_Current, Video_Bitmap[k + 1], targ_x_Index, targ_y_Index,true);

			  uint Score = 4294967295;
			  Point Minum;
			  switch (SearchCode)
			  {
			  case BBM:
				  for (unsigned int cand_y_Index = 0; cand_y_Index < Video_Bitmap[0]->Height -(MaskSize -1); cand_y_Index += 1)
				  {
					  for (unsigned int cand_x_Index = 0; cand_x_Index < Video_Bitmap[0]->Width-(MaskSize -1); cand_x_Index += 1)
					  {
						  Bitmap^ temp2 = gcnew Bitmap(MaskSize, MaskSize);
						  Rectangle cloneRect2 = Rectangle(cand_x_Index, cand_y_Index, MaskSize, MaskSize);
						  temp2 = Video_Bitmap[k]->Clone(cloneRect2, Video_Bitmap[k]->PixelFormat);
						  ShowImage(pictureBox_Cand,temp2, cand_x_Index, cand_y_Index, false);
						  ShowImage(pictureBox_Reference,Video_Bitmap[k], cand_x_Index, cand_y_Index, true);
						  uint temp_Score = MatchMethodCaculate(temp, temp2);
						  if (temp_Score <Score)
						  {
							  Score = temp_Score;
							  Minum = Point(cand_x_Index, cand_y_Index);
						  }
						  delete temp2;
					  }
				  }
				  
				  break;
			  default:
				  break;
			  }
		  }
		 
	  }
	
	}
}
private: System::Void encode_btn_Click(System::Object^  sender, System::EventArgs^  e) {
	System::String ^str=comboBox1->Text->Substring(0,1);
	 MatchCode =  Convert::ToInt16(str);
	str=comboBox2->Text->Substring(0, 1);
	SearchCode = Convert::ToInt16(str);
    thread = gcnew Thread(gcnew ThreadStart(this,&VideoProcessUI::Encoding));
	thread->Start();
}

};
}
