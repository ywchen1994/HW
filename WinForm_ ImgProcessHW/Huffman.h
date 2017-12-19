#pragma once

#include<cliext\vector>
#include<string>
#include<vector>
#include<fstream>
namespace WinForm_ImgProcessHW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Runtime::InteropServices;
	using namespace std;
	struct SymAndProbability
	{
		uint16_t Symbol;
		uint16_t Probability;
	};
	struct node
	{
		node * leftChild;
		node * rightChild;
		int frequency;
		int content;
		std::string code;
		short codelength;

	};
	
	/// <summary>
	/// Huffman ���K�n
	/// </summary>
	public ref class Huffman : public System::Windows::Forms::Form
	{
	public:
		Huffman(void)
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
		~Huffman()
		{
			if (components)
			{
				delete components;
				delete[]R_code;
			}
		}
	private: System::Windows::Forms::Button^  Btn_Encode;
	protected:

	protected:

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		SymAndProbability *R_code = new SymAndProbability[256];
		uint16_t NoneZeroCounter = 0;
		System::ComponentModel::Container ^components;
		List<int> R_content;
		List<String^>^ R_huffman_code = gcnew List<String^>();;
		List<Point> R_code_length_fre;
		int R_totalbits;
		int R_totalfre;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::Button^  Btn_Save;
	public:Bitmap ^Img_Source;
	private:
			
#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->Btn_Encode = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Btn_Save = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// Btn_Encode
			// 
			this->Btn_Encode->Location = System::Drawing::Point(36, 12);
			this->Btn_Encode->Name = L"Btn_Encode";
			this->Btn_Encode->Size = System::Drawing::Size(75, 23);
			this->Btn_Encode->TabIndex = 0;
			this->Btn_Encode->Text = L"Encode";
			this->Btn_Encode->UseVisualStyleBackColor = true;
			this->Btn_Encode->Click += gcnew System::EventHandler(this, &Huffman::Btn_Encode_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(480, 35);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(443, 605);
			this->dataGridView1->TabIndex = 2;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Pixel Value";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Probability";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Huffman Code";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Code Length";
			this->Column4->Name = L"Column4";
			// 
			// Btn_Save
			// 
			this->Btn_Save->Location = System::Drawing::Point(165, 11);
			this->Btn_Save->Name = L"Btn_Save";
			this->Btn_Save->Size = System::Drawing::Size(75, 23);
			this->Btn_Save->TabIndex = 3;
			this->Btn_Save->Text = L"Save";
			this->Btn_Save->UseVisualStyleBackColor = true;
			this->Btn_Save->Click += gcnew System::EventHandler(this, &Huffman::Btn_Save_Click);
			// 
			// Huffman
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1116, 652);
			this->Controls->Add(this->Btn_Save);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->Btn_Encode);
			this->Name = L"Huffman";
			this->Text = L"Huffman";
			this->Load += gcnew System::EventHandler(this, &Huffman::Huffman_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void Huffman_Load(System::Object^  sender, System::EventArgs^  e) {
		uint32_t R_statistics[256] = {0};
		for(uint16_t j=0;j<Img_Source->Height;j++)
			for (uint16_t i = 0; i < Img_Source->Width; i++)
			{
				R_statistics[Img_Source->GetPixel(i, j).R]++;
			}
		for (unsigned int i = 0; i < 256; i++)
		{
			if (R_statistics[i] != 0) {
				R_code[NoneZeroCounter].Symbol = i;
				R_code[NoneZeroCounter].Probability = R_statistics[i];
				NoneZeroCounter++;
				R_content.Add(0);
				R_huffman_code->Add("");
				R_code_length_fre.Add(Point(0, 0));
			}
		}
		
	}
private: System::Void Btn_Encode_Click(System::Object^  sender, System::EventArgs^  e) {
		std::vector <node> R_nodeArray;
		for (uint16_t i = 0; i < NoneZeroCounter; i++)
		{
			node tempNode;
			tempNode.content = R_code[i].Symbol;
			tempNode.frequency = R_code[i].Probability;
			tempNode.rightChild = NULL;
			tempNode.leftChild = NULL;
			tempNode.codelength = 0;
			R_nodeArray.push_back(tempNode);
		}
		
		while (!R_nodeArray.empty())
		{
			node * tempNode = new node;
			node * tempNode1 = new node;
			node * tempNode2 = new node;
		
			std::vector<node>::iterator vector_ptr, Min_Index;//�|�N��
			int min_freq = Img_Source->Width*Img_Source->Height;
			for (vector_ptr = R_nodeArray.begin(); vector_ptr != R_nodeArray.end(); vector_ptr++)//��̤p��freq;
			{
				if(min_freq>(*vector_ptr).frequency)
				{
					Min_Index = vector_ptr;
					min_freq = (*vector_ptr).frequency;
				}
			}
			node tempoNode = (*Min_Index);
			*tempNode1 = tempoNode;
			R_nodeArray.erase(Min_Index);//�R��R_nodeArray���M��쪺���ӳ̤p��

			//�A��@���̤p��
		    min_freq= Img_Source->Width*Img_Source->Height;
			for (vector_ptr = R_nodeArray.begin(); vector_ptr != R_nodeArray.end(); vector_ptr++)//�M��R_nodeArray�̤p����
			{

				if (min_freq>(*vector_ptr).frequency)
				{
					Min_Index = vector_ptr;
					min_freq = (*vector_ptr).frequency;
				}
			}
			tempoNode = (*Min_Index);
			*tempNode2 = tempoNode;
			R_nodeArray.erase(Min_Index);//�R��R_nodeArray���M��쪺���ӳ̤p��
			tempNode->leftChild = tempNode1;//�̤p����
			tempNode->rightChild = tempNode2;//�ĤG�p����
			tempNode->frequency = tempNode1->frequency + tempNode2->frequency;//��Ӭۥ[�᪺��
			tempNode->codelength = 0;
			R_nodeArray.push_back(*tempNode);//�A�s�JR_nodeArray���~���|�N
			if (R_nodeArray.size() == 1)//�u�Ѥ@�Ӹ`�I�N�h�X�j��
			{
				break;
			}
		}
		Huffman_treeCoding(&R_nodeArray[0], "", 0);
		for (int i = 0; i < NoneZeroCounter; i++)
		{
			dataGridView1->Rows->Add("R= " + Convert::ToString(R_content[i]), Convert::ToString(Math::Round((double)R_code_length_fre[i].Y / (8*Img_Source->Width*Img_Source->Height), 7)), R_huffman_code[i], Convert::ToString(R_code_length_fre[i].X), Convert::ToString(R_code_length_fre[i].Y*R_code_length_fre[i].X));
		}

		dataGridView1->Rows->Add("Red�`�� :", "1", "", "�����X�� = " + Convert::ToString(Math::Round((double)R_totalbits / R_totalfre, 2)), Convert::ToString(R_totalbits));
		dataGridView1->Refresh();
		

	}
 public: void Huffman_treeCoding(node * temproot, std::string s, short c)
 {
	 node * root1 = new node;
	 root1 = temproot;//�W�v�̰���pixel��
	 root1->code = s;//�N�Ұҽs�X���X
	 root1->codelength = c;//�X��
	 if (root1->leftChild == NULL && root1->rightChild == NULL)//�p�G�s�X�������䪺�l���I��0
	 {
	 const char *code_char = 0;
	 code_char = root1->code.data();
	 int count = 0;
	 for (uint16_t i = 0; i < NoneZeroCounter; i++)
	 {
		 if (root1->content== R_code[i].Symbol)
		 {
			 count = i;
			 break;
		 }
	 }
	 R_content[count] = root1->content;//pixel����
	 R_huffman_code[count] = gcnew String(code_char);//�N�Ұҽs�X���X
	 R_code_length_fre[count] = Point(root1->codelength, root1->frequency);
	 int R_pxiel_totalbits = root1->frequency*root1->codelength;
	 R_totalbits += R_pxiel_totalbits;
	 R_totalfre += root1->frequency;

	}
	 else
	{
		root1->leftChild->codelength = c + 1;
		root1->rightChild->codelength += c + 1;
		Huffman_treeCoding(root1->leftChild, s.append("0"), root1->leftChild->codelength);
		s.erase(s.end() - 1);
		Huffman_treeCoding(root1->rightChild, s.append("1"), root1->rightChild->codelength);
		s.erase(s.end() - 1);
	 }

}
private: System::Void Btn_Save_Click(System::Object^  sender, System::EventArgs^  e) {
	SaveFileDialog ^ SaveUI = gcnew SaveFileDialog;
	SaveUI->CreatePrompt = true;
	SaveUI->OverwritePrompt = true;
	SaveUI->FileName = nullptr;
	SaveUI->Filter = "txt files (*.txt)|*.txt";
	std::fstream fp;
	if (SaveUI->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
	 fp.open((char*)(void*)Marshal::StringToHGlobalAnsi(SaveUI->FileName),std::ios::out);
	 fp<<"Size:(W*H)"<<Img_Source->Width<<" "<< Img_Source->Height<<std::endl;
	 fp <<"SymbolCategory:"<<" "<< NoneZeroCounter<<endl;
	}
	fp.close();
}
};
}
