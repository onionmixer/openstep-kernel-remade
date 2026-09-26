
void _ipc_object_copyin_header
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8);
  if (iVar1 == 0) {
    _ipc_right_copyin_header(param_1,param_2,uStack_8,param_3,param_4);
  }
  return;
}
