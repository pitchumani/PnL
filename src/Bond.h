#ifndef PNL_BOND_H_
#define PNL_BOND_H_

#include "Instrument.h"

class Bond : public Instrument {
protected:
    double faceValue;
    double couponRate;

public:
    Bond(const std::string &sym, const std::string &nam, double fv, double cr);
    double calculateUnitPnL(double currentPrice, double purchasePrice) const override;
};

#endif  // PNL_BOND_H_

