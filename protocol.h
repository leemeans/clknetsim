/*
 * Copyright (C) 2010  Miroslav Lichvar <mlichvar@redhat.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "sysheaders.h"

#define MAX_REQ_SIZE 1024

#define REQ_REGISTER 1
#define REQ_GETTIME 2
#define REQ_SETTIME 3
#define REQ_ADJTIMEX 4
#define REQ_ADJTIME 5
#define REQ_SELECT 6
#define REQ_SEND 7
#define REQ_RECV 8
#define REQ_GETREFTIME 9

struct Request_header {
	long request;
};

struct Reply_empty {
	int pad;
};

struct Request_register {
	unsigned int node;
};

struct Reply_gettime {
	double time;
};

struct Request_settime {
	double time;
};

struct Request_adjtimex {
	struct timex timex;
};

struct Reply_adjtimex {
	int ret;
	int _pad;
	struct timex timex;
};

struct Request_adjtime {
	struct timeval tv;
};

struct Reply_adjtime {
	struct timeval tv;
};

struct Request_select {
	double timeout;
};

#define REPLY_SELECT_TIMEOUT 0
#define REPLY_SELECT_NORMAL 1
#define REPLY_SELECT_BROADCAST 2

struct Reply_select {
	int ret;
};

#define MAX_NTP_PACKETSIZE 1000

struct Request_send {
	unsigned int to;
	unsigned int len;
	char data[MAX_NTP_PACKETSIZE];
};

struct Reply_recv {
	unsigned int from;
	unsigned int len;
	char data[MAX_NTP_PACKETSIZE];
};

struct Reply_getreftime {
	double time;
	double offset;
	int valid;
	int _pad;
};

#endif