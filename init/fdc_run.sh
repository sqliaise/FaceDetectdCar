#!/bin/bash
export LD_LIBRARY_PATH=/home/pi/workspace/project/facedetectdcar/lib:$LD_LIBRARY_PATH
case $1 in
	stop)
		killall -9 fdc_start
		;;
	*)
		cd /home/pi/workspace/project/facedetectdcar/
		./fdc_start
		;;
esac
