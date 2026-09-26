
void _vik_mmu_getasyncflt
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = segment(4);
  param_1[1] = *(undefined4 *)(iVar1 + 0x400);
  iVar1 = segment(4);
  *param_1 = *(undefined4 *)(iVar1 + 0x300);
  uVar2 = 0xffffffff;
  if (_mod_info != 0x40) {
    iVar1 = segment(2);
    param_1[3] = *(undefined4 *)(iVar1 + 0x1c00e00);
    iVar1 = segment(2);
    *(undefined4 *)(iVar1 + 0x1c00e00) = 0xffffffff;
    uVar2 = param_4;
  }
  param_1[2] = uVar2;
  return;
}

