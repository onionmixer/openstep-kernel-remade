/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114b8c */

undefined4 _piconnect(int param_1,int param_2)

{
  *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(*(int *)(param_2 + 8) + 0xc) = *(undefined4 *)(param_1 + 8);
  *(undefined2 *)(param_1 + 0x3e) = 0x1000;
  *(undefined2 *)(param_1 + 0x42) = 0x2000;
  *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) | 0x22;
  *(undefined2 *)(param_2 + 0x26) = 0;
  *(undefined2 *)(param_2 + 0x2a) = 0;
  *(byte *)(param_2 + 6) = *(byte *)(param_2 + 6) | 0x12;
  return 1;
}

