
byte _mbinit(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  if (_m68k_page_size < 0x1000) {
    iVar2 = 0x1000 / _m68k_page_size;
  }
  else {
    iVar2 = 1;
  }
  cVar3 = CARRY4(iVar2 * 5,iVar2 * 5);
  iVar1 = _m_clalloc(iVar2 * 10,0,0);
  if (iVar1 != 0) {
    iVar2 = _m_clalloc(iVar2 * 10,1,0);
    if (iVar2 != 0) {
      return cVar3 << 4 | (iVar2 < 0) << 3;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(&aMbinit);
}
