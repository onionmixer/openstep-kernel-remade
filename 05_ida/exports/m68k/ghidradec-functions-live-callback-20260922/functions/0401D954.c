
void _rtredirect(word *param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = _ifa_ifwithnet(param_2);
  if (iVar1 == 0) {
    _rtstat = _rtstat + 1;
    return;
  }
  uStack_14 = *(undefined4 *)param_1;
  uStack_10 = *(undefined4 *)(param_1 + 2);
  uStack_c = *(undefined4 *)(param_1 + 4);
  uStack_8 = *(undefined4 *)(param_1 + 6);
  iStack_18 = 0;
  _rtalloc(&iStack_18);
  iVar1 = iStack_18;
  if (((iStack_18 == 0) || (iVar2 = _bcmp(param_4,iStack_18 + 0x14,0x10), iVar2 == 0)) &&
     (iVar2 = _ifa_ifwithaddr(param_2), iVar2 == 0)) {
    if (iVar1 != 0) {
      iVar2 = (*(&off_40AE86A)[(uint)*param_1 * 2])(_wildcard,iVar1 + 4);
      if (iVar2 != 0) {
        _rtfree(iVar1);
        iVar1 = 0;
      }
      if (iVar1 != 0) {
        if ((*(word *)(iVar1 + 0x24) & 2) == 0) {
          _rtstat = _rtstat + 1;
        }
        else if (((*(word *)(iVar1 + 0x24) & 4) == 0) && ((param_3 & 4) != 0)) {
          _rtinit(param_1,param_2,0x8030720a,param_3 | 0x10);
          word_40B6A0E = word_40B6A0E + 1;
        }
        else {
          *(undefined4 *)(iVar1 + 0x14) = *param_2;
          *(undefined4 *)(iVar1 + 0x18) = param_2[1];
          *(undefined4 *)(iVar1 + 0x1c) = param_2[2];
          *(undefined4 *)(iVar1 + 0x20) = param_2[3];
          *(word *)(iVar1 + 0x24) = *(word *)(iVar1 + 0x24) | 0x20;
          word_40B6A10 = word_40B6A10 + 1;
        }
        goto loc_401DA96;
      }
    }
    _rtinit(param_1,param_2,0x8030720a,param_3 & 4 | 0x12);
    word_40B6A0E = word_40B6A0E + 1;
  }
  else {
    _rtstat = _rtstat + 1;
    if (iVar1 == 0) {
      return;
    }
loc_401DA96:
    _rtfree(iVar1);
  }
  return;
}

