var l = require('./Looney.js');


function Player(songData)
{
	this.looneys = {
		new l.Looney1(Looney1ServoPin, Looney1MotorPin1, Looney1MotorPin2, Looney1QuadEncoderPin1, Looney1QuadEncoderPin2), 
		new l.Looney2(Looney2ServoPin, Looney2MotorPin1, Looney2MotorPin2, Looney2QuadEncoderPin1, Looney2QuadEncoderPin2), 
		new l.Looney3(Looney3ServoPin, Looney3MotorPin1, Looney3MotorPin2, Looney3QuadEncoderPin1, Looney3QuadEncoderPin2), 
		new l.Looney4(Looney4ServoPin, Looney4MotorPin1, Looney4MotorPin2, Looney4QuadEncoderPin1, Looney4QuadEncoderPin2)
	};

	// looney1MotorPin1 = 'P8_13';
	// looney1MotorPin2 = 'P8_14';

	// var servo = new s.Servo('P9_14');
	// var encoderPin1 = 'P8_5';
	// var encoderPin2 = 'P8_7';
	// var enc = new q.BetterQuadEncoder(encoderPin1, encoderPin2);

	// var encoderPin1 = 'P8_9';
	// var encoderPin2 = 'P8_11';
	// var motor = new q.Motor(encoderPin1, encoderPin2);

}

module.exports.Player = Player;