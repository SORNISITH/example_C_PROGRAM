#include <assert.h>
#include <cstdio>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

struct result_obj {
    int valueue_square;
    int range_posible_1;
    int range_posible_2;
};

void display_obj_result(struct result_obj* x)
{
    printf("square : %d\n", x->valueue_square);
    printf("POSIBLE 1 : %d\n", x->range_posible_1);
    printf("POSIBLE 2 : %d\n", x->range_posible_2);
    
}

struct result_obj* pattern(int x)
{

    if (x <= 0) {
        return NULL;
    }
    struct result_obj* robj = malloc(sizeof(*robj));
    int v = 2;
    int prev_square = 1;
    while (true) {
        if (v > x / v) {
            robj->range_posible_1 = prev_square;
            robj->range_posible_2 = prev_square;
            robj->valueue_square = v - 1;
            break;
        }
        int current_square = v * v;
        if (current_square == x) {
            robj->valueue_square = v;
            robj->range_posible_1 = current_square;
            robj->range_posible_2 = current_square;
            break;
        }
        if ((prev_square <= x && current_square >= x) || current_square >= x) {
            robj->range_posible_1 = prev_square;
            robj->range_posible_2 = current_square;
            robj->valueue_square = v - 1;
            break;
        }
        prev_square = current_square;
        v++;
    }
    return robj;
}


int sqare_root(int x)
{
    double result = 0;
    struct result_obj* partern_obj_ret = pattern(x);
    int a = partern_obj_ret->range_posible_1;
    int b = partern_obj_ret->range_posible_2;
    int z = partern_obj_ret->valueue_square;

    if (a == b) {
        result = z;
    } else {
        double upper = x - a;
        double lower = z * 2;
        double frag = upper / lower;
        if (frag == 1.000) {
            result = z;
        } else {
            result = z + frag;
        }
    }

    free(partern_obj_ret);
    return (int)result;
}

double mySqrt(double x)
{
    if (x < 2)
        return x;

    double guess = x;
    double epsilon = 0.000000001;

    while ((guess * guess - x) > epsilon || (x - guess * guess) > epsilon) {
        guess = (guess + x / guess) / 2.0;
        printf("%f : ", guess);
        printf("(%f + %f / %f) / %f \n", guess, x, guess, 2.0);
    }

    return guess;
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    double x = mySqrt(899933333333333);
    printf("%f", x);

    return EXIT_SUCCESS;
}
