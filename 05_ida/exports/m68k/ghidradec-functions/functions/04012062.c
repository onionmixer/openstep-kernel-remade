
undefined4 _m_free(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (*(sword *)((int)param_1 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aMfree);
  }
  (&word_40B61CC)[*(sword *)((int)param_1 + 10)] =
       (&word_40B61CC)[*(sword *)((int)param_1 + 10)] + -1;
  word_40B61CC = word_40B61CC + 1;
  *(undefined2 *)((int)param_1 + 10) = 0;
  if (0x7f < (uint)param_1[1]) {
    _mclput(param_1);
  }
  uVar1 = *param_1;
  *param_1 = _mfree;
  param_1[1] = 0;
  param_1[0x1f] = 0;
  _mfree = param_1;
  if (_m_want != 0) {
    _m_want = 0;
    _wakeup(&_mfree);
  }
  return uVar1;
}
