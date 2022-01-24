#ifndef _MECHLIB_HPP_
#define _MECHLIB_HPP_

#define fbP 0.3
#define fbD 0
#define tbP 0.95
#define tbD 0

#define FOURBARHIGHER 1200
#define FOURBARHIGH 800
#define FOURBARMEDIUM 50
#define FOURBARLOW 0

#define TWOBARHIGH -1000
#define TWOBARLOW 200

#define FOURBARINSERTIONHIGH 1000
#define FOURBARINSERTIONLOW -350
#define FOURBARINSERTIONLOWER -500

//void setmech(double mogo, double lift);
void mogo2BarControl(void*ignore);
void twoBarLift(int height);
void mogo4BarControl(void*ignore);
void fourBarLift(int height);
void mogo4BarInsertionControl(void*ignore);
void fourBarInsertionLift(int height);
void motorBreak(bool brek);
#endif
