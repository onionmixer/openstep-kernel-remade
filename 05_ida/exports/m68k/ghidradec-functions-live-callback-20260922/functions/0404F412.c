
undefined4
_processor_set_info(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,uint *param_5)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_1 == 0) {
loc_404F488:
    uVar1 = 4;
  }
  else {
    if (param_2 == 1) {
      if (*param_5 < 5) {
        return 5;
      }
      *param_4 = *(undefined4 *)(param_1 + 0x11c);
      param_4[1] = *(undefined4 *)(param_1 + 300);
      param_4[2] = *(undefined4 *)(param_1 + 0x138);
      param_4[4] = *(undefined4 *)(param_1 + 0x160);
      param_4[3] = *(undefined4 *)(param_1 + 0x164);
      uVar2 = 5;
    }
    else {
      if (param_2 != 2) {
        *param_3 = 0;
        goto loc_404F488;
      }
      if (*param_5 < 2) {
        return 5;
      }
      *param_4 = *(undefined4 *)(param_1 + 0x158);
      param_4[1] = *(undefined4 *)(param_1 + 0x154);
      uVar2 = 2;
    }
    *param_5 = uVar2;
    *param_3 = &_realhost;
    uVar1 = 0;
  }
  return uVar1;
}

