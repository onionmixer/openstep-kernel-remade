/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00143965 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00143965(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 4) = *(undefined4 *)(unaff_EBX + 0x34);
  *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(unaff_EBX + 0x28);
  iVar1 = *(int *)(unaff_EBX + 0xc4) * *(int *)(unaff_EBX + 0x38) + *(int *)(unaff_EBX + 0xcc);
  *(int *)(unaff_EBP + -8) = iVar1;
  *(int *)(unaff_ESI + 0xc) = iVar1;
  *(int *)(unaff_ESI + 0x10) =
       ((100 - *(int *)(unaff_EBX + 0x3c)) * *(int *)(unaff_EBX + 0x28)) / 100 -
       (*(int *)(unaff_EBX + 0x28) - *(int *)(unaff_EBP + -8));
  *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_EBX + 0x2c) * *(int *)(unaff_EBX + 0xb8);
  *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(unaff_EBX + 200);
  *(void **)(unaff_EBP + -0xc) = (void *)(unaff_ESI + 0x1c);
  _bcopy((void *)(*(int *)(unaff_EBP + 8) + 0x14),(void *)(unaff_ESI + 0x1c),8);
  return 0;
}

