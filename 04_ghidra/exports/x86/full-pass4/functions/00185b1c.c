/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00185b1c */

void _kdp_setstate(undefined4 *param_1)

{
  undefined2 *puVar1;
  
  puVar1 = DAT_001f66ac;
  *(undefined4 *)(DAT_001f66ac + 0x16) = *param_1;
  *(undefined4 *)(puVar1 + 0x10) = param_1[1];
  *(undefined4 *)(puVar1 + 0x14) = param_1[2];
  *(undefined4 *)(puVar1 + 0x12) = param_1[3];
  *(undefined4 *)(puVar1 + 8) = param_1[4];
  *(undefined4 *)(puVar1 + 10) = param_1[5];
  *(undefined4 *)(puVar1 + 0xc) = param_1[6];
  *(undefined4 *)(puVar1 + 0x20) = param_1[9];
  *(undefined4 *)(puVar1 + 0x1c) = param_1[10];
  puVar1[2] = *(undefined2 *)(param_1 + 0xe);
  *puVar1 = *(undefined2 *)(param_1 + 0xf);
  return;
}

