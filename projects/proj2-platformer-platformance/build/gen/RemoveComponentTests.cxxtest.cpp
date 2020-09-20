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

bool suite_RemoveTestSuite_init = false;
#include "/Users/carterweinberg/gameEngines/projects/proj2-platformer-platformance/test/RemoveComponentTests.cxxtest.hpp"

static RemoveTestSuite suite_RemoveTestSuite;

static CxxTest::List Tests_RemoveTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_RemoveTestSuite( "test/RemoveComponentTests.cxxtest.hpp", 8, "RemoveTestSuite", suite_RemoveTestSuite, Tests_RemoveTestSuite );

static class TestDescription_suite_RemoveTestSuite_testRemoveWorking : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_RemoveTestSuite_testRemoveWorking() : CxxTest::RealTestDescription( Tests_RemoveTestSuite, suiteDescription_RemoveTestSuite, 14, "testRemoveWorking" ) {}
 void runTest() { suite_RemoveTestSuite.testRemoveWorking(); }
} testDescription_suite_RemoveTestSuite_testRemoveWorking;

