
#define MAXVAL 100

int sp=0;
double val[MAXVAL];

void push(double f){
	if (sp<MAXVAL){
  		val[sp++]=f;
		}
	else
  		printf("error : stack full,can't push %g\n");
}

double pop(void){
	if (sp>0)
  		return val[--sp];
  	
	else {
 		printf("error:stack rmpty\n");
 		return 0.0;
	}
