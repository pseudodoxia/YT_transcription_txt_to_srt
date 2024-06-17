#include <stdio.h>


int a,b,c,d,sek,sek_2,sek_3,licznik,nr_sub;
int tab[100000];		// estimated number of charakters in file_name.txt
int subs[150];			// estimated number of subtitles in file_name.srt
int napisz(int ile_sek);	// function(absolute number of seconds) returns time 00:00:00,000 format 

int main() {
	a = 0;
	b = 0;
	nr_sub = 0;

	while (( c = getchar()) != EOF){	// this idea comes from  The ANSI C Programming Language by Brian W. Kernighan (see README.md)
		licznik = 0;
		tab[a] = c;

		if (( tab[a] == 13) && (tab[a - 3] == 58) && (tab[a-6] == 58))
			{sek = (tab[a-1] - 48) + ((tab[a-2] - 48)*10) + ((tab[a-4] - 48)*60) + ((tab[a-5] - 48)*60*10) + ((tab[a-7] - 48)*3600); licznik = 1;} 
		if (( tab[a] == 13) && (tab[a - 3] == 58) && (tab[a - 5] == 10))
			{sek = ((tab[a-1]) - 48) + ((tab[a-2] - 48)*10) + ((tab[a-4] - 48)*60); licznik = 1;}

		if (( tab[a] == 13) && (tab[a - 3] == 58) && (tab[a - 6] == 10))
			{sek = ((tab[a-1]) - 48) + ((tab[a-2] - 48)*10) + ((tab[a-4] - 48)*60) + ((tab[a-5] - 48)*600); licznik = 1;}

		if (( tab[a] == 13) && (tab[a - 3] == 58) && ((tab[a - 5] == 10)))
			{sek = ((tab[a-1]) - 48) + ((tab[a-2] - 48)*10) + ((tab[a-4] - 48)*60); licznik = 1;}
		if ((tab[a] == 13) && (tab[a - 3] == 58) && (a == 4))
			{sek = ((tab[a-1]) - 48) + ((tab[a-2] - 48)*10); licznik = 1;}

		sek_2 = sek;

		if (licznik == 1){ 
			if (nr_sub > 0)
				{printf("%d\n", nr_sub); napisz(sek_3); printf("--> "); napisz(sek_2); printf("\n");}
			if (nr_sub > 0)
			for (d = 1; d < 130; d++) { 
				putchar(subs[d]);
				if (subs[d] == 13)
					{printf("\n"); break;}
			}
			nr_sub++;

			for (d = 0; d < 130; d++)
				subs[d] = 0;
			b = 0;
			printf("\n");
			}
		else {
			subs[b] = c;
			b++;
			sek_3 = sek_2;
		}

		a++;
	}

	{printf("%d\n", nr_sub); napisz(sek_3); printf("--> "); napisz(sek_2 + 4); printf("\n");}

	for (d = 1; d < 130; d++) { 
		putchar(subs[d]);
		if (subs[d] == 13)
			{printf("\n"); break;}
	}

}

int napisz(int ile_sek) {
	int godz = ile_sek/3600;
	int min_10 = (ile_sek - (godz*3600))/600;
	int min = (ile_sek - (godz*3600) - (min_10*600))/60;
	int sek_10 = (ile_sek - (godz*3600) - (min_10*600) - (min*60))/10;
	int sekun = ile_sek - (godz*3600) - (min_10*600) - (min*60) - (sek_10*10); 

	printf("0%d:%d%d:%d%d,000 ", godz, min_10, min, sek_10, sekun); 

}


