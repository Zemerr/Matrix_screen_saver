#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

void mx_chrrain(void) {
	curs_set(0);
	nodelay(stdscr, 1);
	time_t  d;
	srand((unsigned) time(&d));
	start_color();
   	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	int max_x;
    int max_y;
	char c;
	char ch;		
    getmaxyx(stdscr, max_y, max_x);
	int start[max_x];	
	for (int i = 0; i < max_x; i++)
		start[i] = -max_y + rand() % max_y;
	int delat[max_x];     
    for (int i = 0; i < max_x; i++)
        delat[i] = 0+rand() % max_y;
	int end[max_x];
	int tail[max_x];
	int pisY[max_x];
	int flag[max_x];
	for (int i = 0; i < max_x; i++)
         pisY[i] = 0;
	int y;
	y = 0;
    while (1) {		
	int i;
	i = 0; 
	while (i < max_x) {
		if ( i % 3 == 0) {
	 		end[i] = start[i] - delat[i];
			if (flag[i] == 1) {
                 if (tail[i] == max_y+1)
                     flag[i] = 0;
                 move(tail[i], i);
                 printw(" ");
                 tail[i]++;
              }
			if (start[i] == max_y) {
                 pisY[i] = 0;
                 start[i] = 0;
                 flag[i] = 1;
                 tail[i] = max_y - delat[i];
				 delat[i] = 0+rand() % max_y;
			}
			if(end[i] >= 0) {
				printw(" ");
                move(end[i], i);
                printw(" ");
               }  
			if (start[i] >= 0) {
				c = 32 + rand() % 94;
				attron(COLOR_PAIR(1));
				mvaddch(pisY[i], i, c);
				attroff(COLOR_PAIR(1));
				attron(COLOR_PAIR(2));
                mvaddch(pisY[i]-1, i, c);
                attroff(COLOR_PAIR(2));
				if (start[i] == max_y-1) {
					c = 32 + rand() % 94;
                 	attron(COLOR_PAIR(2));
                 	mvaddch(pisY[i], i, c);
                 	attroff(COLOR_PAIR(2));
				}			
            }		
		}	
		i++;
	}
		for(int i = 0; i<max_x; i++) {
			if (start[i] >= 0)
				pisY[i]++;
		}
        usleep(1000 * 42);
        refresh();
		for(int i = 0; i<max_x; i++)          
			start[i]++;	
    	ch = getch();
		if (ch == 'q') {
			clear();
			break;
		}
	}
}

int main() {
    initscr();
	mx_chrrain();	
  	endwin();  
   return 0;
}
