#include <stdio.h>


int a,b,c,d,sek,sek_2,sek_3,licznik,nr_sub;
int tab[100000];		// estimated number of charakters in file_name.txt
int subs[150];			// estimated number of subtitles in file_name.srt
int napisz(int ile_sek);	// function(absolute number of seconds) returns time 00:00:00,000 format 

int main() {
	a = 0;
	b = 0;
	nr_sub = 0;

	while (( c = getchar()) != EOF){	// idea from the book  "The ANSI C Programming Language" by Brian W. Kernighan (see README.md)
		licznik = 0;
		tab[a] = c;

		/* detecting particular strings in order to establish time boundaries and counting absolute number of seconds  */
		if ((tab[a] == 13) && (tab[a - 3] == 58) && (a == 4))			// detecting first '_:__'  string, e.g. '0:00'
			{sek = ((tab[a-1]) - 48) + ((tab[a-2] - 48)*10); licznik = 1;}	// counting absolute number of seconds from 0:00:00 format
		if (( tab[a] == 13) && (tab[a - 3] == 58) && (tab[a - 5] == 10))	// detecting next '[line feed]_:__[carriage return]' string, e.g. next '0:00'
			{sek = ((tab[a-1]) - 48) + ((tab[a-2] - 48)*10) + ((tab[a-4] - 48)*60); licznik = 1;}	counting...
		if (( tab[a] == 13) && (tab[a - 3] == 58) && (tab[a - 6] == 10))	// detecting '[line feed]__:__[carriage return]'  string, e.g. '00:00'
			{sek = ((tab[a-1]) - 48) + ((tab[a-2] - 48)*10) + ((tab[a-4] - 48)*60) + ((tab[a-5] - 48)*600); licznik = 1;}	// counting...
		if (( tab[a] == 13) && (tab[a - 3] == 58) && (tab[a - 6] == 58))	// detecting '_:__:__[carriage return]'  string, e.g. '0:00:00'
			{sek = (tab[a-1] - 48) + ((tab[a-2] - 48)*10) + ((tab[a-4] - 48)*60) + ((tab[a-5] - 48)*60*10) + ((tab[a-7] - 48)*3600); licznik = 1;}	// counting ...
		

		sek_2 = sek;	// establishing time boundaries of single subtitle

		if (licznik == 1){ 	// branching algorithm in case of detection desirable strings listed above
			if (nr_sub > 0)
				{printf("%d\n", nr_sub); napisz(sek_3); printf("--> "); napisz(sek_2); printf("\n");}	// creating time boundaries in srt format
			if (nr_sub > 0)
			for (d = 1; d < 130; d++) { 	// 130 - single subtitle estimated length 
				putchar(subs[d]);	// creating subtitles in srt format
				if (subs[d] == 13)
					{printf("\n"); break;}
			}
			nr_sub++;

			for (d = 0; d < 130; d++)	// erasing table before starting the next string of characters  
				subs[d] = 0;
			b = 0;
			printf("\n");
			}
		else {
			subs[b] = c;	// reading text string from input file_name.txt 
			b++;
			sek_3 = sek_2;	// establishing boundaries of single subtitle
		}

		a++;
	}

	{printf("%d\n", nr_sub); napisz(sek_3); printf("--> "); napisz(sek_2 + 4); printf("\n");}	// creating the last time boundary 

	for (d = 1; d < 130; d++) { 	// creating the last subtitle
		putchar(subs[d]);
		if (subs[d] == 13)
			{printf("\n"); break;}
	}

}

int napisz(int ile_sek) {	// function(absolute number of seconds) returns time 00:00:00,000 format 
	int godz = ile_sek/3600;
	int min_10 = (ile_sek - (godz*3600))/600;
	int min = (ile_sek - (godz*3600) - (min_10*600))/60;
	int sek_10 = (ile_sek - (godz*3600) - (min_10*600) - (min*60))/10;
	int sekun = ile_sek - (godz*3600) - (min_10*600) - (min*60) - (sek_10*10); 

	printf("0%d:%d%d:%d%d,000 ", godz, min_10, min, sek_10, sekun); 

}


