var b = require('bonescript');
var c = require('./Constants.js');



function Servo (servoPin) 
{
	var _servoPin = servoPin;
	var _position = 0;
	var _increment = 0.1;

	b.pinMode(servoPin, b.OUTPUT);

	this.SetPosition = function (newPos)
	{
		if (newPos < 0 || newPos > 1) { return; }

		_UpdateDuty (newPos);
	}

	var _UpdateDuty = function (newPos)
	{
		var dutyCycle = (_position * 0.97) + c.DUTY_CYCLE_MIN;
		b.analogWrite(_servoPin, dutyCycle, c.SERVO_WRITE_FREQ, _ScheduleNextUpdate);
	}

	/* Responsible for incrementally scheduling servo moves until the servo has
	 * reached the desired position
	 *
	 */
	var _ScheduleNextUpdate = function ()
	{
		_position = _position + _increment;

    if (_position < 0) 
    {
        _position = 0;
        _increment = -_increment;
    } 
    else if (_position > 1) 
    {
        _position = 1;
        _increment = -_increment;
    }
    
    // call updateDuty after 100ms
    setTimeout(_UpdateDuty, 100);
	}
}

module.exports.Servo = Servo;