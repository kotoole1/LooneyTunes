/* Looney Tunes - POE Final Project Fall 2013
 * Franklin W. Olin College of Engineering
 * Kyle McConnaughay, Kevin O'Toole, Chris Joyce, Allie Duncan, Philicia Chow
 */

var b = require('bonescript');
var constants = require('./Constants.js');


function Motor (motorPin1, motorPin2)
{
	var pin1 = motorPin1;
	var pin2 = motorPin2;

	b.pinMode(pin1, b.OUTPUT);
	b.pinMode(pin2, b.OUTPUT);

	// configure pins as outputs
	b.digitalWrite(motor1, b.HIGH);
	b.digitalWrite(motor1, b.HIGH);
}

module.exports.Motor = Motor;