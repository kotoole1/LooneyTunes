/* Looney Tunes - POE Final Project Fall 2013
 * Franklin W. Olin College of Engineering
 * Kyle McConnaughay, Kevin O'Toole, Chris Joyce, Allie Dunca, Philicia Chow
 *
 * Template for this class was taken from medecaukey: "value",  
 * https://github.com/medecau/QuadEncoder/blob/master/QuadEncoder.cpp
 */

var b = require('bonescript');

function BetterQuadEncoder (pin1, pin2)
{
	b.pinMode(pin1, b.INPUT);
	b.pinMode(pin2, b.INPUT);
	b.attachInterrupt(pin1, true, b.CHANGE, pinOneTick);
	b.attachInterrupt(pin2, true, b.CHANGE, pinTwoTick);

	//
	// Start pin running
	//

	// read in the BoneScript library
	var b = require('bonescript');

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
  
	function pinOneTick(x)
	{
	  	_val1 = parseInt(x.value);
	  	tick();
	}

	function pinTwoTick(y)
	
	  	_val2 = parseInt(y.value);
	  	tick();
	}

	function tick ()
	{
  	


	    
    //for each pair there's a position out of four
    if ( _val1 == 1 ) 
    {// stationary position
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

	    	// //handle whether it should be incremented or decremented
	    	// if(_pos == 0 && _prevPos == 3 || _pos == 1 && _prevPos == 0 || _pos == 2 && _prevPos == 1 || _pos == 3 && _prevPos == 2){
	    	// 	//console.log("incrememting");
	    	// 	_dir = 1;

	    	// }


	    	// if (_pos == 3 && _prevPos == 0 || _pos == 2 && _prevPos == 3 || _pos == 1 && _prevPos == 2 || _pos == 0 && _prevPos == 1)
	    	// {
	    	// 	//console.log("decrementing");
	    		
	    	// 	_dir = -1;
	    	// }

	    	// _prevPos = _pos;
	    	
	    
	  // }

	 console.log("absolute position: " + _absPos);
	 return _absPos;
	 
	}

	this.dispose = function()
	{
		// detach interrupts
		b.detachInterrupt(_inputPin1);
		b.detachInterrupt(_inputPin2);
		console.log("Pin event handlers detached");
	}
}

module.exports.BetterQuadEncoder = BetterQuadEncoder;