
void _vm_page_remove(int param_1)

{
  int *piVar1;
  sword *psVar2;
  int iVar3;
  
  if ((*(byte *)(param_1 + 0x20) & 0x20) != 0) {
    piVar1 = (int *)(_vm_page_buckets +
                    (_vm_page_hash_mask &
                    *(int *)(param_1 + 0x14) + (*(uint *)(param_1 + 0x18) >> (_page_shift & 0x3f)))
                    * 4);
    iVar3 = *piVar1;
    if (param_1 == iVar3) {
      *piVar1 = *(int *)(param_1 + 0x10);
    }
    else {
      do {
        piVar1 = (int *)(iVar3 + 0x10);
        iVar3 = *piVar1;
      } while (param_1 != iVar3);
      *piVar1 = *(int *)(iVar3 + 0x10);
    }
    iVar3 = *(int *)(param_1 + 8);
    piVar1 = *(int **)(param_1 + 0xc);
    if (iVar3 == *(int *)(param_1 + 0x14)) {
      *(int **)(iVar3 + 4) = piVar1;
    }
    else {
      *(int **)(iVar3 + 0xc) = piVar1;
    }
    if (piVar1 == *(int **)(param_1 + 0x14)) {
      *piVar1 = iVar3;
    }
    else {
      piVar1[2] = iVar3;
    }
    psVar2 = (sword *)(*(int *)(param_1 + 0x14) + 0x16);
    *psVar2 = *psVar2 + -1;
    *(byte *)(param_1 + 0x20) = *(byte *)(param_1 + 0x20) & 0xdf;
  }
  return;
}
