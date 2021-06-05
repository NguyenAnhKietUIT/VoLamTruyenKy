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
	return 0; //Kim = 1, Mộc = 2, Thủy = 3, Hỏa = 4, Thổ = 5
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
		return 10; //Sát thương gây ra đối với hệ Thủy
	if (m->PhanLoai() == 2)
		return 20; //Sát thương gây ra đối với hệ Mộc
	if (m->PhanLoai() == 4)
		return -20; //Sát thương phải nhận khi gặp hệ Hỏa
	return 0; //Sát thương khi gặp đối tượng cùng Hệ
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
		return 10;  //Sát thương gây ra đối với hệ Hỏa
	if (m->PhanLoai() == 5)
		return 20;  //Sát thương gây ra đối với hệ Thổ
	if (m->PhanLoai() == 1)
		return -20; //Sát thương phải nhận khi gặp hệ Kim
	return 0; //Sát thương khi gặp đối tượng cùng Hệ
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
		return 10;  //Sát thương gây ra đối với hệ Mộc
	if (m->PhanLoai() == 4)
		return 20;  //Sát thương gây ra đối với hệ Hỏa
	if (m->PhanLoai() == 5)
		return -20; //Sát thương phải nhận khi gặp hệ Thổ
	return 0; //Sát thương khi gặp đối tượng cùng Hệ
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
		return 10;  //Sát thương gây ra đối với hệ Thổ
	if (m->PhanLoai() == 1)
		return 20;  //Sát thương gây ra đối với hệ Kim
	if (m->PhanLoai() == 3)
		return -20; //Sát thương phải nhận khi gặp hệ Thủy
	return 0; //Sát thương khi gặp đối tượng cùng Hệ
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
		return 10;  //Sát thương gây ra đối với hệ Kim
	if (m->PhanLoai() == 3)
		return 20;  //Sát thương gây ra đối với hệ Thủy
	if (m->PhanLoai() == 2)
		return -20; //Sát thương phải nhận khi gặp hệ Mộc
	return 0; //Sát thương khi gặp đối tượng cùng Hệ
}

Tho::~Tho()
{
}
