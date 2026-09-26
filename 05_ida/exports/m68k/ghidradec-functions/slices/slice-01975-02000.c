/* GHIDRADEC_FUNCTION index=1975 start=0x40697d4 */

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
/* GHIDRADEC_FUNCTION index=1976 start=0x40698a8 */

void _DoModCalc(int param_1,int param_2)

{
  byte bVar1;
  undefined2 uStack_10;
  undefined2 uStack_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  undefined2 uStack_8;
  undefined2 uStack_6;
  
  bVar1 = *(byte *)(param_1 + 2 + param_2);
  if ((bVar1 & 0x10) != 0) {
    _CalcModBit(param_1,bVar1 & 0xf);
    if ((bVar1 & 0x20) == 0) {
      uStack_8 = (undefined2)param_2;
      uStack_6 = 0;
      uStack_e = 0;
      uStack_a = 0;
      uStack_c = 0;
      uStack_10 = 0;
      _LLEventPost(0xc,*(undefined4 *)(_evg + 0x18),&uStack_10);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1977 start=0x4069916 */

void _DoCharGen(sword *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  sword sVar2;
  int iVar3;
  word wVar4;
  word wVar5;
  int iVar6;
  uint uVar7;
  sword sVar8;
  uint uVar9;
  word *pwVar10;
  byte *pbVar11;
  byte *pbVar12;
  word *pwVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  word wStack_10;
  sword sStack_e;
  word wStack_c;
  word wStack_a;
  sword sStack_8;
  word wStack_6;
  
  _keyPressed = 1;
  sVar2 = *param_1;
  sStack_e = -(sword)-(param_3 == 2);
  sVar8 = (sword)param_2;
  uVar14 = 0xb;
  if (param_3 != 0) {
    uVar14 = 10;
  }
  wVar5 = (word)((uint)*(undefined4 *)(_evg + 0xc) >> 0x10);
  pwVar13 = *(word **)(_curMapping + param_2 * 4 + 0xc6);
  sStack_8 = sVar8;
  if (pwVar13 != (word *)0x0) {
    if (sVar2 == 0) {
      pwVar10 = (word *)((int)pwVar13 + 1);
      wVar4 = (word)*(byte *)pwVar13;
    }
    else {
      pwVar10 = pwVar13 + 1;
      wVar4 = *pwVar13;
    }
    if (wVar4 != 0) {
      iVar3 = 2;
      if (sVar2 != 0) {
        iVar3 = 4;
      }
      iVar6 = 0;
      if (-1 < *(int *)(_curMapping + 0x82)) {
        do {
          if ((wVar4 & 1) != 0) {
            if ((wVar5 & 1) != 0) {
              pwVar10 = (word *)(iVar3 + (int)pwVar10);
            }
            iVar3 = iVar3 * 2;
          }
          wVar4 = (sword)wVar4 >> 1;
          wVar5 = (sword)wVar5 >> 1;
          iVar6 = iVar6 + 1;
        } while (iVar6 <= *(int *)(_curMapping + 0x82));
      }
    }
    if (sVar2 == 0) {
      wStack_c = (word)(char)*(byte *)pwVar10;
      wStack_a = (word)(byte)*pwVar10;
    }
    else {
      wStack_c = *pwVar10;
      wStack_a = pwVar10[1];
    }
    pwVar13 = *(word **)(_curMapping + param_2 * 4 + 0xc6);
    uVar7 = (*(uint *)(_evg + 0xc) & 0x3ffff) >> 0x10;
    if (sVar2 == 0) {
      pwVar10 = (word *)((int)pwVar13 + 1);
      wVar5 = (word)*(byte *)pwVar13;
    }
    else {
      pwVar10 = pwVar13 + 1;
      wVar5 = *pwVar13;
    }
    if ((wVar5 != 0) && (uVar7 != 0)) {
      iVar3 = 2;
      if (sVar2 != 0) {
        iVar3 = 4;
      }
      iVar6 = 0;
      if (-1 < *(int *)(_curMapping + 0x82)) {
        do {
          if ((wVar5 & 1) != 0) {
            if ((uVar7 & 1) != 0) {
              pwVar10 = (word *)(iVar3 + (int)pwVar10);
            }
            iVar3 = iVar3 * 2;
          }
          wVar5 = (sword)wVar5 >> 1;
          uVar7 = (int)uVar7 >> 1;
          iVar6 = iVar6 + 1;
        } while (iVar6 <= *(int *)(_curMapping + 0x82));
      }
    }
    if (sVar2 == 0) {
      wStack_10 = (word)(char)*(byte *)pwVar10;
      wStack_6 = (word)(byte)*pwVar10;
    }
    else {
      wStack_10 = *pwVar10;
      wStack_6 = pwVar10[1];
    }
    if (wStack_c == 0xffff) {
      pbVar12 = *(byte **)(_curMapping + 0x2ca);
      iVar3 = 0;
      if (wStack_a != 0) {
        do {
          if (sVar2 == 0) {
            pbVar11 = pbVar12 + 1;
            iVar6 = (uint)*pbVar12 * 2;
          }
          else {
            pbVar11 = pbVar12 + 2;
            iVar6 = *(sword *)pbVar12 * 4;
          }
          pbVar12 = pbVar11 + iVar6;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)wStack_a);
      }
      uVar1 = *(undefined4 *)(_evg + 0xc);
      iVar3 = 0;
      if (sVar2 == 0) {
        pwVar13 = (word *)(pbVar12 + 1);
        uVar7 = (uint)*pbVar12;
      }
      else {
        pwVar13 = (word *)(pbVar12 + 2);
        uVar7 = (uint)*(sword *)pbVar12;
      }
      if (0 < (int)uVar7) {
        do {
          if (sVar2 == 0) {
            pwVar10 = (word *)((int)pwVar13 + 1);
            wStack_c = (word)*(byte *)pwVar13;
          }
          else {
            pwVar10 = pwVar13 + 1;
            wStack_c = *pwVar13;
          }
          if (wStack_c == 0xff) {
            wStack_6 = 0;
            sStack_e = 0;
            wStack_a = 0;
            wStack_c = 0;
            wStack_10 = 0;
            if (param_3 != 0) {
              if (sVar2 == 0) {
                pwVar13 = (word *)((int)pwVar10 + 1);
                uVar9 = (uint)*(byte *)pwVar10;
              }
              else {
                pwVar13 = pwVar10 + 1;
                uVar9 = (uint)(sword)*pwVar10;
              }
              *(uint *)(_evg + 0xc) = *(uint *)(_evg + 0xc) | 1 << (uVar9 + 0x10 & 0x3f);
              uVar16 = *(undefined4 *)(_evg + 0x18);
              uVar15 = 0xc;
              sStack_8 = sVar8;
              goto loc_4069B8A;
            }
            if (sVar2 == 0) {
              pwVar13 = (word *)((int)pwVar10 + 1);
              sStack_8 = sVar8;
            }
            else {
              pwVar13 = pwVar10 + 1;
              sStack_8 = sVar8;
            }
          }
          else {
            if (sVar2 == 0) {
              pwVar13 = (word *)((int)pwVar10 + 1);
              wStack_6 = (word)*(byte *)pwVar10;
            }
            else {
              pwVar13 = pwVar10 + 1;
              wStack_6 = *pwVar10;
            }
            uVar16 = *(undefined4 *)(_evg + 0x18);
            uVar15 = uVar14;
loc_4069B8A:
            wStack_10 = wStack_c;
            wStack_a = wStack_6;
            _LLEventPost(uVar15,uVar16,&wStack_10);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)uVar7);
      }
      *(undefined4 *)(_evg + 0xc) = uVar1;
    }
    else {
      _LLEventPost(uVar14,*(undefined4 *)(_evg + 0x18),&wStack_10);
    }
  }
  if ((*(byte *)(_curMapping + 2 + param_2) & 0x40) != 0) {
    _DoSpecialKey(param_2,param_3,*(undefined4 *)(_evg + 0xc));
  }
  if (param_3 == 1) {
    word_40B1252 = uRam040c364a;
    word_40B1254 = sVar8;
  }
  else if ((param_3 == 0) && (param_2 == word_40B1254)) {
    word_40B1252 = 0xffff;
    word_40B1254 = -1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1978 start=0x4069c24 */

void _DoKbdEvent(int param_1,int param_2,undefined2 param_3)

{
  byte bVar1;
  
  bVar1 = *(byte *)(_curMapping + 2 + param_1);
  if (param_2 == 0) {
    if (-1 < (char)bVar1) {
      _AllKeysUp();
      return;
    }
    bVar1 = bVar1 & 0x7f;
  }
  else {
    bVar1 = bVar1 | 0x80;
  }
  *(uint *)(_evg + 0xc) = CONCAT22((sword)((uint)*(undefined4 *)(_evg + 0xc) >> 0x10),param_3);
  *(byte *)(_curMapping + 2 + param_1) = bVar1;
  if (param_2 == 0) {
    if ((bVar1 & 0x20) != 0) {
      _DoCharGen(_curMapping,param_1,0);
    }
    if ((bVar1 & 0x10) != 0) {
      _DoModCalc(_curMapping,param_1);
    }
  }
  else {
    if ((bVar1 & 0x10) != 0) {
      _DoModCalc(_curMapping,param_1);
    }
    if ((bVar1 & 0x20) != 0) {
      _DoCharGen(_curMapping,param_1,param_2);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1979 start=0x4069ce2 */

void _DoKbdRepeat(void)

{
  sword sVar1;
  bool bVar2;
  
  if (((word_40B1252 != -1) && (_eventsOpen != 0)) &&
     (sVar1 = word_40B1252 + -1, bVar2 = word_40B1252 == 1, word_40B1252 = sVar1, bVar2)) {
    if ((*(byte *)(word_40B1254 + 2 + _curMapping) & 0x20) != 0) {
      _DoCharGen(_curMapping,(int)word_40B1254,2);
    }
    word_40B1252 = sRam040c3652;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1980 start=0x4069d3a */

void _ResetKbd(void)

{
  int iVar1;
  undefined4 unaff_D3;
  
  if (_mapNotDefault == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(_curMapping + 0x2d8);
    unaff_D3 = _curMapLen;
  }
  _InitKbd(1);
  if (iVar1 != 0) {
    _kfree(iVar1,unaff_D3);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1981 start=0x4069d84 */

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
/* GHIDRADEC_FUNCTION index=1982 start=0x4069e12 */

void _AllKeysUp(void)

{
  sword sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  word_40B1254 = 0xffff;
  word_40B1252 = 0xffff;
  if (_curMapping != (sword *)0x0) {
    sVar1 = *_curMapping;
    pbVar7 = *(byte **)(_curMapping + 0x43);
    if (pbVar7 == (byte *)0x0) {
      uVar4 = 0;
      pbVar6 = (byte *)0x0;
    }
    else if (sVar1 == 0) {
      pbVar6 = pbVar7 + 1;
      uVar4 = (uint)*pbVar7;
    }
    else {
      pbVar6 = pbVar7 + 2;
      uVar4 = (uint)*(sword *)pbVar7;
    }
    uVar2 = 0;
    do {
      iVar3 = 0;
      pbVar7 = pbVar6;
      if (0 < (int)uVar4) {
        do {
          if (sVar1 == 0) {
            pbVar8 = pbVar7 + 1;
            uVar5 = (uint)*pbVar7;
          }
          else {
            pbVar8 = pbVar7 + 2;
            uVar5 = (uint)*(sword *)pbVar7;
          }
          if (uVar5 == uVar2) goto loc_4069E8A;
          iVar3 = iVar3 + 1;
          pbVar7 = pbVar8;
        } while (iVar3 < (int)uVar4);
      }
      pbVar7 = (byte *)((int)_curMapping + uVar2 + 2);
      *pbVar7 = *pbVar7 & 0x7f;
loc_4069E8A:
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 0x80);
  }
  if (_eventsOpen != 0) {
    *(uint *)(_evg + 0xc) = *(uint *)(_evg + 0xc) & 0xffc1ffff;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1983 start=0x4069eb8 */

void _MoveTheCursor(int param_1)

{
  undefined4 uVar1;
  sword sVar2;
  sword sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar5 = -1;
  if (_screens == 0) {
    return;
  }
  iVar4 = _evScreen + _currentScreen * 0x28;
  if (((((param_1._0_2_ < *(sword *)(iVar4 + 0xc)) || (*(sword *)(iVar4 + 0xe) <= param_1._0_2_)) ||
       (param_1._2_2_ < *(sword *)(iVar4 + 0x10))) || (*(sword *)(iVar4 + 0x12) <= param_1._2_2_))
     && (iVar5 = sub_406AA0C(param_1), iVar5 < 0)) {
    sVar2 = _cursorPin._0_2_;
    if ((_cursorPin._0_2_ <= param_1._0_2_) &&
       (sVar2 = param_1._0_2_, _cursorPin._2_2_ < param_1._0_2_)) {
      sVar2 = _cursorPin._2_2_;
    }
    sVar3 = dword_40C3618._0_2_;
    if ((dword_40C3618._0_2_ <= param_1._2_2_) &&
       (sVar3 = param_1._2_2_, dword_40C3618._2_2_ < param_1._2_2_)) {
      sVar3 = dword_40C3618._2_2_;
    }
    param_1 = CONCAT22(sVar2,sVar3);
  }
  if (param_1 == *(int *)(_evg + 0x18)) {
    return;
  }
  *(int *)(_evg + 0x18) = param_1;
  if (iVar5 < 0) {
    _evdispatch(3,_currentScreen,0);
  }
  else {
    _evdispatch(1,_currentScreen,0);
    uVar6 = *(undefined4 *)(_evScreen + 0xc + iVar5 * 0x28);
    uVar1 = *(undefined4 *)(_evScreen + 0x10 + iVar5 * 0x28);
    _cursorPin._2_2_ = (sword)uVar6;
    _cursorPin._0_2_ = (sword)((uint)uVar6 >> 0x10);
    _cursorPin = CONCAT22(_cursorPin._0_2_,_cursorPin._2_2_ + -1);
    dword_40C3618._2_2_ = (sword)uVar1;
    dword_40C3618._0_2_ = (sword)((uint)uVar1 >> 0x10);
    dword_40C3618 = CONCAT22(dword_40C3618._0_2_,dword_40C3618._2_2_ + -1);
    _currentScreen = iVar5;
    _evdispatch(2,iVar5,0);
  }
  if (*(int *)(_evg + 0x34) != 0) {
    if (((*(uint *)(_evg + 0x34) & 0x40) == 0) || ((*(uint *)(_evg + 8) & 4) == 0)) {
      if (((char)*(undefined4 *)(_evg + 0x34) < '\0') && ((*(uint *)(_evg + 8) & 1) != 0)) {
        uVar6 = 7;
      }
      else {
        if ((*(uint *)(_evg + 0x34) & 0x20) == 0) goto loc_406A05C;
        uVar6 = 5;
      }
    }
    else {
      uVar6 = 6;
    }
    _LLEventPost(uVar6,param_1,0);
  }
loc_406A05C:
  if (((*(byte *)(_evg + 0x33) & 1) != 0) &&
     (((((param_1._0_2_ < *(sword *)(_evg + 0x28) || (*(sword *)(_evg + 0x2a) <= param_1._0_2_)) ||
        (param_1._2_2_ < *(sword *)(_evg + 0x2c))) || (*(sword *)(_evg + 0x2e) <= param_1._2_2_)) &&
      ((*(byte *)(_evg + 0x33) & 1) != 0)))) {
    _LLEventPost(9,*(undefined4 *)(_evg + 0x18),0);
    *(byte *)(_evg + 0x33) = *(byte *)(_evg + 0x33) & 0xfe;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1984 start=0x406a0d0 */

uint _process_mouse_event(int param_1)

{
  byte bVar1;
  uint uVar2;
  
  if (_buttonsTied == 0) {
    if (_mouseHandedness != 0) {
      bVar1 = *(byte *)(param_1 + 3);
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 2) & 1 | bVar1 & 0xfe;
      *(byte *)(param_1 + 2) = bVar1 & 1 | *(byte *)(param_1 + 2) & 0xfe;
    }
  }
  else {
    if ((*(byte *)(param_1 + 2) & 1) == 0) {
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xfe;
    }
    *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) | 1;
  }
  if ((~(uint)*(byte *)(param_1 + 3) & 1) != (*(uint *)(_evg + 8) & 7) >> 2) {
    if ((*(byte *)(param_1 + 3) & 1) == 0) {
      _lastPressure = 0xff;
      _LLEventPost(1,*(undefined4 *)(_evg + 0x18),0);
      uVar2 = *(uint *)(_evg + 8) | 4;
    }
    else {
      _lastPressure = 0;
      _LLEventPost(2,*(undefined4 *)(_evg + 0x18),0);
      uVar2 = *(uint *)(_evg + 8) & 0xfffffffb;
    }
    *(uint *)(_evg + 8) = uVar2;
    *(byte *)(_evg + 0x33) =
         *(byte *)(_evg + 0x33) & 0xfd | (byte)(((*(byte *)(_evg + 0x33) & 7) >> 2) << 1);
    if ((*(byte *)(_evg + 0x33) & 2) == 0) {
      uVar2 = *(uint *)(_evg + 0xc) & 0xfffffeff;
    }
    else {
      uVar2 = *(uint *)(_evg + 0xc) | 0x100;
    }
    *(uint *)(_evg + 0xc) = uVar2;
  }
  uVar2 = ~(uint)*(byte *)(param_1 + 2) & 1;
  if (uVar2 != (*(uint *)(_evg + 8) & 1)) {
    if ((*(byte *)(param_1 + 2) & 1) == 0) {
      _LLEventPost(3,*(undefined4 *)(_evg + 0x18),0);
      uVar2 = *(uint *)(_evg + 8) | 1;
    }
    else {
      _LLEventPost(4,*(undefined4 *)(_evg + 0x18),0);
      uVar2 = *(uint *)(_evg + 8) & 0xfffffffe;
    }
    *(uint *)(_evg + 8) = uVar2;
  }
  *(undefined4 *)(_evg + 0x14) = 1;
  uVar2 = CONCAT22((sword)(uVar2 >> 0x10),*(word *)(param_1 + 2)) & 0xfffffefe;
  if ((*(word *)(param_1 + 2) & 0xfefe) != 0) {
    uVar2 = *(uint *)(param_1 + 3) >> 0x19;
    if ((uVar2 & 0x40) != 0) {
      uVar2 = uVar2 | 0xffffff80;
    }
    _mouseDelX = _mouseDelX - uVar2;
    uVar2 = *(uint *)(param_1 + 2) >> 0x19;
    if ((uVar2 & 0x40) != 0) {
      uVar2 = uVar2 | 0xffffff80;
    }
    _mouseDelY = _mouseDelY - uVar2;
  }
  *(undefined4 *)(_evg + 0x14) = 0;
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1985 start=0x406a29c */

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
/* GHIDRADEC_FUNCTION index=1986 start=0x406a394 */

void _ShowWaitCursor(void)

{
  *(undefined4 *)(_evg + 0x40) = 1;
  sub_406A9D4(1);
  _waitFrameTime = _waitFrameRate + 1;
  _waitSusTime = _waitSustain;
  return;
}
/* GHIDRADEC_FUNCTION index=1987 start=0x406a3ca */

void _HideWaitCursor(void)

{
  *(undefined4 *)(_evg + 0x40) = 0;
  sub_406A9D4(0);
  return;
}
/* GHIDRADEC_FUNCTION index=1988 start=0x406a3e4 */

void _AnimateWaitCursor(void)

{
  sub_406A9D4(*(int *)(_evg + 0x1c) + 1);
  _waitFrameTime = _waitFrameRate;
  return;
}
/* GHIDRADEC_FUNCTION index=1989 start=0x406a40a */

void _evsetup_screens(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1[2];
  if (_evScreen == 0) {
    _evScreenSize = param_1[1] * 0x28;
    _evScreen = _kalloc(_evScreenSize);
    _bzero(_evScreen,_evScreenSize);
    _totalShmemSize = 0xcd2;
  }
  iVar1 = _evScreen;
  iVar2 = iVar2 * 0x28;
  iVar3 = param_1[5];
  *(int *)(_evScreen + 0xc + iVar2) = param_1[4];
  *(int *)(iVar1 + 0x10 + iVar2) = iVar3;
  iVar1 = iVar1 + iVar2;
  *(int *)(iVar1 + 8) = param_1[3];
  _totalShmemSize = _totalShmemSize + *(int *)(iVar1 + 8);
  *param_1 = _totalShmemSize;
  return;
}
/* GHIDRADEC_FUNCTION index=1990 start=0x406a49e */

int _ev_register_screen(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (_evg == 0) {
    iVar2 = -1;
  }
  else {
    if (_screens == 0) {
      dword_40B1278 = _evs;
    }
    puVar1 = (undefined4 *)(_evScreen + _screens * 0x28);
    *param_1 = (int)puVar1;
    *puVar1 = param_2;
    puVar1[7] = param_3;
    puVar1[6] = param_4;
    puVar1[8] = param_5;
    puVar1[9] = param_6;
    if (puVar1[2] != 0) {
      puVar1[1] = dword_40B1278;
    }
    dword_40B1278 = puVar1[2] + dword_40B1278;
    iVar2 = _screens + 0x100;
    _screens = _screens + 1;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=1991 start=0x406a522 */

undefined4 _ev_unregister_screen(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((_evg == 0) || (param_1 = param_1 + -0x100, param_1 < 0)) || (_screens <= param_1)) {
    uVar2 = 0xffffffff;
  }
  else {
    _evdispatch(1,_currentScreen,0);
    iVar1 = _evScreen;
    param_1 = param_1 * 0x28;
    *(undefined4 *)(_evScreen + 0x1c + param_1) = 0;
    *(undefined4 *)(iVar1 + 0x18 + param_1) = 0;
    *(undefined4 *)(iVar1 + 0x20 + param_1) = 0;
    *(undefined4 *)(iVar1 + 0x24 + param_1) = 0;
    _evdispatch(2,_currentScreen,0);
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1992 start=0x406a59a */

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
/* GHIDRADEC_FUNCTION index=1993 start=0x406a668 */

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
/* GHIDRADEC_FUNCTION index=1994 start=0x406a7a8 */

void _TermMouse(void)

{
  if (_screens != 0) {
    _evdispatch(1,_currentScreen,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1995 start=0x406a7ca */

void _ResetMouse(void)

{
  if (_autoDimmed != 0) {
    _UndoAutoDim();
  }
  _InitMouseVars();
  return;
}
/* GHIDRADEC_FUNCTION index=1996 start=0x406a7e6 */

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
/* GHIDRADEC_FUNCTION index=1997 start=0x406a86a */

void _evdispatch(uint param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  code *pcVar5;
  
  iVar1 = _evScreen + param_2 * 0x28;
  uVar4 = 0;
  if ((param_1 < 4) || ((*(byte *)(iVar1 + 0x14) & 0x60) != 0)) {
    *(byte *)(iVar1 + 0x14) =
         *(byte *)(iVar1 + 0x14) & 0x9f |
         (DAT_40b127c[(param_1 & 3) + ((*(byte *)(iVar1 + 0x14) & 0x7f) >> 5) * 4] & 3) << 5;
    uVar2 = (*(byte *)(iVar1 + 0x14) & 0x7f) >> 5;
    if (uVar2 == 2) {
      pcVar5 = *(code **)(iVar1 + 0x20);
loc_406A8F0:
      if (pcVar5 != (code *)0x0) {
        uVar4 = (*pcVar5)(iVar1,*(undefined4 *)(_evg + 0x18),*(undefined4 *)(_evg + 0x1c));
      }
    }
    else if (uVar2 < 3) {
      if ((uVar2 == 1) && (*(code **)(iVar1 + 0x18) != (code *)0x0)) {
        uVar4 = (**(code **)(iVar1 + 0x18))(iVar1);
      }
    }
    else if (uVar2 == 3) {
      pcVar5 = *(code **)(iVar1 + 0x1c);
      goto loc_406A8F0;
    }
    if (uVar4 == 0) {
      *(byte *)(iVar1 + 0x14) = (byte)(((uint)*(byte *)(iVar1 + 0x14) << 0x19) >> 0x1e);
    }
  }
  if (param_1 == 4) {
    dword_40B4FB2 = param_3;
  }
  else if (-1 < *(char *)(iVar1 + 0x14)) goto loc_406A96C;
  if (*(code **)(iVar1 + 0x24) != (code *)0x0) {
    cVar3 = (**(code **)(iVar1 + 0x24))(iVar1,dword_40B4FB2);
    *(byte *)(iVar1 + 0x14) = *(byte *)(iVar1 + 0x14) & 0x7f | cVar3 << 7;
    uVar4 = *(byte *)(iVar1 + 0x14) >> 7 | uVar4;
  }
loc_406A96C:
  uVar2 = 1 << (param_2 & 0x3f);
  _evRetryMask = _evRetryMask & ~uVar2;
  if (uVar4 != 0) {
    _evRetryMask = uVar2 | _evRetryMask;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1998 start=0x406a992 */

void _evretry(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = _evRetryMask;
  for (uVar2 = 0; (uVar1 != 0 && (uVar2 < _screens)); uVar2 = uVar2 + 1) {
    if ((uVar1 & 1) != 0) {
      _evdispatch(0,uVar2,0);
    }
    uVar1 = uVar1 >> 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1999 start=0x406aa70 */

void _fc_cmd_xfr(int *param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = *param_1;
  pbVar2 = (byte *)param_1[7];
  bVar3 = pbVar2[10];
  uVar4 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
          0xfffff;
  if ((((uVar4 ^ *_event_middle) & 0x80000) != 0) &&
     (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
    *_event_high = *_event_high + 1;
  }
  *(undefined4 *)(param_2 + 0x1c) = *_event_high;
  *(uint *)(param_2 + 0x18) = *_event_middle | uVar4;
  switch(bVar3 & 0x1f) {
  case :
  case :
  case :
  case :
  case :
  case :
    break;
  :
    pbVar2[0xb] = *(byte *)(param_1[7] + 0x58) | pbVar2[0xb];
  }
  if (((uint)*pbVar2 == *(uint *)((int)param_1 + 0x25e)) ||
     ((iVar5 = _fc_configure(param_1,(uint)*pbVar2), iVar5 == 0 &&
      (iVar5 = _fc_specify(param_1,*pbVar2,_fd_drive_info + *(int *)(param_2 + 0x24) * 0x44),
      iVar5 == 0)))) {
    if (((byte)(0x10 << (pbVar2[0x58] & 0x3f)) & *(byte *)(iVar1 + 2)) == 0) {
      switch(bVar3 & 0x1f) {
      case :
      case :
      case :
      case :
      case :
      case :
      case :
      case :
      case :
      case :
        _fc_motor_on(param_1);
      }
    }
    iVar5 = _fc_send_cmd(param_1,pbVar2);
  }
  *(int *)(pbVar2 + 0x3e) = iVar5;
  return;
}

