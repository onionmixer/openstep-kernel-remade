
void _DoSpecialKey(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (_curMapping != 0) {
    if (param_2 == 0) {
      if ((*(byte *)(_curMapping + 0x2ce) == param_1) || (*(byte *)(_curMapping + 0x2cf) == param_1)
         ) {
        _snd_device_vol_save();
      }
      else if ((*(byte *)(_curMapping + 0x2d0) == param_1) ||
              (*(byte *)(_curMapping + 0x2d1) == param_1)) {
        _callout_dispatch(4,_RecordBrightness,0);
      }
    }
    else if ((*(byte *)(_curMapping + 0x2ce) == param_1) ||
            (*(byte *)(_curMapping + 0x2cf) == param_1)) {
      _DoSoundKey(param_1,param_2,param_3);
    }
    else if ((*(byte *)(_curMapping + 0x2d0) == param_1) ||
            (*(byte *)(_curMapping + 0x2d1) == param_1)) {
      if (_autoDimmed != 0) {
        _UndoAutoDim();
      }
      if (*(byte *)(_curMapping + 0x2d0) == param_1) {
        iVar1 = _curBright + 1;
      }
      else {
        iVar1 = _curBright + -1;
      }
      _curBright = _SetCurBrightness(iVar1);
    }
  }
  return;
}
