/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00110014 */

uint _ttyoutput(uint param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  uint uVar10;
  
  iVar2 = _ttynty(param_2);
  uVar5 = *(uint *)(param_2 + 0x3c);
  if (((uVar5 & 0x200020) != 0) || ((*(uint *)(iVar2 + 0x10) & 0x10000000) == 0)) {
    if ((uVar5 & 0x800000) != 0) {
      return 0xffffffff;
    }
    iVar2 = _putc(param_1,(FILE *)(param_2 + 0x18));
    if (iVar2 == 0) {
      _tk_nout = _tk_nout + 1;
      return 0xffffffff;
    }
    return param_1;
  }
  if (((uVar5 & 0x2000000) == 0) && ((*(uint *)(iVar2 + 0x10) & 0x300) != 0x300)) {
    param_1 = param_1 & 0x7f;
  }
  else {
    param_1 = param_1 & 0xff;
  }
  if ((param_1 == 4) && ((uVar5 & 2) == 0)) {
    return 0xffffffff;
  }
  if (((param_1 == 9) && ((uVar5 & 0xc00) == 0xc00)) && ((*(byte *)(param_2 + 0x42) & 0x40) == 0)) {
    iVar2 = 8 - (*(byte *)(param_2 + 0x48) & 7);
    if ((uVar5 & 0x800000) == 0) {
      uVar3 = _spltty();
      iVar4 = _b_to_q(s__001dafb2,iVar2,param_2 + 0x18);
      iVar2 = iVar2 - iVar4;
      _tk_nout = _tk_nout + iVar2;
      _splx(uVar3);
    }
    *(char *)(param_2 + 0x48) = *(char *)(param_2 + 0x48) + (char)iVar2;
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    return 9;
  }
  _tk_nout = _tk_nout + 1;
  if ((uVar5 & 4) != 0) {
    pcVar8 = &DAT_001dafbc;
    cVar1 = DAT_001dafbb;
    while (cVar1 != '\0') {
      pcVar9 = pcVar8 + 1;
      if (param_1 == (int)*pcVar8) {
        iVar4 = _ttyoutput(0x5c,param_2);
        if (-1 < iVar4) {
          return param_1;
        }
        param_1 = (uint)pcVar8[-1];
        break;
      }
      pcVar8 = pcVar8 + 2;
      cVar1 = *pcVar9;
    }
    if (param_1 - 0x41 < 0x1a) {
      iVar4 = _ttyoutput(0x5c,param_2);
      if (-1 < iVar4) {
        return param_1;
      }
    }
    else if (param_1 - 0x61 < 0x1a) {
      param_1 = param_1 - 0x20;
    }
  }
  if (((param_1 == 10) && (((uVar5 & 0x10) != 0 || ((*(byte *)(iVar2 + 0x13) & 0x20) != 0)))) &&
     (iVar4 = _ttyoutput(0xd,param_2), -1 < iVar4)) {
    return 10;
  }
  if (((uVar5 & 0x800000) == 0) && (iVar4 = _putc(param_1,(FILE *)(param_2 + 0x18)), iVar4 != 0)) {
    return param_1;
  }
  bVar6 = *(byte *)(param_2 + 0x48);
  uVar7 = (uint)(char)bVar6;
  uVar10 = 0;
  switch((&_partab)[param_1] & 0x3f) {
  case 0:
    bVar6 = bVar6 + 1;
    break;
  case 2:
    if (0 < (int)uVar7) {
      bVar6 = bVar6 - 1;
    }
    break;
  case 3:
    uVar5 = (int)uVar5 >> 8 & 3;
    if (uVar5 == 1) {
      if ((0 < (int)uVar7) && (uVar10 = (uVar7 >> 4) + 3, 6 < uVar10)) {
        uVar10 = 6;
      }
    }
    else if (uVar5 == 2) {
      iVar4 = _hz * 100;
      goto LAB_0011028e;
    }
    goto LAB_00110353;
  case 4:
    if (((uVar5 & 0xc00) == 0x400) && (uVar10 = 1 - (uVar7 | 0xfffffff8), (int)uVar10 < 5)) {
      uVar10 = 0;
    }
    bVar6 = bVar6 + 8 & 0xf8;
    break;
  case 5:
    if ((uVar5 & 0x4000) != 0) {
      uVar10 = 0x7f;
    }
    break;
  case 6:
    uVar5 = *(int *)(param_2 + 0x3c) >> 0xc & 3;
    if (uVar5 == 2) {
      iVar4 = _hz * 0xa6;
LAB_0011028e:
      uVar10 = iVar4 >> 10;
    }
    else if (uVar5 < 3) {
      if (uVar5 == 1) {
        iVar4 = _hz * 0x53;
        goto LAB_0011028e;
      }
    }
    else if (uVar5 == 3) {
      if ((-1 < (int)uVar7) && ((int)uVar7 < 9)) {
        do {
          _putc(0x7f,(FILE *)(param_2 + 0x18));
          uVar7 = uVar7 + 1;
        } while ((int)uVar7 < 9);
      }
      uVar10 = 0;
    }
LAB_00110353:
    bVar6 = 0;
  }
  *(byte *)(param_2 + 0x48) = bVar6;
  if (((uVar10 != 0) && ((*(uint *)(param_2 + 0x3c) & 0x2800000) == 0)) &&
     ((*(uint *)(iVar2 + 0x10) & 0x300) != 0x300)) {
    _putc(uVar10 | 0x80,(FILE *)(param_2 + 0x18));
  }
  return 0xffffffff;
}

