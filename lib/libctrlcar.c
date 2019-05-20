#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include "libctrlcar.h"

int lib_pwm_enable(unsigned int enable)
{
	int fd;
	fd = open("/sys/class/pwm/pwmchip0/pwm0/enable", O_WRONLY);
	if (fd < 0) {
		printf("failed to open enable file!\n");
		return -1;
	}
	if (enable) {
		if (write(fd, "1", 2)<0) {
			printf("failed to enable pwm0!\n");
			goto err;
		}
	}
	else {
		if (write(fd, "0", 2)<0) {
			printf("failed to disable pwm0!\n");
			goto err;
		}
	}
	return 0;
err:
	close(fd);
	return -1;
}

int lib_pwm_config(unsigned int period, unsigned int duty)
{
	int fd;
	int len_p, len_d;
	char buf_p[64], buf_d[64];
	if (access("/sys/class/pwm/pwmchip0/pwm0",F_OK)==-1) {
		fd = open("/sys/class/pwm/pwmchip0/export", O_WRONLY);
		if (fd < 0) {
			printf("failed to open export file!\n");
			return -1;
		}
		if (write(fd, "0", 2)<0) {
			printf("failed to export pwm0!\n");
			goto err;
		}
		close(fd);
	}
	fd = open("/sys/class/pwm/pwmchip0/pwm0/period", O_WRONLY);
	if (fd < 0) {
		printf("failed to open period file!\n");
		return -1;
	}
	len_p = snprintf(buf_p, sizeof(buf_p), "%d", period);
	if (write(fd, buf_p, len_p)<0) {
		printf("failed to config pwm0!\n");
		goto err;
	}
	close(fd);
	fd = open("/sys/class/pwm/pwmchip0/pwm0/duty_cycle", O_WRONLY);
	if (fd < 0) {
		printf("failed to open duty_cycle file!\n");
		return -1;
	}
	len_d = snprintf(buf_d, sizeof(buf_d), "%d", duty);
	if (write(fd, buf_d, len_d)<0) {
		printf("failed to config pwm0!\n");
		goto err;
	}
	close(fd);
	return 0;

err:
	close(fd);
	return -1;
}

int lib_ctrl_car(unsigned int cmd)
{
	int fd;
	fd = open("/dev/motor", O_WRONLY);
	if (fd < 0) {
		printf("failed to open motor device!\n");
		return -1;
	}
	if (ioctl(fd, cmd)<0) {
		printf("failed to ctrl motor!\n");
		close(fd);
		return -1;
	}
	close(fd);
	return 0;
}

int lib_motor_test(void)
{
	int i;
	pwm_config(6000000, 300000);
	pwm_enable(1);
	for (i=1;i<=11;i++) {
		if (i == 2)
			i++;
		lib_ctrl_car(i);
		sleep(2);
	}
	pwm_enable(0);
	lib_ctrl_car(0);
	return 0;
}
