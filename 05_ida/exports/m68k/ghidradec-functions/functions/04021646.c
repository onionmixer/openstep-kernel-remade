
void _ip_stripoptions(byte *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (*param_1 & 0xf) * 4 + -0x14;
  uVar3 = (uint)param_1 & 0xffffff80;
  pbVar1 = param_1 + 0x14;
  if (param_2 != 0) {
    *(sword *)(param_2 + 8) = (sword)iVar2;
    *(undefined4 *)(param_2 + 4) = 0xc;
    _bcopy(pbVar1,param_2 + 0xc,iVar2);
  }
  _bcopy(pbVar1 + iVar2,pbVar1,(*(sword *)(uVar3 + 8) + -0x14) - iVar2);
  *(sword *)(uVar3 + 8) = *(sword *)(uVar3 + 8) - (sword)iVar2;
  *param_1 = *param_1 & 0xf5 | 5;
  return;
}
