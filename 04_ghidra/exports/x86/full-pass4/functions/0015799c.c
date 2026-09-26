/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015799c */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0015799c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int unaff_EBP;
  uint *unaff_ESI;
  uint unaff_EDI;
  
  iVar1 = _kalloc();
  *(int *)(unaff_EBP + -4) = iVar1;
  if (iVar1 == 0) {
    uVar2 = 6;
  }
  else {
    puVar3 = *(undefined4 **)(unaff_EBP + -4);
    iVar1 = 0;
    *(undefined4 *)(unaff_EBP + -8) = 0;
    do {
      if (*(int *)((int)&_machine_slot + *(int *)(unaff_EBP + -8)) != 0) {
        *puVar3 = (&_processor_ptr)[iVar1];
        puVar3 = puVar3 + 1;
      }
      *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) + 0x20;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 1);
    *unaff_ESI = unaff_EDI;
    **(undefined4 **)(unaff_EBP + 0xc) = *(undefined4 *)(unaff_EBP + -4);
    puVar3 = *(undefined4 **)(unaff_EBP + -4);
    uVar4 = 0;
    if (unaff_EDI != 0) {
      do {
        uVar2 = _convert_processor_to_port();
        *puVar3 = uVar2;
        puVar3 = puVar3 + 1;
        uVar4 = uVar4 + 1;
      } while (uVar4 < unaff_EDI);
    }
    uVar2 = 0;
  }
  return uVar2;
}

