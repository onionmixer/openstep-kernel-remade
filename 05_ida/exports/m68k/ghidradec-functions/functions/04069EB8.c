
void _MoveTheCursor(int param_1)

{
  undefined4 uVar1;
  sword sVar2;
  sword sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar5 = -1;
  if (_screens == 0) {
    return;
  }
  iVar4 = _evScreen + _currentScreen * 0x28;
  if (((((param_1._0_2_ < *(sword *)(iVar4 + 0xc)) || (*(sword *)(iVar4 + 0xe) <= param_1._0_2_)) ||
       (param_1._2_2_ < *(sword *)(iVar4 + 0x10))) || (*(sword *)(iVar4 + 0x12) <= param_1._2_2_))
     && (iVar5 = sub_406AA0C(param_1), iVar5 < 0)) {
    sVar2 = _cursorPin._0_2_;
    if ((_cursorPin._0_2_ <= param_1._0_2_) &&
       (sVar2 = param_1._0_2_, _cursorPin._2_2_ < param_1._0_2_)) {
      sVar2 = _cursorPin._2_2_;
    }
    sVar3 = dword_40C3618._0_2_;
    if ((dword_40C3618._0_2_ <= param_1._2_2_) &&
       (sVar3 = param_1._2_2_, dword_40C3618._2_2_ < param_1._2_2_)) {
      sVar3 = dword_40C3618._2_2_;
    }
    param_1 = CONCAT22(sVar2,sVar3);
  }
  if (param_1 == *(int *)(_evg + 0x18)) {
    return;
  }
  *(int *)(_evg + 0x18) = param_1;
  if (iVar5 < 0) {
    _evdispatch(3,_currentScreen,0);
  }
  else {
    _evdispatch(1,_currentScreen,0);
    uVar6 = *(undefined4 *)(_evScreen + 0xc + iVar5 * 0x28);
    uVar1 = *(undefined4 *)(_evScreen + 0x10 + iVar5 * 0x28);
    _cursorPin._2_2_ = (sword)uVar6;
    _cursorPin._0_2_ = (sword)((uint)uVar6 >> 0x10);
    _cursorPin = CONCAT22(_cursorPin._0_2_,_cursorPin._2_2_ + -1);
    dword_40C3618._2_2_ = (sword)uVar1;
    dword_40C3618._0_2_ = (sword)((uint)uVar1 >> 0x10);
    dword_40C3618 = CONCAT22(dword_40C3618._0_2_,dword_40C3618._2_2_ + -1);
    _currentScreen = iVar5;
    _evdispatch(2,iVar5,0);
  }
  if (*(int *)(_evg + 0x34) != 0) {
    if (((*(uint *)(_evg + 0x34) & 0x40) == 0) || ((*(uint *)(_evg + 8) & 4) == 0)) {
      if (((char)*(undefined4 *)(_evg + 0x34) < '\0') && ((*(uint *)(_evg + 8) & 1) != 0)) {
        uVar6 = 7;
      }
      else {
        if ((*(uint *)(_evg + 0x34) & 0x20) == 0) goto loc_406A05C;
        uVar6 = 5;
      }
    }
    else {
      uVar6 = 6;
    }
    _LLEventPost(uVar6,param_1,0);
  }
loc_406A05C:
  if (((*(byte *)(_evg + 0x33) & 1) != 0) &&
     (((((param_1._0_2_ < *(sword *)(_evg + 0x28) || (*(sword *)(_evg + 0x2a) <= param_1._0_2_)) ||
        (param_1._2_2_ < *(sword *)(_evg + 0x2c))) || (*(sword *)(_evg + 0x2e) <= param_1._2_2_)) &&
      ((*(byte *)(_evg + 0x33) & 1) != 0)))) {
    _LLEventPost(9,*(undefined4 *)(_evg + 0x18),0);
    *(byte *)(_evg + 0x33) = *(byte *)(_evg + 0x33) & 0xfe;
  }
  return;
}
