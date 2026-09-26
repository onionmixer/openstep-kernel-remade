/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119f62 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_00119f62(void)

{
  int iVar1;
  byte *unaff_EBX;
  int unaff_EBP;
  
  (**(code **)(*(int *)(*(int *)(unaff_EBX + 0x40) + 0x1c) + 0x54))();
  *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
  _biowait();
  if ((*unaff_EBX & 4) == 0) {
    _copy_to_phys(*(undefined4 *)(unaff_EBX + 0x20),
                  *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0x24));
    **(undefined4 **)(unaff_EBP + 0x24) = 0;
    _brelse();
    iVar1 = *(int *)(unaff_EBP + 0x14) - *(int *)(unaff_EBX + 0x28);
  }
  else {
    _brelse();
    **(int **)(unaff_EBP + 0x24) = (int)*(short *)(unaff_EBX + 0x1c);
    iVar1 = 0;
  }
  return iVar1;
}

