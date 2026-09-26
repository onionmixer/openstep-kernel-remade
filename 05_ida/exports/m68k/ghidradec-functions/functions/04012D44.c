
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
