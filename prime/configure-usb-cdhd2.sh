#!/bin/sh

modprobe ftdi_sio
echo '24cb 0002' > /sys/bus/usb-serial/drivers/ftdi_sio/new_id


