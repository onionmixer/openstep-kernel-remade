
uint _igmp_sendreport(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte bVar12;
  
  puVar2 = _mfree;
  cVar8 = '\0';
  if (_mfree == (undefined4 *)0x0) {
    cVar9 = '\0';
    cVar10 = '\x01';
    cVar11 = '\0';
    bVar12 = 0;
    puVar2 = (undefined4 *)_m_more(0,2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMget);
    }
    *(undefined2 *)((int)_mfree + 10) = 2;
    word_40B61CC = word_40B61CC + -1;
    cVar8 = 0xfffe < word_40B61D0;
    word_40B61D0 = word_40B61D0 + 1;
    puVar3 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar3;
    puVar2[1] = 0xc;
    cVar9 = '\0';
    cVar10 = '\0';
    cVar11 = '\0';
    bVar12 = 0;
  }
  puVar3 = _mfree;
  uVar4 = (uint)(byte)(cVar8 << 4 | cVar9 << 3 | cVar10 << 2 | cVar11 << 1 | bVar12);
  if (puVar2 != (undefined4 *)0x0) {
    if (_mfree == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)_m_more(0,0xe);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMget);
      }
      *(undefined2 *)((int)_mfree + 10) = 0xe;
      word_40B61CC = word_40B61CC + -1;
      word_40B61E8 = word_40B61E8 + 1;
      puVar6 = (undefined4 *)*_mfree;
      *_mfree = 0;
      _mfree = puVar6;
      puVar3[1] = 0xc;
    }
    if (puVar3 == (undefined4 *)0x0) {
      uVar4 = _m_free(puVar2);
    }
    else {
      puVar2[1] = 0x74;
      *(undefined2 *)(puVar2 + 2) = 8;
      puVar7 = (undefined *)(puVar2[1] + (int)puVar2);
      *puVar7 = 0x12;
      puVar7[1] = 0;
      *(undefined4 *)(puVar7 + 4) = *param_1;
      *(undefined2 *)(puVar7 + 2) = 0;
      uVar5 = _in_cksum(puVar2,8);
      *(undefined2 *)(puVar7 + 2) = uVar5;
      puVar2[1] = puVar2[1] + -0x14;
      *(sword *)(puVar2 + 2) = *(sword *)(puVar2 + 2) + 0x14;
      iVar1 = puVar2[1];
      *(undefined *)((int)puVar2 + iVar1 + 1) = 0;
      *(undefined2 *)((int)puVar2 + iVar1 + 2) = 0x1c;
      *(undefined2 *)((int)puVar2 + iVar1 + 6) = 0;
      *(undefined *)((int)puVar2 + iVar1 + 9) = 2;
      *(undefined4 *)((int)puVar2 + iVar1 + 0xc) = 0;
      *(undefined4 *)((int)puVar2 + iVar1 + 0x10) = *(undefined4 *)(puVar7 + 4);
      puVar6 = (undefined4 *)(puVar3[1] + (int)puVar3);
      *puVar6 = param_1[1];
      *(undefined *)(puVar6 + 1) = 1;
      *(bool *)((int)puVar6 + 5) = _ip_mrouter != 0;
      _ip_output(puVar2,0,0,2,puVar3);
      uVar4 = _m_free(puVar3);
      dword_40BBE3C = dword_40BBE3C + 1;
    }
  }
  return uVar4;
}
