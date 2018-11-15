//Aleksandra Trifonova
//Comp Sci 222
//11/01/2018
//Assignment 3 Error Bit Detection & Correction
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

/* declare global vars */
int max_length, hamming_parity;

/* define hamming "string" as a dynamic array of characters */
char *hamming_string = nullptr;

int temp_bit;

/***************************************************************/
void set_Parameters();

void set_Parameters() {
/* prompt for maximum hamming code length and for even/odd parity (even/odd)*/
    printf("Please enter the maximum hamming code length. \n");
    scanf("%d", &max_length);
    printf("Please enter even/odd for the parity bit. \n");
    scanf("%d", &hamming_parity);
/* allocate memory for hamming string based on maximum length and size of a character element*/
    hamming_string = (char *) malloc(max_length * sizeof(char));
}

double num_Parity;

/***************************************************************/
void error_Checking() {
/* declare local vars */
    int parity_check, a, b, c;
    int actual_length;
    int error_bit = 0;
/* prompt for hamming code as a "string"*/
    printf("Please enter the Hamming Code: ");
    scanf("%s", hamming_string);

/* Determine actual Hamming code length & number of parity bits*/
    actual_length = strlen(hamming_string);
    num_Parity = ceil(log(actual_length) / log(2));

/* OUTER LOOP: for each parity bit in the Hamming code*/
    for (a = 1; a <= actual_length; a *= 2)
    { /* BEGIN OF OUTER LOOP */
        temp_bit = a;
        /* initialize appropriate local variables -- parity_check to hamming_parity */
        parity_check = hamming_parity;
        /* MIDDLE LOOP: for each starting bit of a sequence */
        for (b = a; b < actual_length; b = b + (2 * a)){;
        /* INNER LOOP: for each bit to be checked, check value and update parity information for current parity bit*/
        for (c = b; (c < b + a + 1) && (c < actual_length + 1); c++) {
            /* update parity checking by including result for parity bit checked in total */
            parity_check ^= (hamming_string[actual_length - c] - '0');
        } // c-loop
    }// b-loop
    if (parity_check == 1) {
        error_bit += temp_bit;
    }
} /* END OF OUTER LOOP
//* report error in hamming code based on result from parity bits or report no error if none */
if (error_bit == 0) {
printf("There is no bit error\n");

}else {
printf("There is a error in bit: %d \n", error_bit);
if (hamming_string[actual_length - error_bit] == '0'){
    hamming_string[actual_length - error_bit] = '1';
}//if
else {
hamming_string[actual_length - error_bit] = '0';

} //else
printf("The corrected Hamming code is: %s \n", hamming_string);

}//else


}


/***********************OPTIONAL***************************/
void free_hamming() {
    if (hamming_string != nullptr)
        free(hamming_string);
}

/***************************************************************/
//main
int main() {
    /* declare local var's */
    int choice = 0;
    /* until program exits, print menu, select choice via switch statement and call appropriate function*/
    while(choice != 3){
        printf("\n\n");

        printf("Error Detection & Correction");

        printf("\n\n");
        printf("1) Please enter the  Parameters \n");

        printf("2) Check Hamming Code \n");

        printf("3) Quit\n");

        printf("\n");
        printf("Enter Selection: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:{
                set_Parameters();
                break;
            }
            case 2:{
                error_Checking();
                break;
            }
            case 3:{
                printf("Quitting now! \n");
                break;

            }default:
                printf("Not a valid entry. \n");
        }//switch

    }//while
    return 1;
}
