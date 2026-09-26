/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b984 */

int _vno_rw(int param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  
  piVar1 = *(int **)(param_1 + 0x18);
  if ((param_2 == 1) && (iVar3 = _isrofile(piVar1), iVar3 != 0)) {
    iVar4 = 0x1e;
  }
  else {
    iVar3 = *(int *)(param_3 + 0x14);
    bVar5 = piVar1[10] == 1;
    uVar2 = *(uint *)(param_1 + 8);
    if ((uVar2 & 8) != 0) {
      bVar5 = bVar5 | 2;
    }
    if ((uVar2 & 0x40000) != 0) {
      bVar5 = bVar5 | 4;
    }
    if (piVar1[10] == 8) {
      *(short *)(param_3 + 0x10) = (short)uVar2;
    }
    if (((piVar1[10] == 1) && ((*(byte *)(*piVar1 + 0x38) & 0x10) != 0)) &&
       ((*(byte *)(*_active_u + 0x16) & 2) == 0)) {
      iVar4 = _mfs_io(piVar1,param_3,param_2,bVar5,*(undefined4 *)(param_1 + 0x20));
    }
    else {
      iVar4 = (**(code **)(piVar1[7] + 8))
                        (piVar1,param_3,param_2,bVar5,*(undefined4 *)(param_1 + 0x20));
    }
    if (iVar4 == 0) {
      if (((*(byte *)(param_1 + 8) & 8) != 0) || (piVar1[10] == 8)) {
        *(int *)(param_1 + 0x1c) = *(int *)(param_3 + 8) - (iVar3 - *(int *)(param_3 + 0x14));
      }
      iVar4 = 0;
    }
  }
  return iVar4;
}

