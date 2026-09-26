
undefined4 _port_insert_send(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((((param_1 != 0) && (param_3 != 0)) && (param_3 != -1)) && ((param_2 != 0 && (param_2 != -1)))
     ) {
    iVar1 = _ipc_object_copyout_name_compat(param_1,param_2,0x11,param_3);
    if (iVar1 == 6) {
      return 6;
    }
    if (iVar1 < 7) {
      if (iVar1 == 0) {
        return 0;
      }
    }
    else {
      if (iVar1 == 0xd) {
        return 0xd;
      }
      if (iVar1 == 0x15) {
        return 5;
      }
    }
  }
  return 4;
}

