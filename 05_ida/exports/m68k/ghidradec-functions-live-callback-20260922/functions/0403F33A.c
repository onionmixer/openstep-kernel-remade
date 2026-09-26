
void _ipc_mqueue_changed(int param_1,undefined4 param_2)

{
  int iVar1;
  
  while( true ) {
    iVar1 = _ipc_thread_dequeue(param_1 + 4);
    if (iVar1 == 0) break;
    *(undefined4 *)(iVar1 + 0x94) = param_2;
    _thread_go(iVar1);
  }
  return;
}

