/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018e510 */

void FUN_0018e510(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x28) + 0x70);
  if (iVar2 == 0) {
    iVar2 = _kalloc(0xe0);
    *(int *)(*(int *)(param_1 + 0x28) + 0x70) = iVar2;
    puVar4 = (undefined4 *)(iVar2 + 0x84);
    puVar5 = &DAT_001d15e0;
    puVar6 = puVar4;
    for (iVar3 = 0x17; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
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
    puVar4 = (undefined4 *)(iVar2 + 0x84);
  }
  puVar4[0xb] = *param_2;
  puVar4[8] = param_2[1];
  puVar4[10] = param_2[2];
  puVar4[9] = param_2[3];
  puVar4[4] = param_2[4];
  puVar4[5] = param_2[5];
  puVar4[6] = param_2[6];
  puVar4[0x11] = param_2[7];
  *(undefined2 *)(puVar4 + 0x12) = *(undefined2 *)(param_2 + 8);
  uVar1 = param_2[9];
  puVar4[0x10] = uVar1;
  puVar4[0x10] = uVar1 & 0x70fd7 | 0x20202;
  puVar4[0xe] = param_2[10];
  *(undefined2 *)(puVar4 + 0xf) = *(undefined2 *)(param_2 + 0xb);
  *(undefined2 *)(puVar4 + 3) = 0;
  *(undefined2 *)(puVar4 + 2) = 0;
  *(undefined2 *)(puVar4 + 1) = 0;
  *(undefined2 *)puVar4 = 0;
  *(undefined2 *)(puVar4 + 0x14) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)(puVar4 + 0x13) = *(undefined2 *)(param_2 + 0xd);
  *(undefined2 *)(puVar4 + 0x15) = *(undefined2 *)(param_2 + 0xe);
  *(undefined2 *)(puVar4 + 0x16) = *(undefined2 *)(param_2 + 0xf);
  return;
}

