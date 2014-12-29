


/*
         
   ________    _                                   __ 
  / ____/ /_  (_)___  ____  ___  _________  __  __/ /_
 / /   / __ \/ / __ \/ __ \/ _ \/ ___/ __ \/ / / / __/
/ /___/ / / / / /_/ / /_/ /  __/ /  / / / / /_/ / /_  
\____/_/ /_/_/ .___/ .___/\___/_/  /_/ /_/\__,_/\__/  
            /_/   /_/                                 
Visit us: www.chippernut.com
Written by:
Jon Gulbrandson
12/28/2014

Kudos to: 
Adafruit (www.adafruit.com)
Arduino (www.arduino.com)

RPM SIGNAL GENERATOR

This generates a square wave using the Arduino TONE command. 
The output is currently confiqured to Digital Pin #5. 
Wire this pin directly to the input of your SHIFT LIGHT TACH SIGNAL IN 
No Transistor is needed. 
                                                                      
*/

/*******************************************************
********              CONFIGURATION             ********
********                                        ********
********************************************************/

/* INSTRUCTIONS
Set your RPM lowpoint (RPM_MIN) to the lowest point, do not
go lower than 1000 RPM.  Set your RPM highpoint (RPM_MAX) to 
the redline of your vehicle. The SPEED variable is used for 
the speed at which the generator sweeps through the RPM range. 
A higher SPEED variable will result in a slower speed. Try to keep
this between (10 - 50).


*/

float RPM_MIN = 1000;
float RPM_MAX = 6500;
int SPEED = 15;



/*******************************************************
********               DEFINITIONS              ********
********                                        ********
********************************************************/


boolean accel = false;
int x;

/*******************************************************
********                  SETUP                 ********
********                                        ********
********************************************************/


void setup() {
pinMode(5, OUTPUT);  
RPM_MIN = (RPM_MIN / 20.6);
RPM_MAX = (RPM_MAX / 20.6);
x = RPM_MIN;
}


/*******************************************************
********                MAIN LOOP               ********
********                                        ********
********************************************************/

void loop() {

while (accel==false){
        x++;
        tone(5,x);
        delay(SPEED);
        if (x>RPM_MAX){accel=true;}
   }
while (accel==true){
         x--;
        tone(5,x);
        delay(SPEED); 
       if (x<RPM_MIN){accel=false;}
   }
}
