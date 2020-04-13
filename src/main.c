
#define RCC_BASE (0x40021000)
#define APB2ENR_BASE (0x18)
#define APB2ENR ( unsigned long *)((RCC_BASE)+(APB2ENR_BASE))

struct gpio {
  long int crl;
  long int crh;
  long int idr;
  long int odr;
};

struct gpio *gpioc = (struct gpio *)0x40011000;

void delay(unsigned long delay)
{
    while(delay) delay--;
}

int main(void)
{

    *APB2ENR = 0x11;
    gpioc->crh = 0x00100000;

    while(1)
    {
        gpioc->odr ^= (1 << 13);
        delay(500000);
    }
}

void SystemInit(void)
{

}
