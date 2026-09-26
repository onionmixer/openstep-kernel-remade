/* GHIDRADEC_FUNCTION index=400 start=0x4012c44 */

undefined4 _soconnect(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(byte *)(param_1 + 3) & 2) == 0) {
    if (((*(word *)(param_1 + 6) & 6) == 0) ||
       (((*(byte *)(*(int *)(param_1 + 0xc) + 9) & 4) == 0 &&
        (iVar2 = _sodisconnect(param_1), iVar2 == 0)))) {
      uVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,4,0,param_2,0);
    }
    else {
      uVar1 = 0x38;
    }
  }
  else {
    uVar1 = 0x2d;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=401 start=0x4012cba */

void _soconnect2(int param_1,undefined4 param_2)

{
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,0x11,0,param_2,0);
  return;
}
/* GHIDRADEC_FUNCTION index=402 start=0x4012cf2 */

undefined4 _sodisconnect(int param_1)

{
  undefined4 uVar1;
  
  if ((*(word *)(param_1 + 6) & 2) == 0) {
    uVar1 = 0x39;
  }
  else if ((*(word *)(param_1 + 6) & 8) == 0) {
    uVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,6,0,0,0);
  }
  else {
    uVar1 = 0x25;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=403 start=0x4012d44 */

uint _sosend(int param_1,int param_2,int param_3,byte param_4,int param_5)

{
  word wVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iStack_14;
  uint uStack_10;
  int iStack_8;
  
  iStack_8 = 0;
  iStack_14 = 0;
  uVar8 = 0;
  bVar2 = true;
  if (((*(byte *)(*(int *)(param_1 + 0xc) + 9) & 1) != 0) &&
     ((int)(uint)*(word *)(param_1 + 0x3a) < *(int *)(param_3 + 0x12))) {
    return 0x28;
  }
  bVar3 = false;
  if (((param_4 & 4) != 0) &&
     (((*(byte *)(param_1 + 3) & 0x10) == 0 && ((*(byte *)(*(int *)(param_1 + 0xc) + 9) & 1) != 0)))
     ) {
    bVar3 = true;
  }
  *(int *)((int)_active_u + 0x19a) = *(int *)((int)_active_u + 0x19a) + 1;
  if (param_5 != 0) {
    iStack_14 = (int)*(sword *)(param_5 + 8);
  }
loc_4012DF0:
  if ((*(byte *)(param_1 + 0x4d) & 1) != 0) {
    do {
      *(word *)(param_1 + 0x4c) = *(word *)(param_1 + 0x4c) | 2;
      _sleep(param_1 + 0x4c,0x1a);
    } while ((*(byte *)(param_1 + 0x4d) & 1) != 0);
  }
  *(word *)(param_1 + 0x4c) = *(word *)(param_1 + 0x4c) | 1;
  do {
    wVar1 = *(word *)(param_1 + 6);
    if ((wVar1 & 0x10) != 0) {
      uVar8 = 0x20;
      goto loc_4013154;
    }
    if (*(word *)(param_1 + 0x50) != 0) {
      uVar8 = (uint)*(word *)(param_1 + 0x50);
      *(undefined2 *)(param_1 + 0x50) = 0;
      goto loc_4013154;
    }
    if ((wVar1 & 2) == 0) {
      if ((*(byte *)(*(int *)(param_1 + 0xc) + 9) & 4) != 0) {
        uVar8 = 0x39;
        goto loc_4013154;
      }
      if (param_2 == 0) {
        uVar8 = 0x27;
        goto loc_4013154;
      }
    }
    if ((param_4 & 1) == 0) {
      uStack_10 = (uint)*(word *)(param_1 + 0x3e);
      iVar9 = uStack_10 - *(word *)(param_1 + 0x3c);
      iVar7 = (uint)*(word *)(param_1 + 0x3a) - (uint)*(word *)(param_1 + 0x38);
      if (iVar9 < iVar7) {
        iVar7 = iVar9;
      }
      if (((iVar7 <= iStack_14) ||
          (((*(byte *)(*(int *)(param_1 + 0xc) + 9) & 1) != 0 &&
           (iVar7 < *(int *)(param_3 + 0x12) + iStack_14)))) ||
         ((0x3ff < *(int *)(param_3 + 0x12) &&
          (((iVar7 < 0x400 && (0x3ff < *(word *)(param_1 + 0x38))) && ((wVar1 & 0x100) == 0))))))
      break;
    }
    else {
      iVar7 = 0x400;
    }
    iVar7 = iVar7 - iStack_14;
    piVar4 = &iStack_8;
    piVar5 = _mfree;
    do {
      _mfree = piVar5;
      if (iVar7 < 1) break;
      if (piVar5 == (int *)0x0) {
        piVar5 = (int *)_m_more(1,1);
      }
      else {
        if (*(sword *)((int)piVar5 + 10) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(&aMget);
        }
        *(undefined2 *)((int)piVar5 + 10) = 1;
        word_40B61CC = word_40B61CC + -1;
        word_40B61CE = word_40B61CE + 1;
        _mfree = (int *)*piVar5;
        *piVar5 = 0;
        piVar5[1] = 0xc;
      }
      if ((*(int *)(param_3 + 0x12) < 0x200) || (iVar7 < 0x400)) {
loc_4013078:
        iVar9 = iVar7;
        if (*(int *)(param_3 + 0x12) < 0x71) {
          if (*(int *)(param_3 + 0x12) < iVar7) {
loc_4013092:
            iVar9 = 0x70;
            if (*(int *)(param_3 + 0x12) < 0x71) {
              iVar9 = *(int *)(param_3 + 0x12);
            }
          }
        }
        else if (0x70 < iVar7) goto loc_4013092;
        iVar7 = iVar7 - iVar9;
      }
      else {
        if (_mclfree == (undefined4 *)0x0) {
          _m_clalloc(1,1,0);
        }
        if (_mclfree == (undefined4 *)0x0) {
          *(undefined2 *)(piVar5 + 2) = 0x70;
        }
        else {
          _mclrefcnt[(int)_mclfree - _mbutl >> 10] =
               _mclrefcnt[(int)_mclfree - _mbutl >> 10] + '\x01';
          dword_40B61BC = dword_40B61BC + -1;
          iVar9 = (int)_mclfree - (int)piVar5;
          _mclfree = (undefined4 *)*_mclfree;
          piVar5[1] = iVar9;
          *(undefined2 *)(piVar5 + 2) = 0x400;
          *(undefined2 *)(piVar5 + 3) = 1;
        }
        if (*(sword *)(piVar5 + 2) != 0x400) goto loc_4013078;
        iVar9 = 0x400;
        if (*(int *)(param_3 + 0x12) < 0x401) {
          iVar9 = *(int *)(param_3 + 0x12);
        }
        iVar7 = iVar7 + -0x400;
      }
      uVar8 = _uiomove(piVar5[1] + (int)piVar5,iVar9,1,param_3);
      *(sword *)(piVar5 + 2) = (sword)iVar9;
      *piVar4 = (int)piVar5;
      if (uVar8 != 0) goto loc_4013154;
      piVar4 = piVar5;
      piVar5 = _mfree;
    } while (0 < *(int *)(param_3 + 0x12));
    if (bVar3) {
      *(word *)(param_1 + 2) = *(word *)(param_1 + 2) | 0x10;
    }
    uVar6 = 9;
    if ((param_4 & 1) != 0) {
      uVar6 = 0xe;
    }
    uVar8 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,uVar6,iStack_8,param_2,param_5);
    if (bVar3) {
      *(word *)(param_1 + 2) = *(word *)(param_1 + 2) & 0xffef;
    }
    param_5 = 0;
    iStack_14 = 0;
    iStack_8 = 0;
    bVar2 = false;
    if ((uVar8 != 0) || (*(int *)(param_3 + 0x12) == 0)) goto loc_4013154;
  } while( true );
  if ((*(byte *)(param_1 + 6) & 1) != 0) {
    if (((bVar2) && (uVar8 = 0x23, (*(byte *)(*_active_u + 0x16) & 0x40) != 0)) &&
       ((*(byte *)(param_3 + 0x10) & 0x20) != 0)) {
      uVar8 = 0xb;
    }
loc_4013154:
    wVar1 = *(word *)(param_1 + 0x4c);
    *(word *)(param_1 + 0x4c) = wVar1 & 0xfffe;
    if ((wVar1 & 2) != 0) {
      *(word *)(param_1 + 0x4c) = wVar1 & 0xfffc;
      _wakeup(param_1 + 0x4c);
    }
    if (iStack_8 != 0) {
      _m_freem(iStack_8);
    }
    if (uVar8 != 0x20) {
      return uVar8;
    }
    _exception_from_kernel(5,0x10001,0);
    return 0x20;
  }
  wVar1 = *(word *)(param_1 + 0x4c);
  *(word *)(param_1 + 0x4c) = wVar1 & 0xfffe;
  if ((wVar1 & 2) != 0) {
    *(word *)(param_1 + 0x4c) = wVar1 & 0xfffc;
    _wakeup(param_1 + 0x4c);
  }
  _sbwait(param_1 + 0x38);
  goto loc_4012DF0;
}
/* GHIDRADEC_FUNCTION index=404 start=0x40131b0 */

uint _soreceive(int param_1,undefined4 *param_2,int param_3,uint param_4,int *param_5)

{
  code *pcVar1;
  sword sVar2;
  word wVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  sword sVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  int iVar14;
  
  uVar11 = 0;
  iVar8 = *(int *)(param_1 + 0xc);
  if (param_5 != (int *)0x0) {
    *param_5 = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  if ((param_4 & 1) != 0) {
    iVar6 = _m_get(1,1);
    uVar11 = (**(code **)(iVar8 + 0x1a))(param_1,0xd,iVar6,param_4 & 2,0);
    if (uVar11 == 0) {
      do {
        iVar8 = *(int *)(param_3 + 0x12);
        if ((int)*(sword *)(iVar6 + 8) < *(int *)(param_3 + 0x12)) {
          iVar8 = (int)*(sword *)(iVar6 + 8);
        }
        uVar11 = _uiomove(*(int *)(iVar6 + 4) + iVar6,iVar8,0,param_3);
        iVar6 = _m_free(iVar6);
      } while (((*(int *)(param_3 + 0x12) != 0) && (uVar11 == 0)) && (iVar6 != 0));
    }
    if (iVar6 == 0) {
      return uVar11;
    }
    _m_freem(iVar6);
    return uVar11;
  }
  do {
    if ((*(byte *)(param_1 + 0x37) & 1) != 0) {
      do {
        *(word *)(param_1 + 0x36) = *(word *)(param_1 + 0x36) | 2;
        _sleep(param_1 + 0x36,0x1a);
      } while ((*(byte *)(param_1 + 0x37) & 1) != 0);
    }
    *(word *)(param_1 + 0x36) = *(word *)(param_1 + 0x36) | 1;
    if (*(sword *)(param_1 + 0x22) != 0) {
      *(int *)((int)_active_u + 0x19e) = *(int *)((int)_active_u + 0x19e) + 1;
      puVar13 = *(undefined4 **)(param_1 + 0x2e);
      if (puVar13 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(aReceive1);
      }
      uVar12 = puVar13[0x1f];
      if ((*(byte *)(iVar8 + 9) & 2) == 0) {
loc_401348C:
        if ((puVar13 != (undefined4 *)0x0) && (*(sword *)((int)puVar13 + 10) == 0xc)) {
          if ((*(byte *)(iVar8 + 9) & 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(aReceive2);
          }
          if ((param_4 & 2) == 0) {
            *(sword *)(param_1 + 0x22) = *(sword *)(param_1 + 0x22) - *(sword *)(puVar13 + 2);
            sVar10 = *(sword *)(param_1 + 0x26);
            *(sword *)(param_1 + 0x26) = sVar10 + -0x80;
            if (0x7c < (uint)puVar13[1]) {
              *(sword *)(param_1 + 0x26) = sVar10 + -0x480;
            }
            if (param_5 == (int *)0x0) {
              if (*(sword *)((int)puVar13 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
                _panic(&aMfree);
              }
              (&word_40B61CC)[*(sword *)((int)puVar13 + 10)] =
                   (&word_40B61CC)[*(sword *)((int)puVar13 + 10)] + -1;
              word_40B61CC = word_40B61CC + 1;
              *(undefined2 *)((int)puVar13 + 10) = 0;
              if (0x7f < (uint)puVar13[1]) {
                _mclput(puVar13);
              }
              *(undefined4 *)(param_1 + 0x2e) = *puVar13;
              *puVar13 = _mfree;
              puVar13[1] = 0;
              puVar13[0x1f] = 0;
              _mfree = puVar13;
              if (_m_want != 0) {
                _m_want = 0;
                _wakeup(&_mfree);
              }
            }
            else {
              *param_5 = (int)puVar13;
              *(undefined4 *)(param_1 + 0x2e) = *puVar13;
              *puVar13 = 0;
            }
            puVar13 = *(undefined4 **)(param_1 + 0x2e);
            if (puVar13 != (undefined4 *)0x0) {
              puVar13[0x1f] = uVar12;
            }
          }
          else {
            if (param_5 != (int *)0x0) {
              iVar6 = _m_copy(puVar13,0,(int)*(sword *)(puVar13 + 2));
              *param_5 = iVar6;
            }
            puVar13 = (undefined4 *)*puVar13;
          }
        }
      }
      else {
        if (*(sword *)((int)puVar13 + 10) != 8) {
                    /* WARNING: Subroutine does not return */
          _panic(aReceive1a);
        }
        if ((param_4 & 2) != 0) {
          if (param_2 != (undefined4 *)0x0) {
            uVar7 = _m_copy(puVar13,0,(int)*(sword *)(puVar13 + 2));
            *param_2 = uVar7;
          }
          puVar13 = (undefined4 *)*puVar13;
          goto loc_401348C;
        }
        *(sword *)(param_1 + 0x22) = *(sword *)(param_1 + 0x22) - *(sword *)(puVar13 + 2);
        sVar10 = *(sword *)(param_1 + 0x26);
        *(sword *)(param_1 + 0x26) = sVar10 + -0x80;
        if (0x7c < (uint)puVar13[1]) {
          *(sword *)(param_1 + 0x26) = sVar10 + -0x480;
        }
        if (param_2 == (undefined4 *)0x0) {
          if (*(sword *)((int)puVar13 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(&aMfree);
          }
          (&word_40B61CC)[*(sword *)((int)puVar13 + 10)] =
               (&word_40B61CC)[*(sword *)((int)puVar13 + 10)] + -1;
          word_40B61CC = word_40B61CC + 1;
          *(undefined2 *)((int)puVar13 + 10) = 0;
          if (0x7f < (uint)puVar13[1]) {
            _mclput(puVar13);
          }
          *(undefined4 *)(param_1 + 0x2e) = *puVar13;
          *puVar13 = _mfree;
          puVar13[1] = 0;
          puVar13[0x1f] = 0;
          _mfree = puVar13;
          if (_m_want != 0) {
            _m_want = 0;
            _wakeup(&_mfree);
          }
          puVar13 = *(undefined4 **)(param_1 + 0x2e);
        }
        else {
          *param_2 = puVar13;
          puVar13 = (undefined4 *)*puVar13;
          *(undefined4 *)*param_2 = 0;
          *(undefined4 **)(param_1 + 0x2e) = puVar13;
        }
        if (puVar13 != (undefined4 *)0x0) {
          puVar13[0x1f] = uVar12;
          goto loc_401348C;
        }
      }
      iVar14 = 0;
      iVar6 = 0;
      if ((puVar13 == (undefined4 *)0x0) || (*(int *)(param_3 + 0x12) < 1)) goto loc_4013746;
      uVar4 = param_4 & 2;
      break;
    }
    if (*(word *)(param_1 + 0x50) != 0) {
      uVar11 = (uint)*(word *)(param_1 + 0x50);
      *(undefined2 *)(param_1 + 0x50) = 0;
      goto loc_40137C2;
    }
    if ((*(word *)(param_1 + 6) & 0x20) != 0) goto loc_40137C2;
    if (((*(word *)(param_1 + 6) & 2) == 0) && ((*(byte *)(*(int *)(param_1 + 0xc) + 9) & 4) != 0))
    {
      uVar11 = 0x39;
      goto loc_40137C2;
    }
    if (*(int *)(param_3 + 0x12) == 0) goto loc_40137C2;
    if ((*(byte *)(param_1 + 6) & 1) != 0) goto loc_40132f6;
    wVar3 = *(word *)(param_1 + 0x36);
    *(word *)(param_1 + 0x36) = wVar3 & 0xfffe;
    if ((wVar3 & 2) != 0) {
      *(word *)(param_1 + 0x36) = wVar3 & 0xfffc;
      _wakeup(param_1 + 0x36);
    }
    _sbwait(param_1 + 0x22);
  } while( true );
loc_40135C4:
  if (1 < (word)(*(sword *)((int)puVar13 + 10) - 1U)) {
                    /* WARNING: Subroutine does not return */
    _panic(aReceive3);
  }
  iVar9 = *(int *)(param_3 + 0x12);
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xffbf;
  if ((*(word *)(param_1 + 0x52) != 0) &&
     (iVar5 = (uint)*(word *)(param_1 + 0x52) - iVar6, iVar5 < iVar9)) {
    iVar9 = iVar5;
  }
  if (*(sword *)(puVar13 + 2) - iVar14 < iVar9) {
    iVar9 = *(sword *)(puVar13 + 2) - iVar14;
  }
  uVar11 = _uiomove((int)puVar13 + iVar14 + puVar13[1],iVar9,0,param_3);
  sVar10 = (sword)iVar9;
  if (*(sword *)(puVar13 + 2) - iVar14 == iVar9) {
    if (uVar4 == 0) {
      uVar12 = puVar13[0x1f];
      *(sword *)(param_1 + 0x22) = *(sword *)(param_1 + 0x22) - *(sword *)(puVar13 + 2);
      sVar2 = *(sword *)(param_1 + 0x26);
      *(sword *)(param_1 + 0x26) = sVar2 + -0x80;
      if (0x7c < (uint)puVar13[1]) {
        *(sword *)(param_1 + 0x26) = sVar2 + -0x480;
      }
      if (*(sword *)((int)puVar13 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMfree);
      }
      (&word_40B61CC)[*(sword *)((int)puVar13 + 10)] =
           (&word_40B61CC)[*(sword *)((int)puVar13 + 10)] + -1;
      word_40B61CC = word_40B61CC + 1;
      *(undefined2 *)((int)puVar13 + 10) = 0;
      if (0x7f < (uint)puVar13[1]) {
        _mclput(puVar13);
      }
      *(undefined4 *)(param_1 + 0x2e) = *puVar13;
      *puVar13 = _mfree;
      puVar13[1] = 0;
      puVar13[0x1f] = 0;
      _mfree = puVar13;
      if (_m_want != 0) {
        _m_want = 0;
        _wakeup(&_mfree);
      }
      puVar13 = *(undefined4 **)(param_1 + 0x2e);
      if (puVar13 != (undefined4 *)0x0) {
        puVar13[0x1f] = uVar12;
      }
    }
    else {
      puVar13 = (undefined4 *)*puVar13;
      iVar14 = 0;
    }
  }
  else if (uVar4 == 0) {
    puVar13[1] = iVar9 + puVar13[1];
    *(sword *)(puVar13 + 2) = *(sword *)(puVar13 + 2) - sVar10;
    *(sword *)(param_1 + 0x22) = *(sword *)(param_1 + 0x22) - sVar10;
  }
  else {
    iVar14 = iVar9 + iVar14;
  }
  if (*(sword *)(param_1 + 0x52) != 0) {
    if (uVar4 == 0) {
      sVar10 = *(sword *)(param_1 + 0x52) - sVar10;
      *(sword *)(param_1 + 0x52) = sVar10;
      if (sVar10 == 0) {
        *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | 0x40;
loc_4013746:
        if ((param_4 & 2) == 0) {
          if (puVar13 == (undefined4 *)0x0) {
            *(undefined4 *)(param_1 + 0x2e) = uVar12;
          }
          else if ((*(byte *)(iVar8 + 9) & 1) != 0) {
            _sbdroprecord(param_1 + 0x22);
          }
          if (((*(byte *)(iVar8 + 9) & 8) != 0) && (*(int *)(param_1 + 8) != 0)) {
            (**(code **)(iVar8 + 0x1a))(param_1,8,0,0,0);
          }
          if (((uVar11 == 0) && (param_5 != (int *)0x0)) &&
             ((*param_5 != 0 &&
              (pcVar1 = *(code **)(*(int *)(iVar8 + 2) + 0xc), pcVar1 != (code *)0x0)))) {
            uVar11 = (*pcVar1)(*param_5);
          }
        }
        goto loc_40137C2;
      }
    }
    else {
      iVar6 = iVar9 + iVar6;
    }
  }
  if (((puVar13 == (undefined4 *)0x0) || (*(int *)(param_3 + 0x12) < 1)) || (uVar11 != 0))
  goto loc_4013746;
  goto loc_40135C4;
loc_40132f6:
  uVar11 = 0x23;
  if (((*(byte *)(*_active_u + 0x16) & 0x40) != 0) && ((*(byte *)(param_3 + 0x10) & 0x20) != 0)) {
    uVar11 = 0xb;
  }
loc_40137C2:
  wVar3 = *(word *)(param_1 + 0x36);
  *(word *)(param_1 + 0x36) = wVar3 & 0xfffe;
  if ((wVar3 & 2) != 0) {
    *(word *)(param_1 + 0x36) = wVar3 & 0xfffc;
    _wakeup(param_1 + 0x36);
  }
  return uVar11;
}
/* GHIDRADEC_FUNCTION index=405 start=0x40137fa */

undefined4 _soshutdown(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if ((param_2 + 1U & 1) != 0) {
    _sorflush(param_1);
  }
  if ((param_2 + 1U & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(iVar1 + 0x1a))(param_1,7,0,0,0);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=406 start=0x4013846 */

void _sorflush(int param_1)

{
  int iVar1;
  code *pcVar2;
  word wVar3;
  undefined4 uStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  undefined4 uStack_a;
  undefined2 uStack_6;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if ((*(byte *)(param_1 + 0x37) & 1) != 0) {
    do {
      *(word *)(param_1 + 0x36) = *(word *)(param_1 + 0x36) | 2;
      _sleep(param_1 + 0x36,0x1a);
    } while ((*(byte *)(param_1 + 0x37) & 1) != 0);
  }
  *(word *)(param_1 + 0x36) = *(word *)(param_1 + 0x36) | 1;
  _socantrcvmore(param_1);
  wVar3 = *(word *)(param_1 + 0x36);
  *(word *)(param_1 + 0x36) = wVar3 & 0xfffe;
  if ((wVar3 & 2) != 0) {
    *(word *)(param_1 + 0x36) = wVar3 & 0xfffc;
    _wakeup(param_1 + 0x36);
  }
  uStack_1a = *(undefined4 *)(param_1 + 0x22);
  uStack_16 = *(undefined4 *)(param_1 + 0x26);
  uStack_12 = *(undefined4 *)(param_1 + 0x2a);
  uStack_e = *(undefined4 *)(param_1 + 0x2e);
  uStack_a = *(undefined4 *)(param_1 + 0x32);
  uStack_6 = *(undefined2 *)(param_1 + 0x36);
  _bzero((undefined4 *)(param_1 + 0x22),0x16);
  if (((*(byte *)(iVar1 + 9) & 0x10) != 0) &&
     (pcVar2 = *(code **)(*(int *)(iVar1 + 2) + 0x10), pcVar2 != (code *)0x0)) {
    (*pcVar2)(uStack_e);
  }
  _sbrelease(&uStack_1a);
  return;
}
/* GHIDRADEC_FUNCTION index=407 start=0x4013920 */

undefined4 _sosetopt(int param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = param_4;
  uVar3 = 0;
  if (param_2 != 0xffff) {
    if ((*(int *)(param_1 + 0xc) != 0) &&
       (pcVar1 = *(code **)(*(int *)(param_1 + 0xc) + 0x16), pcVar1 != (code *)0x0)) {
      uVar3 = (*pcVar1)(1,param_1,param_2,param_3,&param_4);
      return uVar3;
    }
    goto loc_4013AA2;
  }
  if (param_3 == 0x20) {
loc_40139D6:
    if ((param_4 != 0) && (3 < *(word *)(param_4 + 8))) {
      if (*(int *)(param_4 + *(int *)(param_4 + 4)) == 0) {
        *(word *)(param_1 + 2) = ~(word)param_3 & *(word *)(param_1 + 2);
      }
      else {
        *(word *)(param_1 + 2) = (word)param_3 | *(word *)(param_1 + 2);
      }
      goto loc_4013AA4;
    }
  }
  else {
    if (param_3 < 0x21) {
      if (param_3 != 4) {
        if (param_3 < 5) {
          iVar4 = 1;
        }
        else {
          if (param_3 == 8) goto loc_40139D6;
          iVar4 = 0x10;
        }
        if (iVar4 != param_3) {
loc_4013AA2:
          uVar3 = 0x2a;
          goto loc_4013AA4;
        }
      }
      goto loc_40139D6;
    }
    if (param_3 == 0x100) goto loc_40139D6;
    if (param_3 < 0x101) {
      if (param_3 != 0x40) {
        if (param_3 != 0x80) goto loc_4013AA2;
        if ((param_4 == 0) || (*(sword *)(param_4 + 8) != 8)) goto loc_4013A0C;
        *(undefined2 *)(param_1 + 4) = *(undefined2 *)(param_4 + 6 + *(int *)(param_4 + 4));
      }
      goto loc_40139D6;
    }
    if ((0x1006 < param_3) || (param_3 < 0x1001)) goto loc_4013AA2;
    if ((param_4 != 0) && (3 < *(word *)(param_4 + 8))) {
      switch(param_3) {
      case :
      case :
        if (param_3 == 0x1001) {
          param_1 = param_1 + 0x38;
        }
        else {
          param_1 = param_1 + 0x22;
        }
        iVar4 = _sbreserve(param_1,*(undefined4 *)(param_4 + *(int *)(param_4 + 4)));
        if (iVar4 == 0) {
          uVar3 = 0x37;
        }
        break;
      case :
        *(undefined2 *)(param_1 + 0x40) = *(undefined2 *)(param_4 + 2 + *(int *)(param_4 + 4));
        break;
      case :
        *(undefined2 *)(param_1 + 0x2a) = *(undefined2 *)(param_4 + 2 + *(int *)(param_4 + 4));
        break;
      case :
        *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_4 + 2 + *(int *)(param_4 + 4));
        break;
      case :
        *(undefined2 *)(param_1 + 0x2c) = *(undefined2 *)(param_4 + 2 + *(int *)(param_4 + 4));
      }
      goto loc_4013AA4;
    }
  }
loc_4013A0C:
  uVar3 = 0x16;
loc_4013AA4:
  if (iVar2 != 0) {
    _m_free(iVar2);
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=408 start=0x4013abc */

undefined4 _sogetopt(sword *param_1,int param_2,uint param_3,int *param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_2 != 0xffff) {
    if (*(int *)(param_1 + 6) == 0) {
      return 0x2a;
    }
    pcVar1 = *(code **)(*(int *)(param_1 + 6) + 0x16);
    if (pcVar1 == (code *)0x0) {
      return 0x2a;
    }
    uVar2 = (*pcVar1)(0,param_1,param_2,param_3,param_4);
    return uVar2;
  }
  iVar3 = _m_get(1,10);
  *(undefined2 *)(iVar3 + 8) = 4;
  if (param_3 != 0x100) {
    if (0x100 < (int)param_3) {
      if (param_3 != 0x1004) {
        if (0x1004 < (int)param_3) {
          if (param_3 == 0x1006) {
            *(int *)(iVar3 + *(int *)(iVar3 + 4)) = (int)param_1[0x16];
          }
          else if ((int)param_3 < 0x1006) {
            *(int *)(iVar3 + *(int *)(iVar3 + 4)) = (int)param_1[0x21];
          }
          else if (param_3 == 0x1007) {
            *(uint *)(iVar3 + *(int *)(iVar3 + 4)) = (uint)(word)param_1[0x28];
            param_1[0x28] = 0;
          }
          else {
            if (param_3 != 0x1008) goto loc_4013C64;
            *(int *)(iVar3 + *(int *)(iVar3 + 4)) = (int)*param_1;
          }
          goto loc_4013C70;
        }
        if (param_3 == 0x1002) {
          *(uint *)(iVar3 + *(int *)(iVar3 + 4)) = (uint)(word)param_1[0x12];
          goto loc_4013C70;
        }
        if (0x1002 < (int)param_3) {
          *(uint *)(iVar3 + *(int *)(iVar3 + 4)) = (uint)(word)param_1[0x20];
          goto loc_4013C70;
        }
        if (param_3 == 0x1001) {
          *(uint *)(iVar3 + *(int *)(iVar3 + 4)) = (uint)(word)param_1[0x1d];
          goto loc_4013C70;
        }
        goto loc_4013C64;
      }
      *(uint *)(iVar3 + *(int *)(iVar3 + 4)) = (uint)(word)param_1[0x15];
      goto loc_4013C70;
    }
    if (param_3 != 0x10) {
      if ((int)param_3 < 0x11) {
        if (param_3 != 4) {
          if ((int)param_3 < 5) {
            uVar4 = 1;
          }
          else {
            uVar4 = 8;
          }
loc_4013B4C:
          if (uVar4 != param_3) {
loc_4013C64:
            _m_free(iVar3);
            return 0x2a;
          }
        }
      }
      else if (param_3 != 0x40) {
        if (0x40 < (int)param_3) {
          if (param_3 != 0x80) goto loc_4013C64;
          *(undefined2 *)(iVar3 + 8) = 8;
          *(uint *)(iVar3 + *(int *)(iVar3 + 4)) = *(byte *)((int)param_1 + 3) & 0x80;
          *(int *)(iVar3 + 4 + *(int *)(iVar3 + 4)) = (int)param_1[2];
          goto loc_4013C70;
        }
        uVar4 = 0x20;
        goto loc_4013B4C;
      }
    }
  }
  *(uint *)(iVar3 + *(int *)(iVar3 + 4)) = param_3 & (int)param_1[1];
loc_4013C70:
  *param_4 = iVar3;
  return 0;
}
/* GHIDRADEC_FUNCTION index=409 start=0x4013c7e */

void _sohasoutofband(int param_1)

{
  sword sVar1;
  int iVar2;
  
  sVar1 = *(sword *)(param_1 + 0x54);
  if (sVar1 < 0) {
    _gsignal(-(int)sVar1,0x10);
  }
  else if ((0 < sVar1) && (iVar2 = _pfind((int)sVar1), iVar2 != 0)) {
    _psignal(iVar2,0x10);
  }
  if (*(int *)(param_1 + 0x32) != 0) {
    _selwakeup(*(int *)(param_1 + 0x32),*(byte *)(param_1 + 0x37) & 0x10);
    _selthreadclear(param_1 + 0x32);
    *(word *)(param_1 + 0x36) = *(word *)(param_1 + 0x36) & 0xffef;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=410 start=0x4013cfa */

void _soisconnecting(int param_1)

{
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfff5 | 4;
  _wakeup(param_1 + 0x4e);
  return;
}
/* GHIDRADEC_FUNCTION index=411 start=0x4013d20 */

void _soisconnected(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    iVar2 = _soqremque(param_1,0);
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aSoisconnected);
    }
    _soqinsque(iVar1,param_1,1);
    _sowakeup(iVar1,iVar1 + 0x22);
    _wakeup(iVar1 + 0x4e);
  }
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfff3 | 2;
  _wakeup(param_1 + 0x4e);
  _sowakeup(param_1,param_1 + 0x22);
  _sowakeup(param_1,param_1 + 0x38);
  return;
}
/* GHIDRADEC_FUNCTION index=412 start=0x4013db6 */

void _soisdisconnecting(int param_1)

{
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfffb | 0x38;
  _wakeup(param_1 + 0x4e);
  _sowakeup(param_1,param_1 + 0x38);
  _sowakeup(param_1,param_1 + 0x22);
  return;
}
/* GHIDRADEC_FUNCTION index=413 start=0x4013dfe */

void _soisdisconnected(int param_1)

{
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfff1 | 0x30;
  _wakeup(param_1 + 0x4e);
  _sowakeup(param_1,param_1 + 0x38);
  _sowakeup(param_1,param_1 + 0x22);
  return;
}
/* GHIDRADEC_FUNCTION index=414 start=0x4013e46 */

undefined2 * _sonewconn(undefined2 *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  
  iVar1 = (sword)param_1[0x10] * 3;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 1;
  }
  if (((int)(sword)param_1[0xc] + (int)(sword)param_1[0xf] <= iVar1 >> 1) &&
     (iVar1 = _m_getclr(0,3), iVar1 != 0)) {
    puVar3 = (undefined2 *)(*(int *)(iVar1 + 4) + iVar1);
    *puVar3 = *param_1;
    puVar3[1] = param_1[1] & 0xfffd;
    puVar3[2] = param_1[2];
    puVar3[3] = param_1[3] | 1;
    *(undefined4 *)(puVar3 + 6) = *(undefined4 *)(param_1 + 6);
    puVar3[0x27] = param_1[0x27];
    puVar3[0x2a] = param_1[0x2a];
    _soqinsque(param_1,puVar3,0);
    iVar2 = (**(code **)(*(int *)(puVar3 + 6) + 0x1a))(puVar3,0,0,0,0);
    if (iVar2 == 0) {
      return puVar3;
    }
    if (*(int *)(puVar3 + 8) != 0) {
      _soqremque(puVar3,0);
    }
    _m_free(iVar1);
  }
  return (undefined2 *)0x0;
}
/* GHIDRADEC_FUNCTION index=415 start=0x4013f14 */

void _soqinsque(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  *(int *)(param_2 + 0x10) = param_1;
  if (param_3 == 0) {
    *(sword *)(param_1 + 0x18) = *(sword *)(param_1 + 0x18) + 1;
    iVar1 = *(int *)(param_1 + 0x14);
    iVar2 = param_1;
    while (param_1 != iVar1) {
      iVar2 = *(int *)(iVar2 + 0x14);
      iVar1 = *(int *)(iVar2 + 0x14);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(iVar2 + 0x14);
    *(int *)(iVar2 + 0x14) = param_2;
  }
  else {
    *(sword *)(param_1 + 0x1e) = *(sword *)(param_1 + 0x1e) + 1;
    iVar1 = *(int *)(param_1 + 0x1a);
    iVar2 = param_1;
    while (param_1 != iVar1) {
      iVar2 = *(int *)(iVar2 + 0x1a);
      iVar1 = *(int *)(iVar2 + 0x1a);
    }
    *(undefined4 *)(param_2 + 0x1a) = *(undefined4 *)(iVar2 + 0x1a);
    *(int *)(iVar2 + 0x1a) = param_2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=416 start=0x4013f6e */

undefined4 _soqremque(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar3 = iVar1;
  while( true ) {
    if (param_2 == 0) {
      iVar2 = *(int *)(iVar3 + 0x14);
    }
    else {
      iVar2 = *(int *)(iVar3 + 0x1a);
    }
    if (param_1 == iVar2) break;
    iVar3 = iVar2;
    if (iVar1 == iVar2) {
      return 0;
    }
  }
  if (param_2 == 0) {
    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar2 + 0x14);
    *(sword *)(iVar1 + 0x18) = *(sword *)(iVar1 + 0x18) + -1;
  }
  else {
    *(undefined4 *)(iVar3 + 0x1a) = *(undefined4 *)(iVar2 + 0x1a);
    *(sword *)(iVar1 + 0x1e) = *(sword *)(iVar1 + 0x1e) + -1;
  }
  *(undefined4 *)(iVar2 + 0x1a) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  return 1;
}
/* GHIDRADEC_FUNCTION index=417 start=0x4013fd6 */

void _socantsendmore(int param_1)

{
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | 0x10;
  _sowakeup(param_1,param_1 + 0x38);
  return;
}
/* GHIDRADEC_FUNCTION index=418 start=0x4013ff4 */

void _socantrcvmore(int param_1)

{
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | 0x20;
  _sowakeup(param_1,param_1 + 0x22);
  return;
}
/* GHIDRADEC_FUNCTION index=419 start=0x4014012 */

void _sbselqueue(int param_1)

{
  int iVar1;
  
  iVar1 = _selthreadcache(param_1 + 0x10);
  if (iVar1 != 0) {
    *(word *)(param_1 + 0x14) = *(word *)(param_1 + 0x14) | 0x10;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=420 start=0x4014038 */

void _sbwait(int param_1)

{
  *(word *)(param_1 + 0x14) = *(word *)(param_1 + 0x14) | 4;
  _sleep(param_1,0x1a);
  return;
}
/* GHIDRADEC_FUNCTION index=421 start=0x4014056 */

void _sbwakeup(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    _selwakeup(*(int *)(param_1 + 0x10),*(byte *)(param_1 + 0x15) & 0x10);
    _selthreadclear(param_1 + 0x10);
    *(word *)(param_1 + 0x14) = *(word *)(param_1 + 0x14) & 0xffef;
  }
  if ((*(word *)(param_1 + 0x14) & 4) != 0) {
    *(word *)(param_1 + 0x14) = *(word *)(param_1 + 0x14) & 0xfffb;
    if (_nfs_wakeup_one_nfsd == 1) {
      _wakeup_one(param_1);
    }
    else {
      _wakeup(param_1);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=422 start=0x40140d4 */

void _sowakeup(int param_1,undefined4 param_2)

{
  sword sVar1;
  int iVar2;
  
  _sbwakeup(param_2);
  if ((*(byte *)(param_1 + 6) & 2) != 0) {
    sVar1 = *(sword *)(param_1 + 0x54);
    if (sVar1 < 0) {
      _gsignal(-(int)sVar1,0x17);
    }
    else if (0 < sVar1) {
      iVar2 = _pfind((int)sVar1);
      if (iVar2 != 0) {
        _psignal(iVar2,0x17);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=423 start=0x4014134 */

undefined4 _soreserve(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = _sbreserve(param_1 + 0x38,param_2);
  if (iVar1 != 0) {
    iVar1 = _sbreserve(param_1 + 0x22,param_3);
    if (iVar1 != 0) {
      return 0;
    }
    _sbrelease(param_1 + 0x38);
  }
  return 0x37;
}
/* GHIDRADEC_FUNCTION index=424 start=0x4014180 */

undefined4 _sbreserve(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 < 0xcccd) {
    *(sword *)(param_1 + 2) = (sword)param_2;
    iVar2 = param_2 * 2;
    if (0xffff < iVar2) {
      iVar2 = 0xffff;
    }
    *(sword *)(param_1 + 6) = (sword)iVar2;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=425 start=0x40141b4 */

byte _sbrelease(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  _sbflush(param_1);
  *(undefined2 *)(param_1 + 6) = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  cVar1 = '\0';
  cVar4 = '\0';
  bVar5 = 0;
  cVar2 = *(int *)(param_1 + 0x10) < 0;
  cVar3 = *(int *)(param_1 + 0x10) == 0;
  if (!(bool)cVar3) {
    _selthreadclear(param_1 + 0x10);
  }
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=426 start=0x40141fc */

void _sbappend(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 != 0) {
    piVar2 = *(int **)(param_1 + 0xc);
    if (piVar2 != (int *)0x0) {
      iVar1 = piVar2[0x1f];
      while (iVar1 != 0) {
        piVar2 = (int *)piVar2[0x1f];
        iVar1 = piVar2[0x1f];
      }
      for (; *piVar2 != 0; piVar2 = (int *)*piVar2) {
      }
    }
    _sbcompress(param_1,param_2,piVar2);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=427 start=0x401423a */

void _sbappendrecord(sword *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  sword sVar3;
  int iVar4;
  
  if (param_2 != (undefined4 *)0x0) {
    iVar4 = *(int *)(param_1 + 6);
    if (iVar4 != 0) {
      iVar2 = *(int *)(iVar4 + 0x7c);
      while (iVar2 != 0) {
        iVar4 = *(int *)(iVar4 + 0x7c);
        iVar2 = *(int *)(iVar4 + 0x7c);
      }
    }
    *param_1 = *(sword *)(param_2 + 2) + *param_1;
    sVar3 = param_1[2];
    param_1[2] = sVar3 + 0x80;
    if (0x7c < (uint)param_2[1]) {
      param_1[2] = sVar3 + 0x480;
    }
    if (iVar4 == 0) {
      *(undefined4 **)(param_1 + 6) = param_2;
    }
    else {
      *(undefined4 **)(iVar4 + 0x7c) = param_2;
    }
    uVar1 = *param_2;
    *param_2 = 0;
    _sbcompress(param_1,uVar1,param_2);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=428 start=0x40142ae */

undefined4 _sbappendaddr(word *param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  word wVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  
  piVar4 = _mfree;
  iVar5 = 0x10;
  for (puVar6 = param_3; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {
    iVar5 = *(sword *)(puVar6 + 2) + iVar5;
  }
  if (param_4 != 0) {
    iVar5 = *(sword *)(param_4 + 8) + iVar5;
  }
  iVar3 = (uint)param_1[1] - (uint)*param_1;
  if ((int)((uint)param_1[3] - (uint)param_1[2]) < (int)((uint)param_1[1] - (uint)*param_1)) {
    iVar3 = (uint)param_1[3] - (uint)param_1[2];
  }
  if (iVar5 <= iVar3) {
    if (_mfree == (int *)0x0) {
      piVar4 = (int *)_m_more(0,8);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMget);
      }
      *(undefined2 *)((int)_mfree + 10) = 8;
      word_40B61CC = word_40B61CC + -1;
      word_40B61DC = word_40B61DC + 1;
      piVar2 = (int *)*_mfree;
      *_mfree = 0;
      _mfree = piVar2;
      piVar4[1] = 0xc;
    }
    if (piVar4 != (int *)0x0) {
      puVar6 = (undefined4 *)(piVar4[1] + (int)piVar4);
      *puVar6 = *param_2;
      puVar6[1] = param_2[1];
      puVar6[2] = param_2[2];
      puVar6[3] = param_2[3];
      *(undefined2 *)(piVar4 + 2) = 0x10;
      if ((param_4 != 0) && (*(sword *)(param_4 + 8) != 0)) {
        iVar5 = _m_copy(param_4,0,(int)*(sword *)(param_4 + 8));
        *piVar4 = iVar5;
        if (iVar5 == 0) {
          _m_freem(piVar4);
          return 0;
        }
        *param_1 = *(sword *)(iVar5 + 8) + *param_1;
        wVar1 = param_1[2];
        param_1[2] = wVar1 + 0x80;
        if (0x7c < *(uint *)(*piVar4 + 4)) {
          param_1[2] = wVar1 + 0x480;
        }
      }
      *param_1 = *(sword *)(piVar4 + 2) + *param_1;
      wVar1 = param_1[2];
      param_1[2] = wVar1 + 0x80;
      if (0x7c < (uint)piVar4[1]) {
        param_1[2] = wVar1 + 0x480;
      }
      iVar5 = *(int *)(param_1 + 6);
      if (iVar5 == 0) {
        *(int **)(param_1 + 6) = piVar4;
      }
      else {
        iVar3 = *(int *)(iVar5 + 0x7c);
        while (iVar3 != 0) {
          iVar5 = *(int *)(iVar5 + 0x7c);
          iVar3 = *(int *)(iVar5 + 0x7c);
        }
        *(int **)(iVar5 + 0x7c) = piVar4;
      }
      if ((int *)*piVar4 != (int *)0x0) {
        piVar4 = (int *)*piVar4;
      }
      if (param_3 != (undefined4 *)0x0) {
        _sbcompress(param_1,param_3,piVar4);
      }
      return 1;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=429 start=0x4014448 */

undefined4 _sbappendrights(word *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  word wVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = 0;
  puVar3 = param_2;
  if (param_3 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSbappendrights);
  }
  for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
    iVar6 = *(sword *)(puVar3 + 2) + iVar6;
  }
  iVar4 = (uint)param_1[1] - (uint)*param_1;
  if ((int)((uint)param_1[3] - (uint)param_1[2]) < (int)((uint)param_1[1] - (uint)*param_1)) {
    iVar4 = (uint)param_1[3] - (uint)param_1[2];
  }
  if ((iVar4 < *(sword *)(param_3 + 8) + iVar6) ||
     (iVar6 = _m_copy(param_3,0,(int)*(sword *)(param_3 + 8)), iVar6 == 0)) {
    uVar5 = 0;
  }
  else {
    *param_1 = *(sword *)(iVar6 + 8) + *param_1;
    wVar2 = param_1[2];
    param_1[2] = wVar2 + 0x80;
    if (0x7c < *(uint *)(iVar6 + 4)) {
      param_1[2] = wVar2 + 0x480;
    }
    iVar4 = *(int *)(param_1 + 6);
    if (iVar4 == 0) {
      *(int *)(param_1 + 6) = iVar6;
    }
    else {
      iVar1 = *(int *)(iVar4 + 0x7c);
      while (iVar1 != 0) {
        iVar4 = *(int *)(iVar4 + 0x7c);
        iVar1 = *(int *)(iVar4 + 0x7c);
      }
      *(int *)(iVar4 + 0x7c) = iVar6;
    }
    if (param_2 != (undefined4 *)0x0) {
      _sbcompress(param_1,param_2,iVar6);
    }
    uVar5 = 1;
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=430 start=0x401452c */

void _sbcompress(sword *param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  sword sVar2;
  undefined4 *puVar3;
  
loc_4014540:
  do {
    while( true ) {
      puVar3 = param_2;
      if (puVar3 == (undefined4 *)0x0) {
        return;
      }
      sVar2 = *(sword *)(puVar3 + 2);
      if (sVar2 != 0) break;
      param_2 = (undefined4 *)_m_free(puVar3);
    }
    if (((param_3 != (undefined4 *)0x0) && (uVar1 = param_3[1], uVar1 < 0x7d)) &&
       ((uint)puVar3[1] < 0x7d)) {
      if (((int)sVar2 + (int)*(sword *)(param_3 + 2) + uVar1 < 0x7d) &&
         (*(sword *)((int)puVar3 + 10) == *(sword *)((int)param_3 + 10))) {
        _bcopy((int)puVar3 + puVar3[1],(int)param_3 + (int)*(sword *)(param_3 + 2) + uVar1,
               (int)sVar2);
        *(sword *)(param_3 + 2) = *(sword *)(puVar3 + 2) + *(sword *)(param_3 + 2);
        *param_1 = *(sword *)(puVar3 + 2) + *param_1;
        param_2 = (undefined4 *)_m_free(puVar3);
        goto loc_4014540;
      }
    }
    *param_1 = *(sword *)(puVar3 + 2) + *param_1;
    sVar2 = param_1[2];
    param_1[2] = sVar2 + 0x80;
    if (0x7c < (uint)puVar3[1]) {
      param_1[2] = sVar2 + 0x480;
    }
    if (param_3 == (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 6) = puVar3;
    }
    else {
      *param_3 = puVar3;
    }
    param_2 = (undefined4 *)*puVar3;
    *puVar3 = 0;
    param_3 = puVar3;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=431 start=0x4014600 */

void _sbflush(sword *param_1)

{
  sword sVar1;
  
  if ((*(byte *)((int)param_1 + 0x15) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aSbflush);
  }
  sVar1 = param_1[2];
  while (sVar1 != 0) {
    _sbdrop(param_1,*param_1);
    sVar1 = param_1[2];
  }
  if (((*param_1 == 0) && (param_1[2] == 0)) && (*(int *)(param_1 + 6) == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aSbflush2);
}
/* GHIDRADEC_FUNCTION index=432 start=0x4014666 */

void _sbdrop(sword *param_1,int param_2)

{
  undefined4 *puVar1;
  sword sVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(param_1 + 6);
  puVar3 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)puVar1[0x1f];
  }
  while (puVar4 = puVar1, 0 < param_2) {
    if (puVar4 == (undefined4 *)0x0) {
      if (puVar3 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aSbdrop);
      }
      puVar1 = puVar3;
      puVar3 = (undefined4 *)puVar3[0x1f];
    }
    else {
      sVar2 = *(sword *)(puVar4 + 2);
      if (param_2 < sVar2) {
        *(sword *)(puVar4 + 2) = sVar2 - (sword)param_2;
        puVar4[1] = param_2 + puVar4[1];
        *param_1 = *param_1 - (sword)param_2;
        break;
      }
      param_2 = param_2 - sVar2;
      *param_1 = *param_1 - sVar2;
      sVar2 = param_1[2];
      param_1[2] = sVar2 + -0x80;
      if (0x7c < (uint)puVar4[1]) {
        param_1[2] = sVar2 + -0x480;
      }
      if (*(sword *)((int)puVar4 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMfree);
      }
      (&word_40B61CC)[*(sword *)((int)puVar4 + 10)] =
           (&word_40B61CC)[*(sword *)((int)puVar4 + 10)] + -1;
      word_40B61CC = word_40B61CC + 1;
      *(undefined2 *)((int)puVar4 + 10) = 0;
      if (0x7f < (uint)puVar4[1]) {
        _mclput(puVar4);
      }
      puVar1 = (undefined4 *)*puVar4;
      *puVar4 = _mfree;
      puVar4[1] = 0;
      puVar4[0x1f] = 0;
      _mfree = puVar4;
      if (_m_want != 0) {
        _m_want = 0;
        _wakeup(&_mfree);
      }
    }
  }
  if (puVar4 != (undefined4 *)0x0) {
    sVar2 = *(sword *)(puVar4 + 2);
    while (sVar2 == 0) {
      *param_1 = *param_1;
      sVar2 = param_1[2];
      param_1[2] = sVar2 + -0x80;
      if (0x7c < (uint)puVar4[1]) {
        param_1[2] = sVar2 + -0x480;
      }
      if (*(sword *)((int)puVar4 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMfree);
      }
      (&word_40B61CC)[*(sword *)((int)puVar4 + 10)] =
           (&word_40B61CC)[*(sword *)((int)puVar4 + 10)] + -1;
      word_40B61CC = word_40B61CC + 1;
      *(undefined2 *)((int)puVar4 + 10) = 0;
      if (0x7f < (uint)puVar4[1]) {
        _mclput(puVar4);
      }
      puVar1 = (undefined4 *)*puVar4;
      *puVar4 = _mfree;
      puVar4[1] = 0;
      puVar4[0x1f] = 0;
      _mfree = puVar4;
      if (_m_want != 0) {
        _m_want = 0;
        _wakeup(&_mfree);
      }
      if (puVar1 == (undefined4 *)0x0) goto loc_401482E;
      puVar4 = puVar1;
      sVar2 = *(sword *)(puVar1 + 2);
    }
    if (puVar4 != (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 6) = puVar4;
      puVar4[0x1f] = puVar3;
      return;
    }
  }
loc_401482E:
  *(undefined4 **)(param_1 + 6) = puVar3;
  return;
}
/* GHIDRADEC_FUNCTION index=433 start=0x401483c */

void _sbdroprecord(sword *param_1)

{
  int *piVar1;
  sword sVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 6);
  if (piVar3 != (int *)0x0) {
    *(int *)(param_1 + 6) = piVar3[0x1f];
    do {
      *param_1 = *param_1 - *(sword *)(piVar3 + 2);
      sVar2 = param_1[2];
      param_1[2] = sVar2 + -0x80;
      if (0x7c < (uint)piVar3[1]) {
        param_1[2] = sVar2 + -0x480;
      }
      if (*(sword *)((int)piVar3 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMfree);
      }
      (&word_40B61CC)[*(sword *)((int)piVar3 + 10)] =
           (&word_40B61CC)[*(sword *)((int)piVar3 + 10)] + -1;
      word_40B61CC = word_40B61CC + 1;
      *(undefined2 *)((int)piVar3 + 10) = 0;
      if (0x7f < (uint)piVar3[1]) {
        _mclput(piVar3);
      }
      piVar1 = (int *)*piVar3;
      *piVar3 = (int)_mfree;
      piVar3[1] = 0;
      piVar3[0x1f] = 0;
      _mfree = piVar3;
      if (_m_want != 0) {
        _m_want = 0;
        _wakeup(&_mfree);
      }
      piVar3 = piVar1;
    } while (piVar1 != (int *)0x0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=434 start=0x4014908 */

void _socket(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _falloc();
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 8) = 3;
    *(undefined2 *)(iVar2 + 0xc) = 2;
    *(undefined **)(iVar2 + 0x12) = _socketops;
    uVar3 = _socreate(*puVar1,&uStack_8,puVar1[1],puVar1[2]);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      *(undefined4 *)(iVar2 + 0x16) = uStack_8;
      *(int *)(*(int *)(_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = iVar2;
    }
    else {
      *(undefined4 *)(*(int *)(_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = 0;
      *(undefined2 *)(iVar2 + 0xe) = 0;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=435 start=0x40149a6 */

void _bind(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _getsock(*puVar1);
  if (iVar2 != 0) {
    uVar3 = _sockargs(&uStack_8,puVar1[1],puVar1[2],8);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      uVar3 = _sobind(*(undefined4 *)(iVar2 + 0x16),uStack_8);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
      _m_freem(uStack_8);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=436 start=0x4014a26 */

void _listen(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _getsock(*puVar1);
  if (iVar2 != 0) {
    uVar3 = _solisten(*(undefined4 *)(iVar2 + 0x16),puVar1[1]);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=437 start=0x4014a66 */

uint _accept(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  byte bVar10;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  if (puVar1[1] != 0) {
    uVar3 = _copyinmsg(puVar1[2],&iStack_8,4);
    *(char *)(dword_40B57D4 + 100) = (char)uVar3;
    if (*(char *)(dword_40B57D4 + 100) != '\0') {
      return uVar3;
    }
    iVar4 = _useracc(puVar1[1],iStack_8,0);
    if (iVar4 == 0) {
      *(undefined *)(dword_40B57D4 + 100) = 0xe;
      return 0;
    }
  }
  iVar4 = _getsock(*puVar1);
  if (iVar4 == 0) {
    return 0;
  }
  cVar6 = '\0';
  iVar4 = *(int *)(iVar4 + 0x16);
  if ((*(byte *)(iVar4 + 3) & 2) == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
    return 0;
  }
  if ((*(byte *)(iVar4 + 6) & 1) == 0) {
    if (*(sword *)(iVar4 + 0x1e) == 0) {
      if (*(sword *)(iVar4 + 0x50) != 0) goto loc_4014B70;
      while ((*(byte *)(iVar4 + 7) & 0x20) == 0) {
        _sleep(iVar4 + 0x4e,0x1a);
        if ((*(sword *)(iVar4 + 0x1e) != 0) || (*(sword *)(iVar4 + 0x50) != 0)) goto loc_4014B6A;
      }
      *(undefined2 *)(iVar4 + 0x50) = 0x35;
    }
  }
  else if (*(sword *)(iVar4 + 0x1e) == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0x23;
    return 0;
  }
loc_4014B6A:
  if (*(sword *)(iVar4 + 0x50) == 0) {
    iVar5 = _falloc();
    if (iVar5 == 0) {
      *(undefined4 *)(*(int *)(_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = 0;
      return (uint)(byte)(cVar6 << 4 | 4);
    }
    uVar2 = *(undefined4 *)(iVar4 + 0x1a);
    iVar4 = _soqremque(uVar2,1);
    if (iVar4 != 0) {
      *(undefined2 *)(iVar5 + 0xc) = 2;
      *(undefined4 *)(iVar5 + 8) = 3;
      *(undefined **)(iVar5 + 0x12) = _socketops;
      *(undefined4 *)(iVar5 + 0x16) = uVar2;
      *(int *)(*(int *)(_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = iVar5;
      uVar3 = _m_get(1,8);
      _soaccept(uVar2,uVar3);
      if (puVar1[1] != 0) {
        if (*(sword *)(uVar3 + 8) < iStack_8) {
          iStack_8 = (int)*(sword *)(uVar3 + 8);
        }
        cVar6 = CARRY4(*(uint *)(uVar3 + 4),uVar3);
        _copyoutmsg(*(uint *)(uVar3 + 4) + uVar3,puVar1[1],iStack_8);
        _copyoutmsg(&iStack_8,puVar1[2],4);
      }
      cVar7 = (int)uVar3 < 0;
      cVar8 = uVar3 == 0;
      cVar9 = '\0';
      bVar10 = 0;
      _m_freem(uVar3);
      return (uint)(byte)(cVar6 << 4 | cVar7 << 3 | cVar8 << 2 | cVar9 << 1 | bVar10);
    }
                    /* WARNING: Subroutine does not return */
    _panic(&aAccept);
  }
loc_4014B70:
  *(undefined *)(dword_40B57D4 + 100) = *(undefined *)(iVar4 + 0x51);
  *(undefined2 *)(iVar4 + 0x50) = 0;
  return (uint)(byte)(cVar6 << 4 | 4);
}
/* GHIDRADEC_FUNCTION index=438 start=0x4014c7a */

void _connect(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar4;
  int iVar3;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _getsock(*puVar1);
  if (iVar2 == 0) {
    return;
  }
  iVar2 = *(int *)(iVar2 + 0x16);
  if ((*(word *)(iVar2 + 6) & 0x104) == 0x104) {
    *(undefined *)(dword_40B57D4 + 100) = 0x25;
    return;
  }
  uVar4 = _sockargs(&uStack_8,puVar1[1],puVar1[2],8);
  *(undefined *)(dword_40B57D4 + 100) = uVar4;
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return;
  }
  uVar4 = _soconnect(iVar2,uStack_8);
  *(undefined *)(dword_40B57D4 + 100) = uVar4;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    if ((*(word *)(iVar2 + 6) & 0x104) == 0x104) {
      *(undefined *)(dword_40B57D4 + 100) = 0x24;
      goto loc_4014DBC;
    }
    iVar3 = _setjmp(dword_40B57D4 + 0x28);
    if (iVar3 == 0) {
      while (((*(byte *)(iVar2 + 7) & 4) != 0 && (*(sword *)(iVar2 + 0x50) == 0))) {
        _sleep(iVar2 + 0x4e,0x1a);
      }
      *(undefined *)(dword_40B57D4 + 100) = *(undefined *)(iVar2 + 0x51);
      *(undefined2 *)(iVar2 + 0x50) = 0;
    }
    else if (*(char *)(dword_40B57D4 + 100) == '\0') {
      *(undefined *)(dword_40B57D4 + 100) = 4;
    }
  }
  *(word *)(iVar2 + 6) = *(word *)(iVar2 + 6) & 0xfffb;
loc_4014DBC:
  _m_freem(uStack_8);
  return;
}
/* GHIDRADEC_FUNCTION index=439 start=0x4014dce */

void _socketpair(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar4;
  int iVar3;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _useracc(puVar1[3],8,0);
  if (iVar2 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0xe;
    return;
  }
  uVar4 = _socreate(*puVar1,&uStack_8,puVar1[1],puVar1[2]);
  *(undefined *)(dword_40B57D4 + 100) = uVar4;
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return;
  }
  uVar4 = _socreate(*puVar1,&uStack_c,puVar1[1],puVar1[2]);
  *(undefined *)(dword_40B57D4 + 100) = uVar4;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    iVar2 = _falloc();
    if (iVar2 != 0) {
      iStack_14 = *(int *)(dword_40B57D4 + 0x5c);
      *(undefined4 *)(iVar2 + 8) = 3;
      *(undefined2 *)(iVar2 + 0xc) = 2;
      *(undefined **)(iVar2 + 0x12) = _socketops;
      *(undefined4 *)(iVar2 + 0x16) = uStack_8;
      *(int *)(*(int *)(_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = iVar2;
      iVar3 = _falloc();
      if (iVar3 != 0) {
        *(undefined4 *)(iVar3 + 8) = 3;
        *(undefined2 *)(iVar3 + 0xc) = 2;
        *(undefined **)(iVar3 + 0x12) = _socketops;
        *(undefined4 *)(iVar3 + 0x16) = uStack_c;
        *(int *)(*(int *)(_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = iVar3;
        iStack_10 = *(int *)(dword_40B57D4 + 0x5c);
        uVar4 = _soconnect2(uStack_8,uStack_c);
        *(undefined *)(dword_40B57D4 + 100) = uVar4;
        if (*(char *)(dword_40B57D4 + 100) == '\0') {
          if (puVar1[1] != 2) {
loc_4014F4E:
            *(undefined4 *)(dword_40B57D4 + 0x5c) = 0;
            _copyoutmsg(&iStack_14,puVar1[3],8);
            return;
          }
          uVar4 = _soconnect2(uStack_c,uStack_8);
          *(undefined *)(dword_40B57D4 + 100) = uVar4;
          if (*(char *)(dword_40B57D4 + 100) == '\0') goto loc_4014F4E;
        }
        *(undefined2 *)(iVar3 + 0xe) = 0;
        *(undefined4 *)(*(int *)(_active_u + 0x146) + iStack_10 * 4) = 0;
      }
      *(undefined2 *)(iVar2 + 0xe) = 0;
      *(undefined4 *)(*(int *)(_active_u + 0x146) + iStack_14 * 4) = 0;
    }
    _soclose(uStack_c);
  }
  _soclose(uStack_8);
  return;
}
/* GHIDRADEC_FUNCTION index=440 start=0x4014fb8 */

void _sendto(void)

{
  undefined4 *puVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uStack_1c = puVar1[4];
  uStack_18 = puVar1[5];
  puStack_14 = &uStack_24;
  uStack_10 = 1;
  uStack_24 = puVar1[1];
  uStack_20 = puVar1[2];
  uStack_c = 0;
  uStack_8 = 0;
  _sendit(*puVar1,&uStack_1c,puVar1[3]);
  return;
}
/* GHIDRADEC_FUNCTION index=441 start=0x4015008 */

void _send(void)

{
  undefined4 *puVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uStack_1c = 0;
  uStack_18 = 0;
  puStack_14 = &uStack_24;
  uStack_10 = 1;
  uStack_24 = puVar1[1];
  uStack_20 = puVar1[2];
  uStack_c = 0;
  uStack_8 = 0;
  _sendit(*puVar1,&uStack_1c,puVar1[3]);
  return;
}
/* GHIDRADEC_FUNCTION index=442 start=0x4015054 */

void _sendmsg(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined auStack_9c [128];
  undefined auStack_1c [8];
  undefined *puStack_14;
  uint uStack_10;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar2 = _copyinmsg(puVar1[1],auStack_1c,0x18);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    if (uStack_10 < 0x10) {
      uVar2 = _copyinmsg(puStack_14,auStack_9c,uStack_10 << 3);
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        puStack_14 = auStack_9c;
        _sendit(*puVar1,auStack_1c,puVar1[2]);
      }
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x28;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=443 start=0x40150ee */

void _sendit(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iStack_22;
  int iStack_1e;
  int iStack_1a;
  int iStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  undefined2 uStack_a;
  int iStack_8;
  
  iVar1 = _getsock(param_1);
  if (iVar1 == 0) {
    return;
  }
  iStack_1a = param_2[2];
  iStack_16 = param_2[3];
  uStack_e = 0;
  uStack_12 = 0;
  iStack_8 = 0;
  uStack_a = 0;
  puVar6 = (undefined4 *)param_2[2];
  iVar4 = 0;
  if (0 < param_2[3]) {
    piVar5 = puVar6 + 1;
    do {
      iVar2 = *piVar5;
      if (iVar2 < 0) {
        *(undefined *)(dword_40B57D4 + 100) = 0x16;
        return;
      }
      if (iVar2 != 0) {
        iVar2 = _useracc(*puVar6,iVar2,1);
        if (iVar2 == 0) {
          *(undefined *)(dword_40B57D4 + 100) = 0xe;
          return;
        }
        iStack_8 = *piVar5 + iStack_8;
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 2;
      puVar6 = puVar6 + 2;
    } while (iVar4 < param_2[3]);
  }
  if (*param_2 == 0) {
    iStack_1e = 0;
  }
  else {
    uVar3 = _sockargs(&iStack_1e,*param_2,param_2[1],8);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (*(char *)(dword_40B57D4 + 100) != '\0') {
      return;
    }
  }
  if (param_2[4] == 0) {
    iStack_22 = 0;
  }
  else {
    uVar3 = _sockargs(&iStack_22,param_2[4],param_2[5],0xc);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (*(char *)(dword_40B57D4 + 100) != '\0') goto loc_4015246;
  }
  iVar4 = iStack_8;
  uVar3 = _sosend(*(undefined4 *)(iVar1 + 0x16),iStack_1e,&iStack_1a,param_3,iStack_22);
  *(undefined *)(dword_40B57D4 + 100) = uVar3;
  *(int *)(dword_40B57D4 + 0x5c) = iVar4 - iStack_8;
  if (iStack_22 != 0) {
    _m_freem(iStack_22);
  }
loc_4015246:
  if (iStack_1e != 0) {
    _m_freem(iStack_1e);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=444 start=0x401525e */

void _recvfrom(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  if (puVar1[5] != 0) {
    uVar2 = _copyinmsg(puVar1[5],&uStack_20,4);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
  }
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    uStack_1c = puVar1[4];
    uStack_18 = uStack_20;
    puStack_14 = &uStack_28;
    uStack_10 = 1;
    uStack_28 = puVar1[1];
    uStack_24 = puVar1[2];
    uStack_c = 0;
    uStack_8 = 0;
    _recvit(*puVar1,&uStack_1c,puVar1[3],puVar1[5],0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=445 start=0x40152f0 */

void _recv(void)

{
  undefined4 *puVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uStack_1c = 0;
  uStack_18 = 0;
  puStack_14 = &uStack_24;
  uStack_10 = 1;
  uStack_24 = puVar1[1];
  uStack_20 = puVar1[2];
  uStack_c = 0;
  uStack_8 = 0;
  _recvit(*puVar1,&uStack_1c,puVar1[3],0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=446 start=0x4015340 */

void _recvmsg(void)

{
  undefined4 *puVar1;
  undefined uVar3;
  int iVar2;
  undefined auStack_9c [128];
  undefined auStack_1c [8];
  undefined *puStack_14;
  uint uStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar3 = _copyinmsg(puVar1[1],auStack_1c,0x18);
  *(undefined *)(dword_40B57D4 + 100) = uVar3;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    if (uStack_10 < 0x10) {
      uVar3 = _copyinmsg(puStack_14,auStack_9c,uStack_10 << 3);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        puStack_14 = auStack_9c;
        if ((iStack_c != 0) && (iVar2 = _useracc(iStack_c,uStack_8,0), iVar2 == 0)) {
          *(undefined *)(dword_40B57D4 + 100) = 0xe;
          return;
        }
        _recvit(*puVar1,auStack_1c,puVar1[2],puVar1[1] + 4,puVar1[1] + 0x14);
      }
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x28;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=447 start=0x4015412 */

void _recvit(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iStack_26;
  int iStack_22;
  int iStack_1e;
  int iStack_1a;
  int iStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  int iStack_8;
  
  iVar1 = _getsock(param_1);
  if (iVar1 != 0) {
    iStack_1a = param_2[2];
    iStack_16 = param_2[3];
    uStack_e = 0;
    uStack_12 = 0;
    iStack_8 = 0;
    puVar6 = (undefined4 *)param_2[2];
    iVar4 = 0;
    if (0 < param_2[3]) {
      piVar5 = puVar6 + 1;
      do {
        iVar2 = *piVar5;
        if (iVar2 < 0) {
          *(undefined *)(dword_40B57D4 + 100) = 0x16;
          return;
        }
        if (iVar2 != 0) {
          iVar2 = _useracc(*puVar6,iVar2,0);
          if (iVar2 == 0) {
            *(undefined *)(dword_40B57D4 + 100) = 0xe;
            return;
          }
          iStack_8 = *piVar5 + iStack_8;
        }
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 2;
        puVar6 = puVar6 + 2;
      } while (iVar4 < param_2[3]);
    }
    iStack_26 = iStack_8;
    uVar3 = _soreceive(*(undefined4 *)(iVar1 + 0x16),&iStack_1e,&iStack_1a,param_3,&iStack_22);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    *(int *)(dword_40B57D4 + 0x5c) = iStack_26 - iStack_8;
    if (*param_2 != 0) {
      iStack_26 = param_2[1];
      if ((iStack_26 < 1) || (iStack_1e == 0)) {
        iStack_26 = 0;
      }
      else {
        if (*(sword *)(iStack_1e + 8) < iStack_26) {
          iStack_26 = (int)*(sword *)(iStack_1e + 8);
        }
        _copyoutmsg(*(int *)(iStack_1e + 4) + iStack_1e,*param_2,iStack_26);
      }
      _copyoutmsg(&iStack_26,param_4,4);
    }
    if (param_2[4] != 0) {
      iStack_26 = param_2[5];
      if ((iStack_26 < 1) || (iStack_22 == 0)) {
        iStack_26 = 0;
      }
      else {
        if (*(sword *)(iStack_22 + 8) < iStack_26) {
          iStack_26 = (int)*(sword *)(iStack_22 + 8);
        }
        _copyoutmsg(*(int *)(iStack_22 + 4) + iStack_22,param_2[4],iStack_26);
      }
      _copyoutmsg(&iStack_26,param_5,4);
    }
    if (iStack_22 != 0) {
      _m_freem(iStack_22);
    }
    if (iStack_1e != 0) {
      _m_freem(iStack_1e);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=448 start=0x40155bc */

void _shutdown(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _getsock(*puVar1);
  if (iVar2 != 0) {
    uVar3 = _soshutdown(*(undefined4 *)(iVar2 + 0x16),puVar1[1]);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=449 start=0x40155fc */

void _setsockopt(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  int iVar4;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar4 = 0;
  iVar2 = _getsock(*puVar1);
  if (iVar2 != 0) {
    if ((int)puVar1[4] < 0x71) {
      if (puVar1[3] != 0) {
        iVar4 = _m_get(1,10);
        if (iVar4 == 0) {
          *(undefined *)(dword_40B57D4 + 100) = 0x37;
          return;
        }
        uVar3 = _copyinmsg(puVar1[3],*(int *)(iVar4 + 4) + iVar4,puVar1[4]);
        *(undefined *)(dword_40B57D4 + 100) = uVar3;
        if (*(char *)(dword_40B57D4 + 100) != '\0') {
          _m_free(iVar4);
          return;
        }
        *(undefined2 *)(iVar4 + 8) = *(undefined2 *)((int)puVar1 + 0x12);
      }
      uVar3 = _sosetopt(*(undefined4 *)(iVar2 + 0x16),puVar1[1],puVar1[2],iVar4);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
  return;
}

