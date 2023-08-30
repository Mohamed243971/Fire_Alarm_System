/*
 * SPI_Interface.h
 *
 *  Created on: Aug 28, 2023
 *      Author: moham
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

void MSPI_voidMasterInit();


void MSPI_voidSlaveInit();

u8 MSPI_u8Transvieve(u8 A_u8Data);

void MSPI_voidDisplayNumber(s32 A_s32Number);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
