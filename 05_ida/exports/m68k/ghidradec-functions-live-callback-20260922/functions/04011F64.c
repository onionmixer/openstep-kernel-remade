
undefined4 * _m_get(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)_m_more(param_1,param_2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMget);
    }
    *(sword *)((int)_mfree + 10) = (sword)param_2;
    word_40B61CC = word_40B61CC + -1;
    (&word_40B61CC)[param_2] = (&word_40B61CC)[param_2] + 1;
    puVar1 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar1;
    puVar2[1] = 0xc;
  }
  return puVar2;
}

