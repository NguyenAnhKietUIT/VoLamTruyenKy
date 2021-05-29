#pragma once
class He
{
public:
	virtual int TLSatThuong(He*) = 0;
	virtual int PhanLoai() = 0;
};

class Kim : public He
{
public:
	int PhanLoai();
	int TLSatThuong(He*);
};

class Moc : public He
{
public:
	int PhanLoai();
	int TLSatThuong(He*);
};

class Thuy : public He
{
public:
	int PhanLoai();
	int TLSatThuong(He*);
};

class Hoa :public He
{
public:
	int PhanLoai();
	int TLSatThuong(He*);
};

class Tho :public He
{
	int PhanLoai();
	int TLSatThuong(He*);
};