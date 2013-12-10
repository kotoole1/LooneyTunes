/* Looney Tunes - POE Final Project Fall 2013
 * Franklin W. Olin College of Engineering
 * Kyle McConnaughay, Kevin O'Toole, Chris Joyce, Allie Dunca, Philicia Chow
 */

var b = require('bonescript');
var q = require('./QuadEncoder.js');
var s = require('./Servo.js');
var l = require('./Looney.js');
var m = require('./Motor.js');
var c = require('./Constants.js');

/****************************************************************************/
/*                              Test Suite                                  */
/****************************************************************************/

// TestServo(c.Looney1ServoPin);
// TestMotor(c.Looney1MotorPin1, c.Looney1MotorPin2)
TestEncoder(c.Looney1ServoPin, c.Looney1MotorPin1, c.Looney1MotorPin2, c.Looney1QuadEncoderPin1, c.Looney1QuadEncoderPin2);

/****************************************************************************/
/*                          Function Definitions                            */
/****************************************************************************/

function TestServo(servoPin)
{
	var servo = new s.Servo(servoPin);

	servo.SetPosition(c.SILENT);
	setTimeout(function () { servo.SetPosition(c.PIANO); }, 1000);
	setTimeout(function () { servo.SetPosition(c.MEZZ_PIANO); }, 2000);
	setTimeout(function () { servo.SetPosition(c.MEZZO_FORTE); }, 3000);
	setTimeout(function () { servo.SetPosition(c.FORTE); }, 4000);
	setTimeout(function () { servo.SetPosition(c.MEZZO_FORTE); }, 5000);
	setTimeout(function () { servo.SetPosition(c.MEZZO_PIANO); }, 6000);
	setTimeout(function () { servo.SetPosition(c.PIANO); }, 7000);
	setTimeout(function () { servo.SetPosition(c.SILENT); }, 8000);
}

function TestMotor(motorPin1, motorPin2)
{
	var motor = new m.Motor(motorPin1, motorPin2);

	motor.Tighten();
	setTimeout(function () { motor.Hold(); }, 1000);
	setTimeout(function () { motor.Loosen(); }, 2000);
	setTimeout(function () { motor.Hold(); }, 3000);
}

function TestEncoder(servoPin, motorPin1, motorPin2, encoderPin1, encoderPin2)
{
	//just test the encoder
	//var encoder = new q.QuadEncoder(encoderPin1, encoderPin2);

	var looney = new l.Looney(Looney1ServoPin, Looney1MotorPin1, Looney1MotorPin2, Looney1QuadEncoderPin1, Looney1QuadEncoderPin2);
	looney.SetNote(10);
}




