
bool _object_copyin(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  int iVar1;
  
  iVar1 = _ipc_object_copyin_compat(*(undefined4 *)(param_1 + 0x7c),param_2,param_3,param_4,param_5)
  ;
  return iVar1 == 0;
}
