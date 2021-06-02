#include "PhanTu.h"
#include <iostream>
#include <string>
#include <iomanip>
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
	cout.width(18);
	cout << left << "Nguoi choi";
	cout << "|";
	cout.width(35);
	cout << left << this->Ten;
	cout << "|";
	cout.width(7);
	cout << left << this->HeName;
	cout << "|";
	cout.width(17);
	cout << left << this->mpMonPhai;
	cout << "|";
	cout.width(12);
	cout << left << this->iCapDo;
	cout << "|";
	cout.width(12);
	cout << left << this->MucSatThuong();
	cout << "|";
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
	cout.width(18);
	cout << left << "Quai thong thuong";
	cout << "|";
	cout.width(35);
	cout << left << this->Ten;
	cout << "|";
	cout.width(7);
	cout << left << this->HeName;
	cout << "|";
	cout.width(17);
	cout << "                 |";
	cout.width(12);
	cout << left << this->iCapDo;
	cout << "|";
	cout.width(12);
	cout << left << this->MucSatThuong();
	cout << "|";
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
	cout.width(18);
	cout << left << "Quai dau linh";
	cout << "|";
	cout.width(35);
	cout << left << this->Ten;
	cout << "|";
	cout.width(7);
	cout << left << this->HeName;
	cout << "|";
	cout.width(17);
	cout << "                 |";
	cout.width(12);
	cout << left << this->iCapDo;
	cout << "|";
	cout.width(12);
	cout << left << this->MucSatThuong();
	cout << "|";
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