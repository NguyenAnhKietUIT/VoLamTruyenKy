#include "PhanTu.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void PhanTu::Input()
{
}

void PhanTu::Output()
{
}

float PhanTu::SatThuong(PhanTu*)
{
	return 0.0f;
}

float PhanTu::MucSatThuong()
{
	return 0.0f;
}

void PhanTu::SetHe(int Loai)
{
	switch (Loai)
	{
	case 1:
		mpHe = new Kim;
		break;
	case 2:
		mpHe = new Moc;
		break;
	case 3:
		mpHe = new Thuy;
		break;
	case 4:
		mpHe = new Hoa;
		break;
	case 5:
		mpHe = new Tho;
		break;
	default: break;
	}
}

He* PhanTu::GetHe()
{
	return mpHe;
}

void NhanVat::Input()
{
	cin.ignore();
	do
	{
		cout << "Nhap ten: ";
		getline(cin, Ten);
	} while (Ten == "");

	cout << "Nhap cap do: ";
	cin >> iCapDo;

	cout << "Nhap he ngu hanh: " << endl;
	HANDLE ConsoleColor;
	ConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	int Loai = 0;
	do
	{
		SetConsoleTextAttribute(ConsoleColor, 8);
		cout << "1. Kim" << endl;
		SetConsoleTextAttribute(ConsoleColor, 10);
		cout << "2. Moc" << endl;
		SetConsoleTextAttribute(ConsoleColor, 11);
		cout << "3. Thuy" << endl;
		SetConsoleTextAttribute(ConsoleColor, 12);
		cout << "4. Hoa" << endl;
		SetConsoleTextAttribute(ConsoleColor, 6);
		cout << "5. Tho" << endl;
		SetConsoleTextAttribute(ConsoleColor, 15);
		cout << "Nhap 1 so 1~5: ";
		cin >> Loai;

	} while (Loai < 1);

	cout << "Nhap mon phai: " << endl;
	switch (Loai)
	{
		case 1:
		{
			mpHe = new Kim;
			HeName = "Kim";
			SetConsoleTextAttribute(ConsoleColor, 8);
			cout << "1. Thieu Lam" << endl;
			cout << "2. Thien Vuong bang" << endl;
			SetConsoleTextAttribute(ConsoleColor, 15);
			cout << "Chon 1 so trong 2 so tren: ";
			cin >> MonPhai;
			if (MonPhai == 1)
				mpMonPhai = "Thieu Lam";
			else
				mpMonPhai = "Thien Vuong bang";
			break;
		}
		case 2:
		{
			mpHe = new Moc;
			HeName = "Moc";
			SetConsoleTextAttribute(ConsoleColor, 10);
			cout << "1. Ngu Doc Giao" << endl;
			cout << "2. Duong Mon" << endl;
			SetConsoleTextAttribute(ConsoleColor, 15);
			cout << "Chon 1 so trong 2 so tren: ";
			cin >> MonPhai;
			if (MonPhai == 1)
				mpMonPhai = "Ngu Doc Giao";
			else
				mpMonPhai = "Duong Mon";
			break;
		}
		case 3:
		{
			mpHe = new Thuy;
			HeName = "Thuy";
			SetConsoleTextAttribute(ConsoleColor, 11);
			cout << "1. Nga My" << endl;
			cout << "2. Thuy Yen Mon" << endl;
			SetConsoleTextAttribute(ConsoleColor, 15);
			cout << "Chon 1 so trong 2 so tren: ";
			cin >> MonPhai;
			if (MonPhai == 1)
				mpMonPhai = "Nga My";
			else
				mpMonPhai = "Thuy Yen Mon";
			break;
		}
		case 4:
		{
			mpHe = new Hoa;
			HeName = "Hoa";
			SetConsoleTextAttribute(ConsoleColor, 12);
			cout << "1. Cai Bang" << endl;
			cout << "2. Thien Nhan giao" << endl;
			SetConsoleTextAttribute(ConsoleColor, 15);
			cout << "Chon 1 so trong 2 so tren: ";
			cin >> MonPhai;
			if (MonPhai == 1)
				mpMonPhai = "Cai Bang";
			else
				mpMonPhai = "Thien Nhan giao";
			break;
		}
		case 5:
		{
			mpHe = new Tho;
			HeName = "Tho";
			SetConsoleTextAttribute(ConsoleColor, 6);
			cout << "1. Con Lon" << endl;
			cout << "2. Vo Dang" << endl;
			SetConsoleTextAttribute(ConsoleColor, 15);
			cout << "Chon 1 so trong 2 so tren: ";
			cin >> MonPhai;
			if (MonPhai == 1)
				mpMonPhai = "Con Lon";
			else
				mpMonPhai = "Vo Dang";
			break;
		}
		default:
			break;
	}
	SetConsoleTextAttribute(ConsoleColor, 15);
	cout << "=====================================" << endl;
}

void NhanVat::Output()
{
	HANDLE ConsoleColor;
	ConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	int a = this->GetHe()->PhanLoai();
	switch (a)
	{
	case 1:
	{
		SetConsoleTextAttribute(ConsoleColor, 8);
		break;
	}
	case 2:
	{
		SetConsoleTextAttribute(ConsoleColor, 10);
		break;
	}
	case 3:
	{
		SetConsoleTextAttribute(ConsoleColor, 11);
		break;
	}
	case 4:
	{
		SetConsoleTextAttribute(ConsoleColor, 12);
		break;
	}
	case 5:
	{
		SetConsoleTextAttribute(ConsoleColor, 6);
		break;
	}
	default: break;
	}

	cout << "Ten: " << this->Ten << endl;
	cout << "Cap: " << this->iCapDo << endl;
	cout << "Mon Phai: " << this->mpMonPhai << endl;
	cout << "He: " << this->HeName << endl;
	cout << "Muc sat thuong: " << this->MucSatThuong() << endl;
	SetConsoleTextAttribute(ConsoleColor, 15);
	cout << endl;
}

float NhanVat::MucSatThuong()
{
	return iCapDo * 5;
}

float NhanVat::SatThuong(PhanTu* p)
{
	float fMST = MucSatThuong();
	return fMST + fMST * mpHe->TLSatThuong(p->GetHe()) / 100;
}

void ThongThuong::Input()
{
	cin.ignore();
	cout << "Nhap ten: ";
	getline(cin, Ten);

	cout << "Nhap cap do: ";
	cin >> iCapDo;

	cout << "Nhap he ngu hanh: " << endl;
	HANDLE ConsoleColor;
	ConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	int Loai = 0;
	do
	{
		SetConsoleTextAttribute(ConsoleColor, 8);
		cout << "1. Kim" << endl;
		SetConsoleTextAttribute(ConsoleColor, 10);
		cout << "2. Moc" << endl;
		SetConsoleTextAttribute(ConsoleColor, 11);
		cout << "3. Thuy" << endl;
		SetConsoleTextAttribute(ConsoleColor, 12);
		cout << "4. Hoa" << endl;
		SetConsoleTextAttribute(ConsoleColor, 6);
		cout << "5. Tho" << endl;
		SetConsoleTextAttribute(ConsoleColor, 15);
		cout << "Nhap 1 so 1~5: ";
		cin >> Loai;

		cout << "=====================================" << endl;
	} while (Loai < 1);

	switch (Loai)
	{
	case 1:
		mpHe = new Kim;
		HeName = "Kim";
		break;
	case 2:
		mpHe = new Moc;
		HeName = "Moc";
		break;
	case 3:
		mpHe = new Thuy;
		HeName = "Thuy";
		break;
	case 4:
		mpHe = new Hoa;
		HeName = "Hoa";
		break;
	case 5:
		mpHe = new Tho;
		HeName = "Tho";
		break;
	default:
		break;
	}
}

void ThongThuong::Output()
{
	HANDLE ConsoleColor;
	ConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	int a = this->GetHe()->PhanLoai();
	switch (a)
	{
	case 1:
	{
		SetConsoleTextAttribute(ConsoleColor, 8);
		break;
	}
	case 2:
	{
		SetConsoleTextAttribute(ConsoleColor, 10);
		break;
	}
	case 3:
	{
		SetConsoleTextAttribute(ConsoleColor, 11);
		break;
	}
	case 4:
	{
		SetConsoleTextAttribute(ConsoleColor, 12);
		break;
	}
	case 5:
	{
		SetConsoleTextAttribute(ConsoleColor, 6);
		break;
	}
	default: break;
	}
	cout << "Ten: " << this->Ten << endl;
	cout << "Cap: " << this->iCapDo << endl;
	cout << "He: " << this->HeName << endl;
	cout << "Muc sat thuong: " << this->MucSatThuong() << endl;
	SetConsoleTextAttribute(ConsoleColor, 15);
	cout << endl;
}

float ThongThuong::MucSatThuong()
{
	return iCapDo * 3;
}

float ThongThuong::SatThuong(PhanTu* p)
{
	float fMST = MucSatThuong();
	return fMST + fMST * mpHe->TLSatThuong(p->GetHe()) / 100;
}

void DauLinh::Input()
{
	cin.ignore();
	cout << "Nhap ten: ";
	getline(cin, Ten);

	cout << "Nhap cap do: ";
	cin >> iCapDo;

	cout << "Nhap he ngu hanh: " << endl;
	HANDLE ConsoleColor;
	ConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	int Loai = 0;
	do
	{
		SetConsoleTextAttribute(ConsoleColor, 8);
		cout << "1. Kim" << endl;
		SetConsoleTextAttribute(ConsoleColor, 10);
		cout << "2. Moc" << endl;
		SetConsoleTextAttribute(ConsoleColor, 11);
		cout << "3. Thuy" << endl;
		SetConsoleTextAttribute(ConsoleColor, 12);
		cout << "4. Hoa" << endl;
		SetConsoleTextAttribute(ConsoleColor, 6);
		cout << "5. Tho" << endl;
		SetConsoleTextAttribute(ConsoleColor, 15);
		cout << "Nhap 1 so 1~5: ";
		cin >> Loai;

		cout << "=====================================" << endl;
	} while (Loai < 1);

	switch (Loai)
	{
	case 1:
		mpHe = new Kim;
		HeName = "Kim";
		break;
	case 2:
		mpHe = new Moc;
		HeName = "Moc";
		break;
	case 3:
		mpHe = new Thuy;
		HeName = "Thuy";
		break;
	case 4:
		mpHe = new Hoa;
		HeName = "Hoa";
		break;
	case 5:
		mpHe = new Tho;
		HeName = "Tho";
		break;
	default:
		break;
	}
}

void DauLinh::Output()
{
	HANDLE ConsoleColor;
	ConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	int a = this->GetHe()->PhanLoai();
	switch (a)
	{
	case 1:
	{
		SetConsoleTextAttribute(ConsoleColor, 8);
		break;
	}
	case 2:
	{
		SetConsoleTextAttribute(ConsoleColor, 10);
		break;
	}
	case 3:
	{
		SetConsoleTextAttribute(ConsoleColor, 11);
		break;
	}
	case 4:
	{
		SetConsoleTextAttribute(ConsoleColor, 12);
		break;
	}
	case 5:
	{
		SetConsoleTextAttribute(ConsoleColor, 6);
		break;
	}
	default: break;
	}
	cout << "Ten: " << this->Ten << endl;
	cout << "Cap: " << this->iCapDo << endl;
	cout << "He: " << this->HeName << endl;
	cout << "Muc sat thuong: " << this->MucSatThuong() << endl;
	SetConsoleTextAttribute(ConsoleColor, 15);
	cout << endl;
}

float DauLinh::MucSatThuong()
{
	return iCapDo * 7;
}

float DauLinh::SatThuong(PhanTu* p)
{
	float fMST = MucSatThuong();
	return fMST + fMST * mpHe->TLSatThuong(p->GetHe()) / 100;
}