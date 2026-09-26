
void _InitMouseVars(void)

{
  sword sVar1;
  int iVar2;
  
  _clickTimeThresh = 0x1e;
  word_40C3316 = 3;
  _clickSpaceThresh = 3;
  _clickTime = 0xffffffe2;
  _clickLoc._2_2_ = 0xfffd;
  _clickLoc._0_2_ = 0xfffd;
  _clickState = 1;
  _autoDimTime = *(int *)(_evg + 0x10) + 0x1d718;
  _autoDimPeriod = 0x1d718;
  _dimmedBrightness = 0xf;
  _buttonsTied = 1;
  _mouseHandedness = 0;
  _numMouseScales = dword_40B1260;
  sVar1 = dword_40B1260._2_2_;
  while (sVar1 = sVar1 + -1, sVar1 != -1) {
    iVar2 = (int)sVar1;
    (&_mouseScaleThresholds)[iVar2] = *(undefined2 *)(unk_40B1264 + iVar2 * 2);
    *(undefined2 *)(_mouseScaleFactors + iVar2 * 2) = *(undefined2 *)(unk_40B126E + iVar2 * 2);
  }
  _mouseDelY = 0;
  _mouseDelX = 0;
  return;
}

