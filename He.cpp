#include "He.h"

int He::TLSatThuong(He*)
{
	return 0;
}

int He::PhanLoai()
{
	return 0;
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