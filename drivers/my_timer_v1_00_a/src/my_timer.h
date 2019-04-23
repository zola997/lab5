/*****************************************************************************
* Filename:          D:\ra205-2016\lab5/drivers/my_timer_v1_00_a/src/my_timer.h
* Version:           1.00.a
* Description:       my_timer Driver Header File
* Date:              Tue Apr 23 11:27:43 2019 (by Create and Import Peripheral Wizard)
*****************************************************************************/

#ifndef MY_TIMER_H
#define MY_TIMER_H

/***************************** Include Files *******************************/

#include "xbasic_types.h"
#include "xstatus.h"
#include "xil_io.h"

/************************** Constant Definitions ***************************/


/**
 * User Logic Slave Space Offsets
 * -- SLV_REG0 : user logic slave module register 0
 * -- SLV_REG1 : user logic slave module register 1
 * -- SLV_REG2 : user logic slave module register 2
 * -- SLV_REG3 : user logic slave module register 3
 */
#define MY_TIMER_USER_SLV_SPACE_OFFSET (0x00000000)
#define MY_TIMER_SLV_REG0_OFFSET (MY_TIMER_USER_SLV_SPACE_OFFSET + 0x00000000)
#define MY_TIMER_SLV_REG1_OFFSET (MY_TIMER_USER_SLV_SPACE_OFFSET + 0x00000004)
#define MY_TIMER_SLV_REG2_OFFSET (MY_TIMER_USER_SLV_SPACE_OFFSET + 0x00000008)
#define MY_TIMER_SLV_REG3_OFFSET (MY_TIMER_USER_SLV_SPACE_OFFSET + 0x0000000C)

/**************************** Type Definitions *****************************/


/***************** Macros (Inline Functions) Definitions *******************/

/**
 *
 * Write a value to a MY_TIMER register. A 32 bit write is performed.
 * If the component is implemented in a smaller width, only the least
 * significant data is written.
 *
 * @param   BaseAddress is the base address of the MY_TIMER device.
 * @param   RegOffset is the register offset from the base to write to.
 * @param   Data is the data written to the register.
 *
 * @return  None.
 *
 * @note
 * C-style signature:
 * 	void MY_TIMER_mWriteReg(Xuint32 BaseAddress, unsigned RegOffset, Xuint32 Data)
 *
 */
#define MY_TIMER_mWriteReg(BaseAddress, RegOffset, Data) \
 	Xil_Out32((BaseAddress) + (RegOffset), (Xuint32)(Data))

/**
 *
 * Read a value from a MY_TIMER register. A 32 bit read is performed.
 * If the component is implemented in a smaller width, only the least
 * significant data is read from the register. The most significant data
 * will be read as 0.
 *
 * @param   BaseAddress is the base address of the MY_TIMER device.
 * @param   RegOffset is the register offset from the base to write to.
 *
 * @return  Data is the data from the register.
 *
 * @note
 * C-style signature:
 * 	Xuint32 MY_TIMER_mReadReg(Xuint32 BaseAddress, unsigned RegOffset)
 *
 */
#define MY_TIMER_mReadReg(BaseAddress, RegOffset) \
 	Xil_In32((BaseAddress) + (RegOffset))


/**
 *
 * Write/Read 32 bit value to/from MY_TIMER user logic slave registers.
 *
 * @param   BaseAddress is the base address of the MY_TIMER device.
 * @param   RegOffset is the offset from the slave register to write to or read from.
 * @param   Value is the data written to the register.
 *
 * @return  Data is the data from the user logic slave register.
 *
 * @note
 * C-style signature:
 * 	void MY_TIMER_mWriteSlaveRegn(Xuint32 BaseAddress, unsigned RegOffset, Xuint32 Value)
 * 	Xuint32 MY_TIMER_mReadSlaveRegn(Xuint32 BaseAddress, unsigned RegOffset)
 *
 */
#define MY_TIMER_mWriteSlaveReg0(BaseAddress, RegOffset, Value) \
 	Xil_Out32((BaseAddress) + (MY_TIMER_SLV_REG0_OFFSET) + (RegOffset), (Xuint32)(Value))
#define MY_TIMER_mWriteSlaveReg1(BaseAddress, RegOffset, Value) \
 	Xil_Out32((BaseAddress) + (MY_TIMER_SLV_REG1_OFFSET) + (RegOffset), (Xuint32)(Value))
#define MY_TIMER_mWriteSlaveReg2(BaseAddress, RegOffset, Value) \
 	Xil_Out32((BaseAddress) + (MY_TIMER_SLV_REG2_OFFSET) + (RegOffset), (Xuint32)(Value))
#define MY_TIMER_mWriteSlaveReg3(BaseAddress, RegOffset, Value) \
 	Xil_Out32((BaseAddress) + (MY_TIMER_SLV_REG3_OFFSET) + (RegOffset), (Xuint32)(Value))

#define MY_TIMER_mReadSlaveReg0(BaseAddress, RegOffset) \
 	Xil_In32((BaseAddress) + (MY_TIMER_SLV_REG0_OFFSET) + (RegOffset))
#define MY_TIMER_mReadSlaveReg1(BaseAddress, RegOffset) \
 	Xil_In32((BaseAddress) + (MY_TIMER_SLV_REG1_OFFSET) + (RegOffset))
#define MY_TIMER_mReadSlaveReg2(BaseAddress, RegOffset) \
 	Xil_In32((BaseAddress) + (MY_TIMER_SLV_REG2_OFFSET) + (RegOffset))
#define MY_TIMER_mReadSlaveReg3(BaseAddress, RegOffset) \
 	Xil_In32((BaseAddress) + (MY_TIMER_SLV_REG3_OFFSET) + (RegOffset))

/************************** Function Prototypes ****************************/


/**
 *
 * Run a self-test on the driver/device. Note this may be a destructive test if
 * resets of the device are performed.
 *
 * If the hardware system is not built correctly, this function may never
 * return to the caller.
 *
 * @param   baseaddr_p is the base address of the MY_TIMER instance to be worked on.
 *
 * @return
 *
 *    - XST_SUCCESS   if all self-test code passed
 *    - XST_FAILURE   if any self-test code failed
 *
 * @note    Caching must be turned off for this function to work.
 * @note    Self test may fail if data memory and device are not on the same bus.
 *
 */
XStatus MY_TIMER_SelfTest(void * baseaddr_p);
/**
*  Defines the number of registers available for read and write*/
#define TEST_AXI_LITE_USER_NUM_REG 4


#endif /** MY_TIMER_H */
