/*
 * Copyright (c) 2009-2012 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 *
 *
 *
 */


#include <stdio.h>
#include "platform.h"
#include "xparameters.h"
#include "xio.h"
#include "vga_periph_mem.h"


void print(char *str);

int main()
{
    init_platform();
    int br;
    int i=0xA0;
    int br1;
    int br2;
    int n=1;
    int smer = 0, smer1 = 0;
    unsigned char string_s[] = "LAZA JE LEGENDA";

    VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x00, 0x0);// direct mode   0
    VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x04, 0x3);// display_mode  1
    VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x08, 0x1);// show frame      2
    VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x0C, 0x1);// font size       3
    VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x10, 0xFFFFFF);// foreground 4
    VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x14, 0x000014);// background color 5
    VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x18, 0xFF0000);// frame color      6

    print("Hello World\n\r");


    clear_graphics_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);
    clear_text_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);
    do {
    	//VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x14, 0xA12345);
    //brisi_tekst(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR,i);
    //clear_text_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);
    draw_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR+br);

    print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR+i, string_s,15);
    for(br1=0;br1<300000;br1++){
    }
    //VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x14, 0xB23456);


    if (smer == 0){
    	br += 0x1;
    	if(br==0x22) {
        	//br=-0x22;
    		smer = 1;
        }
    }else{
    	br -= 0x1;
    	if(br == -0x22){
    		smer = 0;
    	}
    }

    if (smer1 == 0){

        print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR+i-4, " ",1);
        i += 1;
    	if(i == 0x107){
    	        //print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR+i, "               ",15);
    	    	//i=0xA0;
    	        smer1 = 1;
    	    }
    }else{

        print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR+i+0x38, " ",1);
        i -= 1;
    	if(i == 0xA0){
    		smer1 = 0;
    	}
    }

    } while (TRUE);

    set_cursor(350);



    return 0;
}
