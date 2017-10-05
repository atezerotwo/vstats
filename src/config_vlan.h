#ifndef CONFIG_VLAN_H_INCLUDED
#define CONFIG_VLAN_H_INCLUDED

#define MAXBUF 1024

struct config
{
    char graphiteuse[MAXBUF];
    char graphiteserver[MAXBUF];
    char graphiteport[MAXBUF];
    char graphiteprefix[MAXBUF];
    char ethdevname[MAXBUF];
};

struct config get_config(char *filename);

#endif // CONFIG_VLAN_H_INCLUDED
