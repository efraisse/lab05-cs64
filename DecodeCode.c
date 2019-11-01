#include "DecodeCode.h"

mipsinstruction decode(int value)
{
	mipsinstruction instr;

	// TODO: fill in the fields
	instr.funct = 0b111111;
	instr.immediate = 0b10000000000000001111111111111111;
	instr.rd = 0b000000000000000001111100000000000;
	instr.rt = 0b00000000000111110000000000000000;
	instr.rs = 0b00000011111000000000000000000000;
	instr.opcode = 0b11111100000000000000000000000000;

	return instr;
}


