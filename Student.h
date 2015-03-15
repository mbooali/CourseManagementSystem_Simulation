#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef class Course Course;
typedef class Student Student;
typedef class Term Term;
// Student.h: interface for the Student class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENT_H__4E5F2360_FA61_4C57_BEAE_5745C7F1F42F__INCLUDED_)
#define AFX_STUDENT_H__4E5F2360_FA61_4C57_BEAE_5745C7F1F42F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef Term Term;
class Student  
{
	int term,passed,given,EDU;
	string name,family,ID;
	Student *next;
	Course *head;
	Term *thead;
public:
	Student();
	void Enter(string newname, string newfamily, string newID);
	Student* Next();
	void SetNext( Student *next2 );
	string GiveID(){return ID;}
	void Termplus();
	Course* course(){return head;}
	void SetCourse(Course* X){head = X;}
	Term* termout(){return thead;}
	int termnum(){return term;}
	void SetTerm(Term* T){thead = T;}
	void Pass(int vahed){passed+=vahed;}
	int Passed(){return passed;}
	int Given(){return given;}
	void Givenplus(int vahed){given+=vahed;}
	void Set_Edu(){EDU=1;}
	int Edu(){return passed;}
	void THEAD(Term* thead2){thead=thead2;}
};

#endif // !defined(AFX_STUDENT_H__4E5F2360_FA61_4C57_BEAE_5745C7F1F42F__INCLUDED_)
