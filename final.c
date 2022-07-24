#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lib.h"



int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("No option recognized. Wrong Usage. Please try -h\n");
        return 0;
    }
    
    int c;

    while((c = getopt (argc, argv, "hr:"))!= 1)
    {
        
        switch(c)
        {
        case 'h':
            printf("Bitte -r nutzen um eine Rechtseckfunktion zu nutzen. Verwende -r Amplitude Pulslänge Gesamtlänge Dateiname\n");
            exit(0);

        case 'r': ;
	    FILE *datei = NULL;
	if(argc != 6)
	{
		printf("Fehlendes oder zu viele Argumente!\n");
		exit(1);
	}		
	
            datei = fopen(argv[5],"w");
            fclose(datei);
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
