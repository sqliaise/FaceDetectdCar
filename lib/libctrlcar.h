#define MOTOR_STOP       0
#define MOTOR_FORWARD    1
#define NOT_USED	 2
#define MOTOR_BACK       3
#define MOTOR_LEFT       4
#define MOTOR_RIGHT      5
#define MOTOR_LEFTFO     6
#define MOTOR_RIGHTBA    7
#define MOTOR_RIGHTFO    8
#define MOTOR_LEFTBA     9
#define MOTOR_TURNLEFT   10
#define MOTOR_TURNRIGHT  11

extern int lib_pwm_enable(unsigned int enable);
extern int lib_pwm_config(unsigned int period, unsigned int duty);
extern int lib_ctrl_car(unsigned int cmd);
extern int lib_motor_test(void);

