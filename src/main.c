#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include "config_vlan.h"
#include "handler.h"
#include <string.h>
#include <curl/curl.h>

#define FILENAME "/opt/vlanstats/vlanstats.conf"

//#define netmask "PCAP_NETMASK_UNKNOWN"

CURL *curl;
CURLcode res;




int main(void)
{
    /*config stuff*/
    struct config options;
    options = get_config(FILENAME);

    /*pcap stuff*/
    pcap_t *adhandle = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev = options.ethdevname;
    char packet_filter[] = "vlan";
    struct bpf_program filtercode;

    //printf("Device: %s\n", dev);

    adhandle = pcap_open_live(dev, 72, 1, 1000, errbuf);


    if(adhandle == NULL)
    {
		fprintf(stderr, "\nUnable to open the adapter. it is not supported by libpcap\n");
		fprintf(stderr, errbuf);
		/* Free the device list */
		//pcap_freealldevs(alldevs);
		return -1;
	}


    //compile the filter
	if (pcap_compile(adhandle, &filtercode, packet_filter, 1, PCAP_NETMASK_UNKNOWN) <0)
	{
		fprintf(stderr, "\nUnable to compile the packet filter. Check the syntax.\n");
		//pcap_freealldevs(alldevs);
		return -1;
	}

    if (pcap_setfilter(adhandle, &filtercode)<0)
	{
		fprintf(stderr, "\nError setting the filter.\n");
		/* Free the device list */
		//pcap_freealldevs(alldevs);
		return -1;
	}

	printf("started on %s ...\n", dev);
    pcap_loop(adhandle, 0, packet_handler, NULL);

    return 0;
}


