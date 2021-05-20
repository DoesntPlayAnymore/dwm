#ifndef DWMC
#include "dwm.c"
#define DWMC
#endif
#include <time.h>


int
sprint_time(char *dest, const char*fmt)
{
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	return sprintf(dest, fmt, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}



void
spawn_scrot(const Arg *arg)
{
        char buf[128];
        sprint_time(buf, "%d%02d%02d_%02d:%02d:%02d");

	char filename[256];
	sprintf(filename, "%s%s.png", (char *)arg->v, buf);
	
	char *arg_list[] = {"scrot", filename, NULL};
	
	if (fork() == 0) {
                if (dpy)
                        close(ConnectionNumber(dpy));
                setsid();
                execvp(arg_list[0], arg_list);
                fprintf(stderr, "dwm: execvp %s", "scrot");
                perror(" failed");
                exit(EXIT_SUCCESS);
        }
}
