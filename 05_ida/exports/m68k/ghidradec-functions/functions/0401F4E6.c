
undefined * _inet_ntoa(undefined4 *param_1)

{
  int iVar1;
  undefined *puVar2;
  char *pcVar3;
  char *pcVar4;
  byte *pbVar5;
  undefined4 uStack_8;
  
  uStack_8 = *param_1;
  puVar2 = unk_40B3470;
  iVar1 = 0;
  pbVar5 = (byte *)&uStack_8;
  do {
    pcVar3 = puVar2;
    if (iVar1 != 0) {
      pcVar3 = puVar2 + 1;
      *puVar2 = '.';
    }
    pcVar4 = pcVar3;
    if (99 < *pbVar5) {
      *pcVar3 = *pbVar5 / 100 + 0x30;
      pcVar4 = pcVar3 + 1;
      if ((char)(((word)((word)*pbVar5 + ((*pbVar5 >> 2) / 0x19) * -100) & 0xff) / 10) == '\0') {
        pcVar4 = pcVar3 + 2;
        pcVar3[1] = '0';
      }
      *pbVar5 = *pbVar5 % 100;
    }
    pcVar3 = pcVar4;
    if (9 < *pbVar5) {
      pcVar3 = pcVar4 + 1;
      *pcVar4 = *pbVar5 / 10 + 0x30;
      *pbVar5 = *pbVar5 % 10;
    }
    puVar2 = pcVar3 + 1;
    *pcVar3 = *pbVar5 + 0x30;
    iVar1 = iVar1 + 1;
    pbVar5 = pbVar5 + 1;
  } while (iVar1 < 4);
  *puVar2 = '\0';
  return unk_40B3470;
}
