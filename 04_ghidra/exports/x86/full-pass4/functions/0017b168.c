/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017b168 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0017b168(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint unaff_EBX;
  int unaff_EBP;
  
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(unaff_EBP + 0xc);
  *(uint *)(iVar2 + 0x18) = unaff_EBX;
  piVar1 = (int *)(_vm_page_buckets +
                  ((unaff_EBX >> ((byte)_page_shift & 0x1f)) + *(int *)(unaff_EBP + 0xc) &
                  __vm_page_hash_mask) * 8);
  _splimp();
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  iVar2 = *(int *)(unaff_EBP + 8);
  *(int *)(iVar2 + 0x10) = piVar1[1];
  piVar1[1] = iVar2;
  LOCK();
  *piVar1 = 0;
  UNLOCK();
  _splx();
  puVar3 = *(undefined4 **)(unaff_EBP + 0xc);
  puVar4 = (undefined4 *)puVar3[1];
  if (puVar3 == puVar4) {
    *puVar3 = *(undefined4 *)(unaff_EBP + 8);
  }
  else {
    puVar4[2] = *(undefined4 *)(unaff_EBP + 8);
  }
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined4 **)(iVar2 + 0xc) = puVar4;
  iVar5 = *(int *)(unaff_EBP + 0xc);
  *(int *)(iVar2 + 8) = iVar5;
  *(int *)(iVar5 + 4) = iVar2;
  *(byte *)(iVar2 + 0x20) = *(byte *)(iVar2 + 0x20) | 4;
  *(short *)(iVar5 + 0x1a) = *(short *)(iVar5 + 0x1a) + 1;
  return;
}

