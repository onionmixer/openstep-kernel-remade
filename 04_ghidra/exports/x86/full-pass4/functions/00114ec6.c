/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114ec6 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00114ec6(void)

{
  uint unaff_EBX;
  
  *(undefined4 *)(unaff_EBX + 0x10) = 0;
  _sbrelease();
  _sorflush();
  _m_free(unaff_EBX & 0xffffff80);
  _splx();
  return;
}

