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
  printf("expected funct: %u\n", exp->funct);
  printf("actual funct: %u\n", got.funct);
  printf("expected immediate: %u\n", exp->immediate);
  printf("actual immediate: %u\n", got.immediate);
  printf("expected rd: %u\n", exp->rd);
  printf("actual rd: %u\n", got.rd);
  printf("expected rt: %u\n", exp->rt);
  printf("actual rt: %u\n", got.rt);
  printf("expected rs: %u\n", exp->rt);
  printf("actual rs: %u\n", got.rs);
  printf("expected opcode: %u\n", exp->opcode);
  printf("actual opcode: %u\n\n", got.opcode);
  return (exp->funct == got.funct &&
          exp->immediate == got.immediate &&
          exp->rd == got.rd &&
          exp->rt == got.rt &&
          exp->rs == got.rs &&
          exp->opcode == got.opcode);
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
