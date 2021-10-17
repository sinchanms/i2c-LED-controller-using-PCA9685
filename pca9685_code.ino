/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  PWM test - this will drive 16 PWMs in a 'wave'

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These drivers use I2C to communicate, 2 pins are required to  
  interface.

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);
int i;
void setup() {
  Serial.begin(9600);
  Serial.println("16 channel PWM test!");

  pwm.begin();
  /*
   * In theory the internal oscillator (clock) is 25MHz but it really isn't
   * that precise. You can 'calibrate' this by tweaking this number until
   * you get the PWM update frequency you're expecting!
   * The int.osc. for the PCA9685 chip is a range between about 23-27MHz and
   * is used for calculating things like writeMicroseconds()
   * Analog servos run at ~50 Hz updates, It is importaint to use an
   * oscilloscope in setting the int.osc frequency for the I2C PCA9685 chip.
   * 1) Attach the oscilloscope to one of the PWM signal pins and ground on
   *    the I2C PCA9685 chip you are setting the value for.
   * 2) Adjust setOscillatorFrequency() until the PWM update frequency is the
   *    expected value (50Hz for most ESCs)
   * Setting the value here is specific to each individual I2C PCA9685 chip and
   * affects the calculations for the PWM update frequency. 
   * Failure to correctly set the int.osc value will cause unexpected PWM results
   */
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(60);  // This is the maximum PWM frequency

  // if you want to really speed stuff up, you can go into 'fast 400khz I2C' mode
  // some i2c devices dont like this so much so if you're sharing the bus, watch
  // out for this!
  Wire.setClock(400000);
}

void loop() {
  ledoneRed();
  ledtwoRed();
  ledthreeRed();
  ledfourRed();
  ledfiveRed();
  delay(1000);
  ledoneBlue();
  ledtwoBlue();
  ledthreeBlue();
  ledfourBlue();
  ledfiveBlue();
  delay(1000);
  ledoneGreen();
  ledtwoGreen();
  ledthreeGreen();
  ledfourGreen();
  ledfiveGreen();
  delay(1000);
  redPwm();
  greenPwm();
  bluePwm();
  purplePwm();
  yellowPwm();
  ledoffAll();
  delay(200);
  white();
  delay(1000);
  randomblink();
  delay(100);
} 


void ledoneYellow(){
  pwm.setPWM(0, 4096,0 ); // red
  pwm.setPWM(1,0 ,4096 ); // blue
  pwm.setPWM(2, 4096,0 ); // green
}

void ledoneRed(){
  pwm.setPWM(0, 4096,0 ); // red
  pwm.setPWM(1,0 ,4096 ); // blue
  pwm.setPWM(2, 0,4096 ); // green
}

void ledoneGreen(){
  pwm.setPWM(2, 4096,0 );
  pwm.setPWM(0,0 ,4096 );
  pwm.setPWM(1, 0,4096 );
}

void ledoneBlue(){
  pwm.setPWM(1, 4096,0 );
  pwm.setPWM(2,0 ,4096 );
  pwm.setPWM(0, 0,4096 );
}

void ledonePurple(){
  pwm.setPWM(0, 4096,0 ); // red
  pwm.setPWM(1,4096,0  ); // blue
  pwm.setPWM(2, 0,4096 ); // green
}


void ledtwoPurple(){
  pwm.setPWM(3, 4096,0 ); // red
  pwm.setPWM(5,4096,0  ); // blue
  pwm.setPWM(4, 0,4096 ); // green
}


void ledtwoYellow(){
  pwm.setPWM(3, 4096,0 ); // red
  pwm.setPWM(5,0 ,4096 ); // blue
  pwm.setPWM(4, 4096,0 ); // green
}

void ledtwoRed(){
  pwm.setPWM(3, 4096,0 ); //red
  pwm.setPWM(4,0 ,4096 ); // green
  pwm.setPWM(5, 0,4096 ); // blue
}

void ledtwoGreen(){
  pwm.setPWM(4, 4096,0 );
  pwm.setPWM(3,0 ,4096 );
  pwm.setPWM(5, 0,4096 );
}

void ledtwoBlue(){
  pwm.setPWM(5, 4096,0 );
  pwm.setPWM(3,0 ,4096 );
  pwm.setPWM(4, 0,4096 );
}

void ledthreeYellow(){
  pwm.setPWM(6, 4096,0 ); // red
  pwm.setPWM(7,0 ,4096 ); // blue
  pwm.setPWM(8, 4096,0 ); // green
}

void ledthreePurple(){
  pwm.setPWM(6, 4096,0 ); // red
  pwm.setPWM(7,4096,0  ); // blue
  pwm.setPWM(8, 0,4096 ); // green
}

void ledthreeRed(){
  pwm.setPWM(6, 4096,0 );
  pwm.setPWM(7,0 ,4096 );
  pwm.setPWM(8, 0,4096 );
}

void ledthreeGreen(){
  pwm.setPWM(8, 4096,0 );
  pwm.setPWM(6,0 ,4096 );
  pwm.setPWM(7, 0,4096 );
}

void ledthreeBlue(){
  pwm.setPWM(7, 4096,0 );
  pwm.setPWM(6,0 ,4096 );
  pwm.setPWM(8, 0,4096 );
}

void ledfourYellow(){
  pwm.setPWM(9, 4096,0 ); // red
  pwm.setPWM(11,0 ,4096 ); // blue
  pwm.setPWM(10, 4096,0 ); // green
}

void ledfourPurple(){
  pwm.setPWM(9, 4096,0 ); // red
  pwm.setPWM(11,4096,0  ); // blue
  pwm.setPWM(10, 0,4096 ); // green
}

void ledfourRed(){
  pwm.setPWM(9, 4096,0 );
  pwm.setPWM(10,0 ,4096 );
  pwm.setPWM(11, 0,4096 );
}

void ledfourGreen(){
  pwm.setPWM(10, 4096,0 );
  pwm.setPWM(9,0 ,4096 );
  pwm.setPWM(11, 0,4096 );
}

void ledfourBlue(){
  pwm.setPWM(11, 4096,0 );
  pwm.setPWM(9,0 ,4096 );
  pwm.setPWM(10, 0,4096 );
}


void ledfivePurple(){
  pwm.setPWM(12, 4096,0 ); // red
  pwm.setPWM(14,4096,0  ); // blue
  pwm.setPWM(13, 0,4096 ); // green
}

void ledfiveYellow(){
  pwm.setPWM(12, 4096,0 ); // red
  pwm.setPWM(14,0 ,4096 ); // blue
  pwm.setPWM(13, 4096,0 ); // green
}

void ledfiveRed(){
  pwm.setPWM(12, 4096,0 );
  pwm.setPWM(13,0 ,4096 );
  pwm.setPWM(14, 0,4096 );
}

void ledfiveGreen(){
  pwm.setPWM(13, 4096,0 );
  pwm.setPWM(12,0 ,4096 );
  pwm.setPWM(14, 0,4096 );
}

void ledfiveBlue(){
  pwm.setPWM(14, 4096,0 );
  pwm.setPWM(12,0 ,4096 );
  pwm.setPWM(13, 0,4096 );
}

void redPwm(){
  for(int i=0;i<4096;i=i+10)
  {
    pwm.setPWM(0, 0,i );
    pwm.setPWM(3, 0,i );
    pwm.setPWM(6, 0,i );
    pwm.setPWM(9, 0,i );
    pwm.setPWM(12, 0,i );
    ledoffGreen();
    ledoffBlue();
    delay(1);
  }
  delay(1000);
  for(int i=4096;i>0;i=i-10)
  {
    pwm.setPWM(0, 0,i );
    pwm.setPWM(3, 0,i );
    pwm.setPWM(6, 0,i );
    pwm.setPWM(9, 0,i );
    pwm.setPWM(12, 0,i );
    ledoffGreen();
    ledoffBlue();
    delay(1);
  }
}

void yellowPwm(){
  for(int i=0;i<4096;i=i+10)
  {
    pwm.setPWM(0, 0,i );
    pwm.setPWM(3, 0,i );
    pwm.setPWM(6, 0,i );
    pwm.setPWM(9, 0,i );
    pwm.setPWM(12, 0,i );
    pwm.setPWM(2, 0,i );
    pwm.setPWM(4, 0,i );
    pwm.setPWM(8, 0,i );
    pwm.setPWM(10, 0,i );
    pwm.setPWM(13, 0,i );
    ledoffBlue();
    delay(1);
  }
  delay(1000);
  for(int i=4096;i>0;i=i-10)
  {
    pwm.setPWM(0, 0,i );
    pwm.setPWM(3, 0,i );
    pwm.setPWM(6, 0,i );
    pwm.setPWM(9, 0,i );
    pwm.setPWM(12, 0,i );
    pwm.setPWM(2, 0,i );
    pwm.setPWM(4, 0,i );
    pwm.setPWM(8, 0,i );
    pwm.setPWM(10, 0,i );
    pwm.setPWM(13, 0,i );
    ledoffBlue();
    delay(1);
  }
}

void bluePwm(){
  for(int i=0;i<4096;i=i+10)
  {
    pwm.setPWM(1, 0,i );
    pwm.setPWM(5, 0,i );
    pwm.setPWM(7, 0,i );
    pwm.setPWM(11, 0,i );
    pwm.setPWM(14, 0,i );
    ledoffGreen();
    ledoffRed();
    delay(1);
  }
  delay(1000);
  for(int i=4096;i>0;i=i-10)
  {
    pwm.setPWM(1, 0,i );
    pwm.setPWM(5, 0,i );
    pwm.setPWM(7, 0,i );
    pwm.setPWM(11, 0,i );
    pwm.setPWM(14, 0,i );
    ledoffGreen();
    ledoffRed();
    delay(1);
  }
}


void greenPwm(){
  for(int i=0;i<4096;i=i+10)
  {
    pwm.setPWM(2, 0,i );
    pwm.setPWM(4, 0,i );
    pwm.setPWM(8, 0,i );
    pwm.setPWM(10, 0,i );
    pwm.setPWM(13, 0,i );
    ledoffBlue();
    ledoffRed();
    delay(1);
  }
  delay(1000);
  for(int i=4096;i>0;i=i-10)
  {
    pwm.setPWM(2, 0,i );
    pwm.setPWM(4, 0,i );
    pwm.setPWM(8, 0,i );
    pwm.setPWM(10, 0,i );
    pwm.setPWM(13, 0,i );
    ledoffBlue();
    ledoffRed();
    delay(1);
  }
}


void purplePwm(){
  for(int i=0;i<4096;i=i+10)
  {
    pwm.setPWM(0, 0,i );
    pwm.setPWM(3, 0,i );
    pwm.setPWM(6, 0,i );
    pwm.setPWM(9, 0,i );
    pwm.setPWM(12, 0,i );
    pwm.setPWM(1, 0,i );
    pwm.setPWM(5, 0,i );
    pwm.setPWM(7, 0,i );
    pwm.setPWM(11, 0,i );
    pwm.setPWM(14, 0,i );
    ledoffGreen();
    delay(1);
  }
  delay(1000);
  for(int i=4096;i>0;i=i-10)
  {
    pwm.setPWM(0, 0,i );
    pwm.setPWM(3, 0,i );
    pwm.setPWM(6, 0,i );
    pwm.setPWM(9, 0,i );
    pwm.setPWM(12, 0,i );
    pwm.setPWM(1, 0,i );
    pwm.setPWM(5, 0,i );
    pwm.setPWM(7, 0,i );
    pwm.setPWM(11, 0,i );
    pwm.setPWM(14, 0,i );
    ledoffGreen();
    delay(1);
  }
}

void ledoffAll(){
  pwm.setPWM(0, 0, 4096 );
  pwm.setPWM(1,0 ,4096 );
  pwm.setPWM(2, 0,4096 );
  pwm.setPWM(3, 0, 4096 );
  pwm.setPWM(4,0 ,4096 );
  pwm.setPWM(5, 0,4096 );
  pwm.setPWM(6, 0, 4096 );
  pwm.setPWM(7,0 ,4096 );
  pwm.setPWM(8, 0,4096 );
  pwm.setPWM(9, 0, 4096 );
  pwm.setPWM(10,0 ,4096 );
  pwm.setPWM(11, 0,4096 );
  pwm.setPWM(12, 0, 4096 );
  pwm.setPWM(13,0 ,4096 );
  pwm.setPWM(14, 0,4096 );
  
}

void ledoffRed(){
  pwm.setPWM(0, 0, 4096 );
  pwm.setPWM(3, 0, 4096 );
  pwm.setPWM(6, 0, 4096 );
  pwm.setPWM(9, 0, 4096 );
  pwm.setPWM(12, 0, 4096 );
  
}

void ledoffBlue(){
  pwm.setPWM(1, 0, 4096 );
  pwm.setPWM(5, 0, 4096 );
  pwm.setPWM(7, 0, 4096 );
  pwm.setPWM(11, 0, 4096 );
  pwm.setPWM(14, 0, 4096 );
  
}

void ledoffGreen(){
  pwm.setPWM(2, 0, 4096 );
  pwm.setPWM(4, 0, 4096 );
  pwm.setPWM(8, 0, 4096 );
  pwm.setPWM(10, 0, 4096 );
  pwm.setPWM(13, 0, 4096 );
  
}

void white()
{
  pwm.setPWM(0,4096,0 );
  pwm.setPWM(3,4096 ,0);
  pwm.setPWM(6,4096,0);
  pwm.setPWM(9,4096,0 );
  pwm.setPWM(12,4096,0);
  
  pwm.setPWM(1, 4096,0 );
  pwm.setPWM(5, 4096,0 );
  pwm.setPWM(7,4096,0);
  pwm.setPWM(11,4096,0 );
  pwm.setPWM(14, 4096,0 );
  
  pwm.setPWM(2, 4096,0 );
  pwm.setPWM(4, 4096,0 );
  pwm.setPWM(8, 4096,0 );
  pwm.setPWM(10, 4096,0);
  pwm.setPWM(13,4096,0);
}

void randomblink()
{
/* for(int z=0;z<5;z++)
 {
  for (uint16_t i=0; i<4096; i += 8) {
    for (uint8_t pwmnum=0; pwmnum < 16; pwmnum++) {
      pwm.setPWM(pwmnum, 0, (i + (4096/16)*pwmnum) % 4096 );
    }
}
 }*/
 for(int i=0;i<30;i++)
 {
 ledoneRed();
 ledtwoBlue();
 ledthreeGreen();
 ledfourPurple();
 ledfiveYellow();
 delay(100);
 ledoneYellow();
 ledtwoRed();
 ledthreeBlue();
 ledfourGreen();
 ledfivePurple();
 delay(100);
 ledonePurple();
 ledtwoYellow();
 ledthreeRed();
 ledfourBlue();
 ledfiveGreen();
 delay(100);
 ledoneGreen();
 ledtwoPurple();
 ledthreeYellow();
 ledfourRed();
 ledfiveBlue();
 delay(100);
 ledoneBlue();
 ledtwoBlue();
 ledthreeGreen();
 ledfourPurple();
 ledfiveYellow();
 }
}
