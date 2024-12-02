#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char* string;

string *input(int*);
string divide(string);
string translate(string);
bool isZero(string);
bool verif(string);
int Exists(char,string,int);

// nombres de 0 jusqu'a 999
string NBR[] = {"zero", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix", "onze", "douze", "treize", "quatorze", "quinze", "seize", "dix-sept", "dix-huit", "dix-neuf", "vingt", "vingt-un", "vingt-deux", "vingt-trois", "vingt-quatre", "vingt-cinq", "vingt-six", "vingt-sept", "vingt-huit", "vingt-neuf", "trente", "trente-un", "trente-deux", "trente-trois", "trente-quatre", "trente-cinq", "trente-six", "trente-sept", "trente-huit", "trente-neuf", "quarante", "quarante-un", "quarante-deux", "quarante-trois", "quarante-quatre", "quarante-cinq", "quarante-six", "quarante-sept", "quarante-huit", "quarante-neuf", "cinquante", "cinquante-un", "cinquante-deux", "cinquante-trois", "cinquante-quatre", "cinquante-cinq", "cinquante-six", "cinquante-sept", "cinquante-huit", "cinquante-neuf", "soixante", "soixante-un", "soixante-deux", "soixante-trois", "soixante-quatre", "soixante-cinq", "soixante-six", "soixante-sept", "soixante-huit", "soixante-neuf", "soixante-dix-", "soixante et onze", "soixante-douze", "soixante-treize", "soixante-quatorze", "soixante-quinze", "soixante-seize", "soixante-dix-sept", "soixante-dix-huit", "soixante-dix-neuf", "quatre-vingt", "quatre-vingt-un", "quatre-vingt-deux", "quatre-vingt-trois", "quatre-vingt-quatre", "quatre-vingt-cinq", "quatre-vingt-six", "quatre-vingt-sept", "quatre-vingt-huit", "quatre-vingt-neuf", "quatre-vingt-dix-", "quatre-vingt-onze", "quatre-vingt-douze", "quatre-vingt-treize", "quatre-vingt-quatorze", "quatre-vingt-quinze", "quatre-vingt-seize", "quatre-vingt-dix-sept", "quatre-vingt-dix-huit", "quatre-vingt-dix-neuf", "cent", "cent un", "cent deux", "cent trois", "cent quatre", "cent cinq", "cent six", "cent sept", "cent huit", "cent neuf", "cent dix", "cent onze", "cent douze", "cent treize", "cent quatorze", "cent quinze", "cent seize", "cent dix-sept", "cent dix-huit", "cent dix-neuf", "cent vingt", "cent vingt-un", "cent vingt-deux", "cent vingt-trois", "cent vingt-quatre", "cent vingt-cinq", "cent vingt-six", "cent vingt-sept", "cent vingt-huit", "cent vingt-neuf", "cent trente", "cent trente-un", "cent trente-deux", "cent trente-trois", "cent trente-quatre", "cent trente-cinq", "cent trente-six", "cent trente-sept", "cent trente-huit", "cent trente-neuf", "cent quarante", "cent quarante-un", "cent quarante-deux", "cent quarante-trois", "cent quarante-quatre", "cent quarante-cinq", "cent quarante-six", "cent quarante-sept", "cent quarante-huit", "cent quarante-neuf", "cent cinquante", "cent cinquante-un", "cent cinquante-deux", "cent cinquante-trois", "cent cinquante-quatre", "cent cinquante-cinq", "cent cinquante-six", "cent cinquante-sept", "cent cinquante-huit", "cent cinquante-neuf", "cent soixante", "cent soixante-un", "cent soixante-deux", "cent soixante-trois", "cent soixante-quatre", "cent soixante-cinq", "cent soixante-six", "cent soixante-sept", "cent soixante-huit", "cent soixante-neuf", "cent soixante-dix", "cent soixante et onze", "cent soixante-douze", "cent soixante-treize", "cent soixante-quatorze", "cent soixante-quinze", "cent soixante-seize", "cent soixante-dix-sept", "cent soixante-dix-huit", "cent soixante-dix-neuf", "cent quatre-vingt", "cent quatre-vingt-un", "cent quatre-vingt-deux", "cent quatre-vingt-trois", "cent quatre-vingt-quatre", "cent quatre-vingt-cinq", "cent quatre-vingt-six", "cent quatre-vingt-sept", "cent quatre-vingt-huit", "cent quatre-vingt-neuf", "cent quatre-vingt-dix", "cent quatre-vingt-onze", "cent quatre-vingt-douze", "cent quatre-vingt-treize", "cent quatre-vingt-quatorze", "cent quatre-vingt-quinze", "cent quatre-vingt-seize", "cent quatre-vingt-dix-sept", "cent quatre-vingt-dix-huit", "cent quatre-vingt-dix-neuf", "deux-cents", "deux-cent un", "deux-cent deux", "deux-cent trois", "deux-cent quatre", "deux-cent cinq", "deux-cent six", "deux-cent sept", "deux-cent huit", "deux-cent neuf", "deux-cent dix", "deux-cent onze", "deux-cent douze", "deux-cent treize", "deux-cent quatorze", "deux-cent quinze", "deux-cent seize", "deux-cent dix-sept", "deux-cent dix-huit", "deux-cent dix-neuf", "deux-cent vingt", "deux-cent vingt-un", "deux-cent vingt-deux", "deux-cent vingt-trois", "deux-cent vingt-quatre", "deux-cent vingt-cinq", "deux-cent vingt-six", "deux-cent vingt-sept", "deux-cent vingt-huit", "deux-cent vingt-neuf", "deux-cent trente", "deux-cent trente-un", "deux-cent trente-deux", "deux-cent trente-trois", "deux-cent trente-quatre", "deux-cent trente-cinq", "deux-cent trente-six", "deux-cent trente-sept", "deux-cent trente-huit", "deux-cent trente-neuf", "deux-cent quarante", "deux-cent quarante-un", "deux-cent quarante-deux", "deux-cent quarante-trois", "deux-cent quarante-quatre", "deux-cent quarante-cinq", "deux-cent quarante-six", "deux-cent quarante-sept", "deux-cent quarante-huit", "deux-cent quarante-neuf", "deux-cent cinquante", "deux-cent cinquante-un", "deux-cent cinquante-deux", "deux-cent cinquante-trois", "deux-cent cinquante-quatre", "deux-cent cinquante-cinq", "deux-cent cinquante-six", "deux-cent cinquante-sept", "deux-cent cinquante-huit", "deux-cent cinquante-neuf", "deux-cent soixante", "deux-cent soixante-un", "deux-cent soixante-deux", "deux-cent soixante-trois", "deux-cent soixante-quatre", "deux-cent soixante-cinq", "deux-cent soixante-six", "deux-cent soixante-sept", "deux-cent soixante-huit", "deux-cent soixante-neuf", "deux-cent soixante-dix", "deux-cent soixante et onze", "deux-cent soixante-douze", "deux-cent soixante-treize", "deux-cent soixante-quatorze", "deux-cent soixante-quinze", "deux-cent soixante-seize", "deux-cent soixante-dix-sept", "deux-cent soixante-dix-huit", "deux-cent soixante-dix-neuf", "deux-cent quatre-vingt", "deux-cent quatre-vingt-un", "deux-cent quatre-vingt-deux", "deux-cent quatre-vingt-trois", "deux-cent quatre-vingt-quatre", "deux-cent quatre-vingt-cinq", "deux-cent quatre-vingt-six", "deux-cent quatre-vingt-sept", "deux-cent quatre-vingt-huit", "deux-cent quatre-vingt-neuf", "deux-cent quatre-vingt-dix", "deux-cent quatre-vingt-onze", "deux-cent quatre-vingt-douze", "deux-cent quatre-vingt-treize", "deux-cent quatre-vingt-quatorze", "deux-cent quatre-vingt-quinze", "deux-cent quatre-vingt-seize", "deux-cent quatre-vingt-dix-sept", "deux-cent quatre-vingt-dix-huit", "deux-cent quatre-vingt-dix-neuf", "trois-cents", "trois-cent un", "trois-cent deux", "trois-cent trois", "trois-cent quatre", "trois-cent cinq", "trois-cent six", "trois-cent sept", "trois-cent huit", "trois-cent neuf", "trois-cent dix", "trois-cent onze", "trois-cent douze", "trois-cent treize", "trois-cent quatorze", "trois-cent quinze", "trois-cent seize", "trois-cent dix-sept", "trois-cent dix-huit", "trois-cent dix-neuf", "trois-cent vingt", "trois-cent vingt-un", "trois-cent vingt-deux", "trois-cent vingt-trois", "trois-cent vingt-quatre", "trois-cent vingt-cinq", "trois-cent vingt-six", "trois-cent vingt-sept", "trois-cent vingt-huit", "trois-cent vingt-neuf", "trois-cent trente", "trois-cent trente-un", "trois-cent trente-deux", "trois-cent trente-trois", "trois-cent trente-quatre", "trois-cent trente-cinq", "trois-cent trente-six", "trois-cent trente-sept", "trois-cent trente-huit", "trois-cent trente-neuf", "trois-cent quarante", "trois-cent quarante-un", "trois-cent quarante-deux", "trois-cent quarante-trois", "trois-cent quarante-quatre", "trois-cent quarante-cinq", "trois-cent quarante-six", "trois-cent quarante-sept", "trois-cent quarante-huit", "trois-cent quarante-neuf", "trois-cent cinquante", "trois-cent cinquante-un", "trois-cent cinquante-deux", "trois-cent cinquante-trois", "trois-cent cinquante-quatre", "trois-cent cinquante-cinq", "trois-cent cinquante-six", "trois-cent cinquante-sept", "trois-cent cinquante-huit", "trois-cent cinquante-neuf", "trois-cent soixante", "trois-cent soixante-un", "trois-cent soixante-deux", "trois-cent soixante-trois", "trois-cent soixante-quatre", "trois-cent soixante-cinq", "trois-cent soixante-six", "trois-cent soixante-sept", "trois-cent soixante-huit", "trois-cent soixante-neuf", "trois-cent soixante-dix", "trois-cent soixante et onze", "trois-cent soixante-douze", "trois-cent soixante-treize", "trois-cent soixante-quatorze", "trois-cent soixante-quinze", "trois-cent soixante-seize", "trois-cent soixante-dix-sept", "trois-cent soixante-dix-huit", "trois-cent soixante-dix-neuf", "trois-cent quatre-vingt", "trois-cent quatre-vingt-un", "trois-cent quatre-vingt-deux", "trois-cent quatre-vingt-trois", "trois-cent quatre-vingt-quatre", "trois-cent quatre-vingt-cinq", "trois-cent quatre-vingt-six", "trois-cent quatre-vingt-sept", "trois-cent quatre-vingt-huit", "trois-cent quatre-vingt-neuf", "trois-cent quatre-vingt-dix", "trois-cent quatre-vingt-onze", "trois-cent quatre-vingt-douze", "trois-cent quatre-vingt-treize", "trois-cent quatre-vingt-quatorze", "trois-cent quatre-vingt-quinze", "trois-cent quatre-vingt-seize", "trois-cent quatre-vingt-dix-sept", "trois-cent quatre-vingt-dix-huit", "trois-cent quatre-vingt-dix-neuf", "quatre-cents", "quatre-cent un", "quatre-cent deux", "quatre-cent trois", "quatre-cent quatre", "quatre-cent cinq", "quatre-cent six", "quatre-cent sept", "quatre-cent huit", "quatre-cent neuf", "quatre-cent dix", "quatre-cent onze", "quatre-cent douze", "quatre-cent treize", "quatre-cent quatorze", "quatre-cent quinze", "quatre-cent seize", "quatre-cent dix-sept", "quatre-cent dix-huit", "quatre-cent dix-neuf", "quatre-cent vingt", "quatre-cent vingt-un", "quatre-cent vingt-deux", "quatre-cent vingt-trois", "quatre-cent vingt-quatre", "quatre-cent vingt-cinq", "quatre-cent vingt-six", "quatre-cent vingt-sept", "quatre-cent vingt-huit", "quatre-cent vingt-neuf", "quatre-cent trente", "quatre-cent trente-un", "quatre-cent trente-deux", "quatre-cent trente-trois", "quatre-cent trente-quatre", "quatre-cent trente-cinq", "quatre-cent trente-six", "quatre-cent trente-sept", "quatre-cent trente-huit", "quatre-cent trente-neuf", "quatre-cent quarante", "quatre-cent quarante-un", "quatre-cent quarante-deux", "quatre-cent quarante-trois", "quatre-cent quarante-quatre", "quatre-cent quarante-cinq", "quatre-cent quarante-six", "quatre-cent quarante-sept", "quatre-cent quarante-huit", "quatre-cent quarante-neuf", "quatre-cent cinquante", "quatre-cent cinquante-un", "quatre-cent cinquante-deux", "quatre-cent cinquante-trois", "quatre-cent cinquante-quatre", "quatre-cent cinquante-cinq", "quatre-cent cinquante-six", "quatre-cent cinquante-sept", "quatre-cent cinquante-huit", "quatre-cent cinquante-neuf", "quatre-cent soixante", "quatre-cent soixante-un", "quatre-cent soixante-deux", "quatre-cent soixante-trois", "quatre-cent soixante-quatre", "quatre-cent soixante-cinq", "quatre-cent soixante-six", "quatre-cent soixante-sept", "quatre-cent soixante-huit", "quatre-cent soixante-neuf", "quatre-cent soixante-dix", "quatre-cent soixante et onze", "quatre-cent soixante-douze", "quatre-cent soixante-treize", "quatre-cent soixante-quatorze", "quatre-cent soixante-quinze", "quatre-cent soixante-seize", "quatre-cent soixante-dix-sept", "quatre-cent soixante-dix-huit", "quatre-cent soixante-dix-neuf", "quatre-cent quatre-vingt", "quatre-cent quatre-vingt-un", "quatre-cent quatre-vingt-deux", "quatre-cent quatre-vingt-trois", "quatre-cent quatre-vingt-quatre", "quatre-cent quatre-vingt-cinq", "quatre-cent quatre-vingt-six", "quatre-cent quatre-vingt-sept", "quatre-cent quatre-vingt-huit", "quatre-cent quatre-vingt-neuf", "quatre-cent quatre-vingt-dix", "quatre-cent quatre-vingt-onze", "quatre-cent quatre-vingt-douze", "quatre-cent quatre-vingt-treize", "quatre-cent quatre-vingt-quatorze", "quatre-cent quatre-vingt-quinze", "quatre-cent quatre-vingt-seize", "quatre-cent quatre-vingt-dix-sept", "quatre-cent quatre-vingt-dix-huit", "quatre-cent quatre-vingt-dix-neuf", "cinq-cents", "cinq-cent un", "cinq-cent deux", "cinq-cent trois", "cinq-cent quatre", "cinq-cent cinq", "cinq-cent six", "cinq-cent sept", "cinq-cent huit", "cinq-cent neuf", "cinq-cent dix", "cinq-cent onze", "cinq-cent douze", "cinq-cent treize", "cinq-cent quatorze", "cinq-cent quinze", "cinq-cent seize", "cinq-cent dix-sept", "cinq-cent dix-huit", "cinq-cent dix-neuf", "cinq-cent vingt", "cinq-cent vingt-un", "cinq-cent vingt-deux", "cinq-cent vingt-trois", "cinq-cent vingt-quatre", "cinq-cent vingt-cinq", "cinq-cent vingt-six", "cinq-cent vingt-sept", "cinq-cent vingt-huit", "cinq-cent vingt-neuf", "cinq-cent trente", "cinq-cent trente-un", "cinq-cent trente-deux", "cinq-cent trente-trois", "cinq-cent trente-quatre", "cinq-cent trente-cinq", "cinq-cent trente-six", "cinq-cent trente-sept", "cinq-cent trente-huit", "cinq-cent trente-neuf", "cinq-cent quarante", "cinq-cent quarante-un", "cinq-cent quarante-deux", "cinq-cent quarante-trois", "cinq-cent quarante-quatre", "cinq-cent quarante-cinq", "cinq-cent quarante-six", "cinq-cent quarante-sept", "cinq-cent quarante-huit", "cinq-cent quarante-neuf", "cinq-cent cinquante", "cinq-cent cinquante-un", "cinq-cent cinquante-deux", "cinq-cent cinquante-trois", "cinq-cent cinquante-quatre", "cinq-cent cinquante-cinq", "cinq-cent cinquante-six", "cinq-cent cinquante-sept", "cinq-cent cinquante-huit", "cinq-cent cinquante-neuf", "cinq-cent soixante", "cinq-cent soixante-un", "cinq-cent soixante-deux", "cinq-cent soixante-trois", "cinq-cent soixante-quatre", "cinq-cent soixante-cinq", "cinq-cent soixante-six", "cinq-cent soixante-sept", "cinq-cent soixante-huit", "cinq-cent soixante-neuf", "cinq-cent soixante-dix", "cinq-cent soixante et onze", "cinq-cent soixante-douze", "cinq-cent soixante-treize", "cinq-cent soixante-quatorze", "cinq-cent soixante-quinze", "cinq-cent soixante-seize", "cinq-cent soixante-dix-sept", "cinq-cent soixante-dix-huit", "cinq-cent soixante-dix-neuf", "cinq-cent quatre-vingt", "cinq-cent quatre-vingt-un", "cinq-cent quatre-vingt-deux", "cinq-cent quatre-vingt-trois", "cinq-cent quatre-vingt-quatre", "cinq-cent quatre-vingt-cinq", "cinq-cent quatre-vingt-six", "cinq-cent quatre-vingt-sept", "cinq-cent quatre-vingt-huit", "cinq-cent quatre-vingt-neuf", "cinq-cent quatre-vingt-dix", "cinq-cent quatre-vingt-onze", "cinq-cent quatre-vingt-douze", "cinq-cent quatre-vingt-treize", "cinq-cent quatre-vingt-quatorze", "cinq-cent quatre-vingt-quinze", "cinq-cent quatre-vingt-seize", "cinq-cent quatre-vingt-dix-sept", "cinq-cent quatre-vingt-dix-huit", "cinq-cent quatre-vingt-dix-neuf", "six-cents", "six-cent un", "six-cent deux", "six-cent trois", "six-cent quatre", "six-cent cinq", "six-cent six", "six-cent sept", "six-cent huit", "six-cent neuf", "six-cent dix", "six-cent onze", "six-cent douze", "six-cent treize", "six-cent quatorze", "six-cent quinze", "six-cent seize", "six-cent dix-sept", "six-cent dix-huit", "six-cent dix-neuf", "six-cent vingt", "six-cent vingt-un", "six-cent vingt-deux", "six-cent vingt-trois", "six-cent vingt-quatre", "six-cent vingt-cinq", "six-cent vingt-six", "six-cent vingt-sept", "six-cent vingt-huit", "six-cent vingt-neuf", "six-cent trente", "six-cent trente-un", "six-cent trente-deux", "six-cent trente-trois", "six-cent trente-quatre", "six-cent trente-cinq", "six-cent trente-six", "six-cent trente-sept", "six-cent trente-huit", "six-cent trente-neuf", "six-cent quarante", "six-cent quarante-un", "six-cent quarante-deux", "six-cent quarante-trois", "six-cent quarante-quatre", "six-cent quarante-cinq", "six-cent quarante-six", "six-cent quarante-sept", "six-cent quarante-huit", "six-cent quarante-neuf", "six-cent cinquante", "six-cent cinquante-un", "six-cent cinquante-deux", "six-cent cinquante-trois", "six-cent cinquante-quatre", "six-cent cinquante-cinq", "six-cent cinquante-six", "six-cent cinquante-sept", "six-cent cinquante-huit", "six-cent cinquante-neuf", "six-cent soixante", "six-cent soixante-un", "six-cent soixante-deux", "six-cent soixante-trois", "six-cent soixante-quatre", "six-cent soixante-cinq", "six-cent soixante-six", "six-cent soixante-sept", "six-cent soixante-huit", "six-cent soixante-neuf", "six-cent soixante-dix", "six-cent soixante et onze", "six-cent soixante-douze", "six-cent soixante-treize", "six-cent soixante-quatorze", "six-cent soixante-quinze", "six-cent soixante-seize", "six-cent soixante-dix-sept", "six-cent soixante-dix-huit", "six-cent soixante-dix-neuf", "six-cent quatre-vingt", "six-cent quatre-vingt-un", "six-cent quatre-vingt-deux", "six-cent quatre-vingt-trois", "six-cent quatre-vingt-quatre", "six-cent quatre-vingt-cinq", "six-cent quatre-vingt-six", "six-cent quatre-vingt-sept", "six-cent quatre-vingt-huit", "six-cent quatre-vingt-neuf", "six-cent quatre-vingt-dix", "six-cent quatre-vingt-onze", "six-cent quatre-vingt-douze", "six-cent quatre-vingt-treize", "six-cent quatre-vingt-quatorze", "six-cent quatre-vingt-quinze", "six-cent quatre-vingt-seize", "six-cent quatre-vingt-dix-sept", "six-cent quatre-vingt-dix-huit", "six-cent quatre-vingt-dix-neuf", "sept-cents", "sept-cent un", "sept-cent deux", "sept-cent trois", "sept-cent quatre", "sept-cent cinq", "sept-cent six", "sept-cent sept", "sept-cent huit", "sept-cent neuf", "sept-cent dix", "sept-cent onze", "sept-cent douze", "sept-cent treize", "sept-cent quatorze", "sept-cent quinze", "sept-cent seize", "sept-cent dix-sept", "sept-cent dix-huit", "sept-cent dix-neuf", "sept-cent vingt", "sept-cent vingt-un", "sept-cent vingt-deux", "sept-cent vingt-trois", "sept-cent vingt-quatre", "sept-cent vingt-cinq", "sept-cent vingt-six", "sept-cent vingt-sept", "sept-cent vingt-huit", "sept-cent vingt-neuf", "sept-cent trente", "sept-cent trente-un", "sept-cent trente-deux", "sept-cent trente-trois", "sept-cent trente-quatre", "sept-cent trente-cinq", "sept-cent trente-six", "sept-cent trente-sept", "sept-cent trente-huit", "sept-cent trente-neuf", "sept-cent quarante", "sept-cent quarante-un", "sept-cent quarante-deux", "sept-cent quarante-trois", "sept-cent quarante-quatre", "sept-cent quarante-cinq", "sept-cent quarante-six", "sept-cent quarante-sept", "sept-cent quarante-huit", "sept-cent quarante-neuf", "sept-cent cinquante", "sept-cent cinquante-un", "sept-cent cinquante-deux", "sept-cent cinquante-trois", "sept-cent cinquante-quatre", "sept-cent cinquante-cinq", "sept-cent cinquante-six", "sept-cent cinquante-sept", "sept-cent cinquante-huit", "sept-cent cinquante-neuf", "sept-cent soixante", "sept-cent soixante-un", "sept-cent soixante-deux", "sept-cent soixante-trois", "sept-cent soixante-quatre", "sept-cent soixante-cinq", "sept-cent soixante-six", "sept-cent soixante-sept", "sept-cent soixante-huit", "sept-cent soixante-neuf", "sept-cent soixante-dix", "sept-cent soixante et onze", "sept-cent soixante-douze", "sept-cent soixante-treize", "sept-cent soixante-quatorze", "sept-cent soixante-quinze", "sept-cent soixante-seize", "sept-cent soixante-dix-sept", "sept-cent soixante-dix-huit", "sept-cent soixante-dix-neuf", "sept-cent quatre-vingt", "sept-cent quatre-vingt-un", "sept-cent quatre-vingt-deux", "sept-cent quatre-vingt-trois", "sept-cent quatre-vingt-quatre", "sept-cent quatre-vingt-cinq", "sept-cent quatre-vingt-six", "sept-cent quatre-vingt-sept", "sept-cent quatre-vingt-huit", "sept-cent quatre-vingt-neuf", "sept-cent quatre-vingt-dix", "sept-cent quatre-vingt-onze", "sept-cent quatre-vingt-douze", "sept-cent quatre-vingt-treize", "sept-cent quatre-vingt-quatorze", "sept-cent quatre-vingt-quinze", "sept-cent quatre-vingt-seize", "sept-cent quatre-vingt-dix-sept", "sept-cent quatre-vingt-dix-huit", "sept-cent quatre-vingt-dix-neuf", "huit-cents", "huit-cent un", "huit-cent deux", "huit-cent trois", "huit-cent quatre", "huit-cent cinq", "huit-cent six", "huit-cent sept", "huit-cent huit", "huit-cent neuf", "huit-cent dix", "huit-cent onze", "huit-cent douze", "huit-cent treize", "huit-cent quatorze", "huit-cent quinze", "huit-cent seize", "huit-cent dix-sept", "huit-cent dix-huit", "huit-cent dix-neuf", "huit-cent vingt", "huit-cent vingt-un", "huit-cent vingt-deux", "huit-cent vingt-trois", "huit-cent vingt-quatre", "huit-cent vingt-cinq", "huit-cent vingt-six", "huit-cent vingt-sept", "huit-cent vingt-huit", "huit-cent vingt-neuf", "huit-cent trente", "huit-cent trente-un", "huit-cent trente-deux", "huit-cent trente-trois", "huit-cent trente-quatre", "huit-cent trente-cinq", "huit-cent trente-six", "huit-cent trente-sept", "huit-cent trente-huit", "huit-cent trente-neuf", "huit-cent quarante", "huit-cent quarante-un", "huit-cent quarante-deux", "huit-cent quarante-trois", "huit-cent quarante-quatre", "huit-cent quarante-cinq", "huit-cent quarante-six", "huit-cent quarante-sept", "huit-cent quarante-huit", "huit-cent quarante-neuf", "huit-cent cinquante", "huit-cent cinquante-un", "huit-cent cinquante-deux", "huit-cent cinquante-trois", "huit-cent cinquante-quatre", "huit-cent cinquante-cinq", "huit-cent cinquante-six", "huit-cent cinquante-sept", "huit-cent cinquante-huit", "huit-cent cinquante-neuf", "huit-cent soixante", "huit-cent soixante-un", "huit-cent soixante-deux", "huit-cent soixante-trois", "huit-cent soixante-quatre", "huit-cent soixante-cinq", "huit-cent soixante-six", "huit-cent soixante-sept", "huit-cent soixante-huit", "huit-cent soixante-neuf", "huit-cent soixante-dix", "huit-cent soixante et onze", "huit-cent soixante-douze", "huit-cent soixante-treize", "huit-cent soixante-quatorze", "huit-cent soixante-quinze", "huit-cent soixante-seize", "huit-cent soixante-dix-sept", "huit-cent soixante-dix-huit", "huit-cent soixante-dix-neuf", "huit-cent quatre-vingt", "huit-cent quatre-vingt-un", "huit-cent quatre-vingt-deux", "huit-cent quatre-vingt-trois", "huit-cent quatre-vingt-quatre", "huit-cent quatre-vingt-cinq", "huit-cent quatre-vingt-six", "huit-cent quatre-vingt-sept", "huit-cent quatre-vingt-huit", "huit-cent quatre-vingt-neuf", "huit-cent quatre-vingt-dix", "huit-cent quatre-vingt-onze", "huit-cent quatre-vingt-douze", "huit-cent quatre-vingt-treize", "huit-cent quatre-vingt-quatorze", "huit-cent quatre-vingt-quinze", "huit-cent quatre-vingt-seize", "huit-cent quatre-vingt-dix-sept", "huit-cent quatre-vingt-dix-huit", "huit-cent quatre-vingt-dix-neuf", "neuf-cents", "neuf-cent un", "neuf-cent deux", "neuf-cent trois", "neuf-cent quatre", "neuf-cent cinq", "neuf-cent six", "neuf-cent sept", "neuf-cent huit", "neuf-cent neuf", "neuf-cent dix", "neuf-cent onze", "neuf-cent douze", "neuf-cent treize", "neuf-cent quatorze", "neuf-cent quinze", "neuf-cent seize", "neuf-cent dix-sept", "neuf-cent dix-huit", "neuf-cent dix-neuf", "neuf-cent vingt", "neuf-cent vingt-un", "neuf-cent vingt-deux", "neuf-cent vingt-trois", "neuf-cent vingt-quatre", "neuf-cent vingt-cinq", "neuf-cent vingt-six", "neuf-cent vingt-sept", "neuf-cent vingt-huit", "neuf-cent vingt-neuf", "neuf-cent trente", "neuf-cent trente-un", "neuf-cent trente-deux", "neuf-cent trente-trois", "neuf-cent trente-quatre", "neuf-cent trente-cinq", "neuf-cent trente-six", "neuf-cent trente-sept", "neuf-cent trente-huit", "neuf-cent trente-neuf", "neuf-cent quarante", "neuf-cent quarante-un", "neuf-cent quarante-deux", "neuf-cent quarante-trois", "neuf-cent quarante-quatre", "neuf-cent quarante-cinq", "neuf-cent quarante-six", "neuf-cent quarante-sept", "neuf-cent quarante-huit", "neuf-cent quarante-neuf", "neuf-cent cinquante", "neuf-cent cinquante-un", "neuf-cent cinquante-deux", "neuf-cent cinquante-trois", "neuf-cent cinquante-quatre", "neuf-cent cinquante-cinq", "neuf-cent cinquante-six", "neuf-cent cinquante-sept", "neuf-cent cinquante-huit", "neuf-cent cinquante-neuf", "neuf-cent soixante", "neuf-cent soixante-un", "neuf-cent soixante-deux", "neuf-cent soixante-trois", "neuf-cent soixante-quatre", "neuf-cent soixante-cinq", "neuf-cent soixante-six", "neuf-cent soixante-sept", "neuf-cent soixante-huit", "neuf-cent soixante-neuf", "neuf-cent soixante-dix", "neuf-cent soixante et onze", "neuf-cent soixante-douze", "neuf-cent soixante-treize", "neuf-cent soixante-quatorze", "neuf-cent soixante-quinze", "neuf-cent soixante-seize", "neuf-cent soixante-dix-sept", "neuf-cent soixante-dix-huit", "neuf-cent soixante-dix-neuf", "neuf-cent quatre-vingt", "neuf-cent quatre-vingt-un", "neuf-cent quatre-vingt-deux", "neuf-cent quatre-vingt-trois", "neuf-cent quatre-vingt-quatre", "neuf-cent quatre-vingt-cinq", "neuf-cent quatre-vingt-six", "neuf-cent quatre-vingt-sept", "neuf-cent quatre-vingt-huit", "neuf-cent quatre-vingt-neuf", "neuf-cent quatre-vingt-dix", "neuf-cent quatre-vingt-onze", "neuf-cent quatre-vingt-douze", "neuf-cent quatre-vingt-treize", "neuf-cent quatre-vingt-quatorze", "neuf-cent quatre-vingt-quinze", "neuf-cent quatre-vingt-seize", "neuf-cent quatre-vingt-dix-sept", "neuf-cent quatre-vingt-dix-huit", "neuf-cent quatre-vingt-dix-neuf"};

// fonction principale
int main()
{
	int j,flag;
	string* Entree;
	
	system("color F0");
	Entree = input(&flag);
	
	string Pentiere[4] = {divide(Entree[0]), divide(Entree[0]), divide(Entree[0]), divide(Entree[0])};
	string Preelle[4];
	string Ordre[4] = {"Milliards", "Millions", "Mille", ""};
	
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
	string str = malloc(size * sizeof(char));
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
			return j;
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
	
	return NBR[num];
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
