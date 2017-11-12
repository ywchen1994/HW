#include "LoadingUI.h"

using namespace WinForm_ImgProcessHW;
using namespace System;
[STAThread]
int main(cli::array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew LoadingUI());
	return 0;
}