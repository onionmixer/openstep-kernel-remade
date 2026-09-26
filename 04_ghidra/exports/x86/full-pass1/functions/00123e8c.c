/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00123e8c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _inet_queue(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  _netisr._0_1_ = (byte)_netisr | 4;
  _wakeup(&_soft_net_wakeup);
  uVar2 = _splimp();
  if (DAT_001eaa78 < DAT_001eaa7c) {
    if (param_2[1] - 0x10 < 0x6d) {
      param_2[1] = param_2[1] + -4;
      *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + 4;
      puVar4 = param_2;
    }
    else {
      uVar3 = _splimp();
      puVar4 = _mfree;
      if (_mfree == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)_m_more(0,2);
      }
      else {
        if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(&DAT_001dbaa7);
        }
        *(undefined2 *)((int)_mfree + 10) = 2;
        _DAT_001e917c = _DAT_001e917c + -1;
        _DAT_001e9180 = _DAT_001e9180 + 1;
        puVar1 = (undefined4 *)*_mfree;
        *_mfree = 0;
        _mfree = puVar1;
        puVar4[1] = 0xc;
      }
      _splx(uVar3);
      if (puVar4 == (undefined4 *)0x0) goto LAB_00123fa3;
      puVar4[1] = 0xc;
      *(undefined2 *)(puVar4 + 2) = 4;
      *puVar4 = param_2;
    }
    if (puVar4 != (undefined4 *)0x0) {
      *(undefined4 *)(puVar4[1] + (int)puVar4) = param_1;
      puVar4[0x1f] = 0;
      puVar1 = puVar4;
      if (DAT_001eaa74 != (undefined4 *)0x0) {
        DAT_001eaa74[0x1f] = puVar4;
        puVar1 = _ipintrq;
      }
      _ipintrq = puVar1;
      DAT_001eaa78 = DAT_001eaa78 + 1;
      DAT_001eaa74 = puVar4;
      goto LAB_00123fac;
    }
  }
LAB_00123fa3:
  DAT_001eaa80 = DAT_001eaa80 + 1;
  _m_freem(param_2);
LAB_00123fac:
  _splx(uVar2);
  return;
}

