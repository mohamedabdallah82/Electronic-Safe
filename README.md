# Electronic-Safe

## Password-Protected Security System

This code implements a password-protected security system using an Arduino board, a keypad, an LCD display, LEDs, a servo motor, and a buzzer. The system prompts the user to enter a password and grants access if the correct password is entered. It also triggers an alarm and locks the system if an incorrect password is entered multiple times.

### Components Used
- Arduino board
- Keypad
- LCD display
- Servo motor
- LEDs (Green and Red)
- Buzzer

### Libraries Used
- LiquidCrystal: Controls the LCD display.
- Keypad: Handles input from the keypad.
- Servo: Controls the servo motor.

### Pin Connections
- Buzzer: Connected to pin 10.
- Green LED: Connected to pin 11.
- Red LED: Connected to pin 12.
- LCD:
  - RS pin connected to analog pin A0.
  - EN pin connected to analog pin A1.
  - D4, D5, D6, D7 pins connected to analog pins A2, A3, A4, A5, respectively.
- Keypad:
  - ROW pins connected to digital pins 8, 7, 6, and 5.
  - COL pins connected to digital pins 4, 3, 2.

### Variables Used
- `truePassword`: The correct password (initialized as "0000").
- `i`: Counter for the entered password.
- `count`: Number of correctly entered password characters.
- `wrongEntry`: Count of incorrect password attempts.
- `n`: Length of the true password.
- `password`: Array to store the entered password.

### Functions
- `setup()`: Initializes the pins and settings, displays a welcome message on the LCD, and prompts the user to enter the password.
- `loop()`: The main program loop that waits for keypad input. If a button is pressed and it's not '#', the entered character is stored and displayed as '*' on the LCD. If the entered character is '*', the system is reset. If the entered character is '#', it checks if the entered password matches the true password. If the passwords match, it displays a success message, unlocks the system, and waits for the user to enter '*' to lock again. If the passwords don't match, it displays a wrong password message and calls the `wrongPass()` function. If the user enters the wrong password three times, the `callThePoliceThereIsAThief()` function is called.
- `wrongPass()`: Displays a wrong password message, increments the wrong entry count, and calls the `reset()` function.
- `reset()`: Resets the variables, clears the LCD, and displays the password prompt. It locks the system by turning off the green LED, turning on the red LED, and moving the servo motor to the initial position.
- `callThePoliceThereIsAThief()`: Activates an alarm by flashing the red LED and sounding the buzzer continuously. It also displays a warning message on the LCD indicating that the user can't enter the password again.

Please note that this is a brief overview of the code. For a more detailed understanding, it's recommended to go through the code and comments provided within the code itself.

###Circuit Diagram
![Electronic Safe](https://github.com/mohamedabdallah82/Electronic-Safe/assets/126836270/ec524727-b32c-4bac-ab39-4b5084a61deb)

###Simulation


https://github.com/mohamedabdallah82/Electronic-Safe/assets/126836270/a74c419a-9b14-4cb5-b434-1fd940e42b1e


###Author

-@mohamedabdallah82
