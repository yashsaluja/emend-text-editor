#include<unistd.h>
#include<termios.h>

void enableRawMode() {
    // struct termios, tcgetattr(), tcsetattr(), ECHO, and TCSAFLUSH all come from <termios.h>.
    struct termios raw;

    tcgetattr(STDIN_FILENO, &raw);

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