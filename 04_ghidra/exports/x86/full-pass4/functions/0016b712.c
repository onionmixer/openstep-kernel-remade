/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016b712 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0016b712(void)

{
  int iVar1;
  int iVar2;
  int *unaff_EBX;
  int unaff_EBP;
  
  if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
    iVar2 = _splhigh();
    do {
      do {
      } while (*unaff_EBX != 0);
      LOCK();
      iVar1 = *unaff_EBX;
      *unaff_EBX = 1;
      UNLOCK();
    } while (iVar1 == 1);
    unaff_EBX[1] = iVar2;
  }
  else {
    _lock_write();
  }
  unaff_EBX[2] = unaff_EBX[2] + 1;
  unaff_EBX[5] = unaff_EBX[5] + unaff_EBX[7];
  if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
    LOCK();
    *unaff_EBX = 0;
    UNLOCK();
    _splx();
  }
  else {
    _lock_done();
  }
  return *(undefined4 *)(unaff_EBP + -4);
}

