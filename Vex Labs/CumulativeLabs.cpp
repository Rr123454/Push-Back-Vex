#include "main.h"
#include "pros/misc.h"
#include "pros/screen.h"


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

void opcontrol(){
    pros::Controller master(pros::E_CONTROLLER_MASTER); // Basically gives you access to the values that the joystick provides

    bool forward = master.get_digital(pros::E_CONTROLLER_DIGITAL_R1); // Sets R1 as the button to move forward
    bool stop = master.get_digital(pros::E_CONTROLLER_DIGITAL_R2); // Sets R2 as the button to stop it from moving

    while (true){ // Almost forgot about this, can't have the robot moving indefinetly, this way it can be stopped mid move
        if (stop){
        move_robot(0.5, 0);
    }
        else if (forward){
            move_robot(0.5, 80);
    }
    }
    



    
    bool pressed = false;
    
    while(true){
        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A)!= pressed){ //Basically checks the digital val of the controller and runs if pressed

            left_motors.move(20);
            right_motors.move(20);
        }
        pros::delay(20);
    }

    while (true){
        int volt = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y); // Gets the value of the joystic and then stores it into volt
        if (std::abs(volt<5)){
            volt = 0; // Similar to drones, done so that when it is around the middle, no action will occur
        }

        left_motors.move(volt);
        right_motors.move(volt);

        pros::delay(20);

    }
}

void sensors(){
        // 1800 Encoder Ticks
        left_motors.set_encoder_units(pros::E_MOTOR_ENCODER_TICKS);
        right_motors.set_endcoder_units(pros::E_MOTOR_ENCODER_TICKS);

        left_motors.move_relative(1800, 80);
        right_motors.move_relative(1800, 80);

        // 3 Revolutions

        left_motors.set_encoder_units(pros::E_MOTOR_ENCODER_ROTATIONS);
        right_motors.set_encoder_units(pros::E_MOTOR_ENCODER_ROTATIONS);

        left_motors.move_relative(3, 80);
        right_motors.move_relative(3,80);

        // 180 Degrees

        left_motors.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
        right_motors.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);

        left_motors.move_relative(180, 80);
        right_motors.move_relative(180, 80);
}

    void move_rotations(double n){
        left_motors.set_encoder_units(pros::E_MOTOR_ENCODER_ROTATIONS);
        right_motors.set_encoder_units(pros::E_MOTOR_ENCODER_ROTATIONS);

        left_motors.tare_position();
        right_motors.tare_position(); // To reset it to 0

        left_motors.move_relative(n, 80);
        right_motors.move_relative(n, 80);
    }

    void spinnySpin(bool direction, double seconds){
        double time = seconds*1000;
        tare_position();
        if (direction){ // clockwise
            left_motors.move(80);
            right_motors.move(-80);
            pros::delay(time);
        }
        else{
            left_motors.move(-80);
            right_motors.move(80);
            pros::delay(time);
        }
    }

    void moveInches(double inches){
        left_motors.set_encoder_units(pros::E_MOTOR_ENCODER_ROTATIONS);
        right_motors.set_encoder_units(pros::E_MOTOR_ENCODER_ROTATIONS);
        double circumference = Math.PI() * 4;
        double rev = inches / circumference;
        
        left_motors.tare_position();
        right_motors.tare_position();

        left_motors.move_relative(rev, 80);
        right_motors.move_relative(rev, 80);
    }

    void moveDouble(double inch1, double inch2){
        moveInches(inch1);
        moveInches(inch2);
    }


    void initialize(){
        move_rotations(3);
        move_rotations(3);
        spinnySpin(false, 2);
        moveDouble(5, -5);
    }

