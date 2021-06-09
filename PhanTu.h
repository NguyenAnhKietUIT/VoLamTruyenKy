#pragma once
#include "He.h"
#include <string>
using namespace std;

class PhanTu
{
protected:
	string Ten;
	int CapDo;
	He* TenHe;
	string HeName;
public:
	PhanTu();
	string getTen();
	virtual void Input(); //Nhập thông tin của phần tử
	virtual void Output(); //Xuất thông tin của phần tử
	virtual float SatThuong(PhanTu*) = 0;
	virtual float MucSatThuong() = 0; //Hàm tính mức sát thương của phần tử
	void SetHe(int);
	He* GetHe();
	virtual ~PhanTu();
};

class NhanVat : public PhanTu
{
private:
	int MonPhai;
	string TenMonPhai;
public:
	NhanVat();
	void Input();
	void Output();
	float MucSatThuong();
	float SatThuong(PhanTu*);
	~NhanVat();
};

class ThongThuong :public PhanTu
{
public:
	ThongThuong();
	void Input();
	void Output();
	float MucSatThuong();
	float SatThuong(PhanTu*);
	~ThongThuong();
};

class DauLinh :public PhanTu
{
public:
	DauLinh();
	void Input();
	void Output();
	float MucSatThuong();
	float SatThuong(PhanTu*);
	~DauLinh();
};