#pragma once
#include "He.h"
#include <string>
using namespace std;

class DoiTuong
{
protected:
	string Ten;
	int iCapDo;
	He* mpHe;
	string HeName;
public:
	virtual void Input();
	virtual void Output();
	virtual float SatThuong(DoiTuong*) = 0;
	virtual float MucSatThuong() = 0;
	void SetHe(int);
	He* GetHe();
};

class NhanVat : public DoiTuong
{
public:
	int MonPhai;
	string mpMonPhai;
	void Input();
	void Output();
	float MucSatThuong();
	float SatThuong(DoiTuong*);
};

class ThongThuong :public DoiTuong
{
public:
	void Input();
	void Output();
	float MucSatThuong();
	float SatThuong(DoiTuong*);
};

class DauLinh :public DoiTuong
{
public:
	void Input();
	void Output();
	float MucSatThuong();
	float SatThuong(DoiTuong*);
};