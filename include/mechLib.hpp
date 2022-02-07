#ifndef _MECHLIB_HPP_
#define _MECHLIB_HPP_

#define fbP 0.3
#define fbD 0
#define tbP 0.95
#define tbD 0

#define FOURBARHIGHER 1000
#define FOURBARHIGH 800
#define FOURBARMEDIUM 700
#define FOURBARLOW 0

#define TWOBARHIGH -1000
#define TWOBARLOW 200
#define TWOBARHIGHER -1050

#define FOURBARINSERTIONHIGH 350
#define FOURBARINSERTIONLOW -1800
#define FOURBARINSERTIONLOWER -700


#define FOURBARINSERTIONDRIVERHIGH 100
#define FOURBARINSERTIONDRIVERLOW -1000
#define FOURBARINSERTIONDRIVERLOWER -500

//void setmech(double mogo, double lift);
void mogo2BarControl(void*ignore);
void twoBarLift(int height);
void mogo4BarControl(void*ignore);
void fourBarLift(int height);
void mogo4BarInsertionControl(void*ignore);
void fourBarInsertionLift(int height);
void motorBreak(bool brek);
#endif
