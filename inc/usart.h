#ifndef USART_H
#define USART_H

#define USART_BASE (0x40013800)

struct usart {
  unsigned long SR;       /* Address offset: 0x00 */
	unsigned long DR;       /* Address offset: 0x04 */
	unsigned long BRR;      /* Address offset: 0x08 */
	unsigned long CR1;      /* Address offset: 0x0C */
	unsigned long CR2;      /* Address offset: 0x10 */
	unsigned long CR3;      /* Address offset: 0x14 */
	unsigned long GTPR;     /* Address offset: 0x18 */
};

struct usart *USART = (struct usart *)USART_BASE;

#endif
