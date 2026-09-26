
void _fcntl(void)

{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  char cVar5;
  undefined uVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint uStack_1a;
  sword asStack_16 [2];
  int iStack_12;
  int iStack_e;
  
  puVar1 = *(uint **)(dword_40B57D4 + 0x24);
  uVar7 = *puVar1;
  if (((*(uint *)((int)_active_u + 0x152) <= uVar7) ||
      (iVar2 = *(int *)(*(int *)((int)_active_u + 0x146) + uVar7 * 4), iVar2 == 0)) ||
     (iVar2 == -0x10000)) goto loc_40040CC;
  puVar8 = (uint *)(uVar7 + *(int *)((int)_active_u + 0x14a));
  switch(puVar1[1]) {
  case :
    if (0xff < puVar1[2]) goto loc_4004112;
    iVar4 = _ufalloc(puVar1[2]);
    if (iVar4 < 0) {
      return;
    }
    if (iVar2 == *(int *)(*(int *)((int)_active_u + 0x146) + *puVar1 * 4)) {
      _dupit(iVar4,iVar2,(int)(char)(*(byte *)puVar8 & 0xfe));
      return;
    }
    *(undefined4 *)(*(int *)((int)_active_u + 0x146) + iVar4 * 4) = 0;
    goto loc_40040CC;
  case :
    *(uint *)(dword_40B57D4 + 0x5c) = *(byte *)puVar8 & 1;
    break;
  case :
    *puVar8 = *puVar8 & 0xfeffffff | (*(byte *)((int)puVar1 + 0xb) & 1) << 0x18;
    break;
  case :
    *(int *)(dword_40B57D4 + 0x5c) = *(int *)(iVar2 + 8) + -1;
    break;
  case :
    if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
      uVar7 = *(uint *)(iVar2 + 8) & 0x21b3;
    }
    else {
      uVar7 = *(uint *)(iVar2 + 8) & 0x400031b3;
    }
    uVar7 = puVar1[2] + 1 & 0xffffde4c | uVar7;
    uStack_1a = (uVar7 & 7) >> 2;
    uVar6 = _fioctl(iVar2,0x8004667e,&uStack_1a);
    *(undefined *)(dword_40B57D4 + 100) = uVar6;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      uStack_1a = (uVar7 & 0x7f) >> 6;
      uVar6 = _fioctl(iVar2,0x8004667d,&uStack_1a);
      *(undefined *)(dword_40B57D4 + 100) = uVar6;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        *(uint *)(iVar2 + 8) = uVar7;
      }
      else {
        uStack_1a = (*(uint *)(iVar2 + 0xb) & 0x7ffffff) >> 0x1a;
        _fioctl(iVar2,0x8004667e,&uStack_1a);
      }
    }
    break;
  case :
    uVar6 = _fgetown(iVar2,dword_40B57D4 + 0x5c);
    goto loc_40041A6;
  case :
    uVar6 = _fsetown(iVar2,puVar1[2]);
loc_40041A6:
    *(undefined *)(dword_40B57D4 + 100) = uVar6;
    break;
  case :
  case :
  case :
    if (*(sword *)(iVar2 + 0xc) == 1) {
      if (((*(byte *)(*_active_u + 0x16) & 0x40) == 0) ||
         (*(int *)(*(int *)(iVar2 + 0x16) + 0x28) != 1)) goto loc_4004112;
      cVar5 = _copyinmsg(puVar1[2],asStack_16,0x12);
      *(char *)(dword_40B57D4 + 100) = cVar5;
      if (cVar5 != '\0') {
        return;
      }
      if (asStack_16[0] == 2) {
        if (puVar1[1] != 7) {
          bVar3 = *(byte *)(iVar2 + 0xb) & 2;
joined_r0x040040ca:
          if (bVar3 == 0) goto loc_40040CC;
        }
      }
      else if (asStack_16[0] < 3) {
        if (asStack_16[0] != 1) goto loc_4004112;
        if (puVar1[1] != 7) {
          bVar3 = *(byte *)(iVar2 + 0xb) & 1;
          goto joined_r0x040040ca;
        }
      }
      else if (asStack_16[0] != 3) goto loc_4004112;
      cVar5 = _rewhence(asStack_16,iVar2,0);
      *(char *)(dword_40B57D4 + 100) = cVar5;
      if (cVar5 != '\0') {
        return;
      }
      if (iStack_e < 0) {
        iStack_12 = iStack_e + iStack_12;
        iStack_e = -iStack_e;
      }
      if (iStack_12 < 0) {
loc_4004112:
        *(undefined *)(dword_40B57D4 + 100) = 0x16;
        return;
      }
      if ((puVar1[1] != 7) && (asStack_16[0] != 3)) {
        *(byte *)puVar8 = *(byte *)puVar8 | 4;
        *(byte *)(*_active_u + 0x28) = *(byte *)(*_active_u + 0x28) | 0x20;
      }
      cVar5 = (**(code **)(*(int *)(*(int *)(iVar2 + 0x16) + 0x1c) + 0x60))
                        (*(int *)(iVar2 + 0x16),asStack_16,puVar1[1],*(undefined4 *)(iVar2 + 0x1e),
                         (int)*(sword *)(*_active_u + 0x30));
      *(char *)(dword_40B57D4 + 100) = cVar5;
      if (cVar5 != '\0') {
        return;
      }
      if (puVar1[1] != 7) {
        return;
      }
      if (asStack_16[0] == 3) {
        uVar9 = 2;
      }
      else {
        uVar9 = 0x12;
      }
      uVar6 = _copyoutmsg(asStack_16,puVar1[2],uVar9);
      goto loc_40041A6;
    }
loc_40040CC:
    *(undefined *)(dword_40B57D4 + 100) = 9;
    break;
  :
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
