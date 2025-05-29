#include "minunit.h"
#include <stdio.h>
#include "../includes/cube.h"
#include <string.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"



MU_TEST_SUITE(draw_tests)
{

}

int main(void)
{
    MU_RUN_SUITE(draw_tests);
    MU_REPORT();
    return MU_EXIT_CODE;
}