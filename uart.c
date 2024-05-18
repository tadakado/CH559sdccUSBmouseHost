
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "CH559.h"
#include "util.h"
#include "uart.h"

uint8_t __xdata uartRxBuff[64];
uint8_t __xdata rxPos = 0;


void processUart(){
    while(RI){
            RI=0;
            uartRxBuff[rxPos] = SBUF;
            if (uartRxBuff[rxPos]=='\n' || rxPos >= 64){
                for (uint8_t i = 0; i < rxPos; i ++ )
                    {
                        printf( "0x%02X ",uartRxBuff[i]);
                    }
                    printf("\n");
                if(uartRxBuff[0]=='k'){
                //if(uartRxBuff[1]==0x61)LED=0;
                //if(uartRxBuff[1]==0x73)LED=1;
                if(uartRxBuff[1]=='b')runBootloader();
                }
            rxPos=0;
            }else{
            rxPos++;
            }
        }
}

void sendProtocolMSG(unsigned char msgtype, unsigned short length, unsigned char type, unsigned char device, unsigned char endpoint, unsigned char __xdata *msgbuffer){
    return;
}

void sendHidPollMSG(unsigned char msgtype, unsigned short length, unsigned char type, unsigned char device, unsigned char endpoint, unsigned char __xdata *msgbuffer,unsigned char idVendorL,unsigned char idVendorH,unsigned char idProductL,unsigned char idProductH){
    unsigned char bb, xx, yy, vv, hh;
    unsigned short vendor_id, product_id;

    hh = 0;
    if (msgtype == 0x04 && type == 0x02) { // Mouse report
        vendor_id  = ((unsigned short)idVendorH  << 8) | (unsigned short)idVendorL;
        product_id = ((unsigned short)idProductH << 8) | (unsigned short)idProductL;
        switch(vendor_id) {
        case 0x046d: // Logitech (Logicool)
            switch(product_id) {
            case 0xc52b: // ERGO M575
            case 0xc534: // M186
                bb = msgbuffer[1];
                xx = msgbuffer[3];
                yy = msgbuffer[5] << 4 | msgbuffer[4] >> 4;
                vv = msgbuffer[6];
                break;
            case 0xc548: // M650
                bb = msgbuffer[1];
                xx = msgbuffer[3];
                yy = msgbuffer[5];
                vv = msgbuffer[7];
                hh = msgbuffer[8];
                break;
            case 0xc52F: // M331
                bb = msgbuffer[0];
                xx = msgbuffer[2];
                yy = msgbuffer[4];
                vv = msgbuffer[6];
                break;
            default:
                return;
            }
            break;
        case 0x25a7: // Digio
            switch(product_id) {
            case 0x2410: // MUS-RKT109BL
                bb = msgbuffer[0];
                xx = msgbuffer[1];
                yy = msgbuffer[3] << 4 | msgbuffer[2] >> 4;
                vv = msgbuffer[4];
                break;
            default:
                return;
            }
            break;
        default:
            return;
        }
        putchar(0x80);
        putchar(bb);
        putchar(xx);
        putchar(yy);
        putchar(vv);
        putchar(hh);
    }
}
