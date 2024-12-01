#include <malloc.h>
#include "functions.h"

void wyswietl_liste(lista l){
    lista p = l;
    printf("[ ");
    while(p){
        printf("%d ", p->klucz);
        p = p->nast;
    }
    printf("]\n");
}

void dodac_na_poczatek(lista *l, int num){
    lista p = malloc(sizeof(elListy));
    p->klucz = num;
    p->nast = *l;
    *l = p;
}

void dodac_na_koniec(lista *l, int num){
    lista p = malloc(sizeof(elListy));
    p->klucz = num;
    p->nast = 0;
    while((*l)){
        l = &(*l)->nast;
    }
    *l = p;
}


void usun_pierwszy_element(lista *l){
    lista p;
    if(*l != 0){
        p = *l;
        *l = (*l)->nast;
        free(p);
    }
}


void usun_ostatni_element(lista *l){
    if(*l == 0){
        return;
    }
    while((*l)->nast){
        l = &(*l)->nast;
    }
    free(*l);
    *l = 0;
}


bool szukanie(lista l, int x){
    lista p = l;
    while(p){
        if(p->klucz == x){
            printf("Element znaleziony\n");
            return true;
        }
        p = p->nast;
    }
    printf("Element nie znaleziony\n");
    return false;
}

bool usuwanie_znalezionego(lista *l, int x){
    lista p;
    while((*l)){
        if((*l)->klucz == x){
            p = (*l);
            (*l) = (*l)->nast;
            printf("Element znaleziony i ususniety\n");
            free(p);
            return true;
        }
        else{
            l = &(*l)->nast;
        }
    }
    printf("Element nie znaleziony\n");
    return false;
}


lista odwroc_liste(lista l){
    lista curr = l, prev = 0, nast;
    while(curr){
        nast = curr->nast;
        curr->nast = prev;
        prev = curr;
        curr = nast;
    }
    return prev;
}


lista odwroc_rekurencyjnie(lista l){
    if(l == NULL || l->nast == NULL){
        return l;
    }

    lista rev = odwroc_rekurencyjnie(l->nast);
    l->nast->nast = l;
    l->nast = NULL;

    return rev;
}


void drukuj_odw(lista l){

    if(l){
        if(l->nast == 0){
            printf("[ ");
            printf("%d ", l->klucz);
        }
        else{
            drukuj_odw(l->nast);
            printf("%d ", l->klucz);
        }
    }
}


void dodaj_za_wskazanym(lista *l, int x, int target){
    lista p = malloc(sizeof(elListy));
    p->klucz = x;
    p->nast = 0;
    while((*l)){
        if((*l)->klucz == target){
            p->nast = (*l)->nast;
            (*l)->nast = p;
            return;
        }
        else{
            l = &(*l)->nast;
        }
    }
}


void dodaj_przed_wskazanym(lista *l, int x, int target){
    lista p = malloc(sizeof(elListy));
    p->klucz = x;
    p->nast = 0;
    while(*l){
        if((*l)->klucz == target){
            p->klucz = (*l)->klucz;
            (*l)->nast = p;
            (*l)->klucz = x;
            return;
        }
        else{
            l = &(*l)->nast;
        }
    }
}


void wczytaj_z_pliku(lista *l){
    FILE* list = fopen("lista.txt", "r");
    if(list == NULL){
        printf("Failed to open a file\n");
    }
    int temp = 0;
    while(fscanf(list, "%d ", &temp) == 1){
        dodac_na_koniec(l, temp);
    }
}


void usun_wystapienia(lista *l, int x){
    lista p;
    while((*l)){
        if((*l)->klucz == x){
            p = (*l);
            (*l) = (*l)->nast;
            free(p);
        }
        else{
            l = &(*l)->nast;
        }
    }
}

void usun_powtarzania(lista* l){
    int current_key = 0;
    lista *p = &(*l)->nast;
    lista q;

    while(*l){
        current_key = (*l)->klucz;
        p = &(*l)->nast;
        if((*l)->nast){
            while(*p){
                if((*p)->klucz == current_key){
                    q = (*p);
                    (*p) = (*p)->nast;
                    free(q);
                }
                else{
                    p = &(*p)->nast;
                }
            }
        }
        l = &(*l)->nast;
    }
}


void usun_wystapienia_rekur(lista *l, int x){
    lista p;
    if((*l) == NULL){
        return;
    }
    if((*l)->klucz == x){
        p = (*l);
        (*l) = (*l)->nast;
        free(p);
        usun_wystapienia_rekur(l, x);
    }
    else{
        usun_wystapienia_rekur(&(*l)->nast, x);
    }
}


void usun_niepodz(lista *l, int x){
    lista p;
    while((*l)){
        if(((*l)->klucz % x) != 0){
            p = (*l);
            (*l) = (*l)->nast;
            free(p);
        }
        else {
            l = &(*l)->nast;
        }
    }
}


int najwiecej_wystepujacy(lista l){
    int best_count = 0,
        current_count = 0,
        current_number = 0,
        best_value = 0;
    lista p = l,
            q = l;

    if(l == NULL){
        printf("Lista jest pusta\n");
        return 0;
    }

    while(p){
        current_number = p->klucz;
        while(q){
            if(current_number == q->klucz){
                current_count++;
            }

            if(current_count > best_count){
                best_count = current_count;
                best_value = current_number;
            }
            q = q->nast;
        }
        q = l;
        current_count = 0;
        p = p->nast;
    }
    return best_value;
}