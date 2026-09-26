/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a0d5 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0011a0d5(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_EBP;
  
  (**(code **)(*(int *)(*(int *)(unaff_EBX + 0x40) + 0x1c) + 0x54))();
  *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
  _biowait();
  if ((*(byte *)(unaff_EBP + -0x44) & 4) == 0) {
    *(undefined4 *)(*(int *)(unaff_EBP + -0x3c) + 4) = *(undefined4 *)(unaff_EBP + -0x40);
    *(undefined4 *)(*(int *)(unaff_EBP + -0x40) + 8) = *(undefined4 *)(unaff_EBP + -0x3c);
    FUN_0011b26c();
    **(undefined4 **)(unaff_EBP + 0x24) = 0;
    iVar1 = *(int *)(unaff_EBP + 0x14) - *(int *)(unaff_EBP + -0x1c);
  }
  else {
    **(int **)(unaff_EBP + 0x24) = (int)*(short *)(unaff_EBP + -0x28);
    *(int *)(unaff_EBP + 0x18) = *(int *)(unaff_EBP + 0x14) - *(int *)(unaff_EBP + -0x1c);
    *(undefined4 *)(*(int *)(unaff_EBP + -0x3c) + 4) = *(undefined4 *)(unaff_EBP + -0x40);
    *(undefined4 *)(*(int *)(unaff_EBP + -0x40) + 8) = *(undefined4 *)(unaff_EBP + -0x3c);
    FUN_0011b26c();
    iVar1 = *(int *)(unaff_EBP + 0x18);
  }
  return iVar1;
}

