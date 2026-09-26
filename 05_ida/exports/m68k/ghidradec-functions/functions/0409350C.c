
undefined4 _getval(char *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  byte *pbVar8;
  
  iVar6 = 1;
  if (*param_1 == '=') {
    pcVar7 = param_1 + 1;
    if (*pcVar7 == '-') {
      iVar6 = -1;
      pcVar7 = param_1 + 2;
    }
    pbVar8 = (byte *)(pcVar7 + 1);
    iVar4 = *pcVar7 + -0x30;
    uVar5 = 10;
    if (iVar4 != 0) goto loc_4093586;
    bVar3 = *pbVar8;
    if ('/' < (char)bVar3) {
      if ((char)bVar3 < '8') {
        iVar4 = (char)bVar3 + -0x30;
        pbVar8 = (byte *)(pcVar7 + 2);
        uVar5 = 8;
        goto loc_4093586;
      }
      if (bVar3 == 0x62) {
        uVar5 = 2;
        pbVar8 = (byte *)(pcVar7 + 2);
        goto loc_4093586;
      }
      if (bVar3 == 0x78) {
        uVar5 = 0x10;
        pbVar8 = (byte *)(pcVar7 + 2);
        goto loc_4093586;
      }
    }
    iVar1 = _isargsep((int)(char)*pbVar8);
    if (iVar1 != 0) {
loc_4093586:
      do {
        bVar3 = *pbVar8;
        if ((bVar3 < 0x30) || (0x39 < bVar3)) {
          if ((byte)(bVar3 + 0x9f) < 6) {
            bVar3 = bVar3 + 0xa9;
          }
          else {
            if (5 < (byte)(bVar3 + 0xbf)) {
              iVar1 = _isargsep(bVar3);
              if (iVar1 != 0) {
                *param_2 = iVar6 * iVar4;
                goto loc_40935EC;
              }
              break;
            }
            bVar3 = bVar3 - 0x37;
          }
        }
        else {
          bVar3 = bVar3 - 0x30;
        }
        if (uVar5 <= bVar3) break;
        iVar4 = (uint)bVar3 + uVar5 * iVar4;
        pbVar8 = pbVar8 + 1;
      } while( true );
    }
    uVar2 = 1;
  }
  else {
    *param_2 = 1;
loc_40935EC:
    uVar2 = 0;
  }
  return uVar2;
}
