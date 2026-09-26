
int _ipc_splay_tree_pick(int param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    *param_2 = *(undefined4 *)(iVar1 + 0x10);
    *param_3 = iVar1;
  }
  return -(int)-(iVar1 != 0);
}
