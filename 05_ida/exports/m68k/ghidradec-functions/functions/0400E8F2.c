
uint _ttyoutput(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  
  iVar2 = _ttynty(param_2);
  uVar1 = *(uint *)(param_2 + 0x3a);
  if (((uVar1 & 0x200020) != 0) || ((*(uint *)(iVar2 + 0x10) & 0x10000000) == 0)) {
    if ((uVar1 & 0x800000) != 0) {
      return 0xffffffff;
    }
    iVar2 = _putc(param_1,param_2 + 0x18);
    if (iVar2 == 0) {
      _tk_nout = _tk_nout + 1;
      return 0xffffffff;
    }
    return param_1;
  }
  if (((uVar1 & 0x2000000) == 0) && ((*(uint *)(iVar2 + 0x10) & 0x300) != 0x300)) {
    param_1 = param_1 & 0x7f;
  }
  else {
    param_1 = param_1 & 0xff;
  }
  if ((param_1 == 4) && ((uVar1 & 2) == 0)) {
    return 0xffffffff;
  }
  if (((param_1 == 9) && ((uVar1 & 0xc00) == 0xc00)) && ((*(byte *)(param_2 + 0x3f) & 0x40) == 0)) {
    iVar2 = 8 - (*(byte *)(param_2 + 0x46) & 7);
    if ((uVar1 & 0x800000) == 0) {
      iVar3 = _b_to_q(asc_40A6398,iVar2,param_2 + 0x18);
      iVar2 = iVar2 - iVar3;
      _tk_nout = iVar2 + _tk_nout;
    }
    *(char *)(param_2 + 0x46) = (char)iVar2 + *(char *)(param_2 + 0x46);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    return 9;
  }
  _tk_nout = _tk_nout + 1;
  if ((uVar1 & 4) != 0) {
    pcVar7 = asc_40A63A1 + 1;
    do {
      pcVar8 = pcVar7 + 1;
      if ((int)*pcVar7 == param_1) {
        iVar3 = _ttyoutput(0x5c,param_2);
        if (-1 < iVar3) {
          return param_1;
        }
        param_1 = (uint)pcVar7[-1];
        break;
      }
      pcVar7 = pcVar7 + 2;
    } while (*pcVar8 != '\0');
    if (param_1 - 0x41 < 0x1a) {
      iVar3 = _ttyoutput(0x5c,param_2);
      if (-1 < iVar3) {
        return param_1;
      }
    }
    else if (param_1 - 0x61 < 0x1a) {
      param_1 = param_1 - 0x20;
    }
  }
  if (((param_1 == 10) && (((uVar1 & 0x10) != 0 || ((*(byte *)(iVar2 + 0x10) & 0x20) != 0)))) &&
     (iVar3 = _ttyoutput(0xd,param_2), -1 < iVar3)) {
    return 10;
  }
  if (((uVar1 & 0x800000) == 0) && (iVar3 = _putc(param_1,param_2 + 0x18), iVar3 != 0)) {
    return param_1;
  }
  bVar5 = *(byte *)(param_2 + 0x46);
  uVar4 = (uint)(char)bVar5;
  uVar6 = 0;
  switch(_partab[param_1] & 0x3f) {
  case :
    bVar5 = bVar5 + 1;
    break;
  case :
    if (0 < (int)uVar4) {
      bVar5 = bVar5 - 1;
    }
    break;
  case :
    uVar1 = (uVar1 & 0x3ff) >> 8;
    if (uVar1 == 1) {
      if ((0 < (int)uVar4) && (uVar6 = (uVar4 >> 4) + 3, 6 < uVar6)) {
        uVar6 = 6;
      }
    }
    else if (uVar1 == 2) {
      iVar3 = _hz * 100;
      goto loc_400EB2E;
    }
    goto loc_400EBC6;
  case :
    if (((uVar1 & 0xc00) == 0x400) && (uVar6 = 1 - (uVar4 | 0xfffffff8), (int)uVar6 < 5)) {
      uVar6 = 0;
    }
    bVar5 = bVar5 + 8 & 0xf8;
    break;
  case :
    if ((uVar1 & 0x4000) != 0) {
      uVar6 = 0x7f;
    }
    break;
  case :
    uVar1 = (*(uint *)(param_2 + 0x3c) & 0x3fffffff) >> 0x1c;
    if (uVar1 == 2) {
      iVar3 = _hz * 0xa6;
loc_400EB2E:
      uVar6 = iVar3 >> 10;
    }
    else if (uVar1 < 3) {
      if (uVar1 == 1) {
        iVar3 = _hz * 0x53;
        goto loc_400EB2E;
      }
    }
    else if (uVar1 == 3) {
      if (-1 < (int)uVar4) {
        for (; (int)uVar4 < 9; uVar4 = uVar4 + 1) {
          _putc(0x7f,param_2 + 0x18);
        }
      }
      uVar6 = 0;
    }
loc_400EBC6:
    bVar5 = 0;
  }
  *(byte *)(param_2 + 0x46) = bVar5;
  if (((uVar6 != 0) && ((*(uint *)(param_2 + 0x3a) & 0x2800000) == 0)) &&
     ((*(uint *)(iVar2 + 0x10) & 0x300) != 0x300)) {
    _putc(uVar6 | 0x80,param_2 + 0x18);
  }
  return 0xffffffff;
}
