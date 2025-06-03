#include "Portfolio.h"

void Portfolio::addPosition(const Position& position) {
    // Check if the position already exists in the portfolio
    auto existingPosition = getPosition(position.getInstrumentSymbol());
    if (existingPosition.has_value()) {
        throw std::invalid_argument("Position with this symbol already exists in the portfolio");
    }
    positions_.push_back(position);
}

std::optional<Position> Portfolio::getPosition(const std::string& symbol) const {
    for (const auto& pos : positions_) {
        if (pos.getInstrumentSymbol() == symbol) {
            return pos;
        }
    }
    return std::nullopt;  // Return empty optional if not found
}

bool Portfolio::removePosition(const std::string& symbol) {
    auto it = std::remove_if(positions_.begin(), positions_.end(),
                             [&symbol](const Position& pos) {
                                 return pos.getInstrumentSymbol() == symbol;
                             });
    if (it != positions_.end()) {
        positions_.erase(it, positions_.end());
        return true;  // Position was found and removed
    }
    return false;  // Position with the given symbol was not found
}

double Portfolio::getTotalPnL(const std::map<std::string, double>& currentPrices) const {
    double totalPnL = 0.0;
    for (const auto& position : positions_) {
        auto it = currentPrices.find(position.getInstrumentSymbol());
        if (it != currentPrices.end()) {
            totalPnL += position.calculatePnL(it->second);
        } else {
            throw std::runtime_error("Not found the price for instrument");
        }
    }
    return totalPnL;
}
