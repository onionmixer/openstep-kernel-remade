/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001141a4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ****** _m_copy(undefined4 *param_1,int param_2,int param_3)

{
  short *psVar1;
  undefined4 ******ppppppuVar2;
  undefined4 uVar3;
  undefined4 ******ppppppuVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 ******ppppppuVar7;
  undefined4 *****local_8;
  
  if (param_3 == 0) {
LAB_001143d1:
    local_8 = (undefined4 ******)0x0;
  }
  else {
    if ((param_2 < 0) || (param_3 < 0)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_m_copy_001db1f5);
    }
    for (; 0 < param_2; param_2 = param_2 - *psVar1) {
      if (param_1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_m_copy_001db1fc);
      }
      psVar1 = (short *)(param_1 + 2);
      if (param_2 < *psVar1) break;
      param_1 = (undefined4 *)*param_1;
    }
    local_8 = (undefined4 ******)0x0;
    ppppppuVar7 = &local_8;
    while (0 < param_3) {
      if (param_1 == (undefined4 *)0x0) {
        if (param_3 == 1000000000) {
          return (undefined4 ******)local_8;
        }
                    /* WARNING: Subroutine does not return */
        _panic(s_m_copy_001db203);
      }
      uVar3 = _splimp();
      ppppppuVar4 = _mfree;
      if (_mfree == (undefined4 ******)0x0) {
        ppppppuVar4 = (undefined4 ******)_m_more(0,(int)*(short *)((int)param_1 + 10));
      }
      else {
        if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(&DAT_001db20a);
        }
        *(undefined2 *)((int)_mfree + 10) = *(undefined2 *)((int)param_1 + 10);
        _DAT_001e917c = _DAT_001e917c + -1;
        *(short *)(&DAT_001e917c + *(short *)((int)param_1 + 10) * 2) =
             *(short *)(&DAT_001e917c + *(short *)((int)param_1 + 10) * 2) + 1;
        ppppppuVar2 = (undefined4 ******)*_mfree;
        *_mfree = (undefined4 *****)0x0;
        _mfree = ppppppuVar2;
        ppppppuVar4[1] = (undefined4 *****)0xc;
      }
      _splx(uVar3);
      *ppppppuVar7 = ppppppuVar4;
      ppppppuVar7 = (undefined4 ******)local_8;
      if (ppppppuVar4 == (undefined4 ******)0x0) {
        if ((undefined4 ******)local_8 != (undefined4 ******)0x0) {
          uVar3 = _splimp();
          do {
            uVar5 = _splimp();
            if (*(short *)((int)ppppppuVar7 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
              _panic(s_mfree_001db1ef);
            }
            *(short *)(&DAT_001e917c + *(short *)((int)ppppppuVar7 + 10) * 2) =
                 *(short *)(&DAT_001e917c + *(short *)((int)ppppppuVar7 + 10) * 2) + -1;
            _DAT_001e917c = _DAT_001e917c + 1;
            *(undefined2 *)((int)ppppppuVar7 + 10) = 0;
            if ((undefined4 *****)0x7f < ppppppuVar7[1]) {
              _mclput(ppppppuVar7);
            }
            ppppppuVar4 = (undefined4 ******)*ppppppuVar7;
            *ppppppuVar7 = _mfree;
            ppppppuVar7[1] = (undefined4 *****)0x0;
            ppppppuVar7[0x1f] = (undefined4 *****)0x0;
            _mfree = ppppppuVar7;
            _splx(uVar5);
            if (_m_want != 0) {
              _m_want = 0;
              _wakeup(&_mfree);
            }
            ppppppuVar7 = ppppppuVar4;
          } while (ppppppuVar4 != (undefined4 ******)0x0);
          _splx(uVar3);
        }
        goto LAB_001143d1;
      }
      iVar6 = param_3;
      if (*(short *)(param_1 + 2) - param_2 < param_3) {
        iVar6 = *(short *)(param_1 + 2) - param_2;
      }
      *(short *)(ppppppuVar4 + 2) = (short)iVar6;
      if (((uint)param_1[1] < 0x7d) || ((short)iVar6 < 0x71)) {
        _bcopy((void *)((int)param_1 + param_2 + param_1[1]),
               (void *)((int)ppppppuVar4 + (int)ppppppuVar4[1]),(int)*(short *)(ppppppuVar4 + 2));
      }
      else {
        _mcldup(param_1,ppppppuVar4,param_2);
        ppppppuVar4[1] = (undefined4 *****)((int)ppppppuVar4[1] + param_2);
      }
      if (param_3 != 1000000000) {
        param_3 = param_3 - *(short *)(ppppppuVar4 + 2);
      }
      param_2 = 0;
      param_1 = (undefined4 *)*param_1;
      ppppppuVar7 = ppppppuVar4;
    }
  }
  return (undefined4 ******)local_8;
}

