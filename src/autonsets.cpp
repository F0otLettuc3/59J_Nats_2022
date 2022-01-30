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


  //STARTING liftstates
  twoBarLift(TWOBARHIGH);
  delay(500);
  fourBarInsertionLift(FOURBARINSERTIONHIGH);

  //grabbing first mogo
  baseMove(-21, 0.22, 0.02);
  waitBase(1000);
  twoBarLift(TWOBARLOW);
  delay(1000);

  //grabbing second mogo
  timerBase(127, -10, 550);
  waitBase(500);
  baseTurn(100);
  waitBase(1000);
  baseMove(59);
  delay(1900);
  fourBarInsertionLift(FOURBARINSERTIONLOWER);
  delay(1400);
  fourBarLift(950);
  delay(700);

  //scoring the second mogo
  baseTurn(225);
  waitBase(2000);
  baseMove(59, 0.195, 0.0);
  waitBase(2000);
  delay(2000);
  fourBarInsertionLift(FOURBARINSERTIONHIGH);
  delay(2000);

  //grabing the tall mogo
  baseMove(-10);
  waitBase(1000);
  baseTurn(115);
  waitBase(3000);
  fourBarInsertionLift(FOURBARINSERTIONLOW);
  fourBarLift(FOURBARLOW);
  fourBarInsertionLift(FOURBARINSERTIONHIGH);
  delay(500);
  baseMove(32,1.95,0.00);
  waitBase(1500);
  fourBarInsertionLift(FOURBARINSERTIONLOWER);
  delay(500);
  baseMove(53);
  waitBase(1000);
  fourBarInsertionLift(FOURBARINSERTIONHIGH);
  delay(1000);


  //second alliance mogo
  baseMove(-10);
  waitBase(1000);
  baseTurn(23);
  waitBase(1000);
  baseMove(50);
  waitBase(1000);
}
