
undefined4 _xxx_slot_info(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 < 0) || (0 < param_2)) {
    uVar2 = 4;
  }
  else {
    iVar1 = param_2 * 0x20;
    *param_3 = (&_machine_slot)[param_2 * 8];
    param_3[1] = (&dword_40B5DCC)[param_2 * 8];
    param_3[2] = (&dword_40B5DD0)[param_2 * 8];
    param_3[3] = (&dword_40B5DD4)[param_2 * 8];
    param_3[4] = *(undefined4 *)(DAT_40b5dd8 + iVar1);
    param_3[5] = *(undefined4 *)(DAT_40b5dd8 + iVar1 + 4);
    param_3[6] = *(undefined4 *)(DAT_40b5dd8 + iVar1 + 8);
    param_3[7] = *(undefined4 *)(DAT_40b5dd8 + iVar1 + 0xc);
    uVar2 = 0;
  }
  return uVar2;
}

