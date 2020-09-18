#include <stdio.h>
#include <stdbool.h>
#include <pcap.h>

char errbuf[PCAP_ERRBUF_SIZE];
int main() {
    struct pcap_pkthdr header;	/* The header that pcap gives us */
    const u_char *packet;		/* The actual packet */
    pcap_t* p = pcap_open_live("enp8s0", BUFSIZ, 1, 1000, errbuf);
    if (p == NULL) {
        perror("Could not open device for live capture");
        return -1;
    }

    printf("Hello World!\n");

    while (true) {
        packet = pcap_next(p, &header);
        printf("Got packet with len: (%d)\n", header.caplen);
    }
    
}