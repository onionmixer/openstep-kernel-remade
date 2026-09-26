
void _fd_attach(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte abStack_6 [2];
  
  iVar3 = (int)*(sword *)(param_1 + 4);
  if (((&byte_40C371F)[iVar3 * 0x28] & 1) != 0) {
    iVar1 = *(int *)(_fd_volume_p + iVar3 * 4);
    if (iVar1 == 0) {
      iVar1 = _fd_new_fv(iVar3);
      *(int *)(_fd_volume_p + iVar3 * 4) = iVar1;
      _fd_assign_dv(iVar1,iVar3);
    }
    _fd_polling_mode = 1;
    iVar2 = _fd_get_status(iVar1,abStack_6);
    if (((iVar2 == 0) && ((abStack_6[0] & 8) != 0)) && ((abStack_6[0] & 0xc0) != 0)) {
      _fd_inner_retry = 2;
      _fd_outer_retry = 1;
      iVar2 = _fd_attach_com(iVar1);
      if (iVar2 == 0) {
        _fd_basic_cmd(iVar1,4);
        _volume_notify(iVar1);
        _fd_polling_mode = 0;
        _fd_inner_retry = 3;
        _fd_outer_retry = 3;
        return;
      }
    }
    _fd_polling_mode = 0;
    (&dword_40C3708)[iVar3 * 10] = 0;
    _fd_free_fv(iVar1);
    _fd_inner_retry = 3;
    _fd_outer_retry = 3;
  }
  return;
}
