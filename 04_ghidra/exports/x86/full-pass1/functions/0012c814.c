/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012c814 */

void _vattr_to_nattr(int *param_1,int *param_2)

{
  *param_2 = *param_1;
  if (*(ushort *)(param_1 + 1) == 0xffff) {
    param_2[1] = -1;
  }
  else {
    param_2[1] = (uint)*(ushort *)(param_1 + 1);
  }
  if (*(short *)((int)param_1 + 6) == -1) {
    param_2[3] = -1;
  }
  else {
    param_2[3] = (int)*(short *)((int)param_1 + 6);
  }
  if ((short)param_1[2] == -1) {
    param_2[4] = -1;
  }
  else {
    param_2[4] = (int)(short)param_1[2];
  }
  param_2[9] = param_1[3];
  param_2[10] = param_1[4];
  param_2[2] = (int)(short)param_1[5];
  param_2[5] = param_1[6];
  param_2[0xb] = param_1[8];
  param_2[0xc] = param_1[9];
  param_2[0xd] = param_1[10];
  param_2[0xe] = param_1[0xb];
  param_2[0xf] = param_1[0xc];
  param_2[0x10] = param_1[0xd];
  param_2[7] = (int)(short)param_1[0xe];
  param_2[8] = param_1[0xf];
  param_2[6] = param_1[7];
  if (*param_1 == 8) {
    *param_2 = 4;
    param_2[7] = -1;
    param_2[1] = param_2[1] & 0xffff0fffU | 0x2000;
  }
  return;
}

