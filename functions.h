#include <stdio.h>
#include <stdbool.h>

struct el{
    int klucz;
    struct el* nast;
};

typedef struct el elListy;
typedef elListy *lista;

void wyswietl_liste(lista l);
void drukuj_odw(lista l);
void dodac_na_poczatek(lista *l, int num);
void dodac_na_koniec(lista *l, int num);
void usun_pierwszy_element(lista *l);
void usun_ostatni_element(lista *l);
bool szukanie(lista l, int x);
bool usuwanie_znalezionego(lista *l, int x);
lista odwroc_liste(lista l);
lista odwroc_rekurencyjnie(lista l);
void wczytaj_z_pliku(lista *l);
void dodaj_za_wskazanym(lista *l, int x, int target);
void dodaj_przed_wskazanym(lista *l, int x, int target);
void usun_wystapienia(lista *l, int x);
void usun_wystapienia_rekur(lista *l, int x);
void usun_niepodz(lista *l, int x);
int najwiecej_wystepujacy(lista l);
void usun_powtarzania(lista*);