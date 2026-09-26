
byte sub_408CFC8(int param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  
  iVar2 = param_1 * 0x164;
  pbVar1 = (byte *)(&DAT_40b52dc)[param_1 * 0x59];
  cVar4 = '\0';
  bVar3 = sub_408CEE6(*(undefined4 *)(DAT_40b5420 + iVar2));
  bVar3 = bVar3 | DAT_40b5420[iVar2 + 0x12];
  if (((DAT_40b5420[iVar2 + 3] & 8) != 0) || (((&DAT_40b5403)[iVar2] & 0x40) == 0)) {
    bVar3 = bVar3 | 8;
  }
  _delay(1);
  *pbVar1 = 5;
  _delay(1);
  *pbVar1 = bVar3;
  return cVar4 << 4 | ((char)bVar3 < '\0') << 3 | (bVar3 == 0) << 2;
}

