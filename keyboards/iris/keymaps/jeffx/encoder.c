#include "encoder.h"

bool knob_prev_a = false;
knob_report_t knob_report = {.dir = 0, .phase = 0};

void knob_init(void) {
    // I use pins D1 (ISR1) & D4 for a knob.
    // Switching this to use F4/F5 on Iris

    // Set pin mode for D4 as input.
    DDRF &= ~(0UL << PF4);

    // Enable internal pull-up for D4.
    // This is done by "writing" 1 to a pin that has its mode set to input.
    PORTF |= (1 << PF4);

    // Enable interrupt for D5
    // For more info on the below flags see this awesome section 11.1 (pages 89-90) here:
    // https://cdn-shop.adafruit.com/datasheets/atmel-7766-8-bit-avr-atmega16u4-32u4_datasheet.pdf
    // Set pin mode & pull-up.
    DDRF &= ~(0UL << PF5);
    PORTF |= (1UL << PF5);

    // INT:    33221100
    EICRA |= 0b00000100;  // 0b01 - any edge
    // INT:     6  3210
    //EIMSK |= 0b00000010;
}

ISR(INT1_vect) {
    // Port PD1 (Pin 2)
    bool a = PINF & (1 << PF5);

    if (knob_prev_a != a) {
        // "A" channel has REALLY changed.
        knob_report.phase = a;
        knob_prev_a = a;
        bool b = PINF & (1 << PF4);
        if (a == b) {
            // Halfway through CCW rotation (A == B)
            //
            //         +---YOU ARE HERE (A=1, B=1)
            //         |     +---OR HERE (A=0, B=0)
            //         |     |
            //         v     v
            // A: _____/^^^^^\__
            // B: __/^^^^^\_____
            knob_report.dir++;
        } else {
            // Halfway through CW rotation (A != B)
            //
            //         +---YOU ARE HERE (A=1, B=0)
            //         |     +---OR HERE (A=0, B=1)
            //         |     |
            //         v     v
            // A: _____/^^^^^\_____
            // B: ________/^^^^^\__
            knob_report.dir--;
        }
    }
}

knob_report_t knob_report_read(void) {
    // Return knob report.
    return knob_report;
}

void knob_report_reset(void) {
    // Call this ASAP once you've processed the previous knob report.
    // TODO: This should probably be called within `knob_report_read`.
    knob_report = (knob_report_t){.dir = 0, .phase = 0};
}

