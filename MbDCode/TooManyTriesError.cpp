/***************************************************************************
 *   Copyright (c) 2023 Ondsel, Inc.                                       *
 *                                                                         *
 *   This file is part of OndselSolver.                                    *
 *                                                                         *
 *   See LICENSE file for details about copyright.                         *
 ***************************************************************************/
 
#include "TooManyTriesError.h"

using namespace MbD;

TooManyTriesError::TooManyTriesError(const std::string& msg) : std::runtime_error(msg)
{
}
