#include "main.h"


pros::MotorGroup intake({1,21}, pros::MotorGearset::blue);
pros::adi::Pneumatics lift('b', false);
pros::MotorGroup left_motors({-19, -18, -17});
pros::MotorGroup right_motors({11, 12, 13});

void move_robot(double time, int speed){
    left_motors.move_velocity(speed);
    right_motors.move_velocity(speed);
    pros::delay(time * 1000);
}

void move(){
    move_robot(0.5, 5);
    move_robot(0.5, 200);
}



