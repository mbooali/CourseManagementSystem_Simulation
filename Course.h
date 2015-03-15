#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef class Course Course;
typedef class Student Student;
typedef class Term Term;
// ourse.h: interface for the Course class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OURSE_H__E670A739_B1C7_427C_9641_43C8437EC067__INCLUDED_)
#define AFX_OURSE_H__E670A739_B1C7_427C_9641_43C8437EC067__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class Course
{
	int vahed ,zarfiat, term,status,mark;		//status 0 not get 1 now & 2 passed
	string name;
	Course *next;
public:
	Course();
	void SetNext( Course *next2 );			//to set the next parameter of a node by address of next node
	Course* Next();							//Access the address of next nod in course list
	void SetVars( int v, int z, string n );		//set the values of a node in course list
	string GiveName();							//pass out the address of name string of a node in course list
	void Show();
	void SetStatus(int status2){status=status2;}
	int Status(){return status;}
	int Vahed(){return vahed;}
	void SetTerm(int term2){term=term2;}
	int termout(){return term;}
	int Mark(){return mark;}
	void SetMark(int mark2){mark=mark2;}
};

#endif // !defined(AFX_OURSE_H__E670A739_B1C7_427C_9641_43C8437EC067__INCLUDED_)
