#include "testUtils.h"
#include "bracketMatchLib.h"
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


void test_Bracket_Should_Match(){
	String actual;
	strcpy(actual,"{[()]}");
	ASSERT(BracketMatch(actual));
}

void test_Bracket_Should_not_Match_2(){
	String actual;
	strcpy(actual,"{[(()]}");
	ASSERT(false==BracketMatch(actual));
}

void test_Bracket_Should_not_Match_3(){
	String actual;
	strcpy(actual,"{[())]}");
	ASSERT(false==BracketMatch(actual));
}

void test_Bracket_Should_not_Match_with_opening_bracket(){
	String actual;
	strcpy(actual,")");
	ASSERT(false==BracketMatch(actual));
}

void test_Bracket_Should_Match_with_complex_string(){
	String actual;
	strcpy(actual,"({[]()}[()])");
	ASSERT(true==BracketMatch(actual));
}

void test_Bracket_Should_not_Match_with_one_opening_bracket(){
	String actual;
	strcpy(actual,"[{]");
	ASSERT(false==BracketMatch(actual));
}
