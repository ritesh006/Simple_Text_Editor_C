#include <termios.h>
#include <unistd.h>
#include <stdlib.h>










/* Reseting terminal at previous mode after exiting a program*/

struct termios orig_termios;
void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);      
}

/*This function enables raW Mode using termios.h lib*/

void enableRawMode() 
{
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);
    struct termios raw = orig_termios;                      
     raw.c_lflag &= ~(ECHO | ICANON);                     /* Here resetting the raw.c_flag (local mode flage) witch defined macro ECHO */
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);             /* After retriving terminal parameter then applying with this funtion*/
}

int main(int argc, char const *argv[])
{
    enableRawMode();
    char c; 
    
    /* read function continue to read until end of file and press 'q' and  ENTER quiting from program*/
    while( read(STDIN_FILENO, &c, 1) == 1 &&  c != 'q' ); 
   
    return 0;
}
