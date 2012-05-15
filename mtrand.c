/**
 * A random integer generator using "Mersenne twister" random number generator. 
 *
 * @author blackball (bugway@gmail.com)
 */

#include "mtwist.h"
#include <stdio.h>

#define MT_RAND_MAX 0x7FFFFFFF /* 32 bit */

static int _rand_in_range(int limit) {
    int divisor = MT_RAND_MAX / (limit + 1);
    int retval;

    do {
        retval = mt_lrand() / divisor; 
    } while( retval > limit );
    
    return retval;
}

static void gen_rand(int arr[], int n, int limit) {
    /* generate random integer in [0, limit] */
    int i;
    if (limit < 1) return ;
    
    mt_goodseed();
    for (i = 0; i < n; ++i) {
        arr[i] = _rand_in_range(limit);
    }
}

static void _print(const int arr[], int n) {
    int i = 0;
    for (; i < n; ++i)
        printf("%d, ", arr[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    int arr[100];
    gen_rand(arr, 100, 255);
    
    _print(arr, 100);
    return 0;
}

