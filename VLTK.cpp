#include <iostream>
#include "He.h"
#include "PhanTu.h"
#include <conio.h>
#include <iomanip>
using namespace std;

void Input(PhanTu* [], int&);
void MaxSatThuong(PhanTu* [], int);
void SatThuong(PhanTu* [], int);
bool Check(PhanTu* [], int);

int main()
{
	PhanTu* arr[100]{};
	int n = 0;
	int iLuaChon = 0;
	cout << "Nhap danh sach cac phan tu" << endl;
	Input(arr, n);
	system("cls");
	do
	{
		cout << "Danh sach thao tac: " << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "1. In danh sach cac phan tu" << endl;
		cout << "2. Tim phan tu co sat thuong lon nhat" << endl;
		cout << "3. So sanh sat thuong cua 2 phan tu" << endl;
		cout << "Nhap thao tac muon thuc hien: ";
		cin >> iLuaChon;

		switch (iLuaChon)
		{
			case 0: break;
			case 1:
			{
				cout << endl;
				cout << setfill('-');
				cout << setw(101) << "-" << endl;
				cout << setfill(' ');
				cout << "|" << setw(7) << left << "STT";
				cout << "|" << setw(20) << left << "Loai";
				cout << "|" << setw(24) << left << "Ten";
				cout << "|" << setw(6) << left << "He";
				cout << "|" << setw(16) << left << "Mon phai";
				cout << "|" << setw(10) << left << "Level";
				cout << "|" << setw(10) << left << "Sat thuong" << "|";
				cout << endl;
				cout << setfill('-');
				cout << setw(101) << "-" << endl;
				cout << setfill(' ');
				for (int i = 0; i < n; i++)
				{
					cout << "|" << setw(7) << left << i + 1;
					arr[i]->Output();
					cout << endl;
					cout << setfill('-');
					cout << setw(101) << "-" << endl;
					cout << setfill(' ');
				}
				cout << endl;
				break;
			}
			case 2:
			{
				MaxSatThuong(arr, n);
				cout << endl;
				break;
			}
			case 3:
			{
				SatThuong(arr, n);
				cout << endl;
				break;
			}
			default:
				break;
		}
	} while (iLuaChon !=0);

	return 0;
}

void Input(PhanTu* arr[], int& n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;

	int iLoai = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap loai: " << endl;
		do
		{
			cout << "1. Nhan vat" << endl;
			cout << "2. Quai thuong" << endl;
			cout << "3. Quai dau linh" << endl;
			cout << "Chon 1 so tu 1~3: ";
			cin >> iLoai;
		} while (iLoai < 1);

		switch (iLoai)
		{
		case 1:
			arr[i] = new NhanVat;
			break;
		case 2:
			arr[i] = new ThongThuong;
			break;
		case 3:
			arr[i] = new DauLinh;
		}
		do
		{
			arr[i]->Input();
		} while (!Check(arr,i));
	}
}

void MaxSatThuong(PhanTu* arr[], int n)
{
	float max = arr[0]->MucSatThuong();

	for (int i = 0; i < n; i++)
		if (max < arr[i]->MucSatThuong())
			max = arr[i]->MucSatThuong();

	cout << "\nNhung phan tu co muc sat thuong cao nhat: " << endl;
	cout << setfill('-');
	cout << setw(93) << "-" << endl;
	cout << setfill(' ');
	cout << "|" << setw(20) << left << "Loai";
	cout << "|" << setw(24) << left << "Ten";
	cout << "|" << setw(6) << left << "He";
	cout << "|" << setw(16) << left << "Mon phai";
	cout << "|" << setw(10) << left << "Level";
	cout << "|" << setw(10) << left << "Sat thuong" << "|";
	cout << endl;
	cout << setfill('-');
	cout << setw(93) << "-" << endl;
	cout << setfill(' ');
	for (int i = 0; i < n; i++)
		if (max == arr[i]->MucSatThuong())
		{
			arr[i]->Output();
			cout << endl;
			cout << setfill('-');
			cout << setw(93) << "-" << endl;
			cout << setfill(' ');
		}
}

void SatThuong(PhanTu* arr[], int n)
{
	int iA, iB;
	cout << endl;
	cout << "Nhap vi tri 2 phan tu muon so sanh: " << endl;
	do
	{
		cout << "Nhap vi tri phan tu 1: ";
		cin >> iA;
		cout << "Nhap vi tri phan tu 2: ";
		cin >> iB;
		if (iA < 0 || iA >= n || iB < 0 || iB >= n)
			cout << "Nhap vi tri sai! Xin vui long nhap lai!" << endl;
	} while (iA < 0 || iA >= n || iB < 0 || iB >= n);

	cout << endl;
	cout << "Gia tri sat thuong phan tu 1 len phan tu 2: ";
	cout << arr[iA]->SatThuong(arr[iB]) << endl;
	cout << "Gia tri sat thuong phan tu 2 len phan tu 1: ";
	cout << arr[iB]->SatThuong(arr[iA]) << endl;
}

bool Check(PhanTu* arr[], int i)
{
	for (int j = 0; j < i; j++)
	{
		if (arr[j]->getTen() == arr[i]->getTen())
		{
			cout << "Ten bi trung! Xin thu ten khac!" << endl;
			return false;
		}
	}
	return true;
}
