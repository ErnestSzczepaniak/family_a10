#ifdef build_platform_host

#define CATCH_CONFIG_MAIN
#include "build.h"
#include "test.h"

#else

#include "build.h"
#include "alt_ethernet.h"
#include "alt_watchdog.h"

struct [[gnu::packed]] Packet
{
    unsigned char destination[6];
    unsigned char source[6];
    unsigned short int type;
}; /* structure: Packet */

void delay()
{
    for (int i = 0; i < 100000; i++)
    {
        
    }
    
}

int main()
{
    alt_wdog_stop(ALT_WDOG1);

    alt_eth_emac_instance_t emac;

    emac.instance = 0;

    Packet packet;

    //7c0 control

    unsigned char rx[4096];
    uint32_t len;

    auto result = alt_eth_dma_mac_config(&emac);

    while(1)
    {
        // result = alt_eth_send_packet(ss, 60, 1, 1, &emac);

        result = alt_eth_get_packet(rx, &len, &emac);

        delay();
    }
    

    while(1);
}

#endif
