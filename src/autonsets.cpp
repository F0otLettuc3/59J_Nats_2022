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
  waitBase(2000);
  baseMove(-17);
  delay(1500);
  twoBarLift(TWOBARLOW);
  delay(500);
  timerBase(127, -20, 645);
  waitBase(2000);
  baseMove(51.5,0.28,0.00);
  delay(1500);
  fourBarInsertionLift(FOURBARINSERTIONLOW);
  delay(600);
  fourBarLift(FOURBARHIGHER);
  waitBase(7000);
  baseTurn(212);
  delay(500);
  waitBase(6500);
  baseMove(57,0.26,0);
  delay(1400);
  fourBarLift(FOURBARMEDIUM);
  delay(2000);
  fourBarInsertionLift(FOURBARINSERTIONHIGH);
  delay(2000);
  waitBase(1000);
  baseMove(-28);
  delay(700);
  fourBarLift(FOURBARLOW);
  delay(500);
  waitBase(7000);
  baseTurn(140);
  delay(500);
  waitBase(3000);
  baseMove(27,0.28,0);
  delay(1500);
  fourBarInsertionLift(FOURBARINSERTIONLOWER);
  delay(1500);
  fourBarLift(100);
  delay(500);
  waitBase(2000);
  baseMove(45);
  delay(1000);
  fourBarInsertionLift(FOURBARINSERTIONHIGH);
  delay(1000);
  waitBase(1000);
  baseMove(-16);
  delay(510);
  fourBarLift(FOURBARLOW);
  delay(600);
  waitBase(7000);
  baseTurn(27);
  delay(2000);
  baseMove(76);
  delay(1300);
  fourBarInsertionLift(FOURBARINSERTIONLOWER);

}



  // //STARTING liftstates
  // twoBarLift(TWOBARHIGH);
  //
  // //grabbing first mogo
  // baseMove(-21, 0.22, 0.02);
  // waitBase(1000);
  // twoBarLift(TWOBARLOW);
  // delay(500);
  //
  // //grabbing second mogo
  // timerBase(127, -10, 550);
  // waitBase(500);
  // baseTurn(100);
  // waitBase(1000);
  // baseMove(59, 0.22, 0.0);
  // delay(1900);
  // fourBarInsertionLift(FOURBARINSERTIONLOW);
  // delay(1000);
  // fourBarLift(920);
  // delay(700);
  //
  // //scoring the second mogo
  // baseTurn(228);
  // waitBase(2500);
  // baseMove(61, 0.2, 0.0);
  // waitBase(1500);
  // delay(2000);
  // fourBarInsertionLift(FOURBARINSERTIONHIGH);
  // delay(1000);
  //
  // //grabing the tall mogo
  //
  // waitBase(1500);
  // baseMove(-17);
  // waitBase(1000);
  // baseTurn(130);
  // fourBarInsertionLift(FOURBARINSERTIONLOW);
  // fourBarLift(FOURBARLOW);
  // fourBarInsertionLift(FOURBARINSERTIONHIGH);
  // delay(500);
  // waitBase(1500);
  // baseMove(32,1.85,0.00);
  // delay(500);
  // waitBase(1500);
  // fourBarInsertionLift(FOURBARINSERTIONLOW);
  // delay(500);
  // fourBarLift(150);
  // baseMove(56,0.22,0.00);
  // waitBase(1000);
  // fourBarInsertionLift(FOURBARINSERTIONHIGH);
  // delay(1000);
  //
  //
  // //blue mogo
  // waitBase(1000);
  // baseMove(-16);
  // fourBarLift(FOURBARHIGH);
  // waitBase(1000);
  // baseTurn(22);
  // waitBase(2000);
  // baseMove(76,0.22,0.00);
  // delay(500);
  // fourBarLift(FOURBARLOW);
  // delay(1500);
  // fourBarInsertionLift(FOURBARINSERTIONLOW);
  // delay(1000);
  // fourBarLift(FOURBARHIGHER);
  // delay(200);
  // waitBase(1000);
  // baseMove(-10);
  // waitBase(1000);
  // baseTurn(-110);
  // waitBase(4000);
  // baseMove(92);
  // delay(2300);
  // fourBarInsertionLift(FOURBARINSERTIONHIGH);
  //
  //
  // // 140 pts
  // delay(2000);
  // waitBase(1000);
  // baseMove(-30);
  // delay(500);
  // fourBarLift(FOURBARLOW);
  // waitBase(3000);
  // baseTurn(180, 1.12, 0.00);
  // waitBase(3000);
  // baseMove(43);
  // fourBarInsertionLift(FOURBARINSERTIONLOW);
  // waitBase(750);
  // fourBarLift(FOURBARHIGH);
  // waitBase(1000);
  // baseTurn(152);
  // waitBase(1000);
  // baseMove(20);
  // delay(750);
  // fourBarInsertionLift(FOURBARINSERTIONHIGH);
  //
  // //second red mogo
  // waitBase(1000);
  // baseMove(10);
  // fourBarLift(FOURBARLOW);
  // waitBase(1500);
  // baseTurn(-90);
  // baseMove(15);
  // fourBarInsertionLift(FOURBARINSERTIONLOW);
