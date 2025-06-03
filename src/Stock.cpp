#include "Stock.h"

Stock::Stock(std::string sym, std::string nam) : Instrument(sym, nam) {}

double Stock::calculateUnitPnL (double currentPrice, double purchasePrice) const {
    return currentPrice - purchasePrice;
}

