#pragma once

#include<vector>
#include<string>

namespace WinForm_ImgProcessHW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
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
	std::vector<SymAndProbability> R_code;
	/// <summary>
	/// Huffman 的摘要
	/// </summary>
	public ref class Huffman : public System::Windows::Forms::Form
	{
	public:
		Huffman(void)
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
		/// 設計工具所需的變數。
		/// </summary>
		
		System::ComponentModel::Container ^components;
	public:Bitmap ^Img_Source;
	private:List<String^>^ R_huffman_code;
			
#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
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
		uint16_t noneZeroCounter = 0;
		for (unsigned char i = 0; i < 256; i++)
		{
			if (R_statistics[i] != 0) {
				noneZeroCounter++;
				SymAndProbability temp;
				temp.Symbol = i;
				temp.Probability = R_statistics[i];
				R_code.push_back(temp);
			}
		}
		SymAndProbability temp;
		for (uint16_t i = 0; i < noneZeroCounter; i++) {
			for (uint16_t j = i; j <noneZeroCounter; j++) {
				if (R_code[j].Probability > R_code[i].Probability) {
					temp = R_code[j];
					R_code[j] = R_code[i];
					R_code[i] = temp;
				}
			}
		}
	}
	private: System::Void Btn_Encode_Click(System::Object^  sender, System::EventArgs^  e) {
		std::vector <node> R_nodeArray;
		for (uint16_t i = 0; i < R_code.size(); i++)
		{
			node tempNode;
			tempNode.content = R_code[i].Symbol;
			tempNode.content = R_code[i].Probability;
			tempNode.rightChild = NULL;
			tempNode.leftChild = NULL;
			tempNode.codelength = 0;
			R_nodeArray.push_back(tempNode);
		}
		R_code.clear();
		while (!R_nodeArray.empty())
		{
			std::vector<node>::iterator Min_index,R_node_ptr;
			int min_freq = Img_Source->Width*Img_Source->Height;
			for (R_node_ptr = R_nodeArray.begin(); R_node_ptr!= R_nodeArray.end(); R_node_ptr++)//找最小的freq;
			{
				if ((*R_node_ptr).frequency< min_freq){
					min_freq = (*R_node_ptr).frequency;
					Min_index =R_node_ptr;
				}	
			}
			node Min_Node_l = (*Min_index);
			R_nodeArray.erase(Min_index);//刪除最小的freq

			//再找一次最小的
		    min_freq= Img_Source->Width*Img_Source->Height;
			for (R_node_ptr = R_nodeArray.begin(); R_node_ptr != R_nodeArray.end(); R_node_ptr++)//找最小的freq;
			{
				if ((*R_node_ptr).frequency< min_freq) {
					min_freq = (*R_node_ptr).frequency;
					Min_index = R_node_ptr;
				}
			}
			node Min_Node_r = *Min_index;
			R_nodeArray.erase(Min_index);//刪除最小的freq
			node tempNode;
			tempNode.leftChild = &Min_Node_l;//最小的值
			tempNode.rightChild = &Min_Node_r;//第二小的值
			tempNode.frequency = Min_Node_l.frequency + Min_Node_r.frequency;//兩個相加後的值
			tempNode.codelength = 0;
			R_nodeArray.push_back(tempNode);
			if (R_nodeArray.size() == 1)break;

		}
		

	}
	};
}
