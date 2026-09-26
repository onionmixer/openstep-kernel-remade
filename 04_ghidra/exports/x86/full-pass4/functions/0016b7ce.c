/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016b7ce */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int * __analysis_fragment_0016b7ce(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *unaff_EBX;
  
  if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
    iVar3 = _splhigh();
    do {
      do {
      } while (*unaff_EBX != 0);
      LOCK();
      iVar1 = *unaff_EBX;
      *unaff_EBX = 1;
      UNLOCK();
    } while (iVar1 == 1);
    unaff_EBX[1] = iVar3;
  }
  else {
    _lock_write();
  }
  piVar2 = (int *)unaff_EBX[4];
  if (piVar2 != (int *)0x0) {
    unaff_EBX[2] = unaff_EBX[2] + 1;
    unaff_EBX[4] = *piVar2;
    if ((int *)unaff_EBX[3] == piVar2) {
      unaff_EBX[3] = 0;
    }
  }
  if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
    LOCK();
    *unaff_EBX = 0;
    UNLOCK();
    _splx();
  }
  else {
    _lock_done();
  }
  return piVar2;
}

