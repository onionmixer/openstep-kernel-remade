/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113f6c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _m_more(int param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  uint uVar7;
  
  do {
    bVar1 = false;
    while( true ) {
      iVar4 = _kmem_mb_alloc(_mb_map,_page_size + _page_mask & ~_page_mask);
      if (iVar4 != 0) {
        uVar7 = _page_size >> 7;
        if (uVar7 != 0) {
          puVar6 = (undefined2 *)(iVar4 + 10);
          do {
            *(undefined4 *)(puVar6 + -3) = 0;
            *puVar6 = 1;
            _DAT_001e917e = _DAT_001e917e + 1;
            __mbstat = __mbstat + 1;
            _m_free(iVar4);
            puVar6 = puVar6 + 0x40;
            iVar4 = iVar4 + 0x80;
            uVar7 = uVar7 - 1;
          } while (0 < (int)uVar7);
        }
        if (iVar4 != 0) {
          uVar5 = _splimp();
          puVar2 = _mfree;
          if (_mfree == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_m_more_001db1e8);
          }
          if (*(short *)((int)_mfree + 10) == 0) {
            *(undefined2 *)((int)_mfree + 10) = (undefined2)param_2;
            _DAT_001e917c = _DAT_001e917c + -1;
            *(short *)(&DAT_001e917c + param_2 * 2) = *(short *)(&DAT_001e917c + param_2 * 2) + 1;
            uVar3 = *_mfree;
            *_mfree = 0;
            _mfree = (undefined4 *)uVar3;
            puVar2[1] = 0xc;
            _splx(uVar5);
            return puVar2;
          }
                    /* WARNING: Subroutine does not return */
          _panic(&DAT_001db1e3);
        }
      }
      if ((param_1 == 0) || (iVar4 = _domains, bVar1)) break;
      for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x1c)) {
        uVar7 = *(uint *)(iVar4 + 0x14);
        if (uVar7 < *(uint *)(iVar4 + 0x18)) {
          do {
            if (*(code **)(uVar7 + 0x2c) != (code *)0x0) {
              (**(code **)(uVar7 + 0x2c))();
            }
            uVar7 = uVar7 + 0x30;
          } while (uVar7 < *(uint *)(iVar4 + 0x18));
        }
      }
      _DAT_001e9178 = _DAT_001e9178 + 1;
      bVar1 = true;
    }
    if (param_1 != 1) {
      _DAT_001e9170 = _DAT_001e9170 + 1;
      return (undefined4 *)0x0;
    }
    _DAT_001e9174 = _DAT_001e9174 + 1;
    _m_want = _m_want + 1;
    _sleep(0x1e93d4);
  } while( true );
}

