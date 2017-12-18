#pragma once
#include<cliext/vector>

namespace WinForm_ImgProcessHW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cliext;
	/// <summary>
	/// SelfDefineContrast 的摘要
	/// </summary>
	public ref class SelfDefineContrast : public System::Windows::Forms::Form
	{
	public:
		SelfDefineContrast(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			LBtnClickPoint.push_back(Point(0,255));
			LBtnClickPoint.push_back(Point(255,0));
			pictureBox1->Image = ImageInit;
			pictureBox1->Refresh();
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~SelfDefineContrast()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;
		Bitmap ^ ImageInit = gcnew Bitmap("WhiteImage.bmp");
	public: Bitmap ^Image_Source;
	private: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	public:vector<Point>LBtnClickPoint;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		  
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(53, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(256, 256);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &SelfDefineContrast::pictureBox1_MouseDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 325);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(14, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(402, 325);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(28, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"255";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 15);
			this->label3->TabIndex = 1;
			this->label3->Text = L"255";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(465, 45);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 60);
			this->button1->TabIndex = 2;
			this->button1->Text = L"生成";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SelfDefineContrast::button1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(652, 21);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(257, 230);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(652, 351);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(257, 230);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// SelfDefineContrast
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1240, 686);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"SelfDefineContrast";
			this->Text = L"SelfDefineContrast";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			LBtnClickPoint.insert(LBtnClickPoint.end() - 1, e->Location);
			int a = LBtnClickPoint.size();
			Point temp;
			for (int i = 0; i < LBtnClickPoint.size(); i++) {
				for (int j = i; j < LBtnClickPoint.size(); j++) {
					if (LBtnClickPoint[j].X < LBtnClickPoint[i].X) {
						temp = LBtnClickPoint[j];
						LBtnClickPoint[j] = LBtnClickPoint[i];
						LBtnClickPoint[i] = temp;
					}
				}
			}
			pictureBox1->Image = ImageInit;
			pictureBox1->Refresh();
		    Graphics ^g=pictureBox1->CreateGraphics();
			
			Pen^ ReferencePen = gcnew Pen(Color::Black, 2.0F);
			for(int i=0;i<LBtnClickPoint.size()-1;i++)
			g->DrawLine(ReferencePen, LBtnClickPoint[i].X, LBtnClickPoint[i].Y, LBtnClickPoint[i+1].X, LBtnClickPoint[i+1].Y);
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Bitmap ^Image_Processed = gcnew Bitmap(Image_Source->Width, Image_Source->Height);
		vector<Point> P;
		for (int k = 0; k < LBtnClickPoint.size(); k++)
			P.push_back(Point(LBtnClickPoint[k].X,(unsigned int)abs((int)255 - (int)LBtnClickPoint[k].Y)));
      for(int i=0;i<Image_Source->Width;i++)
		for(int j=0; j <Image_Source->Height;j++)
		  for(int k=0;k<LBtnClickPoint.size()-1;k++)
			  if ((LBtnClickPoint[k].X <= Image_Source->GetPixel(i, j).R)  && (Image_Source->GetPixel(i, j).R <= LBtnClickPoint[k + 1].X))
			  {

				  float m = (float)(P[k + 1].Y - P[k].Y) / (float)(P[k + 1].X - P[k].X);
				  int  Y = m*(float)(Image_Source->GetPixel(i, j).R - P[k].X )+ P[k].Y;
				  Image_Processed->SetPixel(i,j,Color::FromArgb(Y,Y,Y));
			  }
	  pictureBox3->Image = Image_Processed;
	}
};
}
