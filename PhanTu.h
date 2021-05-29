#pragma once
#include "He.h"
#include <string>
using namespace std;

class PhanTu
{
protected:
	string Ten;
	int iCapDo;
	He* mpHe;
	string HeName;
public:
	virtual void Input();
	virtual void Output();
	virtual float SatThuong(PhanTu*) = 0;
	virtual float MucSatThuong() = 0;
	void SetHe(int);
	He* GetHe();
};

class NhanVat : public PhanTu
{
public:
	int MonPhai;
	string mpMonPhai;
	void Input();
	void Output();
	float MucSatThuong();
	float SatThuong(PhanTu*);
};

class ThongThuong :public PhanTu
{
public:
	void Input();
	void Output();
	float MucSatThuong();
	float SatThuong(PhanTu*);
};

class DauLinh :public PhanTu
{
public:
	void Input();
	void Output();
	float MucSatThuong();
	float SatThuong(PhanTu*);
};