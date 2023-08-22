#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include "hardware/adc.h"

const uint PIN_PHOTO = 26;
const uint PIN_LEDS[] = {11,12,13,14,15};

/// need to figure out min and max values for the leds to work properly
int ledmapper(float reading_value) {	
	return (5*(reading_value / 4200))+1;
}

int main(void) {
	bi_decl(bi_program_description("This is a program to read Thermistor"));
	
	stdio_init_all();
	
	adc_init();
	
	adc_gpio_init(PIN_PHOTO);
	adc_select_input(0);
	
	for (uint i=0; i <5; i++){
		gpio_init(PIN_LEDS[i]);
		gpio_set_dir(PIN_LEDS[i], GPIO_OUT);
	}
	
	while(1) {
		
		const float conversion_factor = 3.3f / (1 << 12);
			
		uint16_t result = adc_read();
		
		printf("Raw Value: 0x%03x, voltage: %f V\n", result, result * conversion_factor);
		/*
		for (uint i=0; i < 5; i++){
			
			if (i < ledmapper(result)) {
				gpio_put(PIN_LEDS[i], 1);
			} else {
				gpio_put(PIN_LEDS[i], 0);
			}
			
		}
		*/
		
		sleep_ms(500);
		
	}
	
}
