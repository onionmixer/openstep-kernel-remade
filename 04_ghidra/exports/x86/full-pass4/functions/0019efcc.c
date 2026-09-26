/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019efcc */

undefined4 FUN_0019efcc(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  void *pvVar5;
  
  piVar1 = *(int **)(param_1 + 0x1c);
  if (*piVar1 == 3) {
    pvVar3 = (void *)piVar1[0x31];
    pvVar5 = (void *)piVar1[0x35];
    for (iVar4 = piVar1[0x32]; iVar4 != 0; iVar4 = iVar4 + -1) {
      _memmove(pvVar5,pvVar3,piVar1[0x33]);
      pvVar5 = (void *)((int)pvVar5 + piVar1[4]);
      pvVar3 = (void *)((int)pvVar3 + piVar1[0x33]);
    }
    _IOFree(piVar1[0x31],piVar1[0x34]);
    uVar2 = 0;
  }
  else {
    _IOLog(s_frameBuffer__bogus_restore__mode_001e4810,*piVar1);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

