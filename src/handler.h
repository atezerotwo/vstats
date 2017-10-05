#ifndef HANDLER_H_INCLUDED
#define HANDLER_H_INCLUDED

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

#endif // HANDLER_H_INCLUDED
