/* Looney Tunes - POE Final Project Fall 2013
 * Franklin W. Olin College of Engineering
 * Kyle McConnaughay, Kevin O'Toole, Chris Joyce, Allie Dunca, Philicia Chow
 */

var b = require('bonescript');
var constants = require('./Constants.js')

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
	// Set pins and pin modes
	this.servoPin = servoPin;
	this.motorPin1 = motorPin1;
	this.motorPin2 = motorPin2;
	this.encoderPin1 = encoderPin1;
	this.encoderPin2 = encoderPin2;

	// b.pinMode(encoderPin1, b.OUTPUT);
	// b.pinMode(encoderPin2, b.OUTPUT);
	// b.digitalWrite(encoderPin1, b.HIGH);
	// b.digitalWrite(encoderPin2, b.HIGH);

	b.pinMode(servoPin, b.OUTPUT);
	b.pinMode(motorPin1, b.OUTPUT);
	b.pinMode(motorPin2, b.OUTPUT);
	b.pinMode(encoderPin1, b.INPUT);
	b.pinMode(encoderPin2, b.INPUT);

	var _notes = {}
	var _servoPosition = 0;

	/* Add a note that this string will be able to play
	 * @param note: A string representation of the note that the string will be
	 *        able to play, e.g. 'A1' or 'B5'
	 * @param ticks: The number of ticks away from the base note of the string 
	 *        that the note parameter is. For instance, if the base note of the
	 *        string is 'A4', then _notes will contain 'A4' : 0. If 'B4' is 5 
	 *        ticks higher than 'A4', then _notes will contain 'B4' : 4
	 */
	this.AddNote = function (note, ticks)
	{
		_notes[note] = ticks;
	}

	/* Move the string into contact with the horse hair
	 * @param volume: A float between 0 and 1 that corresponds with how hard the
	 *        string is pushed into the horse hair
	 */
	this.SetVolume = function (volume)
	{
		b.analogWrite(this.servoPin, volume, constants.SERVO_WRITE_FREQ);
		console.log("Hello");
	};

	/* Set the string to a given frequency 
	 * @param note: An int representing the number of encoder ticks the string
	 *        should be tightened
	 */
	this.SetNote = function (note)
	{
		// Check if the note is higher or lower than the current position

		b.digitalWrite(motorPin1, 0);
		b.digitalWrite(motorPin2, 1);

		b.digitalWrite(motorPin1, 1);
		setTimeout(function() {looney.SetNoteCallback()}, 500)
		//b.digitalWrite(motorPin2, 0, this.SetNoteCallback);
	};

	/* Moniters the state of the string via the encoder to determine when the 
	 * desired tautness has been reached
	 */
	this.SetNoteCallback = function ()
	{
		// Update encoder count

		// Shut down the motors
		b.digitalWrite(motorPin1, 0);
		b.digitalWrite(motorPin2, 0);
	};
}

// Export the constructor for the violin string object. It can be accessed in
// other files by require('./Looney.js');
module.exports.Looney = Looney;