#pragma once

#include <vector>

struct TestQueue {
	static inline std::vector<void(*)()> unitTestQueue;
};

/*
#define ADD_UNIT_TEST(TEST_NAME) \
void TEST_NAME(); \
void __attribute__((constructor)) Queue_##TEST_NAME() { \
	unitTestQueue.push_back(TEST_NAME); \
} \
void TEST_NAME()
*/

#define ADD_UNIT_TEST(TEST_NAME) \
void TEST_NAME(); \
struct Queue_##TEST_NAME : private TestQueue { \
	Queue_##TEST_NAME() { TestQueue::unitTestQueue.push_back(TEST_NAME); } \
} q_##TEST_NAME; \
void TEST_NAME()
