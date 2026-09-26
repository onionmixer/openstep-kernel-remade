/* GHIDRADEC_FUNCTION index=2150 start=0x4074142 */

void _nps_select(sword param_1,undefined4 param_2)

{
  _np_select_common((int)param_1,param_2,1);
  return;
}
/* GHIDRADEC_FUNCTION index=2151 start=0x407415e */

undefined4 _np_select_common(byte param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = (sword)(word)param_1 * 0x14c;
  if (1 < param_1) {
    return 6;
  }
  if (param_2 == 0) {
    if ((*(int *)(DAT_40c3b2a + iVar1 + 0x20) == 6) || (*(int *)(DAT_40c3b2a + iVar1 + 0x20) == 0))
    {
      return 1;
    }
    iVar2 = _selthreadcache(iVar1 + 0x40c3b46);
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = *(uint *)(DAT_40c3b2a + iVar1) | 0x80;
  }
  else {
    if (param_2 != 2) {
      return 0;
    }
    if (param_3 != 0) {
      return 0;
    }
    if (*(int *)(DAT_40c3b2a + iVar1 + 0x20) == 2) {
      return 1;
    }
    iVar2 = _selthreadcache(iVar1 + 0x40c3b42);
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = *(uint *)(DAT_40c3b2a + iVar1) | 0x40;
  }
  *(uint *)(DAT_40c3b2a + iVar1) = uVar3;
  return 0;
}
/* GHIDRADEC_FUNCTION index=2152 start=0x4074204 */

int _np_write(byte param_1,int *param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined *puVar14;
  undefined4 uStack_e;
  int iStack_a;
  undefined uStack_5;
  
  iVar8 = (int)(sword)(word)param_1;
  iVar6 = iVar8 * 0x14c;
  puVar12 = (undefined4 *)(_np_softc + iVar6);
  uVar1 = *puVar12;
  if (1 < param_1) {
    return 6;
  }
  if (param_2[1] == 1) {
    puVar2 = (uint *)*param_2;
    if ((*(uint *)(_np_softc + iVar6 + 0x106) & 1) == 0) {
      return 0x52;
    }
    iVar9 = *(int *)(_np_softc + iVar6 + 0x13e) * 4 * *(int *)(_np_softc + iVar6 + 0x13a);
    uVar4 = puVar2[1];
    if ((iVar9 - uVar4 == 0 || iVar9 < (int)uVar4) &&
       ((uVar3 = *puVar2, uVar3 == (~_page_mask & _page_mask + uVar3) ||
        ((uVar4 + uVar3 & 0xf) == 0)))) {
      while( true ) {
        if ((*(int *)(_np_softc + iVar6 + 0x126) == 0) || (*(int *)(_np_softc + iVar6 + 0x126) == 7)
           ) {
          return 0x50;
        }
        if (*(int *)(_np_softc + iVar6 + 0x126) != 1) break;
        _sleep(iVar6 + 0x40c3b4a,0x28);
      }
      if ((*(uint *)(_np_softc + iVar6 + 0x106) & 0x20) != 0) {
        if ((*(uint *)(_np_softc + iVar6 + 0x106) & 0x10) == 0) {
          uVar13 = 0x4c;
        }
        else {
          uVar13 = 0x4f;
        }
        iVar9 = _np_serial_cmd(puVar12,uVar13,&uStack_5);
        if ((iVar9 != 0) && (iVar9 != 0x51)) {
          return iVar9;
        }
        *(uint *)(_np_softc + iVar6 + 0x106) = *(uint *)(_np_softc + iVar6 + 0x106) & 0xffffffdf;
      }
      uVar13 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
      iVar9 = *(int *)(_kernel_task + 8);
      *(undefined4 *)(_np_softc + iVar6 + 0x144) = 0;
      *(uint *)(_np_softc + iVar6 + 0x148) = ~_page_mask & _page_mask + puVar2[1];
      puVar5 = (uint *)(_np_softc + iVar6 + 0x144);
      iVar7 = _vm_map_find(iVar9,0,0,puVar5,*(undefined4 *)(_np_softc + iVar6 + 0x148),1);
      if (iVar7 != 0) {
        return 0xc;
      }
      _vm_map_reference(uVar13);
      iVar7 = _vm_map_copy(iVar9,uVar13,*puVar5,*(undefined4 *)(_np_softc + iVar6 + 0x148),*puVar2,0
                           ,0);
      if (iVar7 == 0) {
        _vm_map_deallocate(uVar13);
        iVar7 = _vm_map_protect(iVar9,*puVar5,*(int *)(_np_softc + iVar6 + 0x148) + *puVar5,1,0);
        if (iVar7 == 0) {
          iVar7 = _vm_map_pageable(iVar9,~_page_mask & *puVar5,
                                   ~_page_mask &
                                   _page_mask + *(int *)(_np_softc + iVar6 + 0x148) + *puVar5,0);
          if (iVar7 == 0) {
            *(uint *)(_np_softc + iVar6 + 0x100) =
                 (*(int *)(_np_softc + iVar6 + 0x148) + -1 + _page_size) / _page_size + 1;
            _kmem_alloc_wired(_kernel_map,iVar6 + 0x40c3b20,
                              *(int *)(_np_softc + iVar6 + 0x100) * 0x1c);
            *(undefined4 *)(_np_softc + iVar6 + 0x12e) = 3;
loc_40744CE:
            do {
              iVar7 = _np_wait_printer_ready(puVar12);
              if (iVar7 != 0) goto loc_40748EC;
              _dma_list(iVar6 + 0x40c3a28,*(undefined4 *)(_np_softc + iVar6 + 0xfc),
                        *(undefined4 *)(_np_softc + iVar6 + 0x144),
                        *(undefined4 *)(_np_softc + iVar6 + 0x148),*(undefined4 *)(iVar9 + 0x20),0,
                        *(undefined4 *)(_np_softc + iVar6 + 0x100),0,0);
              for (piVar10 = *(int **)(_np_softc + iVar6 + 0xfc); *piVar10 != 0;
                  piVar10 = piVar10 + 7) {
              }
              piVar11 = piVar10;
              if (*(char *)(piVar10[2] + -1) != '\0') {
                piVar11 = piVar10 + 7;
                *piVar10 = (int)piVar11;
                piVar10[4] = 0;
                piVar10[8] = *(int *)(_np_softc + iVar6 + 0x44);
                piVar10[9] = piVar10[8] + 0x10;
                *piVar11 = 0;
                piVar10[0xb] = 0;
              }
              *(int *)(_np_softc + iVar6 + 0x12a) = piVar11[1];
              _np_send(uVar1,0xc2,
                       *(uint *)(_np_softc + iVar6 + 0x132) & 0x1ff |
                       (*(uint *)(_np_softc + iVar6 + 0x13a) & 0x7f) << 0x10);
              if (_np_softc[iVar6 + 0x142] != _np_softc[iVar6 + 0x143]) {
                if (_np_softc[iVar6 + 0x143] == '\0') {
                  _np_setgpout(puVar12,0x40);
                }
                else {
                  _np_cleargpout(puVar12,0x40);
                }
                _np_nap(_hz,puVar12);
                _np_softc[iVar6 + 0x142] = _np_softc[iVar6 + 0x143];
              }
              _np_setgpout(puVar12,0x10);
              _np_setmask(puVar12,4);
              _timeout(_np_serial_timeout,puVar12,_hz * 0x1e);
              _np_softc[iVar6 + 0x104] = _np_softc[iVar6 + 0x104] & 0xfe;
              while (((((_np_softc[iVar6 + 0x11b] & 4) == 0 &&
                       (*(int *)(_np_softc + iVar6 + 0x126) != 1)) &&
                      (*(int *)(_np_softc + iVar6 + 0x126) != 6)) &&
                     ((_np_softc[iVar6 + 0x104] & 1) == 0))) {
                _np_gpinwait(puVar12,_hz * 5);
              }
              _untimeout(_np_serial_timeout,puVar12);
              _np_clearmask(puVar12,4);
              if ((_np_softc[iVar6 + 0x104] & 1) != 0) {
                puVar14 = aNpDVsreqTimeou;
loc_4074862:
                _printf(puVar14,iVar8 * 4 >> 2);
                _lock_write(iVar6 + 0x40c3b36);
                _np_power_off(puVar12);
                _lock_done(iVar6 + 0x40c3b36);
                iVar7 = 5;
                goto loc_40748EC;
              }
              if ((*(int *)(_np_softc + iVar6 + 0x126) == 1) ||
                 (*(int *)(_np_softc + iVar6 + 0x126) == 6)) {
                _np_cleargpout(puVar12,0x10);
                goto loc_40744CE;
              }
              _np_setgpout(puVar12,0x20);
              _np_setstate(puVar12,3);
              uStack_e = 0;
              if (_np_softc[iVar6 + 0x142] == '\0') {
                iStack_a = *(int *)(_np_softc + iVar6 + 0x136) * 0x705;
              }
              else {
                iStack_a = *(int *)(_np_softc + iVar6 + 0x136) * 0x544;
              }
              _us_timeout(_np_startdata,puVar12,&uStack_e,1);
              if (*(int *)(_np_softc + iVar6 + 0x126) == 3) goto loc_4074744;
              iVar7 = *(int *)(_np_softc + iVar6 + 0x126);
              while (iVar7 == 4) {
loc_4074744:
                do {
                  piVar10 = (int *)(_np_softc + iVar6 + 0x126);
                  _sleep(piVar10,0x14);
                } while (*piVar10 == 3);
                iVar7 = *piVar10;
              }
              uVar4 = *(uint *)(_np_softc + iVar6 + 0x126);
              if (uVar4 != 8) {
                if (uVar4 < 9) {
                  if (uVar4 == 1) goto loc_40744CE;
                }
                else if (uVar4 == 9) {
                  iVar7 = _np_setstate_rdyerr(puVar12);
                  if (iVar7 != 0) goto loc_40748EC;
                  _printf(aNpDTimeoutWait,iVar8 * 4 >> 2);
                  goto loc_40744CE;
                }
                iVar7 = _np_setstate_rdyerr(puVar12);
                *(uint *)(_np_softc + iVar6 + 0x106) =
                     *(uint *)(_np_softc + iVar6 + 0x106) & 0xfffffffe;
                goto loc_40748EC;
              }
              *(int *)(_np_softc + iVar6 + 0x12e) = *(int *)(_np_softc + iVar6 + 0x12e) + -1;
              if (*(int *)(_np_softc + iVar6 + 0x12e) == 0) {
                puVar14 = aNpDDmaUnderrun_0;
                goto loc_4074862;
              }
              _printf(aNpDDmaUnderrun,iVar8 * 4 >> 2);
              _np_setmask(puVar12,4);
              while (((_np_softc[iVar6 + 0x11b] & 4) != 0 &&
                     (*(int *)(_np_softc + iVar6 + 0x126) != 1))) {
                _np_gpinwait(puVar12,_hz * 5);
              }
              _np_clearmask(puVar12,4);
              if ((*(int *)(_np_softc + iVar6 + 0x126) == 8) &&
                 (iVar7 = _np_setstate_rdyerr(puVar12), iVar7 != 0)) {
loc_40748EC:
                iVar8 = _vm_map_remove(iVar9,*(undefined4 *)(_np_softc + iVar6 + 0x144),
                                       *(int *)(_np_softc + iVar6 + 0x148) +
                                       *(int *)(_np_softc + iVar6 + 0x144));
                if (iVar8 == 0) {
                  _kmem_free(_kernel_map,*(undefined4 *)(_np_softc + iVar6 + 0xfc),
                             *(int *)(_np_softc + iVar6 + 0x100) * 0x1c);
                  *(undefined4 *)(_np_softc + iVar6 + 0xfc) = 0;
                  *param_2 = *param_2 + 8;
                  param_2[1] = param_2[1] + -1;
                  *puVar2 = puVar2[1] + *puVar2;
                  param_2[2] = puVar2[1] + param_2[2];
                  *(undefined4 *)((int)param_2 + 0x12) = 0;
                  puVar2[1] = 0;
                  return iVar7;
                }
                    /* WARNING: Subroutine does not return */
                _panic(aNpWriteCanTRem);
              }
            } while( true );
          }
          iVar8 = _vm_map_remove(iVar9,*puVar5,*(int *)(_np_softc + iVar6 + 0x148) + *puVar5);
          if (iVar8 != 0) {
                    /* WARNING: Subroutine does not return */
            _panic(aNpWriteVmMapPa);
          }
        }
        else {
          iVar8 = _vm_map_remove(iVar9,*puVar5,*(int *)(_np_softc + iVar6 + 0x148) + *puVar5);
          if (iVar8 != 0) {
                    /* WARNING: Subroutine does not return */
            _panic(aNpWriteVmMapPr);
          }
        }
      }
      else {
        iVar8 = _vm_map_remove(iVar9,*puVar5,*(int *)(_np_softc + iVar6 + 0x148) + *puVar5);
        if (iVar8 != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aNpWriteVmMapCo);
        }
        _vm_map_deallocate(uVar13);
      }
      return 0xe;
    }
  }
  return 0x16;
}
/* GHIDRADEC_FUNCTION index=2153 start=0x4074966 */

int _np_probe(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  _bzero(_np_softc + param_2 * 0x14c,0x14c);
  param_1 = _slot_id + param_1;
  *(int *)(_np_softc + param_2 * 0x14c) = param_1;
  iVar1 = _probe_rb(*(undefined *)(param_1 + 3));
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = param_1;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2154 start=0x40749c2 */

undefined4 _np_attach(int param_1)

{
  int iVar1;
  
  iVar1 = *(sword *)(param_1 + 4) * 0x14c;
  *(byte *)(*(int *)(param_1 + 0x12) + 2) = *(byte *)(*(int *)(param_1 + 0x12) + 2) & 0xfd;
  *(undefined4 *)(_np_softc + iVar1 + 0x126) = 0;
  *(undefined4 *)(_np_softc + iVar1 + 0x106) = 0;
  *(undefined4 *)(_np_softc + iVar1 + 0x122) = 0;
  *(undefined4 *)(_np_softc + iVar1 + 0x11e) = *(undefined4 *)(_np_softc + iVar1 + 0x122);
  _lock_init(iVar1 + 0x40c3b2e,1);
  _lock_init(iVar1 + 0x40c3b36,1);
  *(code **)(_np_softc + iVar1 + 0x14) = _np_dma_intr;
  *(undefined **)(_np_softc + iVar1 + 0x18) = _np_softc + iVar1;
  *(undefined4 *)(_np_softc + iVar1 + 0x1c) = 1;
  *(undefined4 *)(_np_softc + iVar1 + 0x30) = 1;
  *(int *)(_np_softc + iVar1 + 0x20) = _slot_id + 0x2000090;
  _bzero(iVar1 + 0x40c3a6c,0xa0);
  _dma_init(iVar1 + 0x40c3a28,0x1865);
  return 0;
}
/* GHIDRADEC_FUNCTION index=2155 start=0x4074a6c */

void _od_xpr_alert(void)

{
  undefined4 in_stack_00000000;
  
  _od_save_ra = in_stack_00000000;
  _printf();
  return;
}
/* GHIDRADEC_FUNCTION index=2156 start=0x4074a8a */

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
/* GHIDRADEC_FUNCTION index=2157 start=0x4074da2 */

undefined4 _odslave(void)

{
  return 1;
}
/* GHIDRADEC_FUNCTION index=2158 start=0x4074dac */

int _odattach(int param_1)

{
  word wVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  undefined *puVar7;
  
  iVar3 = *(sword *)(param_1 + 6) * 0x28c;
  puVar7 = _od_ctrl + iVar3;
  iVar4 = (int)*(sword *)(param_1 + 4);
  iVar2 = iVar4 * 0x20;
  puVar6 = _od_drive + iVar2;
  iVar3 = *(int *)(_od_ctrl + iVar3 + 0x210);
  wVar1 = (&word_40C3E30)[iVar4 * 0x10];
  if (((wVar1 & 0x800) == 0) && (_od_label == 0)) {
    _od_buf_alloc();
  }
  _bzero(puVar6,0x20);
  *(undefined4 *)(_od_drive + iVar2 + 0x10) = *(undefined4 *)(param_1 + 0x22);
  *(int *)(_od_drive + iVar2 + 0x14) = param_1;
  *(undefined **)(_od_drive + iVar2 + 0xc) = puVar7;
  (&byte_40C3E34)[iVar2] = 0;
  (&DAT_40c3e35)[iVar2] = 0xff;
  (&DAT_40c3e32)[iVar4 * 0x10] = 0xffff;
  _od_status(puVar7,puVar6,iVar3,0x2000,9);
  _od_drive_cmd(puVar7,puVar6,0x5000,9);
  *(undefined *)(iVar3 + 5) = 0xf2;
  if ((wVar1 & 0x800) == 0) {
    uVar5 = _od_status(puVar7,puVar6,iVar3,0x3f00,9);
    if (uVar5 != 0xffffffff) {
      _printf(aDriveRomVDServ,(uVar5 & 0xfff) >> 8,(uVar5 & 0xff) >> 4);
    }
  }
  (&word_40C3E30)[iVar4 * 0x10] = (&word_40C3E30)[iVar4 * 0x10] | 0x200;
  iVar3 = _od_read_label(puVar7,puVar6,wVar1 & 0x800);
  if ((iVar3 != 0) && ((*(byte *)(&word_40C3E30 + iVar4 * 0x10) & 0x40) != 0)) {
    _printf(aSDNoValidDiskL,*(undefined4 *)(**(int **)(_od_drive + iVar2 + 0x14) + 0x20),iVar2 >> 5)
    ;
  }
  (&word_40C3E30)[iVar4 * 0x10] = (&word_40C3E30)[iVar4 * 0x10] & 0xfdff;
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=2159 start=0x4074ee0 */

void _od_timer(void)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  if ((_kernel_task != 0) && (dword_40B4FBE == 0)) {
    _kernel_thread_noblock(_kernel_task,_od_label_alloc);
    _kernel_thread_noblock(_kernel_task,_od_try_attach);
    _kernel_thread_noblock(_kernel_task,_od_request);
    dword_40B4FBE = 1;
  }
  puVar3 = _od_ctrl;
  do {
    if ((*(char *)((int)puVar3 + 0x260) != '\0') &&
       (*(char *)((int)puVar3 + 0x260) = *(char *)((int)puVar3 + 0x260) + -1,
       *(char *)((int)puVar3 + 0x260) == '\0')) {
      *(uint *)((int)puVar3 + 0x220) = *(uint *)((int)puVar3 + 0x220) | 0x200000;
      _odintr(puVar3);
    }
    puVar3 = (undefined *)((int)puVar3 + 0x28c);
  } while (puVar3 < &_od_dbug);
  puVar4 = _od_drive;
  puVar3 = unk_40C3E36;
  do {
    if ((((*(word *)((int)puVar4 + 0x18) & 0x6000) == 0x6000) && (cVar1 = *puVar3, -1 < cVar1)) &&
       (*puVar3 = *puVar3 + '\x01', '\n' < cVar1)) {
      *puVar3 = -1;
      _kernel_thread_noblock(_kernel_task,_od_spiral);
    }
    puVar3 = puVar3 + 0x20;
    puVar4 = (undefined *)((int)puVar4 + 0x20);
  } while (puVar4 < &_od_empty);
  if ((0 < _od_update_time) &&
     (bVar2 = 0x1e < _od_update_time, _od_update_time = _od_update_time + 1, bVar2)) {
    _od_update_time = -1;
    _kernel_thread_noblock(_kernel_task,_od_update_thread);
  }
  _timeout(_od_timer,0,_hz);
  return;
}
/* GHIDRADEC_FUNCTION index=2160 start=0x407502c */

undefined4 _odopen(word param_1,uint param_2)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  word wVar7;
  undefined4 uVar6;
  
  uVar3 = (param_1 & 0xff) >> 3;
  uVar2 = param_1 & 7;
  iVar4 = uVar3 * 0xda;
  if (uVar3 == 0x1f) {
loc_40751CC:
    uVar6 = 0;
  }
  else {
    if ((uVar3 < 0x20) && ((dword_40C3DA8 & 0x400000) != 0)) {
      if ((unk_40C3FA0[iVar4 + 1] & 0x20) != 0) {
        do {
          *(word *)(unk_40C3FA0 + iVar4) = *(word *)(unk_40C3FA0 + iVar4) | 0x10;
          _sleep(unk_40C3FA0 + iVar4,0x14);
        } while ((unk_40C3FA0[iVar4 + 1] & 0x20) != 0);
      }
      if (*(sword *)(unk_40C3FA0 + iVar4) < 0) {
loc_4075126:
        if (((param_2 & 4) != 0) && ((unk_40C3FA0[iVar4] & 0x20) == 0)) {
          return 0x23;
        }
        pcVar1 = *(code **)(_cdevsw + (uint)(param_1 >> 8) * 0x2c);
        iVar5 = 0x100;
        if (pcVar1 == _odopen) {
          iVar5 = 1;
        }
        *(word *)(DAT_40c3f76 + iVar4 + 0x22) =
             *(word *)(DAT_40c3f76 + iVar4 + 0x22) | (word)(iVar5 << uVar2);
        *(undefined2 *)(DAT_40c3f76 + iVar4 + 0x20) =
             *(undefined2 *)(*(int *)(_active_u + 0x1a) + 6);
        if ((0 < *(int *)(*(int *)(DAT_40c3f76 + iVar4) + uVar2 * 0x2e + 0xc2)) ||
           (*(code **)(_cdevsw + (uint)(param_1 >> 8) * 0x2c) == _odopen)) goto loc_40751CC;
        if (pcVar1 != _odopen) {
          wVar7 = ~(word)(0x100 << uVar2);
        }
        else {
          wVar7 = (word)(-2 << uVar2) | (word)(0xfffffffe >> 0x20 - uVar2);
        }
        *(word *)(DAT_40c3f76 + iVar4 + 0x22) = *(word *)(DAT_40c3f76 + iVar4 + 0x22) & wVar7;
      }
      else {
        if ((param_2 & 4) != 0) {
          return 0x23;
        }
        _od_empty = uVar3 + 1;
        iVar5 = _od_make_empty();
        if (-1 < iVar5) {
          if ((_od_requested == 0) && (_od_spinup == 0)) {
            _od_requested = 1;
            _wakeup(&_od_requested);
          }
          while (0 < _od_empty) {
            _sleep(&_od_empty,0x14);
          }
          if (-1 < _od_empty) goto loc_4075126;
        }
      }
    }
    uVar6 = 6;
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=2161 start=0x40751fc */

uint _odclose(word param_1)

{
  word wVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 extraout_D0u;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  char cVar10;
  bool bVar11;
  
  uVar2 = (param_1 & 0xff) >> 3;
  uVar5 = param_1 & 7;
  uVar4 = uVar2 * 0xda;
  uVar6 = uVar4;
  if (uVar2 != 0x1f) {
    if (*(code **)(_cdevsw + (uint)(param_1 >> 8) * 0x2c) == _odopen) {
      uVar5 = -2 << uVar5 | 0xfffffffeU >> 0x20 - uVar5;
    }
    else {
      uVar5 = ~(0x100 << uVar5);
    }
    wVar1 = *(word *)(DAT_40c3f76 + uVar4 + 0x22) & (word)uVar5;
    uVar6 = CONCAT22((sword)(uVar5 >> 0x10),wVar1);
    *(word *)(DAT_40c3f76 + uVar4 + 0x22) = wVar1;
    if (wVar1 == 0) {
      if (((_rootdev & 0xff) >> 3 != uVar2) ||
         (uVar6 = (uint)(_rootdev >> 8), uVar6 != _od_blk_major)) {
        wVar1 = *(word *)(unk_40C3FA0 + uVar4) & 0x2800;
        uVar3 = 0;
        cVar10 = wVar1 < 0x2000;
        bVar9 = SBORROW2(wVar1,0x2000);
        bVar7 = (sword)(wVar1 + 0xe000) < 0;
        bVar8 = wVar1 == 0x2000;
        bVar11 = (bool)cVar10;
        if (!bVar8) {
          if ((*(word *)(unk_40C3FA0 + uVar4) & 0x800) != 0) {
            do {
              _sleep(unk_40C3FA0 + uVar4,0x14);
            } while ((unk_40C3FA0[uVar4] & 8) != 0);
          }
          if (*(int *)(DAT_40c3f76 + uVar4) != 0) {
            _kmem_free(_kernel_map,*(int *)(DAT_40c3f76 + uVar4),0x1c48);
            *(undefined4 *)(DAT_40c3f76 + uVar4) = 0;
          }
          if (*(int *)(DAT_40c3f76 + uVar4 + 4) != 0) {
            _kmem_free(_kernel_map,*(int *)(DAT_40c3f76 + uVar4 + 4),0x3000);
            *(undefined4 *)(DAT_40c3f76 + uVar4 + 4) = 0;
          }
          uVar3 = 0;
          if (*(int *)(DAT_40c3f76 + uVar4 + 0x18) != 0) {
            _kmem_free(_kernel_map,*(int *)(DAT_40c3f76 + uVar4 + 0x18),0x10000);
            *(undefined4 *)(DAT_40c3f76 + uVar4 + 0x18) = 0;
            uVar3 = extraout_D0u;
          }
          *(undefined2 *)(unk_40C3FA0 + uVar4) = 0;
          bVar7 = false;
          bVar8 = true;
          bVar9 = false;
          bVar11 = false;
        }
        uVar6 = CONCAT22(uVar3,(word)(byte)(cVar10 << 4 | bVar7 << 3 | bVar8 << 2 | bVar9 << 1 |
                                           bVar11));
      }
    }
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=2162 start=0x4075334 */

undefined4 _odread(word param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (param_1 & 0xff) >> 3;
  if (uVar1 < 0x1f) {
    uVar2 = _physio(_odstrategy,DAT_40c3eee + uVar1 * 0xda,(int)(sword)param_1,1,_odminphys,param_2,
                    0x400);
  }
  else {
    uVar2 = 6;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2163 start=0x4075386 */

undefined4 _odwrite(word param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (param_1 & 0xff) >> 3;
  if (uVar1 < 0x1f) {
    uVar2 = _physio(_odstrategy,DAT_40c3eee + uVar1 * 0xda,(int)(sword)param_1,0,_odminphys,param_2,
                    0x400);
  }
  else {
    uVar2 = 6;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2164 start=0x40753d6 */

uint _odstrategy(uint *param_1)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  word wVar4;
  uint *puVar5;
  uint uVar6;
  bool bVar7;
  uint uVar8;
  uint uVar9;
  undefined *puVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  byte bVar15;
  
  uVar6 = *(uint *)((int)param_1 + 0x1f) >> 0x1b;
  bVar7 = false;
  uVar8 = uVar6 * 0xda;
  puVar10 = _od_vol + uVar8;
  uVar9 = uVar8;
  if (uVar6 < 0x1f) {
    wVar4 = *(word *)(unk_40C3FA0 + uVar8);
    uVar9 = (uint)wVar4;
    if (wVar4 == 0) goto loc_4075462;
    if (((*param_1 & 1) == 0) && ((wVar4 & 4) != 0)) {
      *(undefined2 *)(param_1 + 7) = 0x1e;
    }
    else {
      iVar3 = *(int *)(_od_vol + uVar8 + 0xae);
      piVar1 = (int *)(iVar3 + (sword)(*(word *)((int)param_1 + 0x1e) & 7) * 0x2e + 0xbe);
      uVar6 = param_1[9];
      param_1[0xe] = uVar6;
      uVar9 = (int)param_1[5] % *(int *)(iVar3 + 0x5c);
      if (uVar9 == 0) {
        if ((uint *)(_od_vol + uVar8 + 0x6a) != param_1) {
          if ((unk_40C3FA0[uVar8] & 0x40) == 0) goto loc_4075462;
          uVar9 = piVar1[1];
          if (((uVar9 == 0) || ((int)uVar6 < 0)) || ((int)uVar9 < (int)uVar6)) goto loc_407547A;
          if (uVar9 == uVar6) {
            param_1[10] = param_1[5];
            goto loc_40755B2;
          }
          param_1[0xe] = *piVar1 + uVar6;
          if (_od_idle_time == 0) {
            _od_idle_time = 1;
          }
          if (0 < _od_idle_time) {
            _od_idle_time = 1;
          }
          if (_od_idle_time == -1) {
            _od_idle_time = -3;
          }
        }
        param_1[0xe] = (int)param_1[0xe] / *(int *)(iVar3 + 100);
        while (((*(word *)(unk_40C3FA0 + uVar8) & 0x400) != 0 && ((int)param_1[0xf] < 2))) {
          *(word *)(unk_40C3FA0 + uVar8) = *(word *)(unk_40C3FA0 + uVar8) | 0x200;
          _sleep(puVar10,0x14);
        }
        cVar14 = _od_vol + uVar8 + 0x6a < param_1;
        if ((uint *)(_od_vol + uVar8 + 0x6a) == param_1) {
          if (((unk_40C3FA0[uVar8 + 1] & 0x40) == 0) ||
             (cVar14 = *(word *)(_od_vol + uVar8 + 0xd4) < 0xf1,
             *(word *)(_od_vol + uVar8 + 0xd4) == 0xf1)) {
            cVar14 = _od_vol + uVar8 + 0x6a < param_1;
            if ((uint *)(_od_vol + uVar8 + 0x6a) == param_1) {
              wVar4 = *(word *)(_od_vol + uVar8 + 0xd4);
              cVar14 = wVar4 < 0xf6;
              if ((wVar4 == 0xf6) || (cVar14 = wVar4 < 0xf1, wVar4 == 0xf1)) {
                _disksort_enter_tail(puVar10,param_1);
                goto loc_4075564;
              }
            }
            goto loc_407555A;
          }
          _disksort_enter_head(puVar10,param_1);
          bVar7 = true;
        }
        else {
loc_407555A:
          _disksort_enter(puVar10,param_1);
        }
loc_4075564:
        if ((_od_vol[uVar8 + 0xc] & 0x60) != 0) {
          cVar13 = '\0';
          cVar11 = '\0';
          cVar12 = '\x01';
          bVar15 = 0;
          if (!bVar7) goto loc_40755A8;
        }
        _od_drive_start(puVar10);
        iVar3 = *(int *)(&DAT_40c3e28 + (uint)*(word *)(_od_vol + uVar8 + 0xd2) * 4);
        puVar5 = (uint *)(iVar3 + 0x18);
        puVar2 = (uint *)*puVar5;
        cVar14 = puVar5 < puVar2;
        cVar13 = SBORROW4((int)puVar5,(int)puVar2);
        cVar11 = (int)puVar5 - (int)puVar2 < 0;
        cVar12 = puVar5 == puVar2;
        bVar15 = cVar14;
        if (!(bool)cVar12) {
          cVar13 = '\0';
          bVar15 = 0;
          cVar11 = *(int *)(iVar3 + 0x20) < 0;
          cVar12 = '\0';
          if (*(int *)(iVar3 + 0x20) == 0) {
            cVar11 = iVar3 < 0;
            cVar12 = iVar3 == 0;
            cVar13 = '\0';
            bVar15 = 0;
            _od_ctrl_start(iVar3);
          }
        }
loc_40755A8:
        return (uint)(byte)(cVar14 << 4 | cVar11 << 3 | cVar12 << 2 | cVar13 << 1 | bVar15);
      }
loc_407547A:
      *(undefined2 *)(param_1 + 7) = 0x16;
    }
  }
  else {
loc_4075462:
    *(undefined2 *)(param_1 + 7) = 6;
  }
  *param_1 = *param_1 | 4;
loc_40755B2:
  if ((*param_1 & 2) == 0) {
    uVar9 = _biodone(param_1);
  }
  return uVar9;
}
/* GHIDRADEC_FUNCTION index=2165 start=0x40755cc */

void _od_drive_start(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = _disksort_first(param_1);
  if (iVar2 != 0) {
    if ((*(word *)(param_1 + 0x36) & 0x2000) == 0) {
      *(word *)(param_1 + 0x36) = *(word *)(param_1 + 0x36) | 0x40;
    }
    if ((*(byte *)(param_1 + 3) & 0x60) == 0) {
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xbf | 0x20;
    }
    if ((*(byte *)(param_1 + 3) & 0x60) != 0x40) {
      iVar2 = *(int *)(&DAT_40c3e28 + (uint)*(word *)((int)param_1 + 0xd2) * 4);
      puVar1 = *(undefined4 **)(iVar2 + 0x1c);
      *puVar1 = param_1;
      param_1[1] = (int)puVar1;
      *param_1 = iVar2 + 0x18;
      *(int **)(iVar2 + 0x1c) = param_1;
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xdf | 0x40;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2166 start=0x4075660 */

byte _od_run_out(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = (_od_spl & 0x10) != 0;
  _od_runout = 2;
  cVar2 = param_1 < 0;
  cVar3 = param_1 == 0;
  cVar4 = '\0';
  bVar5 = 0;
  _od_ctrl_start(param_1);
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=2167 start=0x4075692 */

void _od_ctrl_start(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  int *piVar8;
  
  iVar5 = *(sword *)(param_1 + 4) * 0x28c;
  piVar8 = (int *)0x0;
  if (*(int *)(param_1 + 0x20) == 0) {
    while( true ) {
      piVar2 = *(int **)(param_1 + 0x18);
      piVar4 = (int *)(param_1 + 0x18);
      if (piVar2 == piVar4) break;
      puVar6 = (undefined *)_disksort_first(piVar2);
      if (puVar6 == (undefined *)0x0) {
        piVar1 = (int *)*piVar2;
        piVar2 = (int *)piVar2[1];
        if (piVar1 == piVar4) {
          *(int **)(param_1 + 0x1c) = piVar2;
        }
        else {
          piVar1[1] = (int)piVar2;
        }
        *piVar2 = (int)piVar1;
      }
      else {
        *(byte *)(piVar2 + 3) = *(byte *)(piVar2 + 3) | 0x10;
        iVar7 = (sword)(word)((uint)*(undefined4 *)(puVar6 + 0x1f) >> 0x1b) * 0xda;
        if (piVar2 == piVar8) {
          if (_od_runout == 0) {
            _timeout(_od_run_out,param_1,(int)_od_runout_time);
            _od_runout = 1;
            return;
          }
          if (_od_runout == 1) {
            return;
          }
          _od_runout = 0;
          if (_hz * 0x14 == (int)_od_runout_time) {
            iVar5 = _hz;
            if (_hz < 0) {
              iVar5 = _hz + 1;
            }
            _od_runout_time = (sword)(iVar5 >> 1);
          }
          if (_od_requested != 0) {
            _od_runout = 0;
            return;
          }
          if (_od_spinup != 0) {
            _od_runout = 0;
            return;
          }
          _od_requested = 1;
          _wakeup(&_od_requested);
          return;
        }
        if (((DAT_40c3f32 + iVar7 == puVar6) &&
            ((*(sword *)(DAT_40c3f32 + iVar7 + 0x6a) == 0xf1 ||
             (*(sword *)(DAT_40c3f32 + iVar7 + 0x6a) == 0xf6)))) ||
           ((DAT_40c3fa1[iVar7] & 0x40) == 0)) {
          if (_od_runout != 0) {
            if (DAT_40c3f32 + iVar7 == puVar6) {
              iVar7 = _hz;
              if (_hz < 0) {
                iVar7 = _hz + 1;
              }
              if (iVar7 >> 1 != (int)_od_runout_time) goto loc_4075854;
            }
            if (_hz * 0x14 == (int)_od_runout_time) {
              iVar7 = _hz;
              if (_hz < 0) {
                iVar7 = _hz + 1;
              }
              _od_runout_time = (sword)(iVar7 >> 1);
            }
            if (_od_runout == 1) {
              _untimeout(_od_run_out,param_1);
            }
            _od_runout = 0;
          }
loc_4075854:
          *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
          *(code **)(DAT_40c3dfc + iVar5 + 4) = _od_go;
          *(int *)(DAT_40c3dfc + iVar5 + 8) = param_1;
          _sfa_arbitrate(*(undefined4 *)(DAT_40c3dfc + iVar5),iVar5 + 0x40c3e00);
          return;
        }
        piVar1 = (int *)*piVar2;
        puVar3 = (undefined4 *)piVar2[1];
        if (piVar1 == piVar4) {
          *(undefined4 **)(param_1 + 0x1c) = puVar3;
        }
        else {
          piVar1[1] = (int)puVar3;
        }
        *puVar3 = piVar1;
        puVar3 = *(undefined4 **)(param_1 + 0x1c);
        *puVar3 = piVar2;
        piVar2[1] = (int)puVar3;
        *piVar2 = param_1 + 0x18;
        *(int **)(param_1 + 0x1c) = piVar2;
        if (piVar8 == (int *)0x0) {
          piVar8 = piVar2;
        }
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2168 start=0x407587e */

void _od_go(int param_1)

{
  sword sVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  piVar2 = (int *)(param_1 + 0x18);
  if (piVar2 == (int *)*piVar2) {
                    /* WARNING: Subroutine does not return */
    _panic(aOdQueueEmpty);
  }
  iVar4 = _disksort_first(*piVar2);
  if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aOdQueueEmpty);
  }
  sVar1 = *(sword *)(param_1 + 4);
  iVar3 = (uint)*(word *)((int)&DAT_40c3f9a +
                         (sword)(word)((uint)*(undefined4 *)(iVar4 + 0x1f) >> 0x1b) * 0xda) * 0x20;
  uVar5 = (uint)*(sword *)(*(int *)(_od_drive + iVar3 + 0x14) + 0xc);
  if (-1 < (int)uVar5) {
    _dk_busy = 1 << (uVar5 & 0x3f) | _dk_busy;
    *(int *)(_dk_xfer + uVar5 * 4) = *(int *)(_dk_xfer + uVar5 * 4) + 1;
    *(int *)(_dk_wds + uVar5 * 4) = (*(int *)(iVar4 + 0x14) >> 6) + *(int *)(_dk_wds + uVar5 * 4);
  }
  _od_setup(_od_ctrl + sVar1 * 0x28c,_od_drive + iVar3,iVar4);
  return;
}
/* GHIDRADEC_FUNCTION index=2169 start=0x4075938 */

void _od_setup(int param_1,int param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined2 uVar6;
  int iVar7;
  
  iVar1 = *(int *)(param_2 + 8);
  if ((uint *)(iVar1 + 0x6a) == param_3) {
    if (((*(byte *)(param_2 + 0x18) & 0x40) != 0) || (*(sword *)(iVar1 + 0xd4) == 0xf0))
    goto loc_4075986;
    *(undefined2 *)(iVar1 + 0x86) = 6;
  }
  else {
    if (*(sword *)(param_2 + 0x18) < 0) {
loc_4075986:
      iVar2 = *(int *)(iVar1 + 0xae);
      piVar3 = (int *)((sword)(*(word *)((int)param_3 + 0x1e) & 7) * 0x2e + 0xbe + iVar2);
      *(uint *)(param_1 + 0x230) = param_3[9];
      *(uint *)(param_1 + 0x214) = param_3[8];
      if ((*param_3 & 0x4000010) == 0x10) {
        uVar4 = *(undefined4 *)(*(int *)(*(int *)(param_3[0xb] + 0x66) + 8) + 0x20);
      }
      else {
        uVar4 = _pmap_kernel();
      }
      *(undefined4 *)(param_1 + 0x218) = uVar4;
      iVar7 = (int)(*(int *)(iVar2 + 0x5c) + (param_3[5] - 1)) / *(int *)(iVar2 + 0x5c);
      if ((uint *)(iVar1 + 0x6a) == param_3) {
        *(undefined2 *)(param_1 + 0x248) = *(undefined2 *)(iVar1 + 0xd4);
        *(int *)(param_1 + 0x23c) = iVar7;
        uVar5 = *(uint *)(param_1 + 0x220) | 0x80000;
      }
      else {
        *(int *)(param_1 + 0x230) = *piVar3 + *(int *)(param_1 + 0x230);
        uVar6 = 1;
        if ((*param_3 & 1) != 0) {
          uVar6 = 2;
        }
        *(undefined2 *)(param_1 + 0x248) = uVar6;
        iVar1 = piVar3[1] - param_3[9];
        if (iVar1 < iVar7) {
          iVar7 = iVar1;
        }
        *(int *)(param_1 + 0x23c) = iVar7;
        uVar5 = *(uint *)(param_1 + 0x220) & 0xfff7ffff;
      }
      *(uint *)(param_1 + 0x220) = uVar5;
      param_3[10] = param_3[5] - *(int *)(iVar2 + 0x5c) * *(int *)(param_1 + 0x23c);
      *(undefined *)(param_1 + 0x25f) = 0;
      *(undefined *)(param_1 + 0x25e) = *(undefined *)(param_1 + 0x25f);
      *(undefined *)(param_1 + 0x266) = 0;
      *(undefined *)(param_1 + 0x265) = *(undefined *)(param_1 + 0x266);
      *(undefined *)(*(int *)(param_1 + 0x210) + 0xc) = *(undefined *)(param_1 + 0x26f);
      *(undefined *)(param_1 + 0x271) = 0;
      _od_fsm(param_1,param_2,1);
      _microboot(param_2);
      return;
    }
    *(undefined2 *)(param_3 + 7) = 6;
  }
  *param_3 = *param_3 | 4;
  sub_4075AC0((&_odcinfo)[(param_1 + -0x40c3b88) * 0x451ab30b >> 2]);
  return;
}
/* GHIDRADEC_FUNCTION index=2170 start=0x4075ad2 */

undefined4 _od_done(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint *puVar5;
  int *piVar6;
  undefined2 extraout_D0u;
  undefined2 extraout_D0u_00;
  undefined2 uVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  byte bVar16;
  
  piVar6 = (int *)(param_1 + 0x18);
  if (piVar6 == (int *)*piVar6) {
                    /* WARNING: Subroutine does not return */
    _panic(aOdEmptyQ);
  }
  puVar2 = (undefined4 *)*piVar6;
  puVar8 = (uint *)_disksort_first(puVar2);
  iVar9 = *(sword *)(param_1 + 4) * 0x28c;
  iVar10 = (sword)(word)((uint)*(undefined4 *)((int)puVar8 + 0x1f) >> 0x1b) * 0xda;
  if (-1 < *(sword *)((&DAT_40c3e2c)[(uint)*(word *)(_od_vol + iVar10 + 0xd2) * 8] + 0xc)) {
    uVar1 = (int)*(sword *)((&DAT_40c3e2c)[(uint)*(word *)(_od_vol + iVar10 + 0xd2) * 8] + 0xc) &
            0x3f;
    _dk_busy = (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & _dk_busy;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  _disksort_remove(puVar2,puVar8);
  iVar11 = _disksort_first(puVar2);
  if (iVar11 == 0) {
    piVar3 = (int *)*puVar2;
    puVar4 = (undefined4 *)puVar2[1];
    if (piVar3 == piVar6) {
      *(undefined4 **)(param_1 + 0x1c) = puVar4;
    }
    else {
      piVar3[1] = (int)puVar4;
    }
    *puVar4 = piVar3;
    *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) & 0x9f;
  }
  _sfa_relinquish(*(undefined4 *)(DAT_40c3dfc + iVar9),iVar9 + 0x40c3e00,0);
  if (((DAT_40c3fa1[iVar10] & 8) == 0) && ((*puVar8 & 2) == 0)) {
    if (((*puVar8 & 4) != 0) && ((uint *)(_od_vol + iVar10 + 0x6a) != puVar8)) {
      *(undefined2 *)(puVar8 + 7) = 5;
    }
    _biodone(puVar8);
  }
  iVar9 = _disksort_first(puVar2);
  uVar7 = 0;
  if (iVar9 != 0) {
    _od_drive_start(_od_vol + iVar10);
    uVar7 = extraout_D0u;
  }
  puVar5 = (uint *)(param_1 + 0x18);
  puVar8 = (uint *)*puVar5;
  cVar15 = puVar5 < puVar8;
  cVar14 = SBORROW4((int)puVar5,(int)puVar8);
  cVar12 = (int)puVar5 - (int)puVar8 < 0;
  cVar13 = puVar5 == puVar8;
  bVar16 = cVar15;
  if (!(bool)cVar13) {
    cVar14 = '\0';
    bVar16 = 0;
    cVar12 = *(int *)(param_1 + 0x20) < 0;
    cVar13 = '\0';
    if (*(int *)(param_1 + 0x20) == 0) {
      cVar12 = param_1 < 0;
      cVar13 = param_1 == 0;
      cVar14 = '\0';
      bVar16 = 0;
      _od_ctrl_start(param_1);
      uVar7 = extraout_D0u_00;
    }
  }
  return CONCAT22(uVar7,(word)(byte)(cVar15 << 4 | cVar12 << 3 | cVar13 << 2 | cVar14 << 1 | bVar16)
                 );
}
/* GHIDRADEC_FUNCTION index=2171 start=0x4075c32 */

int _od_fsm(int param_1,int param_2,undefined4 param_3)

{
  undefined *puVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  bool bVar5;
  char cVar9;
  undefined4 uVar6;
  uint *puVar7;
  byte bVar10;
  int iVar8;
  word wVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  sword sVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  char *pcVar22;
  undefined uStack_1d;
  int iStack_1c;
  
  puVar1 = *(undefined **)(param_2 + 8);
  iVar4 = (&_odcinfo)[(param_1 + -0x40c3b88) * 0x451ab30b >> 2];
  piVar2 = *(int **)(puVar1 + 0xae);
  puVar3 = *(undefined **)(param_1 + 0x210);
  bVar5 = false;
  iVar8 = piVar2[0x19];
  iVar20 = (int)*(sword *)((int)piVar2 + 0x76) - (int)*(sword *)(piVar2 + 0x1e);
  *(char *)(param_1 + 0x267) = (char)param_3;
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0x9fffffff;
  if (-1 < *(char *)(param_2 + 0x1e)) {
    *(undefined *)(param_2 + 0x1e) = 0;
  }
  if (*piVar2 == 0x4e655854) {
    iVar17 = piVar2[0x19] >> 1;
  }
  else {
    iVar17 = 1;
  }
  iVar18 = (int)*(sword *)(piVar2 + 0x1e) / iVar17;
  switch(param_3) {
  case :
    *(undefined *)(param_1 + 0x269) = 1;
    iVar12 = *(int *)(*(int *)(puVar1 + 0xb6) + 0x2c) / *(int *)(*(int *)(puVar1 + 0xb6) + 0x28);
    if (*(int *)(param_1 + 0x23c) <= iVar12) {
      iVar12 = *(int *)(param_1 + 0x23c);
    }
    *(int *)(param_1 + 0x244) = iVar12;
    if ((*piVar2 != 0x4e655854) &&
       ((((*(char *)(param_1 + 0x25e) != '\0' || (*(char *)(param_1 + 0x25f) != '\0')) &&
         ((*(char *)(param_1 + 0x25e) != '\x01' || (*(char *)(param_1 + 599) != '\x04')))) ||
        ((*(uint *)(param_1 + 0x220) & 0x800) != 0)))) {
      *(undefined4 *)(param_1 + 0x244) = 1;
    }
    if ((*(uint *)(param_1 + 0x220) & 0xc0000) == 0) {
      iVar16 = *(int *)(param_1 + 0x230) % iVar20;
      iVar12 = (int)*(sword *)((int)piVar2 + 0x7a);
      if ((iVar16 < iVar12) || (iVar16 = *(sword *)(piVar2 + 0x1e) + iVar16, iVar16 < iVar12)) {
        iVar21 = -iVar16;
      }
      else {
        iVar21 = *(sword *)((int)piVar2 + 0x76) - iVar16;
      }
      iVar12 = iVar12 + iVar21;
      if (*(int *)(param_1 + 0x244) < iVar12) {
        iVar12 = *(int *)(param_1 + 0x244);
      }
      *(int *)(param_1 + 0x244) = iVar12;
      *(int *)(param_1 + 0x238) =
           (int)*(sword *)(piVar2 + 0x1c) +
           iVar16 + (int)*(sword *)((int)piVar2 + 0x76) * (*(int *)(param_1 + 0x230) / iVar20);
    }
    else {
      *(undefined4 *)(param_1 + 0x238) = *(undefined4 *)(param_1 + 0x230);
    }
    do {
      *(int *)(param_1 + 0x238) = *(int *)(puVar1 + 0xbe) + *(int *)(param_1 + 0x238);
      *(char *)(param_1 + 0x264) = (char)(*(int *)(param_1 + 0x238) % piVar2[0x19]);
      iVar20 = (int)*(char *)(param_1 + 0x264) % iVar17;
      *(sword *)(param_1 + 0x22c) = (sword)(*(int *)(param_1 + 0x238) / piVar2[0x19]);
      if (*piVar2 == 0x4e655854) {
        uVar14 = ((int)*(sword *)(param_1 + 0x22c) - *(int *)(puVar1 + 0xbe) / piVar2[0x19]) * 2;
        if (iVar8 >> 1 <= (int)*(char *)(param_1 + 0x264)) {
          uVar14 = uVar14 | 1;
        }
      }
      else {
        uVar14 = *(int *)(param_1 + 0x238) - *(int *)(puVar1 + 0xbe);
      }
      iVar12 = uVar14 + (iVar17 + *(int *)(param_1 + 0x244) + -1 + iVar20) / iVar17;
      *(char *)(param_1 + 0x25c) = (char)*(undefined2 *)(param_1 + 0x248);
      if (((*(uint *)(param_1 + 0x220) & 0x40000) != 0) ||
         (((*(uint *)(param_1 + 0x220) & 0x80000) != 0 && ((char)puVar1[0xd9] < '\0')))) {
        bVar5 = true;
        if (((*(char *)(param_1 + 0x25c) != '\x01') && (*(char *)(param_1 + 0x25c) != '\x04')) ||
           (((*(uint *)(param_1 + 0x220) & 0x40000) != 0 || (iVar12 <= (int)uVar14))))
        goto loc_4076424;
        goto loc_4075EE6;
      }
      bVar5 = false;
      iVar16 = 0;
      if (iVar12 <= (int)uVar14) goto loc_4076424;
      iStack_1c = 0;
      while( true ) {
        *(sword *)(param_1 + 0x250) = (sword)((int)uVar14 >> 4);
        *(byte *)(param_1 + 0x252) = ((byte)uVar14 & 0xf) << 1;
        iVar21 = *(int *)(puVar1 + 0xc6);
        uVar13 = *(int *)(iVar21 + *(sword *)(param_1 + 0x250) * 4) >>
                 ((int)*(char *)(param_1 + 0x252) & 0x3fU) & 3;
        if (uVar13 == 1) break;
        if (uVar13 < 2) {
          if (uVar13 != 0) goto loc_4076414;
          if ((iVar16 != 0) && ((*piVar2 == 0x4e655854 || (*(sword *)(param_1 + 0x248) == 2))))
          goto loc_407609A;
          if (*(sword *)(param_1 + 0x248) != 2) {
            if ((*piVar2 != 0x4e655854) && (*(sword *)(param_1 + 0x248) != 0xf5)) {
              if (*(sword *)(param_1 + 0x248) == 4) {
                uVar13 = *(uint *)(*(int *)(puVar1 + 0xc6) + *(sword *)(param_1 + 0x250) * 4);
                if (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) !=
                    (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) & uVar13)) {
                  *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) | 0x1000;
                  if (_od_update_time == 0) {
                    _od_update_time = 1;
                  }
                  uVar13 = ~(3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU)) & uVar13;
                  sVar15 = *(sword *)(param_1 + 0x250);
                  iVar21 = *(int *)(puVar1 + 0xc6);
                  cVar9 = *(char *)(param_1 + 0x252);
                  iVar19 = 3;
loc_40761D8:
                  *(uint *)(iVar21 + sVar15 * 4) = iVar19 << ((int)cVar9 & 0x3fU) | uVar13;
                }
              }
              else {
                uVar13 = *(uint *)(*(int *)(puVar1 + 0xc6) + *(sword *)(param_1 + 0x250) * 4);
                if (2 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) !=
                    (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) & uVar13)) {
                  *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) | 0x1000;
                  if (_od_update_time == 0) {
                    _od_update_time = 1;
                  }
                  uVar13 = ~(3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU)) & uVar13;
                  sVar15 = *(sword *)(param_1 + 0x250);
                  iVar21 = *(int *)(puVar1 + 0xc6);
                  cVar9 = *(char *)(param_1 + 0x252);
                  iVar19 = 2;
                  goto loc_40761D8;
                }
              }
loc_407640C:
              bVar5 = true;
              goto loc_4076414;
            }
            *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x40000;
            *(undefined4 *)(param_1 + 0x214) = *(undefined4 *)(param_1 + 0x224);
            uVar6 = _pmap_kernel();
            *(undefined4 *)(param_1 + 0x218) = uVar6;
            *(undefined2 *)(param_1 + 0x248) = 1;
            *(undefined *)(param_1 + 0x25d) = 0;
            *(int *)(param_1 + 0x234) =
                 (*(int *)(param_1 + 0x238) - *(int *)(puVar1 + 0xbe)) - iVar20;
            iVar8 = 0xf;
            goto loc_4076DD4;
          }
          iVar8 = 0;
          if (iVar12 <= (int)uVar14) goto loc_40763D2;
          goto loc_40760BE;
        }
        if (uVar13 == 2) {
          if (*(sword *)(param_1 + 0x248) != 0xf5) goto loc_407640C;
          goto loc_4076D42;
        }
        if (uVar13 == 3) {
          if (*(sword *)(param_1 + 0x248) == 1) {
            uVar13 = *(uint *)(iVar21 + *(sword *)(param_1 + 0x250) * 4);
            if (2 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) !=
                (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) & uVar13)) {
              *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) | 0x1000;
              if (_od_update_time == 0) {
                _od_update_time = 1;
              }
              *(uint *)(*(int *)(puVar1 + 0xc6) + *(sword *)(param_1 + 0x250) * 4) =
                   2 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) |
                   ~(3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU)) & uVar13;
            }
            if (iVar16 == 0) {
              uStack_1d = (undefined)iVar20;
              *(undefined *)(param_1 + 0x265) = uStack_1d;
            }
            if (((iVar17 != 1) && (iVar12 - 1U == uVar14)) &&
               (*(char *)(param_1 + 0x266) =
                     (char)iVar17 - (char)((iVar20 + *(int *)(param_1 + 0x244)) % iVar17),
               iVar17 == *(char *)(param_1 + 0x266))) {
              *(undefined *)(param_1 + 0x266) = 0;
            }
            goto loc_4076414;
          }
          if (*(sword *)(param_1 + 0x248) != 2) {
            if ((*(sword *)(param_1 + 0x248) != 0xf5) && (*(sword *)(param_1 + 0x248) != 4))
            goto loc_4076414;
            goto loc_4076D42;
          }
          if (iVar16 == 0) {
            iVar8 = 0;
            while (((int)uVar14 < iVar12 &&
                   ((*(int *)(iVar21 + ((int)uVar14 >> 4) * 4) >> (uVar14 & 0xf) * 2 & 3U) == 3))) {
              iVar8 = iVar8 + 1;
              uVar14 = uVar14 + 1;
            }
            goto loc_40763D2;
          }
          iStack_1c = iVar17 * iVar16;
          goto loc_407609A;
        }
loc_4076414:
        iStack_1c = iVar17 + iStack_1c;
        iVar16 = iVar16 + 1;
        uVar14 = uVar14 + 1;
        if (iVar12 <= (int)uVar14) goto loc_4076424;
      }
      if (*(sword *)(param_1 + 0x248) == 0xf5) goto loc_4076D42;
      if (iVar16 != 0) {
        iStack_1c = iVar17 * iVar16;
loc_407609A:
        *(int *)(param_1 + 0x244) = iStack_1c - iVar20;
        goto loc_4076424;
      }
      iVar12 = _od_locate_alt(param_1,param_2,puVar1,
                              (*(int *)(param_1 + 0x238) - *(int *)(puVar1 + 0xbe)) - iVar20,
                              *(undefined4 *)(param_1 + 0x238));
      if (iVar12 == -1) goto loc_4076DE0;
      iVar16 = iVar12 % iVar18;
      sVar15 = *(sword *)(piVar2 + 0x1d);
      if (iVar12 / iVar18 < (int)sVar15) {
        iVar21 = (int)*(sword *)((int)piVar2 + 0x7a) +
                 (iVar12 / iVar18) * (int)*(sword *)((int)piVar2 + 0x76) +
                 (int)*(sword *)(piVar2 + 0x1c);
      }
      else {
        iVar21 = (int)sVar15 * (int)*(sword *)((int)piVar2 + 0x76) + (int)*(sword *)(piVar2 + 0x1c);
        iVar16 = iVar12 - sVar15 * iVar18;
      }
      *(int *)(param_1 + 0x238) = iVar17 * iVar16 + iVar21;
      *(int *)(param_1 + 0x238) = iVar20 + *(int *)(param_1 + 0x238);
      iVar20 = iVar17 - iVar20;
      if (*(int *)(param_1 + 0x244) < iVar20) {
        iVar20 = *(int *)(param_1 + 0x244);
      }
      *(int *)(param_1 + 0x244) = iVar20;
    } while( true );
  case :
    _od_drive_cmd(param_1,param_2,(int)(*(sword *)(param_1 + 0x22e) >> 0xc) | 0xa000,9);
    *(word *)(param_1 + 600) = *(word *)(param_1 + 0x22e) & 0xfff;
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x60000000;
    *(undefined *)(param_1 + 0x268) = _od_next_state[*(byte *)(param_1 + 0x25c)];
  :
loc_4076E5A:
    *puVar3 = (char)((word)*(undefined2 *)(param_1 + 0x22c) >> 8);
    puVar3[1] = (char)*(undefined2 *)(param_1 + 0x22c);
    if ((*piVar2 != 0x4e655854) &&
       ((*(char *)(param_1 + 0x265) != '\0' || (*(char *)(param_1 + 0x266) != '\0')))) {
                    /* WARNING: Subroutine does not return */
      _panic(aOdBeforeAfter);
    }
    if (*(char *)(param_1 + 0x265) == '\0') {
      bVar10 = *(byte *)(param_1 + 0x264);
    }
    else {
      bVar10 = *(char *)(param_1 + 0x264) - *(char *)(param_1 + 0x265);
    }
    puVar3[2] = bVar10 | 0x10;
    puVar3[3] = *(char *)(param_1 + 0x266) +
                (char)*(undefined4 *)(param_1 + 0x244) + *(char *)(param_1 + 0x265);
    iVar8 = _od_issue_cmd(param_1,param_2);
    if (-1 < iVar8) {
      return iVar8;
    }
    break;
  case :
    if ((*(sword *)(param_1 + 0x248) != 4) && (*(sword *)(param_1 + 0x248) != 0xf5)) {
      *(undefined *)(param_1 + 0x25c) = 1;
loc_4076814:
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x20000000;
      *(undefined *)(param_1 + 0x268) = _od_next_state[*(byte *)(param_1 + 0x25c)];
      *(undefined *)(param_1 + 0x269) = 0x12;
      goto loc_4076424;
    }
    goto loc_4076D42;
  case :
    if (((*(uint *)(param_1 + 0x220) & 0x40000) != 0) || (_od_noverify == 0)) {
      *(undefined *)(param_1 + 0x25c) = 8;
      goto loc_4076814;
    }
  case :
    goto loc_4076D42;
  case :
    break;
  case :
loc_4076CEC:
    *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) & 0x3bff;
    if ((*(word *)(puVar1 + 0xd8) & 0x800) != 0) {
      *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) & 0xf7ff;
      _wakeup(puVar1 + 0xd8);
    }
    *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) & 0xcfff;
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xff7fbfff;
    if ((*(uint *)(param_1 + 0x220) & 0x400) == 0) goto loc_4076D42;
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffffbff;
    break;
  case :
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xff7fffff;
    cVar9 = *(char *)(param_1 + 0x26b);
    goto loc_4076DCC;
  case :
    *(undefined2 *)(param_1 + 0x24a) = *(undefined2 *)(puVar3 + 8);
    if ((*(word *)(param_1 + 0x24a) & 1) != 0) {
      _od_status(param_1,param_2,puVar3,0x2800,6);
      *(undefined *)(param_1 + 0x268) = 10;
      return 1;
    }
    goto loc_4076B0C;
  case :
    *(undefined2 *)(param_1 + 0x24c) = *(undefined2 *)(puVar3 + 8);
    if ((*(word *)(param_1 + 0x24c) & 1) != 0) {
      _od_status(param_1,param_2,puVar3,0x2a00,6);
      *(undefined *)(param_1 + 0x268) = 0xb;
      return 1;
    }
    goto loc_4076B0C;
  case :
    *(undefined2 *)(param_1 + 0x24e) = *(undefined2 *)(puVar3 + 8);
loc_4076B0C:
    if (((*(uint *)(param_1 + 0x220) & 0x4000) == 0) && (*(sword *)(param_1 + 0x24e) != 0)) {
      uVar14 = 0xf;
      pcVar22 = (char *)&unk_40B1DB0;
      do {
        if ((((uint)*(word *)(param_1 + 0x24e) & 1 << (uVar14 & 0x1f)) != 0) && (*pcVar22 != '\0'))
        {
          *(char *)(param_1 + 599) = (char)uVar14 + '%';
          *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000;
          break;
        }
        pcVar22 = pcVar22 + -8;
        wVar11 = (word)(uVar14 >> 0x10);
        sVar15 = (sword)uVar14 + -1;
        uVar14 = CONCAT22(wVar11,sVar15);
      } while ((sVar15 != -1) || (uVar14 = (uint)wVar11 * 0x10000 - 1, wVar11 != 0));
    }
    if (((*(uint *)(param_1 + 0x220) & 0x4000) == 0) && ((*(word *)(param_1 + 0x24c) & 0xfffe) != 0)
       ) {
      uVar14 = 0xf;
      pcVar22 = (char *)&unk_40B1D30;
      do {
        if ((((uint)*(word *)(param_1 + 0x24c) & 1 << (uVar14 & 0x1f)) != 0) && (*pcVar22 != '\0'))
        {
          *(char *)(param_1 + 599) = (char)uVar14 + '\x15';
          *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000;
          break;
        }
        pcVar22 = pcVar22 + -8;
        uVar14 = uVar14 - 1;
      } while (0 < (int)uVar14);
    }
    if (((*(uint *)(param_1 + 0x220) & 0x4000) == 0) && ((*(word *)(param_1 + 0x24a) & 0xfffe) != 0)
       ) {
      uVar14 = 0xf;
      pcVar22 = (char *)&unk_40B1CB8;
      do {
        if ((((uint)*(word *)(param_1 + 0x24a) & 1 << (uVar14 & 0x1f)) != 0) && (*pcVar22 != '\0'))
        {
          *(char *)(param_1 + 599) = (char)uVar14 + '\x06';
          *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000;
          break;
        }
        pcVar22 = pcVar22 + -8;
        uVar14 = uVar14 - 1;
      } while (0 < (int)uVar14);
    }
    do {
      iVar8 = _od_drive_cmd(param_1,param_2,0x5000,6);
    } while (iVar8 == -1);
    *(undefined *)(param_1 + 0x268) = 0xc;
    return 1;
  case :
    *(undefined *)(param_1 + 0x267) = *(undefined *)(param_1 + 0x26d);
    *(undefined *)(param_1 + 0x268) = *(undefined *)(param_1 + 0x26e);
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfbffffff;
    puVar3[5] = puVar3[5] | 2;
    return -1;
  case :
    uVar14 = _od_status(param_1,param_2,puVar3,0x2000,9);
    if ((uVar14 & 0x200) != 0) {
      _od_drive_cmd(param_1,param_2,0x5300,6);
      *(undefined *)(param_1 + 0x268) = 0xe;
      return 1;
    }
  case :
    _od_idle_time = 0;
    if ((*(uint *)(param_1 + 0x220) & 0x1000000) != 0) {
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfefdffff;
      return 0;
    }
loc_4076D42:
    *(undefined *)(param_1 + 0x266) = 0;
    *(undefined *)(param_1 + 0x265) = *(undefined *)(param_1 + 0x266);
    *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) - *(int *)(param_1 + 0x244);
    *(int *)(param_1 + 0x214) = piVar2[0x17] * *(int *)(param_1 + 0x244) + *(int *)(param_1 + 0x214)
    ;
    *(int *)(param_1 + 0x230) = *(int *)(param_1 + 0x244) + *(int *)(param_1 + 0x230);
    if (0 < *(int *)(param_1 + 0x23c)) {
      iVar8 = 1;
loc_4076DD4:
      iVar8 = _od_fsm(param_1,param_2,iVar8);
      return iVar8;
    }
    if (((*(uint *)(param_1 + 0x220) & 0x800) != 0) &&
       (*(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffff7ff,
       *(int *)(param_1 + 0x240) != 0)) {
      *(undefined *)(param_1 + 0x25e) = 0;
      *(undefined2 *)(param_1 + 0x248) = 1;
      *(undefined4 *)(param_1 + 0x23c) = *(undefined4 *)(param_1 + 0x240);
      iVar8 = 1;
      goto loc_4076DD4;
    }
    if ((*(uint *)(param_1 + 0x220) & 0x40000) != 0) {
      cVar9 = *(char *)(param_1 + 0x26a);
loc_4076DCC:
      iVar8 = (int)cVar9;
      goto loc_4076DD4;
    }
    goto loc_4076E4C;
  case :
    if ((*(uint *)(param_1 + 0x220) & 0x4000) == 0) {
      *(undefined4 *)(param_1 + 0x230) = *(undefined4 *)(param_1 + 0x234);
      if (*piVar2 == 0x4e655854) {
        *(int *)(param_1 + 0x23c) = iVar8 >> 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x23c) = 1;
      }
      *(char *)(param_1 + 0x25d) = *(char *)(param_1 + 0x25d) + '\x01';
      if (_od_test_passes < *(char *)(param_1 + 0x25d)) {
        *(undefined2 *)(param_1 + 0x248) = 4;
        *(undefined *)(param_1 + 0x26a) = 0x11;
        iVar8 = 1;
      }
      else {
        uVar14 = 0;
        if ((uint)(piVar2[0x17] * *(int *)(param_1 + 0x23c)) >> 2 != 0) {
          do {
            *(undefined4 *)(*(int *)(param_1 + 0x224) + uVar14 * 4) =
                 (&unk_40B1FB8)[*(char *)(param_1 + 0x25d)];
            uVar14 = uVar14 + 1;
          } while (uVar14 < (uint)(piVar2[0x17] * *(int *)(param_1 + 0x23c)) >> 2);
        }
        *(undefined *)(param_1 + 0x26a) = 0xf;
        iVar8 = 1;
      }
    }
    else {
      iVar8 = 0x10;
    }
    goto loc_4076DD4;
  case :
    goto loc_40769A6;
  case :
    if (((*(uint *)(param_1 + 0x220) & 0x4000) == 0) &&
       (uVar14 = *(uint *)(*(int *)(puVar1 + 0xc6) + *(sword *)(param_1 + 0x250) * 4),
       3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) !=
       (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) & uVar14))) {
      *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) | 0x1000;
      if (_od_update_time == 0) {
        _od_update_time = 1;
      }
      *(uint *)(*(int *)(puVar1 + 0xc6) + *(sword *)(param_1 + 0x250) * 4) =
           3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) |
           ~(3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU)) & uVar14;
    }
loc_40769A6:
    if (((*(uint *)(param_1 + 0x220) & 0x4000) == 0) ||
       (iVar8 = _od_remap(param_1,param_2,puVar1,*(undefined4 *)(param_1 + 0x238)), iVar8 != 0)) {
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffbbfff;
      uVar6 = _disksort_first(*(undefined4 *)(iVar4 + 0x18));
      iVar8 = _od_setup(param_1,param_2,uVar6);
      return iVar8;
    }
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffbffff;
    break;
  case :
    *(undefined *)(param_1 + 0x25c) = 1;
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x20000000;
    *(undefined *)(param_1 + 0x268) = _od_next_state[*(byte *)(param_1 + 0x25c)];
    *(undefined *)(param_1 + 0x269) = 0x12;
    bVar5 = true;
    if (*piVar2 != 0x4e655854) {
      *(undefined4 *)(param_1 + 0x244) = 1;
    }
    goto loc_4076424;
  case :
    _od_status(param_1,param_2,puVar3,0x2000,9);
    _od_drive_cmd(param_1,param_2,0x5000,9);
    iVar8 = _od_drive_cmd(param_1,param_2,0x5300,6);
    *(undefined *)(param_1 + 0x268) = 0x14;
    return iVar8;
  case :
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xff7fbfff;
    *(undefined *)(param_2 + 0x1d) = 0xff;
    *(undefined2 *)(param_2 + 0x1a) = 0xffff;
    *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) & 0xdfff;
    iVar8 = (int)*(char *)(param_1 + 0x26c);
    goto loc_4076DD4;
  }
loc_4076DE6:
  puVar7 = (uint *)_disksort_first(*(undefined4 *)(iVar4 + 0x18));
  _od_perror(param_1,param_2,8,puVar7[9],*(undefined4 *)(param_1 + 0x238));
  *puVar7 = *puVar7 | 4;
  if ((*(uint *)(param_1 + 0x220) & 0x1000) != 0) {
    puVar3[0xd] = (char)_od_frmr;
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffffefff;
  }
  if ((uint *)(puVar1 + 0x6a) == puVar7) {
    *(sword *)(puVar1 + 0x86) = (sword)*(char *)(param_1 + 599);
  }
loc_4076E4C:
  iVar8 = sub_4075AC0(iVar4);
  return iVar8;
loc_4075EE6:
  do {
    *(sword *)(param_1 + 0x250) = (sword)((int)uVar14 >> 4);
    *(byte *)(param_1 + 0x252) = ((byte)uVar14 & 0xf) << 1;
    iVar8 = *(int *)(puVar1 + 0xc6);
    if ((*(int *)(iVar8 + *(sword *)(param_1 + 0x250) * 4) >>
         ((int)*(char *)(param_1 + 0x252) & 0x3fU) & 3U) != 1) {
      if (*(sword *)(param_1 + 0x248) == 4) {
        uVar13 = *(uint *)(iVar8 + *(sword *)(param_1 + 0x250) * 4);
        if (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) !=
            (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) & uVar13)) {
          *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) | 0x1000;
          if (_od_update_time == 0) {
            _od_update_time = 1;
          }
          uVar13 = ~(3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU)) & uVar13;
          sVar15 = *(sword *)(param_1 + 0x250);
          iVar8 = *(int *)(puVar1 + 0xc6);
          cVar9 = *(char *)(param_1 + 0x252);
          iVar20 = 3;
loc_4075FEE:
          *(uint *)(iVar8 + sVar15 * 4) = iVar20 << ((int)cVar9 & 0x3fU) | uVar13;
        }
      }
      else {
        uVar13 = *(uint *)(iVar8 + *(sword *)(param_1 + 0x250) * 4);
        if (2 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) !=
            (3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU) & uVar13)) {
          *(word *)(puVar1 + 0xd8) = *(word *)(puVar1 + 0xd8) | 0x1000;
          if (_od_update_time == 0) {
            _od_update_time = 1;
          }
          uVar13 = ~(3 << ((int)*(char *)(param_1 + 0x252) & 0x3fU)) & uVar13;
          sVar15 = *(sword *)(param_1 + 0x250);
          iVar8 = *(int *)(puVar1 + 0xc6);
          cVar9 = *(char *)(param_1 + 0x252);
          iVar20 = 2;
          goto loc_4075FEE;
        }
      }
    }
    uVar14 = uVar14 + 1;
  } while ((int)uVar14 < iVar12);
loc_4076424:
  if ((*(char *)(param_1 + 0x25c) == '\x01') && (bVar5)) {
    *(undefined *)(param_1 + 0x25c) = 4;
  }
  bVar10 = *(byte *)(param_1 + 0x25c);
  if (bVar10 == 0xf1) {
    wVar11 = *(word *)(puVar1 + 0xd8);
    if ((wVar11 & 0x1000) == 0) {
      if ((wVar11 & 0x2000) != 0) {
        if ((_rootdev._0_1_ == _od_blk_major) && (puVar1 == _od_vol)) {
          _od_runout_time = (sword)_hz * 0x14;
        }
loc_4076652:
        *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x400;
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x800000;
        *(undefined2 *)(param_1 + 600) = 0x5600;
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x40000000;
        iVar8 = _od_issue_cmd(param_1,param_2);
        *(undefined *)(param_1 + 0x268) = 7;
        return iVar8;
      }
      goto loc_4076CEC;
    }
    *(word *)(puVar1 + 0xd8) = wVar11 | 0x800;
    _od_update_time = -1;
    _kernel_thread_noblock(_kernel_task,_od_update_thread);
    goto loc_4076D42;
  }
  if (bVar10 < 0xf2) {
    if (bVar10 == 4) {
loc_40764CE:
      *(undefined2 *)(param_1 + 0x262) = 0x4400;
    }
    else if (bVar10 < 5) {
      if (bVar10 == 1) {
        *(undefined2 *)(param_1 + 0x262) = 0x4300;
      }
      else {
        if (bVar10 != 2) goto loc_40766CA;
        *(undefined2 *)(param_1 + 0x262) = 0x4100;
      }
    }
    else {
      if (bVar10 != 8) {
        if (bVar10 == 0xf0) {
          iVar8 = _od_status(param_1,param_2,puVar3,0x2000,9);
          if (iVar8 != -1) {
            *(undefined2 *)(param_1 + 600) = 0x5000;
            *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x40000000;
            iVar8 = _od_issue_cmd(param_1,param_2);
            if (-1 < iVar8) {
              *(undefined *)(param_1 + 0x268) = 0xd;
              return iVar8;
            }
          }
          goto loc_4076DE6;
        }
        goto loc_40766CA;
      }
      *(undefined2 *)(param_1 + 0x262) = 0x4200;
    }
    if ((*(byte *)(param_2 + 0x18) & 0x20) == 0) {
      *(undefined2 *)(param_1 + 600) = 0x5900;
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x40000000;
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xdfffffff;
      *(undefined *)(param_1 + 0x268) = *(undefined *)(param_1 + 0x267);
      *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x2000;
    }
    else {
      *(sword *)(param_1 + 0x22e) = *(sword *)(param_1 + 0x22c) - (sword)_od_land;
      *(undefined2 *)(param_1 + 600) = *(undefined2 *)(param_1 + 0x262);
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x40000000;
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xdfffffff;
      *(undefined *)(param_1 + 0x268) = 2;
      *(undefined2 *)(param_2 + 0x1a) = *(undefined2 *)(param_1 + 0x262);
      iVar8 = (int)*(sword *)(*(int *)(param_2 + 0x14) + 0xc);
      if (-1 < iVar8) {
        *(int *)(_dk_seek + iVar8 * 4) = *(int *)(_dk_seek + iVar8 * 4) + 1;
      }
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0x7fffffff;
    }
    goto loc_4076E5A;
  }
  if (bVar10 == 0xf4) {
    iVar8 = _od_reset(param_1,param_2,puVar3);
    return iVar8;
  }
  if (bVar10 < 0xf5) {
    if (bVar10 == 0xf2) {
      _od_drive_cmd(param_1,param_2,
                    CONCAT22((sword)(*(int *)(param_1 + 0x230) >> 0x1c),
                             (sword)(*(int *)(param_1 + 0x230) >> 0xc)) | 0xa000,9);
      *(char *)(param_2 + 0x1d) = (char)(*(int *)(param_1 + 0x230) >> 0xc);
      if ((*(byte *)(param_2 + 0x18) & 0x20) == 0) {
        _od_drive_cmd(param_1,param_2,0x5900,9);
        *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x2000;
      }
      _od_drive_cmd(param_1,param_2,0x2200,10);
      _delay(0x28);
      puVar3[7] = 0;
      puVar3[7] = 0x20;
      do {
      } while ((puVar3[4] & 1) == 0);
      *(word *)(param_1 + 600) = (word)*(undefined4 *)(param_1 + 0x230) & 0xfff;
loc_4076694:
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x40000000;
      iVar8 = _od_issue_cmd(param_1,param_2);
      *(undefined *)(param_1 + 0x268) = 5;
      return iVar8;
    }
    if (bVar10 == 0xf3) {
      *(undefined2 *)(param_1 + 600) = 0x5a00;
      goto loc_4076694;
    }
  }
  else {
    if (bVar10 == 0xf5) {
      *(undefined *)(param_1 + 0x25c) = 4;
      goto loc_40764CE;
    }
    if (bVar10 == 0xf6) goto loc_4076652;
  }
loc_40766CA:
  *(undefined *)(param_1 + 599) = 0xb;
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000;
  goto loc_4076DE6;
loc_4076DE0:
  *(undefined *)(param_1 + 599) = 0x36;
  goto loc_4076DE6;
  while( true ) {
    iVar8 = iVar8 + 1;
    uVar14 = uVar14 + 1;
    if (iVar12 <= (int)uVar14) break;
loc_40760BE:
    if ((*(int *)(*(int *)(puVar1 + 0xc6) + ((int)uVar14 >> 4) * 4) >> (uVar14 & 0xf) * 2 & 3U) != 0
       ) break;
  }
loc_40763D2:
  _od_zero_fill(param_1,puVar1,iVar8);
  goto loc_4076D42;
}
/* GHIDRADEC_FUNCTION index=2172 start=0x4076ee8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte _od_sect_to(int param_1,int param_2)

{
  undefined *puVar1;
  undefined2 uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  
  puVar1 = *(undefined **)(param_1 + 0x210);
  uVar2 = *(undefined2 *)(param_1 + 0x22c);
  bVar3 = *(byte *)(param_1 + 0x264);
  if (*(char *)(param_1 + 0x264) == '\0') {
    *puVar1 = (char)((uint)(*(sword *)(param_1 + 0x22c) + -1) >> 8);
    puVar1[1] = (char)*(undefined2 *)(param_1 + 0x22c) + -1;
    iVar4 = *(sword *)(param_1 + 0x22c) + -2;
    puVar1[2] = 0x1f;
  }
  else {
    *puVar1 = (char)((word)*(undefined2 *)(param_1 + 0x22c) >> 8);
    puVar1[1] = (char)*(undefined2 *)(param_1 + 0x22c);
    iVar4 = *(sword *)(param_1 + 0x22c) + -1;
    puVar1[2] = *(char *)(param_1 + 0x264) - 1U | 0x10;
  }
  puVar1[3] = 1;
  _od_drive_cmd(param_1,param_2,iVar4 >> 0xc | 0xa000,9);
  _od_drive_cmd(param_1,param_2,*(word *)(param_1 + 0x22e) & 0xfff,9);
  puVar1[5] = puVar1[5] & 0xf2;
  puVar1[0xc] = byte_40B1FDB | *(byte *)(param_1 + 0x26f) & 0xfc;
  puVar1[6] = (byte)(param_2 + -0x40c3e18 >> 5) | 0xc0;
  puVar1[7] = 0;
  puVar1[7] = 2;
  uVar5 = 0;
  do {
    _delay(1);
    if (puVar1[3] != '\x01') break;
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 100000);
  puVar1[4] = _disr_shadow | 0xfc;
  puVar1[7] = 0;
  *puVar1 = (char)((word)uVar2 >> 8);
  puVar1[1] = (char)uVar2;
  puVar1[2] = bVar3 | 0x10;
  puVar1[3] = 1;
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xbfffffff;
  iVar4 = __od_id_r;
  cVar6 = uVar5 < 100000;
  if (uVar5 == 100000) {
    _printf(aOdSectToN1NotF);
  }
  else {
    __od_id_r = 2;
  }
  _od_issue_cmd(param_1,param_2);
  __od_id_r = iVar4;
  return cVar6 << 4 | (iVar4 < 0) << 3 | (iVar4 == 0) << 2;
}
/* GHIDRADEC_FUNCTION index=2173 start=0x4077088 */

undefined4 _od_issue_cmd(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  
  iVar1 = param_1[0x84];
  iVar5 = *(int *)(param_2 + 8);
  if (((param_1[0x88] & 0x20000000) != 0) && ((*(byte *)(param_1 + 0x97) & 0xc3) != 0)) {
    param_1[0x88] = param_1[0x88] | 0x100000;
    iVar7 = 0;
    if ((*(byte *)(param_1 + 0x97) & 0x82) != 0) {
      iVar7 = 0x40000;
    }
    param_1[0xb] = -(int)-(iVar7 == 0x40000);
    iVar2 = *(int *)(*(int *)(iVar5 + 0xae) + 0x5c);
    if (((param_1[0x88] & 0x800) == 0) || (*(char *)(param_1 + 0x97) != '\x02')) {
      uVar3 = param_1[0x86];
    }
    else {
      uVar3 = _pmap_kernel(iVar7,10,iVar2 * *(char *)((int)param_1 + 0x265),
                           iVar2 * *(char *)((int)param_1 + 0x266));
    }
    if (((param_1[0x88] & 0x800) == 0) || (uVar4 = _od_rathole, *(char *)(param_1 + 0x97) != '\x02')
       ) {
      uVar4 = param_1[0x85];
    }
    _dma_list(param_1,param_1 + 0x3e,uVar4,
              *(int *)(*(int *)(iVar5 + 0xae) + 0x5c) *
              ((int)*(char *)((int)param_1 + 0x266) +
              (int)*(char *)((int)param_1 + 0x265) + param_1[0x91]),uVar3);
    param_1[5] = param_1;
    *param_1 = param_1 + 0x3e;
    _dma_start(param_1,*param_1,iVar7);
  }
  bVar6 = (byte)(param_2 + -0x40c3e18 >> 5);
  *(byte *)((int)param_1 + 0x272) = bVar6;
  if ((param_1[0x88] & 0x40000000) == 0) {
    *(byte *)(iVar1 + 6) = bVar6 | 0x80;
  }
  else {
    uVar3 = 6;
    if ((param_1[0x88] & 0x20000000) != 0) {
      uVar3 = 10;
    }
    iVar5 = _od_drive_cmd(param_1,param_2,*(undefined2 *)(param_1 + 0x96),uVar3);
    if (iVar5 < 0) {
      return 0xffffffff;
    }
  }
  if ((param_1[0x88] & 0x20000000) != 0) {
    if ((param_1[0x88] & 0x40000000) == 0) {
      _od_block_async(param_1,param_2);
    }
    *(undefined *)(param_1 + 0x98) = 6;
    if ((*(byte *)(param_1 + 0x97) & 0x82) == 0) {
      if ((*(byte *)(param_1 + 0x97) & 8) == 0) {
        param_1[0x88] = param_1[0x88] | 0x8000000;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) | 4;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xf6;
        *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0xfc;
        bVar6 = byte_40B1FE3 | *(byte *)((int)param_1 + 0x26f);
      }
      else {
        param_1[0x88] = param_1[0x88] | 0x8000000;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) | 8;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xfa;
        *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0xfc;
        bVar6 = byte_40B1FDF | *(byte *)((int)param_1 + 0x26f);
      }
    }
    else {
      *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xf2;
      param_1[0x88] = param_1[0x88] | 0x18000000;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0xfc;
      bVar6 = byte_40B1FDB | *(byte *)((int)param_1 + 0x26f);
    }
    *(byte *)((int)param_1 + 0x26f) = bVar6;
    *(undefined *)(iVar1 + 0xc) = *(undefined *)((int)param_1 + 0x26f);
    *(undefined *)(iVar1 + 7) = 0;
    *(undefined *)(iVar1 + 7) = *(undefined *)(param_1 + 0x97);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2174 start=0x40772f4 */

int _od_locate_alt(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar4 = *(int **)(param_3 + 0xae);
  if ((*piVar4 == 0x4e655854) || (*piVar4 == 0x646c5632)) {
    piVar5 = (int *)((int)piVar4 + 0x22e);
    iVar3 = 0x686;
  }
  else {
    piVar5 = *(int **)(param_3 + 0xb2);
    iVar3 = 0xc00;
  }
  iVar2 = (int)*(sword *)(piVar4 + 0x1e);
  if (*piVar4 == 0x4e655854) {
    iVar2 = iVar2 / (piVar4[0x19] >> 1);
  }
  iVar1 = ((param_5 - *(int *)(param_3 + 0xbe)) - (int)*(sword *)(piVar4 + 0x1c)) /
          (int)*(sword *)((int)piVar4 + 0x76);
  if ((-1 < iVar1) && (iVar1 < *(sword *)(piVar4 + 0x1d))) {
    iVar1 = iVar2 * iVar1;
    iVar2 = iVar2 + iVar1;
    if ((iVar2 < iVar3) && (iVar1 < iVar2)) {
      piVar4 = piVar5 + iVar1;
      do {
        if (param_4 == *piVar4) {
          return iVar1;
        }
        piVar4 = piVar4 + 1;
        iVar1 = iVar1 + 1;
      } while (iVar1 < iVar2);
    }
  }
  iVar2 = 0;
  if (iVar3 != 0) {
    do {
      if (*piVar5 == -1) {
        return -1;
      }
      if (param_4 == *piVar5) {
        return iVar2;
      }
      piVar5 = piVar5 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  return -1;
}
/* GHIDRADEC_FUNCTION index=2175 start=0x40773b6 */

undefined4 _od_remap(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint unaff_D4;
  int unaff_D5;
  int iVar6;
  
  piVar1 = *(int **)(param_3 + 0xae);
  iVar5 = 0;
  if ((*piVar1 == 0x4e655854) || (*piVar1 == 0x646c5632)) {
    iVar6 = (int)piVar1 + 0x22e;
  }
  else {
    iVar6 = *(int *)(param_3 + 0xb2);
  }
  if (*piVar1 == 0x4e655854) {
    iVar5 = (int)*(char *)(param_1 + 0x264) % (piVar1[0x19] >> 1);
  }
  iVar3 = _od_locate_alt(param_1,param_2,param_3,0,param_4);
  if (iVar3 == -1) {
    *(undefined *)(param_1 + 599) = 0x37;
    uVar4 = 0;
  }
  else {
    *(int *)(iVar6 + iVar3 * 4) = (param_4 - *(int *)(param_3 + 0xbe)) - iVar5;
    if (*piVar1 != 0x4e655854) {
      uVar2 = param_4 - *(int *)(param_3 + 0xbe);
      unaff_D5 = (int)uVar2 >> 4;
      unaff_D4 = (uVar2 & 0xf) * 2;
    }
    uVar2 = *(uint *)(*(int *)(param_3 + 0xc6) + unaff_D5 * 4);
    *(word *)(param_3 + 0xd8) = *(word *)(param_3 + 0xd8) | 0x1000;
    if (_od_update_time == 0) {
      _od_update_time = 1;
    }
    *(uint *)(*(int *)(param_3 + 0xc6) + unaff_D5 * 4) =
         1 << (unaff_D4 & 0x3f) | ~(3 << (unaff_D4 & 0x3f)) & uVar2;
    uVar4 = 1;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=2176 start=0x407748e */

void _od_block_async(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2177 start=0x4077496 */

undefined8 _od_drive_cmd(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x210);
  _od_block_async(param_1,param_2);
  *(undefined *)(iVar1 + 7) = 0;
  *(byte *)(iVar1 + 6) = (byte)(param_2 + -0x40c3e18 >> 5) | 0x80;
  _delay(2);
  iVar4 = 1;
  do {
    if ((*(byte *)(iVar1 + 4) & 1) != 0) break;
    _delay(1);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x2001);
  iVar3 = iVar4 / 1;
  if (iVar4 % 1 == 0) {
    *(undefined *)(iVar1 + 7) = 0;
  }
  if (iVar4 < 0x2001) {
    *(sword *)(param_1 + 0x25a) = (sword)param_3;
    *(char *)(iVar1 + 8) = (char)((uint)param_3 >> 8);
    *(char *)(iVar1 + 9) = (char)param_3;
    iVar4 = 1;
    do {
      if ((*(byte *)(iVar1 + 4) & 1) == 0) break;
      _delay(1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x2001);
    iVar3 = iVar4 / 1;
    if (iVar4 % 1 == 0) {
      *(undefined *)(iVar1 + 7) = 0;
    }
    if (iVar4 < 0x2001) {
      if ((param_4 & 9) == 0) {
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x8000000;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) | 1;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xf3;
        if (((param_3 == 0x5200) || (param_3 == 0x5300)) || (param_3 == 0x5600)) {
          *(undefined *)(param_1 + 0x260) = 0x10;
        }
        else {
          *(undefined *)(param_1 + 0x260) = 6;
        }
      }
      else {
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xf2;
      }
      if ((param_4 & 1) != 0) {
        do {
        } while ((*(byte *)(iVar1 + 4) & 1) == 0);
      }
      uVar2 = 0;
      goto loc_40775F8;
    }
    *(undefined *)(param_1 + 599) = 0x3b;
  }
  else {
    *(undefined *)(param_1 + 599) = 0x3a;
  }
  *(undefined *)(param_1 + 0x260) = 0;
  uVar2 = 0xffffffff;
loc_40775F8:
  return CONCAT44(uVar2,iVar3);
}
/* GHIDRADEC_FUNCTION index=2178 start=0x4077602 */

uint _od_dma_intr(int param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  if ((*(uint *)(param_1 + 0x2c) & 0x4000) != 0) {
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x10010000;
  }
  uVar1 = *(uint *)(param_1 + 0x220);
  if ((uVar1 & 0x10000000) != 0) {
    cVar2 = (_od_spl & 0x10) != 0;
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xefffffff;
    cVar3 = param_1 < 0;
    cVar4 = param_1 == 0;
    cVar5 = '\0';
    bVar6 = 0;
    _odintr(param_1);
    uVar1 = (uint)(byte)(cVar2 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2179 start=0x407765a */

void _odintr(undefined *param_1)

{
  undefined *puVar1;
  int *piVar2;
  undefined uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  int iVar11;
  char cVar12;
  byte bVar13;
  byte unaff_D3b;
  byte bVar14;
  byte unaff_D4b;
  undefined *puVar15;
  undefined **ppuVar16;
  undefined *puStack_50;
  undefined *puStack_4c;
  undefined *puStack_48;
  undefined *puStack_44;
  
  iVar7 = (&_odcinfo)[(int)(param_1 + -0x40c3b88) * 0x451ab30b >> 2];
  iVar6 = (int)(char)param_1[0x272];
  iVar5 = iVar6 * 0x20;
  puVar15 = _od_drive + iVar5;
  puVar1 = *(undefined **)(param_1 + 0x210);
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x8000;
  if ((*(uint *)(param_1 + 0x220) & 0x210000) == 0) {
    unaff_D3b = puVar1[4];
    unaff_D4b = puVar1[10];
    puVar1[4] = _disr_shadow | 0xfc;
    puVar1[5] = puVar1[5] & 0xfe;
  }
  puStack_44 = puVar15;
  if ((*(uint *)(param_1 + 0x220) & 0x8000000) == 0) {
    puStack_48 = param_1;
    puStack_4c = (undefined *)0x4077702;
    iVar7 = _od_attn();
    if (iVar7 == 0) {
      if ((*(uint *)(param_1 + 0x220) & 0x200000) != 0) {
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffdfffff;
      }
      _printf();
    }
    else if (iVar7 == 1) {
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x1000000;
    }
    goto loc_40780D8;
  }
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xf7ffffff;
  param_1[0x260] = 0;
  cVar12 = '\0';
  if ((*(uint *)(param_1 + 0x220) & 0x200000) == 0) {
    if ((*(uint *)(param_1 + 0x220) & 0x10000) != 0) {
      cVar12 = '9';
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffeffff;
      goto loc_40777F0;
    }
    if ((char)unaff_D3b < '\0') {
      if ((unaff_D4b & 8) == 0) {
        if ((unaff_D4b & 4) == 0) {
          if ((unaff_D4b & 2) == 0) {
            if ((unaff_D4b & 1) == 0) {
              _printf();
              goto loc_40777F0;
            }
            cVar12 = '\x03';
          }
          else {
            cVar12 = '\x02';
          }
        }
        else {
          cVar12 = '\x01';
        }
      }
      else {
        cVar12 = '8';
      }
    }
    else if ((unaff_D3b & 0x10) == 0) {
      if ((unaff_D3b & 0x20) == 0) {
        if ((unaff_D3b & 0x40) != 0) {
          cVar12 = '\r';
        }
        goto loc_40777F0;
      }
      cVar12 = '\x05';
    }
    else {
      (&word_40C3E30)[iVar6 * 0x10] = (&word_40C3E30)[iVar6 * 0x10] & 0xdfff;
      (&DAT_40c3e35)[iVar5] = 0xff;
      cVar12 = '\x04';
    }
loc_40777F4:
    if ((*(uint *)(param_1 + 0x220) & 0x4000) == 0) {
      param_1[599] = cVar12;
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000;
    }
  }
  else {
    cVar12 = '5';
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffdfffff;
loc_40777F0:
    if (cVar12 != '\0') goto loc_40777F4;
  }
  puVar1[7] = 0;
  puStack_48 = param_1;
  puStack_4c = (undefined *)0x4077820;
  iVar8 = _od_attn();
  if (iVar8 == 1) goto loc_40780D8;
  if ((*(word *)(param_1 + 0x24a) & 4) != 0) {
    param_1[599] = 8;
  }
  if ((*(word *)(param_1 + 0x24a) & 0x4000) != 0) {
    param_1[599] = 0x14;
  }
  if ((*(uint *)(param_1 + 0x220) & 0x1000000) != 0) {
    puStack_48 = param_1;
    puStack_4c = (undefined *)0x4077864;
    puStack_44 = puVar15;
    _od_async_attn();
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffffbfff;
    goto loc_40780D8;
  }
  if ((*(uint *)(param_1 + 0x220) & 0x2000000) != 0) {
    _wakeup();
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfdffffff;
  }
  if (*(int **)(iVar7 + 0x18) == (int *)(iVar7 + 0x18)) {
    _printf();
    goto loc_40780D8;
  }
  puVar9 = (undefined *)_disksort_first();
  if (puVar9 == (undefined *)0x0) {
    _printf();
    goto loc_40780D8;
  }
  iVar7 = *(int *)(puVar9 + 0x24);
  iVar8 = *(int *)(param_1 + 0x238);
  iVar10 = (sword)(word)((uint)*(undefined4 *)(puVar9 + 0x1f) >> 0x1b) * 0xda;
  piVar2 = *(int **)(DAT_40c3f32 + iVar10 + 0x44);
  if ((*(uint *)(param_1 + 0x220) & 0x4800000) == 0) {
    if ((*(uint *)(param_1 + 0x220) & 0x4000) == 0) {
      if ((*(uint *)(param_1 + 0x220) & 0x100000) != 0) {
        puStack_44 = (undefined *)0x4077938;
        _dma_cleanup();
      }
      if ((piVar2 != (int *)0x0) && ((*(uint *)(param_1 + 0x220) & 0x20000000) != 0)) {
        iVar11 = (int)(char)param_1[0x266] +
                 (int)(char)param_1[0x265] + *(int *)(param_1 + 0x244) + *(int *)(param_1 + 0x238);
        param_1[0x256] = (char)(iVar11 % piVar2[0x19]);
        *(sword *)(param_1 + 0x254) = (sword)(iVar11 / piVar2[0x19]);
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x80000000;
      }
      if ((((*(uint *)(param_1 + 0x220) & 0x1000) != 0) &&
          ((*(uint *)(param_1 + 0x220) & 0x20000000) != 0)) && (param_1[0x25c] == '\x02')) {
        puVar1[0xd] = (char)_od_frmr;
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffffefff;
      }
      if ((((param_1[0x25c] & 0x82) != 0) && ((*(uint *)(param_1 + 0x220) & 0x100000) != 0)) &&
         (puVar1[0xb] != '\0')) {
        if ((int)dword_40C3EA0 < (int)(uint)(byte)puVar1[0xb]) {
          dword_40C3EA0 = (uint)(byte)puVar1[0xb];
        }
        if (_od_stats == 0) {
          _od_stats = (uint)(byte)puVar1[0xb];
        }
        else {
          iVar11 = _od_stats + (byte)puVar1[0xb];
          if (iVar11 < 0) {
            iVar11 = iVar11 + 1;
          }
          _od_stats = iVar11 >> 1;
        }
        if (DAT_40c3f32 + iVar10 == puVar9) {
          uVar3 = puVar1[0xb];
          *(undefined4 *)(DAT_40c3f32 + iVar10 + 0x28) = 0;
          DAT_40c3f32[iVar10 + 0x2b] = uVar3;
        }
      }
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffefffff;
      if ((((*(uint *)(param_1 + 0x220) & 0x800) == 0) ||
          ((*(uint *)(param_1 + 0x220) & 0x20000000) == 0)) ||
         ((param_1[0x25c] != '\x02' || ((int)(uint)(byte)puVar1[0xb] <= _od_maxecc)))) {
        if ((((((param_1[0x25c] & 8) == 0) || ((*(uint *)(param_1 + 0x220) & 0x20000000) == 0)) ||
             (*piVar2 == 0x4e655854)) ||
            (((*(uint *)(param_1 + 0x220) & 0x80000) != 0 && ((char)unk_40C3FA0[iVar10 + 1] < '\0'))
            )) || ((int)(uint)(byte)puVar1[0xb] <= _od_maxecc)) {
          ppuVar16 = (undefined **)&stack0xffffffc4;
        }
        else {
          param_1[599] = 0x3c;
          puStack_44 = (undefined *)0x3;
          puStack_4c = param_1;
          puStack_50 = (undefined *)0x4077b6e;
          puStack_48 = puVar15;
          _od_perror();
          if ((*(uint *)(param_1 + 0x220) & 0x800) == 0) {
            *(int *)(param_1 + 0x240) = *(int *)(param_1 + 0x23c) - *(int *)(param_1 + 0x244);
            *(undefined4 *)(param_1 + 0x23c) = *(undefined4 *)(param_1 + 0x244);
          }
          *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x800;
          param_1[0x25e] = 0;
          param_1[0x271] = param_1[0x271] + '\x01';
          *(undefined2 *)(param_1 + 0x248) = 2;
          ppuVar16 = (undefined **)&stack0xffffffc4;
        }
      }
      else {
        if (((((int)(uint)(byte)puVar1[0xb] < _od_maxecc_l1) ||
             (_od_maxecc_h1 < (int)(uint)(byte)puVar1[0xb])) &&
            (((int)(uint)(byte)puVar1[0xb] < _od_maxecc_l2 ||
             (_od_maxecc_h2 < (int)(uint)(byte)puVar1[0xb])))) ||
           (_od_write_retry < (int)(uint)(byte)param_1[0x271])) {
          param_1[599] = 0x3c;
          goto loc_4077BC8;
        }
        param_1[599] = 0x3c;
        puStack_44 = (undefined *)0x1;
        puStack_4c = param_1;
        puStack_50 = (undefined *)0x4077afc;
        puStack_48 = puVar15;
        _od_perror();
        param_1[0x25e] = 0;
        *(undefined2 *)(param_1 + 0x248) = 1;
        ppuVar16 = &puStack_50;
        puStack_50 = (undefined *)0x1;
      }
    }
    else {
loc_4077BC8:
      if ((*(uint *)(param_1 + 0x220) & 0x800) != 0) {
        *(undefined2 *)(param_1 + 0x248) = 1;
        *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x240) + *(int *)(param_1 + 0x23c);
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffff7ff;
      }
      if ((*(uint *)(param_1 + 0x220) & 0x100000) != 0) {
        _dma_abort();
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xefefffff;
        puVar1[7] = 0;
        puStack_44 = (undefined *)0x4077c20;
        sub_407AA5C();
      }
      iVar11 = 0;
      if (((*(uint *)(param_1 + 0x220) & 0x20000000) == 0) || (*(sword *)(param_1 + 0x248) != 1))
      goto loc_4077C78;
      bVar13 = param_1[0x25c];
      if (bVar13 == 4) {
loc_4077C58:
        iVar11 = (*(int *)(param_1 + 0x244) - (uint)(byte)puVar1[3]) + -1;
        if (param_1[599] == '\x04') {
          iVar11 = *(int *)(param_1 + 0x244) - (uint)(byte)puVar1[3];
        }
      }
      else if (bVar13 < 5) {
        if (bVar13 == 1) goto loc_4077C58;
      }
      else if (bVar13 == 8) goto loc_4077C58;
loc_4077C78:
      if (iVar11 != 0) {
        iVar7 = iVar11 + iVar7;
        iVar8 = iVar11 + iVar8;
      }
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffffbfff;
      iVar11 = (char)param_1[599] * 8;
      bVar13 = _od_err[iVar11];
      if (bVar13 == 2) {
        bVar13 = param_1[0x25e];
        param_1[0x25e] = bVar13 + 1;
        if (bVar13 <= (byte)_od_err[iVar11 + 1]) {
          *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x800000;
          param_1[0x26b] = param_1[0x269];
          puStack_44 = (undefined *)0x2;
          puStack_4c = param_1;
          puStack_50 = (undefined *)0x4078028;
          puStack_48 = puVar15;
          _od_perror();
          puStack_50 = (undefined *)0x6;
          _od_drive_cmd(param_1,puVar15,0x1000);
          (&DAT_40c3e35)[iVar5] = 0xff;
          (&word_40C3E30)[iVar6 * 0x10] = (&word_40C3E30)[iVar6 * 0x10] & 0xdfff;
          param_1[0x268] = 8;
          goto loc_40780D8;
        }
        bVar13 = param_1[0x25f];
        param_1[0x25f] = bVar13 + 1;
        if (bVar13 <= (byte)_od_err[iVar11 + 2]) {
          param_1[0x25e] = 0;
          goto loc_40780BA;
        }
        *(int *)(puVar9 + 0x24) = iVar7;
        *(int *)(param_1 + 0x238) = iVar8;
        if ((*(uint *)(param_1 + 0x220) & 0x40000) == 0) {
loc_40780AA:
          ppuVar16 = (undefined **)&stack0xffffffc4;
        }
        else {
          puStack_44 = (undefined *)0x8;
          puStack_4c = param_1;
          puStack_50 = (undefined *)0x4077fe4;
          puStack_48 = puVar15;
          _od_perror();
          *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000;
          puStack_50 = (undefined *)(int)(char)param_1[0x26a];
          ppuVar16 = &puStack_50;
        }
      }
      else {
        if (2 < bVar13) {
          if (bVar13 == 3) {
            *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x800000;
            puStack_44 = (undefined *)0x9;
            puStack_4c = param_1;
            puStack_50 = (undefined *)0x407806c;
            puStack_48 = puVar15;
            _od_perror();
            puStack_50 = (undefined *)0x6;
            _od_drive_cmd(param_1,puVar15,0x5600);
            param_1[0x268] = 7;
            *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x400;
            *(undefined2 *)(unk_40C3FA0 + iVar10) = 0;
            goto loc_40780D8;
          }
          if (bVar13 != 4) goto loc_40780D8;
          bVar13 = param_1[0x25e];
          param_1[0x25e] = bVar13 + 1;
          if ((byte)_od_err[iVar11 + 1] < bVar13) goto loc_40780AA;
loc_40780BA:
          puStack_44 = (undefined *)0x7;
          puStack_4c = param_1;
          puStack_50 = (undefined *)0x40780cc;
          puStack_48 = puVar15;
          _od_perror();
          puStack_50 = puVar1;
          _od_reset(param_1,puVar15);
          goto loc_40780D8;
        }
        if (bVar13 != 1) goto loc_40780D8;
        if (((*(uint *)(param_1 + 0x220) & 0x40000) == 0) ||
           ((param_1[599] == '\x04' && (param_1[0x25e] == '\0')))) {
          if (((*(sword *)(param_1 + 0x248) == 1) &&
              ((*piVar2 != 0x4e655854 &&
               (((*(uint *)(param_1 + 0x220) & 0x80000) == 0 || (-1 < (char)unk_40C3FA0[iVar10 + 1])
                ))))) && ((param_1[599] != '\x04' || (param_1[0x25e] != '\0')))) {
            puStack_48 = param_1;
            puStack_4c = (undefined *)0x4077d50;
            puStack_44 = puVar15;
            iVar7 = _od_remap();
            if (iVar7 == 0) goto loc_40780AA;
            puStack_44 = (undefined *)0x5;
            puStack_4c = param_1;
            puStack_50 = (undefined *)0x4077d6c;
            puStack_48 = puVar15;
            _od_perror();
            ppuVar16 = &puStack_50;
            puStack_50 = (undefined *)0x1;
          }
          else {
            if (((*(uint *)(param_1 + 0x220) & 0x80000) == 0) || ((unk_40C3FA0[iVar10] & 1) == 0)) {
              bVar13 = _od_err[iVar11 + 1];
              bVar14 = _od_err[iVar11 + 2];
            }
            else {
              bVar13 = DAT_40c3f32[iVar10 + 0x6c];
              bVar14 = DAT_40c3f32[iVar10 + 0x6d];
            }
            if ((*(uint *)(param_1 + 0x220) & 0x1000) != 0) {
              bVar13 = 4;
              bVar14 = 0;
            }
            if ((param_1[0x25c] == '\b') && (param_1[0x25e] == '\0')) {
              dword_40C3EA4 = dword_40C3EA4 + 1;
            }
            bVar4 = param_1[0x25e];
            param_1[0x25e] = bVar4 + 1;
            if (bVar13 <= bVar4) {
              param_1[0x25e] = 0;
              bVar13 = param_1[0x25f];
              param_1[0x25f] = bVar13 + 1;
              if (bVar13 < bVar14) {
                *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x800000;
                puStack_44 = (undefined *)0x2;
                puStack_4c = param_1;
                puStack_50 = (undefined *)0x4077f4c;
                puStack_48 = puVar15;
                _od_perror();
                puStack_50 = (undefined *)0x6;
                _od_drive_cmd(param_1,puVar15,0x1000);
                param_1[0x26b] = param_1[0x269];
                param_1[0x268] = 8;
                (&DAT_40c3e35)[iVar5] = 0xff;
                (&word_40C3E30)[iVar6 * 0x10] = (&word_40C3E30)[iVar6 * 0x10] & 0xdfff;
                goto loc_40780D8;
              }
              if ((((param_1[599] == '\x04') && (*piVar2 != 0x4e655854)) &&
                  (param_1[0x25c] == '\x02')) && (*(int *)(param_1 + 0x244) == 1)) {
                puStack_44 = (undefined *)0x4;
                puStack_4c = param_1;
                puStack_50 = (undefined *)0x4077e34;
                puStack_48 = puVar15;
                _od_perror();
                param_1[0x25f] = 0;
                param_1[0x25e] = param_1[0x25f];
                puStack_50 = puVar15;
                _od_sect_to(param_1);
                goto loc_40780D8;
              }
              if ((((param_1[599] == '\x03') || (param_1[599] == '\x1f')) &&
                  ((*piVar2 != 0x4e655854 &&
                   ((param_1[0x25c] == '\x02' && (*(int *)(param_1 + 0x244) == 1)))))) &&
                 ((_od_dbug._0_1_ & 2) == 0)) {
                if ((*(uint *)(param_1 + 0x220) & 0x1000) == 0) {
                  param_1[0x270] = 0;
                  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x1000;
                }
                if ((byte)param_1[0x270] < 0x10) {
                  puVar1[0xd] = param_1[0x270] | (byte)_od_frmr & 0xf0;
                  param_1[0x270] = param_1[0x270] + '\x01';
                  param_1[0x25e] = 1;
                  puStack_44 = (undefined *)0x6;
                  puStack_4c = param_1;
                  puStack_50 = (undefined *)0x4077ef0;
                  puStack_48 = puVar15;
                  _od_perror();
                  goto loc_4077F78;
                }
                puVar1[0xd] = (byte)_od_frmr;
                *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffffefff;
              }
              if (param_1[0x25c] == '\b') {
                dword_40C3EA8 = dword_40C3EA8 + 1;
              }
              *(int *)(puVar9 + 0x24) = iVar7;
              *(int *)(param_1 + 0x238) = iVar8;
              goto loc_40780AA;
            }
loc_4077F78:
            puStack_44 = (undefined *)0x1;
            puStack_4c = param_1;
            puStack_50 = (undefined *)0x4077f8a;
            puStack_48 = puVar15;
            _od_perror();
            puStack_50 = (undefined *)(int)(char)param_1[0x269];
            ppuVar16 = &puStack_50;
          }
        }
        else {
          puStack_44 = (undefined *)0x8;
          puStack_4c = param_1;
          puStack_50 = (undefined *)0x4077cf4;
          puStack_48 = puVar15;
          _od_perror();
          *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000;
          puStack_50 = (undefined *)(int)(char)param_1[0x26a];
          ppuVar16 = &puStack_50;
        }
      }
    }
  }
  else {
    ppuVar16 = (undefined **)&stack0xffffffc4;
  }
  *(undefined **)((int)ppuVar16 + -4) = puVar15;
  *(undefined **)((int)ppuVar16 + -8) = param_1;
  *(undefined4 *)((int)ppuVar16 + -0xc) = 0x40780b8;
  _od_fsm();
loc_40780D8:
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xffff7fff;
  return;
}
/* GHIDRADEC_FUNCTION index=2180 start=0x40780ee */

void _od_reset(int param_1,int param_2,int param_3)

{
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x800000;
  *(byte *)(param_3 + 4) = _disr_shadow | *(byte *)(param_3 + 4) & 0xfc | 1;
  _disr_shadow = _disr_shadow | 1;
  _delay(0x50);
  _disr_shadow = _disr_shadow & 0xfe;
  *(byte *)(param_3 + 4) = _disr_shadow;
  *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x8000000;
  *(undefined *)(param_1 + 0x26c) = *(undefined *)(param_1 + 0x269);
  *(undefined *)(param_1 + 0x268) = 0x13;
  if ((*(word *)(param_2 + 0x18) & 0xa00) == 0x200) {
    _delay(10000000);
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x200000;
    _odintr(param_1);
  }
  else {
    *(undefined *)(param_1 + 0x260) = 10;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2181 start=0x40781be */

undefined4 _od_async_attn(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0x220) & 0x20000) == 0) {
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x20000;
    if (*(char *)(param_1 + 599) == '\b') {
      _od_drive_cmd(param_1,param_2,0x5000,6);
      *(undefined *)(param_1 + 0x268) = 0xd;
      uVar1 = 1;
    }
    else {
      _od_perror(param_1,param_2,8,param_3,param_4);
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffdffff;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = _od_fsm(param_1,param_2,(int)*(char *)(param_1 + 0x268));
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2182 start=0x4078248 */

void _od_perror(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  sword sVar7;
  undefined *puVar8;
  word wVar9;
  
  cVar4 = *(char *)(param_1 + 599);
  wVar9 = 0;
  iVar2 = *(int *)(param_2 + 8);
  iVar3 = *(int *)(iVar2 + 0xae);
  piVar5 = (int *)((&_odcinfo)[(param_1 + -0x40c3b88) * 0x451ab30b >> 2] + 0x18);
  if (((&_odcinfo)[(param_1 + -0x40c3b88) * 0x451ab30b >> 2] != 0) &&
     (piVar1 = (int *)*piVar5, piVar1 != piVar5)) {
    iVar6 = _disksort_first(piVar1);
    if (iVar6 != 0) {
      wVar9 = *(word *)(iVar6 + 0x1e);
    }
  }
  if (((_od_errmsg_filter <= param_3) || ((_od_dbug._0_1_ & 0x10) != 0)) &&
     ((*(uint *)(param_1 + 0x220) & 0x40000) == 0)) {
    if (*(sword *)(param_1 + 0x248) == 2) {
      puVar8 = (undefined *)&aRead;
    }
    else if (*(sword *)(param_1 + 0x248) == 1) {
      puVar8 = (undefined *)&aWrite;
    }
    else {
      puVar8 = aDriveCommand;
      if (*(sword *)(param_1 + 0x248) == 4) {
        puVar8 = (undefined *)&aErase;
      }
    }
    if (wVar9 == 0) {
      sVar7 = 0x3f;
    }
    else {
      sVar7 = (wVar9 & 7) + 0x61;
    }
    _od_xpr_alert(aOdDCSS,*(undefined2 *)(iVar2 + 0xd2),sVar7,puVar8,
                  *(undefined4 *)(_od_errtype + param_3 * 4),0);
    puVar8 = &unk_40A62E7;
    if ((*(uint *)(param_1 + 0x220) & 0x40000) != 0) {
      puVar8 = aTesting;
    }
    _od_xpr_alert(aSSBlockDPhysBl,*(undefined4 *)(DAT_40b1c14 + cVar4 * 8),puVar8,param_4,
                  param_5 - *(int *)(iVar2 + 0xbe),0);
    iVar2 = *(int *)(iVar3 + 100);
    _od_xpr_alert(aDDD,param_5 / iVar2,0,param_5 % iVar2,0,0);
    if ((_od_dbug._0_1_ & 4) != 0) {
      _od_note(param_1,0x4000,_od_xpr_alert);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2183 start=0x40783c4 */

void _od_note(int param_1,uint param_2,code *param_3)

{
  word wVar1;
  uint uVar2;
  sword sVar3;
  undefined5 **ppuVar4;
  word *pwVar5;
  undefined (**ppauVar6) [9];
  undefined *puVar7;
  undefined (*pauVar8) [9];
  
  if ((param_2 & 0x40000000) != 0) {
    (*param_3)(aDriveCmd);
    pwVar5 = (word *)&_od_dcmd;
    if (off_40B1DFC != (undefined5 *)0x0) {
      ppuVar4 = &off_40B1DFC;
      do {
        if ((pwVar5[1] & *(word *)(param_1 + 0x25a)) == *pwVar5) {
          (*param_3)(aS0xX,*ppuVar4,*(undefined2 *)(param_1 + 0x25a));
          goto loc_407843C;
        }
        ppuVar4 = ppuVar4 + 2;
        pwVar5 = pwVar5 + 4;
      } while (*ppuVar4 != (undefined5 *)0x0);
    }
    (*param_3)(aUnknown0xX,*(undefined2 *)(param_1 + 0x25a));
  }
loc_407843C:
  if ((param_2 & 0x20000000) != 0) {
    (*param_3)(aFormatterCmd);
    pwVar5 = &_od_fcmd;
    if (off_40B1ECA != (undefined (*) [9])0x0) {
      ppauVar6 = &off_40B1ECA;
      do {
        if (*pwVar5 == (word)*(byte *)(param_1 + 0x25c)) {
          pauVar8 = *ppauVar6;
          puVar7 = (undefined *)&aS;
          goto loc_4078490;
        }
        ppauVar6 = (undefined (**) [9])((int)ppauVar6 + 6);
        pwVar5 = pwVar5 + 3;
      } while (*ppauVar6 != (undefined (*) [9])0x0);
    }
    pauVar8 = (undefined (*) [9])(uint)*(byte *)(param_1 + 0x25c);
    puVar7 = aUnknown0xX;
loc_4078490:
    (*param_3)(puVar7,pauVar8);
  }
  if ((param_2 & 0x4000) != 0) {
    if ((*(word *)(param_1 + 0x24a) & 0xfffe) != 0) {
      uVar2 = 0xf;
      puVar7 = unk_40B1CBC;
      do {
        if (((uint)*(word *)(param_1 + 0x24a) & 1 << (uVar2 & 0x1f)) != 0) {
          (*param_3)(&aS_2,*(undefined4 *)puVar7);
        }
        puVar7 = (undefined *)((int)puVar7 + -8);
        uVar2 = uVar2 - 1;
      } while (0 < (int)uVar2);
    }
    if ((*(word *)(param_1 + 0x24c) & 0xfffe) != 0) {
      uVar2 = 0xf;
      puVar7 = unk_40B1D34;
      do {
        if (((uint)*(word *)(param_1 + 0x24c) & 1 << (uVar2 & 0x1f)) != 0) {
          (*param_3)(&aS_2,*(undefined4 *)puVar7);
        }
        puVar7 = (undefined *)((int)puVar7 + -8);
        uVar2 = uVar2 - 1;
      } while (0 < (int)uVar2);
    }
    if (*(sword *)(param_1 + 0x24e) != 0) {
      uVar2 = 0xf;
      puVar7 = unk_40B1DB4;
      do {
        if (((uint)*(word *)(param_1 + 0x24e) & 1 << (uVar2 & 0x1f)) != 0) {
          (*param_3)(&aS_2,*(undefined4 *)puVar7);
        }
        puVar7 = (undefined *)((int)puVar7 + -8);
        wVar1 = (word)(uVar2 >> 0x10);
        sVar3 = (sword)uVar2 + -1;
        uVar2 = CONCAT22(wVar1,sVar3);
      } while ((sVar3 != -1) || (uVar2 = (uint)wVar1 * 0x10000 - 1, wVar1 != 0));
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2184 start=0x407853c */

undefined4 _od_attn(int param_1,int param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  
  if ((param_4 & 2) != 0) {
    *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) & 0xdfff;
  }
  if ((*(uint *)(param_1 + 0x220) & 0x4000000) == 0) {
    if ((param_4 & 2) == 0) {
      *(undefined2 *)(param_1 + 0x24e) = 0;
      *(undefined2 *)(param_1 + 0x24c) = *(undefined2 *)(param_1 + 0x24e);
      *(undefined2 *)(param_1 + 0x24a) = *(undefined2 *)(param_1 + 0x24c);
      uVar1 = 0;
    }
    else {
      *(byte *)(param_3 + 5) = *(byte *)(param_3 + 5) & 0xfd;
      *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) & 0xdfff;
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x4000000;
      _od_status(param_1,param_2,param_3,0x2000,6);
      *(undefined *)(param_1 + 0x26d) = *(undefined *)(param_1 + 0x267);
      *(undefined *)(param_1 + 0x26e) = *(undefined *)(param_1 + 0x268);
      *(undefined2 *)(param_1 + 0x24e) = 0;
      *(undefined2 *)(param_1 + 0x24c) = *(undefined2 *)(param_1 + 0x24e);
      *(undefined2 *)(param_1 + 0x24a) = *(undefined2 *)(param_1 + 0x24c);
      *(undefined *)(param_1 + 0x268) = 9;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = _od_fsm(param_1,param_2,(int)*(char *)(param_1 + 0x268));
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2185 start=0x40785f8 */

word _od_status(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  word wVar2;
  char cVar3;
  
  cVar3 = '\0';
  iVar1 = _od_drive_cmd(param_1,param_2,param_4,param_5 & 0xc | 2);
  if (iVar1 == 0) {
    _delay(0x96);
    *(undefined *)(param_3 + 7) = 0;
    *(undefined *)(param_3 + 7) = 0x20;
    wVar2 = (word)(byte)(cVar3 << 4);
    if ((param_5 & 1) != 0) {
      iVar1 = 1;
      do {
        if ((*(byte *)(param_3 + 4) & 1) != 0) {
          if (iVar1 < 0x989681) {
            return *(word *)(param_3 + 8);
          }
          break;
        }
        _delay(1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 0x989681);
      *(undefined *)(param_1 + 599) = 0x3a;
      *(undefined *)(param_1 + 0x260) = 0;
      wVar2 = 0xffff;
    }
  }
  else {
    wVar2 = 0xffff;
  }
  return wVar2;
}
/* GHIDRADEC_FUNCTION index=2186 start=0x40786ba */

undefined4
_od_cmd(word param_1,undefined2 param_2,undefined4 param_3,int param_4,int param_5,
       undefined *param_6,int param_7,int param_8,int param_9,int param_10)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar2 = (sword)(word)(((uint)param_1 << 0x18) >> 0x1b) * 0xda;
  iVar5 = *(int *)(DAT_40c3f32 + iVar2 + 0x44);
  puVar1 = (uint *)(DAT_40c3f32 + iVar2);
  if (param_10 == 0) {
    while ((*puVar1 & 8) != 0) {
      *puVar1 = *puVar1 | 0x40;
      _sleep(puVar1,0x14);
    }
  }
  *puVar1 = 9;
  *(undefined2 *)(DAT_40c3f32 + iVar2 + 0x6a) = param_2;
  if (param_9 == 0) {
    *(word *)(unk_40C3FA0 + iVar2) = *(word *)(unk_40C3FA0 + iVar2) | 0x80;
  }
  if ((param_7 != 0) && ((*(byte *)(param_7 + 7) & 1) != 0)) {
    DAT_40c3f32[iVar2 + 0x6c] = *(undefined *)(param_7 + 8);
    DAT_40c3f32[iVar2 + 0x6d] = *(undefined *)(param_7 + 9);
    *(word *)(unk_40C3FA0 + iVar2) = *(word *)(unk_40C3FA0 + iVar2) | 0x100;
  }
  *(int *)(DAT_40c3f32 + iVar2 + 0x3c) = param_10;
  *(word *)(DAT_40c3f32 + iVar2 + 0x1e) = param_1;
  *(undefined4 *)(DAT_40c3f32 + iVar2 + 0x24) = param_3;
  iVar5 = *(int *)(iVar5 + 0x5c);
  iVar5 = iVar5 * ((param_5 + -1 + iVar5) / iVar5);
  *(int *)(DAT_40c3f32 + iVar2 + 0x14) = iVar5;
  *(int *)(DAT_40c3f32 + iVar2 + 0x20) = param_4;
  if ((param_7 != 0) && (param_4 != 0)) {
    iVar3 = _useracc(param_4,iVar5,0);
    if (iVar3 == 0) {
      return 0xe;
    }
    *puVar1 = *puVar1 | 0x10;
    *(undefined4 *)(DAT_40c3f32 + iVar2 + 0x2c) =
         *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x34);
    *(word *)(*(int *)(DAT_40c3f32 + iVar2 + 0x2c) + 0x2a) =
         *(word *)(*(int *)(DAT_40c3f32 + iVar2 + 0x2c) + 0x2a) | 0x800;
    _vslock(param_4,iVar5);
  }
  _odstrategy(puVar1);
  if (_active_threads == 0) {
    iVar3 = 0;
    do {
      _delay(1);
      if ((*puVar1 & 2) != 0) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 10000000);
    if (iVar3 == 10000000) {
      dword_40C3DA8 = dword_40C3DA8 | 0x200000;
      _odintr(_od_ctrl);
    }
  }
  else {
    _biowait(puVar1);
  }
  *(word *)(unk_40C3FA0 + iVar2) = *(word *)(unk_40C3FA0 + iVar2) & 0xfe7f;
  if ((param_7 != 0) && (param_4 != 0)) {
    _vsunlock(param_4,iVar5,(*puVar1 & 1) != 0);
    *(word *)(*(int *)(DAT_40c3f32 + iVar2 + 0x2c) + 0x2a) =
         *(word *)(*(int *)(DAT_40c3f32 + iVar2 + 0x2c) + 0x2a) & 0xf7ff;
  }
  if ((param_10 == 0) && (*puVar1 = *puVar1 & 0xfffffff7, (*puVar1 & 0x40) != 0)) {
    _wakeup(puVar1);
  }
  if ((*puVar1 & 4) == 0) {
    if (param_8 != 0) {
      *(undefined4 *)(param_8 + 2) = *(undefined4 *)(DAT_40c3f32 + iVar2 + 0x28);
    }
    uVar4 = 0;
  }
  else {
    if (param_6 != (undefined *)0x0) {
      *param_6 = (char)*(undefined2 *)(DAT_40c3f32 + iVar2 + 0x1c);
    }
    uVar4 = 5;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=2187 start=0x40788ec */

int _od_read_label(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined2 uVar2;
  word wVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  undefined4 uVar12;
  int iVar13;
  sword sVar14;
  int iVar15;
  undefined *puVar16;
  int *unaff_A3;
  undefined *puVar17;
  undefined *puVar18;
  undefined auStack_32 [7];
  char acStack_2b [39];
  
  uVar12 = _od_readlabel;
  bVar5 = false;
  if (_od_empty < 1) {
    puVar17 = _od_vol;
    do {
      if (-1 < *(sword *)(puVar17 + 0xd8)) break;
      puVar17 = puVar17 + 0xda;
    } while (puVar17 < (undefined *)0x40c592e);
    if (puVar17 == (undefined *)0x40c592e) {
                    /* WARNING: Subroutine does not return */
      _panic(aOdOutOfVols);
    }
  }
  else {
    puVar17 = DAT_40c3dee + _od_empty * 0xda;
  }
  _disksort_free(puVar17);
  _bzero(puVar17,0xda);
  _disksort_init(puVar17);
  *(undefined2 *)(puVar17 + 0xd8) = 0x8020;
  *(sword *)(puVar17 + 0xd2) = (sword)(param_2 + -0x40c3e18 >> 5);
  *(undefined **)(param_2 + 8) = puVar17;
  uVar6 = _od_errmsg_filter;
  iVar13 = ((int)(puVar17 + -0x40c3ec8) * -0x2593f69b >> 1) << 3;
  if (_inhibit_label_errs != 0) {
    _od_errmsg_filter = 9;
  }
  iVar4 = *(char *)(param_2 + 0x1c) * 0x30;
  *(undefined **)(puVar17 + 0xb6) = _od_drive_info + iVar4;
  iVar10 = *(char *)(param_2 + 0x1c) * 6;
  *(int **)(puVar17 + 0xba) = (int *)((int)&_od_more_info + iVar10);
  iVar15 = 0;
  do {
    piVar7 = _od_label;
    iVar9 = *(int *)(DAT_40b1f72 + iVar15 * 4 + iVar4);
    puVar16 = puVar17;
    if (iVar9 != -1) {
      *(int **)(puVar17 + 0xae) = _od_label;
      if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(aOdNoLabelAlloc);
      }
      _bzero(piVar7,0x1c48);
      *(int *)(puVar17 + 0xbe) =
           *(int *)((int)&_od_more_info + iVar10) *
           (int)*(sword *)((int)&_od_more_info + iVar10 + 4);
      piVar7[0x17] = *(int *)(DAT_40b1f72 + iVar4 + 0x10);
      piVar7[0x19] = (int)*(sword *)((int)&_od_more_info + iVar10 + 4);
      piVar7[0x18] = 1;
      *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 0x2000;
      if ((*(byte *)(param_2 + 0x18) & 0x40) == 0) {
        _od_spinup = 1;
        iVar8 = _od_cmd(iVar13,0xf0,0,0,0,acStack_2b,0,0,0,0);
        if (iVar8 == 5) {
          if ((byte)(acStack_2b[0] - 0x3aU) < 2) {
            *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) & 0xdfff;
            if (param_3 != 0) {
              *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x1000;
            }
            goto loc_4078DFE;
          }
          if ((acStack_2b[0] == '\x14') || (acStack_2b[0] == '\b')) {
            *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) & 0xdfff;
            *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x1000;
            goto loc_4078DFE;
          }
        }
        if (iVar8 != 0) {
          *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) & 0xdfff;
          *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x1000;
          goto loc_4078E00;
        }
      }
      *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x5000;
      iVar8 = _od_cmd(iVar13,2,iVar9,uVar12,0x1c48,acStack_2b,0,0,0,0);
      unaff_A3 = piVar7;
      if (iVar8 == 0) {
        iVar8 = _od_validate_label(uVar12,iVar9);
        if (iVar8 == 0) {
          _bcopy(uVar12,piVar7,0x1c48);
          if ((*piVar7 != 0x4e655854) && (1 < *piVar7 + 0x9b93a9ceU)) {
            iVar8 = 0x16;
            goto loc_4078E00;
          }
          if ((int)*(sword *)((int)&_od_more_info + iVar10 + 4) == piVar7[0x19]) {
            *(undefined4 *)(puVar17 + 0xb2) = _od_bad_block;
            if (((*piVar7 == 0x4e655854) || (*piVar7 == 0x646c5632)) ||
               (iVar8 = _od_cmd(iVar13,2,iVar9 + 4,_od_bad_block,0x3000,0,0,0,0,0), iVar8 == 0)) {
              iVar8 = piVar7[0x19] * piVar7[0x18] * piVar7[0x1a];
              *(int *)(puVar17 + 0xc2) = iVar8;
              if (*piVar7 == 0x4e655854) {
                iVar8 = iVar8 / piVar7[0x19] >> 1;
              }
              else {
                iVar8 = iVar8 >> 2;
              }
              *(int *)(puVar17 + 0xca) = iVar8;
              *(undefined4 *)(puVar17 + 0xc6) = _od_bitmap;
              iVar9 = _od_cmd(iVar13,2,piVar7[0x19] + iVar9,_od_bitmap,
                              *(undefined4 *)(puVar17 + 0xca),0,0,0,0,0);
              if (iVar9 == 0) {
                iVar10 = (int)*(sword *)(*(int *)(param_2 + 0x14) + 0xc);
                if (-1 < iVar10) {
                  *(int *)(_dk_bps + iVar10 * 4) =
                       (piVar7[0x1b] * piVar7[0x19] * piVar7[0x17]) / 0x3c;
                }
                if (param_3 == 0) {
                  if (*piVar7 == 0x4e655854) {
                    uVar12 = 1;
                  }
                  else {
                    uVar12 = 3;
                    if (*piVar7 == 0x646c5632) {
                      uVar12 = 2;
                    }
                  }
                  _printf(aDiskLabelSLabe,piVar7 + 3,uVar12);
                  _od_canon_label(param_1,param_2,puVar17);
                }
                puVar16 = _od_vol;
                goto loc_4078CE4;
              }
            }
          }
        }
      }
      else if (_dma_recover_rl != 0) {
        _od_cmd(iVar13,2,0,uVar12,0x400,acStack_2b,0,0,0,0);
      }
    }
    iVar15 = iVar15 + 1;
  } while (iVar15 < 4);
  if ((*(byte *)(param_2 + 0x18) & 0x40) == 0) goto loc_4078DFE;
  *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 0x2000;
  iVar10 = unaff_A3[0x19] * unaff_A3[0x18] * unaff_A3[0x1a];
  *(int *)(puVar17 + 0xc2) = iVar10;
  if (*unaff_A3 == 0x4e655854) {
    iVar10 = iVar10 / unaff_A3[0x19] >> 1;
  }
  else {
    iVar10 = iVar10 >> 2;
  }
  *(int *)(puVar17 + 0xca) = iVar10;
  *(undefined4 *)(puVar17 + 0xb2) = _od_bad_block;
  _bzero(_od_bad_block,0x3000);
  *(undefined4 *)(puVar17 + 0xc6) = _od_bitmap;
  _bzero(_od_bitmap,*(undefined4 *)(puVar17 + 0xca));
  iVar10 = _rtc_get();
  unaff_A3[10] = iVar10;
  unaff_A3[9] = -0x80000000;
  *unaff_A3 = 0x646c5633;
  iVar10 = _od_write_label(puVar17,0);
  if (iVar10 == 0) {
    *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 0x4000;
    goto loc_407901E;
  }
loc_4078DDE:
  iVar8 = 5;
  puVar16 = puVar17;
  goto loc_4078E00;
  while (puVar16 = puVar16 + 0xda, puVar16 < (undefined *)0x40c592e) {
loc_4078CE4:
    if (((puVar16[0xd8] & 0x40) != 0) && (*(int *)(*(int *)(puVar16 + 0xae) + 0x28) == piVar7[10]))
    {
      *(undefined2 *)(puVar17 + 0xd8) = 0;
      *(sword *)(puVar16 + 0xd2) = (sword)(param_2 + -0x40c3e18 >> 5);
      *(undefined **)(param_2 + 8) = puVar16;
      *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) | 0x2000;
      iVar13 = ((int)(puVar16 + -0x40c3ec8) * -0x2593f69b >> 1) << 3;
      bVar5 = true;
      goto loc_407901E;
    }
  }
  iVar15 = _rtc_get();
  iVar10 = piVar7[10];
  piVar7[10] = iVar15;
  *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 0x6000;
  iVar15 = _od_write_label(puVar17,0);
  puVar16 = puVar17;
  if (iVar15 != 0) {
    if (iVar15 != 0x13) goto loc_4078DDE;
    piVar7[10] = iVar10;
    *(word *)(puVar17 + 0xd8) = *(word *)(puVar17 + 0xd8) | 4;
  }
loc_407901E:
  iVar8 = 0;
  if (_od_empty < 1) {
    if ((_od_specific == (undefined *)0x0) ||
       ((*(int *)(puVar16 + 0xae) != 0 && (puVar16 == _od_specific)))) {
      if (!bVar5) {
        iVar13 = (int)(puVar16 + -0x40c3ec8) * -0x2593f69b >> 1;
        _sprintf(auStack_32,&aOdD,iVar13);
        uVar12 = 1;
        if ((puVar16[0xd9] & 4) != 0) {
          uVar12 = 3;
        }
        wVar3 = (sword)iVar13 << 3;
        _vol_notify_dev((int)(sword)(wVar3 | (sword)_od_blk_major << 8),
                        (int)(sword)(wVar3 | (sword)_od_raw_major << 8),&unk_40A62E7,
                        CARRY4(*(uint *)(*(int *)(puVar16 + 0xae) + 0x24),
                               *(uint *)(*(int *)(puVar16 + 0xae) + 0x24)),auStack_32,uVar12);
      }
      goto loc_40792AA;
    }
    uVar2 = *(undefined2 *)(puVar16 + 0xd2);
    _od_cmd(iVar13,0xf6,0,0,0,0,0,0,0,0);
    if (((_rootdev >> 8 != _od_blk_major) ||
        ((unk_40C3FA0[(sword)(word)(((uint)_rootdev << 0x18) >> 0x1b) * 0xda] & 0x20) != 0)) &&
       (_panel_req_port != 0)) {
      _vol_panel_remove(_od_vol_tag);
      _vol_panel_disk_label
                (_od_panel_abort,*(int *)(_od_specific + 0xae) + 0xc,1,uVar2,_od_specific,1,
                 &_od_vol_tag);
      goto loc_4079218;
    }
    iVar15 = 0;
    iVar10 = *(int *)(_od_specific + 0xae);
    puVar18 = aWrongDiskPleas_1;
    puVar17 = _od_specific;
  }
  else {
    if (!bVar5) {
      _od_empty = 0;
      _wakeup(&_od_empty);
loc_40792AA:
      if (_od_alert_present == 0) {
        _alert_done();
      }
      else {
        _vol_panel_remove(_od_vol_tag);
        _od_alert_abort = 0;
        _od_alert_present = 0;
      }
      _od_spinup = 0;
      if (_od_requested == 1) {
        _od_specific = (undefined *)0x0;
        _od_requested = 2;
        _wakeup(&_od_requested);
      }
      iVar13 = _hz;
      if (_hz < 0) {
        iVar13 = _hz + 1;
      }
      _od_runout_time = (undefined2)(iVar13 >> 1);
      _od_runout = 0;
      if ((!bVar5) && ((puVar16[0xd8] & 0x40) != 0)) {
        _od_label = (int *)0x0;
        _wakeup(&_od_label);
      }
      sVar14 = (sword)_od_blk_major;
      for (iVar13 = _mounttab; iVar13 != 0; iVar13 = *(int *)(iVar13 + 0x1c)) {
        if ((((word)(*(word *)(iVar13 + 4) & 0xfff8) ==
              (word)((sword)((int)(puVar16 + -0x40c3ec8) * -0x2593f69b >> 1) << 3 | sVar14 << 8)) &&
            (*(int *)(iVar13 + 10) != 0)) &&
           ((*(word *)(iVar13 + 4) != 0xffff &&
            (iVar10 = *(int *)(*(int *)(iVar13 + 10) + 0x20),
            (*(uint *)(iVar10 + 0xd0) & 0xffff00) == 0x10000)))) {
          *(undefined *)(iVar10 + 0xd1) = 2;
          *(undefined *)(iVar10 + 0xd0) = 1;
        }
      }
      *(word *)(param_2 + 0x18) = *(word *)(param_2 + 0x18) | 0x8000;
      *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) & 0xffbf;
      _od_drive_start(puVar16);
      _od_ctrl_start(*(undefined4 *)(&DAT_40c3e28 + (uint)*(word *)(puVar16 + 0xd2) * 4));
      goto loc_4078FB0;
    }
    uVar2 = *(undefined2 *)(puVar16 + 0xd2);
    _od_cmd(iVar13,0xf6,0,0,0,0,0,0,0,0);
    if (((_rootdev >> 8 != _od_blk_major) ||
        ((unk_40C3FA0[(sword)(word)(((uint)_rootdev << 0x18) >> 0x1b) * 0xda] & 0x20) != 0)) &&
       (_panel_req_port != 0)) {
      iVar10 = _od_empty * 0xda;
      _vol_panel_remove(_od_vol_tag);
      _vol_panel_disk_num(_od_panel_abort,_od_empty + -1,1,uVar2,DAT_40c3dee + iVar10,1,&_od_vol_tag
                         );
loc_4079218:
      _od_alert_present = 1;
      goto loc_4078DFE;
    }
    iVar15 = _od_empty + -1;
    iVar10 = *(int *)(puVar16 + 0xae);
    puVar18 = aWrongDiskThatW;
    puVar17 = puVar16;
  }
  _od_alert(aInsertDisk,puVar18,iVar10 + 0xc,(int)(puVar17 + -0x40c3ec8) * -0x2593f69b >> 1,iVar15,0
            ,0,0,0,0);
loc_4078DFE:
  iVar8 = 2;
loc_4078E00:
  if (((puVar16 == _od_vol) && (param_3 == 0)) &&
     ((iVar10 = _strcmp(&_boot_dev,&aOd), iVar10 == 0 &&
      (((unk_40B6904 & 8) == 0 && ((byte_40B606F & 1) == 0)))))) {
    _mon_boot(0);
  }
  if ((*(word *)(puVar16 + 0xd8) & 0x10) != 0) {
    *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) & 0xffef;
    _wakeup(puVar16 + 0xd8);
  }
  _od_cmd(iVar13,0xf6,0,0,0,0,0,0,0,0);
  if (((param_3 != 0) && ((0 < _od_empty || (_od_specific != (undefined *)0x0)))) &&
     ((_alert_key == 0x6e || ((_od_alert_abort != 0 || ((*(byte *)(param_2 + 0x18) & 0x40) != 0)))))
     ) {
    if (_od_empty < 1) {
      if (_od_specific != (undefined *)0x0) {
        while (puVar11 = (uint *)_disksort_first(_od_specific), puVar11 != (uint *)0x0) {
          *(undefined2 *)(puVar11 + 7) = 6;
          uVar1 = *puVar11;
          *puVar11 = uVar1 | 4;
          if ((uVar1 & 2) == 0) {
            _biodone(puVar11);
          }
          _disksort_remove(_od_specific,puVar11);
        }
        *(undefined2 *)(_od_specific + 0xd8) = 0x8008;
        _od_ctrl_start(*(undefined4 *)(param_2 + 0x10));
      }
    }
    else {
      _od_empty = -1;
      _wakeup(&_od_empty);
    }
    if (_od_alert_present == 0) {
      _alert_done();
    }
    else {
      _vol_panel_remove(_od_vol_tag);
      _od_alert_abort = 0;
      _od_alert_present = 0;
    }
    if (_od_requested == 1) {
      _od_specific = (undefined *)0x0;
      _od_requested = 2;
      _wakeup(&_od_requested);
    }
  }
  if (!bVar5) {
    *(undefined2 *)(puVar16 + 0xd8) = 0;
  }
  _od_spinup = 0;
loc_4078FB0:
  if ((*(word *)(puVar16 + 0xd8) & 0x10) != 0) {
    *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) & 0xffef;
    _wakeup(puVar16 + 0xd8);
  }
  *(word *)(puVar16 + 0xd8) = *(word *)(puVar16 + 0xd8) & 0xffdf;
  _od_errmsg_filter = uVar6;
  return iVar8;
}
/* GHIDRADEC_FUNCTION index=2188 start=0x40793fe */

undefined4 _od_write_label(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar5;
  int iVar4;
  undefined4 uVar6;
  int iVar7;
  undefined2 *puVar8;
  int iVar9;
  word wStack_14;
  undefined auStack_a [5];
  char cStack_5;
  
  uVar6 = 1;
  piVar1 = *(int **)(param_1 + 0xae);
  if ((*piVar1 == 0x4e655854) || (*piVar1 == 0x646c5632)) {
    wStack_14 = 0x1c48;
    puVar8 = (undefined2 *)((int)piVar1 + 0x1c46);
  }
  else {
    wStack_14 = 0x230;
    puVar8 = (undefined2 *)((int)piVar1 + 0x22e);
  }
  iVar3 = ((param_1 + -0x40c3ec8) * -0x2593f69b >> 1) << 3;
  if (piVar1[9] < 0) {
    for (iVar7 = 3; *(int *)(*(int *)(param_1 + 0xb6) + 0x18 + iVar7 * 4) == -1; iVar7 = iVar7 + -1)
    {
    }
    iVar9 = iVar7 + 1;
  }
  else {
    iVar7 = 0;
    iVar9 = 4;
  }
  if (iVar7 < iVar9) {
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0xb6) + 0x18 + iVar7 * 4);
      if (iVar2 != -1) {
        if (-1 < *(sword *)(param_1 + 0xd8)) {
          return 0x14;
        }
        if (((*(sword *)(piVar1 + 0x1c) == 0) || (iVar2 < *(sword *)(piVar1 + 0x1c))) ||
           (piVar1[0x19] * piVar1[0x18] * piVar1[0x1a] - (int)*(sword *)((int)piVar1 + 0x72) < iVar2
           )) {
          piVar1[1] = iVar2;
          *puVar8 = 0;
          uVar5 = _checksum_16(piVar1,wStack_14 >> 1);
          *puVar8 = uVar5;
          iVar4 = _od_cmd(iVar3,1,iVar2,piVar1,0x1c48,&cStack_5,0,0,0,param_2);
          if ((iVar4 == 0) &&
             ((((*piVar1 == 0x4e655854 || (*piVar1 == 0x646c5632)) ||
               (iVar4 = _od_cmd(iVar3,1,iVar2 + 4,*(undefined4 *)(param_1 + 0xb2),0x3000,&cStack_5,0
                                ,0,0,param_2), iVar4 == 0)) &&
              (iVar4 = _od_cmd(iVar3,1,piVar1[0x19] + iVar2,*(undefined4 *)(param_1 + 0xc6),
                               *(undefined4 *)(param_1 + 0xca),&cStack_5,0,0,0,param_2), iVar4 == 0)
              ))) {
            if ((piVar1[9] < 0) && (_dma_recover_wl != 0)) {
              uVar6 = _kalloc(0x400);
              _od_cmd(iVar3,2,iVar2,uVar6,0x400,auStack_a,0,0,0,param_2);
              _kfree(uVar6,0x400);
            }
            uVar6 = 0;
          }
          else if ((iVar4 == 5) && (cStack_5 == '\x13')) {
            return 0x13;
          }
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar9);
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=2189 start=0x40795fa */

void _od_update(void)

{
  uint uVar1;
  uint *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  puVar4 = _od_vol;
  puVar3 = unk_40C3FA0;
  do {
    if ((*(word *)puVar3 & 0xf004) == 0xf000) {
      puVar2 = (uint *)(puVar4 + 0x6a);
      while ((*puVar2 & 8) != 0) {
        *puVar2 = *puVar2 | 0x40;
        _sleep(puVar2,0x14);
      }
      *puVar2 = 8;
      *(word *)puVar3 = *(word *)puVar3 | 0x400;
      _od_write_label(puVar4,0x7f);
      if ((*(word *)puVar3 & 0x200) != 0) {
        _wakeup(puVar4);
      }
      *(word *)puVar3 = *(word *)puVar3 & 63999;
      uVar1 = *puVar2;
      *puVar2 = uVar1 & 0xfffffff7;
      if ((uVar1 & 0x40) != 0) {
        _wakeup(puVar2);
      }
    }
    if (((sword)*(word *)puVar3 < 0) &&
       (*(word *)puVar3 = *(word *)puVar3 & 0xefff, (*(word *)puVar3 & 0x800) != 0)) {
      _od_cmd((int)(puVar4 + -0x40c3ec8) * 0x69b02594,0xf6,0,0,0,0,0,0,0,0);
    }
    puVar3 = (undefined *)((int)puVar3 + 0xda);
    puVar4 = puVar4 + 0xda;
  } while (puVar4 < (undefined *)0x40c592e);
  return;
}
/* GHIDRADEC_FUNCTION index=2190 start=0x4079720 */

void _od_update_thread(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)(_active_threads + 0x4c);
  uVar2 = *(undefined4 *)(_active_threads + 0x54);
  *(undefined4 *)(_active_threads + 0x4c) = 0x1f;
  *(undefined4 *)(_active_threads + 0x54) = 0x1f;
  _od_update();
  *(undefined4 *)(_active_threads + 0x4c) = uVar1;
  *(undefined4 *)(_active_threads + 0x54) = uVar2;
  _od_update_time = 0;
  _thread_terminate(_active_threads);
  _thread_halt_self();
  return;
}
/* GHIDRADEC_FUNCTION index=2191 start=0x4079784 */

undefined4 _od_validate_label(int *param_1,int param_2)

{
  int iVar1;
  sword sVar2;
  word wVar3;
  sword sVar4;
  sword *psVar5;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if ((iVar1 == 0x4e655854) || (iVar1 == 0x646c5632)) {
      wVar3 = 0x1c48;
      psVar5 = (sword *)((int)param_1 + 0x1c46);
    }
    else {
      wVar3 = 0x230;
      psVar5 = (sword *)((int)param_1 + 0x22e);
    }
    if (param_1[1] == param_2) {
      sVar2 = *psVar5;
      *psVar5 = 0;
      sVar4 = _checksum_16(param_1,wVar3 >> 1);
      if (sVar2 != sVar4) {
        return 0xffffffff;
      }
      return 0;
    }
  }
  return 0xffffffff;
}
/* GHIDRADEC_FUNCTION index=2192 start=0x40797f2 */

void _od_spiral(void)

{
  word *pwVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar2 = _od_drive;
  puVar3 = unk_40C3E36;
  pwVar1 = &word_40C3E30;
  do {
    if ((*puVar3 == -1) && ((*(byte *)(*(int *)((int)puVar2 + 8) + 0xd8) & 0x20) != 0)) {
      _od_cmd((*(int *)((int)puVar2 + 8) + -0x40c3ec8) * 0x69b02594 & 0xfffffff8,0xf3,0,0,0,0,0,0,0,
              0);
      *pwVar1 = *pwVar1 & 0xdfff;
      *puVar3 = '\0';
    }
    puVar3 = puVar3 + 0x20;
    pwVar1 = pwVar1 + 0x10;
    puVar2 = (undefined *)((int)puVar2 + 0x20);
  } while (puVar2 < &_od_empty);
  _thread_terminate(_active_threads);
  _thread_halt_self();
  return;
}
/* GHIDRADEC_FUNCTION index=2193 start=0x4079892 */

void _od_creq_timeout(int param_1)

{
  *(undefined2 *)(param_1 + 10) = 0;
  _wakeup(_od_creq_timeout);
  return;
}
/* GHIDRADEC_FUNCTION index=2194 start=0x40798ae */

int _odioctl(word param_1,int param_2,uint *param_3)

{
  uint uVar1;
  sword sVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined4 uStack_2c;
  int iStack_28;
  uint uStack_24;
  uint uStack_20;
  undefined auStack_1c [8];
  int *piStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  
  uVar4 = (param_1 & 0xff) >> 3;
  iVar5 = uVar4 * 0xda;
  uVar1 = *param_3;
  if (param_2 == 0x2000640f) {
loc_40799D6:
    iVar5 = _od_lock(param_2);
    return iVar5;
  }
  if (param_2 < 0x20006410) {
    if (param_2 == -0x7ff39bf2) {
      uStack_c = param_3[1];
      uStack_8 = param_3[2];
      uStack_10 = uVar1;
      iVar5 = _vm_map_pageable(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),uVar1,uStack_c,
                               uStack_8);
      if (uStack_8 == 0) {
        _od_make_free_pages();
        return iVar5;
      }
      return iVar5;
    }
    if (param_2 < -0x7ff39bf1) {
      if (param_2 == -0x7ffb9bf4) {
        iVar5 = _suser();
        if (iVar5 != 0) {
          _od_dbug = *param_3;
          if ((_od_dbug & 0x1000000) != 0) {
            byte_40C3DF7 = byte_40C3DF7 & 0xbf;
            return 0;
          }
          byte_40C3DF7 = byte_40C3DF7 | 0x40;
          return 0;
        }
        goto loc_4079EE4;
      }
    }
    else {
      if (param_2 == 0x20006407) {
        iVar5 = _suser();
        if (iVar5 != 0) {
          _bzero(&_od_stats,0x28);
          return 0;
        }
        goto loc_4079EE4;
      }
      if (param_2 == 0x20006408) {
        _copyoutmsg(&_od_stats,uVar1,0x28);
        return 0;
      }
    }
  }
  else {
    if (param_2 == 0x4004640b) {
      *param_3 = _od_dbug;
      return 0;
    }
    if (param_2 < 0x4004640c) {
      if (param_2 == 0x20006410) goto loc_40799D6;
    }
    else {
      if (param_2 == 0x40046411) {
        puVar9 = _od_vol;
        do {
          if (-1 < *(sword *)(puVar9 + 0xd8)) break;
          puVar9 = puVar9 + 0xda;
        } while (puVar9 < (undefined *)0x40c592e);
        if (puVar9 == (undefined *)0x40c592e) {
          *param_3 = 0xffffffff;
          return 0;
        }
        *param_3 = (int)(puVar9 + -0x40c3ec8) * -0x2593f69b >> 1;
        return 0;
      }
      if (param_2 == 0x40306405) {
        iVar5 = (char)(&byte_40C3E34)[(uint)*(word *)(_od_vol + iVar5 + 0xd2) * 0x20] * 0x30;
        *param_3 = *(uint *)(_od_drive_info + iVar5);
        param_3[1] = *(uint *)(_od_drive_info + iVar5 + 4);
        param_3[2] = *(uint *)(_od_drive_info + iVar5 + 8);
        param_3[3] = *(uint *)(DAT_40b1f66 + iVar5);
        param_3[4] = *(uint *)(DAT_40b1f66 + iVar5 + 4);
        param_3[5] = *(uint *)(DAT_40b1f66 + iVar5 + 8);
        param_3[6] = *(uint *)(DAT_40b1f66 + iVar5 + 0xc);
        param_3[7] = *(uint *)(DAT_40b1f66 + iVar5 + 0x10);
        param_3[8] = *(uint *)(DAT_40b1f66 + iVar5 + 0x14);
        param_3[9] = *(uint *)(DAT_40b1f66 + iVar5 + 0x18);
        param_3[10] = *(uint *)(DAT_40b1f66 + iVar5 + 0x1c);
        param_3[0xb] = *(uint *)(DAT_40b1f66 + iVar5 + 0x20);
        return 0;
      }
    }
  }
  if ((0x1e < uVar4) || (-1 < *(sword *)(unk_40C3FA0 + iVar5))) {
    return 6;
  }
  piStack_14 = *(int **)(_od_vol + iVar5 + 0xae);
  if (param_2 == 0x20006402) {
    if ((unk_40C3FA0[iVar5] & 0x40) == 0) {
      return 6;
    }
    uVar11 = *(undefined4 *)(_od_vol + iVar5 + 0xca);
    piVar10 = *(int **)(_od_vol + iVar5 + 0xc6);
loc_4079D46:
    iVar5 = _copyoutmsg(piVar10,uVar1,uVar11);
    return iVar5;
  }
  if (0x20006402 < param_2) {
    if (param_2 != 0x20006412) {
      if (param_2 < 0x20006413) {
        if (param_2 != 0x20006403) {
          return 0x19;
        }
        iVar8 = _suser();
        if (iVar8 != 0) {
          if (*(int *)(_od_vol + iVar5 + 0xc6) == 0) {
            return 0;
          }
          iVar8 = _copyinmsg(uVar1,*(int *)(_od_vol + iVar5 + 0xc6),
                             *(undefined4 *)(_od_vol + iVar5 + 0xca));
          *(word *)(unk_40C3FA0 + iVar5) = *(word *)(unk_40C3FA0 + iVar5) | 0x1000;
          if (_od_update_time == 0) {
            _od_update_time = 1;
            return iVar8;
          }
          return iVar8;
        }
      }
      else if (param_2 == 0x20006413) {
        iVar8 = _suser();
        if (iVar8 != 0) {
          if (*(int *)(_od_vol + iVar5 + 0xb2) == 0) {
            return 0;
          }
          iVar8 = _copyinmsg(uVar1,*(int *)(_od_vol + iVar5 + 0xb2),0x3000);
          *(word *)(unk_40C3FA0 + iVar5) = *(word *)(unk_40C3FA0 + iVar5) | 0x1000;
          _od_canon_remap(_od_ctrl);
          if (_od_update_time == 0) {
            _od_update_time = 1;
            return iVar8;
          }
          return iVar8;
        }
      }
      else {
        if (param_2 != 0x20006415) {
          return 0x19;
        }
        iVar8 = _suser();
        if ((iVar8 != 0) ||
           (*(sword *)(_od_vol + iVar5 + 0xce) == *(sword *)(*(int *)(_active_u + 0x1a) + 6))) {
          _od_sync((int)(sword)((sword)((int)(uVar4 * 2) >> 1) << 3 | (sword)_od_blk_major << 8));
          iVar5 = _od_cmd((int)(sword)param_1,0xf1,0,0,0,0,0,0,0,0);
          return iVar5;
        }
      }
      goto loc_4079EE4;
    }
    if ((unk_40C3FA0[iVar5] & 0x40) == 0) {
      return 6;
    }
    uVar11 = 0x3000;
    piVar10 = *(int **)(_od_vol + iVar5 + 0xb2);
    goto loc_4079D46;
  }
  if (param_2 == 0x20006400) {
    if ((unk_40C3FA0[iVar5] & 0x40) == 0) {
      return 6;
    }
    if (piStack_14[9] < 0) {
      return 6;
    }
    uVar11 = 0x1c48;
    piVar10 = piStack_14;
    goto loc_4079D46;
  }
  if (param_2 < 0x20006401) {
    if (param_2 != -0x3faf9bfc) {
      return 0x19;
    }
    puVar3 = param_3 + 4;
    if (*(char *)puVar3 != -0xf) {
      iVar8 = _suser();
      if (iVar8 == 0) goto loc_4079EE4;
      if (*(char *)puVar3 != -0xf) goto loc_4079E02;
    }
    if ((*(sword *)(_od_vol + iVar5 + 0xce) == *(sword *)(*(int *)(_active_u + 0x1a) + 6)) ||
       (iVar5 = _suser(), iVar5 != 0)) {
loc_4079E02:
      _microtime(auStack_1c);
      iVar5 = _od_cmd((int)(sword)param_1,*(undefined *)puVar3,*(undefined4 *)((int)param_3 + 0x12),
                      param_3[1],*param_3,param_3 + 0xc,puVar3,param_3 + 0xc,0,0);
      _microtime(&uStack_24);
      _timevalsub(&uStack_24,auStack_1c);
      param_3[2] = uStack_24;
      param_3[3] = uStack_20;
      if (*(sword *)((int)param_3 + 0x1a) != 0) {
        uStack_2c = 0;
        iStack_28 = (uint)*(word *)((int)param_3 + 0x1a) * 1000;
        _timevalfix(&uStack_2c);
        _us_timeout(_od_creq_timeout,puVar3,&uStack_2c,0);
        sVar2 = *(sword *)((int)param_3 + 0x1a);
        while (sVar2 != 0) {
          _sleep(_od_creq_timeout,0x14);
          sVar2 = *(sword *)((int)param_3 + 0x1a);
        }
        return iVar5;
      }
      return iVar5;
    }
loc_4079EE4:
    return (int)*(char *)(dword_40B57D4 + 100);
  }
  iVar8 = _suser();
  if (iVar8 == 0) goto loc_4079EE4;
  iVar8 = *(int *)(_od_vol + iVar5 + 0xca);
  if (piStack_14 == (int *)0x0) {
    iVar6 = _kmem_alloc_wired(_kernel_map,&piStack_14,0x1c48);
    if (iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aOdSlabelAlloc);
    }
    iVar6 = 0;
  }
  else {
    iVar6 = piStack_14[10];
  }
  iVar7 = _copyinmsg(uVar1,piStack_14,0x1c48);
  if (iVar7 != 0) {
    return iVar7;
  }
  *(int **)(_od_vol + iVar5 + 0xae) = piStack_14;
  if (*(int *)(_od_vol + iVar5 + 0xb2) == 0) {
    iVar7 = _kmem_alloc_wired(_kernel_map,_od_vol + iVar5 + 0xb2,0x3000);
    if (iVar7 != 0) {
      return 0xc;
    }
    _bzero(*(undefined4 *)(_od_vol + iVar5 + 0xb2),0x3000);
  }
  *(int *)(_od_vol + iVar5 + 0xbe) = piStack_14[0x19] * **(int **)(_od_vol + iVar5 + 0xba);
  iVar7 = piStack_14[0x19] * piStack_14[0x18] * piStack_14[0x1a];
  *(int *)(_od_vol + iVar5 + 0xc2) = iVar7;
  if (*piStack_14 == 0x4e655854) {
    iVar7 = iVar7 / piStack_14[0x19] >> 1;
  }
  else {
    iVar7 = iVar7 >> 2;
  }
  if (*(int *)(_od_vol + iVar5 + 0xc6) != 0) {
    if (iVar7 == iVar8) goto loc_4079C5E;
    _kmem_free(_kernel_map,*(int *)(_od_vol + iVar5 + 0xc6),0x10000);
  }
  *(int *)(_od_vol + iVar5 + 0xca) = iVar7;
  iVar8 = _kmem_alloc_wired(_kernel_map,_od_vol + iVar5 + 0xc6,0x10000);
  if (iVar8 != 0) {
    return 0xc;
  }
  _bzero(*(undefined4 *)(_od_vol + iVar5 + 0xc6),*(undefined4 *)(_od_vol + iVar5 + 0xca));
loc_4079C5E:
  if (iVar6 == 0) {
    iVar6 = _rtc_get();
  }
  piStack_14[10] = iVar6;
  *(byte *)(piStack_14 + 9) = *(byte *)(piStack_14 + 9) & 0x7f;
  iVar8 = _od_write_label(_od_vol + iVar5,0);
  if (iVar8 == 0) {
    *(word *)(unk_40C3FA0 + iVar5) = *(word *)(unk_40C3FA0 + iVar5) | 0x4000;
    (&word_40C3E30)[(uint)*(word *)(_od_vol + iVar5 + 0xd2) * 0x10] =
         (&word_40C3E30)[(uint)*(word *)(_od_vol + iVar5 + 0xd2) * 0x10] | 0x8000;
    _od_canon_remap(_od_ctrl);
    return 0;
  }
  return 5;
}
/* GHIDRADEC_FUNCTION index=2195 start=0x4079f4c */

uint _od_canon_remap(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  sword *psStack_8;
  
  uVar1 = _od_errmsg_filter;
  uVar6 = 0;
  _od_errmsg_filter = 9;
  _kmem_alloc_wired(_kernel_map,&psStack_8,0x400);
  iVar2 = _od_cmd(((param_3 + -0x40c3ec8) * -0x2593f69b >> 1) << 3,2,
                  (0x4d50 - **(int **)(param_3 + 0xba)) *
                  (int)*(sword *)(*(int **)(param_3 + 0xba) + 1),psStack_8,0x400,0,0,0,0,0);
  if ((((iVar2 == 0) && (*psStack_8 == -0x1fe)) && (uVar6 = (uint)(word)psStack_8[1], param_4 == 0))
     && (iVar2 = 0, uVar6 != 0)) {
    iVar5 = 4;
    do {
      pbVar7 = (byte *)(iVar5 + (int)psStack_8);
      iVar4 = (uint)pbVar7[3] +
              (int)*(sword *)(*(int *)(param_3 + 0xba) + 4) *
              CONCAT31((int3)((uint)pbVar7[1] * 0x100 + (uint)*pbVar7 * 0x10000 >> 8),pbVar7[2]);
      if ((iVar4 != 0) && (*(int *)(param_3 + 0xbe) <= iVar4)) {
        iVar3 = _od_locate_alt(param_1,param_2,param_3,iVar4 - *(int *)(param_3 + 0xbe),iVar4);
        if (iVar3 == -1) {
          iVar4 = _od_remap(param_1,param_2,param_3,iVar4);
          if (iVar4 == 0) break;
        }
      }
      iVar5 = iVar5 + 4;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)uVar6);
  }
  _kmem_free(_kernel_map,psStack_8,0x400);
  _od_errmsg_filter = uVar1;
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=2196 start=0x407a09c */

void _od_canon_label(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  sword *psStack_12;
  undefined auStack_e [2];
  undefined uStack_c;
  undefined auStack_b [2];
  undefined uStack_9;
  undefined auStack_8 [2];
  undefined uStack_6;
  
  uVar1 = _od_errmsg_filter;
  _od_errmsg_filter = 9;
  _kmem_alloc_wired(_kernel_map,&psStack_12,0x400);
  iVar2 = _od_cmd(((param_3 + -0x40c3ec8) * -0x2593f69b >> 1) << 3,2,
                  (0x4d6a - **(int **)(param_3 + 0xba)) *
                  (int)*(sword *)(*(int **)(param_3 + 0xba) + 1),psStack_12,0x400,0,0,0,0,0);
  if ((iVar2 == 0) && (*psStack_12 == -0xff)) {
    _bcopy(psStack_12 + 0x1b,auStack_e,2);
    uStack_c = 0x2f;
    _bcopy(psStack_12 + 0x1c,auStack_b,2);
    uStack_9 = 0x2f;
    _bcopy(psStack_12 + 0x1a,auStack_8,2);
    uStack_6 = 0;
    uVar3 = _od_canon_remap(param_1,param_2,param_3,1);
    _printf(aLotSSerialSDat,psStack_12 + 9,psStack_12 + 0x11,auStack_e,uVar3 & 0xffff,
            (int)(sword)(uVar3 >> 0x10));
  }
  _kmem_free(_kernel_map,psStack_12,0x400);
  _od_errmsg_filter = uVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=2197 start=0x407a1dc */

undefined4 _od_lock(int param_1)

{
  word wVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  sword sVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  char *pcVar8;
  undefined4 *puVar9;
  
  wVar1 = *(word *)(*(int *)(*(int *)(_active_threads + 0xc) + 0x34) + 0x30);
  if (((param_1 == 0x2000640f) && (_od_lock_pid != 0)) ||
     ((param_1 == 0x20006410 && (wVar1 != _od_lock_pid)))) {
    uVar2 = 0x10;
  }
  else {
    _od_lock_pid = wVar1;
    if (param_1 == 0x20006410) {
      puVar7 = _od_drive;
      do {
        if ((((*(word *)((int)puVar7 + 0x18) & 0xc000) == 0xc000) &&
            (iVar4 = *(int *)((int)puVar7 + 8), iVar4 != 0)) &&
           ((*(byte *)(iVar4 + 0xd8) & 0x20) != 0)) {
          sVar5 = (sword)_od_blk_major;
          iVar3 = _getnewbuf_count();
          if (2 < iVar3) {
            _update((int)(sword)((sword)((iVar4 + -0x40c3ec8) * -0x2593f69b >> 1) << 3 | sVar5 << 8)
                    ,0xfffffff8);
          }
        }
        puVar7 = (undefined *)((int)puVar7 + 0x20);
      } while (puVar7 < &_od_empty);
    }
    puVar9 = _all_psets;
    if ((undefined4 **)_all_psets != &_all_psets) {
      do {
        for (puVar6 = (undefined4 *)puVar9[0x4c]; puVar6 != puVar9 + 0x4c;
            puVar6 = (undefined4 *)puVar6[6]) {
          pcVar8 = (char *)(*(int *)(puVar6[3] + 0x30) + 8);
          iVar4 = _strcmp(pcVar8,*(int *)(_kernel_task + 0x30) + 8);
          if (((iVar4 != 0) && (iVar4 = _strcmp(pcVar8,&aBiod), iVar4 != 0)) &&
             (((uint)_od_lock_pid != (int)*(sword *)(*(int *)(puVar6[3] + 0x34) + 0x30) &&
              (*pcVar8 != '\0')))) {
            if (param_1 == 0x2000640f) {
              _thread_suspend(puVar6);
            }
            else {
              _thread_resume(puVar6);
            }
          }
        }
        puVar6 = puVar9 + 0x50;
        puVar9 = (undefined4 *)*puVar6;
      } while ((undefined4 **)*puVar6 != &_all_psets);
    }
    if (param_1 == 0x2000640f) {
      _mfs_cache_clear();
    }
    if (param_1 == 0x20006410) {
      _od_lock_pid = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2198 start=0x407a368 */

void _od_make_free_pages(void)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _page_size * 2 * _vm_page_free_target;
  _kmem_alloc_wired(_kernel_map,&uStack_8,iVar1);
  _kmem_free(_kernel_map,uStack_8,iVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=2199 start=0x407a3ac */

void _od_unlock_check(sword param_1)

{
  if (_od_lock_pid == param_1) {
    _od_lock(0x20006410);
  }
  return;
}

