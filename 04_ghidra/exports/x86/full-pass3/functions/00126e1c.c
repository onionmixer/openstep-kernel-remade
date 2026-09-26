/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00126e1c */

void _ip_stripoptions(byte *param_1,int param_2)

{
  size_t sVar1;
  byte *pbVar2;
  uint uVar3;
  
  sVar1 = (*param_1 & 0xf) * 4 - 0x14;
  uVar3 = (uint)param_1 & 0xffffff80;
  pbVar2 = param_1 + 0x14;
  if (param_2 != 0) {
    *(short *)(param_2 + 8) = (short)sVar1;
    *(undefined4 *)(param_2 + 4) = 0xc;
    _bcopy(pbVar2,(void *)(param_2 + 0xc),sVar1);
  }
  _bcopy(pbVar2 + sVar1,pbVar2,(*(short *)(uVar3 + 8) + -0x14) - sVar1);
  *(short *)(uVar3 + 8) = *(short *)(uVar3 + 8) - (short)sVar1;
  *param_1 = *param_1 & 0xf0 | 5;
  return;
}

