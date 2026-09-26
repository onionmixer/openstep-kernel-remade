
undefined4 _ipc_right_inuse(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *param_3;
  uVar3 = uVar1 & 0x1f0000;
  if (uVar3 != 0) {
    if (((uVar1 & 0x400000) == 0) ||
       (((uVar3 != 0x10000 && (uVar3 != 0x40000)) || (uVar2 = param_3[1], *(int *)(uVar2 + 4) < 0)))
       ) {
      return 1;
    }
    if (uVar3 == 0x10000) {
      if ((uVar1 & 0x200000) != 0) {
        _ipc_marequest_cancel(param_1,param_2);
      }
      _ipc_hash_delete(param_1,uVar2,param_2,param_3);
    }
    _ipc_object_release(uVar2);
    param_3[2] = 0;
    param_3[1] = 0;
    *param_3 = *param_3 & 0xff800000;
  }
  return 0;
}
