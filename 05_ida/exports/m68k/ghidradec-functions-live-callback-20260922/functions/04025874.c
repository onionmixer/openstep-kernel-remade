
undefined4 _udp_output(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  sword sVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar1 = _mfree;
  iVar5 = 0;
  for (puVar4 = param_2; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    iVar5 = *(sword *)(puVar4 + 2) + iVar5;
  }
  if (_mfree == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)_m_more(0,2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMget);
    }
    *(undefined2 *)((int)_mfree + 10) = 2;
    word_40B61CC = word_40B61CC + -1;
    word_40B61D0 = word_40B61D0 + 1;
    puVar4 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar4;
    puVar1[1] = 0xc;
  }
  if (puVar1 == (undefined4 *)0x0) {
    _m_freem(param_2);
    uVar2 = 0x37;
  }
  else {
    puVar1[1] = 0x60;
    *(undefined2 *)(puVar1 + 2) = 0x1c;
    *puVar1 = param_2;
    puVar4 = (undefined4 *)(puVar1[1] + (int)puVar1);
    puVar4[1] = 0;
    *puVar4 = 0;
    *(undefined *)(puVar4 + 2) = 0;
    *(undefined *)((int)puVar4 + 9) = 0x11;
    *(sword *)((int)puVar4 + 10) = (sword)iVar5 + 8;
    puVar4[3] = *(undefined4 *)(param_1 + 0x12);
    puVar4[4] = *(undefined4 *)(param_1 + 0xc);
    *(undefined2 *)(puVar4 + 5) = *(undefined2 *)(param_1 + 0x16);
    *(undefined2 *)((int)puVar4 + 0x16) = *(undefined2 *)(param_1 + 0x10);
    *(undefined2 *)(puVar4 + 6) = *(undefined2 *)((int)puVar4 + 10);
    *(undefined2 *)((int)puVar4 + 0x1a) = 0;
    if (_udpcksum != 0) {
      sVar3 = _in_cksum(puVar1,iVar5 + 0x1c);
      *(sword *)((int)puVar4 + 0x1a) = sVar3;
      if (sVar3 == 0) {
        *(undefined2 *)((int)puVar4 + 0x1a) = 0xffff;
      }
    }
    *(sword *)((int)puVar4 + 2) = (sword)iVar5 + 0x1c;
    *(undefined *)(puVar4 + 2) = byte_40AEBC7;
    uVar2 = _ip_output(puVar1,*(undefined4 *)(param_1 + 0x34),param_1 + 0x20,
                       *(word *)(*(int *)(param_1 + 0x18) + 2) & 0x32 | 2,
                       *(undefined4 *)(param_1 + 0x38));
  }
  return uVar2;
}

