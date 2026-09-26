/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014a49c */

void _ipc_marequest_destroy(uint *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  
  uVar3 = *param_1;
  iVar8 = 0;
  piVar1 = (int *)(uVar3 + 8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  uVar7 = param_1[1];
  uVar4 = param_1[2];
  if (uVar7 != 0) {
    piVar1 = (int *)(_ipc_marequest_table +
                    ((uVar3 >> 4) + (uVar7 >> 8) + (uVar7 & 0xff) & _ipc_marequest_mask) * 8);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    puVar6 = (uint *)(piVar1 + 1);
    for (puVar5 = (uint *)piVar1[1];
        (puVar5 != (uint *)0x0 && ((*puVar5 != uVar3 || (puVar5[1] != uVar7))));
        puVar5 = (uint *)puVar5[3]) {
      puVar6 = puVar5 + 3;
    }
    *puVar6 = puVar5[3];
    LOCK();
    *piVar1 = 0;
    UNLOCK();
    if (*(int *)(uVar3 + 0xc) == 0) {
      uVar7 = 0;
    }
    else {
      puVar6 = (uint *)_ipc_entry_lookup(uVar3,uVar7);
      *puVar6 = *puVar6 & 0xffdfffff;
      if (uVar4 == 0) {
        iVar8 = _ipc_port_copy_send(*(undefined4 *)(uVar3 + 0x44));
      }
    }
  }
  LOCK();
  *(undefined4 *)(uVar3 + 8) = 0;
  UNLOCK();
  _ipc_space_release(uVar3);
  _zfree(_ipc_marequest_zone,param_1);
  if (uVar4 == 0) {
    if ((iVar8 != 0) && (iVar8 != -1)) {
      _ipc_notify_msg_accepted_compat(iVar8,uVar7);
    }
  }
  else {
    _ipc_notify_msg_accepted(uVar4,uVar7);
  }
  return;
}

