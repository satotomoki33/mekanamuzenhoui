/*
 * uart.c
 *
 *  Created on: Jun 26, 2024
 *      Author: owner
 */

#include <stddef.h>
#include <stdint.h>

#include "uart.h"

void uart_init(struct Uart *uart) {
	HAL_UART_Receive_DMA(uart->huart, uart->buf, sizeof(uart->buf));
}

size_t uart_available(struct Uart *uart) {
    size_t write_idx = sizeof(uart->buf) - __HAL_DMA_GET_COUNTER(uart->huart->hdmarx);
    return (sizeof(uart->buf) + write_idx - uart->read_idx) % sizeof(uart->buf);
}

uint8_t uart_read(struct Uart *uart) {
	uint8_t res = uart->buf[uart->read_idx];
	uart->read_idx = (uart->read_idx + 1) % sizeof(uart->buf);
	return res;
}
