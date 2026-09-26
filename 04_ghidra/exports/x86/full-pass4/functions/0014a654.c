/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014a654 */

void _ipc_mqueue_move(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_2 + 4);
joined_r0x0014a67d:
  do {
    do {
      iVar1 = iVar2;
      if (iVar1 == 0) {
        return;
      }
      iVar2 = _ipc_kmsg_queue_next(param_2 + 4,iVar1);
    } while (*(int *)(iVar1 + 0x1c) != param_3);
    _ipc_kmsg_rmqueue(param_2 + 4,iVar1);
    while (iVar3 = _ipc_thread_dequeue(param_1 + 8), iVar3 != 0) {
      _thread_go(iVar3);
      if (*(uint *)(iVar1 + 0x18) <= *(uint *)(iVar3 + 0x9c)) {
        *(undefined4 *)(iVar3 + 0x98) = 0;
        *(int *)(iVar3 + 0x9c) = iVar1;
        *(undefined4 *)(iVar3 + 0xa0) = *(undefined4 *)(param_3 + 0x34);
        *(int *)(param_3 + 0x34) = *(int *)(param_3 + 0x34) + 1;
        goto joined_r0x0014a67d;
      }
      *(undefined4 *)(iVar3 + 0x98) = 0x10004004;
      *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(iVar1 + 0x18);
    }
    _ipc_kmsg_enqueue(param_1 + 4,iVar1);
  } while( true );
}

