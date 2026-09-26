/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001464ac */

undefined4 _ipc_entry_grow_table(int param_1)

{
  void *pvVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  undefined4 uVar9;
  int *piVar10;
  uint uVar11;
  uint *puVar12;
  int iVar13;
  uint uVar14;
  uint local_6c;
  uint *local_60;
  undefined1 local_4c [24];
  undefined1 local_34 [24];
  undefined1 local_1c [24];
  
  while( true ) {
    if (*(int *)(param_1 + 0x10) != 0) {
      _assert_wait(param_1,0);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      _thread_block_with_continuation(0);
      piVar10 = (int *)(param_1 + 8);
      do {
        do {
        } while (*piVar10 != 0);
        LOCK();
        iVar7 = *piVar10;
        *piVar10 = 1;
        UNLOCK();
      } while (iVar7 == 1);
      return 0;
    }
    pvVar1 = *(void **)(param_1 + 0x14);
    puVar2 = *(uint **)(param_1 + 0x1c);
    uVar3 = *puVar2;
    uVar4 = puVar2[-1];
    uVar5 = puVar2[1];
    if (uVar4 == uVar3) {
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      return 3;
    }
    *(undefined4 *)(param_1 + 0x10) = 1;
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    if (puVar2[-1] << 4 < _page_size) {
      local_60 = (uint *)_ipc_table_alloc(*puVar2 << 4);
    }
    else {
      local_60 = (uint *)_ipc_table_realloc(puVar2[-1] << 4,pvVar1,*puVar2 << 4);
    }
    piVar10 = (int *)(param_1 + 8);
    do {
      do {
      } while (*piVar10 != 0);
      LOCK();
      iVar7 = *piVar10;
      *piVar10 = 1;
      UNLOCK();
    } while (iVar7 == 1);
    *(undefined4 *)(param_1 + 0x10) = 0;
    if (local_60 == (uint *)0x0) {
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      _thread_wakeup_prim(param_1,0,0);
      return 6;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      _thread_wakeup_prim(param_1,0,0);
      _ipc_table_free(*puVar2 << 4,local_60);
      piVar10 = (int *)(param_1 + 8);
      do {
        do {
        } while (*piVar10 != 0);
        LOCK();
        iVar7 = *piVar10;
        *piVar10 = 1;
        UNLOCK();
      } while (iVar7 == 1);
      return 0;
    }
    *(uint **)(param_1 + 0x14) = local_60;
    *(uint *)(param_1 + 0x18) = uVar3;
    *(uint **)(param_1 + 0x1c) = puVar2 + 1;
    if (puVar2[-1] << 4 < _page_size) {
      _bcopy(pvVar1,local_60,uVar4 << 4);
    }
    uVar11 = 0;
    if (uVar4 != 0) {
      iVar7 = 0;
      do {
        *(undefined4 *)((int)local_60 + iVar7 + 0xc) = 0;
        iVar7 = iVar7 + 0x10;
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar4);
    }
    _bzero(local_60 + uVar4 * 4,(uVar3 - uVar4) * 0x10);
    uVar11 = 0;
    puVar8 = local_60;
    if (uVar4 != 0) {
      do {
        if ((*puVar8 & 0x1f0000) == 0x10000) {
          _ipc_hash_local_insert(param_1,puVar8[1],uVar11,puVar8);
        }
        uVar11 = uVar11 + 1;
        puVar8 = puVar8 + 4;
      } while (uVar11 < uVar4);
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      _ipc_splay_tree_split(param_1 + 0x20,uVar5 << 8,local_4c);
      _ipc_splay_tree_split(local_4c,uVar3 << 8,local_34);
      _ipc_splay_tree_split(local_34,uVar4 << 8,local_1c);
      puVar8 = (uint *)_ipc_splay_traverse_start(local_34);
      while (puVar8 != (uint *)0x0) {
        uVar11 = puVar8[4];
        puVar12 = local_60 + (uVar11 >> 8) * 4;
        if (*puVar12 == 0) {
          uVar14 = *puVar8;
          *puVar12 = uVar14 | uVar11 << 0x18;
          uVar6 = puVar8[1];
          puVar12[1] = uVar6;
          puVar12[2] = puVar8[2];
          if ((uVar14 & 0x1f0000) == 0x10000) {
            _ipc_hash_global_delete(param_1,uVar6,uVar11,puVar8);
            _ipc_hash_local_insert(param_1,uVar6,uVar11 >> 8,puVar12);
          }
          *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
          uVar9 = 1;
        }
        else {
          *puVar12 = *puVar12 | 0x800000;
          uVar9 = 0;
        }
        puVar8 = (uint *)_ipc_splay_traverse_next(local_34,uVar9);
      }
      _ipc_splay_traverse_finish(local_34);
      iVar13 = 0;
      local_6c = 0;
      iVar7 = _ipc_splay_traverse_start(local_4c);
      while (iVar7 != 0) {
        uVar11 = *(uint *)(iVar7 + 0x10) >> 8;
        if (local_6c != uVar11) {
          iVar13 = iVar13 + 1;
          local_6c = uVar11;
        }
        iVar7 = _ipc_splay_traverse_next(local_4c,0);
      }
      _ipc_splay_traverse_finish(local_4c);
      *(int *)(param_1 + 0x3c) = iVar13;
      iVar7 = param_1 + 0x20;
      _ipc_splay_tree_join(iVar7,local_4c);
      _ipc_splay_tree_join(iVar7,local_34);
      _ipc_splay_tree_join(iVar7,local_1c);
    }
    uVar11 = local_60[2];
    uVar14 = uVar3 - 1;
    if (uVar4 <= uVar14) {
      puVar8 = local_60 + uVar14 * 4;
      do {
        if (*puVar8 == 0) {
          *puVar8 = 0xff000000;
          puVar8[2] = uVar11;
          uVar11 = uVar14;
        }
        puVar8 = puVar8 + -4;
        uVar14 = uVar14 - 1;
      } while (uVar4 <= uVar14);
    }
    local_60[2] = uVar11;
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    _thread_wakeup_prim(param_1,0,0);
    _ipc_table_free(puVar2[-1] << 4,pvVar1);
    piVar10 = (int *)(param_1 + 8);
    do {
      do {
      } while (*piVar10 != 0);
      LOCK();
      iVar7 = *piVar10;
      *piVar10 = 1;
      UNLOCK();
    } while (iVar7 == 1);
    if (*(int *)(param_1 + 0xc) == 0) break;
    if (*(uint **)(param_1 + 0x1c) != puVar2 + 1) {
      return 0;
    }
    if ((*(int *)(param_1 + 0x3c) == 0) ||
       ((uint)(*(int *)(param_1 + 0x3c) << 5) <= (uVar5 - uVar3) * 0x10)) {
      return 0;
    }
  }
  return 0;
}

