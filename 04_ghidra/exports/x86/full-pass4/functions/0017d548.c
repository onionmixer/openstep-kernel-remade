/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017d548 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

bool __analysis_fragment_0017d548(void)

{
  int iVar1;
  int unaff_EBX;
  
  if ((*(byte *)(unaff_EBX + 0xc) & 1) != 0) {
    iVar1 = FUN_0017cd58();
    return iVar1 != 5;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_vnode_has_page_called_on_non_def_001e0ec0);
}

