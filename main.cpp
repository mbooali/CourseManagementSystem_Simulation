#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#include "Course.h"
#include "Student.h"
#include "Term.h"

using namespace std;
typedef class Course Course;
typedef class Student Student;
typedef class Term Term;



void Lopen(Course* a,int *topass);
void Sopen(Student* s);
void ADD_Student(Student*a,string newname, string newfamily, string newID);
void scan_Course(Course* a);
Course* Find_Course(Course* a, string name);
Student* Find_Student(Student* a, string ID);
void New_Student(Course* c, Student* a);
void Intro();
void TermPlus(Student* a);
void Summery(Term *ST);
void ADD(Course* c, Student* s,string str);
void ADD_Course(Student *s, Course* C, string name);
void MarkSetter(Student* s);
void TermCreat(Student* s,int topass);

int main()
{
	srand(time(NULL));

	Course c;		/// dummy object for course
	Student s;		/// dummy object for students
	Student* found;
	int topass=0,flag=0;
	string Temp_ID;
	string str = "default";
	string Temp_Course;
	c.SetNext(NULL);
	s.SetNext(NULL);
	Lopen(&c,&topass);
	Sopen(&s);

	Intro();
	while(str != "Quit")
	{
		
		cout << "\n\ncommand line\t";
		cin >> str;
		if(str == "start")
		{
			flag = 0;		//flag 0 yani inke faghat mitune entekhab vahed kone
			TermPlus(&s);
		}
		else if(str == "END")
		{
			flag = 1;
			MarkSetter(&s);			// function names is clear
			TermCreat(&s,topass);


			// nomeraaat bayad elam shavad va moaddele term mohasebe shavad
			// inja bayad nomre ha dade shavad va pas az aan moaddele term gerefte shavad
			//yek node be term e haryek az daneshjooa ezafe mishe ke haavie shomareye term akhir be hamrahe moaddele an ast
			cout << "2";
		}
		else if(str == "NewStudent")
		{
			New_Student(&c,&s);
		}
		else if(str == "Quit")
		{
			cout << "\n Press any Key to Exit from this program\n";
		}
		else
		{
			
			if(flag == 0)
			{
				ADD(&c,&s,str);
					// entekhaab vahed ba sharayete maloom
			}
			else if(flag == 1)
			{
				cout << "\nPLease enter an ID to see Its summery on term AVerAgE:   ";
				Temp_ID = str;
				found = Find_Student(&s,Temp_ID);	//in hamun student e ke bayad summery sho bede
				cout << "\n" << Temp_ID << ":\n";
				while(found == NULL)
				{
					cout << "\n the student not found\n\n please re ENTER the Student Number:   ";
					cin >> Temp_ID;
					found = Find_Student(&s,Temp_ID);
				}
				Summery(found->termout());
				
				// moshaahede ye link liste daneshjooee ke shomare daneshjooee un ro user dade
			}
			else
			{
				cout << "\n\n\t U made the UT SyStem Uncle!!!!!!!!!!!" << endl;
			}
		}
	}
	
	return 0;
}


///ehtiat shavad dishab saat e 2 ino ezafe kardam
void Summery(Term *ST)
{
	Term* now;
	if(ST == NULL)
	{
		cout << "\nno term is ready for this Student\n" ;
		return;
	}
	else
	{
		now = ST;
		cout << "Term " << now->Tnum() << " : " << now->Avg() << "\n\n" ; 
		while ( now->Next() != NULL)
		{	
			now = now->Next();
			cout << "Term " << now->Tnum() << " : " << now->Avg() << "\n\n" ;
		}
	}	
}


void TermCreat(Student* s,int topass)
{
	Student* now;
	Course* nowC;
	Term* nowT;
	float avg,sum=0;
	int counter=0;
	fstream in;
	in.open("Karname.txt",fstream::out | fstream::app);

	if(s->Next() == NULL)
	{
		return ;
	}
	else
	{
		now = s->Next();
		in << now->GiveID() << ":" << endl;
		nowC = now->course();

		counter = 0;
			while(nowC != NULL)				//scan all the lesson for a student 
			{
				if(nowC->Status() == 1)
				{
					in << nowC->GiveName() << ":" << nowC->Mark() << endl;
					if(nowC->Mark() >= 10)
						nowC->SetStatus(2);
					else
						nowC->SetStatus(0);

					sum += nowC->Mark();
					counter++;
				}
				avg = sum/counter;

					nowC = nowC->Next();
			}
				nowT = new Term;
				nowT->SetVar(now->termnum(),avg);
				nowT->SetNext(now->termout());
				now->THEAD(nowT);
			in << "Average:  " << avg << endl;
			if( avg>=0 && avg<12)
				in << "Mashroot!" << endl;
			if(topass - now->Passed() == 0)
				in << endl << "EDUCATED!!!" << endl;
//inja kari ke bayad ro anjam bedim midim

		while (now->Next() != NULL)			///scan student list
		{
			now = now->Next();
			in << now->GiveID() << ":" << endl;
			nowC = now->course();
			counter = 0;
			while(nowC != NULL)
			{
				if(nowC->Status() == 1)
				{
					in << nowC->GiveName() << ":" << nowC->Mark() << endl;
					if(nowC->Mark() >= 10)
						nowC->SetStatus(2);
					else
						nowC->SetStatus(2);

					sum += nowC->Mark();
					counter++;
				}
				avg = sum/counter;
		
				nowC = nowC->Next();
			}
				nowT = new Term;		//term ro ba moaddelesh be link liste termhaye daneshjoo ezafe mikone
				nowT->SetVar(now->termnum(),avg);
				nowT->SetNext(now->termout());
				now->THEAD(nowT);
			in << "Average:  " << avg << endl;
			if( avg>=0 && avg<12)
				in << "Mashroot!" << endl;
			if(topass - now->Passed() == 0)
				in << endl << "EDUCATED!!!" << endl;
			
		}
	}
	in.close();
}

