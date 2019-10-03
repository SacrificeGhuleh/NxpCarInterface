//
// Created by Richard Zvonek on 21-Nov-18.
//

#ifndef NXPCUPRASPI_NXPDEFINES_H
#define NXPCUPRASPI_NXPDEFINES_H

namespace nxpbc {

#define SERIAL_DATA_BUFF_SIZE 281
#define DATA_BUFF_SIZE SERIAL_DATA_BUFF_SIZE - 5
#define SERIAL_CONTROL_BUFF_SIZE 17
#define SERIAL_SETTING_BUFF_SIZE 17

#ifndef __TFC_H

#define CAMERA_LINE_LENGTH      128        // Number of camera pixels

#define PWM_MINMAX          1000      // -/+ range for PWM

#define SERVO_MINMAX        1000      // -/+ range for servo position

#define ADC_MAXVAL          0x0FFF      // Maximum value of analog sample from ADC
#define ANDATA_MINMAX        1000      // -/+ range for analog values (e.g. potentiometers)

#define SERVO_DEFAULT_CENTER    1500      // Center position of servo - pulse in microseconds
#define SERVO_DEFAULT_MAX_LR    200        // Default -/+ range of pulse width range
#define SERVO_MAX_LR        400        // Maximum -/+ allowed range of pulse width

#define PWM_DEFAULT_MAX        200        // Default value for maximal -/+ PWM duty cycle
#define PWM_MAX            500        // Maximal allowed -/+ PWM duty cycle
  
  // commands
#define CMD_DATA          1
#define CMD_SETTING          2
#define CMD_CONTROL          3

// protocol start and stop byte
#define STX              0x2
#define ETX              0x3

#endif

#define COM_PORT_NAME Settings::getInstance()->getComPortName().c_str()

#define COM_BAUD_RATE Settings::getInstance()->getComPortBaudRate()

#define COM_TIMEOUT Settings::getInstance()->getComPortTimeout()

#define CONTROL_PWM_MAX Settings::getInstance()->getControlPwmMax()

#define CONTROL_PWM_STEP Settings::getInstance()->getControlPwmStep()

#define CONTROL_DRIVE_MAX Settings::getInstance()->getControlDriveMax()

#define SERVO_CENTER Settings::getInstance()->getServoCenter()

#define SERVO_LR Settings::getInstance()->getServoLR()

#define CONTROL_TURN_RATIO Settings::getInstance()->getServoTurnRatio()

#define CONTROL_MAX_RATIO Settings::getInstance()->getServoMaxRatio()

#define CONST_ERROR Settings::getInstance()->getErrorConst()

#define CONST_DERIVATIVE Settings::getInstance()->getDerivativeConst()

#define CONST_INTEGRAL Settings::getInstance()->getIntegralConst()

#define COLOR_BLACK 0x00

#define COLOR_WHITE 0xff

#define COLOR_WHITE_ORIGINAL 0xfff

#define BLACK_COUNT 10

#define PREV_LINE_SEARCH_REGION Settings::getInstance()->getPrevLineSearchRegion()

#define SAVE_RAW Settings::getInstance()->getSaveRaw()

#define SAVE_NORM Settings::getInstance()->getSaveNorm()

#define SAVE_THRESH Settings::getInstance()->getSaveThresh()

#define SAVE_CSV Settings::getInstance()->getSaveCsv()

#define DELETE_AND_PARK(ptr)  if(\
    ptr != nullptr){\
    delete ptr;\
    ptr = nullptr;\
    }
}

#endif //NXPCUPRASPI_NXPDEFINES_H
