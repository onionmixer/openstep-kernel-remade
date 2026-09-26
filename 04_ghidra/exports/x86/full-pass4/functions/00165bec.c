/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00165bec */

void _task_deallocate(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
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
      iVar2 = param_1[0xb];
      piVar1 = (int *)(iVar2 + 0x158);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      _pset_remove_task(iVar2,param_1);
      LOCK();
      *(undefined4 *)(iVar2 + 0x158) = 0;
      UNLOCK();
      _pset_deallocate(iVar2);
      _vm_map_deallocate(param_1[3]);
      _ipc_space_release(param_1[0x22]);
      _pcb_common_terminate(param_1);
      _utask_free(param_1[0xe]);
      _zfree(_task_zone,param_1);
    }
  }
  return;
}

