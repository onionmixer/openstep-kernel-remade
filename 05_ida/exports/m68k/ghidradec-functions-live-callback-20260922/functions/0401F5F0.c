
byte _inet_queue(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  
  _netisr = _netisr | 4;
  _wakeup(&_soft_net_wakeup);
  puVar3 = _mfree;
  uVar1 = dword_40B7BC8;
  if ((int)dword_40B7BC0 < dword_40B7BC4) {
    if (param_2[1] - 0x10 < 0x6d) {
      param_2[1] = param_2[1] + -4;
      *(sword *)(param_2 + 2) = *(sword *)(param_2 + 2) + 4;
      puVar3 = param_2;
    }
    else {
      if (_mfree == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)_m_more(0,2);
      }
      else {
        if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(&aMget);
        }
        *(undefined2 *)((int)_mfree + 10) = 2;
        word_40B61CC = word_40B61CC + -1;
        word_40B61D0 = word_40B61D0 + 1;
        puVar2 = (undefined4 *)*_mfree;
        *_mfree = 0;
        _mfree = puVar2;
        puVar3[1] = 0xc;
      }
      uVar1 = dword_40B7BC8;
      if (puVar3 == (undefined4 *)0x0) goto loc_401F6F6;
      puVar3[1] = 0xc;
      *(undefined2 *)(puVar3 + 2) = 4;
      *puVar3 = param_2;
    }
    uVar1 = dword_40B7BC8;
    if (puVar3 != (undefined4 *)0x0) {
      *(undefined4 *)((int)puVar3 + puVar3[1]) = param_1;
      puVar3[0x1f] = 0;
      puVar2 = puVar3;
      if (dword_40B7BBC != (undefined4 *)0x0) {
        dword_40B7BBC[0x1f] = puVar3;
        puVar2 = _ipintrq;
      }
      _ipintrq = puVar2;
      cVar4 = 0xfffffffe < dword_40B7BC0;
      cVar7 = SCARRY4(dword_40B7BC0,1);
      dword_40B7BC0 = dword_40B7BC0 + 1;
      cVar5 = (int)dword_40B7BC0 < 0;
      cVar6 = dword_40B7BC0 == 0;
      bVar8 = cVar4;
      dword_40B7BBC = puVar3;
      goto loc_401F6FE;
    }
  }
loc_401F6F6:
  dword_40B7BC8 = uVar1 + 1;
  cVar4 = 0xfffffffe < uVar1;
  cVar5 = (int)param_2 < 0;
  cVar6 = param_2 == (undefined4 *)0x0;
  cVar7 = '\0';
  bVar8 = 0;
  _m_freem(param_2);
loc_401F6FE:
  return cVar4 << 4 | cVar5 << 3 | cVar6 << 2 | cVar7 << 1 | bVar8;
}

