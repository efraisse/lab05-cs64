#include <stdio.h>
#include "DecodeCode.h"

/* To make:
 * $ gcc DecodeCodeTester.c DecodeCode.c -o decode_tester
 *
 * To run:
 * $ ./decode_tester
 */

#define NUM_TEST_CASES 2

struct Test {
  int input;
  mipsinstruction expectedOutput;
};

struct Test TESTS[NUM_TEST_CASES] = {
  {
    19546144,
    {
      32,
      16416,
      8,
      10,
      9,
      0
    }
  },
  {
    640745471,
    {
      63,
      -1,
      31,
      16,
      17,
      9
    }
  }
};

// returns 1 on success, else 0
int runTest(struct Test* test) {
  mipsinstruction* exp = &test->expectedOutput;
  mipsinstruction got = decode(test->input);
  return (exp->funct == got.funct &&
          exp->immediate == got.immediate &&
          exp->rd == got.rd &&
          exp->rt == got.rt &&
          exp->rs == got.rs &&
          exp->opcode == got.opcode);
          std::cout << "expected funct: " << exp->funct << std::endl;
          std::cout << "actual funct: " << got.funct << std::endl;
          std::cout << "expected immediate: " << exp->immediate << std::endl;
          std::cout << "actual immediate: " << got.immediate << std::endl;
          std::cout << "expected rd: " << exp->rd << std::endl;
          std::cout << "actual rd: " << got.rd << std::endl;
          std::cout << "expected rt: " << exp->rt << std::endl;
          std::cout << "actual rt: " << got.rt << std::endl;
          std::cout << "expected rs: " << exp->rs << std::endl;
          std::cout << "actual rs: " << got.rs << std::endl;
          std::cout << "expected opcode: " << exp->opcode << std::endl;
          std::cout << "actual opcode: " << got.opcode << std::endl;
}
          
int main(int argc, char** argv) {
  unsigned int testNum;
  unsigned int numPassed = 0;
  unsigned int numFailed = 0;
  
  for (testNum = 0; testNum < NUM_TEST_CASES; ++testNum) {
    if (runTest(&TESTS[testNum])) {
      numPassed++;
    } else {
      printf("Failed on test %u\n", testNum);
      numFailed++;
    }
  }

  printf("Num passed: %u\n", numPassed);
  printf("Num failed: %u\n", numFailed);

  return 0;
}
