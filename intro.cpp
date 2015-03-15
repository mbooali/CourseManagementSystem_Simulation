#include <iostream>
#include <fstream>
#include <string>

#include "Course.h"
#include "Student.h"

using namespace std;
typedef class Course Course;
typedef class Student Student;
typedef class Term Term;





void Lopen(Course* a,int *topass)
{
	Course *now;
	string name;
	int	lesnum=0,vahed,zarfiat;
	fstream in;
	in.open("Lesson.txt",fstream::in | fstream::out | fstream::app);
	in >> *topass >>lesnum ;
	for(int i = 0; i < lesnum; i++)
	{
		now = new Course;
		in >> name >> vahed >> zarfiat;
		now->SetVars(vahed, zarfiat, name);
		now->SetNext(a->Next());
		a->SetNext(now);
	}
    in.close();
}

void Sopen(Student* s)			//open files and add the student
{
	Student *now;
	Course *nowC;
	string name,family,ID,lname;
	int	stnumber,lesnum=0,vahed,zarfiat,chert;
	fstream in,ins;

	in.open("Student.txt",fstream::in | fstream::out | fstream::app);
	in >> stnumber ;		//file opening
	for(int i = 0; i < stnumber; i++)
	{							//read student info and add it to link list of students
		now = new Student;
		in >> ID >> name >> family;
		now->Enter(name, family, ID);
		now->SetNext(s->Next());
		s->SetNext(now);

		ins.open("Lesson.txt",fstream::in | fstream::out);		// b uild the link list of courses for a student
		ins >> chert >>lesnum ;
		for(int j = 0; j < lesnum; j++)
		{
			nowC = new Course;
			ins >> lname >> vahed >> zarfiat;
			nowC->SetVars(vahed, zarfiat, lname);
			nowC->SetNext(now->course());
			now->SetCourse(nowC);
		}
	    ins.close();
		

	}
    in.close();
}


void ADD_Student(Student*a,string newname, string newfamily, string newID)		//add new student to linked list of stus
{
	Student* now;
	Course *nowC;
	string name,lname;
	int	lesnum=0,vahed,zarfiat,chert;
	fstream in;

	now = new Student;
	now->SetTerm(0);
	now->Enter(newname, newfamily, newID);
	now->SetNext(a->Next());
	a->SetNext(now);
	
	in.open("Lesson.txt",fstream::in | fstream::out);
	in >> chert >>lesnum ;
	for(int i = 0; i < lesnum; i++)
	{
		nowC = new Course;
		in >> lname >> vahed >> zarfiat;
		nowC->SetVars(vahed, zarfiat, lname);
		nowC->SetNext(now->course());
		now->SetCourse(nowC);
	}
    in.close();
}

void scan_Course(Course* a)			// every things is clear
{
	Course* now;
	if(a->Next() == NULL)
	{
		return;
	}
	else
	{
		now = a->Next();
		now->Show();
		while (now->Next() != NULL)
		{
			now = 	now->Next();
			now->Show();
		}// ALL things is vaZEh
	}
}



Course* Find_Course(Course* a, string name)
{
	Course* now;
	if(a->Next() == NULL)
	{
		return NULL;
	}
	else
	{
		now = a->Next();
		if( now->GiveName().compare(name) == 0 )
			return now;
		while (now->Next() != NULL)
		{
			now = 	now->Next();
			if( now->GiveName().compare(name) == 0 )
				return now;
		}
	}
	return NULL;
}



Student* Find_Student(Student* a, string ID)		// khodaeesh moshakhhase
{
	Student* now;
	if(a->Next() == NULL)
	{
		return NULL;
	}
	else
	{
		now = a->Next();
		if( now->GiveID().compare(ID) == 0 )
			return now;
		while (now->Next() != NULL)
		{
			now = 	now->Next();
			if( now->GiveID().compare(ID) == 0 )
				return now;
		}
	}
	return NULL;
}

void New_Student(Course* c, Student* a)			// functioni ke modiriate function haye new student ra dar main bar ohde darad
{
	string name, family, ID;
	cout << "Enter the newStudent STnumber: \t";
	cin >> ID ;
	cout << "Name :  \t";
	cin >> name;
	cout << "FamiLy  \t";
	cin >> family;

	ADD_Student(a,name,family,ID);
	cout << "New student add to list successfuly";
}

void Intro()			// help e barname
{
	cout << "instruction:\n\n";
	cout << "\t1. new term:   start\n";
	cout << "\t2. new student:  NewStudent\n";
	cout << "\t3. End term:   END\n";
	cout << "\t3. Quit anyway:   Quit\n";
}


void TermPlus(Student* a)		// ezafe konnandeye term 
{
	Student* now;
	if(a->Next() == NULL)
	{
		return;
	}
	else
	{
		now = a->Next();
		now->Termplus();
		while (now->Next() != NULL)
		{	
			now = now->Next();
			now->Termplus();	
		}
	}	
}



void ADD_Course(Student *s, Course* C, string name)
{
					// b e daneshjoo course add mikonad
	Course* now;

	if(C == NULL)
	{
		cout << "\nno term is ready for this Student\n" ;
		return;			// student 
	}
	else
	{
		now = C;
		if( now->GiveName()==name && now->Status()==0 && s->Given()+now->Vahed()<=17  )
		{
			now->SetStatus(1);
			now->SetTerm(s->termnum());
			s->Givenplus(now->Vahed());
		}
		else if (now->GiveName()==name && (now->Status()!=0) )
		{
			cout << "\nU cant pick this Course again\n\n";
			return;
		}

		while ( now->Next() != NULL)
		{	
			now = now->Next();
			if( now->GiveName()==name && now->Status()==0 )
			{	
				now->SetStatus(1);
			}
			else if (now->GiveName()==name && (now->Status()!=0) )
			{
				cout << "\nU cant pick this Course again\n\n";
				return;
			}
		}
	}
}

void ADD(Course* c, Student* s,string str)
{
	Student* found;
	Course* cfound;
	string Temp_ID,Temp_Course;
	cout << "\nPLease enter an ID to  Add Course (enter ID and Press Enter):   ";
	Temp_ID = str;
	found = Find_Student(s,Temp_ID);
	while(found == NULL)
	{
		cout << "\n the student not found\n\n please re ENTER the Student Number:   ";
		cin >> Temp_ID;
		found = Find_Student(s,Temp_ID);
	}
	cout << "\n\n And now type the Course name And Press ENTER (to finish the Course giving 'shoot' and then press EnteR)     ";
	
	while ( Temp_Course != "*" )
	{
		cin >> Temp_Course;
		cfound = Find_Course(c,Temp_Course);
		while(found == NULL)
		{
			cout << "\n the Course not found\n\n please re ENTER the Course name:   ";
			cin >> Temp_Course;
			cfound = Find_Course(c,Temp_ID);
		}
		ADD_Course(found,found->course(),Temp_Course);
	}
}



void MarkSetter(Student* s)			//set marks
{
	Student* now;
	Course* nowC;
	if(s->Next() == NULL)
	{
		return ;
	}
	else
	{
		now = s->Next();

		nowC = now->course();
		while(nowC != NULL)
		{	
			if(nowC->Status() == 1)
				nowC->SetMark(rand()%21);
			nowC = nowC->Next();
		}

//inja kari ke bayad ro anjam bedim

		while (now->Next() != NULL)
		{
			now = 	now->Next();
			
			nowC = now->course();
			while(nowC != NULL)
			{	
				if(nowC->Status() == 1)
					nowC->SetMark(rand()%21);
				nowC = nowC->Next();
			}
			
		}
	}
}

