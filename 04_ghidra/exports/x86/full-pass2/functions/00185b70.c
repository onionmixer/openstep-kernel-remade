/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00185b70 */

void _kdp_exception(undefined1 *param_1,uint *param_2,undefined2 *param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6)

{
  *param_1 = 0xd;
  param_1[1] = DAT_001f66b6;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined2 *)(param_1 + 2) = 0xc;
  *(undefined4 *)(param_1 + 8) = 1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = param_4;
  *(undefined4 *)(param_1 + 0x14) = param_5;
  *(undefined4 *)(param_1 + 0x18) = param_6;
  *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + (short)(*(int *)(param_1 + 8) << 4);
  DAT_001f66b8 = 1;
  *param_3 = DAT_001f66b4;
  *param_2 = (uint)*(ushort *)(param_1 + 2);
  return;
}

