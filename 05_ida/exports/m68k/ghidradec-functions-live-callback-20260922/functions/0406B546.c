
undefined4 _fd_slave(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  byte abStack_6 [2];
  
  iVar5 = (int)*(sword *)(param_2 + 4);
  iVar1 = iVar5 * 0x28;
  if (iVar5 < 1) {
    *(int *)(&DAT_40c3700 + iVar5 * 10) = (int)*(sword *)(param_2 + 8);
    (&dword_40C3704)[iVar5 * 10] = param_1;
    (&dword_40C3708)[iVar5 * 10] = 0;
    (&DAT_40c370c)[iVar5 * 10] = 0;
    (&dword_40C3710)[iVar5 * 10] = param_2;
    *(undefined4 *)(unk_40C3714 + iVar1) = 0;
    *(undefined4 *)(unk_40C3714 + iVar1 + 4) = 0;
    *(undefined4 *)(unk_40C3714 + iVar1 + 8) = 0;
    (&dword_40C3720)[iVar5 * 10] = 0;
    uVar2 = _fd_new_fv(iVar5);
    *(undefined4 *)(_fd_volume_p + iVar5 * 4) = uVar2;
    *(uint *)(unk_40C3714 + iVar1 + 8) = *(uint *)(unk_40C3714 + iVar1 + 8) | 1;
    _fd_assign_dv(uVar2,iVar5);
    _fd_polling_mode = 1;
    iVar3 = _fd_get_status(uVar2,abStack_6);
    if ((iVar3 == 0) && ((abStack_6[0] & 8) != 0)) {
      uVar2 = 1;
      _printf(&aSAs,_fd_drive_info + (&dword_40C3720)[iVar5 * 10] * 0x44);
    }
    else {
      (&dword_40C3708)[iVar5 * 10] = 0;
      *(uint *)(unk_40C3714 + iVar1 + 8) = *(uint *)(unk_40C3714 + iVar1 + 8) & 0xfffffffe;
      _fd_free_fv(uVar2);
      *(undefined4 *)(_fd_volume_p + iVar5 * 4) = 0;
      uVar2 = 0;
    }
    _fd_polling_mode = 0;
    if (unk_40C3758 == 0) {
      unk_40C3758 = _fd_new_fv(8);
    }
    puVar4 = _bdevsw;
    if (_bdevsw < _bdevsw + _nblkdev * 0x18) {
      do {
        if (*(code **)puVar4 == _fdopen) {
          _fd_blk_major = (int)((int)puVar4 + -0x40b087c) * -0x55555555 >> 3;
        }
        puVar4 = (undefined *)((int)puVar4 + 0x18);
      } while (puVar4 < _bdevsw + _nblkdev * 0x18);
    }
    puVar4 = _cdevsw;
    if (_cdevsw < _cdevsw + _nchrdev * 0x2c) {
      do {
        if (*(code **)puVar4 == _fdopen) {
          _fd_raw_major = (int)((int)puVar4 + -0x40b0ac0) * -0x45d1745d >> 2;
        }
        puVar4 = (undefined *)((int)puVar4 + 0x2c);
      } while (puVar4 < _cdevsw + _nchrdev * 0x2c);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

