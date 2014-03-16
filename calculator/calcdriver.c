#include <jni.h>
#include <stdio.h>
#include "calculator.h"
#include "com_calc_Driver.h"

/*
 * Class:     com_calc_Driver
 * Method:    setOperand
 * Signature: (F)V
 */
JNIEXPORT void JNICALL Java_com_calc_Driver_setOperand
(JNIEnv *env, jobject obj, jfloat f){
  setOperand(f);
}

/*
 * Class:     com_calc_Driver
 * Method:    setOperator
 * Signature: (C)V
 */
JNIEXPORT void JNICALL Java_com_calc_Driver_setOperator
(JNIEnv *env, jobject obj, jchar c){
  setOperator(c);
}

/*
 * Class:     com_calc_Driver
 * Method:    result
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_calc_Driver_result
(JNIEnv *env, jobject obj){
  return result();
}
