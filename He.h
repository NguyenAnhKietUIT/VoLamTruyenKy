#pragma once
class He
{
public:
	He();
	virtual int TLSatThuong(He*) = 0; // Hàm nhận tham số là 1 trong 5 hệ: Kim, Mộc, Thủy, Hỏa, Thổ
	virtual int PhanLoai() = 0; // Phân loại hệ bằng các hằng số: Kim = 1, Mộc = 2, Thủy = 3, Hỏa = 4, Thổ = 5
	virtual ~He();
};

class Kim : public He
{
public:
	Kim();
	int PhanLoai();
	int TLSatThuong(He*);
	~Kim();
};

class Moc : public He
{
public:
	Moc();
	int PhanLoai();
	int TLSatThuong(He*);
	~Moc();
};

class Thuy : public He
{
public:
	Thuy();
	int PhanLoai();
	int TLSatThuong(He*);
	~Thuy();
};

class Hoa :public He
{
public:
	Hoa();
	int PhanLoai();
	int TLSatThuong(He*);
	~Hoa();
};

class Tho :public He
{
public:
	Tho();
	int PhanLoai();
	int TLSatThuong(He*);
	~Tho();
};