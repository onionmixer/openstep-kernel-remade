/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c6ec */

void _ipc_port_set_qlimit(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x3c);
  if (uVar1 < param_2) {
    uVar3 = 0;
    if (param_2 != uVar1) {
      do {
        iVar2 = _ipc_thread_dequeue(param_1 + 0x4c);
        if (iVar2 == 0) break;
        *(undefined4 *)(iVar2 + 0x98) = 0;
        _thread_go(iVar2);
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_2 - uVar1);
    }
  }
  *(uint *)(param_1 + 0x3c) = param_2;
  return;
}

