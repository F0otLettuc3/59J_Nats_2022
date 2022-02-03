#include "main.h"

void initialize() {
	  Controller master(E_CONTROLLER_MASTER);
		Motor FL (FLmotor, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
		Motor BL (BLmotor, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
		Motor FR (FRmotor, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
		Motor BR (BRmotor, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	  Motor lLift (Lliftmotor, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
		Motor rLift (RLiftmotor, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
		Motor Bintake (Bmotor, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES);
		Motor Fintake (Fmotor, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES);
		Imu imu (imuPort);
		imu.reset();


		Task controlTask(Control, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT);
    Task debugTask(Debug, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT);
		Task odometryTask(Odometry, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT);
		Task sensorsTask(Sensors, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT);
		Task mogo4BarControlTask(mogo4BarControl, (void*)"PROS", TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"My Task");
		Task mogo2BarControlTask(mogo2BarControl, (void*)"PROS", TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"My Task");
		Task mogo4BarInsertionControlTask(mogo4BarInsertionControl, (void*)"PROS", TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"My Task");

}


void disabled() {}

void competition_initialize() {}

void autonomous() {
	int autonum = 5;
	switch(autonum){
		case 1: red1(); break;
		case 2: red2(); break;
		case 3: blue1(); break;
		case 4: blue2(); break;
		case 5: skills(); break;
	}
	delay(25);
}

void opcontrol() {
	Controller master(E_CONTROLLER_MASTER);
	 	Motor FL (FLmotor);
	 	Motor BL (BLmotor);
	 	Motor FR (FRmotor);
	 	Motor BR (BRmotor);
		Motor mogo2Bar (Bmotor);
		Motor mogo4BarLeft (Lliftmotor);
		Motor mogo4BarRight (RLiftmotor);
		Motor mogo4BarInsertion(Fmotor);
		twoBarLift(TWOBARLOW);
		fourBarLift(FOURBARLOW);
		fourBarInsertionLift(FOURBARINSERTIONHIGH);

		int fourBarSensitivity = 2;
		int fourBarSetTarg = 1;
		bool liftstate = true;
		bool bliftstate = false;

	while (true) {

		//tank drive
		double left = master.get_analog(ANALOG_LEFT_Y);
		double right = master.get_analog(ANALOG_RIGHT_Y);
		FL.move(left);
		BL.move(left);
		FR.move(right);
		BR.move(right);

		//lift Control
	if(master.get_digital_new_press(DIGITAL_L1)){
			fourBarLift(FOURBARHIGH);
		}
	else if(master.get_digital_new_press(DIGITAL_L2)){
			fourBarLift(FOURBARLOW);
		}

	if (master.get_digital_new_press(DIGITAL_R2)){
		bliftstate = !bliftstate;
		delay(5);
	}

	if (bliftstate){
		twoBarLift(TWOBARHIGH);
	}else {
		twoBarLift((TWOBARLOW));
		delay(5);
	}


	if (master.get_digital_new_press(DIGITAL_R1)){
		liftstate = !liftstate;
		delay(5);
	}

	if(liftstate){
		fourBarInsertionLift(FOURBARINSERTIONLOW);
	}else{
		fourBarInsertionLift(FOURBARINSERTIONHIGH);
		delay(5);
	}

delay(5);
 }
}
