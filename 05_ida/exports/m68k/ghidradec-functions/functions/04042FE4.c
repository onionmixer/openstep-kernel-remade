
void _ipc_space_destroy(int param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  if (iVar1 != 0) {
    iVar1 = *(int *)(param_1 + 8);
    while (iVar1 != 0) {
      _assert_wait(param_1,0);
      _thread_block_with_continuation(0);
      iVar1 = *(int *)(param_1 + 8);
    }
    puVar3 = *(uint **)(param_1 + 0xc);
    uVar2 = *(uint *)(param_1 + 0x10);
    uVar4 = 0;
    puVar5 = puVar3;
    if (uVar2 != 0) {
      do {
        if ((*puVar5 & 0x1f0000) != 0) {
          _ipc_right_clean(param_1,*puVar5 >> 0x18 | uVar4 << 8,puVar5);
        }
        uVar4 = uVar4 + 1;
        puVar5 = puVar5 + 4;
      } while (uVar4 < uVar2);
    }
    _ipc_table_free(*(int *)(*(int *)(param_1 + 0x14) + -4) << 4,puVar3);
    puVar3 = (uint *)_ipc_splay_traverse_start(param_1 + 0x18);
    while (puVar3 != (uint *)0x0) {
      uVar2 = puVar3[4];
      if ((*puVar3 & 0x1f0000) == 0x10000) {
        _ipc_hash_global_delete(param_1,puVar3[1],uVar2,puVar3);
      }
      _ipc_right_clean(param_1,uVar2,puVar3);
      puVar3 = (uint *)_ipc_splay_traverse_next(param_1 + 0x18,1);
    }
    _ipc_splay_traverse_finish(param_1 + 0x18);
    iVar1 = *(int *)(param_1 + 0x3c);
    if ((iVar1 != 0) && (iVar1 != -1)) {
      _ipc_port_release_send(iVar1);
    }
    _ipc_space_release(param_1);
  }
  return;
}
