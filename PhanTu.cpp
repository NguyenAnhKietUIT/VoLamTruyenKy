#include "PhanTu.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

PhanTu::PhanTu()
{
	iCapDo = 1;
}

string PhanTu::getTen()
{
	return this->Ten;
}

void PhanTu::Input()
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
	} while (Loai < 1 || Loai > 5);

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

PhanTu::~PhanTu()
{
}

NhanVat::NhanVat()
{
}

void NhanVat::Input()
{
	PhanTu::Input();

	HANDLE ConsoleColor;
	ConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if (HeName == "Kim")
	{
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
	}
	else if (HeName == "Moc")
	{
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
	}
	else if (HeName == "Thuy")
	{
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
	}
	else if (HeName == "Hoa")
	{
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
	}
	else
	{
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
	}
	SetConsoleTextAttribute(ConsoleColor, 15);
	cout << "-----------------------------------------" << endl;
}

void NhanVat::Output()
{
	cout << "|" << setw(20) << left << "Nguoi choi";
	cout << "|" << setw(24) << left << this->Ten;
	cout << "|" << setw(6) << left << this->HeName;
	cout << "|" << setw(16) << left << this->mpMonPhai;
	cout << "|" << setw(10) << left << this->iCapDo;
	cout << "|" << setw(10) << left << this->MucSatThuong() << "|";
}

float NhanVat::MucSatThuong()
{
	return iCapDo * 5.0f;
}

float NhanVat::SatThuong(PhanTu* p)
{
	float fMST = MucSatThuong();
	return fMST + fMST * mpHe->TLSatThuong(p->GetHe()) / 100;
}

NhanVat::~NhanVat()
{
}

ThongThuong::ThongThuong()
{
}

void ThongThuong::Input()
{
	PhanTu::Input();
	cout << "-----------------------------------------" << endl;

}

void ThongThuong::Output()
{
	cout << "|" << setw(20) << left << "Quai thong thuong";
	cout << "|" << setw(24) << left << this->Ten;
	cout << "|" << setw(6) << left << this->HeName;
	cout << "|" << setw(16) << " ";
	cout << "|" << setw(10) << left << this->iCapDo;
	cout << "|" << setw(10) << left << this->MucSatThuong() << "|";
}

float ThongThuong::MucSatThuong()
{
	return iCapDo * 3.0f;
}

float ThongThuong::SatThuong(PhanTu* p)
{
	float fMST = MucSatThuong();
	return fMST + fMST * mpHe->TLSatThuong(p->GetHe()) / 100;
}

ThongThuong::~ThongThuong()
{
}

DauLinh::DauLinh()
{
}

void DauLinh::Input()
{
	PhanTu::Input();
	cout << "-----------------------------------------" << endl;

}

void DauLinh::Output()
{
	cout << "|" << setw(20) << left << "Quai dau linh";
	cout << "|" << setw(24) << left << this->Ten;
	cout << "|" << setw(6) << left << this->HeName;
	cout << "|" << setw(16) << " ";
	cout << "|" << setw(10) << left << this->iCapDo;
	cout << "|" << setw(10) << left << this->MucSatThuong() << "|";
}

float DauLinh::MucSatThuong()
{
	return iCapDo * 7.0f;
}

float DauLinh::SatThuong(PhanTu* p)
{
	float fMST = MucSatThuong();
	return fMST + fMST * mpHe->TLSatThuong(p->GetHe()) / 100;
}

DauLinh::~DauLinh()
{
}
