#include <iostream>
#include "He.h"
#include "DoiTuong.h"
using namespace std;

void Input(DoiTuong* [], int&);
void MaxSatThuong(DoiTuong* [], int);
void SatThuong(DoiTuong* [], int);

int main()
{
	DoiTuong* arr[100]{};
	int n = 0;
	Input(arr, n);
	MaxSatThuong(arr, n);
	SatThuong(arr, n);
	return 0;
}

void Input(DoiTuong* arr[], int& n)
{
	cout << "Nhap so luong doi tuong: ";
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

void MaxSatThuong(DoiTuong* arr[], int n)
{
	float max = arr[0]->MucSatThuong();

	for (int i = 0; i < n; i++)
		if (max < arr[i]->MucSatThuong())
			max = arr[i]->MucSatThuong();

	cout << "\nNhung doi tuong co muc sat thuong cao nhat: " << endl;
	for (int i = 0; i < n; i++)
		if (max == arr[i]->MucSatThuong())
			arr[i]->Output();
}

void SatThuong(DoiTuong* arr[], int n)
{
	int iA, iB;
	cout << "Nhap vi tri 2 doi tuong muon so sanh: " << endl;
	do
	{
		cout << "Nhap vi tri doi tuong 1: ";
		cin >> iA;
		cout << "Nhap vi tri doi tuong 2: ";
		cin >> iB;
		if (iA < 0 || iA >= n || iB < 0 || iB >= n)
			cout << "Nhap vi tri sai! Xin vui long nhap lai!" << endl;
	} while (iA < 0 || iA >= n || iB < 0 || iB >= n);

	cout << "Gia tri sat thuong doi tuong 1 len doi tuong 2: ";
	cout << arr[iA]->SatThuong(arr[iB]) << endl;
	cout << "Gia tri sat thuong doi tuong 2 len doi tuong 1: ";
	cout << arr[iB]->SatThuong(arr[iA]) << endl;
}