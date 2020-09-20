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

bool suite_GameObjectsTestSuite_init = false;
#include "/Users/carterweinberg/gameEngines/projects/proj2-platformer-platformance/test/GameObjectTests.cxxtest.hpp"

static GameObjectsTestSuite suite_GameObjectsTestSuite;

static CxxTest::List Tests_GameObjectsTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_GameObjectsTestSuite( "test/GameObjectTests.cxxtest.hpp", 8, "GameObjectsTestSuite", suite_GameObjectsTestSuite, Tests_GameObjectsTestSuite );

static class TestDescription_suite_GameObjectsTestSuite_testCoords : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameObjectsTestSuite_testCoords() : CxxTest::RealTestDescription( Tests_GameObjectsTestSuite, suiteDescription_GameObjectsTestSuite, 14, "testCoords" ) {}
 void runTest() { suite_GameObjectsTestSuite.testCoords(); }
} testDescription_suite_GameObjectsTestSuite_testCoords;

static class TestDescription_suite_GameObjectsTestSuite_testSetCoordsX : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameObjectsTestSuite_testSetCoordsX() : CxxTest::RealTestDescription( Tests_GameObjectsTestSuite, suiteDescription_GameObjectsTestSuite, 23, "testSetCoordsX" ) {}
 void runTest() { suite_GameObjectsTestSuite.testSetCoordsX(); }
} testDescription_suite_GameObjectsTestSuite_testSetCoordsX;

static class TestDescription_suite_GameObjectsTestSuite_testSetCoordsY : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameObjectsTestSuite_testSetCoordsY() : CxxTest::RealTestDescription( Tests_GameObjectsTestSuite, suiteDescription_GameObjectsTestSuite, 31, "testSetCoordsY" ) {}
 void runTest() { suite_GameObjectsTestSuite.testSetCoordsY(); }
} testDescription_suite_GameObjectsTestSuite_testSetCoordsY;

static class TestDescription_suite_GameObjectsTestSuite_testSetCoordsW : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameObjectsTestSuite_testSetCoordsW() : CxxTest::RealTestDescription( Tests_GameObjectsTestSuite, suiteDescription_GameObjectsTestSuite, 39, "testSetCoordsW" ) {}
 void runTest() { suite_GameObjectsTestSuite.testSetCoordsW(); }
} testDescription_suite_GameObjectsTestSuite_testSetCoordsW;

static class TestDescription_suite_GameObjectsTestSuite_testSetCoordsH : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_GameObjectsTestSuite_testSetCoordsH() : CxxTest::RealTestDescription( Tests_GameObjectsTestSuite, suiteDescription_GameObjectsTestSuite, 47, "testSetCoordsH" ) {}
 void runTest() { suite_GameObjectsTestSuite.testSetCoordsH(); }
} testDescription_suite_GameObjectsTestSuite_testSetCoordsH;

