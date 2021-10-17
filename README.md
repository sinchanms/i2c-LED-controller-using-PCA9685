# i2c_PCA9685

Abstract:

The I2C LED controllers enable core functions in some of today’s most ubiquitous devices and
applications, in cellular handsets, LED blinkers and dimmers control LED back-lit keypads and LCD
screens, party lighting, status indicators and so on. They are also deployed in advanced applications such
as illumination control while off-loading host processors in LCD displays. These I2C LED controllers work
with I2C interfaces such as RGB or RGBA LED drivers.

The I2C-bus is a standard bi-directional interface that uses a controller, known as the master, to
communicate with slave devices. A slave may not transmit data unless it has been addressed by the
master. Each device on the I2C bus has a specific device address to differentiate between other devices
that are on the same I2C bus.

The PCA9685 is an I²C-bus controlled 16-channel LED controller optimized for Red/Green/Blue/Amber
(RGBA) color backlighting applications. Each LED output has its own 12-bit resolution (4096 steps) fixed
frequency individual PWM controller that operates at a programmable frequency from a typical of 24 Hz
to 1526 Hz with a duty cycle that is adjustable from 0 % to 100 % to allow the LED to be set to a specific
brightness value. All outputs are set to the same PWM frequency. The LED driver will be controlled by an
ATMEGA Series board which will act as an I2C master device.
Using this design various patterns are generated with different color combination.
