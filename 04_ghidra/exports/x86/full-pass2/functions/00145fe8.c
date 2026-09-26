/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00145fe8 */

int _ipc_entry_alloc_name(int param_1,uint param_2,int *param_3)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint local_c;
  uint local_8;
  
  uVar7 = param_2 >> 8;
  puVar8 = (undefined4 *)0x0;
  piVar6 = (int *)(param_1 + 8);
  do {
    do {
    } while (*piVar6 != 0);
    LOCK();
    iVar5 = *piVar6;
    *piVar6 = 1;
    UNLOCK();
  } while (iVar5 == 1);
  do {
    if (*(int *)(param_1 + 0xc) == 0) {
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      if (puVar8 != (undefined4 *)0x0) {
        _zfree(_ipc_tree_entry_zone,puVar8);
      }
      return 0x10;
    }
    if ((uVar7 != 0) && (uVar7 < *(uint *)(param_1 + 0x18))) {
      iVar5 = *(int *)(param_1 + 0x14);
      puVar4 = (uint *)(uVar7 * 0x10 + iVar5);
      if ((*puVar4 & 0x1f0000) == 0) {
        uVar1 = 0;
        for (uVar3 = *(uint *)(iVar5 + 8); uVar7 != uVar3;
            uVar3 = *(uint *)(iVar5 + 8 + uVar3 * 0x10)) {
          uVar1 = uVar3;
        }
        *(undefined4 *)(iVar5 + 8 + uVar1 * 0x10) = *(undefined4 *)(iVar5 + 8 + uVar3 * 0x10);
        *puVar4 = param_2 << 0x18;
        puVar4[2] = 0;
        *param_3 = (int)puVar4;
joined_r0x0014608b:
        if (puVar8 != (undefined4 *)0x0) {
          _zfree(_ipc_tree_entry_zone,puVar8);
        }
        return 0;
      }
      if (param_2 << 0x18 == (*puVar4 & 0xff000000)) {
        *param_3 = (int)puVar4;
        goto joined_r0x0014608b;
      }
    }
    if ((*(int *)(param_1 + 0x38) != 0) &&
       (iVar5 = _ipc_splay_tree_lookup(param_1 + 0x20,param_2), iVar5 != 0)) {
      *param_3 = iVar5;
      goto joined_r0x0014608b;
    }
    if (((uVar7 < *(uint *)(param_1 + 0x18)) ||
        (uVar1 = **(uint **)(param_1 + 0x1c), uVar1 <= uVar7)) ||
       ((uint)((*(int *)(param_1 + 0x3c) + 1) * 0x20) <= (uVar1 - *(uint *)(param_1 + 0x18)) * 0x10)
       ) {
      if (puVar8 != (undefined4 *)0x0) {
        *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
        if (uVar7 < *(uint *)(param_1 + 0x18)) {
          puVar4 = (uint *)(*(int *)(param_1 + 0x14) + uVar7 * 0x10);
          *puVar4 = *puVar4 | 0x800000;
        }
        else if (uVar7 < **(uint **)(param_1 + 0x1c)) {
          _ipc_splay_tree_bounds(param_1 + 0x20,param_2,&local_8,&local_c);
          bVar2 = false;
          if (((local_8 != 0xffffffff) && (local_8 >> 8 == param_2 >> 8)) ||
             ((local_c != 0 && (local_c >> 8 == param_2 >> 8)))) {
            bVar2 = true;
          }
          if (!bVar2) {
            *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
          }
        }
        _ipc_splay_tree_insert(param_1 + 0x20,param_2,puVar8);
        *puVar8 = 0;
        puVar8[1] = 0;
        puVar8[2] = 0;
        puVar8[5] = param_1;
        *param_3 = (int)puVar8;
        return 0;
      }
      piVar6 = (int *)(param_1 + 8);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      puVar8 = (undefined4 *)_zalloc(_ipc_tree_entry_zone);
      if (puVar8 == (undefined4 *)0x0) {
        return 6;
      }
      do {
        do {
        } while (*piVar6 != 0);
        LOCK();
        iVar5 = *piVar6;
        *piVar6 = 1;
        UNLOCK();
      } while (iVar5 == 1);
    }
    else {
      iVar5 = _ipc_entry_grow_table(param_1);
      if (iVar5 != 0) {
        if (puVar8 != (undefined4 *)0x0) {
          _zfree(_ipc_tree_entry_zone,puVar8);
        }
        return iVar5;
      }
    }
  } while( true );
}

