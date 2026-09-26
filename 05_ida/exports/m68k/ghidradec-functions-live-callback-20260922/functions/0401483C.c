
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

