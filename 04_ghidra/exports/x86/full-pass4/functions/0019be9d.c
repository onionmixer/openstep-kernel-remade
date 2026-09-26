/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019be9d */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019be9d(void)

{
  int *piVar1;
  byte bVar2;
  undefined2 *puVar3;
  int unaff_EBP;
  int iVar4;
  
  puVar3 = *(undefined2 **)(unaff_EBP + -0x10);
  iVar4 = 0xc;
  do {
    bVar2 = **(byte **)(unaff_EBP + -8);
    *(byte **)(unaff_EBP + -8) = *(byte **)(unaff_EBP + -8) + 1;
    if ((char)bVar2 < '\0') {
      *puVar3 = *(undefined2 *)(unaff_EBP + -0xc);
    }
    if ((bVar2 & 0x40) != 0) {
      puVar3[1] = *(undefined2 *)(unaff_EBP + -0xc);
    }
    if ((bVar2 & 0x20) != 0) {
      puVar3[2] = *(undefined2 *)(unaff_EBP + -0xc);
    }
    if ((bVar2 & 0x10) != 0) {
      puVar3[3] = *(undefined2 *)(unaff_EBP + -0xc);
    }
    if ((bVar2 & 8) != 0) {
      puVar3[4] = *(undefined2 *)(unaff_EBP + -0xc);
    }
    if ((bVar2 & 4) != 0) {
      puVar3[5] = *(undefined2 *)(unaff_EBP + -0xc);
    }
    if ((bVar2 & 2) != 0) {
      puVar3[6] = *(undefined2 *)(unaff_EBP + -0xc);
    }
    if ((bVar2 & 1) != 0) {
      puVar3[7] = *(undefined2 *)(unaff_EBP + -0xc);
    }
    puVar3 = (undefined2 *)((int)puVar3 + *(int *)(*(int *)(unaff_EBP + 8) + 0x10));
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  piVar1 = (int *)(*(int *)(unaff_EBP + 8) + 0xa8);
  *piVar1 = *piVar1 + 1;
  return;
}

