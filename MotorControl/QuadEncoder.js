/* Looney Tunes - POE Final Project Fall 2013
 * Franklin W. Olin College of Engineering
 * Kyle McConnaughay, Kevin O'Toole, Chris Joyce, Allie Dunca, Philicia Chow
 *
 * Template for this class was taken from medecaukey: "value",  
 * https://github.com/medecau/QuadEncoder/blob/master/QuadEncoder.cpp
 */

var b = require('bonescript');

function QuadEncoder(pin1, pin2)
{
	b.pinMode(pin1, b.INPUT);
	b.pinMode(pin2, b.INPUT);
	// b.digitalWrite(pin1, b.HIGH);
	// b.digitalWrite(pin2, b.HIGH);

	var _inputPin1 = pin1;
  var _inputPin2 = pin2;
  var _val1 = 1;
  var _val2 = 1;
  var _oldVal1 = 1;
  var _oldVal2 = 1;
  var _pos = 0;
  var _oldPos = 0;
  var _turn = 0;
  var _turnCount = 0;
  var _moved = false;

  this.tick = function () 
  {
  	_moved = false;
	  _val1 = b.digitalRead(_inputPin1);
	  _val2 = b.digitalRead(_inputPin2);

	  // console.log('_val1: ' + _val1);
	  // console.log('_val2: ' + _val2);

	  if ( _val1 != _oldVal1 || _val2 != _oldVal2) 
	  {
	    _oldVal1 = _val1;
	    _oldVal2 = _val2;
	    
	    //for each pair there's a position out of four
	    if ( _val1 == 1 ) 
	    {// stationary position
	      if (_val2 == 1)
	      {
	        _pos = 0;
	      }
	      else if (_val2 == 0)
	      {
	        _pos = 3;
	      }
	    } 
	    else if (_val1 == 0)
	    {
	      if (_val2 == 1)
	      {
	        _pos = 1;
	      }
	      else if (_val2 == 0)
	      {
	        _pos = 2;
	      }
	    }
	    
	    console.log(_pos);
	    console.log(_val1 + ", " + _val2)
	    
	    _turn = _pos - _oldPos;
	    _oldPos = _pos;
	    if (Math.abs(_turn) != 2) 
	    {
	      if (_turn == 1 || _turn == -3) { _turnCount++; }
	      else if (_turn == -1 || _turn == 3) { _turnCount--; }
	    }
	    
	    if (_pos == 0)
	    { 
	      if (_turnCount > 0)
	      {
	        _turnCount = 0;
					_moved = true;
	        return '>';
	      } 
	      else if (_turnCount < 0)
	      {
	      	_moved = true;
	        _turnCount=0;
	        return '<';
	      } 
	    }
	    else 
	    {
				_moved = false;
	      _turnCount = 0;
	      return '-';
	    }
  	}
  	else 
    {
			_moved = false;
      _turnCount = 0;
      return '-';
    }
  }
}

module.exports.QuadEncoder = QuadEncoder;