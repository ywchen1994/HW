#pragma once
#include <iostream> 
using namespace System;
using namespace System::Drawing;
using namespace System::Data;
ref class PCXData
{
public:
	PCXData();
	void LoadPCXFile(String^ filename, PCXData % PCXdata);
	String ^m_filePath;//�ɮ׸��|
	String ^m_fileName;//�ɮצW��
	String^ m_Manufacturer;//Zsoft ID
	int m_version;//����
	int m_Encoding;//PCX run-length encoding
	int m_Hdpi;//
	int m_Vdpi;//
	int m_reserved;//
	String^ m_NPlanes;//
	String^ m_color;//�Ƕ� �m��
	int m_HscreenSize;//Video screen size (Horizontal)
	int m_VscreenSize;// Video screen size (Vertical)
	Bitmap^ m_Image;
	int m_BytePerLine;
	int m_BitsPerPixel;
	Bitmap^ m_ColorMap;
	
};

