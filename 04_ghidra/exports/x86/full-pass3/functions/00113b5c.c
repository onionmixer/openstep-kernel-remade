/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113b5c */

void _mbinit(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (_page_size < 0x1000) {
    iVar1 = (int)(0x1000 / (ulonglong)_page_size);
  }
  else {
    iVar1 = 1;
  }
  uVar2 = _splimp();
  iVar3 = _m_clalloc(iVar1 * 10,0,0);
  if (iVar3 != 0) {
    iVar1 = _m_clalloc(iVar1 * 10,1,0);
    if (iVar1 != 0) {
      _splx(uVar2);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_mbinit_001db1cc);
}

