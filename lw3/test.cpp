#include "figure.hpp"
#include <gtest/gtest.h>

class SquareTest : public ::testing::Test {
protected:
    void SetUp() override {
        square = new Square(1.0,1.0, 4.0,1.0, 4.0,4.0, 1.0,4.0);
    }

    void TearDown() override {
        delete square;
    }

    Square* square;
};

TEST_F(SquareTest, TestAssignmentOperator) {
    Square *sq2 = square;
    ASSERT_TRUE(square == sq2);
}

TEST_F(SquareTest, TestEqualityOperator) {
    Square sq2(1.0,1.0, 4.0,1.0, 4.0,4.0, 1.0,4.0);
    ASSERT_TRUE(*square == sq2);
}

TEST_F(SquareTest, TestInequalityOperator) {
    Square sq2(2.0,2.0, 5.0,2.0, 5.0,5.0, 2.0,5.0);
    ASSERT_TRUE(*square != sq2);
}

TEST_F(SquareTest, TestArea) {
    double area = static_cast<double>(*square);
    ASSERT_DOUBLE_EQ(area, 9.0);
}

TEST_F(SquareTest, TestCenter) {
    std::stringstream ss;
    std::streambuf* oldbuf = std::cout.rdbuf(ss.rdbuf());
    square->center();
    std::cout.rdbuf(oldbuf);
    ASSERT_EQ(ss.str(), "Center of figure: (2.5, 2.5)\n");
}



class RectangleTest : public ::testing::Test {
protected:
    void SetUp() override {
        rectangle = new Rectangle(1.0,1.0, 5.0,1.0, 5.0,4.0, 1.0,4.0);
    }

    void TearDown() override {
        delete rectangle;
    }

    Rectangle* rectangle;
};

TEST_F(RectangleTest, TestArea) {
    double area = static_cast<double>(*rectangle);
    ASSERT_DOUBLE_EQ(area, 12.0);
}

TEST_F(RectangleTest, TestInputOperator) {
    std::stringstream input("1.0 1.0 5.0 1.0 5.0 4.0 1.0 4.0");
    input >> *rectangle;
    double area = static_cast<double>(*rectangle);
    ASSERT_DOUBLE_EQ(area, 12.0);
}



class TrapezoidTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Code here will be called immediately after the constructor, before each test
        trapezoid = new Trapezoid(0.0,0.0, 1.0,1.0, 3.0,1.0, 4.0,0.0);
    }

    void TearDown() override {
        // Code here will be called immediately after each test, before the destructor
        delete trapezoid;
    }

    Trapezoid* trapezoid;
};

TEST_F(TrapezoidTest, TestArea) {
    double area = static_cast<double>(*trapezoid);
    ASSERT_DOUBLE_EQ(area, 3.0);
}

TEST_F(TrapezoidTest, TestInputOperator) {
    std::stringstream input("0.0 0.0 1.0 1.0 3.0 1.0 4.0 0.0");
    input >> *trapezoid;
    double area = static_cast<double>(*trapezoid);
    ASSERT_DOUBLE_EQ(area, 3.0);
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}