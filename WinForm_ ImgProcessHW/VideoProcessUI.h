#pragma once
#include<stdlib.h>
#include<cliext\vector>
#include<fstream>
#include<string>
typedef unsigned int uint;
namespace WinForm_ImgProcessHW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace Threading;
	using namespace std;
	
	/// <summary>
	/// VideoProcessUI ���K�n
	/// </summary>
	enum SearchMode
	{ 
		BBM,TDL

	};
	enum CalculateMethod
	{
		MAD,
		MSD,
		PDC
	};
	public ref class VideoProcessUI : public System::Windows::Forms::Form
	{
	public:
		VideoProcessUI(void)
		{
			InitializeComponent();
			//
			//TODO:  �b���[�J�غc�禡�{���X
			//
		}
	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
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
			 int MaskSize = 48;
	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
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
			 uint PDCthreshold = 0;
			 Thread ^thread;
	private: System::Windows::Forms::Label^  label3;

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
			 Graphics ^graph_MotionVect;
	private: System::Windows::Forms::PictureBox^  pictureBox_MotionVector;
			 System::String^ FileName;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  Btn_Decode;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  tBOX_Threshold;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart_PSNR;
	private: System::Windows::Forms::Button^  BtnDecode_Play;
			 cliext::vector<Bitmap^>Video_Bitmap_Decode;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label10;
			 int MatchCode;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VideoProcessUI::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Btn_Decode = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tBOX_Threshold = (gcnew System::Windows::Forms::Label());
			this->chart_PSNR = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->BtnDecode_Play = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Reference))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Current))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Cand))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_target))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_MotionVector))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_PSNR))->BeginInit();
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
			this->openToolStripMenuItem->Size = System::Drawing::Size(106, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &VideoProcessUI::openToolStripMenuItem_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->label1->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->trackBar1->Maximum = 100;
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
			this->label3->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(584, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 17);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Curreut";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->label4->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &VideoProcessUI::comboBox1_SelectedIndexChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->label6->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->label5->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->label12->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label12->Location = System::Drawing::Point(612, 406);
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
			this->encode_btn->Enabled = false;
			this->encode_btn->Font = (gcnew System::Drawing::Font(L"�L�n������", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->pictureBox_MotionVector->Location = System::Drawing::Point(12, 510);
			this->pictureBox_MotionVector->Name = L"pictureBox_MotionVector";
			this->pictureBox_MotionVector->Size = System::Drawing::Size(256, 226);
			this->pictureBox_MotionVector->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox_MotionVector->TabIndex = 34;
			this->pictureBox_MotionVector->TabStop = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(13, 474);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(70, 12);
			this->label7->TabIndex = 35;
			this->label7->Text = L"MotionVector";
			// 
			// Btn_Decode
			// 
			this->Btn_Decode->Font = (gcnew System::Drawing::Font(L"�L�n������", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Btn_Decode->Location = System::Drawing::Point(865, 428);
			this->Btn_Decode->Name = L"Btn_Decode";
			this->Btn_Decode->Size = System::Drawing::Size(87, 37);
			this->Btn_Decode->TabIndex = 36;
			this->Btn_Decode->Text = L"Decode";
			this->Btn_Decode->UseVisualStyleBackColor = true;
			this->Btn_Decode->Click += gcnew System::EventHandler(this, &VideoProcessUI::Btn_Decode_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(721, 428);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 37;
			this->textBox1->Text = L"64";
			this->textBox1->Visible = false;
			// 
			// tBOX_Threshold
			// 
			this->tBOX_Threshold->AutoSize = true;
			this->tBOX_Threshold->Font = (gcnew System::Drawing::Font(L"�L�n������", 9));
			this->tBOX_Threshold->Location = System::Drawing::Point(616, 434);
			this->tBOX_Threshold->Name = L"tBOX_Threshold";
			this->tBOX_Threshold->Size = System::Drawing::Size(99, 16);
			this->tBOX_Threshold->TabIndex = 38;
			this->tBOX_Threshold->Text = L"ThresholdValue:";
			this->tBOX_Threshold->Visible = false;
			// 
			// chart_PSNR
			// 
			chartArea1->AxisX->Interval = 1;
			chartArea1->AxisX->Minimum = 0;
			chartArea1->AxisY->Maximum = 1000;
			chartArea1->AxisY->Minimum = 0;
			chartArea1->Name = L"ChartArea1";
			this->chart_PSNR->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart_PSNR->Legends->Add(legend1);
			this->chart_PSNR->Location = System::Drawing::Point(475, 529);
			this->chart_PSNR->Name = L"chart_PSNR";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->Name = L"PSNR_S";
			this->chart_PSNR->Series->Add(series1);
			this->chart_PSNR->Size = System::Drawing::Size(538, 256);
			this->chart_PSNR->TabIndex = 39;
			this->chart_PSNR->Text = L"chart1";
			// 
			// BtnDecode_Play
			// 
			this->BtnDecode_Play->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BtnDecode_Play.Image")));
			this->BtnDecode_Play->Location = System::Drawing::Point(183, 440);
			this->BtnDecode_Play->Name = L"BtnDecode_Play";
			this->BtnDecode_Play->Size = System::Drawing::Size(47, 46);
			this->BtnDecode_Play->TabIndex = 40;
			this->BtnDecode_Play->UseVisualStyleBackColor = true;
			this->BtnDecode_Play->Visible = false;
			this->BtnDecode_Play->Click += gcnew System::EventHandler(this, &VideoProcessUI::BtnDecode_Play_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(721, 344);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 41;
			this->textBox2->Text = L"64";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(644, 354);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(52, 12);
			this->label10->TabIndex = 42;
			this->label10->Text = L"BlockSize";
			// 
			// VideoProcessUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1104, 840);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->BtnDecode_Play);
			this->Controls->Add(this->chart_PSNR);
			this->Controls->Add(this->tBOX_Threshold);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->Btn_Decode);
			this->Controls->Add(this->label7);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_PSNR))->EndInit();
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
			for (unsigned int i = 0; i < openFileName->Length; i++)
			{
				Video_Bitmap.push_back(gcnew Bitmap(openFileName[i]));
			}
		}
		trackBar1->Maximum = Video_Bitmap.size();
		label2->Text="/"+Video_Bitmap.size().ToString();
	}
private: System::Void Btn_Play_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = true;//timer1�Ұ�
		rate = 60;//�t�v
		timer1->Interval = rate;//�ɶ����j���(�@��)
	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (CurrentFrameNo >= Video_Bitmap.size())//�p�G�p��Ϲ����p�Ƥj�󵥩�Ϲ��`�i��
	{
		timer1->Enabled = false;//timer1����
		CurrentFrameNo = 0;//�p���k�s
	}
	pictureBox_Reference->Image = Video_Bitmap[CurrentFrameNo];//picture���video_bitmap�H��trackBar1���ܰʪ��Ϲ�
	label1->Text = Convert::ToString(CurrentFrameNo + 1);//��ܥثe����n�i��
	trackBar1->Value = CurrentFrameNo;//trackBar1�����H�ۭp��Ϲ����p�Ʀ��ܰ�
	CurrentFrameNo++;//�֥[�p��
}
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	CurrentFrameNo = trackBar1->Value;//img_position����trackBar1�ثe����
	if (CurrentFrameNo <= Video_Bitmap.size())
	{
		pictureBox_Reference->Image = Video_Bitmap[CurrentFrameNo];//picture���video_bitmap�H��trackBar1���ܰʪ��Ϲ�
		label1->Text = Convert::ToString(CurrentFrameNo + 1);//��ܥثe����n�i��
	}
}
delegate void SetLabel(System::String^ str);
void SetLabelText(System::String^ str)
{
	if (this->label8->InvokeRequired)
	{
		SetLabel ^d = gcnew SetLabel(this, &VideoProcessUI::SetLabelText);
		this->Invoke(d, gcnew cli::array<Object^> { str });
	}
	else
	{
		this->label8->Text = str;
		this->label8->Refresh();
	}
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
delegate void DrawMotionVector(System::Windows::Forms::PictureBox^ PBox,Point P1,Point P2);
public:void DrawArrow(PictureBox^ PBox, Point P1, Point P2)
{
	
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
	case PDC:
		for(uint j=0;j<MaskSize;j++)
			for (uint i = 0; i < MaskSize; i++)
			{
				if (abs(src1->GetPixel(i, j).R - src2->GetPixel(i, j).R) <= PDCthreshold)
				{
					Sum++;
				}
			}
		Sum = (MaskSize*MaskSize) - Sum;
		break;
	default:
		break;
	}
	return Sum;
}
 private:void Encoding()
{
	 
	fstream fp;
	cliext::vector<Point> motionVector;
	
  for (unsigned int k = 0; k < Video_Bitmap.size()-1; k++)
	{
	  SetLabelText((k+1).ToString()+"/"+Video_Bitmap.size().ToString());
	  
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
				  motionVector.push_back(Point(Minum.X - targ_x_Index, Minum.Y - targ_y_Index));
				  break;
			   case TDL:
			   {   
				 Point Center = Point(targ_x_Index, targ_y_Index);
				 Point candidate_winner;
				 int s = 4;
			    while (s >=1)
			    {
					Score = 4294967295;
					for (int i = -1; i < 2; i++)
					{
						for (int j = -1; j < 2; j++)
						{
							if ((i == 0 && j == 0) || (abs(i)+ abs(j)==1))
							{
								int cand_x_Index = Center.X + i*s*MaskSize;
								int cand_y_Index = Center.Y + j*s*MaskSize;
								if (0 <= cand_x_Index && cand_x_Index < Video_Bitmap[k]->Width && 0 <= cand_y_Index && cand_y_Index < Video_Bitmap[k]->Height)
								{
									Bitmap^ temp2 = gcnew Bitmap(MaskSize, MaskSize);
									Rectangle cloneRect2 = Rectangle(cand_x_Index, cand_y_Index, MaskSize, MaskSize);
									temp2 = Video_Bitmap[k]->Clone(cloneRect2, Video_Bitmap[k]->PixelFormat);
									ShowImage(pictureBox_Cand, temp2, cand_x_Index, cand_y_Index, false);
									ShowImage(pictureBox_Reference, Video_Bitmap[k], cand_x_Index, cand_y_Index, true);
									uint temp_Score = MatchMethodCaculate(temp, temp2);
									if (temp_Score < Score && (s!= 1))
									{
										Score = temp_Score;
										Minum = Point(cand_x_Index, cand_y_Index);
									}
									if ((s ==1) && temp_Score < Score)
									{
										Score = temp_Score;
										candidate_winner = Point(cand_x_Index, cand_y_Index);
									}
									delete temp2;
								}
							}
						}
					}
					if (Minum.X == Center.X && Minum.Y == Center.Y)
					{
						s = s / 2;
					}
					else
						Center = Minum;
			    }
				
				motionVector.push_back(Point(candidate_winner.X- targ_x_Index, candidate_winner.Y - targ_y_Index));
			   break;
			   }
			  default:
				  break;
			  }
			  delete temp;
		  }
		 
	  }
	}
  fp.open((char*)(void*)Marshal::StringToHGlobalAnsi(FileName),std::ios::app);
  for (uint i = 0; i < motionVector.size(); i++)
  {
	  fp << motionVector[i].X <<" "<<motionVector[i].Y<< endl;
  }
  fp.close();
}
private:double C_PSNR(Bitmap ^Source, Bitmap ^TestImage)
{
	double SNR_Value = 0;
	double SumofSource = 0;
	double SumofMSE = 0;//Source-Test
	for (UInt16 i = 0; i < Source->Width; i++)
		for (UInt16 j = 0; j < Source->Height; j++)
		{
			
			SumofMSE +=pow(Source->GetPixel(i, j).R-TestImage->GetPixel(i, j).R,2);
		}
	SumofMSE =  SumofMSE/(Source->Height* Source->Width);
	SNR_Value = Math::Log10(255*255 / SumofMSE);
	return 10 * SNR_Value;
}
private: System::Void encode_btn_Click(System::Object^  sender, System::EventArgs^  e) {
	System::String ^str=comboBox1->Text->Substring(0,1);
	MatchCode =  Convert::ToInt16(str);
	PDCthreshold = Convert::ToInt16(textBox1->Text);
	str=comboBox2->Text->Substring(0, 1);
	SearchCode = Convert::ToInt16(str);
	SaveFileDialog ^ SaveUI = gcnew SaveFileDialog;
	SaveUI->OverwritePrompt = true;
	SaveUI->FileName = nullptr;
	SaveUI->Filter = "txt files (*.txt)|*.txt";
	MaskSize = Convert::ToInt32(textBox2->Text);
	fstream fp;
	if (SaveUI->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		FileName = SaveUI->FileName;
		fp.open((char*)(void*)Marshal::StringToHGlobalAnsi(SaveUI->FileName), std::ios::out);
		fp << MaskSize <<" "<<Video_Bitmap.size()<<endl;
	}
	fp.close();
    thread = gcnew Thread(gcnew ThreadStart(this,&VideoProcessUI::Encoding));
	thread->Start();
}

private: System::Void Btn_Decode_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
	openFileDialog1->Multiselect = true;
	openFileDialog1->FileName = nullptr;
	cli::array<String^>^ openFileName;
	
	if (Video_Bitmap_Decode.size() != 0)Video_Bitmap_Decode.clear();
	Bitmap ^temp_FirstFrame;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		openFileName = openFileDialog1->FileNames;
	}
	fstream fp;
	if (openFileName[1]->IndexOf("tiff")> 0)
		temp_FirstFrame = gcnew Bitmap(openFileName[1]);
	if (openFileName[0]->IndexOf("tiff")> 0)
		temp_FirstFrame = gcnew Bitmap(openFileName[0]);
		
	if (openFileName[1]->IndexOf("txt")> 0)
		fp.open((char*)(void*)Marshal::StringToHGlobalAnsi(openFileName[1]), std::ios::in);
	if (openFileName[0]->IndexOf("txt")> 0)
		fp.open((char*)(void*)Marshal::StringToHGlobalAnsi(openFileName[0]), std::ios::in);

	Bitmap ^First = temp_FirstFrame->Clone(Rectangle(0,0, temp_FirstFrame->Width, temp_FirstFrame->Height), temp_FirstFrame->PixelFormat);
	Video_Bitmap_Decode.push_back(gcnew Bitmap(First));
	
	char line[100];
	fp.getline(line, sizeof(line));
	
	int secondFrameIndex_X = 0, secondFrameIndex_Y=0;
	cli::array<Char>^sep = gcnew cli::array<Char>{' '};
	System::String^ str = gcnew String(line);
	cli::array<String^>^result = str->Split(sep, StringSplitOptions::RemoveEmptyEntries);
	int blockSize = Convert::ToInt32(result[0]);
	int FrameNo = Convert::ToInt32(result[1]);
	label2->Text ="/"+FrameNo.ToString();
	Bitmap ^Image = gcnew Bitmap(Video_Bitmap_Decode[0]->Width, Video_Bitmap_Decode[0]->Height);
	while (Video_Bitmap_Decode.size()< FrameNo)
	{
		
		fp.getline(line, sizeof(line));		
		str = gcnew String(line);
		result = str->Split(sep, StringSplitOptions::RemoveEmptyEntries);
		int MotionVector_X = Convert::ToInt32(result[0]);
		int MotionVector_Y = Convert::ToInt32(result[1]);
		
		for (int j = 0; j < blockSize; j++)
			for (int i = 0; i < blockSize; i++)
			{
				Color c = First->GetPixel(secondFrameIndex_X +MotionVector_X+i, secondFrameIndex_Y +MotionVector_Y+j);
				Image->SetPixel(i+ secondFrameIndex_X, j+ secondFrameIndex_Y, c);
			}
		secondFrameIndex_X += blockSize;
		if (secondFrameIndex_X  == Video_Bitmap_Decode[0]->Width)
		{
			secondFrameIndex_X = 0;
			secondFrameIndex_Y+= blockSize;
		}
		if (secondFrameIndex_Y  == Video_Bitmap_Decode[0]->Height)
		{
			secondFrameIndex_X = 0;
			secondFrameIndex_Y = 0;
		
			Video_Bitmap_Decode.push_back(gcnew Bitmap(Image));
		
		}
	}

	for (uint i = 0; i < Video_Bitmap_Decode.size(); i++)
	{
		double value = C_PSNR(Video_Bitmap[i],Video_Bitmap_Decode[i]);
		chart_PSNR->Series["PSNR_S"]->Points->AddXY(i,(int)value);
	}
	fp.close();
	BtnDecode_Play->Visible = true;
	pictureBox_MotionVector->Size.Width = Video_Bitmap[1]->Width;
	pictureBox_MotionVector->Size.Height = Video_Bitmap[1]->Height;
	pictureBox_MotionVector->Image= Video_Bitmap[1];
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	System::String ^str = comboBox1->Text->Substring(0, 1);
	MatchCode = Convert::ToInt16(str);
	encode_btn->Enabled = true;
	if (MatchCode==2)
	{
		textBox1->Visible=true;
		tBOX_Threshold->Visible = true;
	}
	else {
		textBox1->Visible = false;
		tBOX_Threshold->Visible = false;
	}
}
private: System::Void BtnDecode_Play_Click(System::Object^  sender, System::EventArgs^  e) {
	for (uint i = 0; i < Video_Bitmap_Decode.size(); i++)
	{
		label1->Text = (i+1).ToString();
		label1->Refresh();
		pictureBox_Reference->Image = Video_Bitmap_Decode[i];
		pictureBox_Reference->Refresh();
		_sleep(50);
	}
}
};
}
