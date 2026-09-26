/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001593e4 */

undefined4 _ipc_task_init(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  iVar2 = _ipc_space_create(_ipc_table_entries,&local_8);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_task_init_001decc4);
  }
  iVar2 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 100) = 0;
    *(int *)(param_1 + 0x68) = iVar2;
    uVar3 = _ipc_port_make_send(iVar2);
    *(undefined4 *)(param_1 + 0x6c) = uVar3;
    *(undefined4 *)(param_1 + 0x88) = local_8;
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x70) = 0;
      *(undefined4 *)(param_1 + 0x74) = 0;
      iVar2 = 3;
      do {
        *(undefined4 *)(param_1 + 0x78 + iVar2 * 4) = 0;
        iVar2 = iVar2 + -1;
      } while (-1 < iVar2);
    }
    else {
      piVar1 = (int *)(param_2 + 100);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      iVar2 = 0;
      do {
        uVar3 = _ipc_port_copy_send(*(undefined4 *)(param_2 + 0x78 + iVar2 * 4));
        *(undefined4 *)(param_1 + 0x78 + iVar2 * 4) = uVar3;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 4);
      uVar3 = _ipc_port_copy_send(*(undefined4 *)(param_2 + 0x70));
      *(undefined4 *)(param_1 + 0x70) = uVar3;
      uVar3 = _ipc_port_copy_send(*(undefined4 *)(param_2 + 0x74));
      *(undefined4 *)(param_1 + 0x74) = uVar3;
      LOCK();
      uVar3 = *(undefined4 *)(param_2 + 100);
      *(undefined4 *)(param_2 + 100) = 0;
      UNLOCK();
    }
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_ipc_task_init_001decd2);
}

