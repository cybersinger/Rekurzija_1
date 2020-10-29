#include <stdio.h>

// Poenta programa: unosis petocifreni broj, funkcija racuna prosek cifara tog broja
// Korisno u ovom programu:
// 1. Rekurzija
// 2. Predavanje vise od jednog argumenta funkciji
// 3. Trik sa (float) kad u jednacini figurisu integeri

float calcAvg(int inputNr, int ftens, int fCtr)
{
    float fAvg;
    int digits = (inputNr - inputNr % ftens) / ftens;
    fCtr = fCtr + digits;
    inputNr = inputNr - digits * ftens;
    ftens = ftens / 10;
    //printf("Check - inputNr=%d\tftens=%d\tctr=%d\tdigits=%d\n", inputNr, ftens, fCtr, digits); - debugging alat
        if (ftens == 0)
    {
        fAvg = (float) fCtr / 5; // vidi 3 gore
        // printf("Vrednost fAvg u funkciji je %2.2f\n", fAvg); - debugging alat
        return fAvg; // vidi 1 gore. "return" mi nije trebao u Paiza.io, ali MVS trazi
    }
    return calcAvg(inputNr, ftens, fCtr);
}

int main(void) {

    int fiveDigInt;
    int pocTens = 10000, pocCtr = 0;     // Ovde iniciram par varijabli, jer ih funkcija gore menja, a za rekurziju mi trebaju njihove originalne vrednosti
    printf("Unesi petocifreni broj: \n");
    scanf_s("%d", &fiveDigInt, 4); // Zapamti - u scanf_s moras adresu target varijable da koristis, zato &

    float avg = 0.0;
    avg = calcAvg(fiveDigInt, pocTens, pocCtr); // vidi 2 gore
    printf("Average of 5 digits of number %d is %2.2f\n", fiveDigInt, avg); // 2.2f znaci dve cifre pre tacke, dve posle (da mi ne da 4.6000000)

}