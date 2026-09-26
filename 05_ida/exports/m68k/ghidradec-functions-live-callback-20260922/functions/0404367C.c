
void _ipc_splay_tree_bounds(uint *param_1,uint param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uStack_8;
  
  uStack_8 = param_1[1];
  if (uStack_8 == 0) {
    *param_3 = 0xffffffff;
  }
  else {
    if (param_2 != *param_1) {
      sub_40431D2(uStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      sub_404310C(param_2,uStack_8,&uStack_8,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5);
      *param_1 = param_2;
      param_1[1] = uStack_8;
    }
    uVar1 = *(uint *)(uStack_8 + 0x10);
    if (param_2 < uVar1) {
      if (param_1 + 2 == (uint *)param_1[3]) {
        *param_3 = 0xffffffff;
      }
      else {
        *param_3 = ((uint *)param_1[3])[-3];
      }
    }
    else {
      *param_3 = uVar1;
    }
    if (param_2 <= uVar1) {
      *param_4 = uVar1;
      return;
    }
    if (param_1 + 4 != (uint *)param_1[5]) {
      *param_4 = ((uint *)param_1[5])[-2];
      return;
    }
  }
  *param_4 = 0;
  return;
}

