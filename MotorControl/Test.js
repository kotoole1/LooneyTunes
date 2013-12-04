/* Looney Tunes - POE Final Project Fall 2013
 * Franklin W. Olin College of Engineering
 * Kyle McConnaughay, Kevin O'Toole, Chris Joyce, Allie Dunca, Philicia Chow
 */

var b = require('bonescript');
var q = require('./QuadEncoder.js');
var s = require('./Servo.js');
var loon = require('./Looney.js');
var constants = require('./Constants.js');


var servo = new s.Servo('P9_14');
var encoderPin1 = 'P8_7';
var encoderPin2 = 'P8_9';
var enc = new q.QuadEncoder(encoderPin1, encoderPin2);

var lefts = 0;
var rights = 0;
console.log("Give it half a second");
TestEncoder();
console.log("Wheeeee!");

function TestServo()
{
	servo.SetPosition(0);
	servo.SetPosition(0.25);
	servo.SetPosition(0.5);
	servo.SetPosition(0.75);
	servo.SetPosition(1);
	servo.SetPosition(0.75);
	servo.SetPosition(0.5);
	servo.SetPosition(0.25);
	servo.SetPosition(0);
}

function TestEncoder()
{
	var testEncoderReads = setInterval(function(){ReadEncoder()}, 0.01);
	setTimeout(function(){clearInterval(testEncoderReads); console.log("lefts: " + lefts); console.log("rights: " + rights);}, 10000);

	var ReadEncoder = function () 
	{
		var ticked = enc.tick();
		if (ticked == '>')
		{
			lefts++;
			console.log(ticked);
		}
		else if (ticked == '<')
		{
			rights++;
			console.log(ticked);
		}
	}
}

// var enc = new q.QuadEncoder(encoderPin1, encoderPin2);
// var testEncoderReads = setInterval(function(){console.log(enc.tick())}, 10);
// setTimeout(function(){clearInterval(testEncoderReads);}, 1000);

// var looney = new loon.Looney('P9_14', 'P8_4', 'P8_6', encoderPin1, encoderPin2);

// Test each volume of the string
// setTimeout(function() {looney.SetVolume(constants.SILENT);}, 1000);
// setTimeout(function() {looney.SetVolume(constants.PIANO);}, 2000);
// setTimeout(function() {looney.SetVolume(constants.MEZZO_PIANO);}, 3000);
// setTimeout(function() {looney.SetVolume(constants.MEZZO_FORTE);}, 4000);
// setTimeout(function() {looney.SetVolume(constants.FORTE);}, 5000);

// var testEncoderReads = setInterval(function(){ReadEncoder()}, 100);
// setTimeout(function(){clearInterval(testEncoderReads);}, 5000);

// var ReadEncoder = function () 
// {
// 	var pin1Value = b.digitalRead(encoderPin1);
// 	var pin2Value = b.digitalRead(encoderPin2);

// 	console.log(pin1Value + ", " + pin2Value);
// }