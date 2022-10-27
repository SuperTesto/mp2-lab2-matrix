#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
    TDynamicMatrix<int> m(5);

    ASSERT_NO_THROW(TDynamicMatrix<int> mat1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
    TDynamicMatrix<int> mat1(4);
    mat1[0][1] = 7;
    TDynamicMatrix<int> mat2(mat1);
    EXPECT_EQ(7, mat2[0][1]);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicMatrix<int> mat1(6);
    TDynamicMatrix<int> mat2(mat1);
    mat1[0][0] = 7;
    EXPECT_EQ(0, mat2[0][0]);
}

TEST(TDynamicMatrix, can_get_size)
{
    TDynamicVector<int> m(3);
    EXPECT_EQ(3, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    TDynamicMatrix<int> m(3);
    m[0][1] = 7;
    EXPECT_EQ(7, m[0][1]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    TDynamicMatrix<int> m(3);
    ASSERT_ANY_THROW(m[0][-2]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> m(3);
    ASSERT_ANY_THROW(m[0][200]);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> m(3);
    ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> mat1(3), mat2(3);
    mat1[0][0] = 6;
    mat1[2][1] = 7;
    mat2 = mat1;
    EXPECT_EQ(6, mat2[0][0]);
    EXPECT_EQ(7, mat2[2][1]);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicVector<int> mat1(3), mat2(7);
    mat1 = mat2;
    EXPECT_EQ(7, mat1.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> mat1(4), mat2(2);
    mat1[0][0] = 8;
    mat1[2][1] = 5;
    mat2 = mat1;
    EXPECT_EQ(8, mat2[0][0]);
    EXPECT_EQ(0, mat2[1][1]);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> mat1(3), mat2(3);
    mat1[0][1] = 6;
    mat2[0][1] = 6;
    EXPECT_EQ(true, mat1 == mat2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> m(3);
    EXPECT_EQ(true, m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> mat1(5), mat2(6);
    EXPECT_EQ(false, mat1 == mat2);
}

TEST(TDynamicMatrix, can_multiply_scalar_by_matrix)
{
    TDynamicMatrix<int> m(3);
    m[0][1] = 6;
    m = m * 2;
    EXPECT_EQ(12, m[0][1]);
    EXPECT_EQ(0, m[0][0]);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> mat1(3), mat2(3), m3;
    mat1[1][0] = 4;
    mat2[1][0] = 3;
    m3 = mat1 + mat2;
    EXPECT_EQ(7, m3[1][0]);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> mat1(4), mat2(5);
    ASSERT_ANY_THROW(mat2 + mat1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> mat1(3), mat2(3), m3;
    mat1[1][0] = 6;
    mat2[1][0] = 3;
    m3 = mat1 - mat2;
    EXPECT_EQ(3, m3[1][0]);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> mat1(4), mat2(3);
    ASSERT_ANY_THROW(mat2 - mat1);
}
