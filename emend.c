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

    raw.c_lflag &= !(ECHO);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
int main() 
{
    enableRawMode(); //Enables raw mode
    char c;
    // read() and STDIN_FILENO part of <unistd.h>
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
  return 0;
}