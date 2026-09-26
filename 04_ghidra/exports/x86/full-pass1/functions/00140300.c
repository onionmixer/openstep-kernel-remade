/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00140300 */

undefined4 _disksort_first(int param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (DAT_001f50ec == 0) {
    if ((*(byte *)(param_1 + 0xc) & 1) != 0) {
      iVar2 = (*DAT_001f50dc)(param_1);
      if (iVar2 == 0) {
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xfe;
        pcVar3 = DAT_001f50e8;
        goto LAB_0014034f;
      }
      goto LAB_00140354;
    }
LAB_00140364:
    uVar5 = _splbio();
    piVar1 = (int *)(param_1 + 0x24);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if ((undefined4 *)(param_1 + 0x10) == *(undefined4 **)(param_1 + 0x10)) {
      LOCK();
      *(undefined4 *)(param_1 + 0x24) = 0;
      UNLOCK();
      _splx(uVar5);
      uVar4 = 0;
    }
    else {
      uVar4 = **(undefined4 **)(param_1 + 0x10);
      LOCK();
      *(undefined4 *)(param_1 + 0x24) = 0;
      UNLOCK();
      _splx(uVar5);
    }
  }
  else {
    if ((*(byte *)(param_1 + 0xc) & 1) == 0) {
      if (*(int *)(param_1 + 0x10) == param_1 + 0x10) {
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 1;
        pcVar3 = DAT_001f50e4;
LAB_0014034f:
        (*pcVar3)(param_1);
      }
LAB_00140354:
      if ((*(byte *)(param_1 + 0xc) & 1) == 0) goto LAB_00140364;
    }
    uVar4 = (*DAT_001f50dc)(param_1);
  }
  return uVar4;
}

