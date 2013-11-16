/* Looney Tunes - POE Final Project Fall 2013
 * Franklin W. Olin College of Engineering
 * Kyle McConnaughay, Kevin O'Toole, Chris Joyce, Allie Dunca, Philicia Chow
 */


/* Object to control a single string
 * 
 */ 
function Looney(servoPin, motorPin1, motorPin2, encoderPin1, encoderPin2) 
{
	this.servoPin = servoPin;
	this.motorPin1 = motorPin1;
	this.motorPin2 = motorPin2;
	this.encoderPin1 = encoderPin1;
	this.encoderPin2 = encoderPin2;
}