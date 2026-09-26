
void _m_freem(undefined4 *param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  
  while( true ) {
    puVar1 = param_1;
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    if (*(sword *)((int)puVar1 + 10) == 0) break;
    (&word_40B61CC)[*(sword *)((int)puVar1 + 10)] =
         (&word_40B61CC)[*(sword *)((int)puVar1 + 10)] + -1;
    word_40B61CC = word_40B61CC + 1;
    *(undefined2 *)((int)puVar1 + 10) = 0;
    if (0x7f < (uint)puVar1[1]) {
      _mclput(puVar1);
    }
    param_1 = (undefined4 *)*puVar1;
    *puVar1 = _mfree;
    puVar1[1] = 0;
    puVar1[0x1f] = 0;
    bVar2 = _m_want != 0;
    _m_want = 0;
    _mfree = puVar1;
    if (bVar2) {
      _m_want = 0;
      _wakeup(&_mfree);
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(&aMfree);
}

