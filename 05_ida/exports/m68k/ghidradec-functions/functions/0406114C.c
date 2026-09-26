
byte _vm_page_insert(int param_1,int *param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  
  if ((*(byte *)(param_1 + 0x20) & 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmPageInsert);
  }
  *(int **)(param_1 + 0x14) = param_2;
  *(uint *)(param_1 + 0x18) = param_3;
  param_3 = param_3 >> (_page_shift & 0x3f);
  uVar2 = _vm_page_hash_mask & (int)param_2 + param_3;
  piVar1 = (int *)(_vm_page_buckets + uVar2 * 4);
  *(int *)(param_1 + 0x10) = *piVar1;
  *piVar1 = param_1;
  piVar1 = (int *)param_2[1];
  if (piVar1 == param_2) {
    *param_2 = param_1;
  }
  else {
    piVar1[2] = param_1;
  }
  *(int **)(param_1 + 0xc) = piVar1;
  *(int **)(param_1 + 8) = param_2;
  param_2[1] = param_1;
  *(byte *)(param_1 + 0x20) = *(byte *)(param_1 + 0x20) | 0x20;
  *(sword *)((int)param_2 + 0x16) = *(sword *)((int)param_2 + 0x16) + 1;
  return CARRY4((uint)param_2,param_3) << 4 | ((int)uVar2 < 0) << 3 | (uVar2 == 0) << 2;
}
