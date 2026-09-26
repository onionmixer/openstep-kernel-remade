
undefined4 _fdopen(word param_1,byte param_2)

{
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined auStack_6 [2];
  
  uVar1 = (param_1 & 0xff) >> 3;
  bVar2 = (byte)(1 << (param_1 & 7));
  iVar5 = *(int *)(_fd_volume_p + uVar1 * 4);
  if (uVar1 == 8) {
    uVar3 = 0;
  }
  else if (uVar1 < 9) {
    uVar3 = 6;
    iVar4 = 0;
    iVar6 = 0;
    do {
      if (((&byte_40C371F)[iVar6] & 1) != 0) {
        uVar3 = 0;
        _lock_write(&_fd_open_lock);
        if (((param_2 & 4) == 0) || ((iVar5 != 0 && (*(int *)(iVar5 + 4) != 1)))) {
          if (iVar5 == 0) {
            iVar5 = _fd_new_fv(uVar1);
            *(int *)(_fd_volume_p + uVar1 * 4) = iVar5;
            *(uint *)(iVar5 + 0x124) = *(uint *)(iVar5 + 0x124) | 4;
            *(undefined4 *)(iVar5 + 4) = 1;
            iVar4 = _fd_get_status(iVar5,auStack_6);
            if (iVar4 != 0) {
              _fd_free_fv(iVar5);
              uVar3 = 6;
              goto loc_406BB9A;
            }
          }
          if (param_1 >> 8 == _fd_raw_major) {
            *(byte *)(iVar5 + 0x129) = bVar2 | *(byte *)(iVar5 + 0x129);
          }
          else {
            *(byte *)(iVar5 + 0x128) = bVar2 | *(byte *)(iVar5 + 0x128);
          }
          *(undefined2 *)(iVar5 + 0x136) = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 6);
        }
        else {
          uVar3 = 0x23;
        }
loc_406BB9A:
        _lock_done(&_fd_open_lock);
        return uVar3;
      }
      iVar6 = iVar6 + 0x28;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 1);
  }
  else {
    uVar3 = 6;
  }
  return uVar3;
}

