#include "Position.h"

Position::Position(std::shared_ptr<Instrument> instr, double price, int qty)
    : instrument(std::move(instr)), purchasePrice(price), quantity(qty) {
    if (!instrument) {
        throw std::invalid_argument("Instrument cannot be null");
    }
}

const std::string& Position::getInstrumentSymbol() const {
    return instrument->getSymbol();
}

double Position::calculatePnL(double currentPrice) const {
    return instrument->calculateUnitPnL(currentPrice, purchasePrice) * quantity;
}

