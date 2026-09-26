
undefined4 * _m_pullup(undefined4 *param_1,int param_2)

{
  int iVar1;
  sword sVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar4 = _mfree;
  if (((uint)(param_2 + param_1[1]) < 0x7d) && ((undefined4 *)*param_1 != (undefined4 *)0x0)) {
    param_2 = param_2 - *(sword *)(param_1 + 2);
    puVar4 = param_1;
    param_1 = (undefined4 *)*param_1;
  }
  else {
    if (0x70 < param_2) goto loc_40125FE;
    if (_mfree == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)_m_more(0,(int)*(sword *)((int)param_1 + 10));
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMget);
      }
      *(undefined2 *)((int)_mfree + 10) = *(undefined2 *)((int)param_1 + 10);
      word_40B61CC = word_40B61CC + -1;
      (&word_40B61CC)[*(sword *)((int)param_1 + 10)] =
           (&word_40B61CC)[*(sword *)((int)param_1 + 10)] + 1;
      puVar3 = (undefined4 *)*_mfree;
      *_mfree = 0;
      _mfree = puVar3;
      puVar4[1] = 0xc;
    }
    if (puVar4 == (undefined4 *)0x0) goto loc_40125FE;
    *(undefined2 *)(puVar4 + 2) = 0;
  }
  iVar1 = puVar4[1];
  do {
    iVar5 = (0x7c - iVar1) - (int)*(sword *)(puVar4 + 2);
    if (param_2 + 0x20 < iVar5) {
      iVar5 = param_2 + 0x20;
    }
    if (*(sword *)(param_1 + 2) < iVar5) {
      iVar5 = (int)*(sword *)(param_1 + 2);
    }
    _bcopy(param_1[1] + (int)param_1,(int)puVar4 + (int)*(sword *)(puVar4 + 2) + puVar4[1],iVar5);
    param_2 = param_2 - iVar5;
    *(sword *)(puVar4 + 2) = (sword)iVar5 + *(sword *)(puVar4 + 2);
    sVar2 = *(sword *)(param_1 + 2) - (sword)iVar5;
    *(sword *)(param_1 + 2) = sVar2;
    if (sVar2 == 0) {
      param_1 = (undefined4 *)_m_free(param_1);
    }
    else {
      param_1[1] = iVar5 + param_1[1];
    }
    if (param_2 < 1) {
      *puVar4 = param_1;
      return puVar4;
    }
  } while (param_1 != (undefined4 *)0x0);
  _m_free(puVar4);
  param_1 = (undefined4 *)0x0;
loc_40125FE:
  _m_freem(param_1);
  return (undefined4 *)0x0;
}
