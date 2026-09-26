/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00187fec */

int _isbad(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  param_4 = param_2 * 0x10000 + param_3 * 0x100 + param_4;
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar1 = (uint)*(ushort *)(iVar2 + 10 + param_1) +
            (uint)*(ushort *)(iVar2 + 8 + param_1) * 0x10000;
    if (param_4 == iVar1) {
      return iVar3;
    }
    if (param_4 < iVar1) {
      return -1;
    }
    if (iVar1 < 0) {
      return -1;
    }
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x7e);
  return -1;
}

