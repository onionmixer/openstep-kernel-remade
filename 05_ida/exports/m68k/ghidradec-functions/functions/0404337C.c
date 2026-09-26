
void _ipc_splay_tree_delete(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iStack_8;
  
  iStack_8 = param_1[1];
  if (param_2 != *param_1) {
    sub_40431D2(iStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
    sub_404310C(param_2,iStack_8,&iStack_8,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5);
  }
  *(undefined4 *)param_1[3] = *(undefined4 *)(iStack_8 + 0x18);
  *(undefined4 *)param_1[5] = *(undefined4 *)(iStack_8 + 0x1c);
  _zfree(_ipc_tree_entry_zone,iStack_8);
  iStack_8 = param_1[2];
  iVar1 = param_1[4];
  iVar2 = iVar1;
  if ((iStack_8 != 0) && (iVar2 = iStack_8, iVar1 != 0)) {
    sub_404310C(0xffffffff,iStack_8,&iStack_8,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5);
    sub_40431D2(iStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
    *(int *)(iStack_8 + 0x1c) = iVar1;
    iVar2 = iStack_8;
  }
  iStack_8 = iVar2;
  param_1[1] = iStack_8;
  if (iStack_8 != 0) {
    *param_1 = *(int *)(iStack_8 + 0x10);
    param_1[3] = (int)(param_1 + 2);
    param_1[5] = (int)(param_1 + 4);
  }
  return;
}
