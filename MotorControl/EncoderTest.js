/* Looney Tunes - POE Final Project Fall 2013
 * Franklin W. Olin College of Engineering
 * Kyle McConnaughay, Kevin O'Toole, Chris Joyce, Allie Dunca, Philicia Chow
 */

var b = require('bonescript');
var q = require('./BetterQuadEncoder.js');
var s = require('./Servo.js');
var loon = require('./Looney.js');
var constants = require('./Constants.js');


var servo = new s.Servo('P9_14');
var encoderPin1 = 'P8_7';
var encoderPin2 = 'P8_9';
var enc = new q.BetterQuadEncoder(encoderPin1, encoderPin2);

var lefts = 0;
var rights = 0;

console.log("TestEncoder()");
TestEncoder();

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
	setTimeout(function(){enc.dispose();}, 10000);
}