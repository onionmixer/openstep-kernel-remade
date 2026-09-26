/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011c066 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011c066(void)

{
  uint *puVar1;
  short sVar2;
  int unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  uint unaff_EDI;
  
  sVar2 = *(short *)(unaff_EBX + 8);
  *(short *)(unaff_EBX + 8) = sVar2 + -1;
  if ((sVar2 == 1) &&
     (*(byte *)(unaff_EBX + 4) = *(byte *)(unaff_EBX + 4) & 0xf7, (unaff_EDI & 0x10) != 0)) {
    _wakeup();
  }
  puVar1 = (uint *)(*(int *)(unaff_EBP + 8) + 8);
  *puVar1 = *puVar1 & 0xffffff7f;
  if ((unaff_ESI & 0x100) != 0) {
    if ((unaff_EDI & 4) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vno_bsd_unlock__EXLOCK_001db744);
    }
    sVar2 = *(short *)(unaff_EBX + 10);
    *(short *)(unaff_EBX + 10) = sVar2 + -1;
    if ((sVar2 == 1) &&
       (*(byte *)(unaff_EBX + 4) = *(byte *)(unaff_EBX + 4) & 0xeb, (unaff_EDI & 0x10) != 0)) {
      _wakeup();
    }
    puVar1 = (uint *)(*(int *)(unaff_EBP + 8) + 8);
    *puVar1 = *puVar1 & 0xfffffeff;
  }
  return;
}

