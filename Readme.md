EMEND: A TEXT EDITOR

-- Part of my semester minor project.
-- Group: 
    -Manu
    -Vansh
    -Yash
    -Lakshit
    
-- Total files:
    --Makefile
    --emend.c
    --Readme.md
    --Executable emend
    --HTML document for Readme.
PS: EMEND means to edit a piece of text.

TIMELINE
___________________________________________________________________________________________________________________________________________

Date: 25/08/2017

ENTERING INTO CANONICAL MODE:
____________________________
-- Enabled raw mode in terminal to stop ECHOING text in the terminal. Echoing text in the terminal is helpful in Canonical mode but it is not recommended it Raw mode. ECHO causes each keypress to be printed to the terminal so you can see what you're typing. It does the same thing but doesn't print out anything. We can exit Raw mode by typing CTRL+C at the terminal and then typing reset followed by hitting ENTER. This resets the terminal and everything is set back to normal. All the raw mode attributes such as struct termios, tcgetattr(), tcsetattr(), ECHO and TCSAFLUSH all come from <termios.h> header file.

--Terminal attributes are set into termios using tcgetatt(). After modifying, THese can be applies to the terminal using tcsetattr(). TCSAFLUSH argument sets when to apply changes. Here in our case, it waits for all pending outputs to be written to terminal, and also discards any input that hasn't been read.

-- c_lflag field is called "local flags", other flag fields are input flag c_iflag, output flag c_oflag and control flag c_cflag. All of these has to be modified to enable raw mode. There are the flags which are used to enable raw mode into a terminal. ECHO is a bitflag. Bitwise NOT(~) is used on this value. Then bitwise AND is used which forces the fourth bit in the flag field to become zero and causes every other bit to retain its current value. As soon as you press 'q' the program will quit.