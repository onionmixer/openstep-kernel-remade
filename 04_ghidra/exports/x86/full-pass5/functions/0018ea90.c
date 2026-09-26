/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018ea90 */

void _thread_dup(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x28) + 0x70);
  if (iVar1 == 0) {
    iVar1 = _kalloc(0xe0);
    *(int *)(*(int *)(param_1 + 0x28) + 0x70) = iVar1;
    puVar4 = (undefined4 *)(iVar1 + 0x84);
    puVar3 = &DAT_001d15e0;
    puVar5 = puVar4;
    for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
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
    puVar4 = (undefined4 *)(iVar1 + 0x84);
  }
  iVar1 = *(int *)(*(int *)(param_2 + 0x28) + 0x70);
  if (iVar1 == 0) {
    iVar1 = _kalloc(0xe0);
    *(int *)(*(int *)(param_2 + 0x28) + 0x70) = iVar1;
    puVar3 = (undefined4 *)(iVar1 + 0x84);
    puVar5 = &DAT_001d15e0;
    puVar6 = puVar3;
    for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
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
    puVar3 = (undefined4 *)(iVar1 + 0x84);
  }
  puVar5 = puVar3;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar3[0xb] = (int)*(short *)(*(int *)(*(int *)(param_2 + 0xc) + 0x3c) + 0x30);
  puVar3[9] = 1;
  puVar3[0x10] = puVar3[0x10] & 0xfffffffe;
  return;
}

