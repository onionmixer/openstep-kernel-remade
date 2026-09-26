/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016236c */

bool FUN_0016236c(byte *param_1,uint *param_2,undefined2 *param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *param_2;
  if (7 < uVar1) {
    *param_1 = *param_1 | 0x80;
    param_1[2] = 0xc;
    param_1[3] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    param_1[0x12] = 0;
    param_1[0x13] = 0x40;
    param_1[0x14] = 7;
    param_1[0x15] = 0;
    param_1[0x16] = 0;
    param_1[0x17] = 0;
    iVar2 = *(int *)(param_1 + 8);
    *(int *)(param_1 + 8) = iVar2 + 1;
    *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + ((short)iVar2 * 3 + 3) * 4;
    *param_3 = _kdp;
    *param_2 = (uint)*(ushort *)(param_1 + 2);
  }
  return 7 < uVar1;
}

