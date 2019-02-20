#include <iostream>
#include <stdlib.h>



void mergesortthird(int *a, int *aux, int length) {
    int temp, i, j, k, cursor = 0;

    if (length < 3) // base case takes care of 2 and 1

        //CCHANAGE
    {
        if (length == 2) // change format
        {
            if (*a > *(a + 1)) {
                temp = *a;
                *a = *(a + 1);
                *(a + 1) = temp;
            }
        }
        return;
    } else {

        mergesortthird(a, aux, (length / 3));
        mergesortthird(a + (length / 3), aux, (length) / 3);
        mergesortthird(a + (2 * length / 3), aux, length - (2 * length / 3));


        //length/3;

        //length - (2*length/3);

        //length - (length/3);

        // one where each one is exhausted
        // one where two are exhausted, so just move all of the last one
        for (i = 0, j = length / 3, k = length; i++;) {
            // If no array has been exhausted
            if (i < j && j < k && k < length) {   // i is the smallest
                if (a[i] < a[j] && a[i] < a[k]) {
                    aux[cursor++] = a[i++];
                }

                // j is the smallest
                if (a[j] < a[i] && a[j] < a[k]) {
                    aux[cursor++] = a[j++];
                }

                // k is the smallest
                if (a[k] < a[i] && a[k] < a[j]) {
                    aux[cursor++] = a[k++];
                }

                //if i is exhausted (i = length/3)
                if (i == (length / 3) && j < ((2 * length / 3)) && k < length) {
                    if (a[j] < a[k]) {
                        aux[cursor++] = a[j++];
                    } else {
                        aux[cursor++] = a[k++];
                    }
                }

                //if j is exhausted (j = (2*length/3)))
                if (j == (2 * length / 3) && i < length / 3 && k < length) {
                    if (a[i] < a[k]) {
                        aux[cursor++] = a[i++];
                    } else {
                        aux[cursor++] = a[k++];
                    }
                }

                //if k is exhausted (k = length)
                if (k == length && i < (length / 3) && j < (2 * length / 3)) {
                    if (a[i] < a[j]) {
                        aux[cursor++] = a[i++];
                    } else {
                        aux[cursor++] = a[j++];
                    }
                }

                // i & j are exhausted  001
                if (i == length / 3 && j == (2 * length / 3) && k < length) {
                    aux[cursor++] = a[k++];
                }

                // i & k are exhausted 010
                if (i == (length / 3) && j < (2 * length / 3) && k == length) {
                    aux[cursor++] = a[i++];
                }

                // j & k are exhausted 100
                if (i < (length / 3) && j == (2 * length / 3) && k == length) {
                    aux[cursor++] = a[i++];
                }

            }

        }
        for (i = 0; i < length; i++) /* copying back */
            a[i] = aux[i];
    }
}








int main ()
{
    int a[9] = { 4, 6, 9, 2, 13, 26, 74, 67, 97};
    // 2, 4, 6, 9, 13, 26, 74, 67, 97
    int aux[9];

    mergesortthird(a, aux, 9);

    for ( int i = 0; i<10; i++)
    {
        std::cout<<a[i]<< std::endl;
    }


}
