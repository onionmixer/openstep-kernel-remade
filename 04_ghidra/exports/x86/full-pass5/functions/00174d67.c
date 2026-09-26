/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00174d67 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00174d67(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_EBX;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  unaff_EBX[2] = *(int *)(unaff_EBP + -0x14);
  unaff_EBX[3] = *(int *)(unaff_EBP + -0xc);
  *(byte *)(unaff_EBX + 6) = *(byte *)(unaff_EBX + 6) & 0xfa;
  unaff_EBX[4] = *(int *)(unaff_EBP + 0xc);
  unaff_EBX[5] = *(int *)(unaff_EBP + 0x10);
  *(byte *)(unaff_EBX + 6) = *(byte *)(unaff_EBX + 6) & 0xb7;
  if (*(int *)(*(int *)(unaff_EBP + 8) + 0x2c) != 0) {
    unaff_EBX[9] = 1;
    unaff_EBX[7] = 3;
    unaff_EBX[8] = 7;
    *(undefined2 *)(unaff_EBX + 10) = 0;
  }
  iVar2 = *(int *)(unaff_EBP + 8);
  *(int *)(iVar2 + 0x1c) = *(int *)(iVar2 + 0x1c) + 1;
  *unaff_EBX = iVar1;
  unaff_EBX[1] = *(int *)(iVar1 + 4);
  iVar3 = *unaff_EBX;
  *(int **)unaff_EBX[1] = unaff_EBX;
  *(int **)(iVar3 + 4) = unaff_EBX;
  *(int *)(iVar2 + 0x28) = *(int *)(iVar2 + 0x28) + (unaff_EBX[3] - unaff_EBX[2]);
  if ((*(int *)(iVar2 + 0x40) == iVar1) && ((uint)unaff_EBX[2] <= *(uint *)(iVar1 + 0xc))) {
    *(int **)(iVar2 + 0x40) = unaff_EBX;
  }
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  _lock_done();
  return *(undefined4 *)(unaff_EBP + -0x10);
}

