/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00124338 */

int FUN_00124338(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = _socreate(2,param_3,2,0);
  if (iVar1 == 0) {
    if ((*(ushort *)(param_1 + 0xc) & 1) == 0) {
      *(ushort *)(param_2 + 0x10) = *(ushort *)(param_1 + 0xc) | 0x21;
      iVar1 = _ifioctl(*param_3,0x80206910,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    else if (*(short *)(param_1 + 0xc) < 0) {
      iVar1 = _ifioctl(*param_3,0xc020690d,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
      *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) & 0xbfff;
      return -1;
    }
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) | 0x4000;
    _bzero(&local_14,0x10);
    local_14 = CONCAT22(local_14._2_2_,2);
    *(undefined4 *)(param_2 + 0x10) = local_14;
    *(undefined4 *)(param_2 + 0x14) = local_10;
    *(undefined4 *)(param_2 + 0x18) = local_c;
    *(undefined4 *)(param_2 + 0x1c) = local_8;
    iVar1 = _ifioctl(*param_3,0x8020690c,param_2);
    if (iVar1 == 0) {
      iVar2 = _m_get(1,8);
      if (iVar2 == 0) {
        iVar1 = 0x37;
      }
      else {
        *(undefined2 *)(iVar2 + 8) = 0x10;
        puVar3 = (undefined2 *)(iVar2 + *(int *)(iVar2 + 4));
        *puVar3 = 2;
        puVar3[1] = 0x4400;
        *(undefined4 *)(puVar3 + 2) = 0;
        iVar1 = _sobind(*param_3,iVar2);
        _m_freem(iVar2);
        if (iVar1 == 0) {
          *(ushort *)(*param_3 + 6) = *(ushort *)(*param_3 + 6) | 0x100;
          iVar1 = 0;
        }
      }
    }
  }
  else {
    *param_3 = 0;
  }
  return iVar1;
}

