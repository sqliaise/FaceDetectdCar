# README.md
***
## Note:
* The software runs on the **Raspberry Pi 3 Model B** and guides the car through the camera. 
* It needs to be combined with the driver of the Mecanum wheel. 
* Driver source code in **driver** path. 
* The driver uses the Raspberry Pi gpio **5,12,13,16,19,20,26,21** to control the motor steering 
    and the gpio18 to output PWM to control the motor speed. 
***
## About Build:
* Use **make** to compile this software. 
* Replace the corresponding **DTS** file in the kernel and compile the driver to the kernel. 
***
## About environment: 
* You need to compile and install **opencv3.0.0** firstly. 
***
## About run: 
* Modify the **LD_LIBRARY_PATH** and **fdc_start** path in the **init/fdc_run.sh** file. 
* Then run the script. 
