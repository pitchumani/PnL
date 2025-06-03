#include <gtest/gtest.h>
#include "Instrument.h"

// A simple concrete subclass for testing Instrument
class TestInstrument : public Instrument {
public:
    TestInstrument(const std::string& sym, const std::string& nam)
        : Instrument(sym, nam) {}
    double calculateUnitPnL(double currentPrice, double purchasePrice) const override {
        return currentPrice - purchasePrice;
    }
};

class InstrumentTest : public ::testing::Test {
protected:
    TestInstrument instrument{"SYM", "Test Instrument"};
};

TEST_F(InstrumentTest, Constructor_SetsSymbolAndName) {
    EXPECT_EQ(instrument.getSymbol(), "SYM");
    EXPECT_EQ(instrument.getName(), "Test Instrument");
}

TEST_F(InstrumentTest, GetSymbol_ReturnsReference) {
    std::string& symbolRef = instrument.getSymbol();
    symbolRef = "NEWSYM";
    EXPECT_EQ(instrument.getSymbol(), "NEWSYM");
}

TEST_F(InstrumentTest, GetName_ReturnsReference) {
    std::string& nameRef = instrument.getName();
    nameRef = "New Name";
    EXPECT_EQ(instrument.getName(), "New Name");
}

TEST_F(InstrumentTest, CalculateUnitPnL_WorksCorrectly) {
    EXPECT_DOUBLE_EQ(instrument.calculateUnitPnL(120.0, 100.0), 20.0);
    EXPECT_DOUBLE_EQ(instrument.calculateUnitPnL(80.0, 100.0), -20.0);
    EXPECT_DOUBLE_EQ(instrument.calculateUnitPnL(100.0, 100.0), 0.0);
}