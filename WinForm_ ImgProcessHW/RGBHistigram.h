#pragma once

namespace WinForm_ImgProcessHW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// RGBHistigram 的摘要
	/// </summary>
	public ref class RGBHistigram : public System::Windows::Forms::Form
	{
	public:
		RGBHistigram(void)
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
		~RGBHistigram()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataVisualization::Charting::Chart^  chart_RGB;
	protected:

	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart_RGB = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_RGB))->BeginInit();
			this->SuspendLayout();
			// 
			// chart_RGB
			// 
			chartArea1->AxisX->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
			chartArea1->AxisX->LogarithmBase = 255;
			chartArea1->AxisX->Maximum = 255;
			chartArea1->AxisX->Minimum = 0;
			chartArea1->Name = L"ChartArea1";
			this->chart_RGB->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart_RGB->Legends->Add(legend1);
			this->chart_RGB->Location = System::Drawing::Point(12, 36);
			this->chart_RGB->Name = L"chart_RGB";
			series1->ChartArea = L"ChartArea1";
			series1->Color = System::Drawing::Color::Red;
			series1->Legend = L"Legend1";
			series1->Name = L"R";
			series2->ChartArea = L"ChartArea1";
			series2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series2->Legend = L"Legend1";
			series2->Name = L"G";
			series3->ChartArea = L"ChartArea1";
			series3->Color = System::Drawing::Color::Blue;
			series3->Legend = L"Legend1";
			series3->Name = L"B";
			this->chart_RGB->Series->Add(series1);
			this->chart_RGB->Series->Add(series2);
			this->chart_RGB->Series->Add(series3);
			this->chart_RGB->Size = System::Drawing::Size(909, 542);
			this->chart_RGB->TabIndex = 0;
			// 
			// RGBHistigram
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1044, 616);
			this->Controls->Add(this->chart_RGB);
			this->Name = L"RGBHistigram";
			this->Text = L"RGBHistigram";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_RGB))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
