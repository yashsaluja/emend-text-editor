#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>

struct termios orig_termios;
void disableRawMode() 
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() 
{
    // struct termios, tcgetattr(), tcsetattr(), ECHO, and TCSAFLUSH all come from <termios.h>.
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8); //It is not a flag but a bitmask
    raw.c_lflag &= !(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME]= 1;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
int main() 
{
    enableRawMode(); //Enables raw mode
    // read() and STDIN_FILENO part of <unistd.h>
    while (1)
    {   
        char c = '\0';
        read(STDIN_FILENO, &c, 1);
        if(iscntrl(c)) 
        {
            printf("%d\r\n", c);
        }
        else
        {
            printf("%d ('%c')\r\n", c, c);
        }
        if(c == 'q')
        {
            break;
        }
    }
  return 0;
}