#include "AtPointConstraintIqcJqc.h"
#include "DispCompIeqcJeqcO.h"
#include "CREATE.h"
#include "EndFrameqc.h"

using namespace MbD;

AtPointConstraintIqcJqc::AtPointConstraintIqcJqc(EndFrmcptr frmi, EndFrmcptr frmj, int axisi) :
	AtPointConstraintIqcJc(frmi, frmj, axisi)
{
}

void MbD::AtPointConstraintIqcJqc::initializeGlobally()
{
	AtPointConstraintIqcJc::initializeGlobally();
	ppGpEJpEJ = (std::static_pointer_cast<DispCompIeqcJeqcO>(riIeJeO))->ppriIeJeOpEJpEJ;
}

void AtPointConstraintIqcJqc::initriIeJeO()
{
	riIeJeO = CREATE<DispCompIeqcJeqcO>::With(frmI, frmJ, axis);
}

void MbD::AtPointConstraintIqcJqc::calcPostDynCorrectorIteration()
{
	AtPointConstraintIqcJc::calcPostDynCorrectorIteration();
	pGpEJ = std::static_pointer_cast<DispCompIeqcJeqcO>(riIeJeO)->priIeJeOpEJ;
}

void MbD::AtPointConstraintIqcJqc::useEquationNumbers()
{
	AtPointConstraintIqcJc::useEquationNumbers();
	iqXJminusOnePlusAxis = std::static_pointer_cast<EndFrameqc>(frmJ)->iqX() + axis;
	iqEJ = std::static_pointer_cast<EndFrameqc>(frmJ)->iqE();
}

void MbD::AtPointConstraintIqcJqc::fillPosICError(FColDsptr col)
{
	AtPointConstraintIqcJc::fillPosICError(col);
	col->at(iqXJminusOnePlusAxis) += lam;
	col->atiplusFullVectortimes(iqEJ, pGpEJ, lam);
}

void MbD::AtPointConstraintIqcJqc::fillPosICJacob(SpMatDsptr mat)
{
	AtPointConstraintIqcJc::fillPosICJacob(mat);
	(*(mat->at(iG)))[iqXJminusOnePlusAxis] += 1.0;
	(*(mat->at(iqXJminusOnePlusAxis)))[iG] += 1.0;
	mat->atijplusFullRow(iG, iqEJ, pGpEJ);
	mat->atijplusFullColumn(iqEJ, iG, pGpEJ->transpose());
	mat->atijplusFullMatrixtimes(iqEJ, iqEJ, ppGpEJpEJ, lam);
}
