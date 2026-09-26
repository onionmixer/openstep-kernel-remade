
undefined4 *
_mclgetx(undefined4 param_1,undefined4 param_2,int param_3,undefined2 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)_m_more(param_5,1);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMget);
    }
    *(undefined2 *)((int)_mfree + 10) = 1;
    word_40B61CC = word_40B61CC + -1;
    word_40B61CE = word_40B61CE + 1;
    puVar1 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar1;
    puVar2[1] = 0xc;
  }
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[1] = param_3 - (int)puVar2;
    *(undefined2 *)(puVar2 + 2) = param_4;
    *(undefined2 *)(puVar2 + 3) = 2;
    *(undefined4 *)((int)puVar2 + 0xe) = param_1;
    *(undefined4 *)((int)puVar2 + 0x12) = param_2;
    *(undefined4 *)((int)puVar2 + 0x16) = 0;
  }
  return puVar2;
}

