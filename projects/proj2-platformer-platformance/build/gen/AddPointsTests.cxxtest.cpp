/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

bool suite_AddPointsTestSuite_init = false;
#include "/Users/carterweinberg/gameEngines/projects/proj2-platformer-platformance/test/AddPointsTests.cxxtest.hpp"

static AddPointsTestSuite suite_AddPointsTestSuite;

static CxxTest::List Tests_AddPointsTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_AddPointsTestSuite( "test/AddPointsTests.cxxtest.hpp", 9, "AddPointsTestSuite", suite_AddPointsTestSuite, Tests_AddPointsTestSuite );

static class TestDescription_suite_AddPointsTestSuite_testRemoveWorking : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AddPointsTestSuite_testRemoveWorking() : CxxTest::RealTestDescription( Tests_AddPointsTestSuite, suiteDescription_AddPointsTestSuite, 15, "testRemoveWorking" ) {}
 void runTest() { suite_AddPointsTestSuite.testRemoveWorking(); }
} testDescription_suite_AddPointsTestSuite_testRemoveWorking;

