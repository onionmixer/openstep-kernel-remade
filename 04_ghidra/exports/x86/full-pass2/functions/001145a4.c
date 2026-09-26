/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001145a4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _m_pullup(undefined4 *param_1,int param_2)

{
  int iVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  size_t sVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if (((uint)(param_2 + param_1[1]) < 0x7d) && ((undefined4 *)*param_1 != (undefined4 *)0x0)) {
    param_2 = param_2 - *(short *)(param_1 + 2);
    puVar7 = (undefined4 *)*param_1;
    puVar3 = param_1;
  }
  else {
    if (0x70 < param_2) goto LAB_00114800;
    uVar4 = _splimp();
    puVar3 = _mfree;
    if (_mfree == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)_m_more(0,(int)*(short *)((int)param_1 + 10));
    }
    else {
      if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&DAT_001db20f);
      }
      *(undefined2 *)((int)_mfree + 10) = *(undefined2 *)((int)param_1 + 10);
      _DAT_001e917c = _DAT_001e917c + -1;
      *(short *)(&DAT_001e917c + *(short *)((int)param_1 + 10) * 2) =
           *(short *)(&DAT_001e917c + *(short *)((int)param_1 + 10) * 2) + 1;
      puVar7 = (undefined4 *)*_mfree;
      *_mfree = 0;
      _mfree = puVar7;
      puVar3[1] = 0xc;
    }
    _splx(uVar4);
    if (puVar3 == (undefined4 *)0x0) goto LAB_00114800;
    *(undefined2 *)(puVar3 + 2) = 0;
    puVar7 = param_1;
  }
  iVar1 = puVar3[1];
  do {
    sVar6 = (0x7c - iVar1) - (int)*(short *)(puVar3 + 2);
    if ((int)(param_2 + 0x20U) < (int)sVar6) {
      sVar6 = param_2 + 0x20U;
    }
    if ((int)*(short *)(puVar7 + 2) < (int)sVar6) {
      sVar6 = (int)*(short *)(puVar7 + 2);
    }
    _bcopy((void *)((int)puVar7 + puVar7[1]),
           (void *)((int)puVar3 + (int)*(short *)(puVar3 + 2) + puVar3[1]),sVar6);
    param_2 = param_2 - sVar6;
    *(short *)(puVar3 + 2) = *(short *)(puVar3 + 2) + (short)sVar6;
    sVar2 = *(short *)(puVar7 + 2) - (short)sVar6;
    *(short *)(puVar7 + 2) = sVar2;
    if (sVar2 == 0) {
      uVar4 = _splimp();
      if (*(short *)((int)puVar7 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_mfree_001db1dd);
      }
      *(short *)(&DAT_001e917c + *(short *)((int)puVar7 + 10) * 2) =
           *(short *)(&DAT_001e917c + *(short *)((int)puVar7 + 10) * 2) + -1;
      _DAT_001e917c = _DAT_001e917c + 1;
      *(undefined2 *)((int)puVar7 + 10) = 0;
      if (0x7f < (uint)puVar7[1]) {
        _mclput(puVar7);
      }
      puVar8 = (undefined4 *)*puVar7;
      *puVar7 = _mfree;
      puVar7[1] = 0;
      puVar7[0x1f] = 0;
      _mfree = puVar7;
      _splx(uVar4);
      if (_m_want != 0) {
        _m_want = 0;
        _wakeup(&_mfree);
      }
    }
    else {
      puVar7[1] = puVar7[1] + sVar6;
      puVar8 = puVar7;
    }
    if (param_2 < 1) {
      *puVar3 = puVar8;
      return puVar3;
    }
    puVar7 = puVar8;
  } while (puVar8 != (undefined4 *)0x0);
  uVar4 = _splimp();
  if (*(short *)((int)puVar3 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_mfree_001db1dd);
  }
  *(short *)(&DAT_001e917c + *(short *)((int)puVar3 + 10) * 2) =
       *(short *)(&DAT_001e917c + *(short *)((int)puVar3 + 10) * 2) + -1;
  _DAT_001e917c = _DAT_001e917c + 1;
  *(undefined2 *)((int)puVar3 + 10) = 0;
  if (0x7f < (uint)puVar3[1]) {
    _mclput(puVar3);
  }
  *puVar3 = _mfree;
  puVar3[1] = 0;
  puVar3[0x1f] = 0;
  _mfree = puVar3;
  _splx(uVar4);
  param_1 = (undefined4 *)0x0;
  if (_m_want != 0) {
    _m_want = 0;
    _wakeup(&_mfree);
  }
LAB_00114800:
  if (param_1 != (undefined4 *)0x0) {
    uVar4 = _splimp();
    do {
      uVar5 = _splimp();
      if (*(short *)((int)param_1 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_mfree_001db1ef);
      }
      *(short *)(&DAT_001e917c + *(short *)((int)param_1 + 10) * 2) =
           *(short *)(&DAT_001e917c + *(short *)((int)param_1 + 10) * 2) + -1;
      _DAT_001e917c = _DAT_001e917c + 1;
      *(undefined2 *)((int)param_1 + 10) = 0;
      if (0x7f < (uint)param_1[1]) {
        _mclput(param_1);
      }
      puVar3 = (undefined4 *)*param_1;
      *param_1 = _mfree;
      param_1[1] = 0;
      param_1[0x1f] = 0;
      _mfree = param_1;
      _splx(uVar5);
      if (_m_want != 0) {
        _m_want = 0;
        _wakeup(&_mfree);
      }
      param_1 = puVar3;
    } while (puVar3 != (undefined4 *)0x0);
    _splx(uVar4);
  }
  return (undefined4 *)0x0;
}

