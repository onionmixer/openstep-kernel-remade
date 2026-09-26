
int _ipc_object_alloc(undefined4 param_1,int param_2,uint param_3,uint param_4,undefined4 param_5,
                     undefined4 *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puStack_8;
  
  puVar1 = (undefined4 *)_zalloc((&_ipc_object_zones)[param_2]);
  if (puVar1 == (undefined4 *)0x0) {
    iVar2 = 6;
  }
  else {
    iVar2 = _ipc_entry_alloc(param_1,param_5,&puStack_8);
    if (iVar2 == 0) {
      *puStack_8 = param_4 | param_3 | *puStack_8;
      puStack_8[1] = (uint)puVar1;
      *puVar1 = 1;
      puVar1[1] = param_2 << 0x10 | 0x80000000;
      *param_6 = puVar1;
      iVar2 = 0;
    }
    else {
      _zfree((&_ipc_object_zones)[param_2],puVar1);
    }
  }
  return iVar2;
}
