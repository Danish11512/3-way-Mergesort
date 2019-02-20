#include <iostream>
#include <stdlib.h>



void merge_sort(int *a, int *aux, int length) {
    int temp, i, j, k;
    int cursor = 0;

    if (length > 1)// base case takes care of 2 and 1
    {
        if (length == 2) // change format
        {
            if (a[0] > a[1]) {
                temp = a[0];
                a[0] = a[1];
                a[1] = temp;
            }
            return;
        }


        merge_sort(a, aux, (length / 3));
        merge_sort(a + (length / 3), aux, (length) / 3);
        merge_sort(a + (2 * length / 3), aux, length - (2 * length / 3));


        // one where each one is exhausted
        // one where two are exhausted, so just move all of the last one

        for (cursor = 0, i = 0, j = length / 3, k = (2 * length / 3); cursor < length;) {
            // If no array has been exhausted
            if (i < (length / 3) && j < (2 * length / 3) && k < length) {

                // i is the smallest
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
            if ( i < (length / 3) && j == (2 * length / 3) && k < length) {
                if (a[i] < a[k]) {
                    aux[cursor++] = a[i++];
                } else {
                    aux[cursor++] = a[k++];
                }
            }

            //if k is exhausted (k = length)
            if (i < (length / 3) && j < (2 * length / 3) && k == length ) {
                if (a[i] < a[j]) {
                    aux[cursor++] = a[i++];
                } else {
                    aux[cursor++] = a[j++];
                }
            }

            // j & k are exhausted 100
            if (i < (length / 3) && j == (2 * length / 3) && k == length) {
                aux[cursor++] = a[i++];
            }

            // i & k are exhausted 010
            if (i == (length / 3) && j < (2 * length / 3) && k == length) {
                aux[cursor++] = a[i++];
            }

            // i & j are exhausted  001
            if (i == (length / 3) && j == (2 * length / 3) && k < length) {
                aux[cursor++] = a[k++];
            }
        }
        for (i = 0; i < length; i++) {/* copying back */
            a[i] = aux[i];
        }
    }
}




int main()
{  int *r, *s; long i;
    printf("Allocating Array. "); fflush(stdout);
    r = (int *) malloc(3000000 * sizeof(int));
    s = (int *) malloc(3000000 * sizeof(int));
    printf("Filling array. "); fflush(stdout);
    for( i = 0; i< 3000000; i++)
        r[i] = 3 * ((137 * i)%3000000);
    printf("Sorting. "); fflush(stdout);
    merge_sort( r, s, 3000000 );
    printf("Checking. \n"); fflush(stdout);
    for(i=0; i< 3000000; i++)
        if( r[i] != 3*i )
        {  printf("Error at %d; is %d, should be %d\n", i, r[i], 3*i );
            fflush(stdout); exit(-1);
        }
    printf("Passed Test.\n");
}
