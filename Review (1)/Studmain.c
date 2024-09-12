#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Student.h"
#include "Student.c"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Stack s = createStack();
	Student stud = createstud(23103435,"Fafa","lname", "BSIT");
	push(&s, stud);
	 stud = createstud(23103432,"Bob","lname","BSCS");
	push(&s, stud);
	 stud = createstud(23103436,"Cab","wew","BSIT");
	push(&s, stud);
	 stud = createstud(23103439,"Zasdas","asdasdas", "BSCS");
	push(&s, stud);
visualise(s);
	printf("\n");
	
	Stack x =getStudent("BSCS",s);
	visualise(x);
		printf("\n");
	 x =getStudent("BSIT",s);
	visualise(x);
		printf("\n");
	sortStack(&s);
	printf("sorted:\n");
	visualise(s);
	return 0;
}
