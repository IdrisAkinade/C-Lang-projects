
### INTRODUCTION:

<img src ="https://c15468752.files.wordpress.com/2018/12/hpm_0000_0002_0_img0088.jpg?w=256&h=347">
My idea for this mini-project is to build a voice controlled lift. The main aim of this project is to design and construct a voice operated lift control system. This system acts as human-machine communication system. Speech recognition is the process of recognizing the spoken words to take the necessary actions accordingly. This device is very helpful for paralysis, short height people and physically challenged persons. The speech recognition system provides the communication mechanism between the user and the microcontroller based lift control mechanism. This project makes use of a DC motor for moving the lift based on the voice/speech commands given by the user and voice recognition chip is used for recognition of the voice commands. Microcontroller is programmed, with the help of embedded C instructions. The microcontroller is capable of communicating with all input and output modules. The voice recognition system which is the input module to the microcontroller takes the voice instructions given by the user as input and the controller judges whether the instruction is to lift upwards or to the downwards , and according to the users voice the switching mechanism controls the lift. Also, a 7-segment display is available for visual information of operations being performed.

### APPARATUS:

-2 pulleys
-strings
-7 segment display
-Small rectangular box
-Big box
-Stepper Motor
-Arduino
-Breadboard
-USB to mini USB cable
-Power supply
-SN754410NE
-74HC595
-4 switches
-4 10K ohms resistors
-Wire of desired coloured
-Snips

### BUILDING THE LIFT:

The first thing I did was to build the lift. I built the lift using a rectangular box. I then put the lift in a big box as shown in the image below:

I then used 2 pulleys, one at the top of the box and one attached to the stepper motor connected with strings to pull the lift up and down. I also had a 7 segment display on top of the box to display what floor the lift is on.A schematic diagram of it is shown below:

<img src ="https://c15468752.files.wordpress.com/2018/12/IMG-2327.jpg?w=528&h=704">
<img src ="https://c15468752.files.wordpress.com/2018/12/IMG-2328.jpg?w=530&h=666">

### WIRING:

The wiring for this project is very easy because there is very few wiring done and not a messy one also. I used Arduino Nano you can use any arduino of your choice.

Stepper Motor :The wiring for the stepper is shown below and you can revisit my blog to check my instructions for the Stepper Motor 

<img src ="https://c15468752.files.wordpress.com/2018/12/IMG-2324.jpg?w=770">



### Switches:

Connect three wires to the board. The first two, red and black, connect to the two long vertical rows on the side of the breadboard to provide access to the 5 volt supply and ground. The third wire goes from digital pin of the arduino to one leg of the pushbutton. That same leg of the button connects through a pull-down resistor (here 10K ohm) to ground. The other leg of the button connects to the 5 volt supply.

When the push button is open (unpressed) there is no connection between the two legs of the push button, so the pin is connected to ground (through the pull-down resistor) and we read a LOW. When the button is closed (pressed), it makes a connection between its two legs, connecting the pin to 5 volts, so that we read a HIGH.

Pull-down resistors are used in electronic logic circuits to ensure that inputs to Arduino settle at expected logic levels if external devices are disconnected or are at high-impedance. As nothing is connected to an input pin, it does not mean that it is a logical zero. Pull down resistors are connected between the ground and the appropriate pin on the device.

Here is a picture of it below:

<img src ="https://c15468752.files.wordpress.com/2018/12/IMG-2325.jpg?w=770">
<img src ="https://c15468752.files.wordpress.com/2018/12/IMG-2323.jpg?w=770">




### CONTROLLING THE LIFT:

First let`s see how the cabin can move up or down. I used an “i” variable shows the number of floor.As you see elevator consist of 4 floor then for each floor, the code is written. You have to start the elevator in the first floor because elevator can’t understand where it is when the system firstly ready to go. Now elevator is ready.For example, push the button 4 which means exactly you want to elevator of the cabin goes up to forth floor. Then, due to if(buttonState4 == HIGH), the codes will be worked inside of this line. As we know i=1 firstly so i<4. Then until i goes to the 3, up() function will be active. So cabin will be on the fourth floor. After that which floor you want to go just push the button.

The up() and down() functions are very important. If you look at to the code closely, you see up() and down() functions is in a for loop. Inside of the for loop variable, a and b are increased until it is equal to 149, which makes 150 steps. These steps represents the elevators each floor length.

UP AND DOWN

Basically my stepper can be moved the cabin as a one floor in 150 steps. The 150 will be depend on the your system. Also delay() time can be changed to take the one floor. Here is the question, how can you know the how much step you need to take for a one floor or how much time you need ? To get the 150, I multiplied the length of my cabin by the step angle of the stepper motor then i  divided the value by the distance of the floor.

Yes that seems complicated so if you feel like you’re not getting a it then just insert your stepper in your system and work it. Give some value after a few trying you find the perfect number.

The line “Show(numbers[i])” in the code represents the floor number on the 7 segment. I Here is the some useful information about the shift register. When you use it in your elevator, it is good idea to use external 5v power supply for seven segment. Do not use arduino as a power supply.
