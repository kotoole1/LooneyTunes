/* Looney Tunes - POE Final Project Fall 2013
 * Franklin W. Olin College of Engineering
 * Kyle McConnaughay, Kevin O'Toole, Chris Joyce, Allie Dunca, Philicia Chow
 */

// Constants for servo control
module.exports.SERVO_WRITE_FREQ = 300; // Hertz
module.exports.DUTY_CYCLE_MIN = 0.03; // In the range [0, 1]

// Constants for volume control should take values between zero and one because
// the position of the servo is controlled by the duty cycle of the PWM write
module.exports.SILENT = 0;
module.exports.PIANO = 0.25;
module.exports.MEZZO_PIANO = 0.5
module.exports.MEZZO_FORTE = 0.75;
module.exports.FORTE = 1;


//Motor pins
module.exports.Looney1MotorPin1 = 'P8_7';
module.exports.Looney1MotorPin2 = 'P8_9';
module.exports.Looney2MotorPin1 = 'P8_11';
module.exports.Looney2MotorPin2 = 'P8_13';		//Does this pin work? - it is listed as "EHRPWN2B"
module.exports.Looney3MotorPin1 = 'P8_15';
module.exports.Looney3MotorPin2 = 'P8_17';
module.exports.Looney4MotorPin1 = 'P8_21';
module.exports.Looney4MotorPin2 = 'P8_23';


//Encoder pins
module.exports.Looney1QuadEncoderPin1 = 'P8_8';
module.exports.Looney1QuadEncoderPin2 = 'P8_10';
module.exports.Looney2QuadEncoderPin1 = 'P8_12';
module.exports.Looney2QuadEncoderPin2 = 'P8_14';
module.exports.Looney3QuadEncoderPin1 = 'P8_16';
module.exports.Looney3QuadEncoderPin2 = 'P8_18';
module.exports.Looney4QuadEncoderPin1 = 'P8_20';
module.exports.Looney4QuadEncoderPin2 = 'P8_22';



//Servo pin numbers (PWM pins)
//Not actually wired yet!!!
module.exports.Looney1ServoPin = 'P9_21';
module.exports.Looney2ServoPin = 'P9_29';
module.exports.Looney1ServoPin = 'P9_14';
module.exports.Looney2ServoPin = 'P9_22';

