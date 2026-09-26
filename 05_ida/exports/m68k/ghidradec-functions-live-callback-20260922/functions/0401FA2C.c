
undefined4 _in_pcbconnect(int param_1,int param_2)

{
  sword sVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  sword *psVar6;
  
  iVar5 = 0;
  psVar6 = (sword *)(*(int *)(param_2 + 4) + param_2);
  if (*(sword *)(param_2 + 8) != 0x10) {
    return 0x16;
  }
  if (*psVar6 != 2) {
    return 0x2f;
  }
  if (psVar6[1] == 0) {
    return 0x31;
  }
  if (_in_ifaddr != 0) {
    if (*(int *)(psVar6 + 2) == 0) {
      *(undefined4 *)(psVar6 + 2) = *(undefined4 *)(_in_ifaddr + 4);
    }
    else if ((*(int *)(psVar6 + 2) == -1) &&
            ((*(byte *)(*(int *)(_in_ifaddr + 0x20) + 0xd) & 2) != 0)) {
      *(undefined4 *)(psVar6 + 2) = *(undefined4 *)(_in_ifaddr + 0x14);
    }
  }
  if (*(int *)(param_1 + 0x12) != 0) goto loc_401FBC6;
  iVar5 = 0;
  piVar2 = (int *)(param_1 + 0x20);
  iVar4 = *piVar2;
  if (iVar4 == 0) {
loc_401FADE:
    if ((*(byte *)(*(int *)(param_1 + 0x18) + 3) & 0x10) == 0) goto loc_401FAEA;
  }
  else {
    if ((*(int *)(param_1 + 0x28) != *(int *)(psVar6 + 2)) ||
       ((*(byte *)(*(int *)(param_1 + 0x18) + 3) & 0x10) != 0)) {
      if (*(sword *)(iVar4 + 0x26) == 1) {
        _rtfree(iVar4);
      }
      else {
        *(sword *)(iVar4 + 0x26) = *(sword *)(iVar4 + 0x26) + -1;
      }
      *piVar2 = 0;
      goto loc_401FADE;
    }
loc_401FAEA:
    if ((*piVar2 == 0) || (*(int *)(*piVar2 + 0x2c) == 0)) {
      *(undefined2 *)(param_1 + 0x24) = 2;
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(psVar6 + 2);
      _rtalloc(piVar2);
    }
  }
  if (((*piVar2 == 0) || (iVar4 = *(int *)(*piVar2 + 0x2c), iVar4 == 0)) ||
     ((*(byte *)(iVar4 + 0xd) & 8) != 0)) {
loc_401FB3A:
    if (iVar5 == 0) goto loc_401FB3E;
  }
  else {
    iVar5 = _in_ifaddr;
    if (_in_ifaddr != 0) {
      do {
        if (iVar4 == *(int *)(iVar5 + 0x20)) break;
        iVar5 = *(int *)(iVar5 + 0x40);
      } while (iVar5 != 0);
      goto loc_401FB3A;
    }
loc_401FB3E:
    sVar1 = psVar6[1];
    psVar6[1] = 0;
    iVar5 = _ifa_ifwithdstaddr(psVar6);
    psVar6[1] = sVar1;
    if (iVar5 == 0) {
      uVar3 = _in_netof(*(undefined4 *)(psVar6 + 2));
      iVar5 = _in_iaonnetof(uVar3);
      if ((iVar5 == 0) && (iVar5 = _in_ifaddr, _in_ifaddr == 0)) {
        return 0x31;
      }
    }
  }
  if ((((*(uint *)(psVar6 + 2) & 0xf0000000) == 0xe0000000) &&
      (iVar4 = *(int *)(param_1 + 0x38), iVar4 != 0)) &&
     (iVar4 = *(int *)(*(int *)(iVar4 + 4) + iVar4), iVar4 != 0)) {
    iVar5 = _in_ifaddr;
    if (_in_ifaddr != 0) {
      do {
        if (iVar4 == *(int *)(iVar5 + 0x20)) break;
        iVar5 = *(int *)(iVar5 + 0x40);
      } while (iVar5 != 0);
      if (iVar5 != 0) goto loc_401FBC6;
    }
    return 0x31;
  }
loc_401FBC6:
  iVar4 = *(int *)(param_1 + 0x12);
  if (iVar4 == 0) {
    iVar4 = *(int *)(iVar5 + 4);
  }
  iVar4 = _in_pcblookup(*(undefined4 *)(param_1 + 8),*(undefined4 *)(psVar6 + 2),psVar6[1],iVar4,
                        *(undefined2 *)(param_1 + 0x16),0);
  if (iVar4 == 0) {
    if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x18) + 0xc) + 9) & 4) != 0) &&
       (*(sword *)(param_1 + 0x16) == psVar6[1])) {
      iVar4 = *(int *)(param_1 + 0x12);
      if (iVar4 == 0) {
        iVar4 = *(int *)(iVar5 + 4);
      }
      if (*(int *)(psVar6 + 2) == iVar4) {
        return 0x3d;
      }
    }
    if (*(int *)(param_1 + 0x12) == 0) {
      if (*(sword *)(param_1 + 0x16) == 0) {
        _in_pcbbind(param_1,0);
      }
      *(undefined4 *)(param_1 + 0x12) = *(undefined4 *)(iVar5 + 4);
    }
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(psVar6 + 2);
    *(sword *)(param_1 + 0x10) = psVar6[1];
    uVar3 = 0;
  }
  else {
    uVar3 = 0x30;
  }
  return uVar3;
}

