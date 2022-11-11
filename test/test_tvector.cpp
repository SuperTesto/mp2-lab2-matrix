#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
    ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
    TDynamicVector<int> v(10);

    ASSERT_NO_THROW(TDynamicVector<int> vec1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
    TDynamicVector<int> vec1(2);
    vec1[0] = 2;
    TDynamicVector<int> vec2(vec1);
    EXPECT_EQ(2, vec2[0]);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
    TDynamicVector<int> vec1(2);
    TDynamicVector<int> vec2(vec1);
    vec1[0] = 2;
    EXPECT_EQ(0, vec2[0]);
}

TEST(TDynamicVector, can_get_size)
{
    TDynamicVector<int> v(6);
    EXPECT_EQ(6, v.size());
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
    TDynamicVector<int> v(6);
    ASSERT_ANY_THROW(v[-1]);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
    TDynamicVector<int> v(7);
    ASSERT_ANY_THROW(v[7]);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
    TDynamicVector<int> v(3);
    ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
    TDynamicVector<int> vec1(4), vec2(4);
    vec1[0] = 1;
    vec1[3] = 3;
    vec2 = vec1;
    EXPECT_EQ(1, vec2[0]);
    EXPECT_EQ(3, vec2[3]);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
    TDynamicVector<int> vec1(2), vec2(6);
    vec1 = vec2;
    EXPECT_EQ(6, vec1.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
    TDynamicVector<int> vec1(4), vec2(2);
    vec1[0] = 1;
    vec1[3] = 3;
    vec2 = vec1;
    EXPECT_EQ(1, vec2[0]);
    EXPECT_EQ(0, vec2[1]);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
    TDynamicVector<int> vec1(10), vec2(10);
    vec1[1] = 2;
    vec2[1] = 2;
    EXPECT_EQ(true, vec1 == vec2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
    TDynamicVector<int> vec1(10);
    EXPECT_EQ(true, vec1 == vec1);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
    TDynamicVector<int> vec1(4), vec2(3);
    EXPECT_EQ(false, vec1 == vec2);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
    TDynamicVector<int> v(5);
    v[0] = 2;
    v = v + 3;
    EXPECT_EQ(5, v[0]);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
    TDynamicVector<int> v(10);
    v[0] = 3;
    v = v - 5;
    EXPECT_EQ(-2, v[0]);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
    TDynamicVector<int> v(5);
    v[0] = 3;
    v = v * 2;
    EXPECT_EQ(6, v[0]);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
    TDynamicVector<int> vec1(10), vec2(10), vec3;
    vec1[2] = 6;
    vec2[2] = 7;
    vec3 = vec1 + vec2;
    EXPECT_EQ(13, vec3[2]);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
    TDynamicVector<int> vec1(5), vec2(7);
    ASSERT_ANY_THROW(vec2 + vec1);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
    TDynamicVector<int> vec1(5), vec2(5), vec3;
    vec1[2] = 6;
    vec2[2] = 9;
    vec3 = vec1 - vec2;
    EXPECT_EQ(-3, vec3[2]);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
    TDynamicVector<int> vec1(6), vec2(4);
    ASSERT_ANY_THROW(vec2 - vec1);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
    TDynamicVector<int> vec1(3), vec2(3);
    vec1[0] = 1; vec1[1] = 2; vec1[2] = 3;
    vec2[0] = 0; vec2[1] = -3; vec2[2] = 3;
    EXPECT_EQ(3, vec1 * vec2);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
    TDynamicVector<int> vec1(2), vec2(3);
    ASSERT_ANY_THROW(vec2 * vec1);
}
