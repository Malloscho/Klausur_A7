#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void write_in_file(char const* const dateiname, int zahl)
{
    printf("%i \n", zahl);
    FILE *datei = NULL;
    datei = fopen(dateiname,"a");
    fprintf(datei,"%i\n",zahl);
    fclose(datei);
}

void rechteckgenerator(int amplitude, int frequenz, int anzahl, char const* const dateiname)
{
    for(int i=0; i < anzahl; i++)
    {
        if((i / frequenz) % 2 )
        {
            write_in_file(dateiname, amplitude);
        }
        else
        {
            write_in_file(dateiname, 0);
        }
        
    }
}
