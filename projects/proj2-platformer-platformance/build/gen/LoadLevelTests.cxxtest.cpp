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

bool suite_LoadLevelTestSuite_init = false;
#include "/Users/carterweinberg/gameEngines/projects/proj2-platformer-platformance/test/LoadLevelTests.cxxtest.hpp"

static LoadLevelTestSuite suite_LoadLevelTestSuite;

static CxxTest::List Tests_LoadLevelTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_LoadLevelTestSuite( "test/LoadLevelTests.cxxtest.hpp", 9, "LoadLevelTestSuite", suite_LoadLevelTestSuite, Tests_LoadLevelTestSuite );

static class TestDescription_suite_LoadLevelTestSuite_testLoadLeveleWorking : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_LoadLevelTestSuite_testLoadLeveleWorking() : CxxTest::RealTestDescription( Tests_LoadLevelTestSuite, suiteDescription_LoadLevelTestSuite, 15, "testLoadLeveleWorking" ) {}
 void runTest() { suite_LoadLevelTestSuite.testLoadLeveleWorking(); }
} testDescription_suite_LoadLevelTestSuite_testLoadLeveleWorking;

