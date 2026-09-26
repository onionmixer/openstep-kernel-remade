/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001182d1 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001182d1(void)

{
  int iVar1;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  if (*(int **)(unaff_ESI + 0xc) != (int *)0x0) {
    iVar1 = **(int **)(unaff_ESI + 0xc);
    *(short *)(iVar1 + 0x42) =
         *(short *)(iVar1 + 0x42) + (*(short *)(unaff_ESI + 0x20) - *(short *)(unaff_EDI + 0x28));
    *(uint *)(unaff_ESI + 0x20) = (uint)*(ushort *)(unaff_EDI + 0x28);
    *(short *)(iVar1 + 0x3e) =
         *(short *)(iVar1 + 0x3e) + (*(short *)(unaff_ESI + 0x1c) - *(short *)(unaff_EDI + 0x24));
    *(uint *)(unaff_ESI + 0x1c) = (uint)*(ushort *)(unaff_EDI + 0x24);
    _sowakeup(iVar1);
  }
  if (*(int *)(unaff_EBP + 0x10) != 0) {
    _m_freem();
  }
  return *(undefined4 *)(unaff_EBP + -0xc);
}

