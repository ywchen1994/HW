#pragma once

#include<cliext\vector>
#include<string>
#include<vector>
namespace WinForm_ImgProcessHW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	
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
	struct HuffmanPackage
	{
		SymAndProbability RawData;
		std::string Code;
		UInt16 CodeLength;
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
	public:Bitmap ^Img_Source;
	private:List<String^>^ R_huffman_code;
			
#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->Btn_Encode = (gcnew System::Windows::Forms::Button());
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
			// Huffman
			// 
			this->Load += gcnew System::EventHandler(this, &Huffman::Huffman_Load);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1116, 652);
			this->Controls->Add(this->Btn_Encode);
			this->Name = L"Huffman";
			this->Text = L"Huffman";
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
			}
		}
		SymAndProbability temp;
		for (uint16_t i = 0; i < NoneZeroCounter; i++) {
			for (uint16_t j = i; j <NoneZeroCounter; j++) {
				if (R_code[j].Probability > R_code[i].Probability) {
					temp.Probability = R_code[j].Probability;
					temp.Symbol = R_code[j].Symbol;

					R_code[j].Probability = R_code[i].Probability;
					R_code[j].Symbol = R_code[i].Symbol;

					R_code[i].Probability = temp.Probability;
					R_code[i].Symbol = temp.Symbol;
				}
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
			std::vector<node>::iterator Min_index,R_node_ptr;
			int min_freq = Img_Source->Width*Img_Source->Height;
			for (R_node_ptr = R_nodeArray.begin(); R_node_ptr!= R_nodeArray.end(); R_node_ptr++)//��̤p��freq;
			{
				if ((*R_node_ptr).frequency< min_freq){
					min_freq = (*R_node_ptr).frequency;
					Min_index =R_node_ptr;
				}	
			}
			node Min_Node_l = (*Min_index);
			R_nodeArray.erase(Min_index);//�R���̤p��freq

			//�A��@���̤p��
		    min_freq= Img_Source->Width*Img_Source->Height;
			for (R_node_ptr = R_nodeArray.begin(); R_node_ptr != R_nodeArray.end(); R_node_ptr++)//��̤p��freq;
			{
				if ((*R_node_ptr).frequency< min_freq) {
					min_freq = (*R_node_ptr).frequency;
					Min_index = R_node_ptr;
				}
			}
			node Min_Node_r = *Min_index;
			R_nodeArray.erase(Min_index);//�R���̤p��freq
			node tempNode;
			tempNode.leftChild = &Min_Node_l;//�̤p����
			tempNode.rightChild = &Min_Node_r;//�ĤG�p����
			tempNode.frequency = Min_Node_l.frequency + Min_Node_r.frequency;//��Ӭۥ[�᪺��
			tempNode.codelength = 0;
			R_nodeArray.push_back(tempNode);
			if (R_nodeArray.size() == 1)break;
		}
		Huffman_treeCoding(&R_nodeArray[0], "", 0);
		delete[]R_code;

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
	/* R_content[count] = root1->content;//pixel����
	 R_huffman_code[count] = gcnew String(code_char);//�N�Ұҽs�X���X
	 R_code_length_fre[count] = Point(root1->codelength, root1->frequency);
	 int R_pxiel_totalbits = root1->frequency*root1->codelength;
	 R_totalbits += R_pxiel_totalbits;
	 R_totalfre += root1->frequency;*/

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
};
}
