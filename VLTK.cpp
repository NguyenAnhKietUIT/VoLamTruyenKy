#include <iostream>
#include "He.h"
#include "PhanTu.h"
#include <conio.h>
#include <iomanip>
using namespace std;

void Input(PhanTu* [], int&); //Nhập các phần tử
void ThaoTac(PhanTu* [], int); //Danh sách các thao tác cần thực hiện
void MaxSatThuong(PhanTu* [], int); //Tìm các phần tử có sát thương cao nhất
void SatThuong(PhanTu* [], int); //So sánh mức sát thương của 2 phần tử 
bool Check(PhanTu* [], int); //Kiểm tra tên có bị trùng với các phần tử trước hay không

int main()
{
	PhanTu* arr[100]{};
	int n = 0;
	cout << "Nhap danh sach cac phan tu" << endl;
	Input(arr, n);
	system("cls"); //Hàm xóa màn hình
	ThaoTac(arr, n);
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
			arr[i] = new NhanVat; //Khởi tạo phần tử loại Nhân Vật
			break;
		case 2:
			arr[i] = new ThongThuong; //Khởi tạo phần tử loại Quái Thông Thường
			break;
		case 3:
			arr[i] = new DauLinh; //Khởi tạo phần tử loại Quái Đầu Lĩnh
		}
		do
		{
			arr[i]->Input();
		} while (!Check(arr,i));
	}
}

void ThaoTac(PhanTu* arr[], int n)
{
	int iLuaChon = 0; 
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
			cout << setw(60) << "DANH SACH CAC PHAN TU";
			cout << endl;
			cout << setfill('-');
			cout << setw(100) << "-" << endl;
			cout << setfill(' ');
			cout << "|" << setw(6) << left << "STT";
			cout << "|" << setw(20) << left << "Loai";
			cout << "|" << setw(24) << left << "Ten";
			cout << "|" << setw(6) << left << "He";
			cout << "|" << setw(16) << left << "Mon phai";
			cout << "|" << setw(10) << left << "Level";
			cout << "|" << setw(10) << left << "Sat thuong" << "|";
			cout << endl;
			cout << setfill('-');
			cout << setw(100) << "-" << endl;
			cout << setfill(' ');
			for (int i = 0; i < n; i++) 
			{
				cout << "|" << setw(6) << left << i + 1;
				arr[i]->Output();
				cout << endl;
				cout << setfill('-');
				cout << setw(100) << "-" << endl;
				cout << setfill(' ');
			} //In danh sách các phần tử
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
	} while (iLuaChon != 0);
}

void MaxSatThuong(PhanTu* arr[], int n)
{
	float max = arr[0]->MucSatThuong(); //Gán Max là mức sát thương của phần tử đầu tiên

	for (int i = 0; i < n; i++) 
		if (max < arr[i]->MucSatThuong()) 
			max = arr[i]->MucSatThuong(); //Cập nhật lại giá trị Max khi tồn tại phần tử có mức sát thương lớn hơn Max

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
		} //Xuất các phần tử có mức sát thương Max
}

void SatThuong(PhanTu* arr[], int n)
{
	int iA = 0, iB = 0; 
	cout << endl;
	cout << "Nhap vi tri 2 phan tu muon so sanh: " << endl; //Nhập hai giá trị ứng với vị trí trong mảng 
	do
	{
		cout << "Nhap vi tri phan tu 1: ";
		cin >> iA;
		cout << "Nhap vi tri phan tu 2: "; 
		cin >> iB;
		if (iA < 0 || iA >= n || iB < 0 || iB >= n)																	
			cout << "Nhap vi tri sai! Xin vui long nhap lai!" << endl;
	} while (iA < 0 || iA >= n || iB < 0 || iB >= n); //Vị trí của hai phần tử không hợp lệ

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
		if (arr[j]->getTen() == arr[i]->getTen()) //Tên của phần tử trùng với tên của phần tử trước đó
		{
			cout << "Ten bi trung! Xin thu ten khac!" << endl;
			return false; //Tên bị trùng
		}
	}
	return true; //Tên hợp lệ
}
