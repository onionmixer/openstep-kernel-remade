/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014cb80 */

void _ipc_port_destroy(int *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint *local_1c;
  uint local_18;
  int local_8;
  
  uVar6 = param_1[10];
  if (uVar6 != 0) {
    param_1[10] = 0;
    param_1[4] = 0;
    param_1[3] = 0;
    LOCK();
    *param_1 = 0;
    UNLOCK();
    if ((uVar6 & 1) == 0) {
      iVar5 = _ipc_port_check_circularity(param_1,uVar6);
      if (iVar5 == 0) {
        _ipc_notify_port_destroyed(uVar6,param_1);
        return;
      }
      _ipc_port_release_sonce(uVar6);
    }
    else {
      uVar6 = uVar6 & 0xfffffffe;
      iVar5 = _ipc_port_check_circularity(param_1,uVar6);
      if (iVar5 == 0) {
        _ipc_notify_port_destroyed_compat(uVar6,param_1);
        return;
      }
      _ipc_port_release_send(uVar6);
    }
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar5 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar5 == 1);
  }
  while (iVar5 = _ipc_thread_dequeue(param_1 + 0x13), iVar5 != 0) {
    *(undefined4 *)(iVar5 + 0x98) = 0;
    _thread_go(iVar5);
  }
  param_1[2] = param_1[2] & 0x7fffffff;
  iVar5 = _ipc_port_timestamp_data;
  do {
  } while (_ipc_port_timestamp_lock_data != 0);
  LOCK();
  UNLOCK();
  _ipc_port_timestamp_data = _ipc_port_timestamp_data + 1;
  LOCK();
  _ipc_port_timestamp_lock_data = 0;
  UNLOCK();
  param_1[3] = iVar5;
  LOCK();
  *param_1 = 0;
  UNLOCK();
  if (param_1[9] != 0) {
    _ipc_notify_send_once(param_1[9]);
  }
  piVar7 = param_1 + 0x10;
  do {
    do {
    } while (*piVar7 != 0);
    LOCK();
    iVar5 = *piVar7;
    *piVar7 = 1;
    UNLOCK();
  } while (iVar5 == 1);
  while (iVar5 = _ipc_kmsg_dequeue(param_1 + 0x11), iVar5 != 0) {
    LOCK();
    *piVar7 = 0;
    UNLOCK();
    _ipc_object_release(param_1);
    *(undefined4 *)(iVar5 + 0x1c) = 0;
    _ipc_kmsg_destroy(iVar5);
    do {
      do {
      } while (*piVar7 != 0);
      LOCK();
      iVar5 = *piVar7;
      *piVar7 = 1;
      UNLOCK();
    } while (iVar5 == 1);
  }
  LOCK();
  *piVar7 = 0;
  UNLOCK();
  puVar1 = (uint *)param_1[0xb];
  if (puVar1 != (uint *)0x0) {
    puVar2 = (uint *)puVar1[1];
    uVar6 = *puVar2;
    local_18 = 1;
    puVar4 = puVar1;
    if (1 < uVar6) {
      do {
        local_1c = puVar4 + 2;
        uVar3 = puVar4[3];
        if (uVar3 != 0) {
          uVar8 = *local_1c;
          if ((uVar8 & 1) == 0) {
            _ipc_notify_dead_name(uVar8,uVar3);
          }
          else {
            uVar8 = uVar8 & 0xfffffffe;
            iVar5 = _ipc_right_lookup_write(uVar8,uVar3,&local_8);
            if (iVar5 == 0) {
              if (*(int **)(local_8 + 4) == param_1) {
                iVar5 = _ipc_port_copy_send(*(undefined4 *)(uVar8 + 0x44));
                _ipc_right_destroy(uVar8,uVar3,local_8);
              }
              else {
                LOCK();
                *(undefined4 *)(uVar8 + 8) = 0;
                UNLOCK();
                iVar5 = 0;
              }
              if ((iVar5 != 0) && (iVar5 != -1)) {
                _ipc_notify_port_deleted_compat(iVar5,uVar3);
              }
            }
            _ipc_space_release(uVar8);
          }
        }
        local_18 = local_18 + 1;
        puVar4 = local_1c;
      } while (local_18 < uVar6);
    }
    _ipc_table_free(*puVar2 * 8,puVar1);
  }
  if ((short)param_1[2] != 0) {
    _ipc_kobject_destroy(param_1);
  }
  _ipc_object_release(param_1);
  return;
}

