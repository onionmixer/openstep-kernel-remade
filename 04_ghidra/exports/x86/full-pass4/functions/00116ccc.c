/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116ccc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _sbdroprecord(short *param_1)

{
  short sVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 6);
  if (piVar4 != (int *)0x0) {
    *(int *)(param_1 + 6) = piVar4[0x1f];
    do {
      *param_1 = *param_1 - (short)piVar4[2];
      sVar1 = param_1[2];
      param_1[2] = sVar1 + -0x80;
      if (0x7c < (uint)piVar4[1]) {
        param_1[2] = sVar1 + -0x480;
      }
      uVar3 = _splimp();
      if (*(short *)((int)piVar4 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_mfree_001db397);
      }
      *(short *)(&DAT_001e917c + *(short *)((int)piVar4 + 10) * 2) =
           *(short *)(&DAT_001e917c + *(short *)((int)piVar4 + 10) * 2) + -1;
      _DAT_001e917c = _DAT_001e917c + 1;
      *(undefined2 *)((int)piVar4 + 10) = 0;
      if (0x7f < (uint)piVar4[1]) {
        _mclput(piVar4);
      }
      piVar2 = (int *)*piVar4;
      *piVar4 = (int)_mfree;
      piVar4[1] = 0;
      piVar4[0x1f] = 0;
      _mfree = piVar4;
      _splx(uVar3);
      if (_m_want != 0) {
        _m_want = 0;
        _wakeup(&_mfree);
      }
      piVar4 = piVar2;
    } while (piVar2 != (int *)0x0);
  }
  return;
}

