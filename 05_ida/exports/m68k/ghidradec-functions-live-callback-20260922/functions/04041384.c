
undefined4 * _ipc_port_alloc_special(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_zalloc(_ipc_object_zones);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 1;
    puVar1[1] = 0x80000000;
    _ipc_port_init(puVar1,param_1,1);
  }
  return puVar1;
}

