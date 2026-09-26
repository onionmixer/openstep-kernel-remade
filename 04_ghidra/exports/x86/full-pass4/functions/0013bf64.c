/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013bf64 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0013bf64(void)

{
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int iStack00000008;
  undefined4 uStack0000000c;
  int iStack00000010;
  
  iStack00000010 = *(int *)(unaff_EBX + 0xcc);
  if (iStack00000010 != 0) {
    uStack0000000c = *(undefined4 *)(unaff_EBP + -4);
    iStack00000008 = unaff_ESI + 0xd4;
    _printf(s_free_inode__s__d_had__d_blocks_001ddb5e);
    *(undefined4 *)(unaff_EBX + 0xcc) = 0;
  }
  *(undefined4 *)(unaff_EBX + 200) = 0;
  return;
}

