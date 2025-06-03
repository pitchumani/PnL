#include<iostream>

#include "Bond.h"
#include "Stock.h"
#include "Portfolio.h"
#include "Position.h"

int main (int argc, char *argv[]) {
    std::cout << "Portfolio PnL Calculator" << std::endl;
    // hardcoded portfolio data
    auto instrumentApple = std::make_shared<Stock>("AAPL", "Apple Inc.");
    auto instrumentGoogle = std::make_shared<Stock>("GOOG", "Alphabet Inc.");
    auto instrumentBond1 = std::make_shared<Bond>("US10Y", "US Treasury 10Y", 1000.0, 0.04);
    auto instrumentBond2 = std::make_shared<Bond>("US20Y", "US Treasury 20Y", 1000.0, 0.03);

    // 100 AAPL shares at $150
    Position posApple(instrumentApple, 150, 100);
    // 50 GOOG shares at $100
    Position posGoogle(instrumentGoogle, 100, 50);
    // 1 US10Y bond at $980
    Position posBond1(instrumentBond1, 980, 1);
    // 1 US20Y bond at $1050
    Position posBond2(instrumentBond2, 1050, 1);

    // market prices data
    std::map<std::string, double> currentPrices = {
        {"AAPL", 155.0},  // Apple Inc. current price
        {"GOOG", 95.0},   // Alphabet Inc. current price
        {"US10Y", 1020.0}, // US Treasury 10Y current price
        {"US20Y", 1100.0}  // US Treasury 20Y current price
    };

    // create portfolio
    Portfolio portfolio;
    portfolio.addPosition(posApple);
    portfolio.addPosition(posGoogle);
    portfolio.addPosition(posBond1);
    portfolio.addPosition(posBond2);
    // calculate total PnL
    try {
        auto positions = portfolio.getPositions();
        if (positions.empty()) {
            std::cout << "Portfolio is empty." << std::endl;
            return 0;
        }
        std::cout << "Portfolio summary:" << std::endl;
        std::cout << "Instrument | Quantity | Purchase Price" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        for (const auto& position : portfolio.getPositions()) {
            std::cout << position.getInstrumentSymbol() << " | "
                      << position.getQuantity() << " | "
                      << position.getPurchasePrice() << std::endl;
        }
        std::cout << "----------------------------------------" << std::endl;
        double totalPnL = portfolio.getTotalPnL(currentPrices);
        std::cout << "Total Portfolio PnL: $" << totalPnL << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error calculating PnL: " << e.what() << std::endl;
    }
    return 0;
}

