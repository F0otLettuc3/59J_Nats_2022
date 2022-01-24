#include "main.h"
#include "autonsets.hpp"

void red1 (){
}

void red2 (){
}

void blue1 (){
}

void blue2 (){
}

void skills (){
  twoBarLift(TWOBARHIGH);
  delay(500);
  fourBarInsertionLift(FOURBARINSERTIONHIGH);
  baseMove(-21, 0.22, 0.02);
  waitBase(1000);
  twoBarLift(TWOBARLOW);
  delay(1000);
  timerBase(127, 40, 500);
  waitBase(500);
  baseTurn(100);
  waitBase(1000);
  baseMove(58);
  delay(1900);
  fourBarInsertionLift(FOURBARINSERTIONLOWER);
  delay(1400);
  fourBarLift(FOURBARHIGHER);
  delay(700);
  baseTurn(225);
  waitBase(2000);
  baseMove(54);
  waitBase(7000);
  delay(2000);
  fourBarInsertionLift(FOURBARINSERTIONHIGH);
  delay(2000);
  fourBarInsertionLift(FOURBARLOW);
  baseTurn(-10);
  waitBase(1000);
  fourBarLift(FOURBARLOW);
  fourBarInsertionLift(FOURBARINSERTIONHIGH);
  baseMove(45);
  waitBase(1000);

}
