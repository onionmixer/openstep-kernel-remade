
undefined4 _ipc_space_create(uint *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  puVar3 = (undefined4 *)_zalloc(_ipc_space_zone);
  if (puVar3 == (undefined4 *)0x0) {
    uVar4 = 6;
  }
  else {
    iVar5 = _ipc_table_alloc(*param_1 << 4);
    if (iVar5 == 0) {
      _zfree(_ipc_space_zone,puVar3);
      uVar4 = 6;
    }
    else {
      uVar2 = *param_1;
      _bzero(iVar5,uVar2 << 4);
      uVar6 = 0;
      if (uVar2 != 0) {
        do {
          puVar1 = (undefined4 *)(iVar5 + uVar6 * 0x10);
          *puVar1 = 0xff000000;
          uVar6 = uVar6 + 1;
          puVar1[2] = uVar6;
        } while (uVar6 < uVar2);
      }
      *(undefined4 *)(iVar5 + -8 + uVar2 * 0x10) = 0;
      *puVar3 = 2;
      puVar3[1] = 1;
      puVar3[2] = 0;
      puVar3[3] = iVar5;
      puVar3[4] = uVar2;
      puVar3[5] = param_1 + 1;
      _ipc_splay_tree_init(puVar3 + 6);
      puVar3[0xc] = 0;
      puVar3[0xd] = 0;
      puVar3[0xe] = 0;
      puVar3[0xf] = 0;
      *param_2 = puVar3;
      uVar4 = 0;
    }
  }
  return uVar4;
}

