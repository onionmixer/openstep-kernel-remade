
void _ioctl(void)

{
  byte *pbVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined uVar6;
  uint auStack_84 [32];
  
  puVar3 = *(uint **)(dword_40B57D4 + 0x24);
  uVar2 = *puVar3;
  if (((*(uint *)(_active_u + 0x152) <= uVar2) ||
      (iVar5 = *(int *)(*(int *)(_active_u + 0x146) + uVar2 * 4), iVar5 == 0)) ||
     (iVar5 == -0x10000)) {
    *(undefined *)(dword_40B57D4 + 100) = 9;
    return;
  }
  if ((*(uint *)(iVar5 + 0xb) & 0x3ffffff) >> 0x18 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 9;
    return;
  }
  uVar4 = puVar3[1];
  if (uVar4 == 0x20006601) {
    pbVar1 = (byte *)(uVar2 + *(int *)(_active_u + 0x14a));
    *pbVar1 = *pbVar1 | 1;
    return;
  }
  if (uVar4 == 0x20006602) {
    pbVar1 = (byte *)(uVar2 + *(int *)(_active_u + 0x14a));
    *pbVar1 = *pbVar1 & 0xfe;
    return;
  }
  uVar2 = (uVar4 & 0x1fffffff) >> 0x10;
  if (0x80 < uVar2) {
    *(undefined *)(dword_40B57D4 + 100) = 0xe;
    return;
  }
  if ((int)uVar4 < 0) {
    if (uVar2 == 0) {
loc_400C35E:
      auStack_84[0] = puVar3[2];
    }
    else {
      uVar6 = _copyinmsg(puVar3[2],auStack_84,uVar2);
      *(undefined *)(dword_40B57D4 + 100) = uVar6;
      if (*(char *)(dword_40B57D4 + 100) != '\0') {
        return;
      }
    }
  }
  else if (((uVar4 & 0x40000000) == 0) || (uVar2 == 0)) {
    if ((uVar4 & 0x20000000) != 0) goto loc_400C35E;
  }
  else {
    _bzero(auStack_84,uVar2);
  }
  if (uVar4 == 0x8004667d) {
    uVar6 = _fset(iVar5,0x40,auStack_84[0]);
    goto loc_400C410;
  }
  if ((int)uVar4 < -0x7ffb9982) {
    if (uVar4 == 0x8004667c) {
      uVar6 = _fsetown(iVar5,auStack_84[0]);
      goto loc_400C410;
    }
  }
  else {
    if (uVar4 == 0x8004667e) {
      uVar6 = _fset(iVar5,4,auStack_84[0]);
      goto loc_400C410;
    }
    if (uVar4 == 0x4004667b) {
      uVar6 = _fgetown(iVar5,auStack_84);
      goto loc_400C410;
    }
  }
  uVar6 = (**(code **)(*(int *)(iVar5 + 0x12) + 4))(iVar5,uVar4,auStack_84);
  *(undefined *)(dword_40B57D4 + 100) = uVar6;
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return;
  }
  if ((uVar4 & 0x40000000) == 0) {
    return;
  }
  if (uVar2 == 0) {
    return;
  }
  uVar6 = _copyoutmsg(auStack_84,puVar3[2],uVar2);
loc_400C410:
  *(undefined *)(dword_40B57D4 + 100) = uVar6;
  return;
}
