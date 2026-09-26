
int _ipc_entry_alloc_name(int param_1,uint param_2,int *param_3)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  uVar6 = param_2 >> 8;
  puVar7 = (undefined4 *)0x0;
  do {
    while( true ) {
      if (*(int *)(param_1 + 4) == 0) {
        if (puVar7 != (undefined4 *)0x0) {
          _zfree(_ipc_tree_entry_zone,puVar7);
        }
        return 0x10;
      }
      if ((uVar6 != 0) && (uVar6 < *(uint *)(param_1 + 0x10))) {
        iVar5 = *(int *)(param_1 + 0xc);
        puVar1 = (uint *)(iVar5 + uVar6 * 0x10);
        if ((*puVar1 & 0x1f0000) == 0) {
          uVar3 = 0;
          for (uVar4 = *(uint *)(iVar5 + 8); uVar6 != uVar4;
              uVar4 = *(uint *)(iVar5 + 8 + uVar4 * 0x10)) {
            uVar3 = uVar4;
          }
          *(undefined4 *)(iVar5 + 8 + uVar3 * 0x10) = *(undefined4 *)(iVar5 + 8 + uVar4 * 0x10);
          *puVar1 = param_2 << 0x18;
          puVar1[2] = 0;
          *param_3 = (int)puVar1;
          if (puVar7 != (undefined4 *)0x0) {
            _zfree(_ipc_tree_entry_zone,puVar7);
          }
          return 0;
        }
        if (param_2 << 0x18 == (*puVar1 & 0xff000000)) {
          *param_3 = (int)puVar1;
          if (puVar7 == (undefined4 *)0x0) {
            return 0;
          }
          _zfree(_ipc_tree_entry_zone,puVar7);
          return 0;
        }
      }
      if ((*(int *)(param_1 + 0x30) != 0) &&
         (iVar5 = _ipc_splay_tree_lookup(param_1 + 0x18,param_2), iVar5 != 0)) {
        *param_3 = iVar5;
        if (puVar7 == (undefined4 *)0x0) {
          return 0;
        }
        _zfree(_ipc_tree_entry_zone,puVar7);
        return 0;
      }
      if (((uVar6 < *(uint *)(param_1 + 0x10)) ||
          (uVar3 = **(uint **)(param_1 + 0x14), uVar3 <= uVar6)) ||
         ((uint)((*(int *)(param_1 + 0x34) + 1) * 0x20) <=
          (uVar3 - *(uint *)(param_1 + 0x10)) * 0x10)) break;
      iVar5 = _ipc_entry_grow_table(param_1);
      if (iVar5 != 0) {
        if (puVar7 != (undefined4 *)0x0) {
          _zfree(_ipc_tree_entry_zone,puVar7);
          return iVar5;
        }
        return iVar5;
      }
    }
    if (puVar7 != (undefined4 *)0x0) {
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      if (uVar6 < *(uint *)(param_1 + 0x10)) {
        pbVar2 = (byte *)(*(int *)(param_1 + 0xc) + 1 + uVar6 * 0x10);
        *pbVar2 = *pbVar2 | 0x80;
      }
      else if ((uVar6 < **(uint **)(param_1 + 0x14)) &&
              (iVar5 = _ipc_entry_tree_collision(param_1,param_2), iVar5 == 0)) {
        *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
      }
      _ipc_splay_tree_insert(param_1 + 0x18,param_2,puVar7);
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
      puVar7[5] = param_1;
      *param_3 = (int)puVar7;
      return 0;
    }
    puVar7 = (undefined4 *)_zalloc(_ipc_tree_entry_zone);
  } while (puVar7 != (undefined4 *)0x0);
  return 6;
}
