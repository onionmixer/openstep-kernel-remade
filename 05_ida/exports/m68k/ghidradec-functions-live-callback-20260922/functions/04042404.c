
undefined4
_ipc_right_info(undefined4 param_1,undefined4 param_2,uint *param_3,uint *param_4,
               undefined2 *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *param_3;
  if (((uVar3 & 0x50000) != 0) &&
     (iVar1 = _ipc_right_check(param_1,param_3[1],param_2,param_3), iVar1 != 0)) {
    if ((uVar3 & 0x400000) != 0) {
      return 0xf;
    }
    uVar3 = *param_3;
  }
  uVar2 = uVar3 & 0x1f0000;
  if ((uVar3 & 0x400000) == 0) {
    if (param_3[2] != 0) {
      uVar2 = uVar2 | 0x80000000;
    }
  }
  else {
    uVar2 = uVar2 | 0x20000000;
  }
  if ((uVar3 & 0x200000) != 0) {
    uVar2 = uVar2 | 0x40000000;
  }
  *param_4 = uVar2;
  *param_5 = 0;
  param_5[1] = (sword)uVar3;
  return 0;
}

