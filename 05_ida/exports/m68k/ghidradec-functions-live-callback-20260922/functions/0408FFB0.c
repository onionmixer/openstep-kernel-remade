
int _in_bootp_bptombuf(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iStack_8;
  
  iVar4 = 0x148;
  piVar6 = &iStack_8;
  do {
    piVar2 = _mfree;
    if (_mfree == (int *)0x0) {
      piVar2 = (int *)_m_more(1,1);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMget);
      }
      *(undefined2 *)((int)_mfree + 10) = 1;
      word_40B61CC = word_40B61CC + -1;
      word_40B61CE = word_40B61CE + 1;
      piVar1 = (int *)*_mfree;
      *_mfree = 0;
      _mfree = piVar1;
      piVar2[1] = 0xc;
    }
    if (iVar4 < 0x200) {
loc_40900BA:
      iVar5 = 0x70;
      if (iVar4 < 0x71) {
loc_40900C4:
        iVar5 = iVar4;
      }
    }
    else {
      if (_mclfree == (undefined4 *)0x0) {
        _m_clalloc(1,1,0);
      }
      if (_mclfree == (undefined4 *)0x0) {
        *(undefined2 *)(piVar2 + 2) = 0x70;
      }
      else {
        _mclrefcnt[(int)_mclfree - _mbutl >> 10] = _mclrefcnt[(int)_mclfree - _mbutl >> 10] + '\x01'
        ;
        dword_40B61BC = dword_40B61BC + -1;
        iVar5 = (int)_mclfree - (int)piVar2;
        _mclfree = (undefined4 *)*_mclfree;
        piVar2[1] = iVar5;
        *(undefined2 *)(piVar2 + 2) = 0x400;
        *(undefined2 *)(piVar2 + 3) = 1;
      }
      if (*(sword *)(piVar2 + 2) != 0x400) goto loc_40900BA;
      iVar5 = 0x400;
      if (iVar4 < 0x401) goto loc_40900C4;
    }
    _bcopy(param_1,piVar2[1] + (int)piVar2,iVar5);
    iVar4 = iVar4 - iVar5;
    param_1 = iVar5 + param_1;
    *(sword *)(piVar2 + 2) = (sword)iVar5;
    *piVar6 = (int)piVar2;
    piVar6 = piVar2;
    if (iVar4 < 1) {
      iVar4 = *(int *)(iStack_8 + 4) + iStack_8;
      *(undefined2 *)(iVar4 + 10) = 0;
      uVar3 = _in_cksum(iStack_8,0x14);
      *(undefined2 *)(iVar4 + 10) = uVar3;
      return iStack_8;
    }
  } while( true );
}

