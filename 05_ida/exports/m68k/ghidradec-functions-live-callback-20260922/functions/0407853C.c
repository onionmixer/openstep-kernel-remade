
undefined4 _od_attn(int param_1,int param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  
  if ((param_4 & 2) != 0) {
    *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) & 0xdfff;
  }
  if ((*(uint *)(param_1 + 0x220) & 0x4000000) == 0) {
    if ((param_4 & 2) == 0) {
      *(undefined2 *)(param_1 + 0x24e) = 0;
      *(undefined2 *)(param_1 + 0x24c) = *(undefined2 *)(param_1 + 0x24e);
      *(undefined2 *)(param_1 + 0x24a) = *(undefined2 *)(param_1 + 0x24c);
      uVar1 = 0;
    }
    else {
      *(byte *)(param_3 + 5) = *(byte *)(param_3 + 5) & 0xfd;
      *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) & 0xdfff;
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000000;
      _od_status(param_1,param_2,param_3,0x2000,6);
      *(undefined *)(param_1 + 0x26d) = *(undefined *)(param_1 + 0x267);
      *(undefined *)(param_1 + 0x26e) = *(undefined *)(param_1 + 0x268);
      *(undefined2 *)(param_1 + 0x24e) = 0;
      *(undefined2 *)(param_1 + 0x24c) = *(undefined2 *)(param_1 + 0x24e);
      *(undefined2 *)(param_1 + 0x24a) = *(undefined2 *)(param_1 + 0x24c);
      *(undefined *)(param_1 + 0x268) = 9;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = _od_fsm(param_1,param_2,(int)*(char *)(param_1 + 0x268));
  }
  return uVar1;
}

