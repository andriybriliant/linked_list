#include <stdio.h>
#include <stdbool.h>
#include "functions.h"


int main() {
    lista l = 0;
    int user_input, target;
    printf("Program pozwalajacy operowac na listach jednokierunkowych\n");
    wczytaj_z_pliku(&l);
    usun_powtarzania(&l);
    while(true){
        printf("Wybierz co chcesz zrobic\n");
        printf("1. Wyswietlic liste\n");
        printf("2. Wyswietlic liste od konca\n");
        printf("3. Dodac na poczatek listy\n");
        printf("4. Dodac na koniec listy\n");
        printf("5. Usuwanie pierwszego elementu listy\n");
        printf("6. Usuwanie ostatniego elementu listy\n");
        printf("7. Szukanie elementu listy\n");
        printf("8. Szukanie elementu listy i usuwanie\n");
        printf("9. Wczytaj liste z pliku\n");
        printf("10. Odwroc liste\n");
        printf("11. Odwroc liste rekurencyjnie\n");
        printf("12. Dodaj za wskazanym elementem listy\n");
        printf("13. Dodaj przed wskazanym elementem listy\n");
        printf("14. Usun wszystkie wystapienia\n");
        printf("15. Usun wszystkie wystapienia rekurencyjnie\n");
        printf("16. Usun wszystkie liczby niepodzielne przez x\n");
        printf("17. Znajdz najwiecej wystapujaca liczbe\n");
        printf("0. Wyjdz\n");

        scanf("%d", &user_input);



        switch(user_input){
            case 1:
                wyswietl_liste(l);
                break;
            case 2:
                drukuj_odw(l);
                printf("]\n");
                break;
            case 3:
                printf("Podaj element ktory chcesz dodac: ");
                scanf("%d", &user_input);
                dodac_na_poczatek(&l, user_input);
                break;
            case 4:
                printf("Podaj element ktory chcesz dodac: ");
                scanf("%d", &user_input);
                dodac_na_koniec(&l, user_input);
                break;
            case 5:
                usun_pierwszy_element(&l);
                printf("Pierwszy element zostal usuniety\n");
                break;
            case 6:
                usun_ostatni_element(&l);
                printf("Ostatni element zostal usuniety\n");
                break;
            case 7:
                printf("Podaj element ktory chcesz znalezc\n");
                scanf("%d", &user_input);
                szukanie(l, user_input);
                break;
            case 8:
                printf("Podaj element ktory chcesz znalezc\n");
                scanf("%d", &user_input);
                usuwanie_znalezionego(&l, user_input);
                break;
            case 9:
                wczytaj_z_pliku(&l);
                printf("Lista zostala wczytana\n");
                break;
            case 10:
                l = odwroc_liste(l);
                break;
            case 11:
                l = odwroc_rekurencyjnie(l);
                break;
            case 12:
                printf("Wpisz element ktory chcesz dodacz\n");
                scanf("%d", &user_input);
                printf("Wpisz element za ktorym chcesz dodac\n");
                scanf("%d", &target);
                dodaj_za_wskazanym(&l, user_input, target);
                break;
            case 13:
                printf("Wpisz element ktory chcesz dodacz\n");
                scanf("%d", &user_input);
                printf("Wpisz element przed ktorym chcesz dodac\n");
                scanf("%d", &target);
                dodaj_przed_wskazanym(&l, user_input, target);
                break;
            case 14:
                printf("Podaj element ktory chcesz usunac\n");
                scanf("%d", &target);
                usun_wystapienia(&l, target);
                break;
            case 15:
                printf("Podaj element ktory chcesz usunac\n");
                scanf("%d", &target);
                usun_wystapienia_rekur(&l, target);
                break;
            case 16:
                printf("Podaj x\n");
                scanf("%d", &target);
                usun_niepodz(&l, target);
                break;
            case 17:
                printf("Najwiecej wystapujaca liczba jest %d\n", najwiecej_wystepujacy(l));
                break;
            case 18:
                usun_powtarzania(&l);
                break;
            case 0:
                return 0;
            default:
                printf("Wprowadz poprawna opcje");
        }
    }
}
