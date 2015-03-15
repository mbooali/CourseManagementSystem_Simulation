// Term.cpp: implementation of the Term class.
//
//////////////////////////////////////////////////////////////////////

#include "Term.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


Term::Term()
{
	tnum =0;
	avg = 0;
}

Term* Term::Next()
{
	return next;
}

void Term::SetNext(Term* next2)
{
	next = next2;
}

void Term::SetVar(int _tnum, float _avg)
{
	tnum=_tnum; avg=_avg;
}
int Term::Tnum()
{
	return tnum;
}

float Term::Avg()
{
	return avg;
}

