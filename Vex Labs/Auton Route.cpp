#include "main.h"
#include "pros/misc.h"
#include "pros/screen.h"
#include "constants.h"


pros::MotorGroup intake({1,21}, pros::MotorGearset::blue);
pros::adi::Pneumatics lift('b', false);
pros::MotorGroup left_motors({-19, -18, -17});
pros::MotorGroup right_motors({11, 12, 13});



int main(){
    pid_drive_set(speed);


}