/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012fced */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0012fced(void)

{
  ushort uVar1;
  int unaff_EBX;
  
  if (*(short *)(unaff_EBX + 0x6c) == 0) {
    uVar1 = *(ushort *)(unaff_EBX + 0x60);
    *(ushort *)(unaff_EBX + 0x60) = uVar1 & 0xffde;
    if ((uVar1 & 2) != 0) {
      *(ushort *)(unaff_EBX + 0x60) = uVar1 & 0xffdc;
      _wakeup();
    }
  }
  return;
}

