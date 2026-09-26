/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142c24 */

bool _isblock(int param_1,int param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = *(int *)(param_1 + 0x38);
  bVar2 = (byte)param_3;
  if (iVar1 == 2) {
    bVar2 = (byte)(3 << (bVar2 & 3) * '\x02');
    param_3 = param_3 >> 2;
  }
  else if (iVar1 < 3) {
    if (iVar1 != 1) {
LAB_00142cb8:
                    /* WARNING: Subroutine does not return */
      _panic(s_isblock_001de0e0);
    }
    bVar2 = (byte)(1 << (bVar2 & 7));
    param_3 = param_3 >> 3;
  }
  else {
    if (iVar1 != 4) {
      if (iVar1 == 8) {
        return *(char *)(param_3 + param_2) == -1;
      }
      goto LAB_00142cb8;
    }
    bVar2 = (byte)(0xf << (bVar2 & 1) * '\x04');
    param_3 = param_3 >> 1;
  }
  return (*(byte *)(param_3 + param_2) & bVar2) == bVar2;
}

