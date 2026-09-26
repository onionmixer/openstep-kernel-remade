
void sub_4085946(int param_1)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _port_allocate(dword_40C6EC0,&iStack_8);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoundCanTAlloc);
  }
  if (param_1 != iStack_8) {
    iVar1 = _port_rename(dword_40C6EC0,iStack_8,param_1);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aSoundCanTRenam);
    }
  }
  iVar1 = _port_set_add(dword_40C6EC0,dword_40C6EA8,param_1);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoundCanTAddPo);
  }
  return;
}
