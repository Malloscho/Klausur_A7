#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void write_in_file(char const* const dateiname, int zahl)
{
    printf("%i \n", zahl);
    //datei = fopen(dateiname,"a");
    //fprintf(datei,"%i\n",zahl);
    //fclose(datei);
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

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "No option recognized. Wrong Usage. Please try -h\n");
    }

    while(true)
    {
        int option = getopt(argc, argv, "hr:");
        switch(option)
        {
        case 'h':
            printf("Bitte -r nutzen um eine Rechtseckfunktion zu nutzen. Verwende -r Amplitude Pulslänge Gesamtlänge Dateiname\n");
            exit(0);

        case 'r':
            //datei = fopen(argv[5],"w");
            //fclose(datei);
            rechteckgenerator(atoi(argv[2]),atoi(argv[3]),atoi(argv[4]),argv[5]);
            break;

        case '?':
            fprintf(stderr, "Please try -h\n");
            exit(1);

        case -1:
            exit(0);
        }
    }

    return 0;
}
