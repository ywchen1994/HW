#pragma once
#include"ImageProcessUI.h"
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
		static bool flag=false;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SelectUI::typeid));
			this->Btn_Img = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Btn_Img
			// 
			this->Btn_Img->BackColor = System::Drawing::Color::Red;
			this->Btn_Img->Font = (gcnew System::Drawing::Font(L"ItalicT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Btn_Img->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Btn_Img->Location = System::Drawing::Point(21, 324);
			this->Btn_Img->Name = L"Btn_Img";
			this->Btn_Img->Size = System::Drawing::Size(185, 65);
			this->Btn_Img->TabIndex = 0;
			this->Btn_Img->Text = L"IMAGE";
			this->Btn_Img->UseVisualStyleBackColor = false;
			this->Btn_Img->Click += gcnew System::EventHandler(this, &SelectUI::Btn_Img_Click);
			// 
			// SelectUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(668, 422);
			this->Controls->Add(this->Btn_Img);
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
	}
	};
}
