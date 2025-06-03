#include "Position.h"

std::string& Position::getInstrumentSymbol() {
    return _symbol;
}

double Position::calculatePnL(double currentPrice) {
    return calculateUnitPnL(currentPrice, purchasePrice) * quantity;
}

