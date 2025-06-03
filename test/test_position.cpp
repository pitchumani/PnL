#include <gtest/gtest.h>
#include <memory>
#include "Position.h"
#include "Bond.h"

class PositionTest : public ::testing::Test {
protected:
    std::shared_ptr<Bond> bond = std::make_shared<Bond>("US10Y", "US Treasury 10Y", 1000.0, 0.03);
    double purchasePrice = 1000.0;
    int quantity = 10;
    Position position{bond, purchasePrice, quantity};
};

TEST_F(PositionTest, Constructor_SetsInstrumentPriceQuantity) {
    EXPECT_EQ(position.getInstrumentSymbol(), "US10Y");
    EXPECT_EQ(position.getQuantity(), 10);
    EXPECT_DOUBLE_EQ(position.getPurchasePrice(), 1000.0);
}

TEST_F(PositionTest, CalculatePnL_PositivePnL) {
    double currentPrice = 1050.0;
    EXPECT_DOUBLE_EQ(position.calculatePnL(currentPrice), (1050.0 - 1000.0) * 10);
}

TEST_F(PositionTest, CalculatePnL_NegativePnL) {
    double currentPrice = 950.0;
    EXPECT_DOUBLE_EQ(position.calculatePnL(currentPrice), (950.0 - 1000.0) * 10);
}

TEST_F(PositionTest, CalculatePnL_ZeroPnL) {
    double currentPrice = 1000.0;
    EXPECT_DOUBLE_EQ(position.calculatePnL(currentPrice), 0.0);
}