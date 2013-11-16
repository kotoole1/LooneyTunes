/* Looney Tunes - POE Final Project Fall 2013
 * Franklin W. Olin College of Engineering
 * Kyle McConnaughay, Kevin O'Toole, Chris Joyce, Allie Dunca, Philicia Chow
 */

var b = require('bonescript');

// Constants for servo control
var SERVO_WRITE_FREQ = 300; // Hertz

// Constants for volume control should take values between zero and one
var SILENT = 0;
var PIANO = 0.25;
var MEZZO_PIANO = 0.5
var MEZZO_FORTE = 0.75;
var FORTE = 1;

/* Object contructor. Looney objects will each be responsible controlling for 
 * a single string
 * @param servoPin: The write pin for the servo to control whether the string is
          in contact with the horse hair
 * @param motorPin1: The first write pin for the motor that tightens/loosens the 
          string
 * @param motorPin2: The second write pin for the motor that tightens/loosens 
          the string
 * @param encoderPin1: The first read pin for the encoder to determine how taut
          the string is
 * @param encoderPin2: The second read pin for the encoder to determine how taut
          the string is
 */ 
function Looney(servoPin, motorPin1, motorPin2, encoderPin1, encoderPin2) 
{
	this.servoPin = servoPin;
	this.motorPin1 = motorPin1;
	this.motorPin2 = motorPin2;
	this.encoderPin1 = encoderPin1;
	this.encoderPin2 = encoderPin2;

	/* Move the string into contact with the horse hair
	 * @param volume: A float between 0 and 1 that corresponds with how hard the
	 *        string is pushed into the horse hair
	 */
	this.Play = function (volume)
	{
		b.analogWrite(this.servoPin, volume, SERVO_WRITE_FREQ);
		console.log("Hello");
	};

	/* Set the string to a given frequency 
	 * @param note: An int representing the number of encoder ticks the string
	 *        should be tightened
	 */
	this.SetNote = function (note)
	{

	};
}

// Test code
var looney = new Looney('P9_14', 0, 0, 0, 0);

setTimeout(function() {looney.Play(SILENT);}, 1000);
setTimeout(function() {looney.Play(PIANO);}, 2000);
setTimeout(function() {looney.Play(MEZZO_PIANO);}, 3000);
setTimeout(function() {looney.Play(MEZZO_FORTE);}, 4000);
setTimeout(function() {looney.Play(FORTE);}, 5000);