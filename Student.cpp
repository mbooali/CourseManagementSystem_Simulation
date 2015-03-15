// Student.cpp: implementation of the Student class.
//
//////////////////////////////////////////////////////////////////////

#include "Student.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


Student::Student()
{	
	EDU=0;
	passed = 0;
	term = 0;
	name = family = "Unknown";
	ID = "810000000";
	head = NULL;
	thead = NULL;
	given = 0;

}
Student* Student::Next()
{
	return next;
}


void Student::SetNext(Student *next2 )
{
	next = next2;
}


void Student::Enter(string newname, string newfamily, string newID)
{
	name = newname;
	family = newfamily;
	ID = newID;
}

void Student::Termplus()
{
	term = term + 1;
}

