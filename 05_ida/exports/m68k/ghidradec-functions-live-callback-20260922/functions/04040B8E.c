
undefined4 _ipc_port_dngrow(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  
  puVar8 = (uint *)param_1[10];
  puVar6 = _ipc_table_dnrequests;
  if (puVar8 != (uint *)0x0) {
    puVar6 = (uint *)(puVar8[1] + 4);
  }
  *param_1 = *param_1 + 1;
  if ((*puVar6 == 0) || (puVar3 = (uint *)_ipc_table_alloc(*puVar6 << 3), puVar3 == (uint *)0x0)) {
    _ipc_object_release(param_1);
    return 6;
  }
  *param_1 = *param_1 + -1;
  if (((param_1[1] < 0) && (puVar8 == (uint *)param_1[10])) &&
     ((puVar8 == (uint *)0x0 || (puVar6 == (uint *)(puVar8[1] + 4))))) {
    puVar5 = (uint *)0x0;
    if (puVar8 == (uint *)0x0) {
      uVar4 = 1;
      uVar7 = 0;
    }
    else {
      puVar5 = (uint *)puVar8[1];
      uVar4 = *puVar5;
      uVar7 = *puVar8;
      _bcopy(puVar8 + 2,puVar3 + 2,uVar4 * 8 + -8);
    }
    uVar1 = *puVar6;
    while (uVar2 = uVar4, uVar2 < uVar1) {
      (puVar3 + uVar2 * 2)[1] = 0;
      puVar3[uVar2 * 2] = uVar7;
      uVar7 = uVar2;
      uVar4 = uVar2 + 1;
    }
    *puVar3 = uVar7;
    puVar3[1] = (uint)puVar6;
    param_1[10] = (int)puVar3;
    if (puVar8 == (uint *)0x0) {
      return 0;
    }
  }
  else {
    puVar5 = puVar6;
    puVar8 = puVar3;
    if (*param_1 == 0) {
      _zfree((&_ipc_object_zones)[*(word *)(param_1 + 1) & 0x7fff],param_1);
    }
  }
  _ipc_table_free(*puVar5 << 3,puVar8);
  return 0;
}

