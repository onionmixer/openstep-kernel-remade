/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011499c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 *
_mclgetx(undefined4 param_1,undefined4 param_2,int param_3,undefined2 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = _splimp();
  puVar3 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)_m_more(param_5,1);
  }
  else {
    if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&DAT_001db214);
    }
    *(undefined2 *)((int)_mfree + 10) = 1;
    _DAT_001e917c = _DAT_001e917c + -1;
    _DAT_001e917e = _DAT_001e917e + 1;
    puVar1 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar1;
    puVar3[1] = 0xc;
  }
  _splx(uVar2);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = param_3 - (int)puVar3;
    *(undefined2 *)(puVar3 + 2) = param_4;
    *(undefined2 *)(puVar3 + 3) = 2;
    puVar3[4] = param_1;
    puVar3[5] = param_2;
    puVar3[6] = 0;
  }
  return puVar3;
}

