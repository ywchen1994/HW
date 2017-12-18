#pragma once
#include <iostream> 
#include <stdio.h >  
#include <stdlib.h >  
#include<cmath>
#include <cliext/vector>  
#include"RGBHistigram.h"
#include"BitPlaneUI.h"
#include"Bouncingball.h"
#include"SelfDefineContrast.h"
#include"Huffman.h"
typedef unsigned int uint;
typedef unsigned char uchar;
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
		Interpolation,//插值放大
		Average, //平均縮小
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
	/// ImageProcessUI 的摘要
	/// </summary>
	public ref class ImageProcessUI : public System::Windows::Forms::Form
	{
	public:
		ImageProcessUI(void)
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

	public:static Bitmap ^Img_Source, ^Img_Source2,^Img_Stack,^Img_tempMask;
	private: System::Windows::Forms::TabControl^  Tab_Image1;
	public:

	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::PictureBox^  pictureBox_Source1;


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
public: System::Windows::Forms::PictureBox^  pictureBox_Result;
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
		/// 設計工具所需的變數。
		/// </summary>
		cliext::vector<Point>CloudLinePoint;
private: System::Windows::Forms::Button^  Btn_CreateWndow;
private: System::Windows::Forms::ToolStripButton^  toolStripButton6;
private: System::Windows::Forms::GroupBox^  groupBox9;
private: System::Windows::Forms::ToolStrip^  toolStrip6;
private: System::Windows::Forms::ToolStripButton^  toolStripButton7;
private: System::Windows::Forms::ToolStripButton^  toolStripButton8;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::GroupBox^  groupBox10;
private: System::Windows::Forms::ToolStrip^  toolStrip7;
private: System::Windows::Forms::ToolStripButton^  toolStripButton9;
private: System::Windows::Forms::ToolStripButton^  toolStripButton10;
private: System::Windows::Forms::GroupBox^  groupBox11;
private: System::Windows::Forms::ToolStrip^  toolStrip8;
private: System::Windows::Forms::ToolStripButton^  toolStripButton11;
private: System::Windows::Forms::GroupBox^  groupBox12;
private: System::Windows::Forms::NumericUpDown^  LowPassSize;
private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::GroupBox^  groupBox13;
private: System::Windows::Forms::ToolStrip^  toolStrip9;
private: System::Windows::Forms::ToolStripButton^  toolStripButton12;
private: System::Windows::Forms::ToolStripButton^  toolStripButton13;
private: System::Windows::Forms::ToolStripButton^  toolStripButton14;
private: System::Windows::Forms::ToolStripButton^  toolStripButton15;
private: System::Windows::Forms::ToolStripButton^  toolStripButton16;
private: System::Windows::Forms::ToolStripButton^  toolStripButton17;
private: System::Windows::Forms::ToolStripButton^  toolStripButton18;
private: System::Windows::Forms::ToolStripButton^  toolStripButton19;
private: System::Windows::Forms::GroupBox^  groupBox14;
private: System::Windows::Forms::NumericUpDown^  A;

private: System::Windows::Forms::Label^  label49;
private: System::Windows::Forms::ToolStripMenuItem^  編碼ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  huffmenToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  connectComponentToolStripMenuItem;
private: System::Windows::Forms::GroupBox^  groupBox15;
private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::NumericUpDown^  Median_FilterSize;
private: System::Windows::Forms::RadioButton^  RadioBtn_Cross;
private: System::Windows::Forms::RadioButton^  RadioBtn_Square;
private: System::Windows::Forms::RadioButton^  RadioBtn_MinMax;
private: System::Windows::Forms::RadioButton^  RadioBtn_MaxMin;


		 Point LBtnUP;

#pragma region Windows Form Designer generated code
		ref struct PCXData//http://www.fysnet.net/pcxfile.htm  PCX解封包資料
		{
			String ^filePath;//檔案路徑
			String ^fileName;//檔案名稱
			String^ Manufacturer;//Zsoft ID
			int version;//版本
			int Encoding;//PCX run-length encoding
			int Hdpi;//
			int Vdpi;//
			int reserved;//
			String^ NPlanes;//
			String^ color;//灰階 彩色
			int HscreenSize;//Video screen size (Horizontal)
			int VscreenSize;// Video screen size (Vertical)
			Bitmap^ Image;//
			int BytePerLine;//
			int BitsPerPixel;//
			Bitmap^ ColorMap;//
		};
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
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
			this->編碼ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->huffmenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->connectComponentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->ChkBox_Inverse_Rotation = (gcnew System::Windows::Forms::RadioButton());
			this->ChkBox_Forward_Rotation = (gcnew System::Windows::Forms::RadioButton());
			this->Rotation = (gcnew System::Windows::Forms::NumericUpDown());
			this->pictureBox_Result = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->RadioBtn_Threshold_inv_Binary = (gcnew System::Windows::Forms::RadioButton());
			this->RadioBtn_Threshold_Binary = (gcnew System::Windows::Forms::RadioButton());
			this->Threshold_value = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->toolStrip4 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->Btn_CreateWndow = (gcnew System::Windows::Forms::Button());
			this->numericUpDown_transparent = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->Btn_CloudLine = (gcnew System::Windows::Forms::RadioButton());
			this->Btn_Rectangle = (gcnew System::Windows::Forms::RadioButton());
			this->Btn_Circle = (gcnew System::Windows::Forms::RadioButton());
			this->Btn_None_Draw = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->ZoomRate = (gcnew System::Windows::Forms::NumericUpDown());
			this->toolStrip5 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->toolStrip6 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton7 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton8 = (gcnew System::Windows::Forms::ToolStripButton());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->toolStrip7 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton9 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton10 = (gcnew System::Windows::Forms::ToolStripButton());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->toolStrip8 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton11 = (gcnew System::Windows::Forms::ToolStripButton());
			this->groupBox12 = (gcnew System::Windows::Forms::GroupBox());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->LowPassSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox13 = (gcnew System::Windows::Forms::GroupBox());
			this->toolStrip9 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton12 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton13 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton14 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton15 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton16 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton17 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton18 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton19 = (gcnew System::Windows::Forms::ToolStripButton());
			this->groupBox14 = (gcnew System::Windows::Forms::GroupBox());
			this->A = (gcnew System::Windows::Forms::NumericUpDown());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->groupBox15 = (gcnew System::Windows::Forms::GroupBox());
			this->RadioBtn_Cross = (gcnew System::Windows::Forms::RadioButton());
			this->RadioBtn_Square = (gcnew System::Windows::Forms::RadioButton());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->Median_FilterSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->RadioBtn_MaxMin = (gcnew System::Windows::Forms::RadioButton());
			this->RadioBtn_MinMax = (gcnew System::Windows::Forms::RadioButton());
			this->menuStrip1->SuspendLayout();
			this->Tab_Image1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Colomap1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Source1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Colomap2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Source2))->BeginInit();
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
			this->groupBox9->SuspendLayout();
			this->toolStrip6->SuspendLayout();
			this->groupBox10->SuspendLayout();
			this->toolStrip7->SuspendLayout();
			this->groupBox11->SuspendLayout();
			this->toolStrip8->SuspendLayout();
			this->groupBox12->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LowPassSize))->BeginInit();
			this->groupBox13->SuspendLayout();
			this->toolStrip9->SuspendLayout();
			this->groupBox14->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A))->BeginInit();
			this->groupBox15->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Median_FilterSize))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->編碼ToolStripMenuItem, this->connectComponentToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1438, 24);
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
			this->fileToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openToolStripMenuItem.Image")));
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->openToolStripMenuItem->Text = L"OpenFile";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &ImageProcessUI::openToolStripMenuItem_Click);
			// 
			// openFile2ToolStripMenuItem
			// 
			this->openFile2ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openFile2ToolStripMenuItem.Image")));
			this->openFile2ToolStripMenuItem->Name = L"openFile2ToolStripMenuItem";
			this->openFile2ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			this->openFile2ToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->openFile2ToolStripMenuItem->Text = L"OpenFile2";
			this->openFile2ToolStripMenuItem->Click += gcnew System::EventHandler(this, &ImageProcessUI::openFile2ToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exitToolStripMenuItem.BackgroundImage")));
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->exitToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &ImageProcessUI::exitToolStripMenuItem_Click);
			// 
			// 編碼ToolStripMenuItem
			// 
			this->編碼ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->huffmenToolStripMenuItem });
			this->編碼ToolStripMenuItem->Name = L"編碼ToolStripMenuItem";
			this->編碼ToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->編碼ToolStripMenuItem->Text = L"編碼";
			// 
			// huffmenToolStripMenuItem
			// 
			this->huffmenToolStripMenuItem->Name = L"huffmenToolStripMenuItem";
			this->huffmenToolStripMenuItem->Size = System::Drawing::Size(123, 22);
			this->huffmenToolStripMenuItem->Text = L"Huffmen";
			this->huffmenToolStripMenuItem->Click += gcnew System::EventHandler(this, &ImageProcessUI::huffmenToolStripMenuItem_Click);
			// 
			// connectComponentToolStripMenuItem
			// 
			this->connectComponentToolStripMenuItem->Name = L"connectComponentToolStripMenuItem";
			this->connectComponentToolStripMenuItem->Size = System::Drawing::Size(137, 20);
			this->connectComponentToolStripMenuItem->Text = L"Connect Component";
			this->connectComponentToolStripMenuItem->Click += gcnew System::EventHandler(this, &ImageProcessUI::connectComponentToolStripMenuItem_Click);
			// 
			// Tab_Image1
			// 
			this->Tab_Image1->Controls->Add(this->tabPage1);
			this->Tab_Image1->Controls->Add(this->tabPage2);
			this->Tab_Image1->Location = System::Drawing::Point(26, 162);
			this->Tab_Image1->Margin = System::Windows::Forms::Padding(2);
			this->Tab_Image1->Name = L"Tab_Image1";
			this->Tab_Image1->SelectedIndex = 0;
			this->Tab_Image1->Size = System::Drawing::Size(669, 507);
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
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Margin = System::Windows::Forms::Padding(2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(2);
			this->tabPage1->Size = System::Drawing::Size(661, 481);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Image1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// Pos_RGBvalue
			// 
			this->Pos_RGBvalue->AutoSize = true;
			this->Pos_RGBvalue->Location = System::Drawing::Point(232, 461);
			this->Pos_RGBvalue->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Pos_RGBvalue->Name = L"Pos_RGBvalue";
			this->Pos_RGBvalue->Size = System::Drawing::Size(0, 12);
			this->Pos_RGBvalue->TabIndex = 26;
			// 
			// Pos_Y
			// 
			this->Pos_Y->AutoSize = true;
			this->Pos_Y->Location = System::Drawing::Point(122, 461);
			this->Pos_Y->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Pos_Y->Name = L"Pos_Y";
			this->Pos_Y->Size = System::Drawing::Size(0, 12);
			this->Pos_Y->TabIndex = 22;
			// 
			// Pos_X
			// 
			this->Pos_X->AutoSize = true;
			this->Pos_X->Location = System::Drawing::Point(34, 461);
			this->Pos_X->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Pos_X->Name = L"Pos_X";
			this->Pos_X->Size = System::Drawing::Size(0, 12);
			this->Pos_X->TabIndex = 23;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(92, 461);
			this->label19->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(16, 12);
			this->label19->TabIndex = 24;
			this->label19->Text = L"Y:";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(14, 461);
			this->label20->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(16, 12);
			this->label20->TabIndex = 25;
			this->label20->Text = L"X:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label10->Location = System::Drawing::Point(427, 312);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(111, 15);
			this->label10->TabIndex = 21;
			this->label10->Text = L"BitsPerPixel:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(547, 410);
			this->label18->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(0, 12);
			this->label18->TabIndex = 12;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(547, 377);
			this->label17->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(0, 12);
			this->label17->TabIndex = 12;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(547, 315);
			this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(0, 12);
			this->label15->TabIndex = 12;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(547, 344);
			this->label16->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(0, 12);
			this->label16->TabIndex = 12;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(547, 204);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(0, 12);
			this->label14->TabIndex = 12;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(547, 174);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 12);
			this->label13->TabIndex = 12;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(547, 142);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 12);
			this->label12->TabIndex = 12;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(547, 114);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 12);
			this->label11->TabIndex = 12;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(547, 82);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 12);
			this->label9->TabIndex = 12;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(547, 50);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 12);
			this->label8->TabIndex = 11;
			// 
			// pictureBox_Colomap1
			// 
			this->pictureBox_Colomap1->Location = System::Drawing::Point(529, 233);
			this->pictureBox_Colomap1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox_Colomap1->Name = L"pictureBox_Colomap1";
			this->pictureBox_Colomap1->Size = System::Drawing::Size(81, 64);
			this->pictureBox_Colomap1->TabIndex = 10;
			this->pictureBox_Colomap1->TabStop = false;
			// 
			// bytesperline_lbl
			// 
			this->bytesperline_lbl->AutoSize = true;
			this->bytesperline_lbl->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->bytesperline_lbl->Location = System::Drawing::Point(428, 404);
			this->bytesperline_lbl->Name = L"bytesperline_lbl";
			this->bytesperline_lbl->Size = System::Drawing::Size(89, 17);
			this->bytesperline_lbl->TabIndex = 7;
			this->bytesperline_lbl->Text = L"BytesPerLine:";
			// 
			// nplanes_lbl
			// 
			this->nplanes_lbl->AutoSize = true;
			this->nplanes_lbl->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->nplanes_lbl->Location = System::Drawing::Point(428, 371);
			this->nplanes_lbl->Name = L"nplanes_lbl";
			this->nplanes_lbl->Size = System::Drawing::Size(60, 17);
			this->nplanes_lbl->TabIndex = 8;
			this->nplanes_lbl->Text = L"NPlanes:";
			// 
			// reserved_lbl
			// 
			this->reserved_lbl->AutoSize = true;
			this->reserved_lbl->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->reserved_lbl->Location = System::Drawing::Point(428, 338);
			this->reserved_lbl->Name = L"reserved_lbl";
			this->reserved_lbl->Size = System::Drawing::Size(66, 17);
			this->reserved_lbl->TabIndex = 9;
			this->reserved_lbl->Text = L"Reserved:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(427, 142);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(111, 15);
			this->label5->TabIndex = 1;
			this->label5->Text = L"BitsPerPixel:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(427, 202);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(87, 15);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Hdpi-Vdpi:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(427, 172);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 15);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Window:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label7->Location = System::Drawing::Point(427, 233);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(87, 15);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Color map:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(427, 111);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 15);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Encoding:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(427, 81);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Version:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(427, 50);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Manufacturer:";
			// 
			// pictureBox_Source1
			// 
			this->pictureBox_Source1->Location = System::Drawing::Point(12, 24);
			this->pictureBox_Source1->Margin = System::Windows::Forms::Padding(2);
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
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Margin = System::Windows::Forms::Padding(2);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(2);
			this->tabPage2->Size = System::Drawing::Size(661, 481);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Image2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(232, 459);
			this->label21->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(33, 12);
			this->label21->TabIndex = 43;
			this->label21->Text = L"label2";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(136, 459);
			this->label22->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(33, 12);
			this->label22->TabIndex = 39;
			this->label22->Text = L"label1";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(34, 459);
			this->label33->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(33, 12);
			this->label33->TabIndex = 40;
			this->label33->Text = L"label1";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(92, 459);
			this->label34->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(16, 12);
			this->label34->TabIndex = 41;
			this->label34->Text = L"Y:";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(14, 459);
			this->label46->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(16, 12);
			this->label46->TabIndex = 42;
			this->label46->Text = L"X:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(546, 417);
			this->label23->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(0, 12);
			this->label23->TabIndex = 31;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(546, 384);
			this->label24->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(0, 12);
			this->label24->TabIndex = 32;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(546, 351);
			this->label25->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(0, 12);
			this->label25->TabIndex = 33;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(547, 318);
			this->label26->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(0, 12);
			this->label26->TabIndex = 38;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(547, 207);
			this->label27->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(0, 12);
			this->label27->TabIndex = 35;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(547, 177);
			this->label28->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(0, 12);
			this->label28->TabIndex = 34;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(547, 145);
			this->label29->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(0, 12);
			this->label29->TabIndex = 37;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(547, 118);
			this->label30->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(0, 12);
			this->label30->TabIndex = 36;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(547, 86);
			this->label31->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(0, 12);
			this->label31->TabIndex = 29;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(547, 54);
			this->label32->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(0, 12);
			this->label32->TabIndex = 28;
			// 
			// pictureBox_Colomap2
			// 
			this->pictureBox_Colomap2->Location = System::Drawing::Point(529, 236);
			this->pictureBox_Colomap2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox_Colomap2->Name = L"pictureBox_Colomap2";
			this->pictureBox_Colomap2->Size = System::Drawing::Size(81, 64);
			this->pictureBox_Colomap2->TabIndex = 27;
			this->pictureBox_Colomap2->TabStop = false;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label35->Location = System::Drawing::Point(427, 414);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(89, 17);
			this->label35->TabIndex = 24;
			this->label35->Text = L"BytesPerLine:";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label36->Location = System::Drawing::Point(427, 381);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(60, 17);
			this->label36->TabIndex = 25;
			this->label36->Text = L"NPlanes:";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label37->Location = System::Drawing::Point(426, 348);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(66, 17);
			this->label37->TabIndex = 26;
			this->label37->Text = L"Reserved:";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label38->Location = System::Drawing::Point(427, 317);
			this->label38->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(111, 15);
			this->label38->TabIndex = 20;
			this->label38->Text = L"BitsPerPixel:";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label39->Location = System::Drawing::Point(427, 145);
			this->label39->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(111, 15);
			this->label39->TabIndex = 19;
			this->label39->Text = L"BitsPerPixel:";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label40->Location = System::Drawing::Point(427, 206);
			this->label40->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(87, 15);
			this->label40->TabIndex = 18;
			this->label40->Text = L"Hdpi-Vdpi:";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label41->Location = System::Drawing::Point(427, 175);
			this->label41->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(63, 15);
			this->label41->TabIndex = 17;
			this->label41->Text = L"Window:";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label42->Location = System::Drawing::Point(427, 236);
			this->label42->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(87, 15);
			this->label42->TabIndex = 16;
			this->label42->Text = L"Color map:";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label43->Location = System::Drawing::Point(427, 114);
			this->label43->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(79, 15);
			this->label43->TabIndex = 15;
			this->label43->Text = L"Encoding:";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label44->Location = System::Drawing::Point(427, 84);
			this->label44->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(71, 15);
			this->label44->TabIndex = 14;
			this->label44->Text = L"Version:";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Font = (gcnew System::Drawing::Font(L"標楷體", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label45->Location = System::Drawing::Point(427, 54);
			this->label45->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(111, 15);
			this->label45->TabIndex = 21;
			this->label45->Text = L"Manufacturer:";
			// 
			// pictureBox_Source2
			// 
			this->pictureBox_Source2->Location = System::Drawing::Point(12, 27);
			this->pictureBox_Source2->Margin = System::Windows::Forms::Padding(2);
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
			this->groupBox1->Location = System::Drawing::Point(16, 26);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(95, 70);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"色彩轉換";
			// 
			// toolStrip2
			// 
			this->toolStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->Btn_ToRed, this->Btn_ToGreen,
					this->Btn_ToBlue
			});
			this->toolStrip2->Location = System::Drawing::Point(2, 44);
			this->toolStrip2->Name = L"toolStrip2";
			this->toolStrip2->Size = System::Drawing::Size(91, 25);
			this->toolStrip2->TabIndex = 1;
			this->toolStrip2->Text = L"toolStrip2";
			// 
			// Btn_ToRed
			// 
			this->Btn_ToRed->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Btn_ToRed->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Btn_ToRed.Image")));
			this->Btn_ToRed->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Btn_ToRed->Name = L"Btn_ToRed";
			this->Btn_ToRed->Size = System::Drawing::Size(23, 22);
			this->Btn_ToRed->Text = L"R";
			this->Btn_ToRed->Click += gcnew System::EventHandler(this, &ImageProcessUI::Btn_ToRed_Click);
			// 
			// Btn_ToGreen
			// 
			this->Btn_ToGreen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Btn_ToGreen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Btn_ToGreen.Image")));
			this->Btn_ToGreen->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Btn_ToGreen->Name = L"Btn_ToGreen";
			this->Btn_ToGreen->Size = System::Drawing::Size(23, 22);
			this->Btn_ToGreen->Text = L"G";
			this->Btn_ToGreen->Click += gcnew System::EventHandler(this, &ImageProcessUI::Btn_ToGreen_Click);
			// 
			// Btn_ToBlue
			// 
			this->Btn_ToBlue->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Btn_ToBlue->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Btn_ToBlue.Image")));
			this->Btn_ToBlue->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Btn_ToBlue->Name = L"Btn_ToBlue";
			this->Btn_ToBlue->Size = System::Drawing::Size(23, 22);
			this->Btn_ToBlue->Text = L"B";
			this->Btn_ToBlue->Click += gcnew System::EventHandler(this, &ImageProcessUI::Btn_ToBlue_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripBtn_Gray });
			this->toolStrip1->Location = System::Drawing::Point(2, 17);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(91, 27);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripBtn_Gray
			// 
			this->toolStripBtn_Gray->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripBtn_Gray.Image")));
			this->toolStripBtn_Gray->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripBtn_Gray->Name = L"toolStripBtn_Gray";
			this->toolStripBtn_Gray->Size = System::Drawing::Size(55, 24);
			this->toolStripBtn_Gray->Text = L"灰階";
			this->toolStripBtn_Gray->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripBtn_Gray_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->toolStrip3);
			this->groupBox2->Location = System::Drawing::Point(127, 26);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(94, 131);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"鏡射";
			// 
			// toolStrip3
			// 
			this->toolStrip3->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip3->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripButton_horizontalFilp,
					this->Btn_verticalFlip, this->toolStripButton_diagonal, this->toolStripButton6
			});
			this->toolStrip3->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::VerticalStackWithOverflow;
			this->toolStrip3->Location = System::Drawing::Point(2, 17);
			this->toolStrip3->Name = L"toolStrip3";
			this->toolStrip3->Size = System::Drawing::Size(90, 119);
			this->toolStrip3->TabIndex = 0;
			this->toolStrip3->Text = L"toolStrip3";
			// 
			// toolStripButton_horizontalFilp
			// 
			this->toolStripButton_horizontalFilp->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_horizontalFilp.Image")));
			this->toolStripButton_horizontalFilp->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_horizontalFilp->Name = L"toolStripButton_horizontalFilp";
			this->toolStripButton_horizontalFilp->Size = System::Drawing::Size(88, 24);
			this->toolStripButton_horizontalFilp->Text = L"水平鏡射";
			this->toolStripButton_horizontalFilp->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton_horizontalFilp_Click);
			// 
			// Btn_verticalFlip
			// 
			this->Btn_verticalFlip->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Btn_verticalFlip.Image")));
			this->Btn_verticalFlip->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Btn_verticalFlip->Name = L"Btn_verticalFlip";
			this->Btn_verticalFlip->Size = System::Drawing::Size(88, 24);
			this->Btn_verticalFlip->Text = L"垂直鏡射";
			this->Btn_verticalFlip->Click += gcnew System::EventHandler(this, &ImageProcessUI::Btn_verticalFlip_Click);
			// 
			// toolStripButton_diagonal
			// 
			this->toolStripButton_diagonal->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_diagonal.Image")));
			this->toolStripButton_diagonal->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_diagonal->Name = L"toolStripButton_diagonal";
			this->toolStripButton_diagonal->Size = System::Drawing::Size(88, 24);
			this->toolStripButton_diagonal->Text = L"對角線鏡射";
			this->toolStripButton_diagonal->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton_diagonalFlip_Click);
			// 
			// toolStripButton6
			// 
			this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton6.Image")));
			this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton6->Name = L"toolStripButton6";
			this->toolStripButton6->Size = System::Drawing::Size(88, 24);
			this->toolStripButton6->Text = L"彈力球";
			this->toolStripButton6->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton6_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->ChkBox_Inverse_Rotation);
			this->groupBox3->Controls->Add(this->ChkBox_Forward_Rotation);
			this->groupBox3->Controls->Add(this->Rotation);
			this->groupBox3->Location = System::Drawing::Point(225, 26);
			this->groupBox3->Margin = System::Windows::Forms::Padding(2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(2);
			this->groupBox3->Size = System::Drawing::Size(124, 70);
			this->groupBox3->TabIndex = 11;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"旋轉";
			// 
			// ChkBox_Inverse_Rotation
			// 
			this->ChkBox_Inverse_Rotation->AutoSize = true;
			this->ChkBox_Inverse_Rotation->Location = System::Drawing::Point(58, 43);
			this->ChkBox_Inverse_Rotation->Margin = System::Windows::Forms::Padding(2);
			this->ChkBox_Inverse_Rotation->Name = L"ChkBox_Inverse_Rotation";
			this->ChkBox_Inverse_Rotation->Size = System::Drawing::Size(59, 16);
			this->ChkBox_Inverse_Rotation->TabIndex = 13;
			this->ChkBox_Inverse_Rotation->Text = L"逆推法";
			this->ChkBox_Inverse_Rotation->UseVisualStyleBackColor = true;
			// 
			// ChkBox_Forward_Rotation
			// 
			this->ChkBox_Forward_Rotation->AutoSize = true;
			this->ChkBox_Forward_Rotation->Checked = true;
			this->ChkBox_Forward_Rotation->Location = System::Drawing::Point(58, 18);
			this->ChkBox_Forward_Rotation->Margin = System::Windows::Forms::Padding(2);
			this->ChkBox_Forward_Rotation->Name = L"ChkBox_Forward_Rotation";
			this->ChkBox_Forward_Rotation->Size = System::Drawing::Size(59, 16);
			this->ChkBox_Forward_Rotation->TabIndex = 13;
			this->ChkBox_Forward_Rotation->TabStop = true;
			this->ChkBox_Forward_Rotation->Text = L"順推法";
			this->ChkBox_Forward_Rotation->UseVisualStyleBackColor = true;
			// 
			// Rotation
			// 
			this->Rotation->Location = System::Drawing::Point(0, 29);
			this->Rotation->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
			this->Rotation->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, System::Int32::MinValue });
			this->Rotation->Name = L"Rotation";
			this->Rotation->Size = System::Drawing::Size(57, 22);
			this->Rotation->TabIndex = 12;
			this->Rotation->ValueChanged += gcnew System::EventHandler(this, &ImageProcessUI::Rotation_ValueChanged);
			// 
			// pictureBox_Result
			// 
			this->pictureBox_Result->Location = System::Drawing::Point(704, 206);
			this->pictureBox_Result->Margin = System::Windows::Forms::Padding(2);
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
			this->groupBox4->Controls->Add(this->button1);
			this->groupBox4->Controls->Add(this->RadioBtn_Threshold_inv_Binary);
			this->groupBox4->Controls->Add(this->RadioBtn_Threshold_Binary);
			this->groupBox4->Controls->Add(this->Threshold_value);
			this->groupBox4->Location = System::Drawing::Point(353, 26);
			this->groupBox4->Margin = System::Windows::Forms::Padding(2);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(2);
			this->groupBox4->Size = System::Drawing::Size(148, 79);
			this->groupBox4->TabIndex = 13;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"二值化";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(71, 50);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(77, 30);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Otsu";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ImageProcessUI::button1_Click);
			// 
			// RadioBtn_Threshold_inv_Binary
			// 
			this->RadioBtn_Threshold_inv_Binary->AutoSize = true;
			this->RadioBtn_Threshold_inv_Binary->Location = System::Drawing::Point(64, 30);
			this->RadioBtn_Threshold_inv_Binary->Margin = System::Windows::Forms::Padding(2);
			this->RadioBtn_Threshold_inv_Binary->Name = L"RadioBtn_Threshold_inv_Binary";
			this->RadioBtn_Threshold_inv_Binary->Size = System::Drawing::Size(83, 16);
			this->RadioBtn_Threshold_inv_Binary->TabIndex = 15;
			this->RadioBtn_Threshold_inv_Binary->Text = L"二值化負片";
			this->RadioBtn_Threshold_inv_Binary->UseVisualStyleBackColor = true;
			// 
			// RadioBtn_Threshold_Binary
			// 
			this->RadioBtn_Threshold_Binary->AutoSize = true;
			this->RadioBtn_Threshold_Binary->Checked = true;
			this->RadioBtn_Threshold_Binary->Location = System::Drawing::Point(64, 10);
			this->RadioBtn_Threshold_Binary->Margin = System::Windows::Forms::Padding(2);
			this->RadioBtn_Threshold_Binary->Name = L"RadioBtn_Threshold_Binary";
			this->RadioBtn_Threshold_Binary->Size = System::Drawing::Size(59, 16);
			this->RadioBtn_Threshold_Binary->TabIndex = 15;
			this->RadioBtn_Threshold_Binary->TabStop = true;
			this->RadioBtn_Threshold_Binary->Text = L"二值化";
			this->RadioBtn_Threshold_Binary->UseVisualStyleBackColor = true;
			// 
			// Threshold_value
			// 
			this->Threshold_value->Location = System::Drawing::Point(0, 21);
			this->Threshold_value->Margin = System::Windows::Forms::Padding(2);
			this->Threshold_value->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->Threshold_value->Name = L"Threshold_value";
			this->Threshold_value->Size = System::Drawing::Size(60, 22);
			this->Threshold_value->TabIndex = 14;
			this->Threshold_value->ValueChanged += gcnew System::EventHandler(this, &ImageProcessUI::Threshold_value_ValueChanged);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->toolStrip4);
			this->groupBox5->Location = System::Drawing::Point(506, 26);
			this->groupBox5->Margin = System::Windows::Forms::Padding(2);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Padding = System::Windows::Forms::Padding(2);
			this->groupBox5->Size = System::Drawing::Size(102, 62);
			this->groupBox5->TabIndex = 14;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"直方圖";
			// 
			// toolStrip4
			// 
			this->toolStrip4->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip4->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripButton1 });
			this->toolStrip4->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::VerticalStackWithOverflow;
			this->toolStrip4->Location = System::Drawing::Point(2, 17);
			this->toolStrip4->Name = L"toolStrip4";
			this->toolStrip4->Size = System::Drawing::Size(98, 38);
			this->toolStrip4->TabIndex = 0;
			this->toolStrip4->Text = L"toolStrip4";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(96, 24);
			this->toolStripButton1->Text = L"RGB直方圖";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton1_Click);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->Btn_CreateWndow);
			this->groupBox6->Controls->Add(this->numericUpDown_transparent);
			this->groupBox6->Location = System::Drawing::Point(700, 26);
			this->groupBox6->Margin = System::Windows::Forms::Padding(2);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Padding = System::Windows::Forms::Padding(2);
			this->groupBox6->Size = System::Drawing::Size(72, 84);
			this->groupBox6->TabIndex = 15;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"透明度";
			// 
			// Btn_CreateWndow
			// 
			this->Btn_CreateWndow->Location = System::Drawing::Point(4, 45);
			this->Btn_CreateWndow->Margin = System::Windows::Forms::Padding(2);
			this->Btn_CreateWndow->Name = L"Btn_CreateWndow";
			this->Btn_CreateWndow->Size = System::Drawing::Size(68, 34);
			this->Btn_CreateWndow->TabIndex = 1;
			this->Btn_CreateWndow->Text = L"生成雲線";
			this->Btn_CreateWndow->UseVisualStyleBackColor = true;
			this->Btn_CreateWndow->Click += gcnew System::EventHandler(this, &ImageProcessUI::Btn_CreateWndow_Click);
			// 
			// numericUpDown_transparent
			// 
			this->numericUpDown_transparent->Location = System::Drawing::Point(4, 18);
			this->numericUpDown_transparent->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown_transparent->Name = L"numericUpDown_transparent";
			this->numericUpDown_transparent->Size = System::Drawing::Size(64, 22);
			this->numericUpDown_transparent->TabIndex = 0;
			this->numericUpDown_transparent->ValueChanged += gcnew System::EventHandler(this, &ImageProcessUI::numericUpDown_transparent_ValueChanged);
			this->numericUpDown_transparent->Enter += gcnew System::EventHandler(this, &ImageProcessUI::numericUpDown_transparent_ValueChanged);
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->Btn_CloudLine);
			this->groupBox7->Controls->Add(this->Btn_Rectangle);
			this->groupBox7->Controls->Add(this->Btn_Circle);
			this->groupBox7->Controls->Add(this->Btn_None_Draw);
			this->groupBox7->Font = (gcnew System::Drawing::Font(L"新細明體", 9));
			this->groupBox7->Location = System::Drawing::Point(613, 26);
			this->groupBox7->Margin = System::Windows::Forms::Padding(2);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Padding = System::Windows::Forms::Padding(2);
			this->groupBox7->Size = System::Drawing::Size(82, 117);
			this->groupBox7->TabIndex = 16;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"繪圖工具";
			// 
			// Btn_CloudLine
			// 
			this->Btn_CloudLine->AutoSize = true;
			this->Btn_CloudLine->Location = System::Drawing::Point(8, 88);
			this->Btn_CloudLine->Margin = System::Windows::Forms::Padding(2);
			this->Btn_CloudLine->Name = L"Btn_CloudLine";
			this->Btn_CloudLine->Size = System::Drawing::Size(47, 16);
			this->Btn_CloudLine->TabIndex = 4;
			this->Btn_CloudLine->TabStop = true;
			this->Btn_CloudLine->Text = L"雲線";
			this->Btn_CloudLine->UseVisualStyleBackColor = true;
			this->Btn_CloudLine->CheckedChanged += gcnew System::EventHandler(this, &ImageProcessUI::Btn_CloudLine_CheckedChanged);
			// 
			// Btn_Rectangle
			// 
			this->Btn_Rectangle->AutoSize = true;
			this->Btn_Rectangle->Location = System::Drawing::Point(8, 69);
			this->Btn_Rectangle->Margin = System::Windows::Forms::Padding(2);
			this->Btn_Rectangle->Name = L"Btn_Rectangle";
			this->Btn_Rectangle->Size = System::Drawing::Size(47, 16);
			this->Btn_Rectangle->TabIndex = 3;
			this->Btn_Rectangle->Text = L"矩形";
			this->Btn_Rectangle->UseVisualStyleBackColor = true;
			this->Btn_Rectangle->CheckedChanged += gcnew System::EventHandler(this, &ImageProcessUI::Btn_Rectangle_CheckedChanged);
			// 
			// Btn_Circle
			// 
			this->Btn_Circle->AutoSize = true;
			this->Btn_Circle->Location = System::Drawing::Point(8, 46);
			this->Btn_Circle->Margin = System::Windows::Forms::Padding(2);
			this->Btn_Circle->Name = L"Btn_Circle";
			this->Btn_Circle->Size = System::Drawing::Size(47, 16);
			this->Btn_Circle->TabIndex = 2;
			this->Btn_Circle->Text = L"圓形";
			this->Btn_Circle->UseVisualStyleBackColor = true;
			this->Btn_Circle->CheckedChanged += gcnew System::EventHandler(this, &ImageProcessUI::Btn_Circle_CheckedChanged);
			// 
			// Btn_None_Draw
			// 
			this->Btn_None_Draw->AutoSize = true;
			this->Btn_None_Draw->Checked = true;
			this->Btn_None_Draw->Location = System::Drawing::Point(8, 26);
			this->Btn_None_Draw->Margin = System::Windows::Forms::Padding(2);
			this->Btn_None_Draw->Name = L"Btn_None_Draw";
			this->Btn_None_Draw->Size = System::Drawing::Size(35, 16);
			this->Btn_None_Draw->TabIndex = 0;
			this->Btn_None_Draw->TabStop = true;
			this->Btn_None_Draw->Text = L"無";
			this->Btn_None_Draw->UseVisualStyleBackColor = true;
			this->Btn_None_Draw->CheckedChanged += gcnew System::EventHandler(this, &ImageProcessUI::Btn_None_Draw_CheckedChanged);
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->ZoomRate);
			this->groupBox8->Controls->Add(this->toolStrip5);
			this->groupBox8->Location = System::Drawing::Point(791, 26);
			this->groupBox8->Margin = System::Windows::Forms::Padding(2);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Padding = System::Windows::Forms::Padding(2);
			this->groupBox8->Size = System::Drawing::Size(89, 146);
			this->groupBox8->TabIndex = 17;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"縮放";
			// 
			// ZoomRate
			// 
			this->ZoomRate->Location = System::Drawing::Point(10, 16);
			this->ZoomRate->Margin = System::Windows::Forms::Padding(2);
			this->ZoomRate->Name = L"ZoomRate";
			this->ZoomRate->Size = System::Drawing::Size(70, 22);
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
			this->toolStrip5->Location = System::Drawing::Point(10, 38);
			this->toolStrip5->Name = L"toolStrip5";
			this->toolStrip5->Size = System::Drawing::Size(80, 119);
			this->toolStrip5->TabIndex = 0;
			this->toolStrip5->Text = L"toolStrip5";
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(78, 24);
			this->toolStripButton2->Text = L"比例放大";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton2_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(78, 24);
			this->toolStripButton3->Text = L"比例縮小";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton3_Click);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(78, 24);
			this->toolStripButton4->Text = L"差分放大";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton4_Click);
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(78, 24);
			this->toolStripButton5->Text = L"平均縮小";
			this->toolStripButton5->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton5_Click);
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->toolStrip6);
			this->groupBox9->Location = System::Drawing::Point(895, 26);
			this->groupBox9->Margin = System::Windows::Forms::Padding(2);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Padding = System::Windows::Forms::Padding(2);
			this->groupBox9->Size = System::Drawing::Size(80, 79);
			this->groupBox9->TabIndex = 18;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"位元平面";
			// 
			// toolStrip6
			// 
			this->toolStrip6->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip6->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripButton7,
					this->toolStripButton8
			});
			this->toolStrip6->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::VerticalStackWithOverflow;
			this->toolStrip6->Location = System::Drawing::Point(2, 17);
			this->toolStrip6->Name = L"toolStrip6";
			this->toolStrip6->Size = System::Drawing::Size(76, 65);
			this->toolStrip6->TabIndex = 0;
			this->toolStrip6->Text = L"toolStrip6";
			// 
			// toolStripButton7
			// 
			this->toolStripButton7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton7.Image")));
			this->toolStripButton7->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton7->Name = L"toolStripButton7";
			this->toolStripButton7->Size = System::Drawing::Size(74, 24);
			this->toolStripButton7->Text = L"位元分割";
			this->toolStripButton7->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton7_Click);
			// 
			// toolStripButton8
			// 
			this->toolStripButton8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton8.Image")));
			this->toolStripButton8->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton8->Name = L"toolStripButton8";
			this->toolStripButton8->Size = System::Drawing::Size(74, 24);
			this->toolStripButton8->Text = L"浮水印";
			this->toolStripButton8->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton8_Click);
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(712, 642);
			this->label47->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(0, 12);
			this->label47->TabIndex = 19;
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->toolStrip7);
			this->groupBox10->Location = System::Drawing::Point(980, 25);
			this->groupBox10->Margin = System::Windows::Forms::Padding(2);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Padding = System::Windows::Forms::Padding(2);
			this->groupBox10->Size = System::Drawing::Size(88, 81);
			this->groupBox10->TabIndex = 20;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"對比";
			// 
			// toolStrip7
			// 
			this->toolStrip7->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip7->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripButton9,
					this->toolStripButton10
			});
			this->toolStrip7->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::VerticalStackWithOverflow;
			this->toolStrip7->Location = System::Drawing::Point(2, 17);
			this->toolStrip7->Name = L"toolStrip7";
			this->toolStrip7->Size = System::Drawing::Size(84, 65);
			this->toolStrip7->TabIndex = 0;
			this->toolStrip7->Text = L"toolStrip7";
			// 
			// toolStripButton9
			// 
			this->toolStripButton9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->toolStripButton9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton9.Image")));
			this->toolStripButton9->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton9->Name = L"toolStripButton9";
			this->toolStripButton9->Size = System::Drawing::Size(82, 24);
			this->toolStripButton9->Text = L"線性對比";
			this->toolStripButton9->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton9_Click);
			// 
			// toolStripButton10
			// 
			this->toolStripButton10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton10.Image")));
			this->toolStripButton10->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton10->Name = L"toolStripButton10";
			this->toolStripButton10->Size = System::Drawing::Size(82, 24);
			this->toolStripButton10->Text = L"自定義對比";
			this->toolStripButton10->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton10_Click);
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->toolStrip8);
			this->groupBox11->Location = System::Drawing::Point(1072, 30);
			this->groupBox11->Margin = System::Windows::Forms::Padding(2);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Padding = System::Windows::Forms::Padding(2);
			this->groupBox11->Size = System::Drawing::Size(94, 80);
			this->groupBox11->TabIndex = 21;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"直方圖等化";
			// 
			// toolStrip8
			// 
			this->toolStrip8->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip8->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripButton11 });
			this->toolStrip8->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::VerticalStackWithOverflow;
			this->toolStrip8->Location = System::Drawing::Point(2, 17);
			this->toolStrip8->Name = L"toolStrip8";
			this->toolStrip8->Size = System::Drawing::Size(90, 38);
			this->toolStrip8->TabIndex = 0;
			this->toolStrip8->Text = L"toolStrip8";
			// 
			// toolStripButton11
			// 
			this->toolStripButton11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton11.Image")));
			this->toolStripButton11->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton11->Name = L"toolStripButton11";
			this->toolStripButton11->Size = System::Drawing::Size(88, 24);
			this->toolStripButton11->Text = L"直方圖等化";
			this->toolStripButton11->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton11_Click);
			// 
			// groupBox12
			// 
			this->groupBox12->Controls->Add(this->label48);
			this->groupBox12->Controls->Add(this->LowPassSize);
			this->groupBox12->Location = System::Drawing::Point(1167, 26);
			this->groupBox12->Margin = System::Windows::Forms::Padding(2);
			this->groupBox12->Name = L"groupBox12";
			this->groupBox12->Padding = System::Windows::Forms::Padding(2);
			this->groupBox12->Size = System::Drawing::Size(123, 51);
			this->groupBox12->TabIndex = 22;
			this->groupBox12->TabStop = false;
			this->groupBox12->Text = L"低通濾波器";
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(11, 21);
			this->label48->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(27, 12);
			this->label48->TabIndex = 1;
			this->label48->Text = L"Size:";
			// 
			// LowPassSize
			// 
			this->LowPassSize->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->LowPassSize->Location = System::Drawing::Point(42, 17);
			this->LowPassSize->Margin = System::Windows::Forms::Padding(2);
			this->LowPassSize->Name = L"LowPassSize";
			this->LowPassSize->Size = System::Drawing::Size(64, 22);
			this->LowPassSize->TabIndex = 0;
			this->LowPassSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->LowPassSize->ValueChanged += gcnew System::EventHandler(this, &ImageProcessUI::LowPassSIze_ValueChanged);
			// 
			// groupBox13
			// 
			this->groupBox13->Controls->Add(this->toolStrip9);
			this->groupBox13->Location = System::Drawing::Point(1297, 30);
			this->groupBox13->Name = L"groupBox13";
			this->groupBox13->Size = System::Drawing::Size(129, 203);
			this->groupBox13->TabIndex = 23;
			this->groupBox13->TabStop = false;
			this->groupBox13->Text = L"高通濾波器";
			// 
			// toolStrip9
			// 
			this->toolStrip9->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->toolStripButton12,
					this->toolStripButton13, this->toolStripButton14, this->toolStripButton15, this->toolStripButton16, this->toolStripButton17,
					this->toolStripButton18, this->toolStripButton19
			});
			this->toolStrip9->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::VerticalStackWithOverflow;
			this->toolStrip9->Location = System::Drawing::Point(3, 18);
			this->toolStrip9->Name = L"toolStrip9";
			this->toolStrip9->Size = System::Drawing::Size(123, 188);
			this->toolStrip9->TabIndex = 0;
			this->toolStrip9->Text = L"toolStrip9";
			// 
			// toolStripButton12
			// 
			this->toolStripButton12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton12.Image")));
			this->toolStripButton12->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton12->Name = L"toolStripButton12";
			this->toolStripButton12->Size = System::Drawing::Size(121, 20);
			this->toolStripButton12->Text = L"Laplacian";
			this->toolStripButton12->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton12_Click);
			// 
			// toolStripButton13
			// 
			this->toolStripButton13->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton13.Image")));
			this->toolStripButton13->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton13->Name = L"toolStripButton13";
			this->toolStripButton13->Size = System::Drawing::Size(121, 19);
			this->toolStripButton13->Text = L"Mask1";
			this->toolStripButton13->ToolTipText = L"toolStripButton13";
			this->toolStripButton13->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton13_Click);
			// 
			// toolStripButton14
			// 
			this->toolStripButton14->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton14.Image")));
			this->toolStripButton14->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton14->Name = L"toolStripButton14";
			this->toolStripButton14->Size = System::Drawing::Size(121, 19);
			this->toolStripButton14->Text = L"Mask2";
			this->toolStripButton14->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton14_Click);
			// 
			// toolStripButton15
			// 
			this->toolStripButton15->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton15.Image")));
			this->toolStripButton15->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton15->Name = L"toolStripButton15";
			this->toolStripButton15->Size = System::Drawing::Size(121, 19);
			this->toolStripButton15->Text = L"Mask3";
			this->toolStripButton15->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton15_Click);
			// 
			// toolStripButton16
			// 
			this->toolStripButton16->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton16.Image")));
			this->toolStripButton16->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton16->Name = L"toolStripButton16";
			this->toolStripButton16->Size = System::Drawing::Size(121, 19);
			this->toolStripButton16->Text = L"Prewitt_X";
			this->toolStripButton16->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton16_Click);
			// 
			// toolStripButton17
			// 
			this->toolStripButton17->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton17.Image")));
			this->toolStripButton17->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton17->Name = L"toolStripButton17";
			this->toolStripButton17->Size = System::Drawing::Size(121, 19);
			this->toolStripButton17->Text = L"Prewitt_Y";
			this->toolStripButton17->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton17_Click);
			// 
			// toolStripButton18
			// 
			this->toolStripButton18->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton18->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton18.Image")));
			this->toolStripButton18->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton18->Name = L"toolStripButton18";
			this->toolStripButton18->Size = System::Drawing::Size(121, 19);
			this->toolStripButton18->Text = L"Sobel_X";
			this->toolStripButton18->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton18_Click);
			// 
			// toolStripButton19
			// 
			this->toolStripButton19->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton19.Image")));
			this->toolStripButton19->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton19->Name = L"toolStripButton19";
			this->toolStripButton19->Size = System::Drawing::Size(121, 19);
			this->toolStripButton19->Text = L"Sobel_Y";
			this->toolStripButton19->Click += gcnew System::EventHandler(this, &ImageProcessUI::toolStripButton19_Click);
			// 
			// groupBox14
			// 
			this->groupBox14->Controls->Add(this->A);
			this->groupBox14->Controls->Add(this->label49);
			this->groupBox14->Location = System::Drawing::Point(1167, 87);
			this->groupBox14->Name = L"groupBox14";
			this->groupBox14->Size = System::Drawing::Size(130, 56);
			this->groupBox14->TabIndex = 24;
			this->groupBox14->TabStop = false;
			this->groupBox14->Text = L"High-boost filtering";
			// 
			// A
			// 
			this->A->Location = System::Drawing::Point(42, 27);
			this->A->Name = L"A";
			this->A->Size = System::Drawing::Size(64, 22);
			this->A->TabIndex = 1;
			this->A->ValueChanged += gcnew System::EventHandler(this, &ImageProcessUI::numericUpDown1_ValueChanged);
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(11, 31);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(16, 12);
			this->label49->TabIndex = 0;
			this->label49->Text = L"A:";
			// 
			// groupBox15
			// 
			this->groupBox15->Controls->Add(this->RadioBtn_MinMax);
			this->groupBox15->Controls->Add(this->RadioBtn_MaxMin);
			this->groupBox15->Controls->Add(this->RadioBtn_Cross);
			this->groupBox15->Controls->Add(this->RadioBtn_Square);
			this->groupBox15->Controls->Add(this->label50);
			this->groupBox15->Controls->Add(this->Median_FilterSize);
			this->groupBox15->Location = System::Drawing::Point(1296, 244);
			this->groupBox15->Name = L"groupBox15";
			this->groupBox15->Size = System::Drawing::Size(110, 127);
			this->groupBox15->TabIndex = 25;
			this->groupBox15->TabStop = false;
			this->groupBox15->Text = L"帶通濾波器";
			// 
			// RadioBtn_Cross
			// 
			this->RadioBtn_Cross->AutoSize = true;
			this->RadioBtn_Cross->Location = System::Drawing::Point(13, 62);
			this->RadioBtn_Cross->Name = L"RadioBtn_Cross";
			this->RadioBtn_Cross->Size = System::Drawing::Size(73, 16);
			this->RadioBtn_Cross->TabIndex = 4;
			this->RadioBtn_Cross->TabStop = true;
			this->RadioBtn_Cross->Text = L"CrossFilter";
			this->RadioBtn_Cross->UseVisualStyleBackColor = true;
			// 
			// RadioBtn_Square
			// 
			this->RadioBtn_Square->AutoSize = true;
			this->RadioBtn_Square->Checked = true;
			this->RadioBtn_Square->Location = System::Drawing::Point(13, 40);
			this->RadioBtn_Square->Name = L"RadioBtn_Square";
			this->RadioBtn_Square->Size = System::Drawing::Size(79, 16);
			this->RadioBtn_Square->TabIndex = 3;
			this->RadioBtn_Square->TabStop = true;
			this->RadioBtn_Square->Text = L"SquareFilter";
			this->RadioBtn_Square->UseVisualStyleBackColor = true;
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(11, 23);
			this->label50->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(27, 12);
			this->label50->TabIndex = 2;
			this->label50->Text = L"Size:";
			// 
			// Median_FilterSize
			// 
			this->Median_FilterSize->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->Median_FilterSize->Location = System::Drawing::Point(42, 13);
			this->Median_FilterSize->Margin = System::Windows::Forms::Padding(2);
			this->Median_FilterSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			this->Median_FilterSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->Median_FilterSize->Name = L"Median_FilterSize";
			this->Median_FilterSize->Size = System::Drawing::Size(50, 22);
			this->Median_FilterSize->TabIndex = 1;
			this->Median_FilterSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->Median_FilterSize->ValueChanged += gcnew System::EventHandler(this, &ImageProcessUI::Median_FilterSize_ValueChanged);
			// 
			// RadioBtn_MaxMin
			// 
			this->RadioBtn_MaxMin->AutoSize = true;
			this->RadioBtn_MaxMin->Location = System::Drawing::Point(13, 84);
			this->RadioBtn_MaxMin->Name = L"RadioBtn_MaxMin";
			this->RadioBtn_MaxMin->Size = System::Drawing::Size(67, 16);
			this->RadioBtn_MaxMin->TabIndex = 5;
			this->RadioBtn_MaxMin->TabStop = true;
			this->RadioBtn_MaxMin->Text = L"Max-Min";
			this->RadioBtn_MaxMin->UseVisualStyleBackColor = true;
			// 
			// RadioBtn_MinMax
			// 
			this->RadioBtn_MinMax->AutoSize = true;
			this->RadioBtn_MinMax->Location = System::Drawing::Point(13, 105);
			this->RadioBtn_MinMax->Name = L"RadioBtn_MinMax";
			this->RadioBtn_MinMax->Size = System::Drawing::Size(67, 16);
			this->RadioBtn_MinMax->TabIndex = 6;
			this->RadioBtn_MinMax->TabStop = true;
			this->RadioBtn_MinMax->Text = L"Min-Max";
			this->RadioBtn_MinMax->UseVisualStyleBackColor = true;
			// 
			// ImageProcessUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1438, 826);
			this->Controls->Add(this->groupBox15);
			this->Controls->Add(this->groupBox14);
			this->Controls->Add(this->groupBox13);
			this->Controls->Add(this->groupBox12);
			this->Controls->Add(this->groupBox11);
			this->Controls->Add(this->groupBox10);
			this->Controls->Add(this->label47);
			this->Controls->Add(this->groupBox9);
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
			this->Margin = System::Windows::Forms::Padding(2);
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
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->toolStrip6->ResumeLayout(false);
			this->toolStrip6->PerformLayout();
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			this->toolStrip7->ResumeLayout(false);
			this->toolStrip7->PerformLayout();
			this->groupBox11->ResumeLayout(false);
			this->groupBox11->PerformLayout();
			this->toolStrip8->ResumeLayout(false);
			this->toolStrip8->PerformLayout();
			this->groupBox12->ResumeLayout(false);
			this->groupBox12->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LowPassSize))->EndInit();
			this->groupBox13->ResumeLayout(false);
			this->groupBox13->PerformLayout();
			this->toolStrip9->ResumeLayout(false);
			this->toolStrip9->PerformLayout();
			this->groupBox14->ResumeLayout(false);
			this->groupBox14->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A))->EndInit();
			this->groupBox15->ResumeLayout(false);
			this->groupBox15->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Median_FilterSize))->EndInit();
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
				 String^name = System::IO::Path::GetFileName(filename);//得到檔案名稱
				 PCXdata.fileName = name;
				 FileStream^ fs = gcnew FileStream(filename, FileMode::Open);//資料流
				 BinaryReader^ br = gcnew BinaryReader(fs);//二進位編碼
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
				 /********************以下處理彩色**********************/
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
					Color color = temp->GetPixel(i, j); //建立Color結構
					dst->SetPixel(temp->Width - i - 1, j, color);
				}
			break;
		case vertical:
			for (int i = 0; i < temp->Width; i++)
				for (int j = 0; j < temp->Height; j++)
				{
					Color color = temp->GetPixel(i, j); //建立Color結構
					dst->SetPixel(i, temp->Height - j - 1, color);
				}
			break;
		case diagonal:
			for (size_t i = 0; i < temp->Width; i++)
				for (size_t j = 0; j < temp->Height; j++)
				{
					Color color = temp->GetPixel(i, j); //建立Color結構
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
	if (dst == nullptr)dst = gcnew Bitmap(src->Width, src->Height);
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
					dst->SetPixel(i, j, Color::FromArgb(255, 255, 255));
				if (code == THRESH_BINARY_Inv)
					dst->SetPixel(i, j, Color::FromArgb(0, 0, 0));
			}
			else if (src->GetPixel(i, j).R<threshold)
			{
				if (code == THRESH_BINARY)
					dst->SetPixel(i, j, Color::FromArgb(0, 0, 0));
				if (code == THRESH_BINARY_Inv)
					dst->SetPixel(i, j, Color::FromArgb(255, 255, 255));
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
	int theta = Convert::ToInt32(Rotation->Text);//讀取輸入的角度
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
	if (theta < 0) theta += 360; 
	theta *= 0.01745329252; // 轉弳度
	vsin = sin(theta), vcos = cos(theta);  //找出sin cos值
	if (Img_Source == nullptr)
		MessageBox::Show("No image1 input");
	else
	{
		int  newWidth = abs(src->Width*vcos) + abs(src->Height*vsin);  //找出原圖旋轉後用來塞入原圖的矩形長寬
		int newHeight = abs(src->Width*vsin) + abs(src->Height*vcos);  //
		Bitmap^ temp_result = gcnew Bitmap(newWidth, newHeight, src->PixelFormat);  //創建出一個可以塞下旋轉後矩形的矩形


		for (int i = 0; i < src->Width; i++)
		{
			for (int j = 0; j < src->Height; j++)
			{
				int nx, ny;  //旋轉後的x y座標
				nx = (int)(vcos*i - vsin*j);
				ny = (int)(vsin*i + vcos*j);
				if (nx < min_x) min_x = nx;  //找出原作標轉換後的最小座標點min_x min_y(因為是原點當圓心轉所以會是負值或0)
				if (ny < min_y) min_y = ny;
			}
		}
		min_x = abs(min_x);  
		min_y = abs(min_y);
		for (int i = 0; i < temp_result->Width; i++) //將矩形的顏色做成與背景同色
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
				if ((nx < newWidth) && (ny < newHeight)) //檢查是否有在原圖旋轉後產生的矩形中
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
		   if (theta < 0) theta += 360;  //ex:轉-30度跟轉330度是一樣的意思
		   theta *= 0.01745329252; // 轉弳度
		   vsin = sin(theta), vcos = cos(theta);  //找出sin cos值
		   if (Img_Source == nullptr)
			   MessageBox::Show("No image1 input");
		   else
		   {
			   int  newWidth = abs(src->Width*vcos) + abs(src->Height*vsin);  //找出原圖旋轉後用來塞入原圖的矩形長寬
			   int newHeight = abs(src->Width*vsin) + abs(src->Height*vcos);  //
			   Bitmap^ temp_result = gcnew Bitmap(newWidth, newHeight, src->PixelFormat);//創建出一個可以塞下旋轉後矩形的矩形


			   for (int i = 0; i < src->Width; i++)
			   {
				   for (int j = 0; j < src->Height; j++)
				   {
					   int nx, ny;  //原圖旋轉後的x y座標
					   nx = (int)(vcos*i - vsin*j);
					   ny = (int)(vsin*i + vcos*j);
					   if (nx < min_x) min_x = nx;  //找出原作標轉換後的最小座標點min_x min_y(因為是原點當圓心轉所以會是負值或0)
					   if (ny < min_y) min_y = ny;
				   }
			   }
			   for (int i = min_x; i < min_x + newWidth; i++)
			   {
				   for (int j = min_y; j < min_y + newHeight; j++)
				   {
					   int nx, ny;  //逆旋轉後的x y座標
					   nx = (int)(vcos*i + vsin*j + 0.5);
					   ny = (int)(-vsin*i + vcos*j + 0.5);
					   if ((nx < src->Width) && (nx > 0) && (ny < src->Height) && (ny > 0))  //在原圖內
						   temp_result->SetPixel(i + abs(min_x), j + abs(min_y), src->GetPixel(nx, ny));  //abs用來修正偏移量
					   else  //在原圖外(設成與背景相同顏色)
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
		System::Drawing::Graphics^ Reference_rec;
		Pen^ ReferencePen = gcnew Pen(Color::Red, 1.0F);
		Point LBtnMove = e->Location;
		int X_size = LBtnMove.X - LBtnDown.X; 
		int Y_size = LBtnMove.Y - LBtnDown.Y; 
		int center_of_x = (LBtnMove.X + LBtnDown.X) / 2;
		int center_of_y = (LBtnMove.Y + LBtnDown.Y) / 2; 
		int a = X_size / 2;
		int b = Y_size / 2;
		int start_x, end_x, start_y, end_y;
		(LBtnDown.X > LBtnMove.X) ? (start_x = LBtnMove.X, end_x = LBtnDown.X) : (start_x = LBtnDown.X, end_x = LBtnMove.X);
		(LBtnDown.Y > LBtnMove.Y) ? (start_y = LBtnMove.Y, end_y = LBtnDown.Y) : (start_y = LBtnDown.Y, end_y = LBtnMove.Y);
		if (start_x < 0) start_x = 0; 
		if (start_y < 0) start_y = 0;
		if(Img_Stack !=nullptr){
		Bitmap ^img_processed = gcnew Bitmap(Img_Stack->Width, Img_Stack->Height);  
		switch (d_Pen)
		{
		case Pen_Circle:
			//****填滿繪圖範圍***
			for (int j = 0; j < Img_Stack->Height; j++)
				for (int i = 0; i < Img_Stack->Width; i++)
				{
					//if (i >= img_overlapping->Width || j >= img_overlapping->Height)  //防止超出圖框
					//break;
					if ((i > start_x) && (i < end_x) && (j > start_y) && (j < end_y))
					{
						float test_in_or_out = (((i - center_of_x)*(i - center_of_x)*1.0) / (a * a)) + (((j - center_of_y)*(j - center_of_y)*1.0) / (b * b));//測試是否在橢圓內
						if (test_in_or_out < 1)
						{
							img_processed->SetPixel(i, j, Img_Source2->GetPixel(i, j));
						}
						else
							img_processed->SetPixel(i, j, Img_Stack->GetPixel(i, j));
					}
					else
						img_processed->SetPixel(i, j, Img_Stack->GetPixel(i, j));

				}
			pictureBox_Result->Image = img_processed;
			pictureBox_Result->Refresh();
			delete img_processed;
			break;
		case Pen_Rect:

			for (uint16_t i = 0; i < Img_Stack->Width; i++)
			{
				for (uint16_t  j= 0; j < Img_Stack->Height; j++)
				{
					if(start_x <=i && i<= end_x&&start_y <= j && j <= end_y)
						img_processed->SetPixel(i, j, Img_Source2->GetPixel(i, j));
					else
					{
						img_processed->SetPixel(i, j, Img_Stack->GetPixel(i, j));
					}
				}
			}
			pictureBox_Result->Image = img_processed;
			pictureBox_Result->Refresh();
			delete img_processed;
			break;
		case Pen_CloudLine:
			LBtnUP = LBtnMove;
			Reference_rec = pictureBox_Result->CreateGraphics();
			CloudLinePoint.push_back(e->Location);
			Reference_rec->DrawLine(ReferencePen
				, CloudLinePoint[CloudLinePoint.size() - 2].X
				, CloudLinePoint[CloudLinePoint.size() - 2].Y
				, CloudLinePoint[CloudLinePoint.size() - 1].X
				, CloudLinePoint[CloudLinePoint.size() - 1].Y);

			line(Img_tempMask,CloudLinePoint[CloudLinePoint.size() - 2], CloudLinePoint[CloudLinePoint.size() - 1]);
			break;
		default:
			break;
		}
	  }
	}
}
private: System::Void pictureBox_Result_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Img_tempMask = gcnew Bitmap(Img_Source->Width, Img_Source->Height);
	for (uint16_t i = 0; i < Img_Source->Width; i++)
		for (uint16_t j = 0; j < Img_Source->Height; j++)
			Img_tempMask->SetPixel(i, j, Color::Black);
	pictureBox_Result->Image = Img_Stack;
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
	bool f_RGB = false;
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
	
	for (uint16_t i = 0; i < 256; i++)
		if ((His_Color[i][0] != His_Color[i][1]) || (His_Color[i][0] != His_Color[i][2]) || (His_Color[i][1] != His_Color[i][2]))
			f_RGB = true;
	if(f_RGB)
	for (int i = 0; i < 256; i++) 
	{
		RGB_His->chart_RGB->Series["R"]->Points->AddXY(i, His_Color[i][0]);
		RGB_His->chart_RGB->Series["G"]->Points->AddXY(i, His_Color[i][1]);
		RGB_His->chart_RGB->Series["B"]->Points->AddXY(i, His_Color[i][2]);
	}
	if(f_RGB==false)
	 for (int i = 0; i < 256; i++)
		RGB_His->chart_RGB->Series["Gray"]->Points->AddXY(i, His_Color[i][2]);
	RGB_His->Show(); //秀出統計圖
}
private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	double Rate = Convert::ToDouble(ZoomRate->Text);
	ZoomFunction(Img_Source, img_processed, Rate, Zoom);
	pictureBox_Result->Image = img_processed;
	pictureBox_Result->Refresh();
	delete img_processed;
}
public:void ZoomFunction(Bitmap ^src, Bitmap ^%dst, double ZoomRate, int code)  //放大縮小
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
			  int set_X = (int)real_X; //pixel位置為整數
			  int set_Y = (int)real_Y;
								 float difference_X = real_X - set_X;  //實際pixel位置與放大倍數間的誤差
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

								 if (set_X >= src->Width - 1)//檢查是否有超過原圖的寬(插值會以靠近的那個pixel作為該點的值，所以可能超出範圍)
								 {
									 difference_X = 1;
									 set_X = set_X - 1;
								 }
								 if (set_Y >= src->Height - 1)//檢查是否有超過原圖的高
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
										 if (set_x >= src->Width)  //不可以超出原圖範圍
											 set_x = src->Width - 1;
										 if (set_y >= src->Height)
											 set_y = src->Height - 1;
										 ori_R += src->GetPixel(set_x, set_y).R;
										 ori_G += src->GetPixel(set_x, set_y).G;
										 ori_B += src->GetPixel(set_x, set_y).B;
									 }
								 }
								 ori_R = ori_R /Math::Pow(ZoomRate,2);
								 ori_G = ori_G / Math::Pow(ZoomRate, 2);
								 ori_B = ori_B / Math::Pow(ZoomRate, 2);
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
private: System::Void Btn_CreateWndow_Click(System::Object^  sender, System::EventArgs^  e) {
	if ((Img_Source == nullptr) || (Img_Source2 == nullptr))
		MessageBox::Show("Input Image");
	else {
	Bitmap ^ Img_Mask = gcnew Bitmap(Img_Stack->Width, Img_Stack->Height);
 	CreatMask(Img_tempMask, Img_Mask);
	Bitmap ^ temp2=gcnew Bitmap(Img_Stack->Width, Img_Stack->Height);

	bitwise_and(Img_Mask,Img_Source2, temp2);


	Threshold(Img_Mask, Img_Mask,100, THRESH_BINARY_Inv);
	Bitmap ^ temp3 = gcnew Bitmap(Img_Stack->Width, Img_Stack->Height);
	bitwise_and(Img_Mask, Img_Stack, temp3);
	bitwise_or(temp2, temp3, temp3);
	pictureBox_Result->Image = temp3;
	pictureBox_Result->Refresh();
	delete Img_Mask;
	delete temp2;
	delete temp3;
	}
	//bitwise_and(Img_Mask_Inv,Img_Stack, Img_Mask_Inv);
	
}
private:void bitwise_and(Bitmap ^src1,Bitmap^src2,Bitmap ^%dst)
{
	if ((src1->Width != src2->Width) || (src1->Height != src2->Height))
		MessageBox::Show("Dimansion msut be same!");
	else
	{
		Bitmap ^ temp_result = gcnew Bitmap(src1->Width, src1->Height);
		for (unsigned int i=0;i<src1->Width;i++)
			for (unsigned int j = 0; j < src1->Height; j++)
			{
				unsigned R =Math::Min(src1->GetPixel(i, j).R, src2->GetPixel(i, j).R);
				unsigned G= Math::Min(src1->GetPixel(i, j).G, src2->GetPixel(i, j).G);
				unsigned B = Math::Min(src1->GetPixel(i, j).B, src2->GetPixel(i, j).B);
				temp_result->SetPixel(i,j,Color::FromArgb(R,G,B));
			}
		Rectangle cloneRect = Rectangle(0, 0, src2->Width, src2->Height);
		System::Drawing::Imaging::PixelFormat format = src2->PixelFormat;
		dst=temp_result->Clone(cloneRect, format);
		delete temp_result;
	}
	
}
private:void bitwise_or(Bitmap ^src1, Bitmap^src2, Bitmap ^%dst)
{
	if ((src1->Width != src2->Width) || (src1->Height != src2->Height))
		MessageBox::Show("Dimansion msut be same!");
	else
	{
		Bitmap ^ temp_result = gcnew Bitmap(src1->Width, src1->Height);
		for (unsigned int i = 0; i<src1->Width; i++)
			for (unsigned int j = 0; j < src1->Height; j++)
			{
				unsigned R = Math::Max(src1->GetPixel(i, j).R, src2->GetPixel(i, j).R);
				unsigned G = Math::Max(src1->GetPixel(i, j).G, src2->GetPixel(i, j).G);
				unsigned B = Math::Max(src1->GetPixel(i, j).B, src2->GetPixel(i, j).B);
				temp_result->SetPixel(i, j, Color::FromArgb(R, G, B));
			}
		Rectangle cloneRect = Rectangle(0, 0, src2->Width, src2->Height);
		System::Drawing::Imaging::PixelFormat format = src2->PixelFormat;
		dst = temp_result->Clone(cloneRect, format);
		delete temp_result;
	}

}
private:void DrawLine(Bitmap ^%src, Point P1, Point P2)
{
  float x_vector = P1.X - P2.X; //x向量
  float y_vector = P1.Y - P2.Y; //y向量
  int Max_X = 0, Min_X = 0, Max_Y = 0, Min_Y = 0
  (P1.X > P2.X) ? (Min_X = P2.X, Max_X = P1.X) : (Min_X = P1.X, Max_X = P2.X);
  (P1.Y > P2.Y) ? (Min_Y = P2.Y, Max_Y = P1.Y) : (Min_Y = P1.Y, Max_Y = P2.Y);
  int constant = (-1 * y_vector * P1.X) + (x_vector * P1.Y); //向量x,y交換便號其中一個 找出線性方程式
  for (int j = Min_Y; j < Max_Y; j++)
    for (int i = Min_X; i < Max_X; i++)
    {
     float value = -1 * y_vector * i + x_vector * j; //算出常數
       if (((int)(value) == constant) || ((int)(value + 1) == constant))
         {
          src->SetPixel(i, j, Color::White);
          src->SetPixel(i + 1, j, Color::White);
	      src->SetPixel(i + 2, j, Color::White);
         }
		}
}
private:void CreatMask(Bitmap^ src,Bitmap ^%dst)
{
	Bitmap ^ temp_result = gcnew Bitmap(src->Width, src->Height);
	for (uint16_t i = 0; i<temp_result->Width; i++)
		for (uint16_t j = 0; j < temp_result->Height; j++)
			temp_result->SetPixel(i, j, Color::Black);
	for (unsigned int j = 0; j < src->Height; j++)	
	{
		cliext::vector<Point> Pos;
		for (unsigned int i = 0; i < src->Width; i++)
		{
			if (src->GetPixel(i, j).R > 0)
				Pos.push_back(Point(i, j));
		}
		if (Pos.size() >= 2)
		{
			for (unsigned int k = 0; k < Pos.size()-1; k++)
			{
				line(temp_result, Pos[k],Pos[k+1]);
			}
		}
	}
	Rectangle cloneRect = Rectangle(0, 0, temp_result->Width, temp_result->Height);
	System::Drawing::Imaging::PixelFormat format = temp_result->PixelFormat;
	dst = temp_result->Clone(cloneRect, format);
}
private:void line(Bitmap ^%src,Point P1,Point P2)
{
	if (P1.X != P2.X) //為直斜線
	{
		float X = P2.X - P1.X;
		float Y = P2.Y - P1.Y;
		float temp = (Y / X) * 1000;
		float a = temp*0.001; //斜率
		float Z = temp*0.001;

		float b = 1.0*(P1.Y - a*P1.X);//截距 因為y = ax+b 所以b = y - ax
		if (a > 0)
		{
			if (P1.X > P2.X)  //右下往左上
			{
				for (int i = P2.X; i < P1.X; i++)
				{
					for (int j = i*a + b + 0.5; j < (int)((i + 1)*a + b + 0.5); j++)
					{
						src->SetPixel(i, j, Color::FromArgb(255, 255,255));
						if (P1.X == P2.X) break;
					}
					if (P1.X == P2.X) break;
				}

			}
			else if (P1.X < P2.X)  //左上往右下
			{
				for (int i = P1.X; i < P2.X; i++)
				{
					for (int j = i*a + b + 0.5; j < (int)((i + 1)*a + b + 0.5); j++)
					{
						src->SetPixel(i, j, Color::FromArgb(255,255,255));
					}
				}
			}
		}
		if (a < 0)
		{
			if (P1.X > P2.X)  //右上往左下
			{
				for (int i = P2.X; i < P1.X; i++)
				{

					for (int j = i*a + b + 0.5; j >= (int)((i + 1)*a + b + 0.5); j--)
					{
						src->SetPixel(i, j, Color::FromArgb(255,255,255));
						//if (P1.X == P2.X) 
						//Vertical_Line(P1, P2);
					}
				}
			}
			else if (P1.X < P2.X)  //左下往右上
			{
				for (int i = P1.X; i < P2.X; i++)
				{

					for (int j = i*a + b + 0.5; j >(int)((i + 1)*a + b + 0.5); j--)
					{
						int pixel = ((i + 1)*a + b + 0.5);
						src->SetPixel(i, j, Color::FromArgb(255,255,255));
						//if (P1.X == P2.X) 
						//Vertical_Line(P1, P2);
					}
				}
			}
		}
	}

	if (P1.X == P2.X)  //垂直線
	{
		if (P1.Y < P2.Y)  //P2在下面，表示滑鼠向下移動
		{
			for (int j = P1.Y; j < P2.Y; j++)
				src->SetPixel(P1.X, j, Color::FromArgb(255,255,255));//畫紅線
		}
		else if (P1.Y > P2.Y)  //P2在上面，表示滑鼠向上移動
		{
			for (int j = P2.Y; j < P1.Y; j++)
				src->SetPixel(P1.X, j, Color::FromArgb(255,255,255));
		}
	}
	if (P1.Y == P2.Y)  //水平線
	{
		if (P1.X > P2.X) //P2在左邊，表示滑鼠向左移動
		{
			for (int i = P2.X; i <= P1.X; i++)
				src->SetPixel(i, P1.Y, Color::FromArgb(255,255,255));
		}
		else if (P1.X < P2.X) //P2在右邊，表示滑鼠向右移動
		{
			for (int i = P1.X; i <= P2.X; i++)
				src->SetPixel(i, P1.Y, Color::FromArgb(255,255,255));
		}
	}

}
private: System::Void toolStripButton6_Click(System::Object^  sender, System::EventArgs^  e) {
	Bouncingball ^bouncing_ball = gcnew Bouncingball;
	bouncing_ball->ShowDialog();
}
private: System::Void toolStripButton7_Click(System::Object^  sender, System::EventArgs^  e) {
	cliext::vector<Bitmap^> Bitchannel; cliext::vector<Bitmap^> BitGray;
	
	Convert2BitChannel(Img_Source, Bitchannel);
	BitPlaneUI ^bitUI = gcnew BitPlaneUI();
	bitUI->pictureBox1->Image = Bitchannel[0];
	bitUI->pictureBox2->Image = Bitchannel[1];
	bitUI->pictureBox3->Image = Bitchannel[2];
	bitUI->pictureBox4->Image = Bitchannel[3];
	bitUI->pictureBox5->Image = Bitchannel[4];
	bitUI->pictureBox6->Image = Bitchannel[5];
	bitUI->pictureBox7->Image = Bitchannel[6];
	bitUI->pictureBox8->Image = Bitchannel[7];
	bitUI->label9->Text = "Bit_code";
	bitUI->Show();

	Convert2GrayChannel(Bitchannel, BitGray);
	
	BitPlaneUI ^GrayUI = gcnew BitPlaneUI();
	GrayUI->pictureBox1->Image = BitGray[0];
	GrayUI->pictureBox2->Image = BitGray[1];
	GrayUI->pictureBox3->Image = BitGray[2];
	GrayUI->pictureBox4->Image = BitGray[3];
	GrayUI->pictureBox5->Image = BitGray[4];
	GrayUI->pictureBox6->Image = BitGray[5];
	GrayUI->pictureBox7->Image = BitGray[6];
	GrayUI->pictureBox8->Image = BitGray[7];
	GrayUI->label9->Text = "Gray_code";
	GrayUI->Show();
	
}
private:void Convert2BitChannel(Bitmap^ src, cliext::vector<Bitmap^>%Bitchannel)
{
	Bitmap^ Img_gray;
	ConvertColor(Img_Source, Img_gray, RGB2Gray);
	for (uint16_t i = 0; i < 8; i++)
	{
		Bitmap^	 initial = gcnew Bitmap(Img_gray->Width, Img_gray->Height);
		Bitchannel.push_back(initial);
	}
	for (uint16_t i = 0; i < Img_gray->Width; i++)
	{
		for (uint16_t j = 0; j < Img_gray->Height; j++)
		{
			unsigned char mask = 0x01;
			unsigned char Value = Img_gray->GetPixel(i, j).R;
			for (uint16_t k = 0; k < 8; k++)
			{
				if ((Value & mask) > 0)
					Bitchannel[k]->SetPixel(i, j, Color::FromArgb(255, 255, 255));
				if ((Value & mask) == 0)
					Bitchannel[k]->SetPixel(i, j, Color::FromArgb(0, 0, 0));
				mask = mask << 1;
			}
		}
	}
}
private:void Convert2GrayChannel(cliext::vector<Bitmap^>%Bitchannel, cliext::vector<Bitmap^>%GrayChannel)
{
	for (size_t i = 0; i < 8; i++)
	{
		Bitmap^	 initial = gcnew Bitmap(Bitchannel[0]->Width, Bitchannel[0]->Height);
		GrayChannel.push_back(initial);
	}
	
	GrayChannel[7] = Bitchannel[7]->Clone(Rectangle(0, 0, Bitchannel[7]->Width, Bitchannel[7]->Height), Bitchannel[7]->PixelFormat);
	for (uint16_t i = 0; i<Bitchannel[7]->Width; i++)
		for (uint16_t j = 0; j < Bitchannel[7]->Height; j++)
			for (uint16_t k = 0; k < 7; k++)
			{
				int XOR = Bitchannel[7 - k]->GetPixel(i, j).R - Bitchannel[6 - k]->GetPixel(i, j).R;
				if (XOR != 0)
					GrayChannel[6 - k]->SetPixel(i, j, Color::FromArgb(255, 255, 255));
				if (XOR == 0)
					GrayChannel[6 - k]->SetPixel(i, j, Color::FromArgb(0, 0, 0));
			}
}
private: System::Void toolStripButton8_Click(System::Object^  sender, System::EventArgs^  e) {
	cliext::vector<Bitmap^> Bitchannel;
	Bitmap ^ Img_processed = gcnew Bitmap(Img_Source->Width, Img_Source->Height);
	Convert2BitChannel(Img_Source, Bitchannel);


	Bitmap ^WaterMark = gcnew Bitmap("WaterMark.bmp");
	Bitchannel[0] = WaterMark->Clone(Rectangle(0, 0, Bitchannel[7]->Width, Bitchannel[7]->Height), Bitchannel[7]->PixelFormat);
	for (uint16_t i = 0; i < Img_Source->Width; i++)
		for (uint16_t j = 0; j < Img_Source->Height; j++)
		{
			unsigned char Value = 0x00;
			unsigned char mask = 0x01;
			for (uint16_t k = 0; k < 8; k++)
			{
				Value += Bitchannel[k]->GetPixel(i, j).R & mask;
				mask = mask << 1;
			}
			Img_processed->SetPixel(i, j, Color::FromArgb(Value, Value, Value));
		}
	double SNR_Value = SNR(Img_Source,Img_processed);
	label47->Text = "SNR: "+SNR_Value.ToString();
	pictureBox_Result->Image = Img_processed;
	pictureBox_Result->Refresh();
	delete Img_processed;
	
	BitPlaneUI ^bitUI = gcnew BitPlaneUI();
	bitUI->pictureBox1->Image = Bitchannel[0];
	bitUI->pictureBox2->Image = Bitchannel[1];
	bitUI->pictureBox3->Image = Bitchannel[2];
	bitUI->pictureBox4->Image = Bitchannel[3];
	bitUI->pictureBox5->Image = Bitchannel[4];
	bitUI->pictureBox6->Image = Bitchannel[5];
	bitUI->pictureBox7->Image = Bitchannel[6];
	bitUI->pictureBox8->Image = Bitchannel[7];
	bitUI->label9->Text = "Bit_code";
	bitUI->Show();
}
 private:double SNR(Bitmap ^%Source, Bitmap ^% TestImage)
{
	 double SNR_Value = 0;
	 double SumofSource = 0;
	 double SumofTest = 0;//Source-Test
	 for (UInt16 i = 0; i < Source->Width; i++)
		 for (UInt16 j = 0; j < Source->Width; j++)
		 {
			 SumofSource += Source->GetPixel(i, j).R;
			 SumofTest += Source->GetPixel(i, j).R - TestImage->GetPixel(i, j).R;
		 }
	 SNR_Value= Math::Log10(SumofSource/ SumofTest);
	 return 20 * SNR_Value;
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^Img_processed;
	RGBHistigram ^RGB_His = gcnew RGBHistigram();
	
	int GrayStatisticProbability[256] = { 0 };
	int threshold_Value = Otus(Img_Source, &GrayStatisticProbability[0]);
	Threshold(Img_Source, Img_processed, threshold_Value, THRESH_BINARY);

	for(uint16_t i=0;i<256;i++)
		RGB_His->chart_RGB->Series["Gray"]->Points->AddXY(i, GrayStatisticProbability[i]);
	Threshold_value->Text = threshold_Value.ToString();
	RGB_His->chart_RGB->Series["R"]->Points->AddXY(threshold_Value,3000);
	RGB_His->ShowDialog();
	pictureBox_Result->Image = Img_processed;
	pictureBox_Result->Refresh();
	delete Img_processed;
}
private:int Otus(Bitmap ^src,int GrayStatisticProbability[256])
{
	int threshold = 0;
	Bitmap ^Img_Gray;
	ConvertColor(src, Img_Gray, RGB2Gray);
	
	unsigned int SumtotalGray;
	unsigned int totalNo= Img_Gray->Width*Img_Gray->Height;
	for (uint16_t i = 0; i < Img_Gray->Width; i++)
		for (uint16_t j = 0; j < Img_Gray->Height; j++)
		{
			GrayStatisticProbability[Img_Gray->GetPixel(i, j).R] +=1;
			SumtotalGray += Img_Gray->GetPixel(i, j).R;
		}
	delete Img_Gray;
	double MeanTotal =(double)SumtotalGray/ (double)totalNo;
	unsigned int weight_Under = 0;
	unsigned int weight_Above= 0;
	unsigned int sum_Lower = 0;
	double varMax = 0;

	for (uint16_t i = 0; i < 256; i++)
	{
	 weight_Under += GrayStatisticProbability[i];
	 sum_Lower += i* GrayStatisticProbability[i];
	 weight_Above = totalNo - weight_Under;
	 unsigned int sum_Above = SumtotalGray - sum_Lower;

	 double W1 = (double)weight_Under / (double)totalNo;
	 double Mean1=0;
	 if(weight_Under!=0)
	 Mean1 = (double)sum_Lower / (double)weight_Under;

	 double W2 = (double)weight_Above / (double)totalNo;

	 double Mean2 = 0;
	 if(weight_Above !=0)Mean2 = (double)sum_Above / (double)weight_Above;

	 double variance_between = W1*pow(Mean1- MeanTotal,2)+W2*pow(Mean2- MeanTotal,2);//w1*var1^2+w2*var2^2
	 if (varMax<variance_between)
	 {
		 varMax = variance_between;
		 threshold=i;
	 }
	}
	return threshold;
}
private:void ImageExtend(Bitmap^src, int NumExtend, Bitmap ^%dst)
{
	dst = gcnew Bitmap(src->Width + NumExtend * 2, src->Height + NumExtend * 2);
	for (uint16_t k = 0; k < NumExtend; k++)
	{
		for (uint j = 0; j < src->Height; j++)
		{
			dst->SetPixel(NumExtend - k - 1, j + NumExtend,src->GetPixel(src->Width - k - 1,j));
			dst->SetPixel(dst->Width - (NumExtend - k),j + NumExtend, src->GetPixel(k, j));
		}
		for (uint i = 0; i < src->Width; i++)
		{
			dst->SetPixel(i + NumExtend,k,src->GetPixel(i, src->Height - (NumExtend - k)));
			dst->SetPixel(i + NumExtend, dst->Height- (NumExtend - k), src->GetPixel(i, k));
		}
		for (uint16_t j = 0; j < NumExtend; j++)//對角擴張
		{
			dst->SetPixel(k,j,src->GetPixel(src->Width - (NumExtend - k),src->Height - (NumExtend - j)));//左上
			dst->SetPixel(j,dst->Height - (NumExtend - k),src->GetPixel(src->Width -(NumExtend - j),k));//左下
			dst->SetPixel(dst->Width-(NumExtend-j),dst->Height-(NumExtend - k),src->GetPixel(j,k));//右下
			dst->SetPixel(dst->Width - (NumExtend - k),j,src->GetPixel(k,src->Height-(NumExtend - j)));
		}
	}
	for (uint i = 0; i < src->Width; i++)
		for (uint j = 0; j < src->Height; j++)
			dst->SetPixel(i+NumExtend,j+NumExtend,src->GetPixel(i,j));
}
private: System::Void toolStripButton9_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^Imgprocessed;
	LinearContrast(Img_Source, Imgprocessed);
	pictureBox_Result->Image = Imgprocessed;
	pictureBox_Result->Refresh();
	delete Imgprocessed;
}
private:void LinearContrast(Bitmap ^src, Bitmap ^%dst)
{
	dst = gcnew Bitmap(src->Width, src->Height);
	int GrayStatistic[256] = { 0 };
	for (uint i = 0; i < src->Width; i++)
		for (uint j = 0; j < src->Height; j++)
			GrayStatistic[src->GetPixel(i, j).R]+=1;
	uint totalNum = src->Width*src->Height;
	uint Percent_5 = totalNum*0.05;
	uint LowfivePercentGrayValue = 0;
	uint TopfivePercentGrayValue = 0;
	int counter = 0;
	int counter2 = 0;
	for (uint i = 0; i <256; i++)
	{
		counter += GrayStatistic[i];
		counter2 += GrayStatistic[255 - i];
		if ((counter- GrayStatistic[i]<=Percent_5) && (Percent_5<= counter))		  
			LowfivePercentGrayValue = i;
		if ((counter2 - GrayStatistic[255 - i] <= Percent_5) && (Percent_5 <= counter2))
			TopfivePercentGrayValue = 255-i;
	}
	for(uint i=0;i<src->Width;i++)
		for (uint j = 0; j < src->Height; j++)
		{
			if ((LowfivePercentGrayValue <= src->GetPixel(i, j).R) && src->GetPixel(i, j).R <= TopfivePercentGrayValue)
			{
				int mapped_value = (int)mapping(src->GetPixel(i, j).R, LowfivePercentGrayValue, TopfivePercentGrayValue);
				dst->SetPixel(i, j, Color::FromArgb(mapped_value, mapped_value, mapped_value));
			}
			else if ((src->GetPixel(i, j).R) < LowfivePercentGrayValue)
				dst->SetPixel(i, j, Color::FromArgb(0, 0, 0));
			else if ((src->GetPixel(i, j).R) > TopfivePercentGrayValue)
				dst->SetPixel(i, j, Color::FromArgb(255, 255,255));
		}
}
private:float mapping(int x, int in_min, int in_max)
{
	return (float)(x - in_min) *(255.0f)/(float)(in_max - in_min);
}
private: System::Void toolStripButton10_Click(System::Object^  sender, System::EventArgs^  e) {
	SelfDefineContrast ^ SelfUI = gcnew SelfDefineContrast();
	SelfUI->Image_Source = Img_Source;
	SelfUI->pictureBox2->Image = SelfUI->Image_Source;
	SelfUI->ShowDialog();
}
private: void HistogramEqualize(Bitmap^src, Bitmap ^%dst)
{
	dst = gcnew Bitmap(src->Width, src->Height);
	int GrayStatistic[256] = { 0 };
	for (uint i = 0; i < dst->Width; i++)
		for (uint j = 0; j < dst->Height; j++)
			GrayStatistic[src->GetPixel(i, j).R] += 1;

	uint sumtemp[256] = { 0 };
	uint sum = 0;
	uint totalPixel = src->Width*src->Height;
	for (uint k = 0; k < 256; k++)
	{
		sum += GrayStatistic[k];
		float temp = 255 * (float)sum / (float)totalPixel;
		sumtemp[k] = temp + 0.5;
	}
	for (uint i = 0; i < dst->Width; i++)
		for (uint j = 0; j < dst->Height; j++)
		{
			int color = src->GetPixel(i, j).R;
			dst->SetPixel(i, j, Color::FromArgb(sumtemp[color], sumtemp[color], sumtemp[color]));
		}
}
private: System::Void toolStripButton11_Click(System::Object^  sender, System::EventArgs^  e) {

	Bitmap ^Img_processed;
	int GrayStatistic[256] = { 0 };
	HistogramEqualize(Img_Source, Img_processed);
	for (uint i = 0; i < Img_processed->Width; i++)
		for (uint j = 0; j < Img_processed->Height; j++)
			GrayStatistic[Img_processed->GetPixel(i, j).R] += 1;
	RGBHistigram ^RGB_His = gcnew RGBHistigram;
	for (int i = 0; i < 256; i++)
		RGB_His->chart_RGB->Series["Gray"]->Points->AddXY(i, GrayStatistic[i]);
	RGB_His->ShowDialog();
	pictureBox_Result->Image = Img_processed;
	pictureBox_Result->Refresh();
	delete Img_processed;
}
private:int Sum_of_Image(Bitmap^% src)
{
	uint Result = 0;
	for (uint i = 0; i < src->Width; i++)
		for (uint j = 0; j < src->Height; j++)
			Result+= src->GetPixel(i, j).R;
	return Result;
}
private: System::Void LowPassSIze_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	int Size = Convert::ToInt32(LowPassSize->Text);
	Bitmap ^ Img_Extended;
	Bitmap ^Img_Filtered = gcnew Bitmap(Img_Source->Width, Img_Source->Height);
	ImageExtend(Img_Source,(Size-1)/2, Img_Extended);
	for(uint j=0;j<Img_Source->Height;j++)
		for (uint i = 0; i < Img_Source->Width; i++)
		{
			Bitmap^ temp = gcnew Bitmap(Size, Size);
			Rectangle cloneRect = Rectangle(i, j, Size, Size);
			temp=Img_Extended->Clone(cloneRect, Img_Extended->PixelFormat);
			double sum=(double)Sum_of_Image(temp);delete temp;
			sum /= pow(Size,2);
			Img_Filtered->SetPixel(i,j,Color::FromArgb(sum, sum, sum));
		}
	delete Img_Extended;
	pictureBox_Result->Image = Img_Filtered;
	pictureBox_Result->Refresh();
	delete Img_Filtered;
}
private:int CalculatorCoeffwithROI(Bitmap ^%src, int *coefficient)
{
	int  Result = 0;
    for (uint j = 0; j < src->Height; j++)
	 for (uint i = 0; i < src->Width; i++)
		{
		 int coeff = *(coefficient + src->Width*j +i);
		 int depp = src->GetPixel(i, j).R;
		 Result += src->GetPixel(i, j).R*coeff;
		}
	return Result;
}
private: System::Void toolStripButton12_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ Img_Extended;
	Bitmap ^Img_Filtered = gcnew Bitmap(Img_Source->Width, Img_Source->Height);
	ImageExtend(Img_Source,1, Img_Extended);
	int LaplaceCoeff[3][3] = { {-1,-1,-1},{ -1,8,-1 },{ -1,-1,-1}};
		                                         
	for (uint j = 0; j<Img_Source->Height; j++)
		for (uint i = 0; i < Img_Source->Width; i++)
		{
			Bitmap^ temp = gcnew Bitmap(3, 3);
			Rectangle cloneRect = Rectangle(i, j, 3, 3);
			temp = Img_Extended->Clone(cloneRect, Img_Extended->PixelFormat);
			int valueabs= CalculatorCoeffwithROI(temp,LaplaceCoeff[0]);
			valueabs = abs(valueabs); valueabs /= 9;
			Img_Filtered->SetPixel(i, j, Color::FromArgb(valueabs, valueabs, valueabs));
		}
	Bitmap ^HE;
	HistogramEqualize(Img_Filtered, HE);
	delete Img_Extended;
	pictureBox_Result->Image = HE;
	pictureBox_Result->Refresh();
	delete Img_Filtered;
	delete HE;
}
private: System::Void toolStripButton13_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ Img_Extended;
	Bitmap ^Img_Filtered = gcnew Bitmap(Img_Source->Width, Img_Source->Height);
	ImageExtend(Img_Source, 1, Img_Extended);
	int LaplaceCoeff[3][3] = { { 0,-1,0 },{ -1,5,-1 },{ 0,-1,0 } };

	for (uint j = 0; j<Img_Source->Height; j++)
		for (uint i = 0; i < Img_Source->Width; i++)
		{
			Bitmap^ temp = gcnew Bitmap(3, 3);
			Rectangle cloneRect = Rectangle(i, j, 3, 3);
			temp = Img_Extended->Clone(cloneRect, Img_Extended->PixelFormat);
			int valueabs = CalculatorCoeffwithROI(temp, LaplaceCoeff[0]);
			valueabs = abs(valueabs); valueabs /= 9;
			Img_Filtered->SetPixel(i, j, Color::FromArgb(valueabs, valueabs, valueabs));
		}
	Bitmap ^ HE;
	HistogramEqualize(Img_Filtered,HE);

	delete Img_Extended;
	pictureBox_Result->Image = HE;
	pictureBox_Result->Refresh();
	delete HE;
	delete Img_Filtered;
}
private: System::Void toolStripButton14_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ Img_Extended;
	Bitmap ^Img_Filtered = gcnew Bitmap(Img_Source->Width, Img_Source->Height);
	ImageExtend(Img_Source, 1, Img_Extended);
	int LaplaceCoeff[3][3] = { {-1,-1,-1 },{ -1,9,-1 },{ -1,-1,-1 } };

	for (uint j = 0; j<Img_Source->Height; j++)
		for (uint i = 0; i < Img_Source->Width; i++)
		{
			Bitmap^ temp = gcnew Bitmap(3, 3);
			Rectangle cloneRect = Rectangle(i, j, 3, 3);
			temp = Img_Extended->Clone(cloneRect, Img_Extended->PixelFormat);
			int valueabs = CalculatorCoeffwithROI(temp, LaplaceCoeff[0]);
			valueabs = abs(valueabs);
			valueabs /= 9;
			Img_Filtered->SetPixel(i, j, Color::FromArgb(valueabs, valueabs, valueabs));
		}
	Bitmap ^ HE;
	HistogramEqualize(Img_Filtered, HE);

	delete Img_Extended;
	pictureBox_Result->Image = HE;
	pictureBox_Result->Refresh();
	delete HE;
	delete Img_Filtered;
}
private: System::Void toolStripButton15_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ Img_Extended;
	Bitmap ^Img_Filtered = gcnew Bitmap(Img_Source->Width, Img_Source->Height);
	ImageExtend(Img_Source, 1, Img_Extended);
	int LaplaceCoeff[3][3] = { { 1,-2,1 },{ -2,5,-2},{ 1,-2,1 } };

	for (uint j = 0; j<Img_Source->Height; j++)
		for (uint i = 0; i < Img_Source->Width; i++)
		{
			Bitmap^ temp = gcnew Bitmap(3, 3);
			Rectangle cloneRect = Rectangle(i, j, 3, 3);
			temp = Img_Extended->Clone(cloneRect, Img_Extended->PixelFormat);
			int valueabs = CalculatorCoeffwithROI(temp, LaplaceCoeff[0]);
			valueabs = abs(valueabs); valueabs /= 9;
			Img_Filtered->SetPixel(i, j, Color::FromArgb(valueabs, valueabs, valueabs));
		}
	Bitmap ^ HE;
	HistogramEqualize(Img_Filtered, HE);

	delete Img_Extended;
	pictureBox_Result->Image = HE;
	pictureBox_Result->Refresh();
	delete HE;
	delete Img_Filtered;
}
private: System::Void toolStripButton16_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ Img_Extended;
	Bitmap ^Img_Filtered = gcnew Bitmap(Img_Source->Width, Img_Source->Height);
	ImageExtend(Img_Source, 1, Img_Extended);
	int LaplaceCoeff[3][3] = { {-1,-1,-1},{ 0,0,0 },{ 1,1,1 } };

	for (uint j = 0; j<Img_Source->Height; j++)
		for (uint i = 0; i < Img_Source->Width; i++)
		{
			Bitmap^ temp = gcnew Bitmap(3, 3);
			Rectangle cloneRect = Rectangle(i, j, 3, 3);
			temp = Img_Extended->Clone(cloneRect, Img_Extended->PixelFormat);
			int valueabs = CalculatorCoeffwithROI(temp, LaplaceCoeff[0]);
			valueabs = abs(valueabs); valueabs /= 9;
			Img_Filtered->SetPixel(i, j, Color::FromArgb(valueabs, valueabs, valueabs));
		}

	delete Img_Extended;
	pictureBox_Result->Image = Img_Filtered;
	pictureBox_Result->Refresh();
	delete Img_Filtered;
}
private: System::Void toolStripButton17_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ Img_Extended;
	Bitmap ^Img_Filtered = gcnew Bitmap(Img_Source->Width, Img_Source->Height);
	ImageExtend(Img_Source, 1, Img_Extended);
	int LaplaceCoeff[3][3] = { { -1,0,1 },{ -1,0,1 },{ -1,0,1 } };

	for (uint j = 0; j<Img_Source->Height; j++)
		for (uint i = 0; i < Img_Source->Width; i++)
		{
			Bitmap^ temp = gcnew Bitmap(3, 3);
			Rectangle cloneRect = Rectangle(i, j, 3, 3);
			temp = Img_Extended->Clone(cloneRect, Img_Extended->PixelFormat);
			int valueabs = CalculatorCoeffwithROI(temp, LaplaceCoeff[0]);
			valueabs = abs(valueabs); valueabs /= 9;
			Img_Filtered->SetPixel(i, j, Color::FromArgb(valueabs, valueabs, valueabs));
		}

	delete Img_Extended;
	pictureBox_Result->Image = Img_Filtered;
	pictureBox_Result->Refresh();
	delete Img_Filtered;
}
private: System::Void toolStripButton18_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ Img_Extended;
	Bitmap ^Img_Filtered = gcnew Bitmap(Img_Source->Width, Img_Source->Height);
	ImageExtend(Img_Source, 1, Img_Extended);
	int LaplaceCoeff[3][3] = { { -1,-2,-1 },{ 0,0,0 },{ 1,2,1 } };

	for (uint j = 0; j<Img_Source->Height; j++)
		for (uint i = 0; i < Img_Source->Width; i++)
		{
			Bitmap^ temp = gcnew Bitmap(3, 3);
			Rectangle cloneRect = Rectangle(i, j, 3, 3);
			temp = Img_Extended->Clone(cloneRect, Img_Extended->PixelFormat);
			int valueabs = CalculatorCoeffwithROI(temp, LaplaceCoeff[0]);
			valueabs = abs(valueabs); valueabs /= 9;
			Img_Filtered->SetPixel(i, j, Color::FromArgb(valueabs, valueabs, valueabs));
		}

	delete Img_Extended;
	pictureBox_Result->Image = Img_Filtered;
	pictureBox_Result->Refresh();
	delete Img_Filtered;
}
private: System::Void toolStripButton19_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ Img_Extended;
	Bitmap ^Img_Filtered = gcnew Bitmap(Img_Source->Width, Img_Source->Height);
	ImageExtend(Img_Source, 1, Img_Extended);
	int LaplaceCoeff[3][3] = { { -1,0,1 },{ -2,0,2 },{ -1,0,1 } };

	for (uint j = 0; j<Img_Source->Height; j++)
		for (uint i = 0; i < Img_Source->Width; i++)
		{
			Bitmap^ temp = gcnew Bitmap(3, 3);
			Rectangle cloneRect = Rectangle(i, j, 3, 3);
			temp = Img_Extended->Clone(cloneRect, Img_Extended->PixelFormat);
			int valueabs = CalculatorCoeffwithROI(temp, LaplaceCoeff[0]);
			valueabs = abs(valueabs); valueabs /= 9;
			Img_Filtered->SetPixel(i, j, Color::FromArgb(valueabs, valueabs, valueabs));
		}

	delete Img_Extended;
	pictureBox_Result->Image = Img_Filtered;
	pictureBox_Result->Refresh();
	delete Img_Filtered;
}
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ Img_Extended;
	Bitmap ^Img_Filtered = gcnew Bitmap(Img_Source->Width, Img_Source->Height);
	int W =9*Convert::ToInt32(A->Text)-1;
	ImageExtend(Img_Source, 1, Img_Extended);
	int LaplaceCoeff[3][3] = { { -1,-1,-1 },{ -1,W,-1},{ -1,-1,-1}};
	int *ptr = new int[Img_Source->Height*Img_Source->Width];
	int max = 0,min=10000;
	for (uint j = 0; j<Img_Source->Height; j++)
		for (uint i = 0; i < Img_Source->Width; i++)
		{
			Bitmap^ temp = gcnew Bitmap(3, 3);
			Rectangle cloneRect = Rectangle(i, j, 3, 3);
			temp = Img_Extended->Clone(cloneRect, Img_Extended->PixelFormat);
			int valueabs = CalculatorCoeffwithROI(temp, LaplaceCoeff[0]);
			valueabs = abs(valueabs); valueabs /= 9;
			*(ptr + Img_Source->Width*j + i) = valueabs;
			if (valueabs > max)max = valueabs;
			if (valueabs <min)min = valueabs;
		}
	for (uint j = 0; j<Img_Source->Height; j++)
		for (uint i = 0; i < Img_Source->Width; i++)
		{
			int mapped=mapping(*(ptr + Img_Source->Width*j + i), min, max);
			Img_Filtered->SetPixel(i, j, Color::FromArgb(mapped, mapped, mapped));
		}
	delete Img_Extended;
	delete ptr;
	pictureBox_Result->Image = Img_Filtered;
	pictureBox_Result->Refresh();
	delete Img_Filtered;
}
private: System::Void huffmenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Huffman ^ UI=gcnew Huffman;
	UI->Img_Source = Img_Source;
	UI->ShowDialog();
	delete UI;
}
private: System::Void connectComponentToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private:int Median_Square(Bitmap^src)
{
	int length  = pow(src->Width, 2);																			//mask長度。
	int data[49] = { 0 };
	int temp = 0;
	int k = 0;
	for( int i = 0; i < src->Width; i++)
		for ( int j = 0; j < src->Height; j++)
		{
			data[k] = src->GetPixel(i, j).R;
			k++;
		}
	for ( int i = 0; i < length; i++) 
	{
		for ( int j = i; j < length; j++) 
		{
 			if (data[j] < data[i]) 
			{
				temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	}
	
	int value = data[(int)(length / 2)];
	return value;
}
private: System::Void Median_FilterSize_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^Img_Extended;
	int mask_size=Convert::ToInt32(Median_FilterSize->Text);
	mask_size += 2;
	ImageExtend(Img_Source, (mask_size - 1) / 2, Img_Extended);
	Bitmap ^Img_Filtered = gcnew Bitmap(Img_Source->Width, Img_Source->Height);
	if (RadioBtn_Square->Checked)
		{
			for (int j = 0; j < Img_Source->Height; j++)
			{
				for (int i = 0; i < Img_Source->Width; i++)
				{
					Bitmap^ temp = gcnew Bitmap(mask_size, mask_size);
					Rectangle mask = Rectangle(i, j, mask_size, mask_size);
					temp = Img_Extended->Clone(mask, Img_Extended->PixelFormat);
					int mask_value = GetMedian_Square(temp);
					delete temp;
					Color filiter_color;
					filiter_color = Color::FromArgb(mask_value, mask_value, mask_value);
					Img_Filtered->SetPixel(i, j, filiter_color);
				}
			}
			delete Img_Extended;
		}//Square
	if (RadioBtn_Cross->Checked)
	{
	  for (uint j = 0; j < Img_Source->Height; j++)
		for (uint i = 0; i < Img_Source->Width; i++)
		 {
		  Bitmap^ temp = gcnew Bitmap(mask_size, mask_size);
		  Rectangle mask = Rectangle(i, j, mask_size, mask_size);
		  temp = Img_Extended->Clone(mask, Img_Extended->PixelFormat);
		  int mask_value = GetMedian_Cross(temp);
		  delete temp;
		  Color filiter_color;
		  filiter_color = Color::FromArgb(mask_value, mask_value, mask_value);
		  Img_Filtered->SetPixel(i, j, filiter_color);
		}
	}
	if (RadioBtn_MaxMin->Checked)
	{
		for(uint j=0;j<Img_Source->Height;j++)
			for (uint i = 0; i < Img_Source->Width; i++)
			{
				Bitmap ^temp = gcnew Bitmap(mask_size, mask_size);
				Rectangle mask = Rectangle(i, j, mask_size, mask_size);
				temp = Img_Extended->Clone(mask, Img_Extended->PixelFormat);
				int mask_value = Max_Min(temp);
				delete temp;
				Color filiter_color;
				filiter_color = Color::FromArgb(mask_value, mask_value, mask_value);
				Img_Filtered->SetPixel(i, j, filiter_color);
			}
	}
	pictureBox_Result->Image = Img_Filtered;
	pictureBox_Result->Refresh();
	delete Img_Filtered;
}
private:int GetMedian_Square(Bitmap^src)
{
  int length = pow(src->Width, 2);																			//mask長度。
  int data[49] = { 0 };
  int temp = 0;
  int k = 0;
  for (int i = 0; i < src->Width; i++)
	for (int j = 0; j < src->Height; j++)
	{
	  data[k] = src->GetPixel(i, j).R;
	  k++;
	}
  for (int i = 0; i < length; i++)
    {
	  for (int j = i; j < length; j++)
	  {
		if (data[j] < data[i])
		{
		  temp = data[j];
		  data[j] = data[i];
		  data[i] = temp;
		 }
	  }
	 }

  int value = data[(int)(length / 2)];
   return value;
}
private:uint GetMedian_Cross(Bitmap ^src)
{
	uint Center_Index = src->Height / 2;
	uint *Data = new uint[src->Height * 2 - 1];
	uint DataCounter = 0;

	for (uint i = 0; i < src->Width; i++)
	{
		Data[DataCounter] = src->GetPixel(i, Center_Index).R;		
		DataCounter++;
	}
	for (uint j = 0; j < src->Height; j++)
	{
		if (j == Center_Index)continue;
		Data[DataCounter] = src->GetPixel(Center_Index,j).R;
		DataCounter++;
	}
	uint temp = 0;

	for (uint i = 0; i < src->Height * 2 - 1; i++) {
		for (uint j = i; j < src->Height * 2 - 1; j++) {
			if (Data[j] < Data[i]) {
				temp = Data[j];
				Data[j] = Data[i];
				Data[i] = temp;
			}
		}
	}
	uint Median = Data[src->Height];
	delete [] Data;
	return Median;
}
private:uint Max_Min(Bitmap ^src)
{
	uint Center_Index = src->Height / 2;
	int data_index = 0;
	uint *Data = new uint[src->Height * 2 - 1];
	for (uint j = 0; j < src->Height; j++)
	{
		Data[data_index] = src->GetPixel(Center_Index, j).R;
		data_index++;
	}
	for (uint i = 0; i < src->Height; i++)
	{
		if (Center_Index == i)continue;
		Data[data_index] = src->GetPixel(i, Center_Index).R;
		data_index++;
	}
	uint temp;
	for (uint i = 0; i < src->Height * 2 - 1; i++) {
		for (uint j = i; j < src->Height * 2 - 1; j++) {
			if (Data[j] < Data[i]) {
				temp = Data[j];
				Data[j] = Data[i];
				Data[i] = temp;
			}
		}
	}
	uint Median = Data[data_index - 2];//
	delete []  Data;
	return Median;
}
};
}