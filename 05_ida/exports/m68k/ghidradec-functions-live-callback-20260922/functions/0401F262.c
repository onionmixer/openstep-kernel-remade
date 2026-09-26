
int _in_ifinit(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined2 auStack_24 [2];
  undefined4 uStack_20;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar1 = param_3[1];
  uStack_14 = *param_2;
  uStack_10 = param_2[1];
  uStack_c = param_2[2];
  uStack_8 = param_2[3];
  *param_2 = *param_3;
  param_2[1] = param_3[1];
  param_2[2] = param_3[2];
  param_2[3] = param_3[3];
  if ((*(int *)(param_1 + 0x36) != 0) && (iVar3 = _if_ioctl(param_1,0x8020690c,param_2), iVar3 != 0)
     ) {
    *param_2 = uStack_14;
    param_2[1] = uStack_10;
    param_2[2] = uStack_c;
    param_2[3] = uStack_8;
    return iVar3;
  }
  _bzero(auStack_24,0x10);
  auStack_24[0] = 2;
  if ((*(byte *)((int)param_2 + 0x3f) & 1) != 0) {
    if ((*(word *)(param_1 + 0xc) & 8) == 0) {
      if ((*(word *)(param_1 + 0xc) & 0x10) != 0) {
        puVar5 = param_2 + 4;
        goto loc_401F330;
      }
      uStack_20 = _in_makeaddr(param_2[0xc],0);
      _rtinit(auStack_24,&uStack_14,0x8030720b,0);
    }
    else {
      puVar5 = &uStack_14;
loc_401F330:
      _rtinit(puVar5,&uStack_14,0x8030720b,4);
    }
    param_2[0xf] = param_2[0xf] & 0xfffffffe;
  }
  if ((int)uVar1 < 0) {
    if ((uVar1 & 0xc0000000) == 0x80000000) {
      param_2[0xb] = 0xffff0000;
    }
    else {
      param_2[0xb] = 0xffffff00;
    }
  }
  else {
    param_2[0xb] = 0xff000000;
  }
  param_2[10] = param_2[0xb] & uVar1;
  uVar2 = param_2[0xd];
  param_2[0xd] = param_2[0xb] | uVar2;
  param_2[0xc] = (param_2[0xb] | uVar2) & uVar1;
  if ((*(byte *)(param_1 + 0xd) & 2) != 0) {
    *(undefined2 *)(param_2 + 4) = 2;
    uVar4 = _in_makeaddr(param_2[0xc],0xffffffff);
    param_2[5] = uVar4;
    param_2[0xe] = param_2[10] | ~param_2[0xb];
  }
  puVar5 = param_2;
  if ((*(word *)(param_1 + 0xc) & 8) == 0) {
    if ((*(word *)(param_1 + 0xc) & 0x10) == 0) {
      uStack_20 = _in_makeaddr(param_2[0xc],0);
      _rtinit(auStack_24,param_2,0x8030720a,1);
      goto loc_401F44C;
    }
    puVar5 = param_2 + 4;
  }
  _rtinit(puVar5,param_2,0x8030720a,5);
loc_401F44C:
  param_2[0xf] = param_2[0xf] | 1;
  _in_addmulti(0xe0000001,param_1);
  return 0;
}

