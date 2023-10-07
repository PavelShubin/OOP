#include<gtest/gtest.h>
#include"money.hpp"

class MoneyTest: public testing::Test {
    protected:
        Money value;
        void SetUp() override {
            value = Money();
        }
        void TearDown() override {
            ~Money(value);
        }
};

// Constructors
TEST_F(MoneyTest, DefaultConstructor) {
    value = Money();
    EXPECT_EQ(value.length(), 0);
}

TEST_F(MoneyTest, FillConstructor) {
    unsigned char t = '5';
    size_t ln = 4;
    value = Money(ln, t);
    EXPECT_EQ(value.length(), 4);
    EXPECT_EQ(value, Money("5555"));

    t = 'a';
    EXPECT_THROW(Money(ln, t), std::invalid_argument);
}

TEST_F(MoneyTest, InitializerLstConstructor) {
    std::initializer_list<unsigned char> f_list = {'5', '7', '3', '4'};

    value = Money{f_list};
    EXPECT_EQ(value.length(), 4);
    EXPECT_EQ(value, Money("5734"));

    std::initializer_list<unsigned char> s_list = {'a', '2', '4'};
    EXPECT_THROW(Money{s_list}, std::invalid_argument);


    std::initializer_list<unsigned char> t_list = {};
    EXPECT_THROW(Money{t_list}, std::invalid_argument);
}

TEST_F(MoneyTest, StringConstructor) {
    std::string s = "8501";
    value = Money(s);
    EXPECT_EQ(value.length(), 4);
    EXPECT_EQ(static_cast< std::string >(value), "85.01");

    EXPECT_THROW(Money("84.3"), std::invalid_argument);

    EXPECT_THROW(Money("a34543"), std::invalid_argument);

    EXPECT_THROW(Money(""), std::invalid_argument);

}

// Operators
TEST_F(MoneyTest, PlusOperator) {
    value = Money("3");
    Money second("3");
    Money result = value + second;
    EXPECT_EQ(result, Money("6"));
    ~Money(second);
    ~Money(result);

    EXPECT_EQ(Money("7831") + Money("2169"), Money("10000"));
    EXPECT_EQ(Money("99999") + Money("1"), Money("100000"));

}

TEST_F(MoneyTest, MinusOperator) {
    value = Money("120");
    EXPECT_EQ(value - Money("21"), Money("99"));
    EXPECT_THROW(value - Money("121"), std::invalid_argument);
    EXPECT_EQ(Money("10000") - Money("1"), Money("9999"));
    EXPECT_EQ(Money("22222") - Money("22222"), Money("0"));

    EXPECT_EQ(Money("10000") - Money("9999"), Money("1"));
}

TEST_F(MoneyTest, EqualityOperator) {
    Money value("100");
    Money value2("100");
    EXPECT_TRUE(value == value2);
}

TEST_F(MoneyTest, InequalityOperator) {
    Money value("100");
    Money value2("200");
    EXPECT_TRUE(value != value2);
}

TEST_F(MoneyTest, LessThanOperator) {
    Money value("100");
    Money value2("200");
    EXPECT_TRUE(value < value2);
}

TEST_F(MoneyTest, GreaterThanOperator) {
    Money value("200");
    Money value2("100");
    EXPECT_TRUE(value > value2);
}

TEST_F(MoneyTest, StringConversionOperator) {
    Money value("100");
    std::string result = static_cast<std::string>(value);
    EXPECT_EQ(result, "1.00");
}

TEST_F(MoneyTest, IntegerConversionOperator) {
    Money value("100");
    int result = static_cast<int>(value);
    EXPECT_EQ(result, 100);
}

TEST_F(MoneyTest, LengthFunction) {
    Money value("10000");
    EXPECT_EQ(value.length(), 5);
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}