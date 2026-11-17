#include <cstdlib>
#include <termios.h>
#include <unistd.h>

struct termios orig_termios;

void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  //this fucntion is part of the cstdlib library and causes fucntion to fun at end of program
  atexit(disableRawMode);
  struct termios raw = orig_termios;
  //bitwise AND the negation of the echo bitflag
  //and the flags field to get the 4th bit in flags field to become 0 so that raw mode id enabled
  raw.c_lflag &= ~(ECHO);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
  enableRawMode();
  char c;
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
  return 0;
}
