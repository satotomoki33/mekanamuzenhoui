/*
 * uart.h
 *
 *  Created on: Jun 26, 2024
 *      Author: owner
 */
#pragma once

#include "main.h"
#include <math.h>
struct Uart {
	UART_HandleTypeDef *huart;
	uint8_t buf[64];
	size_t read_idx;
};

void uart_init(struct Uart *uart);

size_t uart_available(struct Uart *uart);

uint8_t uart_read(struct Uart *uart);

#ifndef INC_UART_H_
#define INC_UART_H_



#endif /* INC_UART_H_ */
