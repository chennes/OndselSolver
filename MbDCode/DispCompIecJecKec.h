#pragma once

#include "KinematicIeJe.h"

namespace MbD {
    class DispCompIecJecKec : public KinematicIeJe
    {
        //efrmK axisK riIeJeKe aAjOKe rIeJeO 
    public:
        DispCompIecJecKec();
        DispCompIecJecKec(EndFrmcptr frmi, EndFrmcptr frmj, EndFrmcptr frmk, int axisk);

        double value() override;

        EndFrmcptr efrmK;
        int axisK;
        double riIeJeKe;
        FColDsptr aAjOKe;
        FColDsptr rIeJeO;
    };
}
