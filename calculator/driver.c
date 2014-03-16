#include <stdio.h>
#include "consoleinput.h"
#include "calculator.h"

int main(int argc, char **argv){
   
  char operator = ' ';

  while(operator != '='){
    setOperand(getOperand());
    operator = getOperator();
    setOperator(operator);
  }

  printf("\n%2.2f\n\n", result());

}
