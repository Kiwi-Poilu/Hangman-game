#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

// introduction au jeu, initialisations, boucle
int	main(void)
{
	char word[] = "PANDA";
	int shots = 10;
	int t = 0;
	char wordHidden[26]; 	
	//countWord ( word );
	int i;
	int c;
	c = 0;
	i = 0;
	while ( word[i] != '\0')
	{
		i++;
	}

	while ( c != i)
	{
		wordHidden[c] = '*';
		c++;
	}
	wordHidden[c] = '\0';

	printf("Bienvenue dans le Pendu !\n\n");
	while ( shots != 0 && t != 1 ) 
	{
		ft_shots(&shots, wordHidden, word);
		shots--;
		t = checkStar(wordHidden);
	}
	if ( shots == 0 )
		printf("Perdu, essaie encore jeune caca !");
	else 
		printf("Pas si nul, crotte junevile");
}

// affiche le nombre de coups restants, lance readChar, lance checkWord
void	ft_shots( int *shots, char *wordHidden, char *word)
{
	char letter;

	printf("Il vous reste %d coups a jouer\n", *shots);
	printf("Quel est le mot secret ? %s\n", wordHidden);
	printf("Proposez une lettre : ");
	letter = readChar();
	checkWord(letter, wordHidden, word);
	printf("\n");
}

// renvoie la saisie d'une lettre a ft_shots
char	readChar()
{
	char letter = 0;

	letter = getchar();
	letter = toupper(letter);

	while ( getchar() != '\n' );

	return letter;
}

// compare la lettre entre avec les mots
void	checkWord( char letter, char *wordHidden, char *word)
{
	int i = 0;
	while ( word[i] != '\0') 
	{
		if (letter == word[i])
		{
			wordHidden[i] = word[i];
		}
		i++;
	}
}

void	countWord ( char *word )
{

	int i;
	int c;
	c = 0;
	i = 0;
	while ( word[i] != '\0')
	{
		i++;
	}

	char wordHidden[i];

	while ( wordHidden[c] != i) 
	{
		wordHidden[i] = '*';
		c++;
	}
}

int	checkStar ( char *wordHidden )
{
	int i = 0;
	int c = 0;

	while ( wordHidden[i] != '\0' )
	{
		if (wordHidden[i] == '*')
			c++;
		i++;
	}
	if ( c == 0 )
		return 1;
	else
		return 0;
}
