
void _ipc_splay_tree_join(int *param_1,int param_2)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 != 0) {
    sub_40431D2(iVar1,param_2 + 8,*(undefined4 *)(param_2 + 0xc),param_2 + 0x10,
                *(undefined4 *)(param_2 + 0x14));
    *(undefined4 *)(param_2 + 4) = 0;
    iStack_8 = param_1[1];
    if (iStack_8 != 0) {
      if (*param_1 != 0) {
        sub_40431D2(iStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
        sub_404310C(0,iStack_8,&iStack_8,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5);
      }
      sub_40431D2(iStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      *(int *)(iStack_8 + 0x18) = iVar1;
      iVar1 = iStack_8;
    }
    iStack_8 = iVar1;
    param_1[1] = iStack_8;
    *param_1 = *(int *)(iStack_8 + 0x10);
    param_1[3] = (int)(param_1 + 2);
    param_1[5] = (int)(param_1 + 4);
  }
  return;
}

