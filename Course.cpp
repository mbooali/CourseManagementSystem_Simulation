// ourse.cpp: implementation of the Course class.
//
//////////////////////////////////////////////////////////////////////

#include "Course.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

string Course::GiveName() 
{
	return name;
}

Course::Course ()		//class Constructor for Course
{
	zarfiat = vahed = term = status = mark = 0;
}

void Course::SetVars( int v, int z, string n )
{
	vahed = v;
	zarfiat = z;
	name = n;
}

Course* Course::Next()
{
	return next;
}


void Course::SetNext( Course *next2 )
{
	next = next2;
}

void Course::Show()
{
	cout << name << endl << vahed<< endl << zarfiat << endl;
}

