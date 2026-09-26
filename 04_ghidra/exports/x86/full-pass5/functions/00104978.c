/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00104978 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00104978(void)

{
  int unaff_EBX;
  
  if (*(int *)(unaff_EBX + 0x14) != 0) {
    (**(code **)(*(int *)(unaff_EBX + 0x14) + 0xc))();
  }
  _crfree();
  if (*(short *)(unaff_EBX + 0xe) != 1) {
                    /* WARNING: Subroutine does not return */
    _panic(s_fp_not_one2_001da675);
  }
  *(undefined2 *)(unaff_EBX + 0xe) = 0;
  _free_file();
  return;
}

