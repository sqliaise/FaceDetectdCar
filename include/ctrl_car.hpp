#ifndef CTRL_CAR_HPP_INCLUDED
#define CTRL_CAR_HPP_INCLUDED

#include <include/detect_face.hpp>

int ctrl_car(int);
int motor_test(void);
int pwm_config(unsigned int period, unsigned int duty);
int pwm_enable(unsigned int enable);

#endif // CTRL_CAR_HPP_INCLUDED
