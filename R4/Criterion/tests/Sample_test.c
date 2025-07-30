#include <criterion/criterion.h>
#include "../include/Sample.h"

Test(SampleTest, add_2_nums) {
    cr_assert_eq(add(2, 4), 5); // Test addition of two numbers
    cr_expect(add(2, 3) == 5, "Expected 2 + 3 to equal 5");

}