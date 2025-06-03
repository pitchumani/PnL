#include <gtest/gtest.h>
#include <memory>
#include <unordered_map>
#include "Portfolio.h"
#include "Bond.h"
#include "Position.h"

class PortfolioTest : public ::testing::Test {
protected:
    std::shared_ptr<Bond> bond1 = std::make_shared<Bond>("US10Y", "US Treasury 10Y", 1000.0, 0.03);
    std::shared_ptr<Bond> bond2 = std::make_shared<Bond>("US5Y", "US Treasury 5Y", 500.0, 0.025);
    Position pos1{bond1, 1000.0, 10};
    Position pos2{bond2, 500.0, 20};
    Portfolio portfolio;

    ~PortfolioTest() noexcept override = default;

    void SetUp() override {
        portfolio.addPosition(pos1);
        portfolio.addPosition(pos2);
    }
};

TEST_F(PortfolioTest, AddPosition_IncreasesSize) {
    EXPECT_EQ(portfolio.size(), (size_t)2);
}

TEST_F(PortfolioTest, RemovePosition_DecreasesSize) {
    portfolio.removePosition("US10Y");
    EXPECT_EQ(portfolio.size(), (size_t)1);
}

TEST_F(PortfolioTest, RemovePosition_NonexistentSymbol_DoesNothing) {
    portfolio.removePosition("NONEXISTENT");
    EXPECT_EQ(portfolio.size(), (size_t)2);
}

TEST_F(PortfolioTest, GetPositionBySymbol_Found) {
    auto pos = portfolio.getPosition("US5Y");
    ASSERT_TRUE(pos.has_value());
    EXPECT_EQ(pos->getInstrumentSymbol(), "US5Y");
}

TEST_F(PortfolioTest, GetPositionBySymbol_NotFound) {
    auto pos = portfolio.getPosition("NONEXISTENT");
    EXPECT_FALSE(pos.has_value());
}

TEST_F(PortfolioTest, GetTotalPnL_CorrectCalculation) {
    std::map<std::string, double> currentPrices = {
        {"US10Y", 1050.0},
        {"US5Y", 480.0}
    };
    double expectedPnL = (1050.0 - 1000.0) * 10 + (480.0 - 500.0) * 20;
    EXPECT_DOUBLE_EQ(portfolio.getTotalPnL(currentPrices), expectedPnL);
}

TEST_F(PortfolioTest, GetTotalPnL_MissingPriceExpectError) {
    // Test with missing price for US5Y
    // This should throw an exception since US5Y price is not provided
    std::map<std::string, double> currentPrices = {
        {"US10Y", 1050.0}
        // US5Y missing
    };
    EXPECT_THROW(portfolio.getTotalPnL(currentPrices), std::runtime_error);
}

TEST_F(PortfolioTest, AddPosition_UpdatesExistingPosition) {
    // Add a position with the same symbol as pos1, expect an exception
    Position updatedPos{bond1, 990.0, 5};
    EXPECT_THROW(portfolio.addPosition(updatedPos), std::invalid_argument);
}

TEST_F(PortfolioTest, PortfolioIsEmptyInitially) {
    Portfolio emptyPortfolio;
    EXPECT_EQ(emptyPortfolio.size(), (size_t)0);
}

TEST_F(PortfolioTest, GetAllPositions_ReturnsAll) {
    auto positions = portfolio.getPositions();
    EXPECT_EQ(positions.size(), (size_t)2);
    EXPECT_EQ(positions[0].getInstrumentSymbol(), "US10Y");
    EXPECT_EQ(positions[1].getInstrumentSymbol(), "US5Y");
}