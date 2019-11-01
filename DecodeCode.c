#include "DecodeCode.h"

mipsinstruction decode(int value)
{
	mipsinstruction instr;

	// TODO: fill in the fields
	instr.funct = (value & 0b111111) >> 0;
	instr.immediate = (value & 0b1111111111111111) >> 0;
	instr.rd = (value & 0b1111100000000000) >> 11;
	instr.rt = (value & 0b111110000000000000000) >> 16;
	instr.rs = (value & 0b11111000000000000000000000) >> 21;
	instr.opcode = (value & 0b11111100000000000000000000000000) >> 26;

	return instr;
}


