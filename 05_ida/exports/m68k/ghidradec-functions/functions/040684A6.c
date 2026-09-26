
void _LLEventPost(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  sword *psVar1;
  sword *psVar2;
  sword *psVar3;
  int iVar4;
  sword *psVar5;
  sword sVar6;
  sword sVar7;
  int iVar8;
  
  iVar4 = *(int *)(_evg + 8);
  psVar1 = _evg + *_evg * 0x14 + 0x25;
  psVar2 = _evg + _evg[2] * 0x14 + 0x25;
  psVar3 = _evg + _evg[1] * 0x14 + 0x25;
  if ((1 << (param_1 & 0x1f) & 0x1ffeU) != 0) {
    if (_autoDimmed == 0) {
      _autoDimTime = _autoDimPeriod + iVar4;
    }
    else {
      _UndoAutoDim();
    }
  }
  psVar5 = _evg;
  sVar7 = (sword)param_2;
  sVar6 = (sword)((uint)param_2 >> 0x10);
  if (((((*(byte *)((int)_evg + 0x33) & 2) == 0) && (psVar3 != psVar1)) && (psVar2[1] == 0)) &&
     ((param_1 == *(uint *)(psVar2 + 2) && ((1 << (param_1 & 0x1f) & 0x2e0U) != 0)))) {
    *(int *)(psVar2 + 4) = (int)sVar6;
    *(int *)(psVar2 + 6) = (int)sVar7;
    *(int *)(psVar2 + 8) = iVar4;
    if (param_3 == (undefined4 *)0x0) {
      return;
    }
    *(undefined4 *)(psVar2 + 0xe) = *param_3;
    *(undefined4 *)(psVar2 + 0x10) = param_3[1];
    *(undefined4 *)(psVar2 + 0x12) = param_3[2];
    return;
  }
  if (*_evg == *psVar3) {
    return;
  }
  *(uint *)(psVar3 + 2) = param_1;
  *(int *)(psVar3 + 4) = (int)sVar6;
  *(int *)(psVar3 + 6) = (int)sVar7;
  *(undefined4 *)(psVar3 + 10) = *(undefined4 *)(psVar5 + 6);
  *(int *)(psVar3 + 8) = iVar4;
  psVar3[0xc] = 0;
  psVar3[0xd] = 0;
  if (param_3 != (undefined4 *)0x0) {
    *(undefined4 *)(psVar3 + 0xe) = *param_3;
    *(undefined4 *)(psVar3 + 0x10) = param_3[1];
    *(undefined4 *)(psVar3 + 0x12) = param_3[2];
  }
  psVar1 = _evg;
  if (param_1 == 2) {
    psVar3[0xf] = _leftENum;
    _leftENum = 0;
  }
  else if ((int)param_1 < 3) {
    if (param_1 == 1) {
      do {
        psVar1[3] = psVar1[3] + 1;
      } while (psVar1[3] == 0);
      _leftENum = _evg[3];
      psVar3[0xf] = _leftENum;
    }
  }
  else if (param_1 == 3) {
    do {
      psVar1[3] = psVar1[3] + 1;
    } while (psVar1[3] == 0);
    _rightENum = _evg[3];
    psVar3[0xf] = _rightENum;
  }
  else if (param_1 == 4) {
    psVar3[0xf] = _rightENum;
    _rightENum = 0;
  }
  if ((1 << (param_1 & 0x1f) & 0x66U) != 0) {
    *(undefined *)(psVar3 + 0x12) = _lastPressure;
  }
  if ((1 << (param_1 & 0x1f) & 0x1eU) != 0) {
    if (iVar4 - _clickTime <= _clickTimeThresh) {
      iVar8 = (int)sVar6 - (int)_clickLoc._0_2_;
      if (iVar8 < 0) {
        iVar8 = -iVar8;
      }
      if (iVar8 <= _clickSpaceThresh) {
        iVar8 = (int)sVar7 - (int)_clickLoc._2_2_;
        if (iVar8 < 0) {
          iVar8 = -iVar8;
        }
        if (iVar8 <= word_40C3316) {
          if ((param_1 == 1) || (param_1 == 3)) {
            iVar8 = _clickState + 1;
            _clickState = _clickState + 1;
            _clickTime = iVar4;
            *(int *)(psVar3 + 0x10) = iVar8;
          }
          else {
            *(int *)(psVar3 + 0x10) = _clickState;
          }
          goto loc_40686F8;
        }
      }
    }
    if ((param_1 == 1) || (param_1 == 3)) {
      _clickLoc = param_2;
      _clickState = 1;
      _clickTime = iVar4;
      psVar3[0x10] = 0;
      psVar3[0x11] = 1;
    }
    else {
      psVar3[0x10] = 0;
      psVar3[0x11] = 0;
    }
  }
loc_40686F8:
  psVar1 = _evg;
  _evg[1] = *psVar3;
  psVar1[2] = *psVar2;
  return;
}
