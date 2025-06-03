#include "Bond.h"

Bond::Bond(const std::string &sym, const std::string &nam, double fv, double cr)
    : Instrument(sym, nam), faceValue(fv), couponRate(cr) {
}

double Bond::calculateUnitPnL(double currentPrice, double purchasePrice) const {
    return currentPrice - purchasePrice;
}

