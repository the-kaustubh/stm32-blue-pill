#ifndef GPIO_H
#define GPIO_H

#define GPIO_BASE (0x40010000)

#define GPIOA_BASE (0x0800)
#define GPIOB_BASE (0x0C00)
#define GPIOC_BASE (0x1000)

struct gpio {
  unsigned long CRL;
  unsigned long CRH;
  unsigned long IDR;
  unsigned long ODR;
  unsigned long BSRR;
  unsigned long BRR;
  unsigned long LCKR;
};

struct gpio *GPIOA = (struct gpio *)(GPIO_BASE + GPIOA_BASE);
struct gpio *GPIOB = (struct gpio *)(GPIO_BASE + GPIOB_BASE);
struct gpio *GPIOC = (struct gpio *)(GPIO_BASE + GPIOC_BASE);

#endif
