
undefined4 _ipc_entry_grow_table(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined auStack_4c [24];
  undefined auStack_34 [24];
  undefined auStack_1c [24];
  
  while( true ) {
    if (*(int *)(param_1 + 8) != 0) {
      _assert_wait(param_1,0);
      _thread_block_with_continuation(0);
      return 0;
    }
    uVar5 = *(undefined4 *)(param_1 + 0xc);
    puVar10 = *(uint **)(param_1 + 0x14);
    uVar2 = *puVar10;
    puVar7 = puVar10 + -1;
    uVar3 = *puVar7;
    puVar8 = puVar10 + 1;
    uVar4 = *puVar8;
    if (uVar2 == uVar3) {
      return 3;
    }
    *(undefined4 *)(param_1 + 8) = 1;
    if (*puVar7 << 4 < _page_size) {
      puVar9 = (uint *)_ipc_table_alloc(*puVar10 << 4);
    }
    else {
      puVar9 = (uint *)_ipc_table_realloc(*puVar7 << 4,uVar5,*puVar10 << 4);
    }
    *(undefined4 *)(param_1 + 8) = 0;
    if (puVar9 == (uint *)0x0) {
      _thread_wakeup_prim(param_1,0,0);
      return 6;
    }
    if (*(int *)(param_1 + 4) == 0) {
      _thread_wakeup_prim(param_1,0,0);
      _ipc_table_free(*puVar10 << 4,puVar9);
      return 0;
    }
    *(uint **)(param_1 + 0xc) = puVar9;
    *(uint *)(param_1 + 0x10) = uVar2;
    *(uint **)(param_1 + 0x14) = puVar8;
    if (*puVar7 << 4 < _page_size) {
      _bcopy(uVar5,puVar9,uVar3 << 4);
    }
    uVar14 = 0;
    if (uVar3 != 0) {
      do {
        puVar9[uVar14 * 4 + 3] = 0;
        uVar14 = uVar14 + 1;
      } while (uVar14 < uVar3);
    }
    _bzero(puVar9 + uVar3 * 4,(uVar2 - uVar3) * 0x10);
    uVar14 = 0;
    puVar10 = puVar9;
    if (uVar3 != 0) {
      do {
        if ((*puVar10 & 0x1f0000) == 0x10000) {
          _ipc_hash_local_insert(param_1,puVar10[1],uVar14,puVar10);
        }
        uVar14 = uVar14 + 1;
        puVar10 = puVar10 + 4;
      } while (uVar14 < uVar3);
    }
    if (*(int *)(param_1 + 0x30) != 0) {
      _ipc_splay_tree_split(param_1 + 0x18,uVar4 << 8,auStack_4c);
      _ipc_splay_tree_split(auStack_4c,uVar2 << 8,auStack_34);
      _ipc_splay_tree_split(auStack_34,uVar3 << 8,auStack_1c);
      puVar10 = (uint *)_ipc_splay_traverse_start(auStack_34);
      while (puVar10 != (uint *)0x0) {
        uVar14 = puVar10[4];
        puVar1 = puVar9 + (uVar14 >> 8) * 4;
        if (*puVar1 == 0) {
          uVar13 = *puVar10;
          *puVar1 = uVar14 << 0x18 | uVar13;
          uVar6 = puVar10[1];
          puVar1[1] = uVar6;
          puVar1[2] = puVar10[2];
          if ((uVar13 & 0x1f0000) == 0x10000) {
            _ipc_hash_global_delete(param_1,uVar6,uVar14,puVar10);
            _ipc_hash_local_insert(param_1,uVar6,uVar14 >> 8,puVar1);
          }
          *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
          uVar11 = 1;
        }
        else {
          *puVar1 = *puVar1 | 0x800000;
          uVar11 = 0;
        }
        puVar10 = (uint *)_ipc_splay_traverse_next(auStack_34,uVar11);
      }
      _ipc_splay_traverse_finish(auStack_34);
      iVar15 = 0;
      uVar14 = 0;
      iVar12 = _ipc_splay_traverse_start(auStack_4c);
      while (iVar12 != 0) {
        uVar13 = *(uint *)(iVar12 + 0x10) >> 8;
        if (uVar14 != uVar13) {
          iVar15 = iVar15 + 1;
          uVar14 = uVar13;
        }
        iVar12 = _ipc_splay_traverse_next(auStack_4c,0);
      }
      _ipc_splay_traverse_finish(auStack_4c);
      *(int *)(param_1 + 0x34) = iVar15;
      iVar15 = param_1 + 0x18;
      _ipc_splay_tree_join(iVar15,auStack_4c);
      _ipc_splay_tree_join(iVar15,auStack_34);
      _ipc_splay_tree_join(iVar15,auStack_1c);
    }
    uVar14 = puVar9[2];
    uVar13 = uVar2 - 1;
    if (uVar3 <= uVar13) {
      puVar10 = puVar9 + uVar13 * 4;
      do {
        if (*puVar10 == 0) {
          *puVar10 = 0xff000000;
          puVar10[2] = uVar14;
          uVar14 = uVar13;
        }
        puVar10 = puVar10 + -4;
        uVar13 = uVar13 - 1;
      } while (uVar3 <= uVar13);
    }
    puVar9[2] = uVar14;
    _thread_wakeup_prim(param_1,0,0);
    _ipc_table_free(*puVar7 << 4,uVar5);
    if (*(int *)(param_1 + 4) == 0) break;
    if (puVar8 != *(uint **)(param_1 + 0x14)) {
      return 0;
    }
    if (*(int *)(param_1 + 0x34) == 0) {
      return 0;
    }
    if ((uint)(*(int *)(param_1 + 0x34) << 5) <= (uVar4 - uVar2) * 0x10) {
      return 0;
    }
  }
  return 0;
}
