/***************************************************************************************
 *
 * Title:       Roberto, the pastis serving robot
 * Version:     v1.0
 * Date:        2014-05-27
 * Author:      Karl Kangur <karl.kangur@gmail.com>
 * Website:     https://github.com/Robopoly/Roberto
 * Licence:     LGPL
 *
 ***************************************************************************************/
#ifndef ROBERTO_H
#define ROBERTO_H



// servo motor positions
#define SERVO_ARM_LEFT_OPEN 60
#define SERVO_ARM_LEFT_HALF_OPEN 140
#define SERVO_ARM_LEFT_CLOSED 152 // was 154
#define SERVO_ARM_RIGHT_OPEN 140
#define SERVO_ARM_RIGHT_CLOSED 38 // was 35
#define SERVO_BOWTIE_CENTER 66
#define SERVO_BOWTIE_RIGHT SERVO_BOWTIE_CENTER + 20
#define SERVO_BOWTIE_LEFT SERVO_BOWTIE_CENTER - 20
#define SERVO_EAR_RIGHT_CENTER 70
#define SERVO_EAR_RIGHT_FORWARDS SERVO_EAR_RIGHT_CENTER + 30
#define SERVO_EAR_RIGHT_BACK SERVO_EAR_RIGHT_CENTER - 30
#define SERVO_EAR_LEFT_CENTER 100
#define SERVO_EAR_LEFT_FORWARDS SERVO_EAR_LEFT_CENTER - 30
#define SERVO_EAR_LEFT_BACK SERVO_EAR_LEFT_CENTER + 30

#define SERVO_ARM_SPEED 20

// timing constants
#define TIME_WAIT_AFTER_CUP_INSERT 1000
#define TIME_BOWTIE_TOGGLE 500
#define TIME_BOWTIEMOVE 2000
#define TIME_LIQUID_SENSOR_REACH 2000
#define TIME_DRIP_WAIT 10000
#define TIME_WAIT_AFTER_CUP_REMOVE 2000
#define TIME_LCD_UPDATE 2000
#define TIME_LED_DISCO 200
#define TIME_HEARTBEAT 1000
#define TIME_EAR_MOVE_IDLE 1000
#define TIME_EAR_MOVE_CUP_REMOVE 5000
#define TIME_EAR_MOVE_CUP_REMOVE_STEP 200
#define TIME_DISCO_MODE 20000
#define TIME_DISCO_DURATION 1000

// eeprom addresses
#define EEPROM_POURING_TIME 0 // 0 and 1
#define EEPROM_PUMP_ACTIVATION 2 // 2 and 3
#define EEPROM_MODE 4 // 0 = manual, 1 = automatic
#define EEPROM_TYPE 5 // 0 = Ricard, 1 = Syrup

#define TYPE_RICARD 0
#define TYPE_SYRUP 1
#define TYPE_COCKTAILS 2                    // !!!


#define MODE_MANUAL 0
#define MODE_AUTOMATIC 1

// input pin definitions
//#define INPUT_CUP                    // need to change to be a value for the load cell
//#define INPUT_FLOW         
#define INPUT_BUTTON_1        10         // need to change to have two buttons
#define INPUT_BUTTON_2      11         // need to change to have two buttons             // !!!
#define INPUT_ARM_CONTACT   0
#define INPUT_SCALE_DAT     13          // need to change to have
#define INPUT_SCALE_CLK     12          // need to change to have

// output pin definitions
#define OUTPUT_PUMP_1             9
#define OUTPUT_PUMP_2           1
#define OUTPUT_EYE_LEFT_RED     A3 // was A2
#define OUTPUT_EYE_LEFT_GREEN   A4 // was A1
#define OUTPUT_EYE_LEFT_BLUE    A5

#define OUTPUT_EYE_RIGHT_RED    A0 // was A5
#define OUTPUT_EYE_RIGHT_GREEN  A1 // was A4
#define OUTPUT_EYE_RIGHT_BLUE   A2

#define OUTPUT_SERVO_ARM_LEFT 4
#define OUTPUT_SERVO_ARM_RIGHT 5
#define OUTPUT_SERVO_BOWTIE 6
#define OUTPUT_SERVO_LEFT_EAR 7
#define OUTPUT_SERVO_RIGHT_EAR 8


// condition macros
#define SCALE_VALUE             scale.get_units()
#define MIN_VAL_MASS_CUP_DETEC  10.0f                         //Mass of PP Cup
#define MAX_POURED_WEIGHT         250
#define DEFAULT_POURED_WEIGHT      150                       //Mass in gram 
///#define COND_CUP_IS_PRESENT  digitalRead(INPUT_CUP)          // need to change. 

#define COND_ARMS_TOUCH digitalRead(INPUT_ARM_CONTACT)

#define COND_LIQUID_DETECT digitalRead(INPUT_FLOW)          // need to change, no flow detector  ///!!!
#define COND_BUTTON_1_PRESSED !digitalRead(INPUT_BUTTON_1) 
#define COND_BUTTON_2_PRESSED !digitalRead(INPUT_BUTTON_2)

// other macros
#define MACRO_PUMP_1_ON digitalWrite(OUTPUT_PUMP_1, HIGH)
#define MACRO_PUMP_1_OFF digitalWrite(OUTPUT_PUMP_1, LOW)
#define MACRO_PUMP_2_ON digitalWrite(OUTPUT_PUMP_2, HIGH)
#define MACRO_PUMP_2_OFF digitalWrite(OUTPUT_PUMP_2, LOW)
//#define LED_ON digitalWrite(LED, HIGH)
//#define LED_OFF digitalWrite(LED, LOW)

enum state_codes
{
  STATE_WAITING_CUP,
  STATE_MOVING_ARMS_IN,
  STATE_POURING,
  STATE_MOVING_RIGHT_ARM_OUT,
  STATE_REMOVE_CUP,
  STATE_MOVING_ARMS_OUT
};

enum return_codes
{
  OK,
  FAIL,
  REPEAT
};

#define ENTRY_STATE STATE_WAITING_CUP

  return_codes stateWaitingCup();
  return_codes stateMovingArmsIn();
  return_codes statePouring();
  return_codes stateMovingRightArmOut();
  return_codes stateRemoveCup();
  return_codes stateMovingArmsOut();

#endif
