#include <iostream>
#include "He.h"
#include "PhanTu.h"
#include <conio.h>
using namespace std;

void Input(PhanTu* [], int&);
void MaxSatThuong(PhanTu* [], int);
void SatThuong(PhanTu* [], int);

int main()
{
	PhanTu* arr[100]{};
	int n = 0;
	int iLuaChon = 0;

	do
	{
		system("cls");
		cout << "Danh sach thao tac: " << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "1. Nhap danh sach cac phan tu" << endl;
		cout << "2. In danh sach cac phan tu" << endl;
		cout << "3. Tim phan tu co sat thuong lon nhat" << endl;
		cout << "4. So sanh sat thuong cua 2 phan tu" << endl;
		cout << "Nhap thao tac muon thuc hien: ";
		cin >> iLuaChon;

		switch (iLuaChon)
		{
			case 1:
			{
				Input(arr, n);
				break;
			}
			case 2:
			{
				Input(arr, n);
				for (int i = 0; i < n; i++)
					arr[i]->Output();
				break;
			}
			case 3:
			{
				Input(arr, n);
				MaxSatThuong(arr, n);
				break;
			}
			case 4:
			{
				Input(arr, n);
				SatThuong(arr, n);
				break;
			}
			default:
				break;
		}
	} while (iLuaChon < 0 || iLuaChon > 4);

	return 0;
}

void Input(PhanTu* arr[], int& n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;

	int iLoai;
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
		arr[i]->Input();
	}
}

void MaxSatThuong(PhanTu* arr[], int n)
{
	float max = arr[0]->MucSatThuong();

	for (int i = 0; i < n; i++)
		if (max < arr[i]->MucSatThuong())
			max = arr[i]->MucSatThuong();

	cout << "\nNhung phan tu co muc sat thuong cao nhat: " << endl;
	for (int i = 0; i < n; i++)
		if (max == arr[i]->MucSatThuong())
			arr[i]->Output();
}

void SatThuong(PhanTu* arr[], int n)
{
	int iA, iB;
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

	cout << "Gia tri sat thuong phan tu 1 len phan tu 2: ";
	cout << arr[iA]->SatThuong(arr[iB]) << endl;
	cout << "Gia tri sat thuong phan tu 2 len phan tu 1: ";
	cout << arr[iB]->SatThuong(arr[iA]) << endl;
}