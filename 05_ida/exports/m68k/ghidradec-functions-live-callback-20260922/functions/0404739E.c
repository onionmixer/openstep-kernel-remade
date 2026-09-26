
undefined4 _port_extract_receive(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = _ipc_object_copyin_compat(param_1,param_2,5,1,param_3), iVar1 == 0)
     ) {
    return 0;
  }
  return 4;
}

