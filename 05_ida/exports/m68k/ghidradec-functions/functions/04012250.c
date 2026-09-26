
undefined4 _m_copy(undefined4 *param_1,int param_2,int param_3)

{
  sword *psVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  sword sVar4;
  undefined4 uStack_8;
  
  if (param_3 == 0) {
loc_40123B8:
    uStack_8 = 0;
  }
  else {
    if ((param_2 < 0) || (param_3 < 0)) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMCopy);
    }
    for (; 0 < param_2; param_2 = param_2 - *psVar1) {
      if (param_1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMCopy);
      }
      psVar1 = (sword *)(param_1 + 2);
      if (param_2 < *psVar1) break;
      param_1 = (undefined4 *)*param_1;
    }
    uStack_8 = 0;
    puVar2 = &uStack_8;
    puVar3 = _mfree;
    while (_mfree = puVar3, 0 < param_3) {
      if (param_1 == (undefined4 *)0x0) {
        if (param_3 == 1000000000) {
          return uStack_8;
        }
                    /* WARNING: Subroutine does not return */
        _panic(&aMCopy);
      }
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)_m_more(0,(int)*(sword *)((int)param_1 + 10));
      }
      else {
        if (*(sword *)((int)puVar3 + 10) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(&aMget);
        }
        *(undefined2 *)((int)puVar3 + 10) = *(undefined2 *)((int)param_1 + 10);
        word_40B61CC = word_40B61CC + -1;
        (&word_40B61CC)[*(sword *)((int)param_1 + 10)] =
             (&word_40B61CC)[*(sword *)((int)param_1 + 10)] + 1;
        _mfree = (undefined4 *)*puVar3;
        *puVar3 = 0;
        puVar3[1] = 0xc;
      }
      *puVar2 = puVar3;
      if (puVar3 == (undefined4 *)0x0) {
        _m_freem(uStack_8);
        goto loc_40123B8;
      }
      sVar4 = (sword)param_3;
      if (*(sword *)(param_1 + 2) - param_2 < param_3) {
        sVar4 = (sword)(*(sword *)(param_1 + 2) - param_2);
      }
      *(sword *)(puVar3 + 2) = sVar4;
      if (((uint)param_1[1] < 0x7d) || (sVar4 < 0x71)) {
        _bcopy((int)param_1 + param_2 + param_1[1],puVar3[1] + (int)puVar3,
               (int)*(sword *)(puVar3 + 2));
      }
      else {
        _mcldup(param_1,puVar3,param_2);
        puVar3[1] = param_2 + puVar3[1];
      }
      if (param_3 != 1000000000) {
        param_3 = param_3 - *(sword *)(puVar3 + 2);
      }
      param_2 = 0;
      param_1 = (undefined4 *)*param_1;
      puVar2 = puVar3;
      puVar3 = _mfree;
    }
  }
  return uStack_8;
}
