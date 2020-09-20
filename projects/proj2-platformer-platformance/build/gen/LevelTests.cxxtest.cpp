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

bool suite_LevelTestSuite_init = false;
#include "/Users/carterweinberg/gameEngines/projects/proj2-platformer-platformance/test/LevelTests.cxxtest.hpp"

static LevelTestSuite suite_LevelTestSuite;

static CxxTest::List Tests_LevelTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_LevelTestSuite( "test/LevelTests.cxxtest.hpp", 8, "LevelTestSuite", suite_LevelTestSuite, Tests_LevelTestSuite );

static class TestDescription_suite_LevelTestSuite_testScore : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_LevelTestSuite_testScore() : CxxTest::RealTestDescription( Tests_LevelTestSuite, suiteDescription_LevelTestSuite, 14, "testScore" ) {}
 void runTest() { suite_LevelTestSuite.testScore(); }
} testDescription_suite_LevelTestSuite_testScore;

static class TestDescription_suite_LevelTestSuite_testAddObject : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_LevelTestSuite_testAddObject() : CxxTest::RealTestDescription( Tests_LevelTestSuite, suiteDescription_LevelTestSuite, 20, "testAddObject" ) {}
 void runTest() { suite_LevelTestSuite.testAddObject(); }
} testDescription_suite_LevelTestSuite_testAddObject;

static class TestDescription_suite_LevelTestSuite_testRemoveObject : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_LevelTestSuite_testRemoveObject() : CxxTest::RealTestDescription( Tests_LevelTestSuite, suiteDescription_LevelTestSuite, 30, "testRemoveObject" ) {}
 void runTest() { suite_LevelTestSuite.testRemoveObject(); }
} testDescription_suite_LevelTestSuite_testRemoveObject;

