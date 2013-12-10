/* Looney Tunes - POE Final Project Fall 2013
 * Franklin W. Olin College of Engineering
 * Kyle McConnaughay, Kevin O'Toole, Chris Joyce, Allie Dunca, Philicia Chow
 *
 * Template for this class was taken from medecaukey: "value",  
 * https://github.com/medecau/QuadEncoder/blob/master/QuadEncoder.cpp
 */

var b = require('bonescript');

function QuadEncoder (pin1, pin2, checkDoneCallback)
{
	var self = this;
	self.checkDoneCallback = checkDoneCallback;

	b.pinMode(pin1, b.INPUT);
	b.pinMode(pin2, b.INPUT);
	b.attachInterrupt(pin1, true, b.CHANGE, self.PinOneTick);
	b.attachInterrupt(pin2, true, b.CHANGE, self.PinTwoTick);

	// b.digitalWrite(pin1, b.HIGH);
	// b.digitalWrite(pin2, b.HIGH);

	var _inputPin1 = pin1;
	var _inputPin2 = pin2;
	var _val1 = 0;
	var _val2 = 0;
	var _pos = 0; //position in the 0,1,2,3 loop
	var _absPos = 0; //overall position of encoder with relation to start
	var _prevPos = 0;
	var _dir = 1; //1 is incrememnting, -1 is decrementing
	var _oldVal1 = 1;
	var _oldVal2 = 1;

	var _seenThree = 0;
	var _seenTwo = 0;
	var _seenOne = 0;
	var _seenZero = 0;
  
	self.PinOneTick = function (x)
	{
	  	_val1 = parseInt(x.value);
	  	self.Tick();
	  	self.CheckDone();
	}

	self.PinTwoTick = function (x)
	{
	  	_val2 = parseInt(x.value);
	  	self.Tick();
	  	self.CheckDone();

	}

	self.Tick = function ()
	{  
	    //for each pair there's a position out of four
	    if ( _val1 == 1 ) 
	    { // stationary position
	      if (_val2 == 1)
	      {
	        _pos = 0;
	        _seenZero = 1;
	      }
	      else if (_val2 == 0)
	      {
	        _pos = 3;
	        _seenThree = 1;
	      }
	    } 
	    else if (_val1 == 0)
	    {
	      if (_val2 == 1)
	      {
	        _pos = 1;
	        _seenOne = 1;
	      }
	      else if (_val2 == 0)
	      {
	        _pos = 2;
	        _seenTwo = 1;
	      }
	    }

		console.log(_pos);
		//console.log(_val1 + ", " + _val2)

		//If all four (0,1,2, and 3) are visited...
		if (_seenOne == 1 && _seenZero == 1 && _seenTwo == 1 && _seenThree == 1 && _pos == 0){
			console.log("TICK!!!!!!!!!");
			_absPos = _absPos + 1*_dir;
			_seenZero = 0;
			_seenOne = 0;
			_seenTwo = 0
			_seenThree = 0;
		}

		//If three modes are visited ( 0, 1, and 3)
		if (_seenOne == 1 && _seenZero == 1 && _seenThree == 1 && _pos == 0){
			console.log("TICK!!!!!!!!!");
			_absPos = _absPos + 1*_dir;
			_seenZero = 0;
			_seenOne = 0;
			_seenTwo = 0
			_seenThree = 0;
		}

		//If three modes are visited ( 0, 2, and 3)
		if (_seenZero == 1 && _seenTwo == 1 && _seenThree == 1 && _pos == 0){
			console.log("TICK!!!!!!!!!");
			//Increment or decrement direction with relation to current direction
			_absPos = _absPos + 1*_dir;
			_seenZero = 0;
			_seenOne = 0;
			_seenTwo = 0
			_seenThree = 0;
		}

		//If two modes are visited ( 0 and 1)
		if (_seenZero == 1 && _seenOne == 1  && _pos == 0){
			console.log("TICK!!!!!!!!!");
			//Increment or decrement direction with relation to current direction
			_absPos = _absPos + 1*_dir;
			_seenZero = 0;
			_seenOne = 0;
			_seenTwo = 0
			_seenThree = 0;
		}

		console.log("absolute position: " + _absPos);
		return _absPos;
	}

	self.CheckDone = function ()
	{
		
	}

	self.Dispose = function()
	{
		// detach interrupts
		b.detachInterrupt(_inputPin1);
		b.detachInterrupt(_inputPin2);
		console.log("Pin event handlers detached");
	}
}

module.exports.QuadEncoder = QuadEncoder;





