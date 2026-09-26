
void _ipc_mqueue_move(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_2;
joined_r0x0403f2b4:
  do {
    do {
      iVar1 = iVar2;
      if (iVar1 == 0) {
        return;
      }
      iVar2 = _ipc_kmsg_queue_next(param_2,iVar1);
    } while (param_3 != *(int *)(iVar1 + 0x1c));
    _ipc_kmsg_rmqueue(param_2,iVar1);
    while (iVar3 = _ipc_thread_dequeue(param_1 + 4), iVar3 != 0) {
      _thread_go(iVar3);
      if (*(uint *)(iVar1 + 0x18) <= *(uint *)(iVar3 + 0x98)) {
        *(undefined4 *)(iVar3 + 0x94) = 0;
        *(int *)(iVar3 + 0x98) = iVar1;
        *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(param_3 + 0x30);
        *(int *)(param_3 + 0x30) = *(int *)(param_3 + 0x30) + 1;
        goto joined_r0x0403f2b4;
      }
      *(undefined4 *)(iVar3 + 0x94) = 0x10004004;
      *(undefined4 *)(iVar3 + 0x98) = *(undefined4 *)(iVar1 + 0x18);
    }
    _ipc_kmsg_enqueue(param_1,iVar1);
  } while( true );
}
