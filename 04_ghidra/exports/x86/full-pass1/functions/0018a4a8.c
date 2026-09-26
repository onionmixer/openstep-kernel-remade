/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018a4a8 */

void FUN_0018a4a8(void)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
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
  
  iVar4 = _active_threads;
  iVar5 = DAT_001e75f8;
  if (_active_threads == DAT_001e75f8) {
    piVar2 = *(int **)(*(int *)(_active_threads + 0x28) + 0xec);
    iVar5 = 0;
    if (piVar2 != (int *)0x0) {
      iVar5 = *piVar2;
    }
    if (iVar5 == 0) {
      return;
    }
    if (*(uint *)(iVar5 + 0x84) < 8) {
      iVar3 = iVar5 + 0x88 + *(uint *)(iVar5 + 0x84) * 0x84;
    }
    else {
      iVar3 = 0;
    }
    if (*(int *)(iVar3 + 0x48) == 0) {
      if ((*(byte *)(iVar5 + 0x518) & 1) == 0) {
        return;
      }
      if ((_cpu_config & 3) == 2) {
        *(undefined2 *)(iVar5 + 0x4ac) = in_FPUControlWord;
        *(undefined2 *)(iVar5 + 0x4b0) = in_FPUStatusWord;
        *(undefined2 *)(iVar5 + 0x4b4) = in_FPUTagWord;
        *(undefined4 *)(iVar5 + 0x4c0) = in_FPUDataPointer;
        *(undefined4 *)(iVar5 + 0x4b8) = in_FPUInstructionPointer;
        *(undefined2 *)(iVar5 + 0x4be) = in_FPULastInstructionOpcode;
        *(unkbyte10 *)(iVar5 + 0x4c8) = in_ST0;
        *(unkbyte10 *)(iVar5 + 0x4d2) = in_ST1;
        *(unkbyte10 *)(iVar5 + 0x4dc) = in_ST2;
        *(unkbyte10 *)(iVar5 + 0x4e6) = in_ST3;
        *(unkbyte10 *)(iVar5 + 0x4f0) = in_ST4;
        *(unkbyte10 *)(iVar5 + 0x4fa) = in_ST5;
        *(unkbyte10 *)(iVar5 + 0x504) = in_ST6;
        *(unkbyte10 *)(iVar5 + 0x50e) = in_ST7;
      }
      *(byte *)(iVar5 + 0x518) = *(byte *)(iVar5 + 0x518) | 2;
      iVar4 = *(int *)(iVar4 + 0x28);
      if ((*(byte *)(iVar4 + 0xf0) & 2) == 0) {
        *(undefined2 *)(iVar4 + 0x7c) = 0x27f;
        *(undefined2 *)(iVar4 + 0x80) = 0;
        *(undefined2 *)(iVar4 + 0x84) = 0xffff;
        *(undefined4 *)(iVar4 + 0x88) = 0;
        *(undefined2 *)(iVar4 + 0x8e) = 0;
        *(undefined2 *)(iVar4 + 0x8c) = 0;
        *(undefined4 *)(iVar4 + 0x90) = 0;
        *(undefined2 *)(iVar4 + 0x94) = 0;
      }
      else {
        *(byte *)(iVar4 + 0xf0) = *(byte *)(iVar4 + 0xf0) & 0xfd;
      }
      *(byte *)(iVar5 + 0x518) = *(byte *)(iVar5 + 0x518) & 0xfe;
      return;
    }
    if ((*(byte *)(iVar5 + 0x518) & 1) != 0) {
      return;
    }
    if ((_cpu_config & 3) == 2) {
      iVar3 = *(int *)(_active_threads + 0x28);
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
    pbVar1 = (byte *)(*(int *)(iVar4 + 0x28) + 0xf0);
    *pbVar1 = *pbVar1 | 2;
LAB_0018a6b0:
    if ((*(byte *)(iVar5 + 0x518) & 2) == 0) {
      *(undefined2 *)(iVar5 + 0x4ac) = 0x37f;
      *(undefined2 *)(iVar5 + 0x4b0) = 0;
      *(undefined2 *)(iVar5 + 0x4b4) = 0xffff;
      *(undefined4 *)(iVar5 + 0x4b8) = 0;
      *(undefined2 *)(iVar5 + 0x4be) = 0;
      *(undefined2 *)(iVar5 + 0x4bc) = 0;
      *(undefined4 *)(iVar5 + 0x4c0) = 0;
      *(undefined2 *)(iVar5 + 0x4c4) = 0;
    }
    else {
      *(byte *)(iVar5 + 0x518) = *(byte *)(iVar5 + 0x518) & 0xfd;
    }
    *(byte *)(iVar5 + 0x518) = *(byte *)(iVar5 + 0x518) | 1;
  }
  else {
    if (DAT_001e75f8 != 0) {
      piVar2 = *(int **)(*(int *)(DAT_001e75f8 + 0x28) + 0xec);
      iVar3 = 0;
      if (piVar2 != (int *)0x0) {
        iVar3 = *piVar2;
      }
      if ((iVar3 == 0) || ((*(byte *)(iVar3 + 0x518) & 1) == 0)) {
        if ((_cpu_config & 3) == 2) {
          iVar3 = *(int *)(DAT_001e75f8 + 0x28);
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
        pbVar1 = (byte *)(*(int *)(iVar5 + 0x28) + 0xf0);
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
    iVar3 = _active_threads;
    DAT_001e75f8 = iVar4;
    piVar2 = *(int **)(*(int *)(_active_threads + 0x28) + 0xec);
    iVar5 = 0;
    if (piVar2 != (int *)0x0) {
      iVar5 = *piVar2;
    }
    if (iVar5 != 0) {
      if (*(uint *)(iVar5 + 0x84) < 8) {
        iVar4 = iVar5 + 0x88 + *(uint *)(iVar5 + 0x84) * 0x84;
      }
      else {
        iVar4 = 0;
      }
      if (*(int *)(iVar4 + 0x48) != 0) goto LAB_0018a6b0;
      *(byte *)(iVar5 + 0x518) = *(byte *)(iVar5 + 0x518) & 0xfe;
    }
    iVar5 = *(int *)(iVar3 + 0x28);
    if ((*(byte *)(iVar5 + 0xf0) & 2) == 0) {
      *(undefined2 *)(iVar5 + 0x7c) = 0x27f;
      *(undefined2 *)(iVar5 + 0x80) = 0;
      *(undefined2 *)(iVar5 + 0x84) = 0xffff;
      *(undefined4 *)(iVar5 + 0x88) = 0;
      *(undefined2 *)(iVar5 + 0x8e) = 0;
      *(undefined2 *)(iVar5 + 0x8c) = 0;
      *(undefined4 *)(iVar5 + 0x90) = 0;
      *(undefined2 *)(iVar5 + 0x94) = 0;
    }
    else {
      *(byte *)(iVar5 + 0xf0) = *(byte *)(iVar5 + 0xf0) & 0xfd;
    }
  }
  return;
}

