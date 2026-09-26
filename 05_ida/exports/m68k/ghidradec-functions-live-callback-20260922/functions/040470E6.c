
undefined4 _port_set_allocate(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined auStack_8 [4];
  
  if (param_1 != 0) {
    iVar1 = _ipc_pset_alloc(param_1,param_2,auStack_8);
    if (iVar1 == 0) {
      return 0;
    }
    if (iVar1 == 6) {
      return 6;
    }
  }
  return 4;
}

