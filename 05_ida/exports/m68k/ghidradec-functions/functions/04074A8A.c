
int _odprobe(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  int *piVar4;
  
  iVar1 = param_2 * 0x28c;
  piVar4 = (int *)(_od_ctrl + iVar1);
  puVar3 = _bdevsw;
  if (_bdevsw < _bdevsw + _nblkdev * 0x18) {
    do {
      if (*(code **)puVar3 == _odopen) {
        _od_blk_major = (int)((int)puVar3 + -0x40b087c) * -0x55555555 >> 3;
      }
      puVar3 = (undefined *)((int)puVar3 + 0x18);
    } while (puVar3 < _bdevsw + _nblkdev * 0x18);
  }
  iVar2 = _od_blk_major;
  puVar3 = _cdevsw;
  if (_cdevsw < _cdevsw + _nchrdev * 0x2c) {
    do {
      if (*(code **)puVar3 == _odopen) {
        _od_raw_major = (int)((int)puVar3 + -0x40b0ac0) * -0x45d1745d >> 2;
      }
      puVar3 = (undefined *)((int)puVar3 + 0x2c);
    } while (puVar3 < _cdevsw + _nchrdev * 0x2c);
  }
  if ((_machine_type == '\0') || (_machine_type == '\x02')) {
    _bzero(piVar4,0x28c);
    _bzero(&_od_stats,0x28);
    param_1 = _slot_id_bmap + param_1;
    iVar2 = _probe_rb((undefined *)(param_1 + 7));
    if (iVar2 == 0) {
      param_1 = 0;
    }
    else {
      *(int *)(_od_ctrl + iVar1 + 0x210) = param_1;
      (&dword_40C3DA8)[param_2 * 0xa3] = (&dword_40C3DA8)[param_2 * 0xa3] | 0x400000;
      iVar2 = _kmem_alloc_wired(_kernel_map,&_od_readlabel,0x1c48);
      if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aOdProbeAlloc);
      }
      iVar2 = _kalloc(0x410);
      _od_rathole = iVar2 + 0xfU & 0xfffffff0;
      if (*(sword *)((&_odcinfo)[param_2] + 6) == 0) {
        *(undefined2 *)((&_odcinfo)[param_2] + 6) = 3;
      }
      _od_spl = (int)*(sword *)((&_odcinfo)[param_2] + 6) << 8 | 0x2000;
      *(byte *)(param_1 + 4) = _disr_shadow | 0xfc;
      *(undefined *)(param_1 + 5) = 0;
      *(undefined *)(param_1 + 7) = 0;
      (&byte_40C3DF7)[iVar1] = 0xc0;
      if (1 < (*(byte *)(_slot_id + 0x200c003) & 7)) {
        (&byte_40C3DF7)[iVar1] = (&byte_40C3DF7)[iVar1] | 0x10;
      }
      *(undefined *)(param_1 + 0xc) = (&byte_40C3DF7)[iVar1];
      *(char *)(param_1 + 0xd) = (char)_od_frmr;
      *(undefined *)(param_1 + 0xe) = 1;
      iVar2 = 0;
      do {
        *(undefined *)(param_1 + 0x10 + iVar2) = *(undefined *)((int)&_od_flgstr + iVar2);
        iVar2 = iVar2 + 1;
      } while (iVar2 < 7);
      iVar2 = _hz;
      if (_hz < 0) {
        iVar2 = _hz + 1;
      }
      _od_runout_time = (undefined2)(iVar2 >> 1);
      *(code **)(_od_ctrl + iVar1 + 0x10) = _od_dma_intr;
      *(undefined4 *)(_od_ctrl + iVar1 + 0x18) = 1;
      *(int *)(_od_ctrl + iVar1 + 0x1c) = _slot_id + 0x2000050;
      *piVar4 = iVar1 + 0x40c3c80;
      _dma_init(piVar4,0x1964);
      *(undefined **)(DAT_40c3dfc + iVar1) = _sf_access_head + param_2 * 0x1e;
      *(undefined4 *)(DAT_40c3dfc + iVar1 + 0x14) = 0;
      _install_scanned_intr(0xd30,_odintr,piVar4);
      iVar1 = _kmem_alloc_wired(_kernel_map,DAT_40c3dac + iVar1,0x2000);
      if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aOdTestAlloc);
      }
      if (_od_timer_started == 0) {
        _timeout(_od_timer,0,_hz);
        _od_timer_started = 1;
      }
    }
  }
  else {
    iVar1 = _od_blk_major * 0x18;
    *(code **)(_bdevsw + iVar1) = _nodev;
    (&off_40B088C)[iVar2 * 6] = _nodev;
    *(code **)(_bdevsw + iVar1 + 0xc) = _nodev;
    *(code **)(_cdevsw + _od_raw_major * 0x2c) = _nodev;
    param_1 = 0;
  }
  return param_1;
}
