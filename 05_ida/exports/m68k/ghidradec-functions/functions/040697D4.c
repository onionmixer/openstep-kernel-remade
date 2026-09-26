
void _CalcModBit(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = _alphaLock;
  uVar1 = 1 << (param_2 + 0x10U & 0x3f);
  uVar4 = ~uVar1 & *(uint *)(_evg + 0xc);
  iVar3 = sub_4069364(param_1,param_2);
  if (iVar3 != 0) {
    uVar4 = uVar1 | uVar4;
  }
  if (param_2 == 1) {
    if (((uVar4 & 0x100000) != 0) && (*(int *)(param_1 + 0x86) == 0)) {
      if ((uVar4 & 0x20000) == 0) {
        if (_keyPressed == 0) {
          _alphaLock = -(int)-(_alphaLock == 0);
        }
      }
      else {
        _keyPressed = 0;
      }
    }
    uVar4 = (int)(uVar4 & 0x20000) >> 1 | _alphaLock << 0x10 | uVar4 & 0xfffeffff;
  }
  else if (param_2 == 0) {
    _alphaLock = (uVar4 & 0x1ffff) >> 0x10;
  }
  if (_alphaLock != uVar2) {
    _AlphaLockFeedback(_alphaLock);
  }
  *(uint *)(_evg + 0xc) = uVar4;
  return;
}
