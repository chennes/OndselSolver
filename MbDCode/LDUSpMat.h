#pragma once

#include "MatrixLDU.h"
#include "SparseMatrix.h"

namespace MbD {
    class LDUSpMat : public MatrixLDU
    {
        //matrixL matrixD matrixU markowitzPivotRowCount markowitzPivotColCount privateIndicesOfNonZerosInPivotRow rowPositionsOfNonZerosInPivotColumn 
    public:
        FColDsptr basicSolvewithsaveOriginal(SpMatDsptr spMat, FColDsptr fullCol, bool saveOriginal) override;
        void decomposesaveOriginal(FMatDsptr fullMat, bool saveOriginal);
        void decomposesaveOriginal(SpMatDsptr spMat, bool saveOriginal);
        FColDsptr forAndBackSubsaveOriginal(FColDsptr fullCol, bool saveOriginal);
        double getmatrixArowimaxMagnitude(int i) override;
        void forwardSubstituteIntoL() override;
        void backSubstituteIntoDU() override;

        std::shared_ptr<SparseMatrix<double>> matrixA, matrixL, matrixU;
        std::shared_ptr<DiagonalMatrix<double>> matrixD;
        int markowitzPivotRowCount, markowitzPivotColCount;
        std::shared_ptr<std::vector<int>> rowPositionsOfNonZerosInPivotColumn;
    };
}
