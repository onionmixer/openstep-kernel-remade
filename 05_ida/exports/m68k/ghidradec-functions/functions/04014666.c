
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
