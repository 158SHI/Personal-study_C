#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

class Box
{
private:
	double length;
	
public:
	double height;
	double width;

public:
	Box(void)
	{
		length = 0.0;
		height = 0.0;
		width = 0.0;
	}
	friend class BigBox;//友元类
	friend void PutLength(Box box);//友元函数
	void GetLength(double len);
	void GetHeight(double hei);
	void GetWidth(double wid);
};

class BigBox
{
public:
	void PrintLength(double len, Box& box);
};

void BigBox::PrintLength(double len, Box& box)
{
	box.GetLength(len);
	cout << "the length of box from BigBox: " << box.length << endl;
}

void PutLength(Box box)//友元函数不是任何类的成员,这种情况下友元函数的参数是类的对象
{
	//友元函数可以直接访问类的private成员和protected成员
	cout << "the length of box: " << box.length << endl;
}

void Box::GetLength(double len)
{
	length = len;
}

void Box::GetHeight(double hei)
{
	height = hei;
}

void Box::GetWidth(double wid)
{
	width = wid;
}


int main()
{
	Box box;
	box.GetHeight(1.1);
	box.GetWidth(2.1);
	box.GetLength(3.1);
	PutLength(box);//通过友元函数访问

	BigBox bigBox;
	bigBox.PrintLength(4.1, box);//通过友元类的成员函数访问
	return 0;
}