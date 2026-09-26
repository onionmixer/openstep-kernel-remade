
int _ipc_splay_tree_lookup(int *param_1,int param_2)

{
  int iStack_8;
  
  iStack_8 = param_1[1];
  if (iStack_8 != 0) {
    if (param_2 != *param_1) {
      sub_40431D2(iStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      sub_404310C(param_2,iStack_8,&iStack_8,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5);
      *param_1 = param_2;
      param_1[1] = iStack_8;
    }
    if (param_2 != *(int *)(iStack_8 + 0x10)) {
      iStack_8 = 0;
    }
  }
  return iStack_8;
}
