/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00162f4e */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00162f4e(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *unaff_EBX;
  int unaff_EBP;
  uint unaff_EDI;
  undefined4 uStack00000008;
  
  uStack00000008 = 0x162f56;
  uVar4 = _splsched();
  *(undefined4 *)(unaff_EBP + -4) = uVar4;
  if (unaff_EDI == 0) {
    piVar1 = unaff_EBX + 8;
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if (*(int *)(unaff_EBP + 0xc) == 0) {
      *(byte *)(unaff_EBX + 0x13) = *(byte *)(unaff_EBX + 0x13) | 9;
    }
    else {
      *(byte *)(unaff_EBX + 0x13) = *(byte *)(unaff_EBX + 0x13) | 1;
    }
    LOCK();
    unaff_EBX[8] = 0;
    UNLOCK();
  }
  else {
    uVar3 = unaff_EDI;
    if ((int)unaff_EDI < 0) {
      uVar3 = ~unaff_EDI;
    }
    *(undefined4 **)(unaff_EBP + -8) = &_wait_queue + ((int)uVar3 % 0x3b) * 2;
    *(undefined4 **)(unaff_EBP + -0xc) = &_wait_lock + (int)uVar3 % 0x3b;
    do {
      do {
      } while (**(int **)(unaff_EBP + -0xc) != 0);
      LOCK();
      iVar2 = **(int **)(unaff_EBP + -0xc);
      **(int **)(unaff_EBP + -0xc) = 1;
      UNLOCK();
    } while (iVar2 == 1);
    piVar1 = unaff_EBX + 8;
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    iVar2 = *(int *)(unaff_EBP + -8);
    *unaff_EBX = iVar2;
    unaff_EBX[1] = *(int *)(iVar2 + 4);
    *(int **)unaff_EBX[1] = unaff_EBX;
    *(int **)(iVar2 + 4) = unaff_EBX;
    unaff_EBX[0xf] = unaff_EDI;
    if (*(int *)(unaff_EBP + 0xc) == 0) {
      *(byte *)(unaff_EBX + 0x13) = *(byte *)(unaff_EBX + 0x13) | 9;
    }
    else {
      *(byte *)(unaff_EBX + 0x13) = *(byte *)(unaff_EBX + 0x13) | 1;
    }
    LOCK();
    unaff_EBX[8] = 0;
    UNLOCK();
    LOCK();
    **(undefined4 **)(unaff_EBP + -0xc) = 0;
    UNLOCK();
  }
  uStack00000008 = *(undefined4 *)(unaff_EBP + -4);
  _splx();
  return;
}

