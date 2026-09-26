
void _ttyrub(uint param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  word wVar5;
  sword sVar6;
  undefined4 uVar7;
  undefined4 uStack_8;
  
  piVar1 = (int *)*param_2;
  uVar2 = *(uint *)((int)piVar1 + 0x3a);
  if ((uVar2 & 8) == 0) {
    return;
  }
  if ((*(byte *)((int)piVar1 + 0x3f) & 0x40) != 0) {
    return;
  }
  *(uint *)((int)piVar1 + 0x3a) = uVar2 & 0xff7fffff;
  if ((uVar2 & 0x10000) == 0) {
    if ((uVar2 & 0x20000) == 0) {
      param_1 = (uint)*(byte *)(piVar1 + 0x13);
    }
    else if ((*(byte *)((int)piVar1 + 0x3f) & 4) == 0) {
      _ttyoutput(0x5c,piVar1);
      *(byte *)((int)piVar1 + 0x3f) = *(byte *)((int)piVar1 + 0x3f) | 4;
    }
    _ttyecho(param_1,param_2);
    goto loc_400F606;
  }
  if (*(char *)((int)piVar1 + 0x49) == '\0') {
loc_400F520:
    _ttyretype(param_2);
    return;
  }
  if (param_1 - 0x109 < 2) {
loc_400F506:
    uVar7 = 2;
  }
  else {
    switch(_partab[param_1 & 0xff] & 0x3f) {
    case :
      uVar7 = 1;
      break;
    case :
    case :
    case :
    case :
    case :
      if ((*(byte *)((int)piVar1 + 0x3a) & 0x10) == 0) goto loc_400F606;
      goto loc_400F506;
    case :
      if ((int)*(char *)((int)piVar1 + 0x49) < *piVar1) goto loc_400F520;
      cVar3 = *(char *)((int)piVar1 + 0x46);
      *(byte *)((int)piVar1 + 0x3f) = *(byte *)((int)piVar1 + 0x3f) | 0x20;
      *(byte *)((int)piVar1 + 0x3b) = *(byte *)((int)piVar1 + 0x3b) | 0x80;
      *(undefined *)((int)piVar1 + 0x46) = *(undefined *)((int)piVar1 + 0x4a);
      iVar4 = piVar1[1] + -1;
      while (iVar4 = _nextc3(piVar1,iVar4,&uStack_8), iVar4 != 0) {
        _ttyecho(uStack_8,param_2);
      }
      *(byte *)((int)piVar1 + 0x3b) = *(byte *)((int)piVar1 + 0x3b) & 0x7f;
      *(byte *)((int)piVar1 + 0x3f) = *(byte *)((int)piVar1 + 0x3f) & 0xdf;
      iVar4 = (int)cVar3 - (int)*(char *)((int)piVar1 + 0x46);
      *(char *)((int)piVar1 + 0x46) = (char)iVar4 + *(char *)((int)piVar1 + 0x46);
      if (8 < iVar4) {
        iVar4 = 8;
      }
      iVar4 = iVar4 + -1;
      if (-1 < iVar4) {
        do {
          do {
            _ttyoutput(8,piVar1);
            wVar5 = (word)((uint)iVar4 >> 0x10);
            sVar6 = (sword)iVar4 + -1;
            iVar4 = CONCAT22(wVar5,sVar6);
          } while (sVar6 != -1);
          iVar4 = (uint)wVar5 * 0x10000 + -1;
        } while (wVar5 != 0);
      }
      goto loc_400F606;
    :
                    /* WARNING: Subroutine does not return */
      _panic(&aTtyrub);
    }
  }
  _ttyrubo(piVar1,uVar7);
loc_400F606:
  *(char *)((int)piVar1 + 0x49) = *(char *)((int)piVar1 + 0x49) + -1;
  return;
}
