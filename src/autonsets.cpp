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
  fourBarInsertionLift(FOURBARINSERTIONHIGH);

  //grabbing first mogo
  baseMove(-21, 0.22, 0.02);
  waitBase(1000);
  twoBarLift(TWOBARLOW);
  delay(500);

  //grabbing second mogo
  timerBase(127, -10, 550);
  waitBase(500);
  baseTurn(100);
  waitBase(1000);
  baseMove(59, 0.22, 0.0);
  delay(1900);
  fourBarInsertionLift(FOURBARINSERTIONLOWER);
  delay(1000);
  fourBarLift(920);
  delay(700);

  //scoring the second mogo
  baseTurn(225);
  waitBase(2000);
  baseMove(59.5, 0.2, 0.0);
  waitBase(1500);
  delay(2000);
  fourBarInsertionLift(FOURBARINSERTIONHIGH);
  delay(1000);

  //grabing the tall mogo
  baseMove(-15);
  waitBase(1000);
  baseTurn(130);
  waitBase(1500);
  fourBarInsertionLift(FOURBARINSERTIONLOW);
  fourBarLift(FOURBARLOW);
  fourBarInsertionLift(FOURBARINSERTIONHIGH);
  delay(500);
  baseMove(32,1.95,0.00);
  waitBase(1500);
  fourBarInsertionLift(FOURBARINSERTIONLOWER);
  delay(500);
  fourBarLift(150);
  baseMove(56,0.22,0.00);
  waitBase(1000);
  fourBarInsertionLift(FOURBARINSERTIONHIGH);
  delay(1000);


  //blue mogo
  waitBase(1000);
  baseMove(-13);
  fourBarLift(FOURBARHIGH);
  waitBase(1000);
  baseTurn(22);
  waitBase(2000);
  baseMove(76,0.22,0.00);
  delay(500);
  fourBarLift(FOURBARLOW);
  delay(1500);
  fourBarInsertionLift(FOURBARINSERTIONLOW);
  delay(1000);
  fourBarLift(FOURBARHIGHER);
  delay(200);
  waitBase(1000);
  baseMove(-10);
  waitBase(1000);
  baseTurn(-105);
  waitBase(4000);
  baseMove(92);
  delay(2300);
  fourBarInsertionLift(FOURBARINSERTIONHIGH);


  // 140 pts
  delay(2000);
  waitBase(1000);
  baseMove(-30);
  delay(500);
  fourBarLift(FOURBARLOW);
  waitBase(3000);
  baseTurn(180, 1.12, 0.00);
  waitBase(3000);
  baseMove(43);
  fourBarInsertionLift(FOURBARINSERTIONLOW);
  waitBase(750);
  fourBarLift(FOURBARHIGH);
  waitBase(1000);
  baseTurn(152);
  waitBase(1000);
  baseMove(20);
  delay(750);
  fourBarInsertionLift(FOURBARINSERTIONHIGH);

  //second red mogo
  waitBase(1000);
  baseMove(10);
  fourBarLift(FOURBARLOW);
  waitBase(1500);
  baseTurn(-90);
  baseMove(15);
  fourBarInsertionLift(FOURBARINSERTIONLOW);

}
