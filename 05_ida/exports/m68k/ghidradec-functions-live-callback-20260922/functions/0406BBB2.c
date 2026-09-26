
undefined4 _fdclose(word param_1)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  
  uVar2 = (param_1 & 0xff) >> 3;
  iVar1 = *(int *)(_fd_volume_p + uVar2 * 4);
  if (uVar2 != 8) {
    if ((8 < uVar2) || (iVar1 == 0)) {
      return 6;
    }
    bVar3 = (byte)(1 << (param_1 & 7));
    if (param_1 >> 8 == _fd_raw_major) {
      *(byte *)(iVar1 + 0x129) = ~bVar3 & *(byte *)(iVar1 + 0x129);
    }
    else {
      *(byte *)(iVar1 + 0x128) = ~bVar3 & *(byte *)(iVar1 + 0x128);
    }
    _lock_write(&_fd_open_lock);
    if (*(char *)(iVar1 + 0x128) == '\0' && *(char *)(iVar1 + 0x129) == '\0') {
      if (*(int *)(iVar1 + 4) == 1) {
        _fd_free_fv(iVar1);
      }
      else {
        _fd_basic_cmd(iVar1,4);
      }
    }
    _lock_done(&_fd_open_lock);
  }
  return 0;
}

