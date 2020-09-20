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

bool suite_ATestSuite_init = false;
#include "/Users/carterweinberg/gameEngines/projects/proj2-platformer-platformance/test/ComponentTests.cxxtest.hpp"

static ATestSuite suite_ATestSuite;

static CxxTest::List Tests_ATestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ATestSuite( "test/ComponentTests.cxxtest.hpp", 8, "ATestSuite", suite_ATestSuite, Tests_ATestSuite );

static class TestDescription_suite_ATestSuite_testAddScoreWorking : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ATestSuite_testAddScoreWorking() : CxxTest::RealTestDescription( Tests_ATestSuite, suiteDescription_ATestSuite, 14, "testAddScoreWorking" ) {}
 void runTest() { suite_ATestSuite.testAddScoreWorking(); }
} testDescription_suite_ATestSuite_testAddScoreWorking;

