
int _ipc_object_copyout(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  int iStack_c;
  undefined4 uStack_8;
  
  while( true ) {
    if (*(int *)(param_1 + 4) == 0) {
      return 0x10;
    }
    if ((param_3 != 0x12) &&
       (iVar1 = _ipc_right_reverse(param_1,param_2,&uStack_8,&iStack_c), iVar1 != 0)) break;
    iVar1 = _ipc_entry_get(param_1,&uStack_8,&iStack_c);
    if (iVar1 == 0) {
      if (-1 < *(int *)(param_2 + 4)) {
        _ipc_entry_dealloc(param_1,uStack_8,iStack_c);
        return 0x14;
      }
      *(int *)(iStack_c + 4) = param_2;
      break;
    }
    iVar1 = _ipc_entry_grow_table(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = _ipc_right_copyout(param_1,uStack_8,iStack_c,param_3,param_4,param_2);
  if (iVar1 != 0) {
    return iVar1;
  }
  *param_5 = uStack_8;
  return 0;
}

