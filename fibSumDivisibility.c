#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


//add typedef
typedef unsigned long long ull;


//fast matrix exponentiation to handle large values of a and b
void mat_mult(ull a[2][2], ull b[2][2], ull mod) {
    ull res[2][2];
    res[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % mod;
    res[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % mod;
    res[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % mod;
    res[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % mod;
    res[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % mod;
    for (int i = 0; i < 2; ++i)
    for(int j = 0; j < 2; ++j)
        a[i][j] = res[i][j];
}


//exponentiating by squaring
void mat_pow(ull mat[2][2], ull n, ull mod) {
    ull res[2][2] = {{1, 0}, {0, 1}}; //identity matrix
    while (n > 0) {
        if (n % 2 == 1)
            mat_mult(res, mat, mod); //multiplying result by current matrix
        mat_mult(mat, mat, mod); //squaring the matrix
        n /=2;
    }
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            mat[i][j] = res[i][j];
}
//compute fibonnaci number modulo
ull fib_mod(ull n, ull mod) {
    if (n == 0) return 0;
    ull mat[2][2] = {{1, 1}, {1, 0}};
    mat_pow(mat, n - 1, mod);
    return mat[0][0]; //top left element
}




int main()
{

	//user inputs
//	printf("Enter value for nb: ")
//	scanf() 
//	printf("Enter value for a: ")
//	scanf()
//	printf("Enter value for b: ")
//	scanf()
//	printf("Enter value for d: ")
//	scanf()

//user inputs
	int nb;
	printf("Enter number of test cases: ");
    	scanf("%d", &nb);

//    int nb;
//    scanf("%d", &nb);
    for (int i = 0; i < nb; i++) {
        ull a, b, d; //change to ull
	printf("Enter values for a, b and d (space separated): ");
        scanf("%llu %llu %llu", &a, &b, &d); // change to llu
        ull sum_mod_d = (fib_mod(b + 2, d) + d - fib_mod(a +1, d)) % d;
        //ull sum_mod_d = (fib_mod(b + 2, d) + d - fib_mod(a + 1, d)) % d;


        printf("F_%llu + ... + F_%llu is %sdivisible by %llu\n",
        a, b, sum_mod_d == 0 ? "" : "NOT ", d);
    }
    return 0;


}
