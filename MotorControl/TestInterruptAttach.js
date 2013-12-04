var b = require('bonescript');
var inputPin = 'P8_7';
b.pinMode(inputPin, b.INPUT);
b.attachInterrupt(inputPin, true, b.CHANGE, interruptCallback);
setTimeout(detach, 12000);

function interruptCallback(x) {
    console.log(JSON.stringify(x));
}

function detach() {
    b.detachInterrupt(inputPin);
    console.log('Interrupt detached');
}