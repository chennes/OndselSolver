#pragma once

#include "VectorNewtonRaphson.h"
#include "SparseMatrix.h"

namespace MbD {
    //class SparseMatrix;

    class SystemNewtonRaphson : public VectorNewtonRaphson
    {
        //
    public:
        void initializeGlobally() override;
        virtual void assignEquationNumbers() = 0;
        virtual void createVectorsAndMatrices();
        std::shared_ptr<MatrixSolver> matrixSolverClassNew() override;
        void calcdxNorm() override;
        void basicSolveEquations() override;
        void handleSingularMatrix() override;

        std::shared_ptr<SparseMatrix<double>> pypx;
    };
}
