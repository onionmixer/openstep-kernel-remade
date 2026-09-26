/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a030 */

kern_return_t
_mach_ports_register
          (task_t target_task,mach_port_array_t init_port_set,
          mach_msg_type_number_t init_port_setCnt)

{
  int *piVar1;
  mach_port_t mVar2;
  uint uVar3;
  int iVar4;
  mach_port_t amStack_14 [4];
  
  if ((target_task != 0) && (init_port_setCnt < 5)) {
    uVar3 = 0;
    if (init_port_setCnt != 0) {
      do {
        amStack_14[uVar3] = init_port_set[uVar3];
        uVar3 = uVar3 + 1;
      } while (uVar3 < init_port_setCnt);
    }
    for (; (int)uVar3 < 4; uVar3 = uVar3 + 1) {
      amStack_14[uVar3] = 0;
    }
    piVar1 = (int *)(target_task + 100);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    if (*(int *)(target_task + 0x68) != 0) {
      iVar4 = 0;
      do {
        mVar2 = *(mach_port_t *)(target_task + 0x78 + iVar4 * 4);
        *(mach_port_t *)(target_task + 0x78 + iVar4 * 4) = amStack_14[iVar4];
        amStack_14[iVar4] = mVar2;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
      LOCK();
      *(undefined4 *)(target_task + 100) = 0;
      UNLOCK();
      iVar4 = 0;
      do {
        mVar2 = amStack_14[iVar4];
        if ((mVar2 != 0) && (mVar2 != 0xffffffff)) {
          _ipc_port_release_send(mVar2);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
      if (init_port_setCnt != 0) {
        _kfree(init_port_set,init_port_setCnt * 4);
      }
      return 0;
    }
    LOCK();
    *(undefined4 *)(target_task + 100) = 0;
    UNLOCK();
  }
  return 4;
}

