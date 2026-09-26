/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00150860 */

void _ipc_space_destroy(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  
  piVar1 = param_1 + 2;
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  iVar2 = param_1[3];
  param_1[3] = 0;
  piVar1 = param_1 + 2;
  LOCK();
  param_1[2] = 0;
  UNLOCK();
  if (iVar2 != 0) {
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if (param_1[4] != 0) {
      piVar1 = param_1 + 2;
      do {
        _assert_wait(param_1,0);
        LOCK();
        param_1[2] = 0;
        UNLOCK();
        _thread_block_with_continuation(0);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar2 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar2 == 1);
      } while (param_1[4] != 0);
    }
    LOCK();
    param_1[2] = 0;
    UNLOCK();
    puVar4 = (uint *)param_1[5];
    uVar3 = param_1[6];
    uVar7 = 0;
    if (uVar3 != 0) {
      uVar5 = 0;
      puVar6 = puVar4;
      do {
        if ((*puVar6 & 0x1f0000) != 0) {
          _ipc_right_clean(param_1,*puVar6 >> 0x18 | uVar5,puVar6);
        }
        uVar5 = uVar5 + 0x100;
        puVar6 = puVar6 + 4;
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar3);
    }
    _ipc_table_free(*(int *)(param_1[7] + -4) << 4,puVar4);
    puVar4 = (uint *)_ipc_splay_traverse_start(param_1 + 8);
    while (puVar4 != (uint *)0x0) {
      uVar3 = puVar4[4];
      if ((*puVar4 & 0x1f0000) == 0x10000) {
        _ipc_hash_global_delete(param_1,puVar4[1],uVar3,puVar4);
      }
      _ipc_right_clean(param_1,uVar3,puVar4);
      puVar4 = (uint *)_ipc_splay_traverse_next(param_1 + 8,1);
    }
    _ipc_splay_traverse_finish(param_1 + 8);
    iVar2 = param_1[0x11];
    if ((iVar2 != 0) && (iVar2 != -1)) {
      _ipc_port_release_send(iVar2);
    }
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar2 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    iVar2 = param_1[1];
    param_1[1] = iVar2 + -1;
    LOCK();
    *param_1 = 0;
    UNLOCK();
    if (iVar2 == 1) {
      _zfree(_ipc_space_zone,param_1);
    }
  }
  return;
}

