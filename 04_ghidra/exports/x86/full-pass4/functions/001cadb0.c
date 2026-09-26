/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cadb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001cadb0(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *unaff_EBX;
  uint uVar3;
  int unaff_EBP;
  int unaff_EDI;
  int iVar4;
  
  while( true ) {
    piVar2 = (int *)*unaff_EBX;
    if (piVar2 == (int *)0x0) {
      if (__NXUncaughtExceptionHandler != (code *)0x0) {
        (*__NXUncaughtExceptionHandler)(*(undefined4 *)(unaff_EBP + 8));
      }
                    /* WARNING: Subroutine does not return */
      _panic("Uncaught exception");
    }
    if (((uint)piVar2 & 1) == 0) break;
    piVar2 = (int *)((((int)piVar2 + -1) / 2) * 0xc + unaff_EBX[1]);
    *unaff_EBX = *piVar2;
    unaff_EBX[3] = ((int)piVar2 - unaff_EBX[1]) * -0x55555555 >> 2;
    (*(code *)piVar2[1])(piVar2[2],*(undefined4 *)(unaff_EBP + 8));
  }
  piVar2[0x13] = *(int *)(unaff_EBP + 8);
  piVar2[0x14] = unaff_EDI;
  piVar2[0x15] = *(int *)(unaff_EBP + 0x10);
  *unaff_EBX = piVar2[0x12];
  iVar4 = 1;
  _jump_label(piVar2,1);
  do {
  } while (DAT_001e5540 != 0);
  LOCK();
  DAT_001e5540 = 1;
  UNLOCK();
  uVar3 = iVar4 + _DAT_001e553c + 7 & 0xfffffff8;
  if ((int)DAT_001e5454 < (int)uVar3) {
    DAT_001e5538 = _realloc(DAT_001e5538,uVar3);
    DAT_001e5454 = uVar3;
  }
  *param_1 = (int)DAT_001e5538 + _DAT_001e553c;
  uVar1 = DAT_001e5540;
  _DAT_001e553c = uVar3;
  LOCK();
  DAT_001e5540 = 0;
  UNLOCK();
  return uVar1;
}

