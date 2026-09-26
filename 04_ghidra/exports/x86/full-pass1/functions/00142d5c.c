/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142d5c */

void _setblock(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  sbyte sVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x38);
  bVar2 = (byte)param_3;
  if (iVar4 == 2) {
    param_3 = param_3 >> 2;
    sVar3 = (bVar2 & 3) * '\x02';
    iVar4 = 3;
LAB_00142db7:
    *(byte *)(param_3 + param_2) = *(byte *)(param_3 + param_2) | (byte)(iVar4 << sVar3);
    return;
  }
  if (iVar4 < 3) {
    if (iVar4 == 1) {
      pbVar1 = (byte *)((param_3 >> 3) + param_2);
      *pbVar1 = *pbVar1 | (byte)(1 << (bVar2 & 7));
      return;
    }
  }
  else {
    if (iVar4 == 4) {
      param_3 = param_3 >> 1;
      sVar3 = (bVar2 & 1) * '\x04';
      iVar4 = 0xf;
      goto LAB_00142db7;
    }
    if (iVar4 == 8) {
      *(undefined1 *)(param_3 + param_2) = 0xff;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_setblock_001de0f1);
}

