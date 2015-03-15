// Term.h: interface for the Term class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TERM_H__B19CF676_F867_4C78_91CA_B47BC2450050__INCLUDED_)
#define AFX_TERM_H__B19CF676_F867_4C78_91CA_B47BC2450050__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Term
{
	int tnum;
	float avg;
	Term *next;
public:
	Term();
	Term* Next();
	void SetNext(Term*);
	void SetVar(int,float);
	int Tnum();
	float Avg();
};

#endif // !defined(AFX_TERM_H__B19CF676_F867_4C78_91CA_B47BC2450050__INCLUDED_)
