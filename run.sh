#!/bin/bash
# while :; do afplay /path/to/song.mp3; done
while :
do
    ./arduino-serial/arduino-serial -b 9600 -p /dev/tty.usbmodem1421 -r | grep "read"
done
