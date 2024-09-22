 /* Copyright Juarendra Ramadhani 2024
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#ifdef OLED_ENABLE
#include QMK_KEYBOARD_H
#include <stdio.h>
#include <stdlib.h>

// Constants for raindrop animation
#define RAINDROP_SPEED 500         // Animation speed in milliseconds
#define RAINDROP_MAX_POSITION 15   // Maximum row position for the raindrop (rows 0 to 15)
#define RAINDROP_COUNT 8          // Number of raindrops
#define OLED_WIDTH 5               // Number of columns on the OLED display (columns 0 to 4)

// Variables for raindrop animation
static uint32_t anim_timer = 0;
static uint8_t raindrop_positions[RAINDROP_COUNT];
static uint8_t raindrop_columns[RAINDROP_COUNT];

// Initialize the raindrop positions and columns
void init_raindrops(void) {
    srand(timer_read());  // Seed the random number generator
    for (uint8_t i = 0; i < RAINDROP_COUNT; i++) {
        raindrop_positions[i] = rand() % (RAINDROP_MAX_POSITION + 1);
        raindrop_columns[i] = rand() % OLED_WIDTH;
    }
}

// Function to display Caps Lock status on the primary (left) display
static void render_primary(void) {
    oled_clear();  // Clear the display
    oled_set_cursor(0, 0);
    if (host_keyboard_led_state().caps_lock) {
        oled_write_P(PSTR("CAPS LOCK ON"), false);
    } else {
        // Draw each raindrop
        for (uint8_t i = 0; i < RAINDROP_COUNT; i++) {
            oled_set_cursor(raindrop_columns[i], raindrop_positions[i]);
            oled_write("*", false);  // Draw the raindrop symbol
        }
    }
}

// Function to render the raindrop animation on the secondary (right) display
static void render_secondary(void) {
    oled_clear();  // Clear the display

    // Draw each raindrop
    for (uint8_t i = 0; i < RAINDROP_COUNT; i++) {
        oled_set_cursor(raindrop_columns[i], raindrop_positions[i]);
        oled_write("*", false);  // Draw the raindrop symbol
    }
}

// Main OLED task handler
bool oled_task_user(void) {
    // Update raindrop animation every RAINDROP_SPEED milliseconds
    if (timer_elapsed32(anim_timer) > RAINDROP_SPEED) {
        anim_timer = timer_read32();

        // Update positions of each raindrop
        for (uint8_t i = 0; i < RAINDROP_COUNT; i++) {
            raindrop_positions[i]++;
            if (raindrop_positions[i] > RAINDROP_MAX_POSITION) {
                raindrop_positions[i] = 0;
                raindrop_columns[i] = rand() % OLED_WIDTH;
            }
        }
    }

    // Render appropriate content based on the keyboard side
    if (is_keyboard_master()) {
        render_primary();      // Left side: Caps Lock status
    } else {
        render_secondary();    // Right side: Raindrop animation
    }
    return false;
}

// Initialize OLED rotation
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    init_raindrops();  // Initialize raindrops at startup
    return OLED_ROTATION_270;  // Adjust as needed for your display orientation
}
#endif
