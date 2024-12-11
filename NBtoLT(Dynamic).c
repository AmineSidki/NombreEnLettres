#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char* string;

string Load();
string *input(int*);
string divide(string);
string translate(string);
bool isZero(string);
bool verif(string);
int Exists(char,string,int);


// fonction principale
int main()
{	
	Load();
	int j, flag;
	string* Entree;
	
	system("color F0");
	Entree = input(&flag);
	
	string Pentiere[4] = {
		divide(Entree[0]), 
		divide(Entree[0]), 
		divide(Entree[0]), 
		divide(Entree[0])
	};
	string Preelle[4];
	string Ordre[4] = {
		"Milliards", 
		"Millions", 
		"Mille", 
		""
	};
	
	printf("\a");
	bool isZ = false;
	
	for (j = 0; j < 4; j++)
	{
		if (!(isZero(Pentiere[j])) || (j == 3 && isZero(Pentiere[2])&& isZero(Pentiere[1])&& isZero(Pentiere[0])))
		{
			if(isZero(Pentiere[j]) && !flag)
			{
				isZ = true;
			}
			printf(" %s %s", translate(Pentiere[j]), Ordre[j]);
		}
	}
	if (Entree[2] != NULL)
	{
		for (j = 0; j < 4; j++)
			Preelle[j] = divide(Entree[2]);
		
		bool isFloat = false;
		for (j = 0; j < 4 ; j++)
			if(!isZero(Preelle[j]))
				isFloat = true;
		if(isFloat)
		{
			printf("virgule ");
			isZ = false;
			if(Entree[1] != NULL)
			{
				for (j = 0; Entree[1][j] != '\0'; j++)
					printf("%s ", translate(Entree[1]));	
			}
		
			for (j = 0; j < 4; j++)
			{
				if (!(isZero(Preelle[j])))
					printf("%s %s ", translate(Preelle[j]), Ordre[j]);
			}
		}
	}
	
	if(isZ)
	{
		printf("\r      ");
	}
	
	printf("\n");
	
	return 0;
}

// pour verifier si le caractere est un chiffre
int IsDigit(char c)
{
	if ((c < 48 || c > 57))
		return 0;
	return 1;
}

// pour verifier si le nombre est un reel
int IsFloat(string str)
{
	int i = 1, l = strlen(str);
	while (i < l - 1)
	{
		if (str[i] == '.')
			return i;
		i++;
	}
	return 0;
}

// pour initialiser une chaine de caracteres formee de zeros
string str_init(int size)
{
	string str = (string)malloc(size * sizeof(char));
	int i;
	for (i = 0; i < size - 1; i++)
	{
		str[i] = '0';
	}
	str[size - 1] = '\0';
	return str;
}

// pour eliminer l'element a gauche de la chaine de caracteres
void str_del_last(string str)
{
	int i = 0, l = strlen(str);
	while (i < l)
	{
		str[i] = str[i + 1];
		i++;
	}
	str = realloc(str, (l - 1) * sizeof(char));
}

// pour eliminer l'element a droite de la chaine de caracteres
void str_del_first(string str)
{
	int l = strlen(str);
	str[l-2] = '\0';
	str = realloc(str, (l - 1) * sizeof(char));
}

// pour deplacer les zeros d'une chaine a une autre
void str_dep_zero(string str1, string str2)
{
	int i = 0;
	while (str1[i] != '\0' && str1[i] == '0')
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
}

// pour effectuer l'entree du nombre
string *input(int *flag)
{
	string *Result = malloc(3 * sizeof(string));
	string tmp = malloc(14 * sizeof(char));
	do
	{
		system("cls");
		printf("\n\tEntrez Un Nombre : ( Max : 12 chiffres )\n");
		printf("________________________________________________________________________________________________________________________\n\n\t");
		scanf("%s", tmp);
		getchar();
		if (!verif(tmp) || (strlen(tmp) > 12 && (tmp[0] <= '9' && tmp[0] >= '0')) || strlen(tmp) > 13)
			{
				printf("\a\n");
				if(!verif(tmp))
					{
						printf("\t\tErreur : L'insertion est invalide !");
						getchar();
					}
				else
					{
						printf("\t\tErreur : Le nombre depasse la limite !");
						getchar();
					}
			}
	} while (!verif(tmp) || (strlen(tmp) > 12 && (tmp[0] <= '9' && tmp[0] >= '0')) || strlen(tmp) > 13);
	
	int i, l = strlen(tmp), index;
	string inp, fl = NULL, zer = NULL;
	
	index = IsFloat(tmp);
	
	if (index)
	{
		int count = 0;
		for (i = index; i < l; i++)
			count++;
			
		fl = str_init(14 - count);
		string fltmp = str_init(count);
		
		strncpy(fltmp, tmp + index, count);
		str_del_last(fltmp);
		
		zer = malloc(12 * sizeof(char));
		
		str_dep_zero(fltmp, zer);
		zer = realloc(zer, sizeof(char) * strlen(zer));
		
		strcat(fl, fltmp);
		tmp = realloc(tmp, (l - count) * sizeof(char));
		tmp[index] = '\0';
	}
	
	l = strlen(tmp);
	*flag = 1;
	
	if (!IsDigit(tmp[0]))
	{
		inp = str_init(14 - l);
		
		if (tmp[0] == 45)
		{
			printf(" Moins");
			*flag = 0;
		}
		
		str_del_last(tmp);
	}
	else
	{
		inp = str_init(13 - l);
	}
	
	strcat(inp, tmp);
	free(tmp);
	
	Result[0] = inp;
	Result[1] = zer;
	Result[2] = fl;
	return Result;
}

//recherche un caractere dans une chaine de caracteres jusqu'a un indice i
int Exists(char c , string str , int i)
{
	int j = 0;
	while(str[j] != '\0' && j < i)
	{
		if(str[j] == c)
		{
			return j;
		}
		j++;
	}
	return 0;
}

// pour verifier si l'entree est bien un nombre
bool verif(string input)
{
	int length = strlen(input), i = 0;
	while (i < length)
	{
		if (!IsDigit(input[i]))
			if(i != 0)
			{
				if(input[i] == 43 || input[i] == 45 || input[i] != '.' || Exists('.',input,i) || !IsDigit(input[i-1]) )
				{
					return false;
				}
			}
			else if(input[i] != 43 && input[i] != 45)
				return false;	
		i++;
	}
	if(input[length-1] == '.')
	{
		return false;
	}
	return true;
}

// pour retourner les 3 premiers chiffres du nombre
string divide(string input)
{
	int l = strlen(input), i;
	string divided = malloc(3 * sizeof(char));
	divided = strncpy(divided, input, 3);
	for (i = 0; i < l - 3; i++)
	{
		input[i] = input[i + 3];
	}
	input[i] = '\0';
	if (l >= 3)
		input = realloc(input, (l - 3) * sizeof(char));
	else
		input = realloc(input, sizeof(char));
	return divided;
}

// pour traduire le nombre en lettres
string translate(string input)
{
	int i = 0, num = 0;
	for (i = 0; i < strlen(input) && input[i] <= '9' && input[i] >= '0'; i++)
	{
		num = num * 10 + input[i] - 48;
	}
	
	return Load(num);
}

// pour verifier si le nombre est nul
bool isZero(string str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
		{
			return false;
		}
		i++;
	}
	return true;
}
string Load(int i)
{
	FILE* fp = fopen("NBRS.txt","r+");
	
	if(fp == NULL)
	{
		printf("ERREUR LORS DE L'OUVERTURE DU FICHIER !");
		getchar();
		exit(0);
	}
	
	else{
		int k = 0;
		string* nombres = malloc(sizeof(string));
		
		while(!feof(fp) && k < i+1)
		{
			k++;
			nombres = realloc(nombres,(k+1)*sizeof(string));
			nombres[k] = malloc(100*sizeof(char));
			int l = 0;
			char in;
			do{
				in = fgetc(fp);
				if(in != '\n' && !feof(fp))
				{
					nombres[k][l] = in;
				}
				else {
					nombres[k][l] = '\0';
				}
				l++;
			}while(l < 100 && in != '\n');
			nombres[k] = realloc(nombres[k],(strlen(nombres[k]))*sizeof(char));
		}
		
		return nombres[k];	
	}
}
