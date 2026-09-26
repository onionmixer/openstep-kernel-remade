/* GHIDRADEC_FUNCTION index=2000 start=0x406ac7a */

void _fc_eject(int *param_1)

{
  int iVar1;
  undefined auStack_5e [90];
  
  if (((byte)(0x10 << (*(byte *)(param_1[7] + 0x58) & 0x3f)) & *(byte *)(*param_1 + 2)) == 0) {
    _fc_motor_on(param_1);
  }
  iVar1 = *(int *)((int)param_1 + 0x25e);
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  _bzero(auStack_5e,0x5a);
  _fd_gen_seek(iVar1,auStack_5e,0x4f,0);
  iVar1 = _fc_send_cmd(param_1,auStack_5e);
  if (iVar1 == 0) {
    _fc_flpctl_bset(param_1,0x80);
    _delay(3);
    _fc_flpctl_bclr(param_1,0x80);
    _fc_flags_bclr(param_1,0x40);
    sub_406B38A(param_1,2000000,4000000);
    *(undefined4 *)(param_1[7] + 0x3e) = 0;
  }
  else {
    *(int *)(param_1[7] + 0x3e) = iVar1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2001 start=0x406ad40 */

uint _fc_motor_on(int *param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  
  iVar1 = *param_1;
  bVar4 = (byte)(0x10 << (*(byte *)(param_1[7] + 0x58) & 0x3f));
  bVar2 = bVar4 & *(byte *)(iVar1 + 2);
  uVar3 = (uint)bVar2;
  if (bVar2 == 0) {
    *(byte *)(iVar1 + 2) = bVar4 | *(byte *)(iVar1 + 2);
    _fc_flags_bclr(param_1,0x40);
    uVar3 = sub_406B38A(param_1,500000,1000000);
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2002 start=0x406ad94 */

void _fc_motor_off(int *param_1)

{
  *(byte *)(*param_1 + 2) =
       ~(byte)(0x10 << (*(byte *)(param_1[7] + 0x58) & 0x3f)) & *(byte *)(*param_1 + 2);
  return;
}
/* GHIDRADEC_FUNCTION index=2003 start=0x406adbc */

int _fc_send_cmd(undefined4 *param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined *puVar7;
  uint uVar8;
  int iVar9;
  
  iVar6 = 0;
  bVar3 = false;
  bVar2 = false;
  iVar9 = *(int *)(param_2 + 0x22);
  uVar4 = 0;
  bVar1 = *(byte *)(param_2 + 10) & 0x1f;
  *(undefined4 *)(param_2 + 0x3e) = 0xffffffff;
  *(undefined4 *)(param_2 + 0x42) = 0;
  *(undefined4 *)(param_2 + 0x46) = 0;
  *(undefined4 *)(param_2 + 0x4a) = 0;
  if (0 < iVar9) {
    if (0x100000 < iVar9) {
      iVar6 = 4;
      _printf(aFdDmaByteCount);
      goto loc_406B29E;
    }
    uVar8 = *(uint *)(param_2 + 0x3a) & 2;
    uVar5 = 0;
    if ((uVar8 == 0) || (uVar5 = 0x40000, uVar8 == 0)) {
      uVar4 = 0x10;
      iVar9 = iVar9 + 0x10;
    }
    _dma_list((int)param_1 + 0x26,(int)param_1 + 0x11e,*(undefined4 *)(param_2 + 0x1e),iVar9,
              *(undefined4 *)(param_2 + 0x50),uVar5,10,0,uVar4);
    _dma_start((int)param_1 + 0x26,(int)param_1 + 0x11e,uVar5);
    bVar2 = true;
  }
  sub_406B346(param_1,param_2);
  _fc_start_timer(param_1,10000);
  puVar7 = (undefined *)(param_2 + 10);
  uVar8 = 0;
  if (*(int *)(param_2 + 0x1a) != 0) {
    do {
      iVar6 = _fc_send_byte(param_1,*puVar7);
      if (iVar6 != 0) {
        if (iVar6 == 10) {
          _fc_stop_timer(param_1);
          _fc_flags_bset(param_1,0x400);
        }
        goto loc_406B29E;
      }
      *(int *)(param_2 + 0x42) = *(int *)(param_2 + 0x42) + 1;
      uVar8 = uVar8 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar8 < *(uint *)(param_2 + 0x1a));
  }
  _fc_stop_timer(param_1);
  if (iVar9 < 1) {
    _fc_flags_bclr(param_1,0x4000);
  }
  else {
    _fc_flags_bset(param_1,0x4000);
    if ((*(byte *)(param_2 + 0x3d) & 2) == 0) {
      **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) & 0xf7;
      _fc_flags_bclr(param_1,0x8000);
    }
    else {
      **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) | 8;
      _fc_flags_bset(param_1,0x8000);
    }
    **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) | 0x10;
  }
  switch(bVar1) {
  case :
  case :
  case :
  case :
  case :
  case :
  case :
    break;
  :
    iVar6 = sub_406B38A(param_1,*(int *)(param_2 + 2) * 1000,*(int *)(param_2 + 2) * 2000);
  }
  if ((param_1[6] & 0x10) != 0) {
    _fc_stop_timer(param_1);
  }
  if (((param_1[6] & 0x4000) != 0) && ((**(byte **)((int)param_1 + 0x236) & 0x10) != 0)) {
    iVar9 = 0;
    if (_dma_chip == 0x139) goto loc_406B016;
    while (iVar9 < 1) {
loc_406B016:
      while( true ) {
        **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) | 4;
        _delay(5);
        **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) & 0xfb;
        _delay(5);
        iVar9 = iVar9 + 1;
        if (_dma_chip != 0x139) break;
        if (7 < iVar9) goto loc_406B04C;
      }
    }
loc_406B04C:
    **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) & 0xef;
  }
  if (iVar6 != 0) {
    if (iVar6 != 1) goto loc_406B29E;
    bVar3 = true;
  }
  if (*(uint *)(param_2 + 0x4a) < *(uint *)(param_2 + 0x36)) {
    _fc_start_timer(param_1,10000);
  }
  uVar8 = *(uint *)(param_2 + 0x4a);
  iVar9 = param_2 + 0x26 + uVar8;
  if (uVar8 < *(uint *)(param_2 + 0x36)) {
    do {
      iVar6 = _fc_get_byte(param_1,iVar9);
      if (iVar6 != 0) {
        if ((iVar6 != 10) || (*(int *)(param_2 + 0x4a) == 0)) goto loc_406B29E;
        break;
      }
      *(int *)(param_2 + 0x4a) = *(int *)(param_2 + 0x4a) + 1;
      uVar8 = uVar8 + 1;
      iVar9 = iVar9 + 1;
    } while (uVar8 < *(uint *)(param_2 + 0x36));
  }
  if ((param_1[6] & 0x10) != 0) {
    _fc_stop_timer(param_1);
  }
  if ((param_1[6] & 0x4000) != 0) {
    _fc_flags_bclr(param_1,0x4000);
    *(undefined4 *)(param_2 + 0x46) = *(undefined4 *)(param_2 + 0x22);
    if (*(uint *)(param_2 + 0x22) < *(uint *)(param_2 + 0x46)) {
      *(uint *)(param_2 + 0x46) = *(uint *)(param_2 + 0x22);
    }
    if ((param_1[6] & 0x10000) != 0) {
      iVar6 = 3;
    }
    _dma_cleanup((int)param_1 + 0x26,0);
    bVar2 = false;
    sub_406B2D4(param_1);
  }
  if (iVar6 == 0) {
    switch(bVar1) {
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      if (*(int *)(param_2 + 0x4a) == 0) {
        iVar6 = 0x12;
        goto loc_406B29E;
      }
      bVar1 = *(byte *)(param_2 + 0x26) & 0xc0;
      if (((bVar1 == 0) || (*(byte *)(param_2 + 0x27) == 0x80)) ||
         ((*(int *)(param_2 + 0x22) != 0 &&
          (((bVar1 == 0x40 && (*(int *)(param_2 + 0x22) == *(int *)(param_2 + 0x46))) &&
           ((*(byte *)(param_2 + 0x27) & 0x10) != 0)))))) goto loc_406B29E;
      if ((*(byte *)(param_2 + 0x26) & 0x10) != 0) {
        iVar6 = 0xb;
        goto loc_406B29E;
      }
      if (*(uint *)(param_2 + 0x4a) < 7) {
        iVar6 = 8;
        goto loc_406B29E;
      }
      bVar1 = *(byte *)(param_2 + 0x27);
      if ((bVar1 & 0x20) != 0) {
        iVar6 = 7;
        if ((*(byte *)(param_2 + 0x28) & 0x20) != 0) {
          iVar6 = 6;
        }
        goto loc_406B29E;
      }
      if ((bVar1 & 0x10) != 0) {
        iVar6 = 0x13;
        goto loc_406B29E;
      }
      if ((bVar1 & 4) != 0) {
        iVar6 = 0xc;
        goto loc_406B29E;
      }
      if ((bVar1 & 2) != 0) {
        iVar6 = 0xd;
        goto loc_406B29E;
      }
      if ((bVar1 & 1) != 0) {
        iVar6 = 0xe;
        goto loc_406B29E;
      }
      bVar1 = *(byte *)(param_2 + 0x28);
      if ((bVar1 & 0x40) != 0) {
        iVar6 = 0xf;
        goto loc_406B29E;
      }
      if ((bVar1 & 0x12) == 0) {
        if ((bVar1 & 1) != 0) {
          iVar6 = 0x10;
        }
        goto loc_406B29E;
      }
      break;
    :
      goto loc_406B29E;
    case :
      if (((*(byte *)(param_2 + 0x26) & 0x20) != 0) &&
         ((*(char *)(param_2 + 0x27) == '\0' && ((*(byte *)*param_1 & 0x10) == 0))))
      goto loc_406B29E;
      break;
    case :
      if (((*(byte *)(param_2 + 0x26) & 0x20) != 0) &&
         ((*(char *)(param_2 + 10) < '\0' || (*(char *)(param_2 + 0x27) == *(char *)(param_2 + 0xc))
          ))) goto loc_406B29E;
    }
    iVar6 = 9;
  }
loc_406B29E:
  if ((param_1[6] & 0x10) != 0) {
    _fc_stop_timer(param_1);
  }
  if (bVar2) {
    _dma_abort((int)param_1 + 0x26);
  }
  if (bVar3) {
    iVar6 = 1;
  }
  return iVar6;
}
/* GHIDRADEC_FUNCTION index=2004 start=0x406b448 */

void _fc_start_timer(int param_1,int param_2)

{
  int iStack_c;
  int iStack_8;
  
  if (_fd_polling_mode == 0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffff7;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x10;
    if (param_2 < 1000000) {
      iStack_c = 0;
    }
    else {
      iStack_c = param_2 / 1000000;
      param_2 = param_2 % 1000000;
    }
    iStack_8 = param_2;
    _us_timeout(_fc_timeout,param_1,&iStack_c,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2005 start=0x406b4da */

void _fc_timeout(int param_1)

{
  _fc_flags_bset(param_1,8);
  _fc_flags_bclr(param_1,0x10);
  _thread_wakeup_prim(param_1 + 0x18,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2006 start=0x406b512 */

void _fc_stop_timer(undefined4 param_1)

{
  if (_fd_polling_mode == 0) {
    _us_untimeout(_fc_timeout,param_1);
    _fc_flags_bclr(param_1,0x18);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2007 start=0x406b546 */

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
/* GHIDRADEC_FUNCTION index=2008 start=0x406b6ea */

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
/* GHIDRADEC_FUNCTION index=2009 start=0x406b7dc */

undefined4 _fd_attach_com(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  uint **ppuVar8;
  undefined *puStack_a0;
  uint *puStack_9c;
  int iStack_98;
  uint *puStack_94;
  uint *puStack_90;
  uint *puStack_8c;
  uint auStack_68 [2];
  uint auStack_60 [23];
  
  uVar1 = param_1[5];
  puVar2 = param_1 + 0x5a;
  if ((*(byte *)((int)param_1 + 0x179) & 2) != 0) {
    return 0;
  }
  *(undefined4 *)((int)param_1 + 0x17a) = 3;
  *(uint *)((int)param_1 + 0x176U) = *(uint *)((int)param_1 + 0x176U) & 0xfffffffe;
  iVar6 = 2;
  do {
    puStack_8c = param_1;
    puStack_90 = (uint *)0x406b814;
    iVar3 = _fd_recal();
    if (iVar3 == 0) break;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (iVar6 == 0) {
    *(undefined4 *)((int)param_1 + 0x17a) = 0;
    puStack_8c = (uint *)aFdRecalibrateF;
loc_406B9D6:
    puStack_90 = (uint *)0x406b9dc;
    _printf();
    return 5;
  }
  *puVar2 = 0;
  puStack_8c = auStack_60;
  puStack_90 = param_1;
  puStack_94 = (uint *)0x406b83e;
  iVar6 = _fd_get_status();
  if (iVar6 != 0) {
    puStack_8c = (uint *)aFdControllerIO;
    goto loc_406B9D6;
  }
  if ((auStack_60[0] & 0x8000000) == 0) {
    puStack_8c = (uint *)aFdNoDriveDetec;
    goto loc_406B9D6;
  }
  if ((auStack_60[0] & 0xc0000000) == 0) {
    puStack_8c = (uint *)aFdNoMediaDetec;
    goto loc_406B9D6;
  }
  if ((auStack_60[0] & 0x10000000) == 0) {
    *(uint *)((int)param_1 + 0x176U) = *(uint *)((int)param_1 + 0x176U) & 0xfffffffb;
  }
  else {
    *(uint *)((int)param_1 + 0x176U) = *(uint *)((int)param_1 + 0x176U) | 4;
  }
  *puVar2 = auStack_60[0] >> 0x1e;
  puVar7 = _fd_disk_info;
  if (_fd_disk_info._0_4_ != 0) {
    do {
      if (auStack_60[0] >> 0x1e == *(uint *)puVar7) break;
      puVar7 = (undefined *)((int)puVar7 + 0xe);
    } while (*(uint *)puVar7 != 0);
  }
  *puVar2 = *(uint *)puVar7;
  param_1[0x5b] = *(uint *)((int)puVar7 + 4);
  param_1[0x5c] = *(uint *)((int)puVar7 + 8);
  *(undefined2 *)(param_1 + 0x5d) = *(undefined2 *)((int)puVar7 + 0xc);
  *(undefined4 *)((int)param_1 + 0x182) = 1;
  *(int *)((int)param_1 + 0x17a) = *(int *)((int)param_1 + 0x172);
  if (*(int *)((int)param_1 + 0x172) != 0) {
    do {
      iVar6 = 2;
      do {
        puStack_8c = (uint *)0x0;
        puStack_90 = (uint *)0x1;
        puStack_94 = param_1;
        iStack_98 = 0x406b8d2;
        iVar3 = _fd_seek();
        if (iVar3 != 0) {
          puStack_8c = (uint *)aFdSeekFailed;
          goto loc_406B9D6;
        }
        puStack_8c = auStack_68;
        puStack_90 = (uint *)0x0;
        puStack_94 = param_1;
        iStack_98 = 0x406b8ea;
        iVar3 = _fd_readid();
        if (iVar3 == 0) goto loc_406B908;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      iVar3 = *(int *)((int)param_1 + 0x17a);
      *(int *)((int)param_1 + 0x17a) = iVar3 + -1;
    } while (iVar3 != 1);
loc_406B908:
    puStack_8c = *(uint **)((int)param_1 + 0x17a);
    if (puStack_8c != (uint *)0x0) {
      puStack_90 = param_1;
      puStack_94 = (uint *)0x406b94c;
      _fd_set_density_info();
      *(uint *)((int)param_1 + 0x176U) = *(uint *)((int)param_1 + 0x176U) | 1;
      puStack_94 = *(uint **)((int)param_1 + 0x17a);
      iStack_98 = 0x406b95c;
      piVar4 = (int *)_fd_get_sectsize_info();
      iVar3 = *piVar4;
      while (iVar3 != 0) {
        puStack_8c = (uint *)*piVar4;
        puStack_90 = param_1;
        puStack_94 = (uint *)0x406b974;
        _fd_set_sector_size();
        iVar6 = 0;
        iVar3 = 2;
        do {
          puStack_8c = (uint *)0x1;
          puStack_90 = (uint *)param_1[5];
          puStack_94 = (uint *)0x1;
          puStack_9c = param_1;
          puStack_a0 = (undefined *)0x406b998;
          iStack_98 = iVar6;
          iVar5 = _fd_raw_rw();
          if (iVar5 == 0) goto loc_406B9E0;
          iVar6 = param_1[99] + 1 + iVar6;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        piVar4 = piVar4 + 3;
        iVar6 = 0;
        iVar3 = *piVar4;
      }
      if (iVar6 == 0) {
        puStack_8c = (uint *)aFdDiskUnreadab;
        puStack_90 = (uint *)0x406b9c8;
        _printf();
        *(uint *)((int)param_1 + 0x176U) = *(uint *)((int)param_1 + 0x176U) & 0xfffffffe;
        return 0;
      }
loc_406B9E0:
      puStack_8c = param_1;
      puStack_90 = (uint *)0x406b9e8;
      iVar6 = _fd_get_label();
      if (iVar6 == 0) {
        puStack_8c = param_1;
        puStack_90 = (uint *)0x406b9f6;
        _fd_setbratio();
        puStack_90 = (uint *)(uVar1 + 0xc);
        puStack_94 = (uint *)aDiskLabelS;
        iStack_98 = 0x406ba0a;
        _printf();
        iStack_98 = *(int *)((int)param_1 + 0x186);
        puStack_9c = (uint *)(*(int *)((int)param_1 + 0x16e) *
                              (uint)*(byte *)(param_1 + 0x5b) *
                              param_1[99] * *(int *)((int)param_1 + 0x186) >> 10);
        puStack_a0 = aDiskCapacityDK;
        _printf();
      }
      if ((*(byte *)((int)param_1 + 0x179) & 4) == 0) {
        return 0;
      }
      ppuVar8 = &puStack_8c;
      puStack_8c = (uint *)aDiskIsWritePro;
      goto loc_406BA48;
    }
  }
  puVar2 = *(uint **)((int)param_1 + 0x172);
  puStack_90 = (uint *)0x406b91a;
  puStack_8c = puVar2;
  piVar4 = (int *)_fd_get_sectsize_info();
  iVar6 = *piVar4;
  puStack_94 = param_1;
  iStack_98 = 0x406b928;
  puStack_90 = puVar2;
  _fd_set_density_info();
  puStack_9c = param_1;
  puStack_a0 = (undefined *)0x406b932;
  iStack_98 = iVar6;
  _fd_set_sector_size();
  *(uint *)((int)param_1 + 0x176U) = *(uint *)((int)param_1 + 0x176U) & 0xfffffffe;
  ppuVar8 = (uint **)&puStack_a0;
  puStack_a0 = aFdDiskUnformat;
loc_406BA48:
  *(undefined4 *)((int)ppuVar8 + -4) = 0x406ba4e;
  _printf();
  return 0;
}
/* GHIDRADEC_FUNCTION index=2010 start=0x406ba5a */

undefined4 _fdsize(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  param_1._3_4_ = param_1._3_4_ >> 0x1b;
  iVar1 = *(int *)(_fd_volume_p + param_1._3_4_ * 4);
  if (param_1._3_4_ == 8) {
    uVar2 = 0;
  }
  else if ((param_1._3_4_ < 9) && (iVar1 != 0)) {
    if ((*(byte *)(iVar1 + 0x179) & 2) == 0) {
      uVar2 = *(undefined4 *)(iVar1 + 0x186);
    }
    else {
      uVar2 = *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x5c);
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2011 start=0x406baa0 */

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
/* GHIDRADEC_FUNCTION index=2012 start=0x406bbb2 */

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
/* GHIDRADEC_FUNCTION index=2013 start=0x406bc58 */

undefined4 _fdread(word param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = (param_1 & 0xff) >> 3;
  iVar1 = *(int *)(_fd_volume_p + uVar2 * 4);
  if ((uVar2 < 8) && (iVar1 != 0)) {
    if ((param_1 & 7) == 1) {
      uVar3 = *(undefined4 *)(iVar1 + 0x186);
    }
    else {
      if ((*(byte *)(iVar1 + 0x179) & 2) == 0) goto loc_406BC96;
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x5c);
    }
    uVar3 = _physio(_fdstrategy,*(int *)(_fd_volume_p + uVar2 * 4) + 0xe0,(int)(sword)param_1,1,
                    sub_406BD66,param_2,uVar3);
  }
  else {
loc_406BC96:
    uVar3 = 6;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2014 start=0x406bce0 */

undefined4 _fdwrite(word param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = (param_1 & 0xff) >> 3;
  iVar1 = *(int *)(_fd_volume_p + uVar2 * 4);
  if ((uVar2 < 8) && (iVar1 != 0)) {
    if ((param_1 & 7) == 1) {
      uVar3 = *(undefined4 *)(iVar1 + 0x186);
    }
    else {
      if ((*(byte *)(iVar1 + 0x179) & 2) == 0) goto loc_406BD1E;
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x5c);
    }
    uVar3 = _physio(_fdstrategy,*(int *)(_fd_volume_p + uVar2 * 4) + 0xe0,(int)(sword)param_1,0,
                    sub_406BD66,param_2,uVar3);
  }
  else {
loc_406BD1E:
    uVar3 = 6;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2015 start=0x406bd84 */

undefined4 _fdstrategy(uint *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar4 = (*(word *)((int)param_1 + 0x1e) & 0xff) >> 3;
  uVar3 = *(word *)((int)param_1 + 0x1e) & 7;
  iVar2 = *(int *)(_fd_volume_p + uVar4 * 4);
  uVar6 = 0;
  if ((uVar4 < 0xb) && (iVar2 != 0)) {
    iVar5 = *(int *)(iVar2 + 0x14);
    if ((uint *)(iVar2 + 0x18) == param_1) {
loc_406BE86:
      iVar5 = iVar2 + 0xba;
      if ((uint *)(iVar2 + 0x18) == param_1) {
        if (*(int *)(*(int *)(iVar2 + 0x5c) + 6) == 2) {
          _disksort_enter_tail(iVar5,param_1);
        }
        else {
          _disksort_enter_head(iVar5,param_1);
        }
      }
      else {
        _disksort_enter(iVar5,param_1);
      }
      if (*(int *)(iVar2 + 0x132) != 0) {
        return 0;
      }
      uVar6 = _fd_start(iVar2);
      return uVar6;
    }
    if ((*(uint *)(iVar2 + 0x176) & 1) == 0) goto loc_406BE0E;
    if ((param_1[5] & *(int *)(iVar2 + 0x186) - 1U) == 0) {
      if (((*param_1 & 1) == 0) && ((*(uint *)(iVar2 + 0x176) & 4) != 0)) {
        *(undefined2 *)(param_1 + 7) = 0x1e;
        goto loc_406BEE2;
      }
      if (uVar3 != 1) {
        if ((*(byte *)(iVar2 + 0x179) & 2) != 0) {
          uVar4 = param_1[9];
          param_1[0xe] = uVar4;
          if (uVar3 < 2) {
            piVar1 = (int *)(iVar5 + uVar3 * 0x2e + 0xbe);
            uVar3 = piVar1[1];
            if (((uVar3 == 0) || ((int)uVar4 < 0)) || ((int)uVar3 < (int)uVar4)) goto loc_406BE72;
            if (uVar3 != uVar4) {
              uVar4 = *piVar1 + uVar4;
              param_1[0xe] = uVar4;
              iVar5 = *(int *)(iVar5 + 0x60) * *(int *)(iVar5 + 100);
              if (0 < iVar5) {
                param_1[0xe] = (int)uVar4 / iVar5;
              }
              goto loc_406BE86;
            }
            goto loc_406BE7E;
          }
        }
        goto loc_406BE0E;
      }
      uVar3 = param_1[9];
      param_1[0xe] = uVar3;
      if ((-1 < (int)uVar3) && (uVar3 <= *(uint *)(iVar2 + 0x192))) {
        if (*(uint *)(iVar2 + 0x192) != uVar3) goto loc_406BE86;
loc_406BE7E:
        param_1[10] = param_1[5];
        goto loc_406BEE8;
      }
    }
loc_406BE72:
    *(undefined2 *)(param_1 + 7) = 0x16;
  }
  else {
loc_406BE0E:
    *(undefined2 *)(param_1 + 7) = 6;
  }
loc_406BEE2:
  *param_1 = *param_1 | 4;
  uVar6 = 0xffffffff;
loc_406BEE8:
  _biodone(param_1);
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=2016 start=0x406befc */

int _fdioctl(undefined8 param_1,uint *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined2 uVar6;
  int iVar3;
  int iVar4;
  uint uVar5;
  int unaff_D2;
  word wVar7;
  int iVar8;
  uint unaff_D5;
  undefined *puVar9;
  undefined2 *puVar10;
  int iStack_1a;
  undefined auStack_16 [10];
  uint uStack_c;
  undefined4 uStack_8;
  
  iVar4 = (int)param_1;
  puVar9 = _fd_volume_p;
  iVar3 = *(int *)(_fd_volume_p + (param_1._3_4_ >> 0x1b) * 4);
  uVar5 = *param_2;
  if (iVar3 == 0) {
    return 6;
  }
  if (iVar4 == 0x40046411) {
    if ((byte_40C371F & 1) == 0) {
      return 0x13;
    }
    uVar5 = 0;
    do {
      if (*(int *)puVar9 == 0) {
        *param_2 = uVar5;
        return 0;
      }
      puVar9 = (undefined *)((int)puVar9 + 4);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 8);
    *param_2 = 0xffffffff;
    return 0;
  }
  if (iVar4 < 0x40046412) {
    if (iVar4 == -0x7ffb99fa) {
      _fd_inner_retry = uVar5;
      return 0;
    }
    if (iVar4 == -0x7ffb99f8) {
      _fd_outer_retry = uVar5;
      return 0;
    }
  }
  else {
    if (iVar4 == 0x40046607) {
      *param_2 = _fd_inner_retry;
      return 0;
    }
    if (iVar4 == 0x40046609) {
      *param_2 = _fd_outer_retry;
      return 0;
    }
  }
  if (7 < param_1._3_4_ >> 0x1b) {
    return 6;
  }
  if (iVar4 == 0x20006401) {
    iVar4 = _suser();
    if (iVar4 == 0) {
      return (int)*(char *)(dword_40B57D4 + 100);
    }
    iVar4 = _copyinmsg(uVar5,*(undefined4 *)(iVar3 + 0x14),0x1c48);
    if (iVar4 == 0) {
      piVar1 = *(int **)(iVar3 + 0x14);
      if ((*piVar1 == 0x4e655854) || (*piVar1 == 0x646c5632)) {
        wVar7 = 0x1c48;
        puVar10 = (undefined2 *)((int)piVar1 + 0x1c46);
      }
      else {
        wVar7 = 0x230;
        puVar10 = (undefined2 *)((int)piVar1 + 0x22e);
      }
      uStack_c = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
                 0xfffff;
      if ((((uStack_c ^ *_event_middle) & 0x80000) != 0) &&
         (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
        *_event_high = *_event_high + 1;
      }
      uStack_8 = *_event_high;
      uStack_c = uStack_c | *_event_middle;
      *(uint *)(*(int *)(iVar3 + 0x14) + 0x28) = uStack_c;
      *(undefined4 *)(*(int *)(iVar3 + 0x14) + 4) = 0;
      *puVar10 = 0;
      uVar6 = _checksum_16(*(undefined4 *)(iVar3 + 0x14),wVar7 >> 1);
      *puVar10 = uVar6;
      iVar4 = _sdchecklabel(*(undefined4 *)(iVar3 + 0x14),0);
      if (iVar4 == 0) {
        return 0x16;
      }
      iVar3 = _fd_write_label(iVar3);
      if (iVar3 != 0) {
        return 5;
      }
      return 0;
    }
    return iVar4;
  }
  if (0x20006401 < iVar4) {
    if (iVar4 == 0x40046418) {
      *param_2 = *(uint *)(iVar3 + 0x186);
      return 0;
    }
    if (iVar4 < 0x40046419) {
      if (iVar4 == 0x20006415) {
        iVar4 = _suser();
        if ((iVar4 == 0) &&
           (*(sword *)(iVar3 + 0x136) != *(sword *)(*(int *)(_active_u + 0x1a) + 6))) {
          return (int)*(char *)(dword_40B57D4 + 100);
        }
        _update(*(int *)(iVar3 + 0x10) << 3 | _fd_blk_major << 8,0xfffffff8);
        iVar3 = _fd_basic_cmd(iVar3,2);
        return iVar3;
      }
      if (iVar4 == 0x40046417) {
        *param_2 = *(uint *)(iVar3 + 0x176) & 1;
        return 0;
      }
    }
    else {
      if (iVar4 == 0x402e6601) {
        *param_2 = *(uint *)(iVar3 + 0x168);
        param_2[1] = *(uint *)(iVar3 + 0x16c);
        param_2[2] = *(uint *)(iVar3 + 0x170);
        param_2[3] = *(uint *)(iVar3 + 0x174);
        param_2[4] = *(uint *)(iVar3 + 0x178);
        param_2[5] = *(uint *)(iVar3 + 0x17c);
        param_2[6] = *(uint *)(iVar3 + 0x180);
        param_2[7] = *(uint *)(iVar3 + 0x184);
        param_2[8] = *(uint *)(iVar3 + 0x188);
        param_2[9] = *(uint *)(iVar3 + 0x18c);
        param_2[10] = *(uint *)(iVar3 + 400);
        *(undefined2 *)(param_2 + 0xb) = *(undefined2 *)(iVar3 + 0x194);
        return 0;
      }
      if (iVar4 < 0x402e6602) {
        if (iVar4 == 0x40046419) {
          *param_2 = *(uint *)(iVar3 + 0x192);
          return 0;
        }
      }
      else if (iVar4 == 0x40306405) {
        iVar4 = *(int *)(iVar3 + 4);
        if (iVar4 == 1) {
          iVar4 = 0;
        }
        iVar4 = (&dword_40C3720)[iVar4 * 10] * 0x44;
        *param_2 = *(uint *)(_fd_drive_info + iVar4);
        param_2[1] = *(uint *)(_fd_drive_info + iVar4 + 4);
        param_2[2] = *(uint *)(_fd_drive_info + iVar4 + 8);
        param_2[3] = *(uint *)(_fd_drive_info + iVar4 + 0xc);
        param_2[4] = *(uint *)(DAT_40b12de + iVar4);
        param_2[5] = *(uint *)(DAT_40b12de + iVar4 + 4);
        param_2[6] = *(uint *)(DAT_40b12de + iVar4 + 8);
        param_2[7] = *(uint *)(DAT_40b12de + iVar4 + 0xc);
        param_2[8] = *(uint *)(DAT_40b12de + iVar4 + 0x10);
        param_2[9] = *(uint *)(DAT_40b12de + iVar4 + 0x14);
        param_2[10] = *(uint *)(DAT_40b12de + iVar4 + 0x18);
        param_2[0xb] = *(uint *)(DAT_40b12de + iVar4 + 0x1c);
        param_2[10] = *(uint *)(iVar3 + 0x186);
        _sprintf(auStack_16,&aD_1,*(undefined4 *)(iVar3 + 0x192));
        _strcat(param_2,auStack_16);
        return 0;
      }
    }
loc_406C46E:
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
    return 0x16;
  }
  if (iVar4 == -0x7ffb99fc) {
    *(char *)(iVar3 + 400) = (char)*param_2;
    return 0;
  }
  if (iVar4 < -0x7ffb99fb) {
    if (iVar4 == -0x7ffb99fe) {
      if (3 < *param_2) {
        return 0x16;
      }
      _fd_set_density_info(iVar3,*param_2);
      return 0;
    }
    if (iVar4 == -0x7ffb99fd) {
      iVar3 = _fd_set_sector_size(iVar3,*param_2);
      if (iVar3 != 0) {
        return 0x16;
      }
      return 0;
    }
    goto loc_406C46E;
  }
  if (iVar4 != -0x3fa59a00) {
    if (-0x3fa59a00 < iVar4) {
      if (iVar4 == 0x20006400) {
        if ((*(byte *)(iVar3 + 0x179) & 2) == 0) {
          return 6;
        }
        iVar3 = _copyoutmsg(*(undefined4 *)(iVar3 + 0x14),uVar5,0x1c48);
        return iVar3;
      }
      goto loc_406C46E;
    }
    if (iVar4 != -0x3fe799fb) goto loc_406C46E;
    iVar8 = *(int *)(iVar3 + 0x186) * param_2[1];
    if (*(int *)(iVar3 + 0x176) == 0) {
      return 0x16;
    }
    unaff_D2 = _kalloc(iVar8);
    if (unaff_D2 == 0) {
      param_2[4] = 2;
      return 0xc;
    }
    if ((param_2[3] == 0) && (iVar4 = _copyinmsg(param_2[2],unaff_D2,iVar8), iVar4 != 0)) {
      param_2[4] = 3;
    }
    else {
      uVar5 = _fd_live_rw(iVar3,*param_2,param_2[1],unaff_D2,param_2[3],&iStack_1a);
      param_2[4] = uVar5;
      iVar4 = 0;
      param_2[5] = param_2[1] - iStack_1a;
      if ((param_2[3] != 0) && (param_2[1] - iStack_1a != 0)) {
        iVar4 = _copyoutmsg(unaff_D2,param_2[2],iVar8);
      }
    }
    goto loc_406C464;
  }
  uVar5 = *(uint *)((int)param_2 + 0x22);
  if (uVar5 == 0) {
loc_406C370:
    uVar2 = *(undefined4 *)((int)param_2 + 0x1e);
    *(uint *)((int)param_2 + 0x1e) = unaff_D5;
    iVar4 = _fd_command(iVar3,param_2);
    if (*(int *)((int)param_2 + 0x3e) != 0) {
      iVar4 = 0;
    }
    *(undefined4 *)((int)param_2 + 0x1e) = uVar2;
    if (((*(byte *)((int)param_2 + 0x3d) & 2) != 0) && (*(int *)((int)param_2 + 0x46) != 0)) {
      iVar4 = _copyoutmsg(unaff_D5,uVar2,*(int *)((int)param_2 + 0x46));
    }
  }
  else {
    if ((uVar5 & 0xf) != 0) {
      return 0x16;
    }
    unaff_D2 = _kalloc(uVar5 + 0x10);
    unaff_D5 = unaff_D2 + 0xfU & 0xfffffff0;
    if (unaff_D2 == 0) {
      *(undefined4 *)((int)param_2 + 0x3e) = 2;
      return 0xc;
    }
    if (((*(byte *)((int)param_2 + 0x3d) & 2) != 0) ||
       (iVar4 = _copyinmsg(*(undefined4 *)((int)param_2 + 0x1e),unaff_D5,
                           *(undefined4 *)((int)param_2 + 0x22)), iVar4 == 0)) goto loc_406C370;
    *(undefined4 *)((int)param_2 + 0x3e) = 3;
  }
  if (*(int *)((int)param_2 + 0x22) == 0) {
    return iVar4;
  }
  iVar8 = *(int *)((int)param_2 + 0x22) + 0x10;
loc_406C464:
  _kfree(unaff_D2,iVar8);
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=2017 start=0x406c490 */

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
/* GHIDRADEC_FUNCTION index=2018 start=0x406c55c */

int _fc_probe(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  word wVar3;
  int iVar4;
  int iVar5;
  sword sVar6;
  byte bVar7;
  undefined4 *puVar8;
  int *piVar9;
  
  iVar4 = param_2 * 0x262;
  piVar9 = (int *)((int)&_fd_controller + iVar4);
  iVar5 = param_2 * 0x1e;
  param_1 = _slot_id_bmap + param_1;
  *piVar9 = param_1;
  *(undefined4 *)(DAT_40c3770 + iVar4) = (&_fc_bcp)[param_2];
  iVar1 = iVar4 + 0x40c3778;
  *(int *)(DAT_40c3770 + iVar4 + 0xc) = iVar1;
  *(int *)iVar1 = iVar1;
  iVar1 = (int)&unk_40C39C2 + iVar4;
  *(int *)(unk_40C39C6 + iVar4) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(DAT_40c3770 + iVar4 + 0x14) = 0;
  DAT_40c3770[iVar4 + 0x20] = 3;
  iVar1 = *piVar9;
  *(undefined *)(iVar1 + 8) = 0;
  (&byte_40C3791)[iVar4] = *(undefined *)(iVar1 + 8);
  *(undefined4 *)(unk_40C39C6 + iVar4 + 4) = 0;
  *(undefined **)(DAT_40c3792 + iVar4 + 0x214) = _sf_access_head + iVar5;
  *(undefined4 *)(DAT_40c3792 + iVar4 + 0x228) = 4;
  if (piVar9 == &_fd_controller) {
    iVar1 = iVar5 + 0x40c39f2;
    *(int *)(_sf_access_head + iVar5 + 10) = iVar1;
    *(int *)iVar1 = iVar1;
    _sf_access_head[iVar5 + 4] = 0;
    *(undefined4 *)(_sf_access_head + iVar5 + 0xe) = 0;
    *(undefined4 *)(_sf_access_head + iVar5 + 0x12) = 0;
    *(undefined4 *)(_sf_access_head + iVar5 + 0x16) = 0;
    *(undefined4 *)(_sf_access_head + iVar5 + 0x1a) = 0;
    dword_40C3764 = &_disk_eject_q;
    _disk_eject_q = &_disk_eject_q;
    iVar5 = 9;
    puVar8 = &unk_40C375C;
    do {
      do {
        *puVar8 = 0;
        puVar8 = puVar8 + -1;
        wVar3 = (word)((uint)iVar5 >> 0x10);
        sVar6 = (sword)iVar5 + -1;
        iVar5 = CONCAT22(wVar3,sVar6);
      } while (sVar6 != -1);
      iVar5 = (uint)wVar3 * 0x10000 + -1;
    } while (wVar3 != 0);
    _lock_init(&_fd_open_lock,1);
    dword_40C39D8 = &_vol_abort_q;
    _vol_abort_q = &_vol_abort_q;
  }
  _fd_polling_mode = 1;
  iVar5 = sub_406D476(piVar9,60000000);
  if (iVar5 == 0) {
    _fd_polling_mode = 0;
    iVar5 = _probe_rb(param_1);
    if ((iVar5 != 0) && (iVar5 = _probe_rb(param_1 + 1), iVar5 != 0)) {
      pcVar2 = (char *)(param_1 + 2);
      iVar5 = _probe_rb(pcVar2);
      if (((iVar5 != 0) &&
          (((iVar5 = _probe_rb(param_1 + 4), iVar5 != 0 &&
            (iVar5 = _probe_rb(param_1 + 5), iVar5 != 0)) &&
           (iVar5 = _probe_rb(param_1 + 7), iVar5 != 0)))) && (*pcVar2 = '\x04', *pcVar2 == '\x04'))
      {
        bVar7 = 0;
        do {
          *(byte *)(param_1 + 2) = bVar7 | 4;
          if ((bVar7 | 4) != *(byte *)(param_1 + 2)) goto loc_406C70A;
          bVar7 = bVar7 + 1;
        } while (bVar7 < 4);
        _fd_polling_mode = 1;
        iVar5 = _fc_82077_reset(piVar9,0);
        if (iVar5 == 0) {
          _fd_polling_mode = 0;
          *(undefined4 *)(DAT_40c3792 + iVar4 + 0x10) = 0x406d3e2;
          *(int **)(DAT_40c3792 + iVar4 + 0x14) = piVar9;
          *(undefined4 *)(DAT_40c3792 + iVar4 + 0x18) = 1;
          *(undefined4 *)(DAT_40c3792 + iVar4 + 0x2c) = 0;
          *(int *)(DAT_40c3792 + iVar4 + 0x1c) = _slot_id + 0x2000010;
          _dma_init(DAT_40c3792 + iVar4,0x1a63);
          *(uint *)(DAT_40c3770 + iVar4 + 0x14) = *(uint *)(DAT_40c3770 + iVar4 + 0x14) | 0x20000;
          *(int *)(DAT_40c3792 + iVar4 + 0x210) = _slot_id_bmap + 0x2014020;
          _sfa_relinquish(*(undefined4 *)(DAT_40c3792 + iVar4 + 0x214),iVar4 + 0x40c39aa,2);
          if (_fc_thread_timer_started != 0) {
            return param_1;
          }
          _timeout(_fc_thread_timer,0,_hz);
          _fc_thread_timer_started = 1;
          return param_1;
        }
        _fd_polling_mode = 0;
      }
    }
loc_406C70A:
    _sfa_relinquish(*(undefined4 *)(DAT_40c3792 + iVar4 + 0x214),iVar4 + 0x40c39aa,2);
  }
  else {
    _fd_polling_mode = 0;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2019 start=0x406c7be */

void _fc_slave(int param_1)

{
  _fd_slave((int)&_fd_controller + *(sword *)(*(int *)(param_1 + 0x22) + 4) * 0x262,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2020 start=0x406c7e6 */

void _fc_go(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2021 start=0x406c7ee */

void _fc_init(int param_1)

{
  _fd_controller = _slot_id_bmap + param_1;
  byte_40C3791 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2022 start=0x406c80c */

undefined4 _fc_start(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = dword_40C3704;
  if (*(int *)(param_1 + 4) == 0) {
    if ((_fd_polling_mode == 0) && ((*(uint *)(dword_40C3704 + 0x18) & 2) == 0)) {
      _fd_thread_block(dword_40C3704 + 0x18,2,dword_40C3704 + 0x14);
    }
    piVar1 = *(int **)(iVar2 + 0x10);
    if (piVar1 == (int *)(iVar2 + 0xc)) {
      *piVar1 = param_1;
    }
    else {
      *(int *)((int)piVar1 + 0x12a) = param_1;
    }
    *(int **)(param_1 + 0x12e) = piVar1;
    *(int *)(param_1 + 0x12a) = iVar2 + 0xc;
    *(int *)(iVar2 + 0x10) = param_1;
    *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) | 1;
    if (_fd_polling_mode != 0) {
      _fc_thread();
      return *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 0x3e);
    }
    _thread_wakeup_prim(iVar2 + 0x18,0,0);
  }
  else if (*(int *)(param_1 + 0x66) == 2) {
    _fd_intr(param_1);
  }
  else {
    _v2d_map(param_1);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2023 start=0x406c8da */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _fc_thread(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  
  iVar9 = 0;
  piVar7 = &_fd_controller;
  do {
    piVar11 = piVar7;
    if (_fd_polling_mode == 0) {
      if ((piVar11[6] & 2U) == 0) break;
    }
    else if ((piVar11[6] & 1U) != 0) break;
    iVar9 = iVar9 + 1;
    piVar7 = (int *)((int)piVar11 + 0x262);
  } while (iVar9 < 1);
  if (iVar9 == 1) {
                    /* WARNING: Subroutine does not return */
    _panic(aFcThreadNoActi);
  }
  if (_fd_polling_mode == 0) {
    _fc_flags_bset(piVar11,2);
    _thread_wakeup_prim(piVar11 + 6,0,0);
  }
  piVar7 = piVar11 + 3;
  do {
    while( true ) {
      if (piVar7 == (int *)*piVar7) {
        do {
          _fc_flags_bclr(piVar11,1);
          _fd_thread_block(piVar11 + 6,1,piVar11 + 5);
        } while (piVar11 + 3 == (int *)piVar11[3]);
      }
      iVar9 = piVar11[3];
      piVar1 = *(int **)(iVar9 + 0x12a);
      piVar2 = *(int **)(iVar9 + 0x12e);
      if (piVar1 == piVar7) {
        piVar11[4] = (int)piVar2;
      }
      else {
        *(int **)((int)piVar1 + 0x12e) = piVar2;
      }
      if (piVar2 == piVar7) {
        *piVar7 = (int)piVar1;
      }
      else {
        *(int **)((int)piVar2 + 0x12a) = piVar1;
      }
      piVar11[7] = iVar9 + 0x60;
      if (*(int *)(iVar9 + 0x66) == 0x80) {
        puVar5 = (undefined4 *)((int)piVar11 + 0x256);
        puVar3 = (undefined4 *)*puVar5;
        while (puVar6 = puVar3, puVar6 != puVar5) {
          puVar3 = *(undefined4 **)((int)puVar6 + 0x12a);
          if (puVar6[1] == 0) {
            puVar4 = *(undefined4 **)((int)puVar6 + 0x12e);
            if (puVar3 == puVar5) {
              *(undefined4 **)((int)piVar11 + 0x25a) = puVar4;
            }
            else {
              *(undefined4 **)((int)puVar3 + 0x12e) = puVar4;
            }
            if (puVar4 == puVar5) {
              *puVar5 = puVar3;
            }
            else {
              *(undefined4 **)((int)puVar4 + 0x12a) = puVar3;
            }
            if (piVar11 == (int *)(&dword_40C3704)[puVar6[1] * 10]) {
              piVar1 = (int *)piVar11[4];
              if (piVar1 == piVar7) {
                *piVar1 = (int)puVar6;
              }
              else {
                *(undefined4 **)((int)piVar1 + 0x12a) = puVar6;
              }
              *(int **)((int)puVar6 + 0x12e) = piVar1;
              *(int **)((int)puVar6 + 0x12a) = piVar11 + 3;
              piVar11[4] = (int)puVar6;
            }
            else {
              _fc_start(puVar6);
            }
          }
        }
        goto loc_406CD2A;
      }
      if (*(int *)(iVar9 + 0x66) == 0x81) {
        puVar5 = (undefined4 *)((int)piVar11 + 0x256);
        puVar3 = (undefined4 *)*puVar5;
        while (puVar6 = puVar3, puVar6 != puVar5) {
          puVar3 = *(undefined4 **)((int)puVar6 + 0x12a);
          if ((*(byte *)((int)puVar6 + 0x127) & 0x10) != 0) {
            puVar4 = *(undefined4 **)((int)puVar6 + 0x12e);
            if (puVar3 == puVar5) {
              *(undefined4 **)((int)piVar11 + 0x25a) = puVar4;
            }
            else {
              *(undefined4 **)((int)puVar3 + 0x12e) = puVar4;
            }
            if (puVar4 == puVar5) {
              *puVar5 = puVar3;
            }
            else {
              *(undefined4 **)((int)puVar4 + 0x12a) = puVar3;
            }
            *(undefined4 *)((int)puVar6 + 0x9e) = 0x14;
            _fd_intr(puVar6);
          }
        }
        goto loc_406CD2A;
      }
      if (*(int *)(iVar9 + 4) == 0) break;
      _v2d_map(iVar9);
    }
    *(undefined *)(iVar9 + 0xb8) = byte_40C3703;
    *(undefined4 *)(iVar9 + 0x9e) = 0xffffffff;
    *(undefined4 *)(iVar9 + 0xa2) = 0;
    *(undefined4 *)(iVar9 + 0xa6) = 0;
    *(undefined4 *)(iVar9 + 0xaa) = 0;
    _fc_flags_bclr(piVar11,0x140d8);
    iVar8 = sub_406D476(piVar11,60000000);
    if (iVar8 != 0) {
loc_406CB92:
      *(int *)(iVar9 + 0x9e) = iVar8;
      goto loc_406CD0C;
    }
    if ((*(char *)(iVar9 + 0xb8) == '\x01') && ((*(byte *)*piVar11 & 0x40) != 0)) {
      *(undefined4 *)(iVar9 + 0x9e) = 5;
      goto loc_406CD2A;
    }
    uVar10 = (uint)*(sword *)(dword_40C3710 + 0xc);
    if ((-1 < (int)uVar10) && (*(int *)(iVar9 + 0x82) != 0)) {
      _dk_busy = 1 << (uVar10 & 0x3f) | _dk_busy;
      *(int *)(_dk_xfer + uVar10 * 4) = *(int *)(_dk_xfer + uVar10 * 4) + 1;
      *(int *)(_dk_seek + uVar10 * 4) = *(int *)(_dk_seek + uVar10 * 4) + 1;
      *(uint *)(_dk_wds + uVar10 * 4) =
           (*(uint *)(iVar9 + 0x82) >> 6) + *(int *)(_dk_wds + uVar10 * 4);
    }
    if (((piVar11[6] & 0x400U) != 0) && (iVar8 = _fc_82077_reset(piVar11,0), iVar8 != 0))
    goto loc_406CB92;
    if (3 < *(byte *)(iVar9 + 0xb8)) {
      *(undefined4 *)(iVar9 + 0x9e) = 5;
      goto loc_406CCB4;
    }
    iVar8 = *piVar11;
    *(byte *)(iVar8 + 2) =
         *(byte *)(iVar9 + 0xb8) | *(byte *)(iVar8 + 2) & 0xfc | *(byte *)(iVar8 + 2);
    switch(*(undefined4 *)(piVar11[7] + 6)) {
    case :
      _fc_cmd_xfr(piVar11,&_fd_drive);
      break;
    case :
      _DAT_40c371c = _DAT_40c371c | 4;
      _fc_eject(piVar11);
      (&dword_40C3708)[*(int *)(iVar9 + 4) * 10] = 0;
      *(undefined4 *)(iVar9 + 4) = 1;
      _DAT_40c371c = _DAT_40c371c & 0xfffffffb;
      break;
    case :
      _fc_motor_on(piVar11);
      goto loc_406CC4A;
    case :
      _fc_motor_off(piVar11);
loc_406CC4A:
      *(undefined4 *)(piVar11[7] + 0x3e) = 0;
      break;
    case :
      _fc_motor_on(piVar11);
      *(undefined4 *)(iVar9 + 0x9e) = 0;
      break;
    :
      *(undefined4 *)(iVar9 + 0x9e) = 4;
    }
    if ((piVar11[6] & 0x10U) != 0) {
      _fc_stop_timer(piVar11);
    }
    sub_406D0C0(piVar11,piVar11[7]);
    if (((byte)(0x10 << (*(byte *)(piVar11[7] + 0x58) & 0x3f)) & *(byte *)(*piVar11 + 2)) == 0) {
      _DAT_40c371c = _DAT_40c371c & 0xfffffffd;
    }
    else {
      _DAT_40c371c = _DAT_40c371c | 2;
    }
loc_406CCB4:
    _fc_flags_bclr(piVar11,0x80);
    if (*(int *)(iVar9 + 0x9e) == 1) {
      _fc_82077_reset(piVar11,aCommandTimeout);
    }
    if (*(int *)(iVar9 + 0x9e) == 10) {
      _fc_82077_reset(piVar11,aBadControllerP);
    }
    if ((piVar11[6] & 0x400U) != 0) {
      _fc_82077_reset(piVar11,aControllerHang);
    }
loc_406CD0C:
    if ((*(byte *)((int)piVar11 + 0x251) & 1) != 0) {
      _sfa_relinquish(*(undefined4 *)((int)piVar11 + 0x23a),(int)piVar11 + 0x23e,2);
    }
loc_406CD2A:
    _fd_intr(iVar9);
    if (_fd_polling_mode != 0) {
      return;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2024 start=0x406ce78 */

int _fc_82077_reset(int *param_1,int *param_2)

{
  int iVar1;
  int **ppiVar2;
  undefined4 uStack_24;
  int *piStack_20;
  undefined4 uStack_1c;
  int *piStack_18;
  code *pcStack_14;
  int *piStack_10;
  
  iVar1 = *param_1;
  if ((param_2 != (int *)0x0) && (_fd_polling_mode == 0)) {
    piStack_10 = param_2;
    pcStack_14 = (code *)((int)(param_1 + -0x1030ddb) * -0x3fca482f >> 1);
    piStack_18 = (int *)aFcDControllerR;
    uStack_1c = 0x406ceb6;
    _printf();
  }
  *(undefined *)(iVar1 + 2) = 0;
  piStack_10 = (int *)0x32;
  pcStack_14 = (code *)0x406cec8;
  _delay();
  *(undefined *)(iVar1 + 2) = 4;
  *(undefined *)(iVar1 + 4) = 0;
  *(undefined *)(iVar1 + 7) = 0;
  *(undefined *)((int)param_1 + 0x25) = 0x40;
  *(undefined *)(iVar1 + 8) = 0x40;
  *(undefined4 *)((int)param_1 + 0x25e) = 0;
  *(uint *)((int)param_1 + 0x52) = *(uint *)((int)param_1 + 0x52) & 0xffffbfff;
  pcStack_14 = (code *)0x3;
  piStack_18 = param_1;
  uStack_1c = 0x406cefe;
  iVar1 = _fc_configure();
  if (iVar1 == 0) {
    piStack_10 = (int *)_fd_drive_info;
    pcStack_14 = (code *)0x3;
    piStack_18 = param_1;
    uStack_1c = 0x406cf1a;
    iVar1 = _fc_specify();
    if (iVar1 == 0) {
      piStack_10 = param_1;
      pcStack_14 = sub_406CD48;
      piStack_18 = (int *)0x736;
      uStack_1c = 0x406cf36;
      _install_scanned_intr();
      uStack_1c = 0x400;
      piStack_20 = param_1;
      uStack_24 = 0x406cf42;
      _fc_flags_bclr();
      ppiVar2 = (int **)&uStack_24;
      uStack_24 = 0x2000;
      goto loc_406CF70;
    }
  }
  if ((param_1[6] & 0x2000U) != 0) {
    piStack_10 = (int *)0x736;
    pcStack_14 = (code *)0x406cf5c;
    _uninstall_scanned_intr();
    pcStack_14 = (code *)0x2000;
    piStack_18 = param_1;
    uStack_1c = 0x406cf68;
    _fc_flags_bclr();
  }
  ppiVar2 = &piStack_10;
  piStack_10 = (int *)0x400;
loc_406CF70:
  *(int **)((int)ppiVar2 + -4) = param_1;
  *(undefined4 *)((int)ppiVar2 + -8) = 0x406cf78;
  _fc_flags_bset();
  return iVar1;
}

