#include <iostream>
#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"
#include "Task_4.h"
#include "Task_5.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

//g++ Gtests.cpp -o test -lgtest -lgmock -pthread

TEST(Test1, Newnum){
    task1 t(true);
    int *arr = t.newnum(5, 2, 3);
    int Test_out = arr[0] + arr[2];
    delete[] arr;
    EXPECT_EQ(2, Test_out);
}

TEST(Test2, Countnum){
    task1 t(true);
    int Test_out = t.countnum(5, 2);
    EXPECT_EQ(3, Test_out);
}


TEST(Test3, othernum){
    task1 t(true);
    int *arr = new int[5]{1, 0, 2, 1, 1};
    arr = t.othernum(arr, 5, 2);
    int Test_out = arr[1];
    delete[] arr;
    EXPECT_EQ(1, Test_out);
}

TEST(Test4, toRevCode){
    task1 t(true);
    int *arr = new int[5]{1, 0, 0, 1, 1};
    arr = t.toRevCode(arr, 5, 0);
    int Test_out = arr[1];
    delete[] arr;
    EXPECT_EQ(1, Test_out);
}

TEST(Test5, toDopCode){
    task2 t(true);
    int *arr = new int[5]{1, 0, 0, 1, 1};
    arr = t.toDopCode(arr, 5, 0);
    int Test_out = arr[1];
    delete[] arr;
    EXPECT_EQ(0, Test_out);
}

TEST(Test6, sum){
    task3 t(true);
    int *arr = new int[5]{0, 0, 0, 0, 1};
    int *arr2 = new int[5]{0, 0, 0, 1, 0};
    arr = t.sum(arr, arr2, 5, 0, 0, 2);
    int Test_out = arr[1];
    delete[] arr;
    delete[] arr2;
    EXPECT_EQ(0, Test_out);
}

TEST(Test7, yadd){
    task5 t(true);
    int *arr = new int[5]{1, 0, 0, 1, 1};
    int Test_out = t.yadd(arr);
    delete[] arr;
    EXPECT_EQ(85, Test_out);
}

TEST(Test8, sum2){
    task3 t(true);
    int *arr = new int[5]{1, 0, 0, 0, 1};
    int *arr2 = new int[5]{0, 0, 0, 1, 0};
    arr = t.sum(arr, arr2, 5, 0, 0, 2);
    int Test_out = arr[4];
    delete[] arr;
    delete[] arr2;
    EXPECT_EQ(1, Test_out);
}

TEST(Test9, toDopCode2){
    task2 t(true);
    int *arr = new int[5]{1, 1, 1, 1, 1};
    arr = t.toDopCode(arr, 5, 0);
    int Test_out = arr[1];
    delete[] arr;
    EXPECT_EQ(1, Test_out);
}

TEST(Test10, Countnum2){
    task1 t(true);
    int Test_out = t.countnum(37, 5);
    EXPECT_EQ(3, Test_out);
}

int main(int args, char **argv){
    ::testing::InitGoogleTest(&args, argv);
    return RUN_ALL_TESTS();
}