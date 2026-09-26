
void _AllKeysUp(void)

{
  sword sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  word_40B1254 = 0xffff;
  word_40B1252 = 0xffff;
  if (_curMapping != (sword *)0x0) {
    sVar1 = *_curMapping;
    pbVar7 = *(byte **)(_curMapping + 0x43);
    if (pbVar7 == (byte *)0x0) {
      uVar4 = 0;
      pbVar6 = (byte *)0x0;
    }
    else if (sVar1 == 0) {
      pbVar6 = pbVar7 + 1;
      uVar4 = (uint)*pbVar7;
    }
    else {
      pbVar6 = pbVar7 + 2;
      uVar4 = (uint)*(sword *)pbVar7;
    }
    uVar2 = 0;
    do {
      iVar3 = 0;
      pbVar7 = pbVar6;
      if (0 < (int)uVar4) {
        do {
          if (sVar1 == 0) {
            pbVar8 = pbVar7 + 1;
            uVar5 = (uint)*pbVar7;
          }
          else {
            pbVar8 = pbVar7 + 2;
            uVar5 = (uint)*(sword *)pbVar7;
          }
          if (uVar5 == uVar2) goto loc_4069E8A;
          iVar3 = iVar3 + 1;
          pbVar7 = pbVar8;
        } while (iVar3 < (int)uVar4);
      }
      pbVar7 = (byte *)((int)_curMapping + uVar2 + 2);
      *pbVar7 = *pbVar7 & 0x7f;
loc_4069E8A:
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 0x80);
  }
  if (_eventsOpen != 0) {
    *(uint *)(_evg + 0xc) = *(uint *)(_evg + 0xc) & 0xffc1ffff;
  }
  return;
}
