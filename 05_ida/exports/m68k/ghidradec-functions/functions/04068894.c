
undefined4 _evsioctl(undefined4 param_1,int param_2,int *param_3)

{
  sword sVar1;
  sword sVar2;
  sword *psVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  sword sVar7;
  
  if (_eventsOpen == 0) {
    return 6;
  }
  sVar1 = *_evg;
  sVar2 = _evg[1];
  if (param_2 == -0x3ff39a96) {
    uVar5 = sub_4068F24(param_3);
    return uVar5;
  }
  if (param_2 < -0x3ff39a95) {
    if (param_2 == -0x7ffb9aaf) {
      _buttonsTied = *param_3;
    }
    else if (param_2 < -0x7ffb9aae) {
      if (param_2 == -0x7ffb9ad4) {
        _waitFrameRate = 0;
        if (1 < *param_3) {
          _waitFrameRate = (sword)*param_3;
        }
      }
      else if (param_2 < -0x7ffb9ad3) {
        if (param_2 == -0x7ffb9af4) {
          if (*param_3 - 1U < 1000) {
            _initialKeyRepeat = *param_3;
          }
        }
        else if (param_2 < -0x7ffb9af3) {
          if (param_2 != -0x7ffb9af6) {
            return 0x16;
          }
          if (*param_3 - 1U < 1000) {
            _keyRepeat = *param_3;
          }
        }
        else if (param_2 == -0x7ffb9ad8) {
          sVar7 = 0;
          if (-1 < *param_3) {
            sVar7 = (sword)*param_3;
          }
          _evg[0x24] = sVar7;
        }
        else {
          if (param_2 != -0x7ffb9ad6) {
            return 0x16;
          }
          _waitSustain = 0;
          if (-1 < *param_3) {
            _waitSustain = (sword)*param_3;
          }
        }
      }
      else if (param_2 == -0x7ffb9ab8) {
        _clickSpaceThresh = *(undefined2 *)param_3;
        word_40C3316 = (undefined2)*param_3;
      }
      else if (param_2 < -0x7ffb9ab7) {
        if (param_2 != -0x7ffb9aba) {
          return 0x16;
        }
        _clickTimeThresh = *param_3;
      }
      else if (param_2 == -0x7ffb9ab3) {
        _autoDimTime = *param_3 + (_autoDimTime - _autoDimPeriod);
        _autoDimPeriod = *param_3;
      }
      else {
        if (param_2 != -0x7ffb9ab1) {
          return 0x16;
        }
        _mouseHandedness = *param_3;
      }
    }
    else if (param_2 == -0x7ff79af2) {
      uVar5 = _kalloc(*param_3);
      iVar4 = _curMapLen;
      iVar6 = _copyinmsg(param_3[1],uVar5,*param_3);
      if ((iVar6 != 0) || (iVar6 = _SetKeyMapping(uVar5,*param_3), iVar6 == 0)) {
        _kfree(uVar5,*param_3);
        return 0x16;
      }
      if (_mapNotDefault == 0) {
        _mapNotDefault = 1;
      }
      else {
        _kfree(iVar6,iVar4);
      }
    }
    else if (param_2 < -0x7ff79af1) {
      if (param_2 == -0x7ffb9a9c) {
        _curBright = _SetCurBrightness(*param_3);
        _RecordBrightness();
      }
      else if (param_2 < -0x7ffb9a9b) {
        if (param_2 != -0x7ffb9aaa) {
          return 0x16;
        }
        if (*param_3 == 0) {
          _UndoAutoDim();
          _autoDimTime = _autoDimPeriod + *(int *)(_evg + 8);
        }
        else {
          _autoDimTime = *(int *)(_evg + 8);
          _DoAutoDim();
        }
      }
      else if (param_2 == -0x7ffb9a9a) {
        _SetAttenuation(3,*param_3);
        _snd_device_vol_set();
        _snd_device_vol_save();
      }
      else {
        if (param_2 != -0x7ffb9a98) {
          return 0x16;
        }
        _dimmedBrightness = *param_3;
        if (_dimmedBrightness < 0) {
          _dimmedBrightness = 0;
        }
        if (0x3d < _dimmedBrightness) {
          _dimmedBrightness = 0x3d;
        }
        if (_autoDimmed != 0) {
          _DoAutoDim();
        }
      }
    }
    else {
      if (param_2 == -0x7feb9afd) {
        _keySema = _keySema + 1;
        *(int *)(_evg + 10) = *(int *)(_evg + 10) + 1;
      }
      else {
        if (-0x7feb9afd < param_2) {
          if (param_2 != -0x7fab9ab6) {
            if (param_2 == -0x3ff79af1) {
              uVar5 = *(undefined4 *)(_curMapping + 0x2d8);
              if (_curMapLen < *param_3) {
                *param_3 = _curMapLen;
              }
              iVar4 = _copyoutmsg(uVar5,param_3[1],*param_3);
              if (iVar4 == 0) goto loc_4068E9E;
            }
            return 0x16;
          }
          psVar3 = _evg;
          psVar3[10] = 0;
          psVar3[0xb] = 1;
          _numMouseScales = *param_3;
          sVar7 = (sword)*param_3;
          while (sVar7 = sVar7 + -1, sVar7 != -1) {
            iVar4 = (int)sVar7;
            (&_mouseScaleThresholds)[iVar4] = *(undefined2 *)((int)param_3 + iVar4 * 2 + 4);
            *(undefined2 *)(_mouseScaleFactors + iVar4 * 2) =
                 *(undefined2 *)((int)param_3 + iVar4 * 2 + 0x2c);
          }
          psVar3 = _evg + 0xb;
          _evg[10] = 0;
          *psVar3 = 0;
          goto loc_4068E9E;
        }
        if (param_2 != -0x7feb9afe) {
          return 0x16;
        }
        _keySema = _keySema + 1;
        *(int *)(_evg + 10) = *(int *)(_evg + 10) + 1;
      }
      _LLEventPost(*param_3,param_3[1],param_3 + 2);
      *(int *)(_evg + 10) = *(int *)(_evg + 10) + -1;
      _keySema = _keySema + -1;
    }
  }
  else if (param_2 == 0x40046549) {
    *(undefined2 *)param_3 = _clickSpaceThresh;
    *(undefined2 *)((int)param_3 + 2) = word_40C3316;
  }
  else if (param_2 < 0x4004654a) {
    if (param_2 == 0x40046510) {
      *param_3 = _curMapLen;
    }
    else if (param_2 < 0x40046511) {
      if (param_2 == 0x2000654c) {
        _ResetMouse();
      }
      else if (param_2 < 0x2000654d) {
        if (param_2 != 0x20006511) {
          return 0x16;
        }
        _ResetKbd();
      }
      else if (param_2 == 0x4004650b) {
        *param_3 = _keyRepeat;
      }
      else {
        if (param_2 != 0x4004650d) {
          return 0x16;
        }
        *param_3 = _initialKeyRepeat;
      }
    }
    else if (param_2 == 0x4004652b) {
      *param_3 = (int)_waitSustain;
    }
    else if (param_2 < 0x4004652c) {
      if (param_2 != 0x40046529) {
        return 0x16;
      }
      *param_3 = (int)_evg[0x24];
    }
    else if (param_2 == 0x4004652d) {
      *param_3 = (int)_waitFrameRate;
    }
    else {
      if (param_2 != 0x40046547) {
        return 0x16;
      }
      *param_3 = _clickTimeThresh;
    }
  }
  else if (param_2 == 0x40046554) {
    *param_3 = _autoDimTime;
  }
  else if (param_2 < 0x40046555) {
    if (param_2 == 0x40046550) {
      *param_3 = _mouseHandedness;
    }
    else if (param_2 < 0x40046551) {
      if (param_2 != 0x4004654e) {
        return 0x16;
      }
      *param_3 = _autoDimPeriod;
    }
    else if (param_2 == 0x40046552) {
      *param_3 = _buttonsTied;
    }
    else {
      if (param_2 != 0x40046553) {
        return 0x16;
      }
      *param_3 = _autoDimmed;
    }
  }
  else if (param_2 == 0x40046567) {
    iVar4 = _vol_r + _vol_l;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 1;
    }
    *param_3 = iVar4 >> 1;
  }
  else if (param_2 < 0x40046568) {
    if (param_2 == 0x40046555) {
      *param_3 = _autoDimTime - *(int *)(_evg + 8);
    }
    else {
      if (param_2 != 0x40046565) {
        return 0x16;
      }
      *param_3 = _curBright;
    }
  }
  else if (param_2 == 0x40046569) {
    *param_3 = _dimmedBrightness;
  }
  else {
    if (param_2 != 0x4054654b) {
      return 0x16;
    }
    iVar4 = 0x14;
    if (_numMouseScales < 0x15) {
      iVar4 = _numMouseScales;
    }
    *param_3 = iVar4;
    sVar7 = (sword)iVar4;
    while (sVar7 = sVar7 + -1, sVar7 != -1) {
      iVar4 = (int)sVar7;
      *(undefined2 *)((int)param_3 + iVar4 * 2 + 4) = (&_mouseScaleThresholds)[iVar4];
      *(undefined2 *)((int)param_3 + iVar4 * 2 + 0x2c) =
           *(undefined2 *)(_mouseScaleFactors + iVar4 * 2);
    }
  }
loc_4068E9E:
  if (((sVar2 == sVar1) && (_eventsOpen != 0)) && (_evg[1] != *_evg)) {
    _evnewevents();
  }
  return 0;
}
