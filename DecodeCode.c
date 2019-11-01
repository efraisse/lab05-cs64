#include "DecodeCode.h"

mipsinstruction decode(int value)
{
	mipsinstruction instr;

	// TODO: fill in the fields
	instr.funct = (value & 0b111111);
	instr.immediate = (value & 0b1111111111111111);
	instr.rd = (value & 0b000000000000000001111100000000000);
	instr.rt = (value & 0b00000000000111110000000000000000);
	instr.rs = (value & 0b00000011111000000000000000000000);
	instr.opcode = (value & 0b11111100000000000000000000000000);

	return instr;
}


