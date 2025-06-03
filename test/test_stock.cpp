#include <gtest/gtest.h>
#include "Stock.h"

class StockTest : public ::testing::Test {
protected:
    Stock stock{"AAPL", "Apple Inc."};
};

TEST_F(StockTest, CalculateUnitPnL_PositivePnL) {
    double currPrice = 150.0;
    double purPrice = 100.0;
    EXPECT_DOUBLE_EQ(stock.calculateUnitPnL(currPrice, purPrice), 50.0);
}

TEST_F(StockTest, CalculateUnitPnL_NegativePnL) {
    double currPrice = 80.0;
    double purPrice = 100.0;
    EXPECT_DOUBLE_EQ(stock.calculateUnitPnL(currPrice, purPrice), -20.0);
}

TEST_F(StockTest, CalculateUnitPnL_ZeroPnL) {
    double currPrice = 100.0;
    double purPrice = 100.0;
    EXPECT_DOUBLE_EQ(stock.calculateUnitPnL(currPrice, purPrice), 0.0);
}

TEST_F(StockTest, Constructor_SetsSymbolAndName) {
    EXPECT_EQ(stock.getSymbol(), "AAPL");
    EXPECT_EQ(stock.getName(), "Apple Inc.");
}