#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) 
{
    if (argc != 3) 
    {
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        syslog(LOG_ERR, "Invalid number of arguments: expected 2, got %d", argc - 1);
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    FILE *fp = fopen(writefile, "w");
    if (fp == NULL) 
    {
        syslog(LOG_ERR, "Error: Could not open file %s for writing", writefile);
        closelog();
        return 1;
    }

    if (fprintf(fp, "%s", writestr) < 0) 
    {
        syslog(LOG_ERR, "Error: Failed to write to file %s", writefile);
        fclose(fp);
        closelog();
        return 1;
    }

    // Clean up
    fclose(fp);
    closelog();

    return 0;
}
