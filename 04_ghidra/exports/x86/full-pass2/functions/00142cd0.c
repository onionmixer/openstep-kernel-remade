/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142cd0 */

void _clrblock(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  sbyte sVar4;
  
  iVar3 = *(int *)(param_1 + 0x38);
  bVar2 = (byte)param_3;
  if (iVar3 == 2) {
    param_3 = param_3 >> 2;
    sVar4 = (bVar2 & 3) * '\x02';
    iVar3 = 3;
LAB_00142d2b:
    *(byte *)(param_3 + param_2) = *(byte *)(param_3 + param_2) & ~(byte)(iVar3 << sVar4);
    return;
  }
  if (iVar3 < 3) {
    if (iVar3 == 1) {
      pbVar1 = (byte *)((param_3 >> 3) + param_2);
      *pbVar1 = *pbVar1 & ((byte)(-2 << (bVar2 & 7)) | (byte)(0xfffffffe >> 0x20 - (bVar2 & 7)));
      return;
    }
  }
  else {
    if (iVar3 == 4) {
      param_3 = param_3 >> 1;
      sVar4 = (bVar2 & 1) * '\x04';
      iVar3 = 0xf;
      goto LAB_00142d2b;
    }
    if (iVar3 == 8) {
      *(undefined1 *)(param_3 + param_2) = 0;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_clrblock_001de0e8);
}

