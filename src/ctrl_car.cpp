#include <include/ctrl_car.hpp>
extern "C" {
#include <lib/libctrlcar.h>
}

int ctrl_car(int ctrl_car_cmd)
{
    if(ctrl_car_cmd<0 || ctrl_car_cmd>11) {
        printf("control cmd is error!\n");
        return -1;
    }
    else {
        switch(ctrl_car_cmd) {
        case IN_RIGHT:
            lib_ctrl_car(MOTOR_LEFT);
            break;
        case IN_LEFT:
            lib_ctrl_car(MOTOR_RIGHT);
            break;
        case IN_CENTER:
	    lib_ctrl_car(MOTOR_FORWARD);
            break;
        case NOT_FIND:
	    lib_ctrl_car(MOTOR_TURNLEFT);
            break;
        default:
	    lib_ctrl_car(MOTOR_STOP);
            break;
        }
    }
}

int motor_test(void)
{
    lib_motor_test();
    return 0;
}

int pwm_config(unsigned int period, unsigned int duty)
{
    lib_pwm_config(period, duty);
    return 0;
}

int pwm_enable(unsigned int enable)
{
    lib_pwm_enable(enable);
    return 0;
}
