#pragma once

#define CAMERA_LINE_LENGTH			128				// Number of camera pixels

#define PWM_MINMAX					1000			// -/+ range for PWM

#define SERVO_MINMAX				1000			// -/+ range for servo position

#define ADC_MAXVAL					0x0FFF			// Maximum value of analog sample from ADC
#define ANDATA_MINMAX				1000			// -/+ range for analog values (e.g. potentiometers)

#define SERVO_DEFAULT_CENTER		1500			// Center position of servo - pulse in microseconds
#define SERVO_DEFAULT_MAX_LR		200				// Default -/+ range of pulse width range
#define SERVO_MAX_LR				400				// Maximum -/+ allowed range of pulse width

#define PWM_DEFAULT_MAX				200				// Default value for maximal -/+ PWM duty cycle
#define PWM_MAX						500				// Maximal allowed -/+ PWM duty cycle

// commands
#define CMD_DATA					1
#define CMD_SETTING					2
#define CMD_CONTROL					3

// protocol start and stop byte
#define STX							0x2
#define ETX							0x3
#include "../../../CLionProjects/RemoteNxpCupRaspi/src/NxpSendFrame.h"

enum andata_chnl_enum { anPOT_1, anPOT_2, anFB_A, anFB_B, anBAT, anLast };

struct s_data {

    s_data() {
        timestamp = 0; // number of sample
        adc[anLast] = {0}; // ADC channels
        dip_sw = 0; // dip switches status
        push_sw = 0; // push buttons
        image[CAMERA_LINE_LENGTH] = {0}; // line camera image
        _padding = 0;
    }

    s_data(nxpbc::SendData data) {
        memcpy(image, data.image, sizeof(uint16_t) * CAMERA_LINE_LENGTH);
        memcpy(adc, data.adc, sizeof(uint16_t) * anLast);
    }

    s_data(s_data* oldData) {
        this->timestamp = oldData->timestamp;
        this->dip_sw = oldData->dip_sw;
        this->push_sw = oldData->push_sw;
        this->_padding = oldData->_padding;

        for (int i = 0; i < anLast; i++) {
            this->adc[i] = oldData->adc[i];
        }
        for (int i = 0; i < CAMERA_LINE_LENGTH; i++) {
            this->image[i] = oldData->image[i];
        }
    }

    uint32_t timestamp = 0; // number of sample
    uint16_t adc[anLast] = {0}; // ADC channels
    uint8_t dip_sw = 0; // dip switches status
    uint8_t push_sw = 0; // push buttons
    uint16_t image[CAMERA_LINE_LENGTH] = {0}; // line camera image
    uint32_t _padding = 0;

    float getVoltage() {
        return (static_cast<float>(adc[anBAT])) / static_cast<float>(ADC_MAXVAL) * 3.3f * 5.7f;
    }

	int32_t ReadPot_i(uint32_t Channel)
	{
		int val = adc[anPOT_1 + (Channel != 0)];
		return -(val * 2 * ANDATA_MINMAX / ADC_MAXVAL - ANDATA_MINMAX);
	}

	// return value in range <-1.0, 1.0>
	float ReadPot_f(uint32_t Channel)
	{
		return ((float)ReadPot_i(Channel)) / ANDATA_MINMAX;
	}

};

struct s_setting {
    s_setting() {
        servo_center[2] = {0}; // servos calibration
        servo_max_lr[2] = {0}; // servos range
        pwm_max = 0; // maximal PWM for motors
        _padding = 0;
    }

    s_setting(s_setting* oldData) {
        this->servo_center[0] = oldData->servo_center[0];
        this->servo_center[1] = oldData->servo_center[1];

        this->servo_max_lr[0] = oldData->servo_max_lr[0];
        this->servo_max_lr[1] = oldData->servo_max_lr[1];

        this->pwm_max = oldData->pwm_max;
        this->_padding = oldData->_padding;
    }

    uint16_t servo_center[2] = {0}; // servos calibration
    uint16_t servo_max_lr[2] = {0}; // servos range
    uint16_t pwm_max = 0; // maximal PWM for motors
    uint16_t _padding = 0;
};

struct s_control {
    s_control() {
        leds = 0; // four leds - low nibble
        pwm_onoff = 0; // enable motors <0,1>
        servo_onoff = 0; // enable servo <0,1>
        _padding1 = 0;
        pwm_a = 0, pwm_b = 0; // PWM of motors <-PWM_MINMAX, PWM_MINMAX>
        servo_pos[2] = {0}; // servos position <-SERVO_MAX_LR, SERVO_MAX_LR>
    }

    s_control(nxpbc::SendData data) {
        pwm_a = data.leftPwm;
        pwm_b = data.rightPwm;
        servo_pos[0] = servo_pos[1] = data.servo;
    }

    s_control(s_control* oldData) {
        this->leds = oldData->leds;
        this->pwm_onoff = oldData->pwm_onoff;
        this->servo_onoff = oldData->servo_onoff;
        this->_padding1 = oldData->_padding1;
        this->pwm_a = oldData->pwm_a;
        this->pwm_b = oldData->pwm_b;
        this->servo_pos[0] = oldData->servo_pos[0];
        this->servo_pos[1] = oldData->servo_pos[1];
    }

    uint8_t leds = 0; // four leds - low nibble
    uint8_t pwm_onoff = 0; // enable motors <0,1>
    uint8_t servo_onoff = 0; // enable servo <0,1>
    uint8_t _padding1 = 0;
    int16_t pwm_a = 0, pwm_b = 0; // PWM of motors <-PWM_MINMAX, PWM_MINMAX>
    int16_t servo_pos[2] = {0}; // servos position <-SERVO_MAX_LR, SERVO_MAX_LR>
};
