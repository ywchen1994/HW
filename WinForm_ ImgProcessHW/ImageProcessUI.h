#pragma once
#include <iostream> 
#include <stdio.h >  
#include <stdlib.h >  
#include<cmath>
#include"vcclr.h"
#include <cliext/vector>  
#include"RGBHistigram.h"
namespace WinForm_ImgProcessHW {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;
	using namespace cliext;
	
	enum BitmapImageProcessing
	{
		RGB2Gray,
		Zoom,
		Interpolation,//���ȩ�j
		Average, //�����Y�p
		ToRed,
		ToGreen,
		ToBlue,
		horizontal,
		vertical,
		diagonal,
		THRESH_BINARY,
		THRESH_BINARY_Inv,
		Duplication,
		other
	};
	enum Pen_Select
	{
		Pen_None,
		Pen_Rect,
		Pen_Line,
		Pen_Circle,
		Pen_CloudLine

	};
	/// <summary>
	/// ImageProcessUI ���K�n
	/// </summary>
	public ref class ImageProcessUI : public System::Windows::Forms::Form
	{
	public:
		ImageProcessUI(void)
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
		~ImageProcessUI()
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

	private:Bitmap ^Img_Source, ^Img_Source2,^Img_Stack;
	private: System::Windows::Forms::TabControl^  Tab_Image1;
	public:

	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::PictureBox^  pictureBox_Source1;
	private: System::Windows::Forms::BindingSource^  bindingSource1;

	private: System::Windows::Forms::PictureBox^  pictureBox_Colomap1;


	private: System::Windows::Forms::Label^  bytesperline_lbl;
	private: System::Windows::Forms::Label^  nplanes_lbl;
	private: System::Windows::Forms::Label^  reserved_lbl;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;



	private: System::Windows::Forms::ToolStrip^  toolStrip2;
	private: System::Windows::Forms::ToolStripButton^  Btn_ToRed;
	private: System::Windows::Forms::ToolStripButton^  Btn_ToGreen;
	private: System::Windows::Forms::ToolStripButton^  Btn_ToBlue;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripBtn_Gray;


	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;


	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::PictureBox^  pictureBox_Colomap2;

	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::Label^  label40;
	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::Label^  label42;
	private: System::Windows::Forms::Label^  label43;
	private: System::Windows::Forms::Label^  label44;
	private: System::Windows::Forms::Label^  label45;
	private: System::Windows::Forms::PictureBox^  pictureBox_Source2;

private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::ToolStrip^  toolStrip3;
private: System::Windows::Forms::ToolStripButton^  toolStripButton_horizontalFilp;
private: System::Windows::Forms::ToolStripButton^  toolStripButton_diagonal;
private: System::Windows::Forms::ToolStripButton^  Btn_verticalFlip;
private: System::Windows::Forms::ToolStripMenuItem^  openFile2ToolStripMenuItem;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Timer^  timer1;
private: System::Windows::Forms::Label^  Pos_RGBvalue;
private: System::Windows::Forms::Label^  Pos_Y;
private: System::Windows::Forms::Label^  Pos_X;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::NumericUpDown^  Rotation;

private: System::Windows::Forms::RadioButton^  ChkBox_Inverse_Rotation;

private: System::Windows::Forms::RadioButton^  ChkBox_Forward_Rotation;
private: System::Windows::Forms::PictureBox^  pictureBox_Result;
private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::RadioButton^  RadioBtn_Threshold_inv_Binary;
private: System::Windows::Forms::RadioButton^  RadioBtn_Threshold_Binary;
private: System::Windows::Forms::NumericUpDown^  Threshold_value;
private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::NumericUpDown^  numericUpDown_transparent;


private: int d_Pen= Pen_None;
		 Point LBtnDown;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::RadioButton^  Btn_Rectangle;
private: System::Windows::Forms::RadioButton^  Btn_Circle;
private: System::Windows::Forms::RadioButton^  Btn_Line;
private: System::Windows::Forms::RadioButton^  Btn_None_Draw;
private: System::Windows::Forms::RadioButton^  Btn_CloudLine;



	private: System::ComponentModel::IContainer^  components;
private: System::Windows::Forms::ToolStrip^  toolStrip4;
private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
private: System::Windows::Forms::GroupBox^  groupBox8;
private: System::Windows::Forms::NumericUpDown^  ZoomRate;

private: System::Windows::Forms::ToolStrip^  toolStrip5;
private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
private: System::Windows::Forms::ToolStripButton^  toolStripButton5;
private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;


	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		vector<Point>CloudLinePoint;

#pragma region Windows Form Designer generated code
		ref struct PCXData//http://www.fysnet.net/pcxfile.htm  PCX�ѫʥ]���
		{
			String ^filePath;//�ɮ׸��|
			String ^fileName;//�ɮצW��
			String^ Manufacturer;//Zsoft ID
			int version;//����
			int Encoding;//PCX run-length encoding
			int Hdpi;//
			int Vdpi;//
			int reserved;//
			String^ NPlanes;//
			String^ color;//�Ƕ� �m��
			int HscreenSize;//Video screen size (Horizontal)
			int VscreenSize;// Video screen size (Vertical)
			Bitmap^ Image;//
			int BytePerLine;//
			int BitsPerPixel;//
			Bitmap^ ColorMap;//
		};
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ImageProcessUI::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFile2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Tab_Image1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->Pos_RGBvalue = (gcnew System::Windows::Forms::Label());
			this->Pos_Y = (gcnew System::Windows::Forms::Label());
			this->Pos_X = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBox_Colomap1 = (gcnew System::Windows::Forms::PictureBox());
			this->bytesperline_lbl = (gcnew System::Windows::Forms::Label());
			this->nplanes_lbl = (gcnew System::Windows::Forms::Label());
			this->reserved_lbl = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox_Source1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->pictureBox_Colomap2 = (gcnew System::Windows::Forms::PictureBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->pictureBox_Source2 = (gcnew System::Windows::Forms::PictureBox());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->toolStrip2 = (gcnew System::Windows::Forms::ToolStrip());
			this->Btn_ToRed = (gcnew System::Windows::Forms::ToolStripButton());
			this->Btn_ToGreen = (gcnew System::Windows::Forms::ToolStripButton());
			this->Btn_ToBlue = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripBtn_Gray = (gcnew System::Windows::Forms::ToolStripButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->toolStrip3 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton_horizontalFilp = (gcnew System::Windows::Forms::ToolStripButton());
			this->Btn_verticalFlip = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton_diagonal = (gcnew System::Windows::Forms::ToolStripButton());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->ChkBox_Inverse_Rotation = (gcnew System::Windows::Forms::RadioButton());
			this->ChkBox_Forward_Rotation = (gcnew System::Windows::Forms::RadioButton());
			this->Rotation = (gcnew System::Windows::Forms::NumericUpDown());
			this->pictureBox_Result = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->RadioBtn_Threshold_inv_Binary = (gcnew System::Windows::Forms::RadioButton());
			this->RadioBtn_Threshold_Binary = (gcnew System::Windows::Forms::RadioButton());
			this->Threshold_value = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->toolStrip4 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_transparent = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->Btn_CloudLine = (gcnew System::Windows::Forms::RadioButton());
			this->Btn_Rectangle = (gcnew System::Windows::Forms::RadioButton());
			this->Btn_Circle = (gcnew System::Windows::Forms::RadioButton());
			this->Btn_Line = (gcnew System::Windows::Forms::RadioButton());
			this->Btn_None_Draw = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->ZoomRate = (gcnew System::Windows::Forms::NumericUpDown());
			this->toolStrip5 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuStrip1->SuspendLayout();
			this->Tab_Image1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Colomap1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Source1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Colomap2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Source2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->toolStrip2->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->toolStrip3->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Rotation))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Result))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Threshold_value))->BeginInit();
			this->groupBox5->SuspendLayout();
			this->toolStrip4->SuspendLayout();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_transparent))->BeginInit();
			this->groupBox7->SuspendLayout();
			this->groupBox8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ZoomRate))->BeginInit();
			this->toolStrip5->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1902, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->openFile2ToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(45, 23);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openToolStripMenuItem.Image")));
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(209, 26);
			this->openToolStripMenuItem->Text = L"OpenFile";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &ImageProcessUI::openToolStripMenuItem_Click);
			// 
			// openFile2ToolStripMenuItem
			// 
			this->openFile2ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openFile2ToolStripMenuItem.Image")));
			this->openFile2ToolStripMenuItem->Name = L"openFile2ToolStripMenuItem";
			this->openFile2ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			this->openFile2ToolStripMenuItem->Size = System::Drawing::Size(209, 26);
			this->openFile2ToolStripMenuItem->Text = L"OpenFile2";
			this->openFile2ToolStripMenuItem->Click += gcnew System::EventHandler(this, &ImageProcessUI::openFile2ToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exitToolStripMenuItem.BackgroundImage")));
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->exitToolStripMenuItem->Size = System::Drawing::Size(209, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &ImageProcessUI::exitToolStripMenuItem_Click);
			// 
			// Tab_Image1
			// 
			this->Tab_Image1->Controls->Add(this->tabPage1);
			this->Tab_Image1->Controls->Add(this->tabPage2);
			this->Tab_Image1->Location = System::Drawing::Point(35, 202);
			this->Tab_Image1->Name = L"Tab_Image1";
			this->Tab_Image1->SelectedIndex = 0;
			this->Tab_Image1->Size = System::Drawing::Size(892, 634);
			this->Tab_Image1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->Pos_RGBvalue);
			this->tabPage1->Controls->Add(this->Pos_Y);
			this->tabPage1->Controls->Add(this->Pos_X);
			this->tabPage1->Controls->Add(this->label19);
			this->tabPage1->Controls->Add(this->label20);
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->label18);
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->label15);
			this->tabPage1->Controls->Add(this->label16);
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->label13);
			this->tabPage1->Controls->Add(this->label12);
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->pictureBox_Colomap1);
			this->tabPage1->Controls->Add(this->bytesperline_lbl);
			this->tabPage1->Controls->Add(this->nplanes_lbl);
			this->tabPage1->Controls->Add(this->reserved_lbl);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->pictureBox_Source1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(884, 605);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Image1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// Pos_RGBvalue
			// 
			this->Pos_RGBvalue->AutoSize = true;
			this->Pos_RGBvalue->Location = System::Drawing::Point(309, 576);
			this->Pos_RGBvalue->Name = L"Pos_RGBvalue";
			this->Pos_RGBvalue->Size = System::Drawing::Size(0, 15);
			this->Pos_RGBvalue->TabIndex = 26;
			// 
			// Pos_Y
			// 
			this->Pos_Y->AutoSize = true;
			this->Pos_Y->Location = System::Drawing::Point(162, 576);
			this->Pos_Y->Name = L"Pos_Y";
			this->Pos_Y->Size = System::Drawing::Size(0, 15);
			this->Pos_Y->TabIndex = 22;
			// 
			// Pos_X
			// 
			this->Pos_X->AutoSize = true;
			this->Pos_X->Location = System::Drawing::Point(45, 576);
			this->Pos_X->Name = L"Pos_X";
			this->Pos_X->Size = System::Drawing::Size(0, 15);
			this->Pos_X->TabIndex = 23;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(123, 576);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(21, 15);
			this->label19->TabIndex = 24;
			this->label19->Text = L"Y:";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(18, 576);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(21, 15);
			this->label20->TabIndex = 25;
			this->label20->Text = L"X:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label10->Location = System::Drawing::Point(569, 390);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(139, 19);
			this->label10->TabIndex = 21;
			this->label10->Text = L"BitsPerPixel:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(729, 512);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(0, 15);
			this->label18->TabIndex = 12;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(729, 471);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(0, 15);
			this->label17->TabIndex = 12;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(729, 394);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(0, 15);
			this->label15->TabIndex = 12;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(729, 430);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(0, 15);
			this->label16->TabIndex = 12;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(729, 255);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(0, 15);
			this->label14->TabIndex = 12;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(729, 217);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 15);
			this->label13->TabIndex = 12;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(729, 177);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 15);
			this->label12->TabIndex = 12;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(729, 143);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 15);
			this->label11->TabIndex = 12;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(729, 103);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 15);
			this->label9->TabIndex = 12;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(729, 63);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 15);
			this->label8->TabIndex = 11;
			// 
			// pictureBox_Colomap1
			// 
			this->pictureBox_Colomap1->Location = System::Drawing::Point(705, 291);
			this->pictureBox_Colomap1->Name = L"pictureBox_Colomap1";
			this->pictureBox_Colomap1->Size = System::Drawing::Size(108, 80);
			this->pictureBox_Colomap1->TabIndex = 10;
			this->pictureBox_Colomap1->TabStop = false;
			// 
			// bytesperline_lbl
			// 
			this->bytesperline_lbl->AutoSize = true;
			this->bytesperline_lbl->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->bytesperline_lbl->Location = System::Drawing::Point(570, 505);
			this->bytesperline_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->bytesperline_lbl->Name = L"bytesperline_lbl";
			this->bytesperline_lbl->Size = System::Drawing::Size(116, 22);
			this->bytesperline_lbl->TabIndex = 7;
			this->bytesperline_lbl->Text = L"BytesPerLine:";
			// 
			// nplanes_lbl
			// 
			this->nplanes_lbl->AutoSize = true;
			this->nplanes_lbl->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->nplanes_lbl->Location = System::Drawing::Point(570, 464);
			this->nplanes_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->nplanes_lbl->Name = L"nplanes_lbl";
			this->nplanes_lbl->Size = System::Drawing::Size(79, 22);
			this->nplanes_lbl->TabIndex = 8;
			this->nplanes_lbl->Text = L"NPlanes:";
			// 
			// reserved_lbl
			// 
			this->reserved_lbl->AutoSize = true;
			this->reserved_lbl->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->reserved_lbl->Location = System::Drawing::Point(570, 423);
			this->reserved_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->reserved_lbl->Name = L"reserved_lbl";
			this->reserved_lbl->Size = System::Drawing::Size(89, 22);
			this->reserved_lbl->TabIndex = 9;
			this->reserved_lbl->Text = L"Reserved:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(569, 177);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(139, 19);
			this->label5->TabIndex = 1;
			this->label5->Text = L"BitsPerPixel:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(569, 253);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(109, 19);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Hdpi-Vdpi:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(569, 215);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 19);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Window:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label7->Location = System::Drawing::Point(569, 291);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(109, 19);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Color map:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(569, 139);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(99, 19);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Encoding:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(569, 101);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Version:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(569, 63);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(139, 19);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Manufacturer:";
			// 
			// pictureBox_Source1
			// 
			this->pictureBox_Source1->Location = System::Drawing::Point(16, 30);
			this->pictureBox_Source1->Name = L"pictureBox_Source1";
			this->pictureBox_Source1->Size = System::Drawing::Size(517, 416);
			this->pictureBox_Source1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox_Source1->TabIndex = 0;
			this->pictureBox_Source1->TabStop = false;
			this->pictureBox_Source1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ImageProcessUI::pictureBox_Source1_MouseDown);
			this->pictureBox_Source1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ImageProcessUI::pictureBox_Source1_MouseMove);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label21);
			this->tabPage2->Controls->Add(this->label22);
			this->tabPage2->Controls->Add(this->label33);
			this->tabPage2->Controls->Add(this->label34);
			this->tabPage2->Controls->Add(this->label46);
			this->tabPage2->Controls->Add(this->label23);
			this->tabPage2->Controls->Add(this->label24);
			this->tabPage2->Controls->Add(this->label25);
			this->tabPage2->Controls->Add(this->label26);
			this->tabPage2->Controls->Add(this->label27);
			this->tabPage2->Controls->Add(this->label28);
			this->tabPage2->Controls->Add(this->label29);
			this->tabPage2->Controls->Add(this->label30);
			this->tabPage2->Controls->Add(this->label31);
			this->tabPage2->Controls->Add(this->label32);
			this->tabPage2->Controls->Add(this->pictureBox_Colomap2);
			this->tabPage2->Controls->Add(this->label35);
			this->tabPage2->Controls->Add(this->label36);
			this->tabPage2->Controls->Add(this->label37);
			this->tabPage2->Controls->Add(this->label38);
			this->tabPage2->Controls->Add(this->label39);
			this->tabPage2->Controls->Add(this->label40);
			this->tabPage2->Controls->Add(this->label41);
			this->tabPage2->Controls->Add(this->label42);
			this->tabPage2->Controls->Add(this->label43);
			this->tabPage2->Controls->Add(this->label44);
			this->tabPage2->Controls->Add(this->label45);
			this->tabPage2->Controls->Add(this->pictureBox_Source2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(884, 605);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Image2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(309, 574);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(41, 15);
			this->label21->TabIndex = 43;
			this->label21->Text = L"label2";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(181, 574);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(41, 15);
			this->label22->TabIndex = 39;
			this->label22->Text = L"label1";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(45, 574);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(41, 15);
			this->label33->TabIndex = 40;
			this->label33->Text = L"label1";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(123, 574);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(21, 15);
			this->label34->TabIndex = 41;
			this->label34->Text = L"Y:";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(18, 574);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(21, 15);
			this->label46->TabIndex = 42;
			this->label46->Text = L"X:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(728, 521);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(0, 15);
			this->label23->TabIndex = 31;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(728, 480);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(0, 15);
			this->label24->TabIndex = 32;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(728, 439);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(0, 15);
			this->label25->TabIndex = 33;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(729, 398);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(0, 15);
			this->label26->TabIndex = 38;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(729, 259);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(0, 15);
			this->label27->TabIndex = 35;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(729, 221);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(0, 15);
			this->label28->TabIndex = 34;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(729, 181);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(0, 15);
			this->label29->TabIndex = 37;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(729, 147);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(0, 15);
			this->label30->TabIndex = 36;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(729, 107);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(0, 15);
			this->label31->TabIndex = 29;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(729, 67);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(0, 15);
			this->label32->TabIndex = 28;
			// 
			// pictureBox_Colomap2
			// 
			this->pictureBox_Colomap2->Location = System::Drawing::Point(705, 295);
			this->pictureBox_Colomap2->Name = L"pictureBox_Colomap2";
			this->pictureBox_Colomap2->Size = System::Drawing::Size(108, 80);
			this->pictureBox_Colomap2->TabIndex = 27;
			this->pictureBox_Colomap2->TabStop = false;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label35->Location = System::Drawing::Point(569, 517);
			this->label35->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(116, 22);
			this->label35->TabIndex = 24;
			this->label35->Text = L"BytesPerLine:";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label36->Location = System::Drawing::Point(569, 476);
			this->label36->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(79, 22);
			this->label36->TabIndex = 25;
			this->label36->Text = L"NPlanes:";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label37->Location = System::Drawing::Point(568, 435);
			this->label37->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(89, 22);
			this->label37->TabIndex = 26;
			this->label37->Text = L"Reserved:";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label38->Location = System::Drawing::Point(569, 396);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(139, 19);
			this->label38->TabIndex = 20;
			this->label38->Text = L"BitsPerPixel:";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label39->Location = System::Drawing::Point(569, 181);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(139, 19);
			this->label39->TabIndex = 19;
			this->label39->Text = L"BitsPerPixel:";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label40->Location = System::Drawing::Point(569, 257);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(109, 19);
			this->label40->TabIndex = 18;
			this->label40->Text = L"Hdpi-Vdpi:";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label41->Location = System::Drawing::Point(569, 219);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(79, 19);
			this->label41->TabIndex = 17;
			this->label41->Text = L"Window:";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label42->Location = System::Drawing::Point(569, 295);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(109, 19);
			this->label42->TabIndex = 16;
			this->label42->Text = L"Color map:";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label43->Location = System::Drawing::Point(569, 143);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(99, 19);
			this->label43->TabIndex = 15;
			this->label43->Text = L"Encoding:";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label44->Location = System::Drawing::Point(569, 105);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(89, 19);
			this->label44->TabIndex = 14;
			this->label44->Text = L"Version:";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Font = (gcnew System::Drawing::Font(L"�з���", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label45->Location = System::Drawing::Point(569, 67);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(139, 19);
			this->label45->TabIndex = 21;
			this->label45->Text = L"Manufacturer:";
			// 
			// pictureBox_Source2
			// 
			this->pictureBox_Source2->Location = System::Drawing::Point(16, 34);
			this->pictureBox_Source2->Name = L"pictureBox_Source2";
			this->pictureBox_Source2->Size = System::Drawing::Size(517, 416);
			this->pictureBox_Source2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox_Source2->TabIndex = 13;
			this->pictureBox_Source2->TabStop = false;
			this->pictureBox_Source2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ImageProcessUI::pictureBox_Source2_MouseMove);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->toolStrip2);
			this->groupBox1->Controls->Add(this->toolStrip1);
			this->groupBox1->Location = System::Drawing::Point(21, 33);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(127, 84);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"��m�ഫ";
			// 
			// toolStrip2
			// 
			this->toolStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->Btn_ToRed, this->Btn_ToGreen,
					this->Btn_ToBlue
			});
			this->toolStrip2->Location = System::Drawing::Point(3, 47);
			this->toolStrip2->Name = L"toolStrip2";
			this->toolStrip2->Size = System::Drawing::Size(121, 26);
			this->toolStrip2->TabIndex = 1;
			this->toolStrip2->Text = L"toolStrip2";
			// 
			// Btn_ToRed
			// 
			this->Btn_ToRed->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Btn_ToRed->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Btn_ToRed.Image")));
			this->Btn_ToRed->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Btn_ToRed->Name = L"Btn_ToRed";
			this->Btn_ToRed->Size = System::Drawing::Size(23, 23);
			this->Btn_ToRed->Text = L"R";
			this->Btn_ToRed->Click += gcnew System::EventHandler(this, &ImageProcessUI::Btn_ToRed_Click);
			// 
			// Btn_ToGreen
			// 
			this->Btn_ToGreen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Btn_ToGreen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Btn_ToGreen.Image")));
			this->Btn_ToGreen->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Btn_ToGreen->Name = L"Btn_ToGreen";
			this->Btn_ToGreen->Size = System::Drawing::Size(24, 23);
			this->Btn_ToGreen->Text = L"G";
			this->Btn_ToGreen->Click += gcnew System::EventHandler(this, &ImageProcessUI::Btn_ToGreen_Click);
			// 
			// Btn_ToBlue
			// 
			this->Btn_ToBlue->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Btn_ToBlue->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Btn_ToBlue.Image")));
			this->Btn_ToBlue->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Btn_ToBlue->Name = L"Btn_ToBlue";
			this->Btn_ToBlue->Size = System::Drawing::Size(23, 23);
			this->Btn_ToBlue->Text = L"B";
			this->Btn_ToBlue->Click += gcnew System::EventHandler(this, &ImageProcessUI::Btn_ToBlue_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripBtn_Gray });
			this->toolStrip1->Location = System::Drawing::Point(3, 20);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(121, 27);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripBtn_Gray
			// 
			this->toolStripBtn_Gray->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripBtn_Gray.Image")));
			this->toolStripBtn_Gray->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripBtn_Gray->Name = L"toolStripBtn_Gray";
			this->toolStripBtn_Gray->Size = System::Drawing::Size(63, 24);
			this->toolStripBtn_Gray->Text = L"�Ƕ�";
			this->toolStripBtn_Gray->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripBtn_Gray_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->toolStrip3);
			this->groupBox2->Location = System::Drawing::Point(169, 33);
			this->groupBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Size = System::Drawing::Size(125, 138);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"��g";
			// 
			// toolStrip3
			// 
			this->toolStrip3->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip3->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripButton_horizontalFilp,
					this->Btn_verticalFlip, this->toolStripButton_diagonal
			});
			this->toolStrip3->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::VerticalStackWithOverflow;
			this->toolStrip3->Location = System::Drawing::Point(3, 20);
			this->toolStrip3->Name = L"toolStrip3";
			this->toolStrip3->Size = System::Drawing::Size(119, 92);
			this->toolStrip3->TabIndex = 0;
			this->toolStrip3->Text = L"toolStrip3";
			// 
			// toolStripButton_horizontalFilp
			// 
			this->toolStripButton_horizontalFilp->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_horizontalFilp.Image")));
			this->toolStripButton_horizontalFilp->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_horizontalFilp->Name = L"toolStripButton_horizontalFilp";
			this->toolStripButton_horizontalFilp->Size = System::Drawing::Size(117, 24);
			this->toolStripButton_horizontalFilp->Text = L"������g";
			this->toolStripButton_horizontalFilp->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton_horizontalFilp_Click);
			// 
			// Btn_verticalFlip
			// 
			this->Btn_verticalFlip->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Btn_verticalFlip.Image")));
			this->Btn_verticalFlip->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Btn_verticalFlip->Name = L"Btn_verticalFlip";
			this->Btn_verticalFlip->Size = System::Drawing::Size(117, 24);
			this->Btn_verticalFlip->Text = L"������g";
			this->Btn_verticalFlip->Click += gcnew System::EventHandler(this, &ImageProcessUI::Btn_verticalFlip_Click);
			// 
			// toolStripButton_diagonal
			// 
			this->toolStripButton_diagonal->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_diagonal.Image")));
			this->toolStripButton_diagonal->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_diagonal->Name = L"toolStripButton_diagonal";
			this->toolStripButton_diagonal->Size = System::Drawing::Size(117, 24);
			this->toolStripButton_diagonal->Text = L"�﨤�u��g";
			this->toolStripButton_diagonal->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton_diagonalFlip_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->ChkBox_Inverse_Rotation);
			this->groupBox3->Controls->Add(this->ChkBox_Forward_Rotation);
			this->groupBox3->Controls->Add(this->Rotation);
			this->groupBox3->Location = System::Drawing::Point(300, 33);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(165, 87);
			this->groupBox3->TabIndex = 11;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"����";
			// 
			// ChkBox_Inverse_Rotation
			// 
			this->ChkBox_Inverse_Rotation->AutoSize = true;
			this->ChkBox_Inverse_Rotation->Location = System::Drawing::Point(78, 54);
			this->ChkBox_Inverse_Rotation->Name = L"ChkBox_Inverse_Rotation";
			this->ChkBox_Inverse_Rotation->Size = System::Drawing::Size(73, 19);
			this->ChkBox_Inverse_Rotation->TabIndex = 13;
			this->ChkBox_Inverse_Rotation->Text = L"�f���k";
			this->ChkBox_Inverse_Rotation->UseVisualStyleBackColor = true;
			// 
			// ChkBox_Forward_Rotation
			// 
			this->ChkBox_Forward_Rotation->AutoSize = true;
			this->ChkBox_Forward_Rotation->Checked = true;
			this->ChkBox_Forward_Rotation->Location = System::Drawing::Point(78, 22);
			this->ChkBox_Forward_Rotation->Name = L"ChkBox_Forward_Rotation";
			this->ChkBox_Forward_Rotation->Size = System::Drawing::Size(73, 19);
			this->ChkBox_Forward_Rotation->TabIndex = 13;
			this->ChkBox_Forward_Rotation->TabStop = true;
			this->ChkBox_Forward_Rotation->Text = L"�����k";
			this->ChkBox_Forward_Rotation->UseVisualStyleBackColor = true;
			// 
			// Rotation
			// 
			this->Rotation->Location = System::Drawing::Point(0, 36);
			this->Rotation->Margin = System::Windows::Forms::Padding(4);
			this->Rotation->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
			this->Rotation->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, System::Int32::MinValue });
			this->Rotation->Name = L"Rotation";
			this->Rotation->Size = System::Drawing::Size(76, 25);
			this->Rotation->TabIndex = 12;
			this->Rotation->ValueChanged += gcnew System::EventHandler(this, &ImageProcessUI::Rotation_ValueChanged);
			// 
			// pictureBox_Result
			// 
			this->pictureBox_Result->Location = System::Drawing::Point(939, 227);
			this->pictureBox_Result->Name = L"pictureBox_Result";
			this->pictureBox_Result->Size = System::Drawing::Size(454, 371);
			this->pictureBox_Result->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox_Result->TabIndex = 12;
			this->pictureBox_Result->TabStop = false;
			this->pictureBox_Result->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ImageProcessUI::pictureBox_Result_MouseDown);
			this->pictureBox_Result->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ImageProcessUI::pictureBox_Result_MouseMove);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->RadioBtn_Threshold_inv_Binary);
			this->groupBox4->Controls->Add(this->RadioBtn_Threshold_Binary);
			this->groupBox4->Controls->Add(this->Threshold_value);
			this->groupBox4->Location = System::Drawing::Point(471, 33);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(198, 77);
			this->groupBox4->TabIndex = 13;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"�G�Ȥ�";
			// 
			// RadioBtn_Threshold_inv_Binary
			// 
			this->RadioBtn_Threshold_inv_Binary->AutoSize = true;
			this->RadioBtn_Threshold_inv_Binary->Location = System::Drawing::Point(86, 37);
			this->RadioBtn_Threshold_inv_Binary->Name = L"RadioBtn_Threshold_inv_Binary";
			this->RadioBtn_Threshold_inv_Binary->Size = System::Drawing::Size(103, 19);
			this->RadioBtn_Threshold_inv_Binary->TabIndex = 15;
			this->RadioBtn_Threshold_inv_Binary->Text = L"�G�Ȥƭt��";
			this->RadioBtn_Threshold_inv_Binary->UseVisualStyleBackColor = true;
			// 
			// RadioBtn_Threshold_Binary
			// 
			this->RadioBtn_Threshold_Binary->AutoSize = true;
			this->RadioBtn_Threshold_Binary->Checked = true;
			this->RadioBtn_Threshold_Binary->Location = System::Drawing::Point(86, 12);
			this->RadioBtn_Threshold_Binary->Name = L"RadioBtn_Threshold_Binary";
			this->RadioBtn_Threshold_Binary->Size = System::Drawing::Size(73, 19);
			this->RadioBtn_Threshold_Binary->TabIndex = 15;
			this->RadioBtn_Threshold_Binary->TabStop = true;
			this->RadioBtn_Threshold_Binary->Text = L"�G�Ȥ�";
			this->RadioBtn_Threshold_Binary->UseVisualStyleBackColor = true;
			// 
			// Threshold_value
			// 
			this->Threshold_value->Location = System::Drawing::Point(0, 26);
			this->Threshold_value->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Threshold_value->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->Threshold_value->Name = L"Threshold_value";
			this->Threshold_value->Size = System::Drawing::Size(80, 25);
			this->Threshold_value->TabIndex = 14;
			this->Threshold_value->ValueChanged += gcnew System::EventHandler(this, &ImageProcessUI::Threshold_value_ValueChanged);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->toolStrip4);
			this->groupBox5->Location = System::Drawing::Point(675, 33);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(136, 128);
			this->groupBox5->TabIndex = 14;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"�����";
			// 
			// toolStrip4
			// 
			this->toolStrip4->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip4->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripButton1 });
			this->toolStrip4->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::VerticalStackWithOverflow;
			this->toolStrip4->Location = System::Drawing::Point(3, 21);
			this->toolStrip4->Name = L"toolStrip4";
			this->toolStrip4->Size = System::Drawing::Size(130, 38);
			this->toolStrip4->TabIndex = 0;
			this->toolStrip4->Text = L"toolStrip4";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(128, 24);
			this->toolStripButton1->Text = L"RGB�����";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton1_Click);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->numericUpDown_transparent);
			this->groupBox6->Location = System::Drawing::Point(933, 33);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(116, 163);
			this->groupBox6->TabIndex = 15;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"�z����";
			// 
			// numericUpDown_transparent
			// 
			this->numericUpDown_transparent->Location = System::Drawing::Point(6, 22);
			this->numericUpDown_transparent->Name = L"numericUpDown_transparent";
			this->numericUpDown_transparent->Size = System::Drawing::Size(86, 25);
			this->numericUpDown_transparent->TabIndex = 0;
			this->numericUpDown_transparent->ValueChanged += gcnew System::EventHandler(this, &ImageProcessUI::numericUpDown_transparent_ValueChanged);
			this->numericUpDown_transparent->Enter += gcnew System::EventHandler(this, &ImageProcessUI::numericUpDown_transparent_ValueChanged);
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->Btn_CloudLine);
			this->groupBox7->Controls->Add(this->Btn_Rectangle);
			this->groupBox7->Controls->Add(this->Btn_Circle);
			this->groupBox7->Controls->Add(this->Btn_Line);
			this->groupBox7->Controls->Add(this->Btn_None_Draw);
			this->groupBox7->Font = (gcnew System::Drawing::Font(L"�s�ө���", 9));
			this->groupBox7->Location = System::Drawing::Point(817, 33);
			this->groupBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox7->Size = System::Drawing::Size(110, 163);
			this->groupBox7->TabIndex = 16;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"ø�Ϥu��";
			// 
			// Btn_CloudLine
			// 
			this->Btn_CloudLine->AutoSize = true;
			this->Btn_CloudLine->Location = System::Drawing::Point(11, 133);
			this->Btn_CloudLine->Name = L"Btn_CloudLine";
			this->Btn_CloudLine->Size = System::Drawing::Size(58, 19);
			this->Btn_CloudLine->TabIndex = 4;
			this->Btn_CloudLine->TabStop = true;
			this->Btn_CloudLine->Text = L"���u";
			this->Btn_CloudLine->UseVisualStyleBackColor = true;
			this->Btn_CloudLine->CheckedChanged += gcnew System::EventHandler(this, &ImageProcessUI::Btn_CloudLine_CheckedChanged);
			// 
			// Btn_Rectangle
			// 
			this->Btn_Rectangle->AutoSize = true;
			this->Btn_Rectangle->Location = System::Drawing::Point(11, 109);
			this->Btn_Rectangle->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Btn_Rectangle->Name = L"Btn_Rectangle";
			this->Btn_Rectangle->Size = System::Drawing::Size(58, 19);
			this->Btn_Rectangle->TabIndex = 3;
			this->Btn_Rectangle->Text = L"�x��";
			this->Btn_Rectangle->UseVisualStyleBackColor = true;
			this->Btn_Rectangle->CheckedChanged += gcnew System::EventHandler(this, &ImageProcessUI::Btn_Rectangle_CheckedChanged);
			// 
			// Btn_Circle
			// 
			this->Btn_Circle->AutoSize = true;
			this->Btn_Circle->Location = System::Drawing::Point(11, 81);
			this->Btn_Circle->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Btn_Circle->Name = L"Btn_Circle";
			this->Btn_Circle->Size = System::Drawing::Size(58, 19);
			this->Btn_Circle->TabIndex = 2;
			this->Btn_Circle->Text = L"���";
			this->Btn_Circle->UseVisualStyleBackColor = true;
			this->Btn_Circle->CheckedChanged += gcnew System::EventHandler(this, &ImageProcessUI::Btn_Circle_CheckedChanged);
			// 
			// Btn_Line
			// 
			this->Btn_Line->AutoSize = true;
			this->Btn_Line->Location = System::Drawing::Point(11, 58);
			this->Btn_Line->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Btn_Line->Name = L"Btn_Line";
			this->Btn_Line->Size = System::Drawing::Size(58, 19);
			this->Btn_Line->TabIndex = 1;
			this->Btn_Line->Text = L"���u";
			this->Btn_Line->UseVisualStyleBackColor = true;
			this->Btn_Line->CheckedChanged += gcnew System::EventHandler(this, &ImageProcessUI::Btn_Line_CheckedChanged);
			// 
			// Btn_None_Draw
			// 
			this->Btn_None_Draw->AutoSize = true;
			this->Btn_None_Draw->Checked = true;
			this->Btn_None_Draw->Location = System::Drawing::Point(11, 32);
			this->Btn_None_Draw->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Btn_None_Draw->Name = L"Btn_None_Draw";
			this->Btn_None_Draw->Size = System::Drawing::Size(43, 19);
			this->Btn_None_Draw->TabIndex = 0;
			this->Btn_None_Draw->TabStop = true;
			this->Btn_None_Draw->Text = L"�L";
			this->Btn_None_Draw->UseVisualStyleBackColor = true;
			this->Btn_None_Draw->CheckedChanged += gcnew System::EventHandler(this, &ImageProcessUI::Btn_None_Draw_CheckedChanged);
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->ZoomRate);
			this->groupBox8->Controls->Add(this->toolStrip5);
			this->groupBox8->Location = System::Drawing::Point(1055, 33);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(119, 188);
			this->groupBox8->TabIndex = 17;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"�Y��";
			// 
			// ZoomRate
			// 
			this->ZoomRate->Location = System::Drawing::Point(14, 20);
			this->ZoomRate->Name = L"ZoomRate";
			this->ZoomRate->Size = System::Drawing::Size(94, 25);
			this->ZoomRate->TabIndex = 1;
			// 
			// toolStrip5
			// 
			this->toolStrip5->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStrip5->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip5->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripButton2,
					this->toolStripButton3, this->toolStripButton4, this->toolStripButton5
			});
			this->toolStrip5->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::VerticalStackWithOverflow;
			this->toolStrip5->Location = System::Drawing::Point(14, 47);
			this->toolStrip5->Name = L"toolStrip5";
			this->toolStrip5->Size = System::Drawing::Size(94, 143);
			this->toolStrip5->TabIndex = 0;
			this->toolStrip5->Text = L"toolStrip5";
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(92, 24);
			this->toolStripButton2->Text = L"��ҩ�j";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton2_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(92, 24);
			this->toolStripButton3->Text = L"����Y�p";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton3_Click);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(92, 24);
			this->toolStripButton4->Text = L"�t����j";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton4_Click);
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(92, 24);
			this->toolStripButton5->Text = L"�����Y�p";
			this->toolStripButton5->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton5_Click);
			// 
			// ImageProcessUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1902, 1033);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->pictureBox_Result);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Tab_Image1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"ImageProcessUI";
			this->Text = L"ImageProcessUI";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->Tab_Image1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Colomap1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Source1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Colomap2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Source2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->toolStrip2->ResumeLayout(false);
			this->toolStrip2->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->toolStrip3->ResumeLayout(false);
			this->toolStrip3->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Rotation))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Result))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Threshold_value))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->toolStrip4->ResumeLayout(false);
			this->toolStrip4->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_transparent))->EndInit();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ZoomRate))->EndInit();
			this->toolStrip5->ResumeLayout(false);
			this->toolStrip5->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ opnFileDlg = gcnew OpenFileDialog;
		opnFileDlg->Multiselect = true;
		if (opnFileDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (opnFileDlg->FileName->IndexOf("jpeg") > 0 | opnFileDlg->FileName->IndexOf("jpg") > 0)
			{
				Img_Source = gcnew Bitmap(opnFileDlg->FileName);
				pictureBox_Source1->Image = Img_Source;
				//pictureBox2->Image = Img_Source;
			}
			if (opnFileDlg->FileName->IndexOf("pcx") > 0)
			{
				PCXData data;
				LoadPCXFile(opnFileDlg->FileName, data);
				Img_Source = data.Image;
				pictureBox_Source1->Image = Img_Source;
				pictureBox_Colomap1->Image = data.ColorMap;
				label8->Text = data.Manufacturer;
				label9->Text = data.version.ToString();
				label11->Text = data.Encoding.ToString();
				label12->Text = data.BitsPerPixel.ToString();
				label13->Text = data.Image->Width.ToString() + "*" + data.Image->Height.ToString();
				label14->Text = data.Hdpi.ToString()+"-"+data.Vdpi.ToString();
				label15->Text = data.BitsPerPixel.ToString();
				label16->Text = data.reserved.ToString();
				label17->Text = data.NPlanes;
				label18->Text = data.BytePerLine.ToString();		
			}
		}
	}
public:void LoadPCXFile(String^ filename, PCXData % PCXdata)
			 {
				 PCXdata.filePath = filename;
				 String^name = System::IO::Path::GetFileName(filename);//�o���ɮצW��
				 PCXdata.fileName = name;
				 FileStream^ fs = gcnew FileStream(filename, FileMode::Open);//��Ƭy
				 BinaryReader^ br = gcnew BinaryReader(fs);//�G�i��s�X
				 while (br->BaseStream->Position < 128)
				 {
					 switch (br->BaseStream->Position)
					 {
					 case 0:
						 PCXdata.Manufacturer = br->ReadByte().ToString();
						 break;
					 case 1:
						 PCXdata.version = br->ReadByte();
						 break;
					 case 2:
						 PCXdata.Encoding = br->ReadByte();
						 break;
					 case 3:
						 PCXdata.BitsPerPixel = br->ReadByte();
						 break;
					 case 4: {
						 int Xmin = br->ReadByte();
						 Xmin = Xmin + 256 * br->ReadByte();
						 int Ymin = br->ReadByte();
						 Ymin = Ymin + 256 * br->ReadByte();
						 int Xmax = br->ReadByte();
						 Xmax = Xmax + 256 * br->ReadByte();
						 int Ymax = br->ReadByte();
						 Ymax = Ymax + 256 * br->ReadByte();
						 PCXdata.Image = gcnew Bitmap(Xmax - Xmin + 1, Ymax - Ymin + 1);
						 break;
					 }
					 case 12:
						 PCXdata.Hdpi = br->ReadByte();
						 break;
					 case 14:
						 PCXdata.Vdpi = br->ReadByte();
						 break;
					 case 64:
						 PCXdata.reserved = br->ReadByte();
						 break;
					 case 65:
						 PCXdata.NPlanes = br->ReadByte().ToString();
						 break;
					 case 66:
						 PCXdata.BytePerLine = br->ReadByte();
						 PCXdata.BytePerLine = 256 * (br->ReadByte()) + PCXdata.BytePerLine;
						 break;
					 case 68:
					 {
						 if (br->ReadByte() == 1)
						 {
							 PCXdata.color = "Color or BW";
						 }
						 else
						 {
							 PCXdata.color = "Grayscale";
						 }
						 break;
					 }
					 case 70:
						 PCXdata.HscreenSize = br->ReadByte();
						 break;
					 case 72:
						 PCXdata.VscreenSize = br->ReadByte();
						 break;
					 default:
						 br->ReadByte();
						 break;
					 }
				 }
				 /***********************************/
				 PCXdata.ColorMap = gcnew Bitmap(128, 128);
				 br->BaseStream->Position = (fs->Length) - 769;//

				 int check = br->ReadByte();
				 Graphics^ graphics = Graphics::FromImage(PCXdata.ColorMap);
				 Color palette;
				 short color[256][3] = { { 0, 0, 0 } };
				 if (check != 12) {
					 br->BaseStream->Position = 16;
					 int red, green, blue;
					 for (int i = 0, c = 0; i < 4; i++)
						 for (int j = 0; j < 4; j++, c++) {
							 red = br->ReadByte();
							 green = br->ReadByte();
							 blue = br->ReadByte();
							 palette = Color::FromArgb(red, green, blue);
							 SolidBrush^ brush = gcnew SolidBrush(palette);
							 System::Drawing::Rectangle rect((i * 32), (j * 32), 32, 32);
							 graphics->FillRectangle(brush, rect);
							 color[c][0] = red;
							 color[c][1] = green;
							 color[c][2] = blue;
						 }
				 }
				 else if (check == 12)
				 {
					 int red, green, blue;
					 for (int i = 0, c = 0; i < 16; i++)
						 for (int j = 0; j < 16; j++, c++) {
							 red = br->ReadByte();
							 green = br->ReadByte();
							 blue = br->ReadByte();
							 palette = Color::FromArgb(red, green, blue);
							 SolidBrush^ brush = gcnew SolidBrush(palette);
							 System::Drawing::Rectangle rect((i * 8), (j * 8), 8, 8);
							 graphics->FillRectangle(brush, rect);
							 color[c][0] = red;
							 color[c][1] = green;
							 color[c][2] = blue;
						 }
				 }
				 br->BaseStream->Position = 127;
				 int count = br->ReadByte();

				 if (PCXdata.Encoding == 0)
				 {
					 int y = 0;
					 int x = 0;
					 while (y < PCXdata.Image->Height)
					 {
						 int pposition = br->BaseStream->Position;
						 int ck_c = br->ReadByte();
						 bool over = false;
						 Color newColor = Color::FromArgb(color[ck_c][0], color[ck_c][1], color[ck_c][2]);
						 PCXdata.Image->SetPixel(x, y, newColor);
						 x++;
						 if (x >= PCXdata.Image->Width)
						 {
							 y++;
							 x = 0;
						 }
					 }
				 }
				 /********************�H�U�B�z�m��**********************/
				 else if (count == 0) {
					 int y = 0;
					 int x = 0;
					 while (y < PCXdata.Image->Height)
					 {
						 int pposition = br->BaseStream->Position;
						 int ck_c = br->ReadByte();
						 bool over = false;
						 if (ck_c >= 192)
						 {
							 int length = ck_c - 192;
							 int colorcode = br->ReadByte();
							 Color newColor = Color::FromArgb(color[colorcode][0], color[colorcode][1], color[colorcode][2]);
							 for (length; length > 0; length--) {
								 PCXdata.Image->SetPixel(x, y, newColor);
								 x++;
								 if (x >= PCXdata.Image->Width)
								 {
									 y++;
									 x = 0;
								 }
								 if (y >= PCXdata.Image->Height)
								 {
									 break;
								 }
							 }
						 }
						 else {
							 Color newColor = Color::FromArgb(color[ck_c][0], color[ck_c][1], color[ck_c][2]);
							 PCXdata.Image->SetPixel(x, y, newColor);
							 x++;
							 if (x >= PCXdata.Image->Width)
							 {
								 y++;
								 x = 0;
							 }
						 }
					 }
				 }
				 fs->Close();
			 }
private: System::Void toolStripBtn_Gray_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	ConvertColor(Img_Source, img_processed, RGB2Gray);
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed;
	}
public: void ConvertColor(Bitmap^ src, Bitmap ^%dst, int code)
		 {
			 if (src != nullptr)
			 {
				 dst = gcnew Bitmap(src->Width, src->Height);
				 switch (code)
				 {
				 case RGB2Gray:
					 for (int i = 0; i < src->Width; i++)
						 for (int j = 0; j < src->Height; j++)
						 {
							 int Gray_vaule = src->GetPixel(i, j).R*0.299 + src->GetPixel(i, j).G* 0.587 + src->GetPixel(i, j).B*0.114 + 0.5;//Gray = R*0.299 + G*0.587 + B*0.114
							 dst->SetPixel(i, j, Color::FromArgb(Gray_vaule, Gray_vaule, Gray_vaule));
						 }
					 break;

				 case ToRed:
					 for (int i = 0; i < src->Width; i++)
						 for (int j = 0; j < src->Height; j++)
						 {
							 dst->SetPixel(i, j, Color::FromArgb(src->GetPixel(i, j).R, 0, 0));
						 }
					 break;
				 case ToGreen:
					 for (int i = 0; i < src->Width; i++)
						 for (int j = 0; j < src->Height; j++)
						 {
							 dst->SetPixel(i, j, Color::FromArgb(0, src->GetPixel(i, j).G, 0));
						 }
					 break;
				 case ToBlue:
					 for (int i = 0; i < src->Width; i++)
						 for (int j = 0; j < src->Height; j++)
						 {
							 dst->SetPixel(i, j, Color::FromArgb(0, 0, src->GetPixel(i, j).B));
						 }
					 break;
				 default:
					 break;
				 }
			 }

			 else
				 MessageBox::Show("No Image yet");
		 }
public: void Flip(Bitmap^ src, Bitmap ^%dst, int code)
{
	if (src != nullptr)
	{
		Bitmap^ temp = src;
		dst = gcnew Bitmap(src->Width, src->Height);
		switch (code)
		{
		case horizontal:
			for (int i = 0; i < temp->Width; i++)
				for (int j = 0; j < temp->Height; j++)
				{
					Color color = temp->GetPixel(i, j); //�إ�Color���c
					dst->SetPixel(temp->Width - i - 1, j, color);
				}
			break;
		case vertical:
			for (int i = 0; i < temp->Width; i++)
				for (int j = 0; j < temp->Height; j++)
				{
					Color color = temp->GetPixel(i, j); //�إ�Color���c
					dst->SetPixel(i, temp->Height - j - 1, color);
				}
			break;
		case diagonal:
			for (size_t i = 0; i < temp->Width; i++)
				for (size_t j = 0; j < temp->Height; j++)
				{
					Color color = temp->GetPixel(i, j); //�إ�Color���c
					dst->SetPixel(temp->Width - i - 1, temp->Height - j - 1, color);
				}
			break;
		default:
			break;
		}
	}
	else MessageBox::Show("No Image yet");
}
public:void Threshold(Bitmap^ src, Bitmap ^%dst, int threshold, int code)
{
	for (size_t i = 0; i < src->Width; i++)
		for (int j = 0; j < src->Height; j++)
		{
			if (src->GetPixel(i, j).R != src->GetPixel(i, j).G || src->GetPixel(i, j).R != src->GetPixel(i, j).B)
			{
				MessageBox::Show("Convert to Gray First");
				break;
			}
		}
	for (size_t i = 0; i < src->Width; i++)
		for (int j = 0; j < src->Height; j++)
		{
			if (src->GetPixel(i, j).R >= threshold)
			{
				if (code == THRESH_BINARY)
					src->SetPixel(i, j, Color::FromArgb(255, 255, 255));
				if (code == THRESH_BINARY_Inv)
					src->SetPixel(i, j, Color::FromArgb(0, 0, 0));
			}
			else if (src->GetPixel(i, j).R<threshold)
			{
				if (code == THRESH_BINARY)
					src->SetPixel(i, j, Color::FromArgb(0, 0, 0));
				if (code == THRESH_BINARY_Inv)
					src->SetPixel(i, j, Color::FromArgb(255, 255, 255));
			}
		}
}
private: System::Void toolStripButton_horizontalFilp_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	Flip(Img_Source, img_processed, horizontal);
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed;
}
private: System::Void Btn_ToRed_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	ConvertColor(Img_Source, img_processed, ToRed);
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed;
}
private: System::Void Btn_ToGreen_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	ConvertColor(Img_Source, img_processed, ToGreen);
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed;
}
private: System::Void Btn_ToBlue_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	ConvertColor(Img_Source, img_processed, ToBlue);
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed;
}
private: System::Void toolStripButton_Threshold_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	ConvertColor(Img_Source, img_processed, RGB2Gray);
	Threshold(img_processed, img_processed, 100, THRESH_BINARY);
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed;
}
private: System::Void toolStripButton_Threshold_Inv_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	ConvertColor(Img_Source, img_processed, RGB2Gray);
	Threshold(img_processed, img_processed, 100, THRESH_BINARY_Inv);
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed;
}
private: System::Void toolStripButton_diagonalFlip_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	Flip(Img_Source, img_processed, diagonal);
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed;
}
private: System::Void Btn_verticalFlip_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	Flip(Img_Source, img_processed, vertical);
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed;
}
private: System::Void openFile2ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog^ opnFileDlg = gcnew OpenFileDialog;
	opnFileDlg->Multiselect = true;

	if (opnFileDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		if (opnFileDlg->FileName->IndexOf("jpeg") > 0 | opnFileDlg->FileName->IndexOf("jpg") > 0 || opnFileDlg->FileName->IndexOf("bmp") > 0 )
		{
			Img_Source2 = gcnew Bitmap(opnFileDlg->FileName);
			pictureBox_Source2->Image = Img_Source2;
		}
		if (opnFileDlg->FileName->IndexOf("pcx") > 0)
		{
			PCXData data;
			LoadPCXFile(opnFileDlg->FileName, data);
			Img_Source2 = data.Image;
			pictureBox_Source2->Image = Img_Source2;
			pictureBox_Colomap2->Image = data.ColorMap;
			label32->Text = data.Manufacturer;
			label31->Text = data.version.ToString();
			label30->Text = data.Encoding.ToString();
			label29->Text = data.BitsPerPixel.ToString();
			label28->Text = data.Image->Width.ToString() + "*" + data.Image->Height.ToString();
			label27->Text = data.Hdpi.ToString() + "-" + data.Vdpi.ToString();
			label26->Text = data.BitsPerPixel.ToString();
			label25->Text=data.reserved.ToString();
			label24->Text = data.NPlanes;
			label23->Text = data.BytePerLine.ToString();
		}
	}
}
private: System::Void pictureBox_Source1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
}
private: System::Void pictureBox_Source1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (Img_Source != nullptr) {
		Pos_X->Text = e->X.ToString();
		Pos_Y->Text = e->Y.ToString();
		System::String ^str;
		if (0 < e->X && e->X < Img_Source->Width && 0 < e->Y && e->Y < Img_Source->Height)
		{
			Color c = Img_Source->GetPixel(e->X, e->Y);
			str = "RGB:(" + c.R.ToString() + " , " + c.G.ToString() + " , " + c.B.ToString() + ")";
			Pos_RGBvalue->Text = str;
		}
	}
}
private: System::Void pictureBox_Source2_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (Img_Source2 != nullptr) {
		label33->Text = e->X.ToString();
		label22->Text = e->Y.ToString();
		System::String ^str;
		if (0 < e->X && e->X < Img_Source2->Width && 0 < e->Y && e->Y < Img_Source2->Height)
		{
			Color c = Img_Source2->GetPixel(e->X, e->Y);
			str = "RGB:(" + c.R.ToString() + " , " + c.G.ToString() + " , " + c.B.ToString() + ")";
			label21->Text = str;
		}
	}
}

private: System::Void Rotation_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	int theta = Convert::ToInt32(Rotation->Text);//Ū����J������
	Bitmap ^ img_processed;
	if (ChkBox_Forward_Rotation->Checked == true)
	{
		ChkBox_Inverse_Rotation->Checked = false;
		Forward_Rotate(Img_Source, img_processed, theta);
	}
	if (ChkBox_Inverse_Rotation->Checked == true)
	{
		ChkBox_Forward_Rotation->Checked = false;
		Inverse_Rotation(Img_Source, img_processed, theta);
	}
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed;
}
public:void Forward_Rotate(Bitmap ^src, Bitmap ^%dst, double theta)
{
	double vcos, vsin;
	int min_x = 1000;
	int min_y = 1000;
	if (theta < 0) theta += 360;  //ex:��-30�׸���330�׬O�@�˪��N��
	theta *= 0.01745329252; // ���y��
	vsin = sin(theta), vcos = cos(theta);  //��Xsin cos��
	if (Img_Source == nullptr)
		MessageBox::Show("No image1 input");
	else
	{
		int  newWidth = abs(src->Width*vcos) + abs(src->Height*vsin);  //��X��ϱ����ΨӶ�J��Ϫ��x�Ϊ��e
		int newHeight = abs(src->Width*vsin) + abs(src->Height*vcos);  //
		Bitmap^ temp_result = gcnew Bitmap(newWidth, newHeight, src->PixelFormat);  //�ЫإX�@�ӥi�H��U�����x�Ϊ��x��


		for (int i = 0; i < src->Width; i++)
		{
			for (int j = 0; j < src->Height; j++)
			{
				int nx, ny;  //����᪺x y�y��
				nx = (int)(vcos*i - vsin*j);
				ny = (int)(vsin*i + vcos*j);
				if (nx < min_x) min_x = nx;  //��X��@���ഫ�᪺�̤p�y���Imin_x min_y(�]���O���I������ҥH�|�O�t�ȩ�0)
				if (ny < min_y) min_y = ny;
			}
		}
		min_x = abs(min_x);  //������ȨD�o�����q�A�ΨӱN����᪺�ϭץ��^�y�Ч��j�󵥩�0
		min_y = abs(min_y);
		for (int i = 0; i < temp_result->Width; i++) //�N�x�Ϊ��C�ⰵ���P�I���P��
			for (int j = 0; j < temp_result->Height; j++)
			{
				temp_result->SetPixel(i, j, Color::FromArgb(240, 240, 240));  //240
			}
		for (int i = 0; i < src->Width; i++)
		{
			for (int j = 0; j < src->Height; j++)
			{
				int nx, ny;
				nx = (int)(vcos*i - vsin*j + min_x + 0.5);
				ny = (int)(vsin*i + vcos*j + min_y + 0.5);
				if ((nx < newWidth) && (ny < newHeight)) //�ˬd�O�_���b��ϱ���Უ�ͪ��x�Τ�
					temp_result->SetPixel(nx, ny, src->GetPixel(i, j));
			}
		}
		Rectangle cloneRect = Rectangle(0, 0, temp_result->Width, temp_result->Height);
		dst = temp_result->Clone(cloneRect, src->PixelFormat);
		delete temp_result;
	}
}
private:void Inverse_Rotation(Bitmap ^src, Bitmap ^%dst, double theta) {

		   double vcos, vsin;
		   int min_x = 1000;
		   int min_y = 1000;
		   if (theta < 0) theta += 360;  //ex:��-30�׸���330�׬O�@�˪��N��
		   theta *= 0.01745329252; // ���y��
		   vsin = sin(theta), vcos = cos(theta);  //��Xsin cos��
		   if (Img_Source == nullptr)
			   MessageBox::Show("No image1 input");
		   else
		   {
			   int  newWidth = abs(src->Width*vcos) + abs(src->Height*vsin);  //��X��ϱ����ΨӶ�J��Ϫ��x�Ϊ��e
			   int newHeight = abs(src->Width*vsin) + abs(src->Height*vcos);  //
			   Bitmap^ temp_result = gcnew Bitmap(newWidth, newHeight, src->PixelFormat);//�ЫإX�@�ӥi�H��U�����x�Ϊ��x��


			   for (int i = 0; i < src->Width; i++)
			   {
				   for (int j = 0; j < src->Height; j++)
				   {
					   int nx, ny;  //��ϱ���᪺x y�y��
					   nx = (int)(vcos*i - vsin*j);
					   ny = (int)(vsin*i + vcos*j);
					   if (nx < min_x) min_x = nx;  //��X��@���ഫ�᪺�̤p�y���Imin_x min_y(�]���O���I������ҥH�|�O�t�ȩ�0)
					   if (ny < min_y) min_y = ny;
				   }
			   }
			   for (int i = min_x; i < min_x + newWidth; i++)
			   {
				   for (int j = min_y; j < min_y + newHeight; j++)
				   {
					   int nx, ny;  //�f����᪺x y�y��
					   nx = (int)(vcos*i + vsin*j + 0.5);
					   ny = (int)(-vsin*i + vcos*j + 0.5);
					   if ((nx < src->Width) && (nx > 0) && (ny < src->Height) && (ny > 0))  //�b��Ϥ�
						   temp_result->SetPixel(i + abs(min_x), j + abs(min_y), src->GetPixel(nx, ny));  //abs�Ψӭץ������q
					   else  //�b��ϥ~(�]���P�I���ۦP�C��)
						   temp_result->SetPixel(i + abs(min_x), j + abs(min_y), Color::FromArgb(240, 240, 240));  //240
				   }
			   }

			   Rectangle cloneRect = Rectangle(0, 0, temp_result->Width, temp_result->Height);
			   dst = temp_result->Clone(cloneRect, src->PixelFormat);
			   delete temp_result;
		   }
	   }
private: System::Void Threshold_value_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	int threshold_value = Convert::ToInt32(Threshold_value->Text);
	ConvertColor(Img_Source, img_processed, RGB2Gray);
	if (RadioBtn_Threshold_Binary->Checked == true)
	{
	RadioBtn_Threshold_inv_Binary->Checked =false;
	Threshold(img_processed, img_processed, threshold_value, THRESH_BINARY);
	}
	if (RadioBtn_Threshold_inv_Binary->Checked == true)
	{
		RadioBtn_Threshold_Binary->Checked = false;
		Threshold(img_processed, img_processed, threshold_value, THRESH_BINARY_Inv);
	}
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed;
}
private: System::Void numericUpDown_transparent_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
    float percent =(float) Convert::ToInt32(numericUpDown_transparent->Text);
     percent /= 100;
	 if (Img_Source != nullptr && Img_Source2 != nullptr)
	 {
		 if ((Img_Source->Width != Img_Source2->Width) || (Img_Source->Height != Img_Source2->Height))

			 MessageBox::Show("Size must be Same!!");

		 else
		 {
			 Img_Stack = gcnew Bitmap(Img_Source->Width, Img_Source->Height);
			 for (size_t i = 0; i < Img_Source->Width; i++)
			 {
				 for (size_t j = 0; j < Img_Source->Height; j++)
				 {
					 Color color_B = Img_Source->GetPixel(i, j);
					 Color color_T = Img_Source2->GetPixel(i, j);
					 int R = (1 - percent)*color_B.R + percent*color_T.R;
					 int G = (1 - percent)*color_B.G + percent*color_T.G;
					 int B = (1 - percent)*color_B.B + percent*color_T.B;
					 Color color = Color::FromArgb(R, G, B);
					 Img_Stack->SetPixel(i, j, color);
				 }
			 }
			 pictureBox_Result->Image = Img_Stack;

		 }
	 }
}
private: System::Void pictureBox_Result_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		System::Drawing::Imaging::PixelFormat format = Img_Source->PixelFormat;
		System::Drawing::Graphics^ Reference_rec;
		Rectangle cloneRect = Rectangle(0, 0, Img_Source->Width, Img_Source->Height);
		Bitmap ^temp = Img_Source->Clone(cloneRect, format);
		Pen^ ReferencePen = gcnew Pen(Color::Red, 2.0F);
		Point LBtnMove = e->Location;
		int X_size = LBtnMove.X - LBtnDown.X; //X�y�Ь۴�
		int Y_size = LBtnMove.Y - LBtnDown.Y; //Y�y�Ь۴�
		switch (d_Pen)
		{
			/*case Pen_None:
			pictureBox2->Image = img_source;
			break;*/
		case Pen_Line:
			//d_Line(temp, LBtnDown, LBtnUp);
			pictureBox_Result->Image = Img_Stack;
			pictureBox_Result->Refresh();
			Reference_rec = pictureBox_Result->CreateGraphics();
			Reference_rec->DrawLine(ReferencePen, LBtnDown.X, LBtnDown.Y, LBtnMove.X, LBtnMove.Y);
			break;
		case Pen_Circle:  //��Ϊ�X��Y Size���t�Ȩ̵M�i�Hø��
						  //d_Circle(temp, LBtnDown, LBtnUp);
			pictureBox_Result->Image = Img_Stack;
			pictureBox_Result->Refresh();
			Reference_rec = pictureBox_Result->CreateGraphics();
			if (X_size > 0)  //�ѥ��V�k�e��
			{
				if (Y_size > 0) //���W�V�k�U�e��  X_size +  Y_size +
					Reference_rec->DrawEllipse(ReferencePen, LBtnDown.X, LBtnDown.Y, X_size, Y_size);
				if (Y_size < 0) //���U�V�k�W�e��  X_size +  Y_size -
					Reference_rec->DrawEllipse(ReferencePen, LBtnDown.X, LBtnDown.Y, X_size, Y_size);
			}

			if (X_size < 0) //�k�V���e��
			{
				if (Y_size > 0) //�k�W�V���U�e��  X_size -  Y_size +
					Reference_rec->DrawEllipse(ReferencePen, LBtnDown.X, LBtnDown.Y, X_size, Y_size);
				if (Y_size < 0) //�k�U�V���W�e�� X_size -  Y_size +
					Reference_rec->DrawEllipse(ReferencePen, LBtnDown.X, LBtnDown.Y, X_size, Y_size);
			}
			break;
		case Pen_Rect:  //***�`�N:�x�Ϊ�Size�p���t�ȫh�L�kø�� �]�������������***
						//d_Rect(temp, LBtnDown, LBtnMove);
			pictureBox_Result->Image = Img_Stack;
			pictureBox_Result->Refresh();
			Reference_rec = pictureBox_Result->CreateGraphics();
			if (X_size > 0)  //�ѥ��V�k�e�x��
			{
				if (Y_size > 0) //���W�V�k�U�x��  X_size +  Y_size +
					Reference_rec->DrawRectangle(ReferencePen, LBtnDown.X, LBtnDown.Y, X_size, Y_size);
				if (Y_size < 0) //���U�V�k�W�x��  X_size +  Y_size -
					Reference_rec->DrawRectangle(ReferencePen, LBtnDown.X, LBtnMove.Y, X_size, Math::Abs(Y_size));
			}

			if (X_size < 0) //�k�V���x��
			{
				if (Y_size > 0) //�k�W�V���U�x��  X_size -  Y_size +
					Reference_rec->DrawRectangle(ReferencePen, LBtnMove.X, LBtnDown.Y, Math::Abs(X_size), Y_size);
				if (Y_size < 0) //�k�U�V���W�x�� X_size -  Y_size +
					Reference_rec->DrawRectangle(ReferencePen, LBtnMove.X, LBtnMove.Y, Math::Abs(X_size), Math::Abs(Y_size));
			}
			break;
		case Pen_CloudLine:
			Reference_rec = pictureBox_Result->CreateGraphics();
			CloudLinePoint.push_back(e->Location);
			Reference_rec->DrawLine(ReferencePen
				, CloudLinePoint[CloudLinePoint.size() - 2].X
				, CloudLinePoint[CloudLinePoint.size() - 2].Y
				, CloudLinePoint[CloudLinePoint.size() - 1].X
				, CloudLinePoint[CloudLinePoint.size() - 1].Y);

			break;
		default:
			break;
		}
	}
}
private: System::Void pictureBox_Result_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	LBtnDown = e->Location;
	CloudLinePoint.resize(0);
	CloudLinePoint.push_back(e->Location);
}
private: System::Void Btn_Line_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	d_Pen = Pen_Line;
}
private: System::Void Btn_Circle_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	d_Pen = Pen_Circle;
}
private: System::Void Btn_Rectangle_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	d_Pen = Pen_Rect;
}
private: System::Void Btn_CloudLine_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	d_Pen = Pen_CloudLine;
}
private: System::Void Btn_None_Draw_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	d_Pen = Pen_None;
}
private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {

	RGBHistigram ^RGB_His = gcnew RGBHistigram;
	unsigned char His_Color[256][3] = { { 0 } }; 

	for (unsigned int i = 0; i < Img_Source->Width; i++)
	{
		for (unsigned int j = 0; j < Img_Source->Height; j++)
		{
			int B = Img_Source->GetPixel(i, j).B;
			int R = Img_Source->GetPixel(i, j).R;
			int G = Img_Source->GetPixel(i, j).G;
		
			His_Color[R][0] += 1; 
			His_Color[G][1] += 1;
			His_Color[B][2] += 1;
			
		}
	}
	
	for (int i = 0; i < 256; i++) 
	{
		RGB_His->chart_RGB->Series["R"]->Points->AddXY(i, His_Color[i][0]);
		RGB_His->chart_RGB->Series["G"]->Points->AddXY(i, His_Color[i][1]);
		RGB_His->chart_RGB->Series["B"]->Points->AddXY(i, His_Color[i][2]);
	}
	RGB_His->Show(); //�q�X�έp��
}
private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	double Rate = Convert::ToDouble(ZoomRate->Text);
	ZoomFunction(Img_Source, img_processed, Rate, Zoom);
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed;
}
public:void ZoomFunction(Bitmap ^src, Bitmap ^%dst, double ZoomRate, int code)  //��j�Y�p
 {
   if (ZoomRate > 0 && src != nullptr)
   {
   
	 switch (code)
	{
     case Zoom:
		 dst = gcnew Bitmap((int)src->Width*ZoomRate + 0.5, (int)src->Height*ZoomRate + 0.5);
       for (unsigned int i = 0; i < dst->Width; i++)
          for (unsigned int j = 0; j < dst->Height; j++)
            {
			  float index_x = (float)(i / ZoomRate);
			  float index_y = (float)(j / ZoomRate);
			  dst->SetPixel(i, j, src->GetPixel((int)index_x + 0.5, (int)index_y + 0.5));
		   }
             break;
	 case Interpolation:
		 dst = gcnew Bitmap((int)src->Width*ZoomRate + 0.5, (int)src->Height*ZoomRate + 0.5);
		if (ZoomRate < 1) MessageBox::Show("Please enter number bigger than 1.");
		 else
	     {
			for (unsigned int j = 0; j < dst->Height; j++)
			{
			 for (unsigned int i = 0; i < dst->Width; i++)
			 {
			  float real_X = i / ZoomRate;
			  float real_Y = j / ZoomRate;
			  int set_X = (int)real_X; //pixel��m�����
			  int set_Y = (int)real_Y;
								 float difference_X = real_X - set_X;  //���pixel��m�P��j���ƶ����~�t
								 float difference_Y = real_Y - set_Y;
								 if (difference_X < 0)
								 {
									 difference_X = 1 + difference_X;
									 set_X = set_X - 1;
								 }

								 if (difference_Y < 0)
								 {
									 difference_Y = 1 + difference_Y;
									 set_Y = set_Y - 1;
								 }

								 if (set_X >= src->Width - 1)//�ˬd�O�_���W�L��Ϫ��e(���ȷ|�H�a�񪺨���pixel�@�����I���ȡA�ҥH�i��W�X�d��)
								 {
									 difference_X = 1;
									 set_X = set_X - 1;
								 }
								 if (set_Y >= src->Height - 1)//�ˬd�O�_���W�L��Ϫ���
								 {
									 difference_Y = 1;
									 set_Y = set_Y - 1;
								 }
								 int R = 0.5*((1 - difference_X) * (src->GetPixel(set_X, set_Y).R + src->GetPixel(set_X, set_Y).R) + difference_X * (src->GetPixel(set_X + 1, set_Y).R + src->GetPixel(set_X, set_Y + 1).R));
								 int G = 0.5*((1 - difference_X) * (src->GetPixel(set_X, set_Y).G + src->GetPixel(set_X, set_Y).G) + difference_X * (src->GetPixel(set_X + 1, set_Y).G + src->GetPixel(set_X, set_Y + 1).G));
								 int B = 0.5*((1 - difference_X) * (src->GetPixel(set_X, set_Y).B + src->GetPixel(set_X, set_Y).B) + difference_X * (src->GetPixel(set_X + 1, set_Y).B + src->GetPixel(set_X, set_Y + 1).B));

								 Color c = Color::FromArgb(R, G, B);
								 dst->SetPixel(i, j, c);
								 //dst->SetPixel(i, j, src->GetPixel((int)index_x + 0.5, (int)index_y + 0.5));
							 }
						 }
					 }
					 break;

				 case Average:
					 dst = gcnew Bitmap((int)src->Width/ZoomRate + 0.5, (int)src->Height/ZoomRate + 0.5);
					 if ((ZoomRate - (int)ZoomRate) != 0)
						 MessageBox::Show("Please enter integer.");
					 else
					 {
						 double mean = (double)(1 / (ZoomRate*ZoomRate));
						 for (unsigned int j = 0; j < dst->Height; j++)
						 {
							 for (unsigned int i = 0; i < dst->Width; i++)
							 {
								 int ori_R = 0;
								 int ori_G = 0;
								 int ori_B = 0;
								 for (int average_y = 0; average_y < (ZoomRate); average_y++)
								 {
									 for (int average_x = 0; average_x < (ZoomRate); average_x++)
									 {
										 int set_x = ZoomRate * i + average_x;
										 int set_y = ZoomRate * j + average_y;
										 if (set_x >= src->Width)  //���i�H�W�X��Ͻd��
											 set_x = src->Width - 1;
										 if (set_y >= src->Height)
											 set_y = src->Height - 1;
										 ori_R += src->GetPixel(set_x, set_y).R;
										 ori_G += src->GetPixel(set_x, set_y).G;
										 ori_B += src->GetPixel(set_x, set_y).B;
									 }
								 }
								 ori_R = ori_R * mean;
								 ori_G = ori_G * mean;
								 ori_B = ori_B * mean;
								 dst->SetPixel(i, j, Color::FromArgb(ori_R, ori_G, ori_B));
							 }
						 }
					 }
					 break;
				 default:
					 break;
				 }
			 }
			 else
			 {
				 MessageBox::Show("No Image yet or Rate cannot be smaller than zero!");
			 }
		 }
private: System::Void toolStripButton3_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	double Rate = Convert::ToDouble(ZoomRate->Text);
	if (Rate != 0) {
		Rate = 1 / Rate;
		ZoomFunction(Img_Source, img_processed, Rate, Zoom);
		pictureBox_Result->Image = img_processed;
		pictureBox_Result->Refresh();
	}
	else
		MessageBox::Show("Can not be zero");
	delete img_processed;
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
private: System::Void toolStripButton4_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	double Rate = Convert::ToDouble(ZoomRate->Text);
	ZoomFunction(Img_Source, img_processed, Rate, Interpolation);
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed;
}
private: System::Void toolStripButton5_Click(System::Object^  sender, System::EventArgs^  e) {
	
	Bitmap ^ img_processed;
	double Rate = Convert::ToDouble(ZoomRate->Text);
	ZoomFunction(Img_Source, img_processed, Rate, Average);
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed; 
}
};
}
