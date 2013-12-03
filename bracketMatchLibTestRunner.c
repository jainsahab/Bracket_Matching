#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_Bracket_Should_Match");
	setup();
		test_Bracket_Should_Match();
	tearDown();
	testEnded();
	testStarted("test_Bracket_Should_not_Match_2");
	setup();
		test_Bracket_Should_not_Match_2();
	tearDown();
	testEnded();
	testStarted("test_Bracket_Should_not_Match_3");
	setup();
		test_Bracket_Should_not_Match_3();
	tearDown();
	testEnded();
	testStarted("test_Bracket_Should_not_Match_with_opening_bracket");
	setup();
		test_Bracket_Should_not_Match_with_opening_bracket();
	tearDown();
	testEnded();
	testStarted("test_Bracket_Should_Match_with_complex_string");
	setup();
		test_Bracket_Should_Match_with_complex_string();
	tearDown();
	testEnded();
	testStarted("test_Bracket_Should_not_Match_with_one_opening_bracket");
	setup();
		test_Bracket_Should_not_Match_with_one_opening_bracket();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
