
undefined4 _fd_command(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar2 = (uint *)(param_1 + 0x18);
  while (((*puVar2 & 8) != 0 && (_fd_polling_mode == 0))) {
    *puVar2 = *puVar2 | 0x40;
    _sleep(puVar2,0x14);
  }
  *puVar2 = 9;
  *(int *)(param_1 + 0x5c) = param_2;
  uVar3 = _pmap_kernel();
  *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x50) = uVar3;
  *(sword *)(param_1 + 0x36) =
       (sword)*(undefined4 *)(param_1 + 0x10) << 3 | (sword)_fd_blk_major << 8;
  iVar4 = _fdstrategy(puVar2);
  if (iVar4 == 0) {
    if (_fd_polling_mode == 0) {
      _biowait(puVar2);
    }
    uVar3 = 0;
    if (*(int *)(param_2 + 0x3e) == 0) goto loc_406C52E;
  }
  uVar3 = 5;
loc_406C52E:
  *(undefined4 *)(param_1 + 0x5c) = 0;
  uVar1 = *puVar2;
  *puVar2 = uVar1 & 0xfffffff7;
  if (((uVar1 & 0x40) != 0) && (_fd_polling_mode == 0)) {
    _wakeup(puVar2);
  }
  return uVar3;
}

