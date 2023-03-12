// Include necessary libraries
#include <stdio.h> // for standard input/output
#include <stdlib.h> // for general-purpose functions
#include <windows.h> // for Windows-specific functions

// Function to get current cursor position
void getCursorPosition(int *x, int *y) {
    POINT p;
    GetCursorPos(&p); // Get current position
    *x = p.x; // Store x-coordinate
    *y = p.y; // Store y-coordinate
}

// Function to move cursor to given coordinates
void movefuncMouse(int x, int y) {
    SetCursorPos(x, y); // Set cursor position
}

// Main function
int main() {
    int x, y; // Variables to store cursor position
    int active = 1; // Flag to indicate whether the mouse movement is active or not
    int wait_time = 5000; // Time to wait in milliseconds
    printf("To turn it on/off press ctrl +l +k \n"); // Show instructions

    // Infinite loop
    while (1) {
        // Check if the Ctrl + L + K key combination is pressed
        if (GetAsyncKeyState(VK_CONTROL) & 0x8000) {
            if (GetAsyncKeyState(0x4C) & 0x8000 && GetAsyncKeyState(0x4B) & 0x8000) {
                if (active) {
                    printf("Mouse movement stopped.\n"); // Show message
                    active = 0; // Deactivate mouse movement
                } else {
                    printf("Mouse movement started.\n"); // Show message
                    active = 1; // Activate mouse movement
                }
                Sleep(200); // Sleep for 200 milliseconds
            }
        }

        // Check if mouse movement is active
        if (active) {
            // Move cursor in a square pattern
            for (int i = 0; i < 4; i++) {
                // Check if mouse movement is still active
                if (!active) {
                    break; // Exit loop
                }
                getCursorPosition(&x, &y); // Get current cursor position
                movefuncMouse(x + 50, y); // Move cursor right
                Sleep(1000); // Wait for 1 second
                getCursorPosition(&x, &y); // Get current cursor position
                movefuncMouse(x, y + 50); // Move cursor down
                Sleep(1000); // Wait for 1 second
                getCursorPosition(&x, &y); // Get current cursor position
                movefuncMouse(x - 50, y); // Move cursor left
                Sleep(1000); // Wait for 1 second
                getCursorPosition(&x, &y); // Get current cursor position
                movefuncMouse(x, y - 50); // Move cursor up
                Sleep(1000); // Wait for 1 second
            }
            Sleep(wait_time); // Wait for specified time
        }
    }

    return 0; // End program
}


