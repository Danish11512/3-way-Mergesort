//#include <iostream>
//#include <stdlib.h>
//
///* mergesort: sort integer array a[length] ; standard mergesort */
///* sorts in increasing order, requires auxiliary array */
//
//void mergesortthird(int *a, int *aux, int length)
//{ int i, j1, j2,  temp;
//  if(length>1) // need special case for 2
//    {  mergesortthird(a, aux, (length/3) ); /* recursive calls */
//       mergesortthird(a + length/3, aux, (2*length/3) - (length/3));
//       mergesortthird(a + (2*length/3), aux, (length - (2*length/3)));
//
//
//       for( i = 0, j1 =0, j2= (length/2) ; i< length; ) /* merging */
//       {   if( ( j1 < (length/2) && a[j1] < a[j2]) || j2 == length)
//	      aux[i++] = a[j1++];
//           else
//	      aux[i++] = a[j2++];
//
//        }
//        for( i = 0; i< length; i++) /* copying back */
//           a[i] = aux[i];
//    }
//}
//
//int main (){
//   int arr[9] = {-5, -7, -8, 1, 45, 0 , 9, 24, 18} ;
//   int aux [9];
//
//   mergesortthird(arr, aux, 9);
//
//   for ( int i = 0; i < 9; i++)
//   {
//       std::cout<<arr[i]<<"\n";
//   }
//
//
//}
//
//
//
//// get array
//// basecae 1 - if array is less than 3, so 2, compare them and go back
//// basecase
//
//
////#include <iostream>
////#include <stdlib.h>
////
/////* mergesort: sort integer array a[length] ; standard mergesort */
/////* sorts in increasing order, requires auxiliary array */
////
////void mergesortthird(int *a, int *aux, int length)
////{
////    int temp, i, j, k;
////
////    if(length <2)
////    {
////        return;
////    }
////
////    if(length ==2 )
////    {
////        if(a[0] > a[1])
////        {
////            a[0] = temp;
////            a[0] = a[1];
////            a[1] = temp;
////        }
////    }
////// split the array now
////
////    mergesortthird(a, aux, (length/3) );
////    mergesortthird(a + length/3, aux, (2*length/3) - (length/3));
////    mergesortthird(a + (2*length/3), aux, (length - (2*length/3)));
//
//
//
////v2
////
////
////#include <iostream>
////#include <stdlib.h>
////
/////* mergesort: sort integer array a[length] ; standard mergesort */
/////* sorts in increasing order, requires auxiliary array */
////
////void mergesortthird(int *a, int *aux, int length)
////{
////    int temp, i, j, k, cursor;
////
////    if(length <2)
////    {
////        return;
////    }
////
////    if(length ==2 )
////    {
////        if(a[0] > a[1])
////        {
////            a[0] = temp;
////            a[0] = a[1];
////            a[1] = temp;
////        }
////        return;
////    }
////// split the array now
////
////    mergesortthird(a, aux, (length/3) );
////    mergesortthird(a + length/3, aux, (2*length/3) - (length/3));
////    mergesortthird(a + (2*length/3), aux, (length - (2*length/3)));
////
////    //  i = length/3;
////    //  j = length - (2*length/3);
////    //  k = length - (length/3);
////
////    for (cursor = 0, i = 0, j = length/3, k = length -(length/3);cursor < length;)
////    {
////        if (i<length/3 && j < (length - (length/3)) && a[i] < a[j] && a[i] < a[k] || a[k] == length)
////        {
////            aux[cursor++] = a[i++];
////        }
////        if (i<length/3 && j < (length - (length/3)) && a[j] < a[i] && a[j] < a[k] || a[k] == length)
////        {
////            aux[cursor++] = a[j++];
////        }
////        if (i<length/3 && j < (length - (length/3)) && a[k] < a[i] && a[k] < a[j] || a[k] == length)
////        {
////            aux[cursor++] = a[k++];
////        }
////    }
////    for( i = 0; i< length; i++) /* copying back */
////        a[i] = aux[i];
////}
//
//
////V3
////
////
////#include <iostream>
////#include <stdlib.h>
////
/////* mergesort: sort integer array a[length] ; standard mergesort */
/////* sorts in increasing order, requires auxiliary array */
////
////void mergesortthird(int *a, int *aux, int length)
////{
////    int temp, i, j, k, cursor = 0;
////
////    if(length <2)
////    {
////        return;
////    }
////
////    if(length ==2 ) // change format
////    {
////        if(a[0] > a[1])
////        {
////            a[0] = temp;
////            a[0] = a[1];
////            a[1] = temp;
////        }
////        return;
////    }
////// split the array now
////
////    mergesortthird(a, aux, (length/3) );
////    mergesortthird(a + length/3, aux, (2*length/3) - (length/3));
////    mergesortthird(a + (2*length/3), aux, (length - (2*length/3)));
////
////    i = 0;
////    //length/3;
////    j = length/3;
////    //length - (2*length/3);
////    k = length - (2*length/3);
////    //length - (length/3);
////
////    //  for (cursor = 0, i = 0, j = length/3, k = length -(length/3);cursor < length;)
////    //  {
////    //    if (i<length/3 && j < (length - (length/3)) && a[i] < a[j] && a[i] < a[k] || a[k] == length)
////    //    {
////    //      aux[cursor++] = a[i++];
////    //    }
////    //    if (i<length/3 && j < (length - (length/3)) && a[j] < a[i] && a[j] < a[k] || a[k] == length)
////    //    {
////    //      aux[cursor++] = a[j++];
////    //    }
////    //     if (i<length/3 && j < (length - (length/3)) && a[k] < a[i] && a[k] < a[j] || a[k] == length)
////    //    {
////    //      aux[cursor++] = a[k++];
////    //    }
////    //  }
////
////
////    // If no array has been exhausted
////    // one wheere each one is exhausted
////    // one where two are exhausted, so just move all of the last one
////    while ( i< length/3  && j < (length - (2*length/3)) && k <length)
////    {
////        // i is the smallest
////        if(a[i]<a[j] && a[i]<a[k])
////        {
////            aux[cursor++] = a[i++];
////        }
////
////        // j is the smallest
////        if(a[j]<a[i] && a[j]<a[k])
////        {
////            aux[cursor++] = a[j++];
////        }
////
////        // k is the smallest
////        if(a[k]<a[i] && a[k]<a[j])
////        {
////            aux[cursor++] = a[k++];
////        }
////
////        //if i is exhausted (i = length/3)
////        if(i == lenght/3)
////        {
////            while(j < (length - (2*length/3)) && k <length)
////            {
////                if (a[j]<a[k])
////                {
////                    aux[cursor++] = a[j++];
////                }
////                else
////                {
////                    aux[cursor++] = a[k++];
////                }
////            }
////        }
////
//////if j is exhausted (j = (length - (2*length/3)))
////        if(j == (length - (2*length/3)))
////        {
////            while( i < lenght/3 && k <length)
////            {
////                if (a[i]<a[k])
////                {
////                    aux[cursor++] = a[i++];
////                }
////                else
////                {
////                    aux[cursor++] = a[k++];
////                }
////            }
////        }
////
//////if k is exhausted (k = length)
////        if(k == length)
////        {
////            while( i < lenght/3 && j < (length - (2*length/3)))
////            {
////                if (a[i]<a[j])
////                {
////                    aux[cursor++] = a[i++];
////                }
////                else
////                {
////                    aux[cursor++] = a[j++];
////                }
////            }
////        }
////
////
////
////
////
////
////
////
////
////
////
////
////    }
////
////
////
////
////
////
////
////
////    for( i = 0; i< length; i++) /* copying back */
////        a[i] = aux[i];
////}
////
////
////int main ()
////{
////    int a[9] = {34, 56, 78, 1, 0, 34, 56, 9, 47};
////    int aux[9];
////    int b[] = {0, 4, 2};
////
////    mergesortthird(a, aux, 9);
////
////    for ( int i = 0; i<10; i++)
////    {
////        std::cout<<a[i]<< std::endl;
////    }
////    std::cout<<*a;
////    std::cout<<a+1;
////
////}
////
//
//
////v4
////
////
////#include <iostream>
////#include <stdlib.h>
////
/////* mergesort: sort integer array a[length] ; standard mergesort */
/////* sorts in increasing order, requires auxiliary array */
////
////void mergesortthird(int *a, int *aux, int length)
////{
////    int temp, i, j, k, cursor = 0;
////
////    if(length <2)
////    {
////        return;
////    }
////
////    if(length ==2 ) // change format
////    {
////        if(a[0] > a[1])
////        {
////            a[0] = temp;
////            a[0] = a[1];
////            a[1] = temp;
////        }
////        return;
////    }
////// split the array now
////
////    mergesortthird(a, aux, (length/3) );
////    mergesortthird(a + length/3, aux, (2*length/3) - (length/3));
////    mergesortthird(a + (2*length/3), aux, (length - (2*length/3)));
////
////    i = 0;
////    //length/3;
////    j = length/3;
////    //length - (2*length/3);
////    k = length - (2*length/3);
////    //length - (length/3);
////
////    //  for (cursor = 0, i = 0, j = length/3, k = length -(length/3);cursor < length;)
////    //  {
////    //    if (i<length/3 && j < (length - (length/3)) && a[i] < a[j] && a[i] < a[k] || a[k] == length)
////    //    {
////    //      aux[cursor++] = a[i++];
////    //    }
////    //    if (i<length/3 && j < (length - (length/3)) && a[j] < a[i] && a[j] < a[k] || a[k] == length)
////    //    {
////    //      aux[cursor++] = a[j++];
////    //    }
////    //     if (i<length/3 && j < (length - (length/3)) && a[k] < a[i] && a[k] < a[j] || a[k] == length)
////    //    {
////    //      aux[cursor++] = a[k++];
////    //    }
////    //  }
////
////
////    // If no array has been exhausted
////    // one wheere each one is exhausted
////    // one where two are exhausted, so just move all of the last one
////    while ( i< length/3  && j < (length - (2*length/3)) && k <length)
////    {
////        // i is the smallest
////        if(a[i]<a[j] && a[i]<a[k])
////        {
////            aux[cursor++] = a[i++];
////        }
////
////        // j is the smallest
////        if(a[j]<a[i] && a[j]<a[k])
////        {
////            aux[cursor++] = a[j++];
////        }
////
////        // k is the smallest
////        if(a[k]<a[i] && a[k]<a[j])
////        {
////            aux[cursor++] = a[k++];
////        }
////
////        //if i is exhausted (i = length/3)
////        if(i == lenght/3)
////        {
////            while(j < (length - (2*length/3)) && k <length)
////            {
////                if (a[j]<a[k])
////                {
////                    aux[cursor++] = a[j++];
////                }
////                else
////                {
////                    aux[cursor++] = a[k++];
////                }
////            }
////        }
////
//////if j is exhausted (j = (length - (2*length/3)))
////        if(j == (length - (2*length/3)))
////        {
////            while( i < lenght/3 && k <length)
////            {
////                if (a[i]<a[k])
////                {
////                    aux[cursor++] = a[i++];
////                }
////                else
////                {
////                    aux[cursor++] = a[k++];
////                }
////            }
////        }
////
//////if k is exhausted (k = length)
////        if(k == length)
////        {
////            while( i < lenght/3 && j < (length - (2*length/3)))
////            {
////                if (a[i]<a[j])
////                {
////                    aux[cursor++] = a[i++];
////                }
////                else
////                {
////                    aux[cursor++] = a[j++];
////                }
////            }
////        }
////
////        // i & j are exhausted  001
////        if (i == lenght/3 && j == (length - (2*length/3)))
////        {
////            // as long as k isn't exhausted
////            while(k<length)
////            {
////                aux[cursor++] = a[k++];
////            }
////        }
////
////        // i & k are exhausted 010
////        if(i == lenght/3 && k == length)
////        {
////            // while j is not exhausted
////            while(j < (length - (2*length/3)))
////            {
////                aux[cursor++] = a[j++];
////            }
////        }
////
////        // j & k are exhausted 100
////        if(j == (length - (2*length/3)) && k == length)
////        {
////            // while j is not exhausted
////            while(i<length/3)
////            {
////                aux[cursor++] = a[i++];
////            }
////        }
////
////
////
////
////
////
////
////
////
////    }
//
//
//
//
//
//
//
//
//    for( i = 0; i< length; i++) /* copying back */
//        a[i] = aux[i];
//}
//
//
//int main ()
//{
//    int a[9] = {34, 56, 78, 1, 0, 34, 56, 9, 47};
//    int aux[9];
//    int b[] = {0, 4, 2};
//
//    mergesortthird(a, aux, 9);
//
//    for ( int i = 0; i<10; i++)
//    {
//        std::cout<<a[i]<< std::endl;
//    }
//    std::cout<<*a;
//    std::cout<<a+1;
//
//}






#include <iostream>
#include <stdlib.h>



void mergesortthird(int *a, int *aux, int length)
{
    int temp, i, j, k, cursor = 0;

    if(length <2)
    {
        return;
    }

    if(length ==2 ) // change format
    {
        if(*a > *(a+1))
        {
            temp = *a;
            *a = *(a+1);
            *(a+1) = temp;
        }
        return;
    }
// split the array now
// else
    mergesortthird(a, aux, (length/3) );
    mergesortthird(a + length/3, aux, (2*length)/3);
    mergesortthird(a + (2*length/3), aux, length - (2*length/3));

    i = 0;
    //length/3;
    j = length/3;
    //length - (2*length/3);
    k = length - (2*length/3);
    //length - (length/3);

    // If no array has been exhausted
    // one wheere each one is exhausted
    // one where two are exhausted, so just move all of the last one
    while ( i< length/3  && j < (length - (2*length/3)) && k <length)
    {
        // i is the smallest
        if(a[i]<a[j] && a[i]<a[k])
        {
            aux[cursor++] = a[i++];
        }

        // j is the smallest
        if(a[j]<a[i] && a[j]<a[k])
        {
            aux[cursor++] = a[j++];
        }

        // k is the smallest
        if(a[k]<a[i] && a[k]<a[j])
        {
            aux[cursor++] = a[k++];
        }

        //if i is exhausted (i = length/3)
        if(i == length/3)
        {
            while(j < (length - (2*length/3)) && k <length)
            {
                if (a[j]<a[k])
                {
                    aux[cursor++] = a[j++];
                }
                else
                {
                    aux[cursor++] = a[k++];
                }
            }
        }

//if j is exhausted (j = (length - (2*length/3)))
        if(j == (length - (2*length/3)))
        {
            while( i < length/3 && k <length)
            {
                if (a[i]<a[k])
                {
                    aux[cursor++] = a[i++];
                }
                else
                {
                    aux[cursor++] = a[k++];
                }
            }
        }

//if k is exhausted (k = length)
        if(k == length)
        {
            while( i < length/3 && j < (length - (2*length/3)))
            {
                if (a[i]<a[j])
                {
                    aux[cursor++] = a[i++];
                }
                else
                {
                    aux[cursor++] = a[j++];
                }
            }
        }

        // i & j are exhausted  001
        if (i == length/3 && j == (length - (2*length/3)))
        {
            // as long as k isn't exhausted
            while(k<length)
            {
                aux[cursor++] = a[k++];
            }
        }

        // i & k are exhausted 010
        if(i == length/3 && k == length)
        {
            // while j is not exhausted
            while(j < (length - (2*length/3)))
            {
                aux[cursor++] = a[j++];
            }
        }

        // j & k are exhausted 100
        if(j == (length - (2*length/3)) && k == length)
        {
            // while j is not exhausted
            while(i<length/3)
            {
                aux[cursor++] = a[i++];
            }
        }
    }
    for( i = 0; i< length; i++) /* copying back */
        a[i] = aux[i];
}


int main ()
{
    int a[9] = {-1, 1, 2, 3, 4, 1, 4, 3, 2};
    int aux[9];

    mergesortthird(a, aux, 9);

    for ( int i = 0; i<10; i++)
    {
        std::cout<<a[i]<< std::endl;
    }


}
