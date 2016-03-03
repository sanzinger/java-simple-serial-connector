/* © Stefan Anzinger 2015.
 *
 * This file is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this fil.  If not, see <http://www.gnu.org/licenses/>.
 *
 * If you use this file in public project you can inform me about this by e-mail,
 * of course if you want it.
 */
/**
 * This function must be compiled independent of jssc.cpp as there are collisions with the imports sys/termbits.h and termios.h
 */
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <asm/termbits.h>
#include <errno.h>

#include "setCustomBaudrate.hpp"
#include <jni.h>

bool setCustomBaudrate(jlong port, jint baud) {
	termios2 *info = new termios2();
	if(ioctl(port, TCGETS2, info)) {
		perror("Cannot get portinfo.");
		delete info;
		return true;
	}
	info->c_cflag &= ~CBAUD;
	info->c_cflag |= BOTHER;
	info->c_ispeed = baud;
	info->c_ospeed = baud;
	if(ioctl(port, TCSETS2, info)) {
		perror("Cannot set custom baudrate.");
		delete info;
		return true;
	}
	delete info;
	return false;
}
