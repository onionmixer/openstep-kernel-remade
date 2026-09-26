
undefined4 _StartCursor(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((_screens != 0) &&
     (_currentScreen = sub_406AA0C(*(undefined4 *)(_evg + 0x18)), -1 < _currentScreen)) {
    uVar1 = *(undefined4 *)(_evScreen + 0xc + _currentScreen * 0x28);
    uVar2 = *(undefined4 *)(_evScreen + 0x10 + _currentScreen * 0x28);
    _cursorPin._2_2_ = (sword)uVar1;
    _cursorPin = CONCAT22((sword)((uint)uVar1 >> 0x10),_cursorPin._2_2_ + -1);
    dword_40C3618._2_2_ = (sword)uVar2;
    dword_40C3618 = CONCAT22((sword)((uint)uVar2 >> 0x10),dword_40C3618._2_2_ + -1);
    _SetCurBrightness(_curBright);
    _evdispatch(2,_currentScreen,0);
    return 0;
  }
  return 0xffffffff;
}
