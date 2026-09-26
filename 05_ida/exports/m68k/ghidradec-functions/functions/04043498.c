
void _ipc_splay_tree_split(uint *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uStack_8;
  
  _ipc_splay_tree_init(param_3);
  uStack_8 = param_1[1];
  if (uStack_8 != 0) {
    if (param_2 != *param_1) {
      sub_40431D2(uStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      sub_404310C(param_2,uStack_8,&uStack_8,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5);
    }
    if (*(uint *)(uStack_8 + 0x10) < param_2) {
      *(undefined4 *)param_1[3] = *(undefined4 *)(uStack_8 + 0x18);
      *(undefined4 *)param_1[5] = 0;
      *(uint *)(uStack_8 + 0x18) = param_1[2];
      param_3[1] = uStack_8;
      *param_3 = *(undefined4 *)(uStack_8 + 0x10);
      param_3[3] = param_3 + 2;
      param_3[5] = param_3 + 4;
      uVar1 = param_1[4];
      param_1[1] = uVar1;
      if (uVar1 != 0) {
        *param_1 = *(uint *)(uVar1 + 0x10);
        param_1[3] = (uint)(param_1 + 2);
        param_1[5] = (uint)(param_1 + 4);
      }
    }
    else {
      *(undefined4 *)param_1[3] = *(undefined4 *)(uStack_8 + 0x18);
      *(undefined4 *)(uStack_8 + 0x18) = 0;
      param_1[1] = uStack_8;
      *param_1 = param_2;
      param_1[3] = (uint)(param_1 + 2);
      uVar1 = param_1[2];
      param_3[1] = uVar1;
      if (uVar1 != 0) {
        *param_3 = *(undefined4 *)(uVar1 + 0x10);
        param_3[3] = param_3 + 2;
        param_3[5] = param_3 + 4;
      }
    }
  }
  return;
}
