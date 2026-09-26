
undefined4 _ipc_marequest_create(uint param_1,undefined4 param_2,int param_3,int *param_4)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint *puStack_c;
  uint uStack_8;
  
  puVar2 = (uint *)_zalloc(_ipc_marequest_zone);
  if (puVar2 == (uint *)0x0) {
    return 0x1000000e;
  }
  if (*(int *)(param_1 + 4) == 0) {
loc_403F046:
    _zfree(_ipc_marequest_zone,puVar2);
    uVar6 = 0x1000000b;
  }
  else {
    iVar3 = _ipc_right_reverse(param_1,param_2,&uStack_8,&puStack_c);
    if (iVar3 == 0) {
      if (param_3 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = _ipc_port_lookup_notify(param_1,param_3);
        if (uVar5 == 0) goto loc_403F046;
      }
      _ipc_space_reference(param_1);
      *puVar2 = param_1;
      puVar2[1] = 0;
      puVar2[2] = uVar5;
    }
    else {
      uVar5 = *puStack_c;
      if ((uVar5 & 0x200000) != 0) {
        _zfree(_ipc_marequest_zone,puVar2);
        return 0x10000006;
      }
      if (param_3 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = _ipc_port_lookup_notify(param_1,param_3);
        if (uVar4 == 0) goto loc_403F046;
      }
      *puStack_c = uVar5 | 0x200000;
      _ipc_space_reference(param_1);
      *puVar2 = param_1;
      puVar2[1] = uStack_8;
      puVar2[2] = uVar4;
      puVar1 = (uint *)(_ipc_marequest_table +
                       (_ipc_marequest_mask & (uStack_8 & 0xff) + (uStack_8 >> 8) + (param_1 >> 4))
                       * 4);
      puVar2[3] = *puVar1;
      *puVar1 = (uint)puVar2;
    }
    *param_4 = (int)puVar2;
    uVar6 = 0;
  }
  return uVar6;
}

