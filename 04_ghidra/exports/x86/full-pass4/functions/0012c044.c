/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012c044 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _igmp_sendreport(undefined4 *param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  
  uVar3 = _splimp();
  puVar4 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)_m_more(0,2);
  }
  else {
    if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&DAT_001dbf48);
    }
    *(undefined2 *)((int)_mfree + 10) = 2;
    _DAT_001e917c = _DAT_001e917c + -1;
    _DAT_001e9180 = _DAT_001e9180 + 1;
    puVar5 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar5;
    puVar4[1] = 0xc;
  }
  _splx(uVar3);
  if (puVar4 != (undefined4 *)0x0) {
    uVar3 = _splimp();
    puVar5 = _mfree;
    if (_mfree == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)_m_more(0,0xe);
    }
    else {
      if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&DAT_001dbf4d);
      }
      *(undefined2 *)((int)_mfree + 10) = 0xe;
      _DAT_001e917c = _DAT_001e917c + -1;
      _DAT_001e9198 = _DAT_001e9198 + 1;
      puVar6 = (undefined4 *)*_mfree;
      *_mfree = 0;
      _mfree = puVar6;
      puVar5[1] = 0xc;
    }
    _splx(uVar3);
    if (puVar5 == (undefined4 *)0x0) {
      _m_free(puVar4);
    }
    else {
      puVar4[1] = 0x74;
      *(undefined2 *)(puVar4 + 2) = 8;
      puVar7 = (undefined1 *)((int)puVar4 + puVar4[1]);
      *puVar7 = 0x12;
      puVar7[1] = 0;
      *(undefined4 *)(puVar7 + 4) = *param_1;
      *(undefined2 *)(puVar7 + 2) = 0;
      uVar2 = _in_cksum(puVar4,8);
      *(undefined2 *)(puVar7 + 2) = uVar2;
      puVar4[1] = puVar4[1] + -0x14;
      *(short *)(puVar4 + 2) = *(short *)(puVar4 + 2) + 0x14;
      iVar1 = puVar4[1];
      *(undefined1 *)((int)puVar4 + iVar1 + 1) = 0;
      *(undefined2 *)((int)puVar4 + iVar1 + 2) = 0x1c;
      *(undefined2 *)((int)puVar4 + iVar1 + 6) = 0;
      *(undefined1 *)((int)puVar4 + iVar1 + 9) = 2;
      *(undefined4 *)((int)puVar4 + iVar1 + 0xc) = 0;
      *(undefined4 *)((int)puVar4 + iVar1 + 0x10) = *(undefined4 *)(puVar7 + 4);
      puVar6 = (undefined4 *)((int)puVar5 + puVar5[1]);
      *puVar6 = param_1[1];
      *(undefined1 *)(puVar6 + 1) = 1;
      *(bool *)((int)puVar6 + 5) = _ip_mrouter != 0;
      _ip_output(puVar4,0,0,2,puVar5);
      _m_free(puVar5);
      _DAT_001eee90 = _DAT_001eee90 + 1;
    }
  }
  return;
}

