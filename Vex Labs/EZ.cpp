// Chassis constructor
ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {1, 2, 3},     // Left Chassis Ports (negative port will reverse it!)
    {-4, -5, -6},  // Right Chassis Ports (negative port will reverse it!)

    7,       // IMU Port
    4.125,   // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    343.0);  // Wheel RPM = cartridge * (motor gear / wheel gear)

    