/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015d6b8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0015d6b8(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  void *pvVar6;
  uint uVar7;
  undefined4 local_8;
  
  if (*(short *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
    uVar3 = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x10);
    *(uint *)(param_1 + 0x18) = uVar3;
    if ((((-1 < *(int *)(param_1 + 0x14)) && (0x2b < uVar3)) &&
        (uVar7 = (uint)*(short *)(param_1 + 0x2e), 0x14 < uVar7)) && (uVar7 <= uVar3 - 0x18)) {
      local_8 = 0;
      pvVar6 = (void *)(param_1 + 0x2c);
      puVar1 = &local_8;
      for (; 0 < (int)uVar7; uVar7 = uVar7 - uVar3) {
        uVar4 = _splimp();
        puVar5 = _mfree;
        if (_mfree == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)_m_more(1,1);
        }
        else {
          if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
            _panic(&DAT_001def24);
          }
          *(undefined2 *)((int)_mfree + 10) = 1;
          _DAT_001e917c = _DAT_001e917c + -1;
          _DAT_001e917e = _DAT_001e917e + 1;
          puVar2 = (undefined4 *)*_mfree;
          *_mfree = 0;
          _mfree = puVar2;
          puVar5[1] = 0xc;
        }
        _splx(uVar4);
        if (puVar5 == (undefined4 *)0x0) {
          _m_freem(local_8);
          return;
        }
        if (uVar7 < _page_size >> 1) {
LAB_0015d834:
          uVar3 = 0x70;
          if ((int)uVar7 < 0x71) {
LAB_0015d83e:
            uVar3 = uVar7;
          }
        }
        else {
          uVar4 = _splimp();
          if (_mclfree == (undefined4 *)0x0) {
            _m_clalloc(1,1,0);
          }
          puVar2 = _mclfree;
          if (_mclfree != (undefined4 *)0x0) {
            (&_mclrefcnt)[(int)_mclfree - __mbutl >> 10] =
                 (&_mclrefcnt)[(int)_mclfree - __mbutl >> 10] + '\x01';
            _DAT_001e916c = _DAT_001e916c + -1;
            _mclfree = (undefined4 *)*_mclfree;
          }
          _splx(uVar4);
          if (puVar2 == (undefined4 *)0x0) {
            *(undefined2 *)(puVar5 + 2) = 0x70;
          }
          else {
            puVar5[1] = (int)puVar2 - (int)puVar5;
            *(undefined2 *)(puVar5 + 2) = 0x400;
            *(undefined2 *)(puVar5 + 3) = 1;
          }
          uVar3 = (uint)*(short *)(puVar5 + 2);
          if (_page_size != uVar3) goto LAB_0015d834;
          if (uVar7 <= uVar3) goto LAB_0015d83e;
        }
        *(short *)(puVar5 + 2) = (short)uVar3;
        _bcopy(pvVar6,(void *)((int)puVar5 + puVar5[1]),uVar3);
        pvVar6 = (void *)((int)pvVar6 + uVar3);
        *puVar1 = puVar5;
        puVar1 = puVar5;
      }
      if (DAT_001def18 != *(int *)(param_1 + 0x3c)) {
        if (DAT_001def10 != 0) {
          if (*(short *)(DAT_001def10 + 0x26) == 1) {
            _rtfree(DAT_001def10);
          }
          else {
            *(short *)(DAT_001def10 + 0x26) = *(short *)(DAT_001def10 + 0x26) + -1;
          }
        }
        DAT_001def10 = 0;
      }
      _ip_output(local_8,0,&DAT_001def10,0x21);
    }
  }
  return;
}

