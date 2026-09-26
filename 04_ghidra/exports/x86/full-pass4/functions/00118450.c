/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00118450 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00118450(void)

{
  int iVar1;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar1 = **(int **)(unaff_ESI + 0xc);
  if (*(int *)(unaff_EBP + 0x18) == 0) {
    _sbappend(iVar1 + 0x24);
  }
  else {
    _sbappendrights(iVar1 + 0x24,*(undefined4 *)(unaff_EBP + 0x10));
  }
  *(short *)(unaff_EDI + 0x42) =
       *(short *)(unaff_EDI + 0x42) -
       (*(short *)(iVar1 + 0x28) - *(short *)(*(int *)(unaff_ESI + 0xc) + 0x20));
  *(uint *)(*(int *)(unaff_ESI + 0xc) + 0x20) = (uint)*(ushort *)(iVar1 + 0x28);
  *(short *)(unaff_EDI + 0x3e) =
       *(short *)(unaff_EDI + 0x3e) -
       (*(short *)(iVar1 + 0x24) - *(short *)(*(int *)(unaff_ESI + 0xc) + 0x1c));
  *(uint *)(*(int *)(unaff_ESI + 0xc) + 0x1c) = (uint)*(ushort *)(iVar1 + 0x24);
  _sowakeup(iVar1);
  *(undefined4 *)(unaff_EBP + 0x10) = 0;
  if (*(int *)(unaff_EBP + 0x10) != 0) {
    _m_freem();
  }
  return *(undefined4 *)(unaff_EBP + -0xc);
}

