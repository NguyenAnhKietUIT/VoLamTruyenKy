#include "He.h"

He::He()
{
}

int He::TLSatThuong(He*)
{
	return 0;
}

int He::PhanLoai()
{
	return 0;
}

He::~He()
{
}

Kim::Kim()
{
}

int Kim::PhanLoai()
{
	return 1;
}

int Kim::TLSatThuong(He* m)
{
	if (m->PhanLoai() == 3)
		return 10;
	if (m->PhanLoai() == 2)
		return 20;
	if (m->PhanLoai() == 4)
		return -20;
	return 0;
}

Kim::~Kim()
{
}

Moc::Moc()
{
}

int Moc::PhanLoai()
{
	return 2;
}

int Moc::TLSatThuong(He* m)
{
	if (m->PhanLoai() == 4)
		return 10;
	if (m->PhanLoai() == 5)
		return 20;
	if (m->PhanLoai() == 1)
		return -20;
	return 0;
}

Moc::~Moc()
{
}

Thuy::Thuy()
{
}

int Thuy::PhanLoai()
{
	return 3;
}

int Thuy::TLSatThuong(He* m)
{
	if (m->PhanLoai() == 2)
		return 10;
	if (m->PhanLoai() == 4)
		return 20;
	if (m->PhanLoai() == 5)
		return -20;
	return 0;
}

Thuy::~Thuy()
{
}

Hoa::Hoa()
{
}

int Hoa::PhanLoai()
{
	return 4;
}

int Hoa::TLSatThuong(He* m)
{
	if (m->PhanLoai() == 5)
		return 10;
	if (m->PhanLoai() == 1)
		return 20;
	if (m->PhanLoai() == 3)
		return -20;
	return 0;
}

Hoa::~Hoa()
{
}

Tho::Tho()
{
}

int Tho::PhanLoai()
{
	return 5;
}

int Tho::TLSatThuong(He* m)
{
	if (m->PhanLoai() == 1)
		return 10;
	if (m->PhanLoai() == 3)
		return 20;
	if (m->PhanLoai() == 2)
		return -20;
	return 0;
}

Tho::~Tho()
{
}
