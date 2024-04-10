#include <syslog.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    int fd;
    size_t nr;

    openlog("Writer", LOG_PID, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Invalid Number of Arguments. Expecting 2 arguments, but received %d", argc - 1);
        closelog();
        return 1;
    }

    fd = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        syslog(LOG_ERR, "Error openning file %s: %s", argv[1], strerror(errno));
        closelog();
        return 1;
    }
    
    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
    
    nr = write(fd, argv[2], strlen(argv[2]));
    if (nr == -1) {
        syslog(LOG_ERR, "Error writing %s to file %s", argv[2], argv[1]);
        closelog();
        close(fd);
    }

    closelog();
    close(fd);

    return 0;
}
