#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
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

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
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

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
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
