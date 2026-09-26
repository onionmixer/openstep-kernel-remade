
/* WARNING: Removing unreachable block (ram,0xf0054484) */
/* WARNING: Removing unreachable block (ram,0xf0054410) */
/* WARNING: Removing unreachable block (ram,0xf00543f8) */
/* WARNING: Removing unreachable block (ram,0xf00543cc) */
/* WARNING: Removing unreachable block (ram,0xf0054390) */
/* WARNING: Removing unreachable block (ram,0xf0054360) */
/* WARNING: Removing unreachable block (ram,0xf00542e0) */
/* WARNING: Removing unreachable block (ram,0xf00542c8) */
/* WARNING: Removing unreachable block (ram,0xf0054288) */
/* WARNING: Removing unreachable block (ram,0xf0054214) */
/* WARNING: Removing unreachable block (ram,0xf00541bc) */
/* WARNING: Removing unreachable block (ram,0xf005417c) */
/* WARNING: Removing unreachable block (ram,0xf0054134) */
/* WARNING: Removing unreachable block (ram,0xf00540a8) */
/* WARNING: Removing unreachable block (ram,0xf0054154) */
/* WARNING: Removing unreachable block (ram,0xf00541a8) */
/* WARNING: Removing unreachable block (ram,0xf00541d4) */
/* WARNING: Removing unreachable block (ram,0xf005424c) */
/* WARNING: Removing unreachable block (ram,0xf00542b4) */
/* WARNING: Removing unreachable block (ram,0xf00542d8) */
/* WARNING: Removing unreachable block (ram,0xf005434c) */
/* WARNING: Removing unreachable block (ram,0xf0054378) */
/* WARNING: Removing unreachable block (ram,0xf00543a0) */
/* WARNING: Removing unreachable block (ram,0xf00543e4) */
/* WARNING: Removing unreachable block (ram,0xf0054404) */
/* WARNING: Removing unreachable block (ram,0xf0054470) */
/* WARNING: Removing unreachable block (ram,0xf005449c) */
/* WARNING: Removing unreachable block (ram,0xf0054124) */
/* WARNING: Removing unreachable block (ram,0xf005408c) */
/* WARNING: Removing unreachable block (ram,0xf0054080) */

undefined8 _ipc_entry_grow_table(int param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  undefined4 unaff_l1;
  uint *puVar10;
  uint *puVar11;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar12;
  undefined4 unaff_l5;
  uint uVar13;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined *puVar14;
  undefined4 unaff_i0;
  undefined4 uVar15;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  uint uVar16;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  puVar14 = (undefined *)((int)register0x00000038 + -0x50);
  iVar1 = *(int *)(param_1 + 0x10);
  do {
    if (iVar1 != 0) {
      _assert_wait(param_1,0);
      *(undefined4 *)(param_1 + 8) = 0;
      _thread_block_with_continuation(0);
      do {
        do {
        } while (*(int *)(param_1 + 8) != 0);
        piVar2 = (int *)(param_1 + 8);
        _simple_lock_try();
        uVar15 = 0;
      } while (piVar2 == (int *)0x0);
locret_F00544F8:
      return CONCAT44(param_2,uVar15);
    }
    puVar10 = *(uint **)(param_1 + 0x1c);
    uVar15 = *(undefined4 *)(param_1 + 0x14);
    uVar13 = *puVar10;
    param_2 = puVar10 + -1;
    uVar12 = puVar10[-1];
    uVar16 = puVar10[1];
    if (uVar12 == uVar13) {
      *(undefined4 *)(param_1 + 8) = 0;
      uVar15 = 3;
      goto locret_F00544F8;
    }
    *(undefined4 *)(param_1 + 0x10) = 1;
    *(undefined4 *)(param_1 + 8) = 0;
    puVar4 = (uint *)(puVar10[-1] << 4);
    if (puVar4 < _page_size) {
      puVar4 = (uint *)(*puVar10 << 4);
      _ipc_table_alloc();
    }
    else {
      _ipc_table_realloc(puVar4,uVar15,*puVar10 << 4);
    }
    do {
      do {
      } while (*(int *)(param_1 + 8) != 0);
      piVar2 = (int *)(param_1 + 8);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x10) = 0;
    if (puVar4 == (uint *)0x0) {
      *(undefined4 *)(param_1 + 8) = 0;
      _thread_wakeup_prim(param_1,0,0);
      uVar15 = 6;
      goto locret_F00544F8;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
      *(undefined4 *)(param_1 + 8) = 0;
      _thread_wakeup_prim(param_1,0,0);
      _ipc_table_free(*puVar10 << 4,puVar4);
      do {
        do {
        } while (*(int *)(param_1 + 8) != 0);
        piVar2 = (int *)(param_1 + 8);
        _simple_lock_try();
        uVar15 = 0;
      } while (piVar2 == (int *)0x0);
      goto locret_F00544F8;
    }
    *(uint **)(param_1 + 0x14) = puVar4;
    *(uint *)(param_1 + 0x18) = uVar13;
    *(uint **)(param_1 + 0x1c) = puVar10 + 1;
    if ((uint *)(*param_2 << 4) < _page_size) {
      _bcopy(uVar15,puVar4,uVar12 << 4);
    }
    uVar7 = 0;
    puVar8 = puVar4;
    if (uVar12 != 0) {
      do {
        puVar8[3] = 0;
        uVar7 = uVar7 + 1;
        puVar8 = puVar8 + 4;
      } while (uVar7 < uVar12);
    }
    _bzero(puVar4 + uVar12 * 4,(uVar13 - uVar12) * 0x10);
    uVar7 = 0;
    puVar8 = puVar4;
    if (uVar12 == 0) {
      iVar1 = *(int *)(param_1 + 0x38);
    }
    else {
      do {
        if ((*puVar8 & 0x1f0000) == 0x10000) {
          _ipc_hash_local_insert(param_1,puVar8[1],uVar7,puVar8);
        }
        uVar7 = uVar7 + 1;
        puVar8 = puVar8 + 4;
      } while (uVar7 < uVar12);
      iVar1 = *(int *)(param_1 + 0x38);
    }
    if (iVar1 != 0) {
      _ipc_splay_tree_split(param_1 + 0x20,uVar16 << 8,puVar14);
      puVar8 = (uint *)((int)register0x00000038 + -0x38);
      _ipc_splay_tree_split(puVar14,uVar13 << 8,puVar8);
      _ipc_splay_tree_split(puVar8,uVar12 << 8,(undefined *)((int)register0x00000038 + -0x20));
      _ipc_splay_traverse_start();
      while (puVar8 != (uint *)0x0) {
        uVar7 = puVar8[4] >> 8;
        puVar11 = puVar4 + uVar7 * 4;
        if (puVar4[uVar7 * 4] == 0) {
          uVar6 = *puVar8;
          puVar4[uVar7 * 4] = uVar6 | puVar8[4] << 0x18;
          uVar9 = puVar8[1];
          puVar11[1] = uVar9;
          puVar11[2] = puVar8[2];
          if ((uVar6 & 0x1f0000) == 0x10000) {
            _ipc_hash_global_delete(param_1,uVar9);
            _ipc_hash_local_insert(param_1,uVar9,uVar7,puVar11);
          }
          uVar5 = 1;
          *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
        }
        else {
          puVar4[uVar7 * 4] = puVar4[uVar7 * 4] | 0x800000;
          uVar5 = 0;
        }
        puVar8 = (uint *)((int)register0x00000038 + -0x38);
        _ipc_splay_traverse_next(puVar8,uVar5);
      }
      _ipc_splay_traverse_finish((undefined *)((int)register0x00000038 + -0x38));
      iVar1 = 0;
      uVar7 = 0;
      puVar3 = (undefined *)((int)register0x00000038 + -0x50);
      _ipc_splay_traverse_start();
      while (puVar3 != (undefined *)0x0) {
        if (*(uint *)(puVar3 + 0x10) >> 8 != uVar7) {
          iVar1 = iVar1 + 1;
          uVar7 = *(uint *)(puVar3 + 0x10) >> 8;
        }
        puVar3 = (undefined *)((int)register0x00000038 + -0x50);
        _ipc_splay_traverse_next(puVar3,0);
      }
      _ipc_splay_traverse_finish(puVar14);
      *(int *)(param_1 + 0x3c) = iVar1;
      iVar1 = param_1 + 0x20;
      _ipc_splay_tree_join(iVar1,puVar14);
      _ipc_splay_tree_join(iVar1,(undefined *)((int)register0x00000038 + -0x38));
      _ipc_splay_tree_join(iVar1,(undefined *)((int)register0x00000038 + -0x20));
    }
    uVar6 = uVar13 - 1;
    uVar7 = puVar4[2];
    if (uVar12 <= uVar6) {
      puVar8 = puVar4 + uVar6 * 4;
      do {
        if (*puVar8 == 0) {
          *puVar8 = 0xff000000;
          puVar8[2] = uVar7;
          uVar7 = uVar6;
        }
        uVar6 = uVar6 - 1;
        puVar8 = puVar8 + -4;
      } while (uVar12 <= uVar6);
    }
    puVar4[2] = uVar7;
    *(undefined4 *)(param_1 + 8) = 0;
    _thread_wakeup_prim(param_1,0,0);
    _ipc_table_free(*param_2 << 4,uVar15);
    do {
      do {
      } while (*(int *)(param_1 + 8) != 0);
      piVar2 = (int *)(param_1 + 8);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    if (*(int *)(param_1 + 0xc) == 0) {
      uVar15 = 0;
      goto locret_F00544F8;
    }
    if (*(uint **)(param_1 + 0x1c) != puVar10 + 1) {
      uVar15 = 0;
      goto locret_F00544F8;
    }
    if ((*(int *)(param_1 + 0x3c) == 0) ||
       ((uint)(*(int *)(param_1 + 0x3c) << 5) <= (uVar16 - uVar13) * 0x10)) {
      uVar15 = 0;
      goto locret_F00544F8;
    }
    iVar1 = *(int *)(param_1 + 0x10);
  } while( true );
}

