/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018df80 */

void _thread_syscall_return(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar1 = _active_threads;
  iVar2 = *(int *)(*(int *)(_active_threads + 0x28) + 0x70);
  if (iVar2 == 0) {
    iVar2 = _kalloc(0xe0);
    *(int *)(*(int *)(iVar1 + 0x28) + 0x70) = iVar2;
    puVar5 = (undefined4 *)(iVar2 + 0x84);
    puVar4 = &DAT_001d15e0;
    puVar6 = puVar5;
    for (iVar3 = 0x17; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    *(undefined4 *)(iVar2 + 0xc4) = 0x200;
    *(undefined2 *)(iVar2 + 0xc0) = 99;
    *(undefined2 *)(iVar2 + 0xcc) = 0x6b;
    *(undefined2 *)(iVar2 + 0x90) = 0x6b;
    *(undefined2 *)(iVar2 + 0x8c) = 0x6b;
    *(undefined2 *)(iVar2 + 0x88) = 0;
    *(undefined2 *)(iVar2 + 0x84) = 0;
  }
  else {
    puVar5 = (undefined4 *)(iVar2 + 0x84);
  }
  puVar5[0xb] = param_1;
  _check_for_ast(puVar5);
  if ((*(byte *)((int)puVar5 + 0x42) & 2) == 0) {
    puVar4 = puVar5 + 0x13;
  }
  else {
    puVar4 = puVar5 + 0x17;
  }
  *(undefined4 **)(**(int **)(iVar1 + 0x28) + 4) = puVar4;
  __return_with_state(puVar5);
  return;
}

