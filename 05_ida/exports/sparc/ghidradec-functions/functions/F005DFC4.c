
/* WARNING: Removing unreachable block (ram,0xf005e18c) */
/* WARNING: Removing unreachable block (ram,0xf005e158) */
/* WARNING: Removing unreachable block (ram,0xf005e13c) */
/* WARNING: Removing unreachable block (ram,0xf005e0f8) */
/* WARNING: Removing unreachable block (ram,0xf005e068) */
/* WARNING: Removing unreachable block (ram,0xf005e044) */
/* WARNING: Removing unreachable block (ram,0xf005e01c) */
/* WARNING: Removing unreachable block (ram,0xf005e050) */
/* WARNING: Removing unreachable block (ram,0xf005e0d4) */
/* WARNING: Removing unreachable block (ram,0xf005e100) */
/* WARNING: Removing unreachable block (ram,0xf005e14c) */
/* WARNING: Removing unreachable block (ram,0xf005e16c) */
/* WARNING: Removing unreachable block (ram,0xf005e194) */
/* WARNING: Removing unreachable block (ram,0xf005dfdc) */

undefined8 _ipc_space_destroy(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
  uint uVar5;
  undefined4 unaff_l3;
  uint *puVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  do {
    do {
    } while (*(int *)(param_1 + 8) != 0);
    piVar1 = (int *)(param_1 + 8);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  iVar2 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (iVar2 != 0) {
    do {
      do {
      } while (*(int *)(param_1 + 8) != 0);
      piVar1 = (int *)(param_1 + 8);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (*(int *)(param_1 + 0x10) != 0) {
      do {
        _assert_wait(param_1,0);
        *(undefined4 *)(param_1 + 8) = 0;
        _thread_block_with_continuation(0);
        do {
          do {
          } while (*(int *)(param_1 + 8) != 0);
          piVar1 = (int *)(param_1 + 8);
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
      } while (*(int *)(param_1 + 0x10) != 0);
    }
    *(undefined4 *)(param_1 + 8) = 0;
    uVar5 = *(uint *)(param_1 + 0x18);
    uVar4 = 0;
    puVar6 = *(uint **)(param_1 + 0x14);
    puVar3 = puVar6;
    if (uVar5 != 0) {
      do {
        if ((*puVar3 & 0x1f0000) != 0) {
          _ipc_right_clean(param_1,uVar4 << 8 | *puVar3 >> 0x18,puVar3);
        }
        uVar4 = uVar4 + 1;
        puVar3 = puVar3 + 4;
      } while (uVar4 < uVar5);
    }
    _ipc_table_free(*(int *)(*(int *)(param_1 + 0x1c) + -4) << 4,puVar6);
    puVar3 = (uint *)(param_1 + 0x20);
    _ipc_splay_traverse_start();
    if (puVar3 != (uint *)0x0) {
      uVar4 = *puVar3;
      while( true ) {
        uVar5 = puVar3[4];
        if ((uVar4 & 0x1f0000) == 0x10000) {
          _ipc_hash_global_delete(param_1,puVar3[1],uVar5,puVar3);
        }
        _ipc_right_clean(param_1,uVar5,puVar3);
        puVar3 = (uint *)(param_1 + 0x20);
        _ipc_splay_traverse_next(puVar3,1);
        if (puVar3 == (uint *)0x0) break;
        uVar4 = *puVar3;
      }
    }
    _ipc_splay_traverse_finish(param_1 + 0x20);
    if ((*(int *)(param_1 + 0x44) != 0) && (*(int *)(param_1 + 0x44) != -1)) {
      _ipc_port_release_send();
    }
    _ipc_space_release(param_1);
  }
  return CONCAT44(param_2,param_1);
}
