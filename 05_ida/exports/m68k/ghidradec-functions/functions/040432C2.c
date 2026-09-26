
void _ipc_splay_tree_insert(uint *param_1,uint param_2,uint param_3)

{
  uint uStack_8;
  
  uStack_8 = param_1[1];
  if (uStack_8 == 0) {
    *(undefined4 *)(param_3 + 0x18) = 0;
    *(undefined4 *)(param_3 + 0x1c) = 0;
  }
  else {
    if (param_2 != *param_1) {
      sub_40431D2(uStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      sub_404310C(param_2,uStack_8,&uStack_8,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5);
    }
    if (param_2 < *(uint *)(uStack_8 + 0x10)) {
      *(undefined4 *)param_1[3] = 0;
      *(uint *)param_1[5] = uStack_8;
    }
    else {
      *(uint *)param_1[3] = uStack_8;
      *(undefined4 *)param_1[5] = 0;
    }
    *(uint *)(param_3 + 0x18) = param_1[2];
    *(uint *)(param_3 + 0x1c) = param_1[4];
  }
  *(uint *)(param_3 + 0x10) = param_2;
  param_1[1] = param_3;
  *param_1 = param_2;
  param_1[3] = (uint)(param_1 + 2);
  param_1[5] = (uint)(param_1 + 4);
  return;
}
