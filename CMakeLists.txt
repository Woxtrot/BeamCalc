cmake_minimum_required(VERSION 3.26)
project(BeamCalc)

set(CMAKE_CXX_STANDARD 17)

add_executable(BeamCalc main.cpp
        problem.cpp
        problem.h
        beamProblem.cpp
        beamProblem.h
        barProblem.cpp
        barProblem.h
        shaftProblem.cpp
        shaftProblem.h
        calculateAreaMoment.cpp
        calculateAreaMoment.h
        errorCheck.cpp
        errorCheck.h
)
