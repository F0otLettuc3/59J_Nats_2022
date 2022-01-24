#include "main.h"
#include "mechlib.hpp"

Motor FL (FLmotor);
Motor FR (FRmotor);
Motor BL (BLmotor);
Motor BR (BRmotor);

Motor Fintake (Fmotor);
Motor Bintake (Bmotor);
Motor lLift (Lliftmotor);
Motor rLift (RLiftmotor);


int twobarTarg=0, fourbarTarg = 0, fourbarInsertionTarg = 0;
void mogo2BarControl(void * ignore){
	Controller master(E_CONTROLLER_MASTER);
	Motor Bintake(Bmotor);
	int oldErr = 0;

	while(true){
		int error = twobarTarg - Bintake.get_position();
		int power = error*tbP + (error-oldErr)*tbD;
		oldErr = error;

		if(abs(error) < 2) {
			Bintake.move(0);
		}
		else Bintake.move(power);

		delay(5);
	}
}
void twoBarLift(int height){
	twobarTarg = height;
}

void mogo4BarControl(void * ignore){
	Controller master(E_CONTROLLER_MASTER);
	Motor lLift (Lliftmotor);
	Motor rLift (RLiftmotor);
	int oldErrLeft = 0, oldErrRight = 0;

	while(true){
		int errorLeft = fourbarTarg - lLift.get_position();
		int powerLeft = errorLeft*tbP + (errorLeft-oldErrLeft)*tbD;
		oldErrLeft = errorLeft;

		if(abs(errorLeft) < 2) {
			lLift.move(0);
		}
		else lLift.move(powerLeft);

		int errorRight = fourbarTarg - rLift.get_position();
		int powerRight = errorRight*tbP + (errorRight-oldErrRight)*tbD;
		oldErrRight = errorRight;

		if(abs(errorRight) < 2) {
			rLift.move(0);
		}
		else rLift.move(powerRight);

		delay(5);

	}
}
void fourBarLift(int height){
	fourbarTarg = height;
}


void mogo4BarInsertionControl(void * ignore){
	Controller master(E_CONTROLLER_MASTER);
	Motor Fintake (Fmotor);
	int_least8_t oldErr = 0;

	while(true){
		int error = fourbarInsertionTarg - Fintake.get_position();
		int power = error*tbP + (error-oldErr)*tbD;
		oldErr = error;

		if(abs(error) < 2) {
			Fintake.move(0);
		}
		else Fintake.move(power);

		delay(5);
	}
}
void fourBarInsertionLift(int height){
	fourbarInsertionTarg = height;
}

void motorBreak(bool brek){
  BL.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  FL.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  BR.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  FR.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
