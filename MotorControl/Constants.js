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