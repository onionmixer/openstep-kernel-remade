
undefined4 _evioctl(undefined4 param_1,int param_2,int *param_3)

{
  bool bVar1;
  sword sVar2;
  sword *psVar3;
  int iVar4;
  
  psVar3 = _evg;
  if ((_eventsOpen == 0) && (param_2 != -0x3fe79afc)) {
    return 6;
  }
  bVar1 = false;
  if ((_eventsOpen != 0) && (_evg[1] != *_evg)) {
    bVar1 = true;
  }
  sVar2 = _leftENum;
  if (param_2 != -0x3ffb9abe) {
    if (param_2 < -0x3ffb9abd) {
      if (param_2 == -0x7ffb9abc) {
        _MoveTheCursor(*param_3,0);
      }
      else if (param_2 < -0x7ffb9abb) {
        if ((param_2 != -0x7ffb9aff) ||
           (iVar4 = _object_copyin(*(undefined4 *)(_active_threads + 0xc),*param_3,6,0,param_3),
           iVar4 == 0)) {
          return 0x16;
        }
        if (_eventPort != 0) {
          _port_release(_eventPort);
        }
        dword_40B123E = *param_3;
        _eventPort = dword_40B123E;
      }
      else {
        if (param_2 != -0x7feb9afe) {
          return 0x16;
        }
        _LLEventPost(*param_3,param_3[1],param_3 + 2);
      }
      goto loc_4068864;
    }
    if (param_2 == -0x3fe79afc) {
      _evsetup_screens(param_3);
      goto loc_4068864;
    }
    if (-0x3fe79afc < param_2) {
      if (param_2 == 0x20006546) {
        _StartCursor();
      }
      else {
        if (param_2 != 0x40046545) {
          return 0x16;
        }
        *(sword *)param_3 = _evg[0xc];
        *(sword *)((int)param_3 + 2) = psVar3[0xd];
      }
      goto loc_4068864;
    }
    sVar2 = _rightENum;
    if (param_2 != -0x3ffb9abd) {
      return 0x16;
    }
  }
  *param_3 = -(int)-((int)sVar2 == *param_3);
loc_4068864:
  if (((!bVar1) && (_eventsOpen != 0)) && (_evg[1] != *_evg)) {
    _evnewevents();
  }
  return 0;
}

