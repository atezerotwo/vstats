#include <stdio.h>
#include <string.h>
#include "config_vlan.h"

#define DELIM "="

struct config get_config(char *filename)
{
    struct config configstruct;
    FILE *file = fopen (filename, "r");

    if (file != NULL)
    {
        char line[MAXBUF];
        int i = 0;

        while(fgets(line, sizeof(line), file) != NULL)
        {

            char *cfline;

            cfline = strstr((char *)line,DELIM); //returns char after delim
            cfline = cfline + strlen(DELIM);
            cfline = strtok(cfline, "\n"); //removes "\n" from the line

            if (i == 0)
            {
                memcpy(configstruct.graphiteuse,cfline,strlen(cfline));
                //printf("%s",configstruct.imgserver);
            }
            else if (i == 1)
            {
                memcpy(configstruct.graphiteserver,cfline,strlen(cfline));
                //printf("%s",configstruct.ccserver);
            }
            else if (i == 2)
            {
                memcpy(configstruct.graphiteport,cfline,strlen(cfline));
                //printf("%s",configstruct.port);
            }
            else if (i == 3)
            {
                memcpy(configstruct.graphiteprefix,cfline,strlen(cfline));
                //printf("%s",configstruct.graphiteprefix);
            }
            else if (i == 4)
            {
                memcpy(configstruct.ethdevname,cfline,strlen(cfline));


                //printf("%s",configstruct.graphiteprefix);
            }

            i++;
        } // End while
        fclose(file);
    } // End if file

    return configstruct;
}
