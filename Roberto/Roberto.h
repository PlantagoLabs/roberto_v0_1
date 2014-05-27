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

#define LED 13

// servo motor positions
#define SERVO_ARM_LEFT_OPEN 60
#define SERVO_ARM_LEFT_HALF_OPEN 140
#define SERVO_ARM_LEFT_CLOSED 154
#define SERVO_ARM_RIGHT_OPEN 140
#define SERVO_ARM_RIGHT_CLOSED 35
#define SERVO_BOWTIE_CENTER 66
#define SERVO_BOWTIE_RIGHT SERVO_BOWTIE_CENTER + 20
#define SERVO_BOWTIE_LEFT SERVO_BOWTIE_CENTER - 20
#define SERVO_EAR_RIGHT_CENTER 90
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
#define TIME_DRIP_WAIT 5000
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

#define MODE_MANUAL 0
#define MODE_AUTOMATIC 1

// input pin definitions
#define INPUT_CUP          0
#define INPUT_FLOW         1
#define INPUT_BUTTON       10
#define INPUT_ARM_CONTACT  11

// output pin definitions
#define OUTPUT_PUMP        9
#define OUTPUT_EYE_LEFT_RED    A2
#define OUTPUT_EYE_LEFT_GREEN  A1
#define OUTPUT_EYE_LEFT_BLUE   A0
#define OUTPUT_EYE_RIGHT_RED    A5
#define OUTPUT_EYE_RIGHT_GREEN  A4
#define OUTPUT_EYE_RIGHT_BLUE   A3

// condition macros
#define COND_CUP_IS_PRESENT digitalRead(INPUT_CUP)
#define COND_ARMS_TOUCH digitalRead(INPUT_ARM_CONTACT)
#define COND_LIQUID_DETECT digitalRead(INPUT_FLOW)
#define COND_BUTTON_PRESSED digitalRead(INPUT_BUTTON)

// othe macros
#define MACRO_PUMP_ON digitalWrite(OUTPUT_PUMP, HIGH)
#define MACRO_PUMP_OFF digitalWrite(OUTPUT_PUMP, LOW)
#define LED_ON digitalWrite(LED, HIGH)
#define LED_OFF digitalWrite(LED, LOW)

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

#endif

