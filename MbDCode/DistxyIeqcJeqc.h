#pragma once

#include "DistxyIeqcJec.h"

namespace MbD {
	class DistxyIeqcJeqc : public DistxyIeqcJec
	{
		//pdistxypXJ pdistxypEJ ppdistxypXIpXJ ppdistxypXIpEJ ppdistxypEIpXJ ppdistxypEIpEJ ppdistxypXJpXJ ppdistxypXJpEJ ppdistxypEJpEJ
	public:
		DistxyIeqcJeqc();
		DistxyIeqcJeqc(EndFrmcptr frmi, EndFrmcptr frmj);

		void calc_ppdistxypEIpEJ();
		void calc_ppdistxypEIpXJ();
		void calc_ppdistxypEJpEJ();
		void calc_ppdistxypXIpEJ();
		void calc_ppdistxypXIpXJ();
		void calc_ppdistxypXJpEJ();
		void calc_ppdistxypXJpXJ();
		void calc_pdistxypEJ();
		void calc_pdistxypXJ();
		void calcPostDynCorrectorIteration() override;
		void init_xyIeJeIe() override;
		void initialize() override;
		FMatDsptr ppvaluepEIpEJ() override;
		FMatDsptr ppvaluepEIpXJ() override;
		FMatDsptr ppvaluepEJpEJ() override;
		FMatDsptr ppvaluepXIpEJ() override;
		FMatDsptr ppvaluepXIpXJ() override;
		FMatDsptr ppvaluepXJpEJ() override;
		FMatDsptr ppvaluepXJpXJ() override;
		FRowDsptr pvaluepEJ() override;
		FRowDsptr pvaluepXJ() override;


		FRowDsptr pdistxypXJ, pdistxypEJ;
		FMatDsptr ppdistxypXIpXJ, ppdistxypXIpEJ, ppdistxypEIpXJ, ppdistxypEIpEJ, ppdistxypXJpXJ, ppdistxypXJpEJ, ppdistxypEJpEJ;

	};
}

