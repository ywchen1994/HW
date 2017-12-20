#pragma once
#include"ImageProcessUI.h"
#include"VideoProcessUI.h"
namespace WinForm_ImgProcessHW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// SelectUI ���K�n
	/// </summary>
	public ref class SelectUI : public System::Windows::Forms::Form
	{
	public:
		SelectUI(void)
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
		~SelectUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Btn_Img;
	protected:

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^  button1;
			 static bool flag = false;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SelectUI::typeid));
			this->Btn_Img = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Btn_Img
			// 
			this->Btn_Img->BackColor = System::Drawing::Color::Red;
			this->Btn_Img->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Btn_Img->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Btn_Img->Location = System::Drawing::Point(24, 183);
			this->Btn_Img->Margin = System::Windows::Forms::Padding(2);
			this->Btn_Img->Name = L"Btn_Img";
			this->Btn_Img->Size = System::Drawing::Size(139, 52);
			this->Btn_Img->TabIndex = 0;
			this->Btn_Img->Text = L"IMAGE";
			this->Btn_Img->UseVisualStyleBackColor = false;
			this->Btn_Img->Click += gcnew System::EventHandler(this, &SelectUI::Btn_Img_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Blue;
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(328, 183);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(139, 52);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Video";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &SelectUI::Btn_Vdo_Click);
			// 
			// SelectUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(501, 338);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Btn_Img);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"SelectUI";
			this->Text = L"SelectUI";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Btn_Img_Click(System::Object^  sender, System::EventArgs^  e) {
		ImageProcessUI ^UI = gcnew ImageProcessUI;
		Hide();
	    UI->ShowDialog();
		delete UI;
		this->Show();
	}
	private: System::Void Btn_Vdo_Click(System::Object^  sender, System::EventArgs^  e) {
		VideoProcessUI ^ UI = gcnew VideoProcessUI;
		Hide();
		UI->ShowDialog();
		delete UI;
		this->Show();
	}
	};
}
