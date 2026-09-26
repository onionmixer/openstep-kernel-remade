
int _ipc_port_alloc(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = _ipc_object_alloc(param_1,0,0x20000,0,&uStack_8,&uStack_c);
  if (iVar1 == 0) {
    _ipc_port_init(uStack_c,param_1,uStack_8);
    *param_2 = uStack_8;
    *param_3 = uStack_c;
    iVar1 = 0;
  }
  return iVar1;
}

