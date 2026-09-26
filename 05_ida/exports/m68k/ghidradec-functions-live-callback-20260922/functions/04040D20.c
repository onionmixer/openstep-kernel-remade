
void _ipc_port_set_qlimit(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x38);
  if (uVar1 < param_2) {
    uVar3 = 0;
    if (param_2 != uVar1) {
      do {
        iVar2 = _ipc_thread_dequeue(param_1 + 0x44);
        if (iVar2 == 0) break;
        *(undefined4 *)(iVar2 + 0x94) = 0;
        _thread_go(iVar2);
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_2 - uVar1);
    }
  }
  *(uint *)(param_1 + 0x38) = param_2;
  return;
}

