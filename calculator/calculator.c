#include "calculator.h"
#include <stdio.h>

void apply(void);

float runningTotal = 0;
float operand = 0;
char operator = ' ';

void setOperand(float f){
  operand = f;
  if(operator == ' '){
    runningTotal += f;
  }
  else{
    apply();
  }
}

void setOperator(char c){
  operator = c;
}

void apply(void){
  switch(operator){
  case '+':
    runningTotal += operand;
    break;
  case '-':
    runningTotal -= operand;
    break;
  case '*':
    runningTotal *= operand;
    break;
  case '/':
    runningTotal /= operand;
    break;
  }
}

float result(void){
  return runningTotal;
}
