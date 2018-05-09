#include "NetModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/route.h>

NetModule::NetModule(void) :
IMonitorModule("Net", mt_table)
{
	_strings = std::vector<std::string>(1);
	_data = std::vector<double>(2);
	_strings[0] = "Network kb In/Out";
}

NetModule::~NetModule(void) {}
NetModule& NetModule::operator=(const NetModule&) { return *this; }
NetModule::NetModule(const NetModule& r) { *this = r; }
void NetModule::update(void)
{
	int mib[] = {
		CTL_NET,
		PF_ROUTE,
		0,
		0,
		NET_RT_IFLIST2,
		0
	};
	size_t len;
	sysctl(mib, 6, NULL, &len, NULL, 0);
	char *buf = (char *)malloc(len);
	sysctl(mib, 6, buf, &len, NULL, 0);
	char *lim = buf + len;
	char *next = NULL;
	u_int64_t totalibytes = 0;
	u_int64_t totalobytes = 0;
	for (next = buf; next < lim; ) {
		struct if_msghdr *ifm = (struct if_msghdr *)next;
		next += ifm->ifm_msglen;
		if (ifm->ifm_type == RTM_IFINFO2) {
			struct if_msghdr2 *if2m = (struct if_msghdr2 *)ifm;
			totalibytes += if2m->ifm_data.ifi_ibytes;
			totalobytes += if2m->ifm_data.ifi_obytes;
		}
	}
	_data[0] = totalibytes / 1024;
	_data[1] = totalobytes / 1024;
}
