/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c4d0 */

undefined4 _ipc_port_dngrow(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint local_1c;
  uint *local_14;
  uint *local_8;
  
  puVar5 = (uint *)param_1[0xb];
  if (puVar5 == (uint *)0x0) {
    local_8 = _ipc_table_dnrequests;
  }
  else {
    local_8 = (uint *)(puVar5[1] + 4);
  }
  param_1[1] = param_1[1] + 1;
  LOCK();
  *param_1 = 0;
  UNLOCK();
  if ((*local_8 == 0) || (puVar3 = (uint *)_ipc_table_alloc(*local_8 << 3), puVar3 == (uint *)0x0))
  {
    _ipc_object_release(param_1);
    return 6;
  }
  do {
    do {
    } while (*param_1 != 0);
    LOCK();
    iVar1 = *param_1;
    *param_1 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  param_1[1] = param_1[1] + -1;
  if (((param_1[2] < 0) && ((uint *)param_1[0xb] == puVar5)) &&
     ((puVar5 == (uint *)0x0 || (local_8 == (uint *)(puVar5[1] + 4))))) {
    local_14 = (uint *)0x0;
    if (puVar5 == (uint *)0x0) {
      local_1c = 1;
      uVar4 = 0;
    }
    else {
      local_14 = (uint *)puVar5[1];
      local_1c = *local_14;
      uVar4 = *puVar5;
      _bcopy(puVar5 + 2,puVar3 + 2,local_1c * 8 - 8);
    }
    uVar2 = *local_8;
    for (; local_1c < uVar2; local_1c = local_1c + 1) {
      (puVar3 + local_1c * 2)[1] = 0;
      puVar3[local_1c * 2] = uVar4;
      uVar4 = local_1c;
    }
    *puVar3 = uVar4;
    puVar3[1] = (uint)local_8;
    param_1[0xb] = (int)puVar3;
    LOCK();
    *param_1 = 0;
    UNLOCK();
    local_8 = local_14;
    if (puVar5 == (uint *)0x0) {
      return 0;
    }
  }
  else {
    LOCK();
    *param_1 = 0;
    UNLOCK();
    puVar5 = puVar3;
    if (param_1[1] == 0) {
      _zfree((&_ipc_object_zones)[*(ushort *)((int)param_1 + 10) & 0x7fff],param_1);
    }
  }
  _ipc_table_free(*local_8 * 8,puVar5);
  return 0;
}

