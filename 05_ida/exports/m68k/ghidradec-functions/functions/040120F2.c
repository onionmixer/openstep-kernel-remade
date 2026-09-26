
undefined4 * _m_more(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  while (iVar3 = _m_expand(param_1), puVar1 = _mfree, iVar3 == 0) {
    if (param_1 != 1) {
      unk_40B61C0 = unk_40B61C0 + 1;
      return (undefined4 *)0x0;
    }
    unk_40B61C4 = unk_40B61C4 + 1;
    _m_want = _m_want + 1;
    _sleep(&_mfree,0x18);
  }
  if (_mfree == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aMMore);
  }
  if (*(sword *)((int)_mfree + 10) == 0) {
    *(sword *)((int)_mfree + 10) = (sword)param_2;
    word_40B61CC = word_40B61CC + -1;
    (&word_40B61CC)[param_2] = (&word_40B61CC)[param_2] + 1;
    uVar2 = *_mfree;
    *_mfree = 0;
    _mfree = (undefined4 *)uVar2;
    puVar1[1] = 0xc;
    return puVar1;
  }
                    /* WARNING: Subroutine does not return */
  _panic(&aMget);
}
