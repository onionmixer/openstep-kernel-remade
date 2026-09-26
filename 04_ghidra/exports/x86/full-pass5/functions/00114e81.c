/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114e81 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00114e81(void)

{
  int iVar1;
  uint unaff_EBX;
  
  *(ushort *)(unaff_EBX + 6) = *(ushort *)(unaff_EBX + 6) | 1;
  if (*(int *)(unaff_EBX + 8) == 0) {
    if (*(int *)(unaff_EBX + 0x10) != 0) {
      iVar1 = _soqremque();
      if ((iVar1 == 0) && (iVar1 = _soqremque(), iVar1 == 0)) {
                    /* WARNING: Subroutine does not return */
        _panic(s_sofree_dq_001db2dd);
      }
      *(undefined4 *)(unaff_EBX + 0x10) = 0;
    }
    _sbrelease();
    _sorflush();
    _m_free(unaff_EBX & 0xffffff80);
  }
  _splx();
  return;
}

