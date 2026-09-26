/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018dc54 */

undefined4 * _thread_user_state(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x28) + 0x70);
  if (iVar1 == 0) {
    iVar1 = _kalloc(0xe0);
    *(int *)(*(int *)(param_1 + 0x28) + 0x70) = iVar1;
    puVar2 = (undefined4 *)(iVar1 + 0x84);
    puVar4 = &DAT_001d15e0;
    puVar5 = puVar2;
    for (iVar3 = 0x17; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    *(undefined4 *)(iVar1 + 0xc4) = 0x200;
    *(undefined2 *)(iVar1 + 0xc0) = 99;
    *(undefined2 *)(iVar1 + 0xcc) = 0x6b;
    *(undefined2 *)(iVar1 + 0x90) = 0x6b;
    *(undefined2 *)(iVar1 + 0x8c) = 0x6b;
    *(undefined2 *)(iVar1 + 0x88) = 0;
    *(undefined2 *)(iVar1 + 0x84) = 0;
  }
  else {
    puVar2 = (undefined4 *)(iVar1 + 0x84);
  }
  return puVar2;
}

