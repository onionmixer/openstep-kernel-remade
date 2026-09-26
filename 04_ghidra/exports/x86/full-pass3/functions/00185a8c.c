/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00185a8c */

void _kdp_getstate(undefined4 *param_1)

{
  ushort *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = DAT_001f66ac;
  puVar3 = &DAT_001d13f4;
  puVar4 = param_1;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *param_1 = *(undefined4 *)(puVar1 + 0x16);
  param_1[1] = *(undefined4 *)(puVar1 + 0x10);
  param_1[2] = *(undefined4 *)(puVar1 + 0x14);
  param_1[3] = *(undefined4 *)(puVar1 + 0x12);
  param_1[4] = *(undefined4 *)(puVar1 + 8);
  param_1[5] = *(undefined4 *)(puVar1 + 10);
  param_1[6] = *(undefined4 *)(puVar1 + 0xc);
  param_1[7] = puVar1 + 0x22;
  param_1[8] = (uint)puVar1[0x24];
  param_1[9] = *(undefined4 *)(puVar1 + 0x20);
  param_1[10] = *(undefined4 *)(puVar1 + 0x1c);
  param_1[0xb] = (uint)puVar1[0x1e];
  param_1[0xc] = (uint)puVar1[6];
  param_1[0xd] = (uint)puVar1[4];
  param_1[0xe] = (uint)puVar1[2];
  param_1[0xf] = (uint)*puVar1;
  return;
}

