/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00121bb5 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00121bb5(void)

{
  int unaff_EBX;
  
  *(short *)(unaff_EBX + 0x26) = *(short *)(unaff_EBX + 0x26) + -1;
  if ((*(uint *)(unaff_EBX + 0x24) & 0xffff0001) == 0) {
    __rttrash = __rttrash + -1;
    _m_free();
  }
  return;
}

