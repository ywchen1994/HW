#include "PCXData.h"

PCXData::PCXData()
{
}

void PCXData::LoadPCXFile(String ^ filename, PCXData % PCXdata)
{
	PCXdata.filePath = filename;
	String^name = System::IO::Path::GetFileName(filename);//得到檔案名稱
	PCXdata.fileName = name;
	FileStream^ fs = gcnew FileStream(filename, FileMode::Open);//資料流
	BinaryReader^ br = gcnew BinaryReader(fs);//二進位編碼
	while (br->BaseStream->Position < 128)
	{
		switch (br->BaseStream->Position)
		{
		case 0:
			PCXdata.m_Manufacturer = br->ReadByte().ToString();
			break;
		case 1:
			PCXdata.m_version = br->ReadByte();
			break;
		case 2:
			PCXdata.m_Encoding = br->ReadByte();
			break;
		case 3:
			PCXdata.m_BitsPerPixel = br->ReadByte();
			break;
		case 4: {
			int Xmin = br->ReadByte();
			Xmin = Xmin + 256 * br->ReadByte();
			int Ymin = br->ReadByte();
			Ymin = Ymin + 256 * br->ReadByte();
			int Xmax = br->ReadByte();
			Xmax = Xmax + 256 * br->ReadByte();
			int Ymax = br->ReadByte();
			Ymax = Ymax + 256 * br->ReadByte();
			PCXdata.m_Image = gcnew Bitmap(Xmax - Xmin + 1, Ymax - Ymin + 1);
			break;
		}
		case 12:
			PCXdata.m_Hdpi = br->ReadByte();
			break;
		case 14:
			PCXdata.m_Vdpi = br->ReadByte();
			break;
		case 64:
			PCXdata.m_reserved = br->ReadByte();
			break;
		case 65:
			PCXdata.m_NPlanes = br->ReadByte().ToString();
			break;
		case 66:
			PCXdata.m_BytePerLine = br->ReadByte();
			PCXdata.m_BytePerLine = 256 * (br->ReadByte()) + PCXdata.m_BytePerLine;
			break;
		case 68:
		{
			if (br->ReadByte() == 1)
			{
				PCXdata.m_color = "Color or BW";
			}
			else
			{
				PCXdata.m_color = "Grayscale";
			}
			break;
		}
		case 70:
			PCXdata.m_HscreenSize = br->ReadByte();
			break;
		case 72:
			PCXdata.m_VscreenSize = br->ReadByte();
			break;
		default:
			br->ReadByte();
			break;
		}
	}
	/***********************************/
	PCXdata.m_ColorMap = gcnew Bitmap(128, 128);
	br->BaseStream->Position = (fs->Length) - 769;//

	int check = br->ReadByte();
	Graphics^ graphics = Graphics::FromImage(PCXdata.m_ColorMap);
	Color palette;
	short color[256][3] = { { 0, 0, 0 } };
	if (check != 12) {
		br->BaseStream->Position = 16;
		int red, green, blue;
		for (int i = 0, c = 0; i < 4; i++)
			for (int j = 0; j < 4; j++, c++) {
				red = br->ReadByte();
				green = br->ReadByte();
				blue = br->ReadByte();
				palette = Color::FromArgb(red, green, blue);
				SolidBrush^ brush = gcnew SolidBrush(palette);
				System::Drawing::Rectangle rect((i * 32), (j * 32), 32, 32);
				graphics->FillRectangle(brush, rect);
				color[c][0] = red;
				color[c][1] = green;
				color[c][2] = blue;
			}
	}
	else if (check == 12)
	{
		int red, green, blue;
		for (int i = 0, c = 0; i < 16; i++)
			for (int j = 0; j < 16; j++, c++) {
				red = br->ReadByte();
				green = br->ReadByte();
				blue = br->ReadByte();
				palette = Color::FromArgb(red, green, blue);
				SolidBrush^ brush = gcnew SolidBrush(palette);
				System::Drawing::Rectangle rect((i * 8), (j * 8), 8, 8);
				graphics->FillRectangle(brush, rect);
				color[c][0] = red;
				color[c][1] = green;
				color[c][2] = blue;
			}
	}
	br->BaseStream->Position = 127;
	int count = br->ReadByte();

	if (PCXdata.m_Encoding == 0)
	{
		int y = 0;
		int x = 0;
		while (y < PCXdata.m_Image->Height)
		{
			int pposition = br->BaseStream->Position;
			int ck_c = br->ReadByte();
			bool over = false;
			Color newColor = Color::FromArgb(color[ck_c][0], color[ck_c][1], color[ck_c][2]);
			PCXdata.m_Image->SetPixel(x, y, newColor);
			x++;
			if (x >= PCXdata.m_Image->Width)
			{
				y++;
				x = 0;
			}
		}
	}
	/********************以下處理彩色**********************/
	else if (count == 0) {
		int y = 0;
		int x = 0;
		while (y < PCXdata.m_Image->Height)
		{
			int pposition = br->BaseStream->Position;
			int ck_c = br->ReadByte();
			bool over = false;
			if (ck_c >= 192)
			{
				int length = ck_c - 192;
				int colorcode = br->ReadByte();
				Color newColor = Color::FromArgb(color[colorcode][0], color[colorcode][1], color[colorcode][2]);
				for (length; length > 0; length--) {
					PCXdata.m_Image->SetPixel(x, y, newColor);
					x++;
					if (x >= PCXdata.m_Image->Width)
					{
						y++;
						x = 0;
					}
					if (y >= PCXdata.m_Image->Height)
					{
						break;
					}
				}
			}
			else {
				Color newColor = Color::FromArgb(color[ck_c][0], color[ck_c][1], color[ck_c][2]);
				PCXdata.m_Image->SetPixel(x, y, newColor);
				x++;
				if (x >= PCXdata.m_Image->Width)
				{
					y++;
					x = 0;
				}
			}
		}
	}
	fs->Close();
	throw gcnew System::NotImplementedException();
}
