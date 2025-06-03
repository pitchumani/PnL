#include <gtest/gtest.h>
#include "Bond.h"

class BondTest : public ::testing::Test {
protected:
    Bond bond{"US10Y", "US Treasury 10Y", 1000.0, 0.03};
};

TEST_F(BondTest, Constructor_SetsSymbolNameFaceValueCouponRate) {
    EXPECT_EQ(bond.getSymbol(), "US10Y");
    EXPECT_EQ(bond.getName(), "US Treasury 10Y");
    EXPECT_DOUBLE_EQ(bond.getFaceValue(), 1000.0);
    EXPECT_DOUBLE_EQ(bond.getCouponRate(), 0.03);
}

TEST_F(BondTest, CalculateUnitPnL_PositivePnL) {
    double currPrice = 1050.0;
    double purPrice = 1000.0;
    EXPECT_DOUBLE_EQ(bond.calculateUnitPnL(currPrice, purPrice), 50.0);
}

TEST_F(BondTest, CalculateUnitPnL_NegativePnL) {
    double currPrice = 950.0;
    double purPrice = 1000.0;
    EXPECT_DOUBLE_EQ(bond.calculateUnitPnL(currPrice, purPrice), -50.0);
}

TEST_F(BondTest, CalculateUnitPnL_ZeroPnL) {
    double currPrice = 1000.0;
    double purPrice = 1000.0;
    EXPECT_DOUBLE_EQ(bond.calculateUnitPnL(currPrice, purPrice), 0.0);
}