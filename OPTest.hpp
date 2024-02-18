#pragma once

#include <vector>

struct UNIT_TestQueue {
	static inline std::vector<void(*)()> UNIT_testQueue;
};

#define ADD_UNIT_TEST(TEST_NAME) _OPTEST_INTERNAL_ADD_TEST(UNIT, TEST_NAME)

#define _OPTEST_INTERNAL_ADD_TEST(TEST_TYPE, TEST_NAME) \
void TEST_TYPE ## _ ## TEST_NAME(); \
struct Queue_ ## TEST_TYPE ## _ ## TEST_NAME : private TEST_TYPE ## _TestQueue { \
	Queue_ ## TEST_TYPE ## _ ## TEST_NAME() { TEST_TYPE ## _TestQueue::TEST_TYPE ## _testQueue.push_back(TEST_TYPE ## _ ## TEST_NAME); } \
} q_ ## TEST_TYPE ## _ ## TEST_NAME; \
void TEST_TYPE ## _ ## TEST_NAME()

/*
#define ADD_UNIT_TEST(TEST_NAME) \
void TEST_NAME(); \
void __attribute__((constructor)) Queue_##TEST_NAME() { \
	unitTestQueue.push_back(TEST_NAME); \
} \
void TEST_NAME()
*/
