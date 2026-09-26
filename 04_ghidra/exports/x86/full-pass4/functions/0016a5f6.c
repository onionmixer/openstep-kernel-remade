/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016a5f6 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0016a5f6(void)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  
  uVar2 = unaff_EBX[7];
  if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
    iVar4 = _splhigh();
    do {
      do {
      } while (*unaff_EBX != 0);
      LOCK();
      iVar1 = *unaff_EBX;
      *unaff_EBX = 1;
      UNLOCK();
    } while (iVar1 == 1);
    unaff_EBX[1] = iVar4;
  }
  else {
    _lock_write();
  }
  do {
    if (*(uint *)(unaff_EBP + 0x10) < uVar2) {
      if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
        LOCK();
        *unaff_EBX = 0;
        UNLOCK();
        _splx();
      }
      else {
        _lock_done();
      }
      return;
    }
    piVar3 = (int *)unaff_EBX[3];
    if ((piVar3 == (int *)0x0) || (unaff_ESI <= piVar3)) {
      piVar3 = unaff_EBX + 4;
    }
    do {
      piVar5 = piVar3;
      piVar3 = (int *)*piVar5;
      if (piVar3 == (int *)0x0) break;
    } while (piVar3 < unaff_ESI);
    *unaff_ESI = (int)piVar3;
    *piVar5 = (int)unaff_ESI;
    unaff_EBX[3] = (int)unaff_ESI;
    unaff_EBX[2] = unaff_EBX[2];
    *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) - uVar2;
    unaff_ESI = (int *)((int)unaff_ESI + uVar2);
    unaff_EBX[5] = unaff_EBX[5] + uVar2;
  } while( true );
}

