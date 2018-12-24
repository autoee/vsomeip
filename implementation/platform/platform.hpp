/**
 * AS - the open source Automotive Software on https://github.com/parai
 *
 * Copyright (C) 2018  AS <parai@foxmail.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */
#ifndef _PLATFORM_HPP_
#define _PLATFORM_HPP_

/* ============================ [ INCLUDES  ] ====================================================== */
#include <stdint.h>
#include <cstring>
namespace vsomeip {
namespace platform {
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */

class steady_timer
{
public:
	steady_timer() {}
};

class io_service {
public:
	io_service() {}
};

namespace ip {
class address {

public:
	address() {}

	friend bool operator!=(const address& a1, const address& a2)
	{
		return !(a1 == a2);
	}

	friend bool operator <(const address& a1, const address& a2) {
		return false;
	};

	friend bool operator ==(const address& a1, const address& a2) {
		if (a1.type_ != a2.type_)
			return false;
		return std::memcmp(a1.ip_address_, a2.ip_address_, 6);
	};
private:
	// The type of the address.
	enum { ipv4, ipv6 } type_;

	// The underlying IPv4 or IPv6 address.
	uint8_t ip_address_[6];
};

class udp_ext {
public:
	udp_ext() {}
};

class tcp {
	typedef int socket;
	typedef int endpoint;
public:
	tcp() {}
};

};
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
};};
#endif /* _PLATFORM_HPP_ */
