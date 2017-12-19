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
		uint32_t Symbol;
		uint32_t Probability;
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
	struct HumanPackage
	{
		uint32_t Symbol;
		std::string code;
	};

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
				delete[]R_code;
				delete[]RHumanPackage;
				delete[]G_code;
				delete[]GHumanPackage;
				delete[]B_code;
				delete[]BHumanPackage;
			}
		}
	private: System::Windows::Forms::Button^  Btn_Encode;
	protected:

	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		
		SymAndProbability *R_code = new SymAndProbability[256];
		SymAndProbability *G_code = new SymAndProbability[256];
		SymAndProbability *B_code = new SymAndProbability[256];
		uint16_t R_NoneZeroCounter = 0;
		uint16_t G_NoneZeroCounter = 0;
		uint16_t B_NoneZeroCounter = 0;
		System::ComponentModel::Container ^components;
		HumanPackage*  RHumanPackage;
		HumanPackage*  GHumanPackage;
		HumanPackage*  BHumanPackage;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::Button^  Btn_Save;
	private: System::Windows::Forms::Button^  Btn_Load;
	public:Bitmap ^Img_Source;
	private:
			
#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
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
			this->Btn_Load = (gcnew System::Windows::Forms::Button());
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
			// Btn_Load
			// 
			this->Btn_Load->Location = System::Drawing::Point(36, 74);
			this->Btn_Load->Name = L"Btn_Load";
			this->Btn_Load->Size = System::Drawing::Size(75, 23);
			this->Btn_Load->TabIndex = 4;
			this->Btn_Load->Text = L"Decode";
			this->Btn_Load->UseVisualStyleBackColor = true;
			this->Btn_Load->Click += gcnew System::EventHandler(this, &Huffman::Btn_Load_Click);
			// 
			// Huffman
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1116, 652);
			this->Controls->Add(this->Btn_Load);
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
		uint32_t G_statistics[256] = { 0 };
		uint32_t B_statistics[256] = { 0 };
		for(uint16_t j=0;j<Img_Source->Height;j++)
			for (uint16_t i = 0; i < Img_Source->Width; i++)
			{
				R_statistics[Img_Source->GetPixel(i, j).R]++;
				G_statistics[Img_Source->GetPixel(i, j).G]++;
			}
		for (unsigned int i = 0; i < 256; i++)
		{
			if (R_statistics[i] != 0) {
				R_code[R_NoneZeroCounter].Symbol = i;
				R_code[R_NoneZeroCounter].Probability = R_statistics[i];
				R_NoneZeroCounter++;
			}
		}
		
	}
private: System::Void Btn_Encode_Click(System::Object^  sender, System::EventArgs^  e) {
		std::vector <node> R_nodeArray;
	     RHumanPackage = new HumanPackage[R_NoneZeroCounter];
		for (uint16_t i = 0; i < R_NoneZeroCounter; i++)
		{
			node tempNode;
			tempNode.content = R_code[i].Symbol;
			tempNode.frequency = R_code[i].Probability;
			tempNode.rightChild = NULL;
			tempNode.leftChild = NULL;
			tempNode.codelength = 0;
			R_nodeArray.push_back(tempNode);
			RHumanPackage[i].code =" ";
		}
		
		CreateHumanTree(R_nodeArray);
		Huffman_treeCoding(&R_nodeArray[0], "", 0, RHumanPackage);
		/*for (UInt16 i = 0; i < NoneZeroCounter; i++)//Debug用
		{
			int bvbbb = RHumanPackage[i].Symbol;
			string aaa = RHumanPackage[i].code;
			int aaaaaa = RHumanPackage[i].code.length();
			int bbb = 999;
		}*/
		double AverageCodeLength = 0;
		for (uint16_t i = 0; i < R_NoneZeroCounter; i++)
		{
			const char *code_char = RHumanPackage[i].code.data();
			System::String^ str=gcnew System::String(code_char);
			AverageCodeLength +=R_code[i].Probability*RHumanPackage[i].code.length();
			dataGridView1->Rows->Add(R_code[i].Symbol.ToString(),R_code[i].Probability.ToString(),str, RHumanPackage[i].code.length().ToString());
		}

		dataGridView1->Rows->Add("壓縮比:"+((Img_Source->Width*Img_Source->Height * 8)/AverageCodeLength).ToString(),"原長度"+(Img_Source->Width*Img_Source->Height*8).ToString(),"平均碼長"+ (AverageCodeLength / (Img_Source->Width*Img_Source->Height)).ToString(), AverageCodeLength.ToString());
		dataGridView1->Refresh();

	}
private:void CreateHumanTree(std::vector<node>&NodeArray)
{
	while (!NodeArray.empty())
	{

		node * tempNode1 = new node;
		node * tempNode2 = new node;

		std::vector<node>::iterator vector_ptr, Min_Index;//疊代器
		int min_freq = Img_Source->Width*Img_Source->Height;
		for (vector_ptr = NodeArray.begin(); vector_ptr != NodeArray.end(); vector_ptr++)//找最小的freq;
		{
			if (min_freq>(*vector_ptr).frequency)
			{
				Min_Index = vector_ptr;
				min_freq = (*vector_ptr).frequency;
			}
		}
		node temp_Node = (*Min_Index);
		*tempNode1 = temp_Node;
		NodeArray.erase(Min_Index);//刪除R_nodeArray中尋找到的那個最小值

									 //再找一次最小的
		min_freq = Img_Source->Width*Img_Source->Height;
		for (vector_ptr = NodeArray.begin(); vector_ptr != NodeArray.end(); vector_ptr++)//尋找R_nodeArray最小的值
		{

			if (min_freq>(*vector_ptr).frequency)
			{
				Min_Index = vector_ptr;
				min_freq = (*vector_ptr).frequency;
			}
		}
		temp_Node = (*Min_Index);
		*tempNode2 = temp_Node;
		NodeArray.erase(Min_Index);//刪除R_nodeArray中尋找到的那個最小值
		node * tempNode = new node;
		tempNode->leftChild = tempNode1;//最小的值
		tempNode->rightChild = tempNode2;//第二小的值
		tempNode->frequency = tempNode1->frequency + tempNode2->frequency;//兩個相加後的值
		tempNode->codelength = 0;
		NodeArray.push_back(*tempNode);//再存入R_nodeArray中繼續疊代
		if (NodeArray.size() == 1)//只剩一個節點就退出迴圈
		{
			break;
		}
	}
}
public: void Huffman_treeCoding(node * temproot, std::string s, short c, HumanPackage* Package)
 {
	 node * root1 = new node;
	 root1 = temproot;//頻率最高的pixel值
	 root1->code = s;//霍夫曼編碼的碼
	 root1->codelength = c;//碼長
	 if (root1->leftChild == NULL && root1->rightChild == NULL)//如果編碼左有兩邊的子結點為0
	 {
	 int count = 0;
	 for (uint16_t i = 0; i < R_NoneZeroCounter; i++)
	 {
		 if (root1->content== R_code[i].Symbol)
		 {
			 count = i;
			 break;
		 }
	 }
	 Package[count].code= root1->code;
	 Package[count].Symbol = root1->content;
	}
	 else
	{
		root1->leftChild->codelength = c + 1;
		root1->rightChild->codelength += c + 1;
		Huffman_treeCoding(root1->leftChild, s.append("0"), root1->leftChild->codelength, Package);
		s.erase(s.end() - 1);
		Huffman_treeCoding(root1->rightChild, s.append("1"), root1->rightChild->codelength, Package);
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
	 fp<<"Size"<<" "<<Img_Source->Width<<" "<< Img_Source->Height<<std::endl;
	 fp <<"SymbolCategory:"<<" "<< R_NoneZeroCounter<<endl;
	 for (UInt16 i = 0; i < R_NoneZeroCounter; i++)
	 {
		 fp << RHumanPackage[i].Symbol << " " << std::stoi(RHumanPackage[i].code, nullptr, 2) << endl;
	 }
	 int counter = 0;
	 for (size_t j = 0; j <Img_Source->Height; j++)
	 {
		 for (size_t i = 0;i<Img_Source->Width; i++)
		 {
			 for (size_t k = 0; k < R_NoneZeroCounter; k++)
			 {
				 if (Img_Source->GetPixel(i, j).R == RHumanPackage[k].Symbol)
				 {
					 fp << std::stoi(RHumanPackage[k].code, nullptr, 2) <<" ";
					 counter++;
					 if (counter==127)
					 {
						 fp << endl;
						 counter = 0;
					 }
				 }
			 }
		 }
	 }
	}
	fp.close();
	delete SaveUI;
}
private: System::Void Btn_Load_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog ^OpnFileUI = gcnew OpenFileDialog;
	OpnFileUI->Filter = "txt files (*.txt)|*.txt";
	fstream fp;
	if (OpnFileUI->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		fp.open((char*)(void*)Marshal::StringToHGlobalAnsi(OpnFileUI->FileName), std::ios::in);
		char line[100];
		fp.getline(line,sizeof(line));
		cli::array<String^>^result;
		cli::array<Char>^sep = gcnew cli::array<Char>{' '};
		System::String^ str = gcnew String(line);
		result = str->Split(sep, StringSplitOptions::RemoveEmptyEntries);
		UInt16 W = 0, H = 0;;
		if (result[0] == "Size")
		{
			W = Convert::ToInt16(result[1]);
			H = Convert::ToInt16(result[2]);
		}
		delete str;
		fp.getline(line, sizeof(line));
		str = gcnew String(line);
		result = str->Split(sep, StringSplitOptions::RemoveEmptyEntries);

		UInt16 decode_R_NoneZero = 0;
		if (result[0] == "SymbolCategory:")
		{
			decode_R_NoneZero = Convert::ToInt16(result[1]);
		}

		
		for (UInt16 i = 0; i < decode_R_NoneZero; i++)
		{
			delete str;
			fp.getline(line, sizeof(line));
			str = gcnew String(line);
			result = str->Split(sep, StringSplitOptions::RemoveEmptyEntries);
			
		}
	}
	fp.close();
}

};
}
