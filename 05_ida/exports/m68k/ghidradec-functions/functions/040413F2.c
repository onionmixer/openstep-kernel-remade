
int _ipc_port_alloc_compat(uint param_1,uint *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puStack_c;
  uint uStack_8;
  
  puVar4 = (undefined4 *)_zalloc(_ipc_object_zones);
  puVar2 = _ipc_table_dnrequests;
  if (puVar4 == (undefined4 *)0x0) {
    iVar5 = 6;
  }
  else {
    puVar6 = (uint *)_ipc_table_alloc(*_ipc_table_dnrequests << 3);
    if (puVar6 == (uint *)0x0) {
      _zfree(_ipc_object_zones,puVar4);
      iVar5 = 6;
    }
    else {
      iVar5 = _ipc_entry_alloc(param_1,&uStack_8,&puStack_c);
      if (iVar5 == 0) {
        puStack_c[1] = (uint)puVar4;
        puStack_c[2] = 1;
        *puStack_c = *puStack_c | 0x420000;
        *puVar4 = 1;
        puVar4[1] = 0x80000000;
        _ipc_port_init(puVar4,param_1,uStack_8);
        uVar1 = *puVar2;
        uVar7 = 0;
        uVar3 = 2;
        uVar8 = uVar7;
        if (2 < uVar1) {
          do {
            uVar7 = uVar3;
            (puVar6 + uVar7 * 2)[1] = 0;
            puVar6[uVar7 * 2] = uVar8;
            uVar3 = uVar7 + 1;
            uVar8 = uVar7;
          } while (uVar7 + 1 < uVar1);
        }
        *puVar6 = uVar7;
        puVar6[1] = (uint)puVar2;
        puVar4[10] = puVar6;
        puVar6[3] = uStack_8;
        puVar6[2] = param_1 | 1;
        _ipc_space_reference(param_1);
        *param_2 = uStack_8;
        *param_3 = puVar4;
        iVar5 = 0;
      }
      else {
        _zfree(_ipc_object_zones,puVar4);
        _ipc_table_free(*puVar2 << 3,puVar6);
      }
    }
  }
  return iVar5;
}
