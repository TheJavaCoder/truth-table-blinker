#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

int sleepTime = 5000;

int inputX[4] = { 0, 0, 1, 1};
int inputY[4] = { 0, 1, 0, 1};

int inputXPin = 15;
int inputYPin = 3;

int andPin = 16;
int orPin = 17;
int nandPin = 18;
int norPin = 19;
int xorPin = 20;
int xnorPin = 21;

// Binary Gates
int AND(int a, int b) {
    return a && b;
}

int OR(int a, int b) {
    return a || b;
}

int NAND(int a, int b) {
    return !(a && b);
}

int NOR(int a, int b) {
    return !(a || b);
}

int XOR(int a, int b) {
    return a ^ b;  // bitwise XOR works fine for 0/1
}

int XNOR(int a, int b) {
    return !(a ^ b);
}

int main()
{
    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
        return -1;
    }

    gpio_init(andPin);
    gpio_set_dir(andPin, GPIO_OUT);

    gpio_init(orPin);
    gpio_set_dir(orPin, GPIO_OUT);

    gpio_init(nandPin);
    gpio_set_dir(nandPin, GPIO_OUT);

    gpio_init(norPin);
    gpio_set_dir(norPin, GPIO_OUT);

    gpio_init(xorPin);
    gpio_set_dir(xorPin, GPIO_OUT);

    gpio_init(xnorPin);
    gpio_set_dir(xnorPin, GPIO_OUT);

    gpio_init(inputXPin);
    gpio_set_dir(inputXPin, GPIO_OUT);

    gpio_init(inputYPin);
    gpio_set_dir(inputYPin, GPIO_OUT);

    while (true) {
        
        for(int i = 0; i < 4; i++) {
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
            int x = inputX[i];
            int y = inputY[i];

            gpio_put(inputXPin, x);
            gpio_put(inputYPin, y);

            gpio_put(andPin, AND(x, y));
            gpio_put(orPin, OR(x, y));
            gpio_put(nandPin, NAND(x, y));
            gpio_put(norPin, NOR(x, y));
            gpio_put(xorPin, XOR(x, y));
            gpio_put(xnorPin, XNOR(x, y));

            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);

            sleep_ms(sleepTime);
        }
    }
}