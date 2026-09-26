/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00186fdc */

void _catch_interrupt(int param_1)

{
  int *piVar1;
  int iVar2;
  
  _intr_handler(param_1);
  if (((*(byte *)(param_1 + 0x42) & 2) != 0) || ((*(byte *)(param_1 + 0x3c) & 3) == 3)) {
    piVar1 = *(int **)(*(int *)(_active_threads + 0x28) + 0xec);
    iVar2 = 0;
    if (piVar1 != (int *)0x0) {
      iVar2 = *piVar1;
    }
    if ((iVar2 == 0) || (7 < *(uint *)(iVar2 + 0x84))) {
      iVar2 = 0;
    }
    else {
      iVar2 = iVar2 + 0x88 + *(uint *)(iVar2 + 0x84) * 0x84;
    }
    if ((iVar2 != 0) &&
       (((*(int *)(iVar2 + 0x78) != 0 || (*(int *)(iVar2 + 0x74) != 0)) &&
        (*(int *)(iVar2 + 0x48) != 0)))) {
      _PCcallMonitor(_active_threads,param_1);
    }
    _check_for_ast(param_1);
  }
  return;
}

