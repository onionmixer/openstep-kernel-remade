/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012c6c4 */

void _nattr_to_vattr(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  short sVar3;
  
  iVar1 = param_1[0xc];
  *param_3 = *param_2;
  *(short *)(param_3 + 1) = (short)param_2[1];
  *(short *)((int)param_3 + 6) = (short)param_2[3];
  *(short *)(param_3 + 2) = (short)param_2[4];
  sVar3 = _vfs_fixedmajor(param_1[9]);
  param_3[3] = (uint)(ushort)(sVar3 << 8 | (ushort)*(byte *)(*(int *)(param_1[9] + 0x128) + 0x28));
  param_3[4] = param_2[10];
  *(short *)(param_3 + 5) = (short)param_2[2];
  uVar2 = *(uint *)(*param_1 + 0x14);
  if (((uint)param_2[5] < uVar2) &&
     (((*(byte *)(*param_1 + 0x38) & 2) != 0 || ((*(byte *)(iVar1 + 0x60) & 0x10) != 0)))) {
    param_3[6] = uVar2;
  }
  else {
    param_3[6] = param_2[5];
  }
  if ((*(uint *)(iVar1 + 0x98) < (uint)param_3[6]) || ((*(byte *)(iVar1 + 0x60) & 0x10) == 0)) {
    *(int *)(iVar1 + 0x98) = param_3[6];
  }
  param_3[8] = param_2[0xb];
  param_3[9] = param_2[0xc];
  param_3[10] = param_2[0xd];
  param_3[0xb] = param_2[0xe];
  param_3[0xc] = param_2[0xf];
  param_3[0xd] = param_2[0x10];
  *(short *)(param_3 + 0xe) = (short)param_2[7];
  param_3[0xf] = param_2[8];
  if (*param_2 == 3) {
    param_3[7] = 0x800;
  }
  else if (*param_2 == 4) {
    param_3[7] = 0x2000;
  }
  else {
    param_3[7] = param_2[6];
  }
  if ((*param_2 == 4) && (param_2[7] == -1)) {
    *param_3 = 8;
    *(ushort *)(param_3 + 1) = *(ushort *)(param_3 + 1) & 0xfff | 0x1000;
    *(undefined2 *)(param_3 + 0xe) = 0;
    param_3[7] = param_2[6];
  }
  return;
}

