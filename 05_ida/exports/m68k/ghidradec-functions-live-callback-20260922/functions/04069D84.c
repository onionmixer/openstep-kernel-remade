
undefined4 _InitKbd(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined uStack_24;
  uint uStack_23;
  
  _mapNotDefault = 0;
  _keyPressed = 0;
  _alphaLock = 0;
  _curMapping = &_curMappingStorage;
  _AlphaLockFeedback(0);
  _initialKeyRepeat = 0x23;
  _keyRepeat = 8;
  word_40B1256 = _adb_keybd_present();
  if (word_40B1256 == 0) {
    uVar2 = 0x34a;
    puVar1 = unk_40AD172;
  }
  else {
    uVar2 = 0x3f0;
    puVar1 = unk_40AD4BC;
  }
  _SetKeyMapping(puVar1,uVar2);
  _AllKeysUp();
  if (param_1 == 0) {
    _nvram_check(&uStack_24);
    _curBright = (uStack_23 & 0xfffffff) >> 0x16;
  }
  return 0;
}

