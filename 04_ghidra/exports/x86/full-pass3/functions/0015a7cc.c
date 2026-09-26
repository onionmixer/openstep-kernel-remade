/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a7cc */

undefined4 _kget(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 <= _k_zone_maxsize) {
    iVar3 = 0;
    uVar1 = _k_zone_elemsize;
    while (uVar1 < param_1) {
      iVar3 = iVar3 + 1;
      uVar1 = (&_k_zone_elemsize)[iVar3];
    }
    if (uVar1 <= _k_zone_maxsize) {
      uVar2 = _zget((&_k_zone)[iVar3]);
      return uVar2;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(&DAT_001ded62);
}

