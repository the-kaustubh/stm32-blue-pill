#include <gpio.h>
#include <rcc.h>

void delay(unsigned long delay)
{
    while(delay) delay--;
}

int main(void)
{

    RCC->APB2ENR = 0x11;
    GPIOC->CRH = 0x00100000;

    while(1)
    {
        GPIOC->ODR ^= (1 << 13);
        delay(500000);
    }
}

void SystemInit(void)
{

}
