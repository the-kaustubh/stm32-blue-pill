#ifndef RCC_H
#define RCC_H

#define RCC_BASE (0x40021000)

#define CR_BASE       (0x000)
#define CFGR_BASE     (0x004)
#define CIR_BASE      (0x008)
#define APB2RSTR_BASE (0x00C)
#define APB1RSTR_BASE (0x010)
#define AHBENR_BASE   (0x014)
#define APB2ENR_BASE  (0x018)
#define APB1ENR_BASE  (0x01C)
#define BDCR_BASE     (0x020)
#define CSR_BASE      (0x024)
#define AHBSTR_BASE   (0x028)
#define CFGR2_BASE    (0x02C)

struct rcc {
  unsigned long CR;
  unsigned long CFGR;
  unsigned long CIR;
  unsigned long APB2RSTR;
  unsigned long APB1RSTR;
  unsigned long AHBENR;
  unsigned long APB2ENR;
  unsigned long APB1ENR;
  unsigned long BDCR;
  unsigned long CSR;
  unsigned long AHBSTR;
  unsigned long CFGR2;
} ;

 struct rcc *RCC = (struct rcc *)(RCC_BASE);


#endif
