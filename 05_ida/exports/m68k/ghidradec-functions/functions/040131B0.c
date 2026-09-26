
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
