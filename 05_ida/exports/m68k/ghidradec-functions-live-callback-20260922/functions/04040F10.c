
int _ipc_port_alloc_name(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _ipc_object_alloc_name(param_1,0,0x20000,0,param_2,&uStack_8);
  if (iVar1 == 0) {
    _ipc_port_init(uStack_8,param_1,param_2);
    *param_3 = uStack_8;
    iVar1 = 0;
  }
  return iVar1;
}

