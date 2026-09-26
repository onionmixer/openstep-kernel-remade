/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00124c2c */

int FUN_00124c2c(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  
  *(ushort *)(param_2 + 0x10) = *(ushort *)(param_1 + 0xc) & 0xfffe;
  iVar1 = _ifioctl(param_3,0x80206910,param_2);
  if (iVar1 == 0) {
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) & 0xbfff;
    _bzero((void *)(param_2 + 0x10),0x10);
    *(undefined2 *)(param_2 + 0x10) = 2;
    iVar1 = _ifioctl(param_3,0x80206916,param_2);
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 0x14) = *param_4;
      iVar1 = _ifioctl(param_3,0x8020690c,param_2);
      if (iVar1 == 0) {
        *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) | 0x8000;
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}

