/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b02d0 */

int FUN_001b02d0(int param_1)

{
  undefined2 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 *local_10;
  uint local_c;
  int local_8;
  
  *(undefined2 *)(param_1 + 0x1a8) = 100;
  *(undefined2 *)(param_1 + 0x1aa) = 100;
  piVar2 = *(int **)(param_1 + 0x15c);
  *piVar2 = 8;
  piVar2[1] = *piVar2 + 0xe10;
  puVar1 = (undefined2 *)(*piVar2 + *(int *)(param_1 + 0x15c));
  *(int *)(param_1 + 0x164) = *(int *)(param_1 + 0x15c) + piVar2[1];
  *(undefined1 *)((int)puVar1 + 0x49) = 1;
  *(undefined1 *)(puVar1 + 0x25) = 1;
  puVar1[0x26] = 0x47;
  *(undefined4 *)(param_1 + 0x1e4) = 75000000;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1d4) = 300000000;
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  *(undefined4 *)(param_1 + 0x1dc) = 0;
  *(undefined4 *)(param_1 + 0x1e0) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 0x16c) = 0x50;
  iVar3 = 0x4f;
  local_10 = puVar1 + 0x6ca;
  iVar4 = 0xd94;
  do {
    *(undefined4 *)(iVar4 + 0x58 + (int)puVar1) = 0;
    *(undefined4 *)(iVar4 + 100 + (int)puVar1) = 0;
    *(undefined4 *)(iVar4 + 0x68 + (int)puVar1) = 0;
    *(undefined4 *)(local_10 + 0x2a) = 0;
    *(int *)(iVar4 + 0x50 + (int)puVar1) = iVar3 + 1;
    local_10 = local_10 + -0x16;
    iVar4 = iVar4 + -0x2c;
    iVar3 = iVar3 + -1;
  } while (iVar3 != -1);
  puVar1[2] = 0;
  *(undefined4 *)(puVar1 + (*(int *)(param_1 + 0x16c) + -1) * 0x16 + 0x28) = 0;
  *puVar1 = (short)*(undefined4 *)(puVar1 + (short)puVar1[2] * 0x16 + 0x28);
  puVar1[1] = (short)*(undefined4 *)(puVar1 + (short)puVar1[2] * 0x16 + 0x28);
  *(undefined4 *)(puVar1 + 4) = 0;
  puVar1[3] = 0xd;
  *(undefined4 *)(puVar1 + 6) = 0;
  _IOGetTimestamp(&local_c);
  uVar5 = local_c >> 0x18 | local_8 << 8;
  if (uVar5 == 0) {
    uVar5 = 1;
  }
  *(uint *)(puVar1 + 8) = uVar5;
  *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_1 + 0x1a8);
  *(byte *)((int)puVar1 + 0x33) = *(byte *)((int)puVar1 + 0x33) & 0xbf;
  *(byte *)((int)puVar1 + 0x33) = *(byte *)((int)puVar1 + 0x33) & 0xdf;
  *(byte *)((int)puVar1 + 0x33) = *(byte *)((int)puVar1 + 0x33) & 0xf7;
  *(byte *)((int)puVar1 + 0x33) = *(byte *)((int)puVar1 + 0x33) & 0xef;
  *(byte *)((int)puVar1 + 0x33) = *(byte *)((int)puVar1 + 0x33) & 0x7f;
  *(undefined4 *)(puVar1 + 0x1a) = 0;
  *(undefined4 *)(puVar1 + 10) = 0;
  *(undefined4 *)(puVar1 + 0x20) = 0;
  *(undefined2 **)(param_1 + 0x168) = puVar1;
  *(undefined1 *)(param_1 + 0x1d2) = 1;
  return param_1;
}

