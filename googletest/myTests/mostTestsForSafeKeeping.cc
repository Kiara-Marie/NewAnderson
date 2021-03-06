
// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "gtest/gtest.h"
#include <iostream>
#include <armadillo>
#include <math.h>
#include <string>
#include <fstream>
#include <ostream>
#include <vector>
#include "../../metrics/metric.h"
#include "../../metrics/levelSpacings.h"
#include "../../resultFinder.h"
#include "../../runSim1D.h"
#include "../../metrics/avgEigVec.h"
#include "../../metrics/utils.h"
#include "../../metrics/inversePR.h"
#include "../../metrics/aboutRun.h"
#include "../../jComputer.h"
#include "../../jComputers/lorentz.h"
#include "../../metrics/energyLevels.h"
#include "../../runSimA.h"
#include "../../runSimSimple.h"
#include "../../resultNoDiag.h"
#include "../../jComputers/lorentzWithoutRDep.h"
#include "../../jComputers/gauss.h"
#include "../../jComputers/constant.h"
#include "../../findE.h"

using namespace std;
using namespace arma;
namespace {

// Step 2. Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.
// After using the macro, you should define your test logic between a
// pair of braces.  You can use a bunch of macros to indicate the
// success or failure of a test.  EXPECT_TRUE and EXPECT_EQ are
// examples of such macros.  For a complete list, see gtest.h.
//
// <TechnicalDetails>
//
// In Google Test, tests are grouped into test cases.  This is how we
// keep test code organized.  You should put logically related tests
// into the same test case.
//
// The test case name and the test name should both be valid C++
// identifiers.  And you should not use underscore (_) in the names.
//
// Google Test guarantees that each test you define is run exactly
// once, but it makes no guarantee on the order the tests are
// executed.  Therefore, you should write your tests in such a way
// that their results don't depend on their order.
//
// </TechnicalDetails>

int MIN_N = 30;

// Tests that the date given isn't crazy
TEST(UtilsTest,GetDate) {
  int firstVal = (int) (*getDate().begin()) - '0';
  EXPECT_LE(firstVal, 3);
}

TEST(UtilsTest,GetTime){
    char first = (char) *(getTime().begin());
    EXPECT_EQ (first, 'T');
}

TEST(JComputer, Plain){
    JComputer myJC = JComputer(3,0,2);
    JComputer copyJC = JComputer(myJC);
    ASSERT_ANY_THROW(myJC.jFinder(3,4));
}

TEST(FindE, BindingEnergy){
    // No defect
    int ndn = 30;
    int ndl = 5;
    double ndnd = (double) ndn;
    EXPECT_EQ(bindingEnergy(ndn,ndl), 1/(ndnd*ndnd));

    // with defect

    int n = 61;
    int bigDefectL = 1;
    int smallDefectL = 3;

    EXPECT_LT(bindingEnergy(n,smallDefectL),bindingEnergy(n,bigDefectL));
}

TEST(RunSim1D,IsSymmetric){
    mat A = { {1, 3, 5},
              {2, 4, 6} };
    EXPECT_FALSE(is_symmetric(A));

    mat B = { {1, 2, 1},
              {2, 2, 3},
              {1, 3, 3}
          };
    EXPECT_TRUE(is_symmetric(B));

    mat C = { {1, 2, 1},
              {2, 2, 3},
              {1, 4, 3}
          };

    EXPECT_FALSE(is_symmetric(C));
}

TEST(RunSim1D, GetNs){
    double W = 15;
    int len = 30;
    vec nValues = getNs(len,W);

    for (int i = 0; i < len; i++){
        EXPECT_GE(nValues(i), MIN_N);
        EXPECT_LE(nValues(i), MIN_N + W);
    }
}

TEST(RunSim1D, SimpleSims){
    Constant testJC = Constant(4,0,0);
    double W = 3;
    double t = 4;
    // unsymmetric matrix shouldn't throw an error, since it should be overwritten
    mat notSymMat = { {1, 2, 1},
                      {2, 2, 3},
                      {1, 4, 3}
                    };
    EXPECT_NO_THROW(runSim1D(W,3,notSymMat, testJC));
    for (int i = 0; i<3;i++){
        for (int j = 0 ; j<3; j++){
            if (i != j){
                EXPECT_EQ(notSymMat(i,j),t);
            } else {
                EXPECT_LE(notSymMat(i,j),1);
                EXPECT_GT(notSymMat(i,j),0);
            }
        }
    }

    // W = 0 should throw an error
    EXPECT_ANY_THROW(runSim1D(0,3,notSymMat,testJC));

}

TEST(RunSimA, SimpleSims){
    Constant testJC = Constant(4,0,0);

    // unsymmetric matrix shouldn't throw an error, since it should be overwritten
    mat notSymMat = { {1, 2, 1},
                      {2, 2, 3},
                      {1, 4, 3}
                    };
    EXPECT_NO_THROW(runSimA(3,3,notSymMat, testJC));
    for (int i = 0; i<3;i++){
        for (int j = 0 ; j<3; j++){
            if (i != j){
                EXPECT_EQ(notSymMat(i,j),4);
            } else {
                EXPECT_LE(notSymMat(i,j),3);
                EXPECT_GT(notSymMat(i,j),0);
            }
        }
    }

    // W = 0 should throw an error
    EXPECT_ANY_THROW(runSimA(0,3,notSymMat,testJC));

}

TEST(RunSimSimple, SimpleSims){
    double W = 5;
    double t = 4;
    Constant testJC = Constant(t,0,0);

    // unsymmetric matrix shouldn't throw an error, since it should be overwritten
    mat notSymMat = { {1, 2, 1},
                      {2, 2, 3},
                      {1, 4, 3}
                    };
    EXPECT_NO_THROW(runSimSimple(W,3,notSymMat, testJC));
    for (int i = 0; i<3;i++){
        for (int j = 0 ; j<3; j++){
            if (i != j){
                EXPECT_EQ(notSymMat(i,j),t);
            } else {
                double halfW = W/2;
                EXPECT_LE(notSymMat(i,j),halfW);
                EXPECT_GT(notSymMat(i,j),-1*halfW);
            }
        }
    }

    int lenA = 20;
    mat A(lenA,lenA);
    // W = 0 should give 2 on all diagonal entries
    EXPECT_NO_THROW(runSimSimple(0, lenA, A, testJC));
    for (int i = 0; i<lenA;i++){
        for (int j = 0 ; j<lenA; j++){
            if (i != j){
                EXPECT_EQ(A(i,j),t);
            } else {
                EXPECT_EQ(A(i,j),2);
            }
        }
    }

}

TEST(ResultFinder, Simple){

    vector<metric*> metrics;
    ResultFinder rf = ResultFinder(metrics);
    // make sure any matrix you are testing is symmetric, 
    // because our diagonalization expects symmetric matrices 
    mat A =     {{1, 2, 1},
                 {2, 2, 3},
                 {1, 3, 3}
                };
    pair<vec, mat> resultPair = rf.saveResults(A,3);
    vec eigval = resultPair.first;
    mat eigvec = resultPair.second;
    //Apply A to first eigvec 
    vec applyA = A * eigvec.col(0);
	// Multiplied first eigvec by first eigval
	vec byFactor = eigvec.col(0) * eigval(0);
	// if diagonalization happened properly, they should be equal
    for (unsigned int i = 0; i< byFactor.n_elem; i++){
        EXPECT_DOUBLE_EQ(byFactor(i), applyA(i));
    }
    
}

TEST(ResultFinder, Simple){

    vector<metric*> metrics;
    ResultFinder rf = ResultFinder(metrics);
    // make sure any matrix you are testing is symmetric, 
    // because our diagonalization expects symmetric matrices 
    mat A =     {{1, 2, 1},
                 {2, 2, 3},
                 {1, 3, 3}
                };
    pair<vec, mat> resultPair = rf.saveResults(A,3);
    vec eigval = resultPair.first;
    mat eigvec = resultPair.second;
    //Apply A to first eigvec 
    vec applyA = A * eigvec.col(0);
	// Multiplied first eigvec by first eigval
	vec byFactor = eigvec.col(0) * eigval(0);
	// if diagonalization happened properly, they should be equal
    for (unsigned int i = 0; i< byFactor.n_elem; i++){
        EXPECT_DOUBLE_EQ(byFactor(i), applyA(i));
    }
    
}


}
