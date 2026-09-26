
void _InitMouse(int param_1)

{
  int iVar1;
  sword sVar2;
  undefined2 *puVar3;
  sword sVar4;
  undefined2 *puVar5;
  
  puVar5 = _evg;
  puVar3 = _evg;
  sVar4 = (sword)param_1;
  while (sVar2 = sVar4 + -1, _evg = puVar3, sVar2 != -1) {
    iVar1 = (int)sVar2;
    *(undefined4 *)(puVar5 + iVar1 * 0x14 + 0x27) = 0;
    *(undefined4 *)(puVar5 + iVar1 * 0x14 + 0x2d) = 0;
    *(undefined4 *)(puVar5 + iVar1 * 0x14 + 0x2f) = 0;
    puVar5[iVar1 * 0x14 + 0x26] = 0;
    puVar5[iVar1 * 0x14 + 0x25] = sVar4;
    puVar3 = _evg;
    sVar4 = sVar2;
  }
  iVar1 = param_1 * 5 + -5;
  puVar3[iVar1 * 4 + 0x25] = 0;
  puVar3[2] = puVar3[iVar1 * 4 + 0x25];
  puVar3[1] = puVar3[(sword)puVar3[2] * 0x14 + 0x25];
  *puVar3 = puVar3[1];
  *(undefined4 *)(puVar3 + 4) = 0;
  puVar3[3] = 0xd;
  *(undefined4 *)(puVar3 + 6) = 0;
  *(undefined4 *)(puVar3 + 8) = 1;
  puVar3[0xc] = 100;
  puVar3[0xd] = 100;
  _screens = 0;
  _sessionPressure = 0;
  _sessionPrecision = 0;
  _lastPressure = 0;
  *(byte *)((int)puVar3 + 0x33) = *(byte *)((int)puVar3 + 0x33) & 0xfd;
  *(byte *)((int)_evg + 0x33) = *(byte *)((int)_evg + 0x33) & 0xfb;
  *(byte *)((int)_evg + 0x33) = *(byte *)((int)_evg + 0x33) & 0xef;
  *(byte *)((int)_evg + 0x33) = *(byte *)((int)_evg + 0x33) & 0xf7;
  _rightENum = 0;
  _leftENum = 0;
  *(byte *)((int)_evg + 0x33) = *(byte *)((int)_evg + 0x33) & 0xfe;
  puVar3 = _evg;
  *(undefined4 *)(_evg + 0x1a) = 0;
  *(undefined4 *)(puVar3 + 10) = 0;
  _autoDimmed = 0;
  _mouseDelY = 0;
  _mouseDelX = 0;
  dword_40B4FB6 = _adb_mouse_present();
  _InitMouseVars();
  return;
}

