#pragma once

#include "FunctionX.h"

namespace MbD {
    class Reciprocal : public FunctionX
    {
        //
    public:
        Reciprocal() = default;
        Reciprocal(Symsptr arg);
        double getValue() override;
        Symsptr differentiateWRTx() override;

        std::ostream& printOn(std::ostream& s) const override;

    };
}
