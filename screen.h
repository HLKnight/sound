#define ESC 0x1B
#define BAR "\u2590"
//#define UNICODE
#define RES 4

enum FGCOLORS {BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
// function prototypes
void setColor(int);

void clearScreen(void);

void gotoxy(int, int);

void bar(double, int);
