/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00124590 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _in_bootp_bptombuf(void *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int *piVar5;
  size_t sVar6;
  int iVar7;
  size_t sVar8;
  void *local_10;
  int *local_c;
  int local_8;
  
  sVar8 = 0x148;
  local_10 = param_1;
  local_c = &local_8;
  do {
    uVar4 = _splimp();
    piVar5 = _mfree;
    if (_mfree == (int *)0x0) {
      piVar5 = (int *)_m_more(1,1);
    }
    else {
      if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&DAT_001dbab5);
      }
      *(undefined2 *)((int)_mfree + 10) = 1;
      _DAT_001e917c = _DAT_001e917c + -1;
      _DAT_001e917e = _DAT_001e917e + 1;
      piVar2 = (int *)*_mfree;
      *_mfree = 0;
      _mfree = piVar2;
      piVar5[1] = 0xc;
    }
    _splx(uVar4);
    if ((int)sVar8 < 0x200) {
LAB_001246ac:
      sVar6 = 0x70;
      if ((int)sVar8 < 0x71) {
LAB_001246b6:
        sVar6 = sVar8;
      }
    }
    else {
      uVar4 = _splimp();
      if (_mclfree == (undefined4 *)0x0) {
        _m_clalloc(1,1,0);
      }
      puVar1 = _mclfree;
      if (_mclfree != (undefined4 *)0x0) {
        (&_mclrefcnt)[(int)_mclfree - __mbutl >> 10] =
             (&_mclrefcnt)[(int)_mclfree - __mbutl >> 10] + '\x01';
        _DAT_001e916c = _DAT_001e916c + -1;
        _mclfree = (undefined4 *)*_mclfree;
      }
      _splx(uVar4);
      if (puVar1 == (undefined4 *)0x0) {
        *(undefined2 *)(piVar5 + 2) = 0x70;
      }
      else {
        piVar5[1] = (int)puVar1 - (int)piVar5;
        *(undefined2 *)(piVar5 + 2) = 0x400;
        *(undefined2 *)(piVar5 + 3) = 1;
      }
      if ((short)piVar5[2] != 0x400) goto LAB_001246ac;
      sVar6 = 0x400;
      if ((int)sVar8 < 0x401) goto LAB_001246b6;
    }
    _bcopy(local_10,(void *)((int)piVar5 + piVar5[1]),sVar6);
    sVar8 = sVar8 - sVar6;
    local_10 = (void *)((int)local_10 + sVar6);
    *(short *)(piVar5 + 2) = (short)sVar6;
    *local_c = (int)piVar5;
    local_c = piVar5;
    if ((int)sVar8 < 1) {
      iVar7 = local_8 + *(int *)(local_8 + 4);
      *(undefined2 *)(iVar7 + 10) = 0;
      uVar3 = _in_cksum(local_8,0x14);
      *(undefined2 *)(iVar7 + 10) = uVar3;
      return local_8;
    }
  } while( true );
}

