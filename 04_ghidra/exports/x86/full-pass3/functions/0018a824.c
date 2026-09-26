/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018a824 */

void _fp_synch(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  undefined2 in_FPUControlWord;
  undefined2 in_FPUStatusWord;
  undefined2 in_FPUTagWord;
  undefined2 in_FPULastInstructionOpcode;
  undefined4 in_FPUDataPointer;
  undefined4 in_FPUInstructionPointer;
  unkbyte10 in_ST0;
  unkbyte10 in_ST1;
  unkbyte10 in_ST2;
  unkbyte10 in_ST3;
  unkbyte10 in_ST4;
  unkbyte10 in_ST5;
  unkbyte10 in_ST6;
  unkbyte10 in_ST7;
  
  if (DAT_001e75f8 == param_1) {
    if (param_1 != 0) {
      piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
      iVar3 = 0;
      if (piVar2 != (int *)0x0) {
        iVar3 = *piVar2;
      }
      if ((iVar3 == 0) || ((*(byte *)(iVar3 + 0x518) & 1) == 0)) {
        if ((_cpu_config & 3) == 2) {
          iVar3 = *(int *)(param_1 + 0x28);
          *(undefined2 *)(iVar3 + 0x7c) = in_FPUControlWord;
          *(undefined2 *)(iVar3 + 0x80) = in_FPUStatusWord;
          *(undefined2 *)(iVar3 + 0x84) = in_FPUTagWord;
          *(undefined4 *)(iVar3 + 0x90) = in_FPUDataPointer;
          *(undefined4 *)(iVar3 + 0x88) = in_FPUInstructionPointer;
          *(undefined2 *)(iVar3 + 0x8e) = in_FPULastInstructionOpcode;
          *(unkbyte10 *)(iVar3 + 0x98) = in_ST0;
          *(unkbyte10 *)(iVar3 + 0xa2) = in_ST1;
          *(unkbyte10 *)(iVar3 + 0xac) = in_ST2;
          *(unkbyte10 *)(iVar3 + 0xb6) = in_ST3;
          *(unkbyte10 *)(iVar3 + 0xc0) = in_ST4;
          *(unkbyte10 *)(iVar3 + 0xca) = in_ST5;
          *(unkbyte10 *)(iVar3 + 0xd4) = in_ST6;
          *(unkbyte10 *)(iVar3 + 0xde) = in_ST7;
        }
        pbVar1 = (byte *)(*(int *)(param_1 + 0x28) + 0xf0);
        *pbVar1 = *pbVar1 | 2;
      }
      else {
        if ((_cpu_config & 3) == 2) {
          *(undefined2 *)(iVar3 + 0x4ac) = in_FPUControlWord;
          *(undefined2 *)(iVar3 + 0x4b0) = in_FPUStatusWord;
          *(undefined2 *)(iVar3 + 0x4b4) = in_FPUTagWord;
          *(undefined4 *)(iVar3 + 0x4c0) = in_FPUDataPointer;
          *(undefined4 *)(iVar3 + 0x4b8) = in_FPUInstructionPointer;
          *(undefined2 *)(iVar3 + 0x4be) = in_FPULastInstructionOpcode;
          *(unkbyte10 *)(iVar3 + 0x4c8) = in_ST0;
          *(unkbyte10 *)(iVar3 + 0x4d2) = in_ST1;
          *(unkbyte10 *)(iVar3 + 0x4dc) = in_ST2;
          *(unkbyte10 *)(iVar3 + 0x4e6) = in_ST3;
          *(unkbyte10 *)(iVar3 + 0x4f0) = in_ST4;
          *(unkbyte10 *)(iVar3 + 0x4fa) = in_ST5;
          *(unkbyte10 *)(iVar3 + 0x504) = in_ST6;
          *(unkbyte10 *)(iVar3 + 0x50e) = in_ST7;
        }
        *(byte *)(iVar3 + 0x518) = *(byte *)(iVar3 + 0x518) | 2;
      }
      FUN_0018a7e4();
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 0x28);
    if ((*(byte *)(iVar3 + 0xf0) & 2) == 0) {
      *(undefined2 *)(iVar3 + 0x7c) = 0x27f;
      *(undefined2 *)(iVar3 + 0x80) = 0;
      *(undefined2 *)(iVar3 + 0x84) = 0xffff;
      *(undefined4 *)(iVar3 + 0x88) = 0;
      *(undefined2 *)(iVar3 + 0x8e) = 0;
      *(undefined2 *)(iVar3 + 0x8c) = 0;
      *(undefined4 *)(iVar3 + 0x90) = 0;
      *(undefined2 *)(iVar3 + 0x94) = 0;
    }
  }
  return;
}

