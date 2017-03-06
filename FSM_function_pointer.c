#include <stdio.h>

typedef void *(*StateFunc)(char * value);

// States
void *led_on(char *);
void *led_off(char *);

void *led_on(char * value) {
    printf("led_on: %c\n",*value);
    return led_off("0"); // next state
}

void *led_off(char * value) {
    printf("led_off: %c\n",*value);
    return led_on("1"); // next state
}

int main() {
    StateFunc statefunc = led_on;
    char data;
    
    while(1) 
    {
        statefunc = (StateFunc)(*statefunc)(&data);
    }
    
    return 1; // should not get here
}
