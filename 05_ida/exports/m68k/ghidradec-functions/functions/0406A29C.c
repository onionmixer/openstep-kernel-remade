
int _mouse_motion(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  
  iVar1 = _evg;
  iVar3 = *(int *)(_evg + 0x14);
  if (iVar3 == 0) {
    if ((*(uint *)(_evg + 0x34) & 0x20000) == 0) {
      iVar3 = _mouseDelX;
      if (_mouseDelX < 0) {
        iVar3 = -_mouseDelX;
      }
      iVar2 = _mouseDelY;
      if (_mouseDelY < 0) {
        iVar2 = -_mouseDelY;
      }
      if ((int)_mouseScaleThresholds << (-(int)-(dword_40B4FB6 != 0) & 0x3fU) < iVar2 + iVar3) {
        iVar4 = 1;
        if (1 < _numMouseScales) {
          puVar5 = unk_40C3696;
          do {
            if (iVar2 + iVar3 <= (int)*(sword *)puVar5 << (-(int)-(dword_40B4FB6 != 0) & 0x3fU))
            break;
            puVar5 = (undefined *)((int)puVar5 + 2);
            iVar4 = iVar4 + 1;
          } while (iVar4 < _numMouseScales);
        }
        _mouseDelX = _mouseDelX * *(sword *)(_mouseScaleFactors + (iVar4 + -1) * 2);
        _mouseDelY = _mouseDelY * *(sword *)(_mouseScaleFactors + (iVar4 + -1) * 2);
      }
    }
    *(uint *)(_evg + 0x34) = *(uint *)(_evg + 0x34) & 0xfffcffff;
    iVar3 = _MoveTheCursor(CONCAT22(_mouseDelX._2_2_ + *(sword *)(iVar1 + 0x18),
                                    _mouseDelY._2_2_ + *(sword *)(iVar1 + 0x1a)),
                           *(undefined4 *)(iVar1 + 0x34));
    _mouseDelY = 0;
    _mouseDelX = 0;
  }
  return iVar3;
}
