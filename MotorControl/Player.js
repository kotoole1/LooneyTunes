var l = require('./Looney.js');


function Player(songData)
{
	this.looneys = {new l.Looney(), new l.Looney(), new l.Looney(), new l.Looney()};

	looney1MotorPin1 = 'P8_13';
	looney1MotorPin2 = 'P8_14';

	var servo = new s.Servo('P9_14');
	var encoderPin1 = 'P8_5';
	var encoderPin2 = 'P8_7';
	var enc = new q.BetterQuadEncoder(encoderPin1, encoderPin2);

	var encoderPin1 = 'P8_9';
	var encoderPin2 = 'P8_11';
	var enc = new q.Motor(encoderPin1, encoderPin2);

}

module.exports.Player = Player;