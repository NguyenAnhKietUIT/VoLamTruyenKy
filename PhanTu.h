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
	PhanTu();
	virtual void Input();
	virtual void Output();
	virtual float SatThuong(PhanTu*) = 0;
	virtual float MucSatThuong() = 0;
	void SetHe(int);
	He* GetHe();
	virtual ~PhanTu();
};

class NhanVat : public PhanTu
{
public:
	NhanVat();
	int MonPhai;
	string mpMonPhai;
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