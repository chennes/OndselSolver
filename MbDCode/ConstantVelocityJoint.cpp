#include "ConstantVelocityJoint.h"
#include "System.h"
#include "AtPointConstraintIJ.h"
#include "CREATE.h"
#include "ConstVelConstraintIJ.h"

using namespace MbD;

MbD::ConstantVelocityJoint::ConstantVelocityJoint()
{
}

MbD::ConstantVelocityJoint::ConstantVelocityJoint(const char* str) : AtPointJoint(str)
{
}

void MbD::ConstantVelocityJoint::initializeGlobally()
{
	if (constraints->empty())
	{
		createAtPointConstraints();
		addConstraint(CREATE<ConstVelConstraintIJ>::With(frmI, frmJ));
		this->root()->hasChanged = true;
	}
	else {
		Joint::initializeGlobally();
	}
}

void MbD::ConstantVelocityJoint::connectsItoJ(EndFrmcptr frmIe, EndFrmcptr frmJe)
{
	//"Subsequent prescribed motions may make frmIe, frmJe become prescribed end frames."
	//"Use newCopyEndFrameqc to prevent efrms from becoming EndFrameqct."

	frmI = frmIe->newCopyEndFrameqc();
	frmJ = frmJe->newCopyEndFrameqc();
}