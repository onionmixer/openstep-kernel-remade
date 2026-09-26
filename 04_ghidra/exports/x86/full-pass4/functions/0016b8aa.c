/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016b8aa */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0016b8aa(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *unaff_EBX;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  while (unaff_EBX = (undefined4 *)*unaff_EBX, unaff_EBX != (undefined4 *)0x0) {
    if (unaff_EBX == unaff_EDI) {
                    /* WARNING: Subroutine does not return */
      _panic(s_zfree_001dfd7c);
    }
  }
  puVar1 = (undefined4 *)unaff_ESI[3];
  if ((puVar1 == (undefined4 *)0x0) || (unaff_EDI <= puVar1)) {
    puVar1 = unaff_ESI + 4;
  }
  do {
    puVar2 = puVar1;
    puVar1 = (undefined4 *)*puVar2;
    if (puVar1 == (undefined4 *)0x0) break;
  } while (puVar1 < unaff_EDI);
  *unaff_EDI = puVar1;
  *puVar2 = unaff_EDI;
  unaff_ESI[3] = unaff_EDI;
  unaff_ESI[2] = unaff_ESI[2] + -1;
  if ((*(byte *)(unaff_ESI + 0xb) & 1) == 0) {
    LOCK();
    *unaff_ESI = 0;
    UNLOCK();
    _splx();
  }
  else {
    _lock_done();
  }
  return;
}

