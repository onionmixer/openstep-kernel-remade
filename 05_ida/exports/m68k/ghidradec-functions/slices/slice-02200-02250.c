/* GHIDRADEC_FUNCTION index=2200 start=0x407a3cc */

void _odminphys(int param_1)

{
  int iVar1;
  
  iVar1 = 0x10000;
  if (_dma_chip == 0x139) {
    iVar1 = 0x2000;
  }
  if (iVar1 < *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = iVar1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2201 start=0x407a3f6 */

void _od_zero_fill(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  word wVar6;
  sword sVar7;
  
  iVar1 = *(int *)(param_2 + 0xae);
  uVar5 = *(uint *)(param_1 + 0x214);
  *(int *)(param_1 + 0x244) = param_3;
  param_3 = param_3 + -1;
  if (param_3 != -1) {
    do {
      for (iVar2 = *(int *)(iVar1 + 0x5c); iVar2 != 0; iVar2 = iVar2 - iVar4) {
        uVar3 = _pmap_resident_extract(*(undefined4 *)(param_1 + 0x218),uVar5);
        iVar4 = _m68k_page_size - (_m68k_page_mask & uVar5);
        if (iVar2 < iVar4) {
          iVar4 = iVar2;
        }
        _bzero(uVar3,iVar4);
        uVar5 = iVar4 + uVar5;
      }
      wVar6 = (word)((uint)param_3 >> 0x10);
      sVar7 = (sword)param_3 + -1;
      param_3 = CONCAT22(wVar6,sVar7);
    } while ((sVar7 != -1) || (param_3 = (uint)wVar6 * 0x10000 + -1, wVar6 != 0));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2202 start=0x407a470 */

void _od_buf_alloc(void)

{
  int iVar1;
  
  iVar1 = _kmem_alloc_wired(_kernel_map,&_od_label,0x1c48);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aOdLabelAlloc);
  }
  iVar1 = _kmem_alloc_wired(_kernel_map,&_od_bad_block,0x3000);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aOdBadBlockAllo);
  }
  iVar1 = _kmem_alloc_wired(_kernel_map,&_od_bitmap,0x10000);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aOdBitmapAlloc);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2203 start=0x407a4fc */

void _od_label_alloc(void)

{
  do {
    if (_od_label == 0) {
      _od_buf_alloc();
    }
    _sleep(&_od_label,0x14);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2204 start=0x407a524 */

void _od_try_attach(void)

{
  int iVar1;
  word *pwVar2;
  undefined *puVar3;
  
  _od_try_th = _active_threads;
  do {
    puVar3 = _od_drive;
    pwVar2 = &word_40C3E30;
    do {
      if ((*pwVar2 & 0x5000) == 0x1000) {
        *pwVar2 = *pwVar2 | 0x800;
        _odattach(*(undefined4 *)((int)puVar3 + 0x14));
        *pwVar2 = *pwVar2 & 0xf7ff;
      }
      pwVar2 = pwVar2 + 0x10;
      puVar3 = (undefined *)((int)puVar3 + 0x20);
    } while (puVar3 < &_od_empty);
    _assert_wait(0,0);
    iVar1 = _hz;
    if (_od_requested != 0) {
      if (_hz < 0) {
        iVar1 = _hz + 1;
      }
      iVar1 = iVar1 >> 1;
    }
    _thread_set_timeout(iVar1);
    _thread_block();
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2205 start=0x407a5c8 */

undefined4 _od_make_empty(void)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)0x0;
  puVar1 = _od_drive;
  do {
    if ((*(word *)((int)puVar1 + 0x18) & 0x5000) == 0x1000) break;
    if (((*(word *)((int)puVar1 + 0x18) & 0x4000) != 0) &&
       ((piVar2 == (int *)0x0 || (*(int *)puVar1 < *piVar2)))) {
      piVar2 = (int *)puVar1;
    }
    puVar1 = (undefined *)((int)puVar1 + 0x20);
  } while (puVar1 < &_od_empty);
  if ((undefined4 *)puVar1 == &_od_empty) {
    if (piVar2 == (int *)0x0) {
      return 0xffffffff;
    }
    if ((*(byte *)(piVar2 + 6) & 4) != 0) {
      return 0;
    }
    iVar3 = (int)(sword)((sword)((piVar2[2] + -0x40c3ec8) * -0x2593f69b >> 1) << 3 |
                        (sword)_od_blk_major << 8);
    _od_sync(iVar3);
    _od_cmd(iVar3,0xf1,0,0,0,0,0,0,0,0);
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=2206 start=0x407a67e */

void _od_sync(word param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = _getnewbuf_count();
  if (2 < iVar2) {
    _update((int)(sword)param_1,0xfffffff8);
    for (iVar2 = _mounttab; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1c)) {
      if (((((*(word *)(iVar2 + 4) & 0xfff8) == param_1) && (*(int *)(iVar2 + 10) != 0)) &&
          (*(word *)(iVar2 + 4) != 0xffff)) &&
         (iVar1 = *(int *)(*(int *)(iVar2 + 10) + 0x20),
         (*(uint *)(iVar1 + 0xd0) & 0xffff00) == 0x20000)) {
        *(undefined *)(iVar1 + 0xd1) = 1;
        _sbupdate(iVar2);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2207 start=0x407a704 */

void _od_request(void)

{
  _od_req_th = _active_threads;
  do {
    _od_requested = 0;
    do {
      _sleep(&_od_requested,0x14);
    } while (_od_requested == 0);
    if (_od_spinup == 0) {
      _od_request_vol();
    }
    while (_od_requested == 1) {
      _sleep(&_od_requested,0x14);
    }
    if (_od_alert_present == 0) {
      _alert_done();
    }
    else {
      _vol_panel_remove(_od_vol_tag);
      _od_alert_abort = 0;
      _od_alert_present = 0;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2208 start=0x407a796 */

byte _od_request_vol(void)

{
  int iVar1;
  undefined *puVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  char cVar6;
  bool bVar7;
  char cVar8;
  bool bVar9;
  byte bVar10;
  bool bVar11;
  
  cVar3 = (_od_spl & 0x10) != 0;
  if (_od_empty < 1) {
    puVar2 = _od_specific;
    if (_od_specific == (undefined *)0x0) {
      puVar2 = _od_vol;
      do {
        if ((puVar2[0xd9] & 0x40) != 0) break;
        puVar2 = puVar2 + 0xda;
      } while (puVar2 < (undefined *)0x40c592e);
      cVar3 = puVar2 < (undefined *)0x40c592e;
      bVar9 = SBORROW4((int)puVar2,0x40c592e);
      bVar5 = (int)(puVar2 + -0x40c592e) < 0;
      bVar7 = true;
      bVar11 = (bool)cVar3;
      if (puVar2 == (undefined *)0x40c592e) goto loc_407A954;
    }
    iVar1 = _od_make_empty();
    bVar9 = false;
    bVar5 = iVar1 < 0;
    bVar7 = iVar1 == 0;
    bVar11 = false;
    if (iVar1 < 1) goto loc_407A954;
    _od_specific = puVar2;
    if (((_rootdev >> 8 != _od_blk_major) ||
        ((unk_40C3FA0[(sword)(word)(((uint)_rootdev << 0x18) >> 0x1b) * 0xda] & 0x20) != 0)) &&
       (_panel_req_port != 0)) {
      cVar3 = 0xfffffff3 < *(uint *)(puVar2 + 0xae);
      _vol_panel_disk_label
                (_od_panel_abort,*(uint *)(puVar2 + 0xae) + 0xc,1,0,puVar2,0,&_od_vol_tag);
      _od_alert_present = 1;
      bVar5 = false;
      bVar7 = false;
      bVar9 = false;
      bVar11 = false;
      goto loc_407A954;
    }
    cVar3 = 0xfffffff3 < *(uint *)(puVar2 + 0xae);
    iVar1 = *(uint *)(puVar2 + 0xae) + 0xc;
    cVar4 = iVar1 < 0;
    cVar6 = iVar1 == 0;
    cVar8 = '\0';
    bVar10 = 0;
    _od_alert(aInsertDisk,aPleaseInsertDi,iVar1,(int)(puVar2 + -0x40c3ec8) * -0x2593f69b >> 1,0,0,0,
              0,0,0);
    bVar10 = cVar3 << 4 | cVar4 << 3 | cVar6 << 2 | cVar8 << 1 | bVar10;
  }
  else {
    if (((_rootdev >> 8 == _od_blk_major) &&
        ((unk_40C3FA0[(sword)(word)(((uint)_rootdev << 0x18) >> 0x1b) * 0xda] & 0x20) == 0)) ||
       (_panel_req_port == 0)) {
      cVar3 = _od_empty == 0;
      iVar1 = _od_empty + -1;
      cVar4 = iVar1 < 0;
      cVar6 = iVar1 == 0;
      cVar8 = '\0';
      bVar10 = 0;
      _od_alert(aInsertDisk,aPleaseInsertNe,iVar1,0,0,0,0,0,0,0);
    }
    else {
      cVar3 = 0xfbf3c211 < (uint)(_od_empty * 0xda);
      _vol_panel_disk_num(_od_panel_abort,_od_empty + -1,1,0,DAT_40c3dee + _od_empty * 0xda,0,
                          &_od_vol_tag);
      _od_alert_present = 1;
      cVar4 = '\0';
      cVar6 = '\0';
      cVar8 = '\0';
      bVar10 = 0;
    }
    bVar10 = cVar3 << 4 | cVar4 << 3 | cVar6 << 2 | cVar8 << 1 | bVar10;
  }
  cVar3 = (_od_spl & 0x10) != 0;
  bVar5 = false;
  bVar7 = bVar10 == 0;
  bVar9 = false;
  bVar11 = false;
loc_407A954:
  return cVar3 << 4 | bVar5 << 3 | bVar7 << 2 | bVar9 << 1 | bVar11;
}
/* GHIDRADEC_FUNCTION index=2209 start=0x407a962 */

void _od_alert(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
              undefined4 param_9,undefined4 param_10)

{
  _alert(0x3c,8,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  _printf(aLPressNKeyIfDi);
  return;
}
/* GHIDRADEC_FUNCTION index=2210 start=0x407a9b0 */

void _od_eject(void)

{
  int iVar1;
  undefined *puVar2;
  uint auStack_24 [8];
  
  _nvram_check(auStack_24);
  puVar2 = _od_drive;
  do {
    if (((*(word *)((int)puVar2 + 0x18) & 0x5000) == 0x5000) &&
       ((iVar1 = (*(int *)((int)puVar2 + 8) + -0x40c3ec8) * -0x2593f69b >> 1, iVar1 != 0 ||
        ((auStack_24[0] & 0x4003c01) != 0x1800)))) {
      iVar1 = iVar1 << 3;
      _od_sync(iVar1);
      _od_cmd(iVar1,0xf6,0,0,0,0,0,0,0,0);
    }
    puVar2 = (undefined *)((int)puVar2 + 0x20);
  } while (puVar2 < &_od_empty);
  return;
}
/* GHIDRADEC_FUNCTION index=2211 start=0x407aa4c */

void _od_panel_abort(undefined4 param_1)

{
  _od_alert_abort = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2212 start=0x407aaca */

void _oddump(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2213 start=0x407aad2 */

undefined4 _odsize(void)

{
  return 0x400;
}
/* GHIDRADEC_FUNCTION index=2214 start=0x407bb06 */

void _scminphys(int param_1)

{
  int iVar1;
  
  iVar1 = 0x10000;
  if (_dma_chip == 0x139) {
    iVar1 = 0x2000;
  }
  if (iVar1 < *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = iVar1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2215 start=0x407bd9c */

void _scsi_init(void)

{
  if (dword_40B4FDA == 0) {
    dword_40B4FD6 = &dword_40B4FD2;
    dword_40B4FD2 = &dword_40B4FD2;
    dword_40B4FDA = 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2216 start=0x407bdc2 */

qword _scsi_probe(undefined4 param_1,int param_2,undefined4 param_3,undefined param_4)

{
  uint uVar1;
  bool bVar2;
  
  *(undefined4 *)(param_2 + 0x10) = param_1;
  *(undefined4 *)(param_2 + 0x14) = param_3;
  *(undefined *)(param_2 + 0x58) = 7;
  _bzero(param_2 + 0x18,0x40);
  uVar1 = 0;
  do {
    *(undefined *)(uVar1 + 0x18 + param_2 + (uint)*(byte *)(param_2 + 0x58) * 8) = 1;
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 8);
  *(undefined *)(param_2 + 0x5a) = 0;
  *(undefined *)(param_2 + 0x5b) = 0;
  *(undefined *)(param_2 + 0x59) = param_4;
  *(undefined *)(param_2 + 0x60) = 0;
  *(int *)(param_2 + 4) = param_2;
  *(int *)param_2 = param_2;
  bVar2 = &dword_40B4FD2 < dword_40B4FD6;
  if (dword_40B4FD6 == &dword_40B4FD2) {
    dword_40B4FD2 = param_2;
  }
  else {
    dword_40B4FD6[2] = param_2;
  }
  *(undefined4 **)(param_2 + 0xc) = dword_40B4FD6;
  *(int **)(param_2 + 8) = &dword_40B4FD2;
  dword_40B4FD6 = (undefined4 *)param_2;
  return (qword)CONCAT14(bVar2 << 4 | (param_2 < 0) << 3 | (param_2 == 0) << 2,
                         (uint)(byte)((7 < uVar1) << 4 | (param_2 < 0) << 3 | (param_2 == 0) << 2));
}
/* GHIDRADEC_FUNCTION index=2217 start=0x407be62 */

undefined4 _scsi_slave(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  sword sVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  
  sVar4 = 0;
  if (_scsi_sdswlist._0_4_ != 0) {
    puVar6 = _scsi_sdswlist;
    puVar5 = (undefined4 *)_scsi_sdswlist._0_4_;
    do {
      iVar2 = _strcmp(*puVar5,*(undefined4 *)(param_2 + 0x16));
      if (iVar2 == 0) break;
      puVar6 = (undefined *)((int)puVar6 + 4);
      sVar4 = sVar4 + 1;
      puVar5 = *(undefined4 **)puVar6;
    } while (puVar5 != (undefined4 *)0x0);
    if (puVar5 != (undefined4 *)0x0) {
      *(sword *)(param_2 + 0x1c) = sVar4;
      iVar2 = (**(code **)((int)puVar5 + 6))((int)*(sword *)(param_2 + 4));
      *(int *)(iVar2 + 0x18) = param_1;
      *(int *)(iVar2 + 0x10) = param_2;
      *(byte *)(iVar2 + 0x24) = *(byte *)(iVar2 + 0x24) & 0x1f;
      *(undefined4 **)(iVar2 + 0x14) = puVar5;
      if (*(word *)(param_2 + 8) != 0x3f) {
        *(byte *)(iVar2 + 0x1c) = (byte)(((uint)*(word *)(param_2 + 8) << 0x19) >> 0x1d);
        bVar1 = *(byte *)(param_2 + 9) & 7;
        *(byte *)(iVar2 + 0x1d) = bVar1;
        if (*(char *)(param_1 + (uint)*(byte *)(iVar2 + 0x1c) * 8 + 0x18 + (uint)bVar1) != '\0') {
          return 0;
        }
        iVar2 = (**(code **)((int)puVar5 + 10))(iVar2,param_2);
        if (iVar2 != 0) {
          return 1;
        }
        return 0;
      }
      do {
        if (7 < *(byte *)(puVar5 + 1)) {
          return 0;
        }
        *(byte *)(iVar2 + 0x1c) = *(byte *)(puVar5 + 1);
        bVar1 = *(byte *)((int)puVar5 + 5);
        while (bVar1 < 8) {
          *(byte *)(iVar2 + 0x1d) = bVar1;
          *(char *)((int)puVar5 + 5) = *(char *)((int)puVar5 + 5) + '\x01';
          if (*(char *)(param_1 + (uint)*(byte *)(iVar2 + 0x1c) * 8 + 0x18 +
                       (uint)*(byte *)(iVar2 + 0x1d)) == '\0') {
            iVar3 = (**(code **)((int)puVar5 + 10))(iVar2,param_2);
            if (iVar3 != 0) {
              return 1;
            }
            if (*(char *)(iVar2 + 0x4f) == '\x02') {
              *(undefined *)((int)puVar5 + 5) = 8;
            }
            if (*(char *)(iVar2 + 0x4f) == '\a') {
              *(undefined *)(puVar5 + 1) = 8;
              goto loc_407BF82;
            }
          }
          else {
loc_407BF82:
            *(undefined *)((int)puVar5 + 5) = 8;
          }
          bVar1 = *(byte *)((int)puVar5 + 5);
        }
        *(char *)(puVar5 + 1) = *(char *)(puVar5 + 1) + '\x01';
        *(undefined *)((int)puVar5 + 5) = 0;
      } while( true );
    }
  }
  _printf(aNoDriverConfig,*(undefined4 *)(param_2 + 0x16));
  return 0;
}
/* GHIDRADEC_FUNCTION index=2218 start=0x407bfb0 */

void _scsi_attach(int param_1)

{
  _scsi_ndevices = _scsi_ndevices + 1;
  (**(code **)(*(int *)(param_1 + 0x14) + 0xe))(param_1);
  if (dword_40B4FCA == 0) {
    dword_40B4FCE = _hz;
    if (_hz < 0) {
      dword_40B4FCE = _hz + 1;
    }
    dword_40B4FCE = dword_40B4FCE >> 1;
    dword_40B4FCA = 1;
    sub_407C2F4();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2219 start=0x407bff8 */

undefined4 _scsi_dstart(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = param_1[6];
  puVar2 = *(undefined4 **)(*(int *)(iVar1 + 0x10) + 0x1c);
  *puVar2 = param_1;
  param_1[1] = (int)puVar2;
  *param_1 = *(int *)(iVar1 + 0x10) + 0x18;
  *(int **)(*(int *)(iVar1 + 0x10) + 0x1c) = param_1;
  *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) | 0x20;
  if (*(char *)(iVar1 + 0x5a) == '\0') {
    uVar3 = sub_407C04A(iVar1);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2220 start=0x407c070 */

void _scsi_docmd(int param_1)

{
  if (_scsi_ndevices == 1) {
    *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) & 0xef;
  }
  (*(code *)**(undefined4 **)(*(int *)(param_1 + 0x18) + 0x14))(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2221 start=0x407c09a */

void _scsi_cintr(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  piVar2 = *(int **)(param_1[4] + 0x18);
  if (*(char *)((int)param_1 + 0x5a) == '\x01') {
    *(undefined *)((int)param_1 + 0x5a) = 0;
  }
  else {
    *(undefined *)((int)param_1 + 0x5a) = 0;
    switch(*(undefined *)((int)piVar2 + 0x4f)) {
    case :
      break;
    :
                    /* WARNING: Subroutine does not return */
      _panic(aScsiCintrBadSd);
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      iVar1 = *piVar2;
      piVar3 = (int *)piVar2[1];
      if (iVar1 == param_1[4] + 0x18) {
        *(int **)(param_1[4] + 0x1c) = piVar3;
      }
      else {
        *(int **)(iVar1 + 4) = piVar3;
      }
      *piVar3 = iVar1;
      *(byte *)(piVar2 + 9) = *(byte *)(piVar2 + 9) & 0xdf;
      (**(code **)(piVar2[5] + 0x16))(piVar2);
      break;
    case :
      iVar1 = *piVar2;
      piVar3 = (int *)piVar2[1];
      if (iVar1 == param_1[4] + 0x18) {
        *(int **)(param_1[4] + 0x1c) = piVar3;
      }
      else {
        *(int **)(iVar1 + 4) = piVar3;
      }
      *piVar3 = iVar1;
      puVar4 = (undefined4 *)param_1[1];
      if (puVar4 == param_1) {
        *param_1 = piVar2;
      }
      else {
        puVar4[2] = piVar2;
      }
      piVar2[3] = (int)puVar4;
      piVar2[2] = (int)param_1;
      param_1[1] = piVar2;
      *(char *)(param_1 + 0x18) = *(char *)(param_1 + 0x18) + '\x01';
    }
    if (((int *)(param_1[4] + 0x18) != *(int **)(param_1[4] + 0x18)) &&
       (*(char *)((int)param_1 + 0x5a) == '\0')) {
      sub_407C04A(param_1);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2222 start=0x407c1b4 */

int * _scsi_reselect(int *param_1,char param_2,char param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = (int *)*param_1;
  while( true ) {
    if (piVar1 == param_1) {
      return (int *)0x0;
    }
    if ((param_2 == *(char *)(piVar1 + 7)) && (param_3 == *(char *)((int)piVar1 + 0x1d))) break;
    piVar1 = (int *)piVar1[2];
  }
  piVar2 = (int *)piVar1[2];
  piVar3 = (int *)piVar1[3];
  if (piVar2 == param_1) {
    param_1[1] = (int)piVar3;
  }
  else {
    piVar2[3] = (int)piVar3;
  }
  if (piVar3 == param_1) {
    *param_1 = (int)piVar2;
  }
  else {
    piVar3[2] = (int)piVar2;
  }
  iVar4 = param_1[4];
  iVar5 = *(int *)(iVar4 + 0x18);
  if (iVar5 == iVar4 + 0x18) {
    *(int **)(iVar4 + 0x1c) = piVar1;
  }
  else {
    *(int **)(iVar5 + 4) = piVar1;
  }
  *piVar1 = iVar5;
  piVar1[1] = param_1[4] + 0x18;
  *(int **)(param_1[4] + 0x18) = piVar1;
  *(char *)(param_1 + 0x18) = *(char *)(param_1 + 0x18) + -1;
  return piVar1;
}
/* GHIDRADEC_FUNCTION index=2223 start=0x407c246 */

void _scsi_restart(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (puVar1 = (undefined4 *)*param_1; puVar1 != param_1; puVar1 = (undefined4 *)puVar1[2]) {
    puVar2 = (undefined4 *)puVar1[2];
    puVar3 = (undefined4 *)puVar1[3];
    if (puVar2 == param_1) {
      param_1[1] = puVar3;
    }
    else {
      puVar2[3] = puVar3;
    }
    if (puVar3 == param_1) {
      *param_1 = puVar2;
    }
    else {
      puVar3[2] = puVar2;
    }
    *(undefined *)((int)puVar1 + 0x4f) = 5;
    *(byte *)(puVar1 + 9) = *(byte *)(puVar1 + 9) & 0x5f;
    (**(code **)(puVar1[5] + 0x16))(puVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2224 start=0x407c2a8 */

undefined4 _scsi_ioctl(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (param_2 == 0x20006409) {
    (**(code **)(*(int *)(iVar1 + 0x14) + 8))(iVar1,1,aBusReset);
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x14) + 4))(iVar1,param_2,param_3,param_4);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2225 start=0x407c48a */

byte _scsi_timeout(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar2 = param_1 < 0;
  cVar3 = param_1 == 0;
  cVar4 = '\0';
  bVar5 = 0;
  (**(code **)(*(int *)(param_1 + 0x14) + 8))(param_1,0,0);
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=2226 start=0x407c4c0 */

void _scsi_msg(int param_1,undefined param_2,undefined4 param_3)

{
  _printf(aSCDDDSOp0xXSdS,*(undefined *)(param_1 + 0x1e),
          (int)*(sword *)(*(int *)(param_1 + 0x10) + 4),*(undefined *)(param_1 + 0x1c),
          *(undefined *)(param_1 + 0x1d),param_3,param_2,*(undefined *)(param_1 + 0x4f),
          *(byte *)(param_1 + 0x4e) & 0x1e);
  return;
}
/* GHIDRADEC_FUNCTION index=2227 start=0x407c51e */

void _scsi_sensemsg(int param_1,int param_2)

{
  _printf(aSCDDDSenseKey0,*(undefined *)(param_1 + 0x1e),
          (int)*(sword *)(*(int *)(param_1 + 0x10) + 4),*(undefined *)(param_1 + 0x1c),
          *(undefined *)(param_1 + 0x1d),*(byte *)(param_2 + 2) & 0xf,*(undefined *)(param_2 + 0xc))
  ;
  return;
}
/* GHIDRADEC_FUNCTION index=2228 start=0x407ce8c */

undefined4 _sdopen(word param_1,byte param_2)

{
  uint uVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  
  uVar1 = (param_1 & 0xff) >> 3;
  bVar2 = (byte)(1 << (param_1 & 7));
  puVar3 = *(undefined4 **)(unk_40B4FDE + uVar1 * 4);
  if (uVar1 < 0x10) {
    _lock_write(&unk_40B504A);
    if ((puVar3 == (undefined4 *)0x0) || ((puVar3[2] & 0x81) != 0x80)) {
      if ((param_2 & 4) != 0) {
        _lock_done(&unk_40B504A);
        return 0x23;
      }
      if (dword_40B2088 == 0) {
        _lock_done(&unk_40B504A);
        return 6;
      }
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)sub_407E802(uVar1);
        *(undefined4 **)(unk_40B4FDE + uVar1 * 4) = puVar3;
        for (puVar4 = _sd_sdd; puVar4 < _sd_sdd + dword_40B2084 * 0xc2;
            puVar4 = (undefined *)((int)puVar4 + 0xc2)) {
          if (((*(char *)(*(int *)((int)puVar4 + 0xb2) + 1) < '\0') && (*(int *)puVar4 == 0)) &&
             (*(int *)((int)puVar4 + 4) == 0)) goto loc_407CF2C;
        }
        puVar4 = _sd_sdd;
        while( true ) {
          if (_sd_sdd + dword_40B2084 * 0xc2 <= puVar4) {
                    /* WARNING: Subroutine does not return */
            _panic(aSdopenNoRemova);
          }
          if (*(char *)(*(int *)((int)puVar4 + 0xb2) + 1) < '\0') break;
          puVar4 = (undefined *)((int)puVar4 + 0xc2);
        }
loc_407CF2C:
        *puVar3 = puVar4;
      }
      puVar3[2] = puVar3[2] | 0x40;
      _lock_done(&unk_40B504A);
      sub_407CCEE(puVar3,0);
      if ((*(byte *)((int)puVar3 + 0xb) & 1) != 0) {
        return 6;
      }
    }
    else {
      _lock_done(&unk_40B504A);
    }
    *(undefined2 *)((int)puVar3 + 0x16) = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 6);
    if (param_1 >> 8 == dword_40B502A) {
      *(byte *)((int)puVar3 + 0xd) = bVar2 | *(byte *)((int)puVar3 + 0xd);
    }
    else {
      *(byte *)(puVar3 + 3) = bVar2 | *(byte *)(puVar3 + 3);
    }
  }
  else if (uVar1 != 0x10) {
    return 6;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2229 start=0x407d026 */

undefined4 _sdclose(word param_1)

{
  int *piVar1;
  uint uVar2;
  byte bVar3;
  
  uVar2 = (param_1 & 0xff) >> 3;
  piVar1 = *(int **)(unk_40B4FDE + uVar2 * 4);
  if (uVar2 < 0x10) {
    if ((*(int *)(*piVar1 + 8) == 0) ||
       (*(sword *)(*(int *)(*(int *)(*piVar1 + 8) + 0x10) + 0x1a) == 0)) {
      return 6;
    }
    bVar3 = (byte)(1 << (param_1 & 7));
    if (param_1 >> 8 == dword_40B502A) {
      *(byte *)((int)piVar1 + 0xd) = ~bVar3 & *(byte *)((int)piVar1 + 0xd);
    }
    else {
      *(byte *)(piVar1 + 3) = ~bVar3 & *(byte *)(piVar1 + 3);
    }
    if (((*(char *)(piVar1 + 3) == '\0' && *(char *)((int)piVar1 + 0xd) == '\0') &&
        (*(char *)(*(int *)(*piVar1 + 0xb2) + 1) < '\0')) &&
       ((*(byte *)((int)piVar1 + 0xb) & 2) == 0)) {
      sub_407F330(piVar1);
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2230 start=0x407d0b8 */

undefined4 _sdsize(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(unk_40B4FDE + (param_1._3_4_ >> 0x1b) * 4);
  if ((param_1._3_4_ >> 0x1b < 0x10) && (iVar1 != 0)) {
    if ((*(byte *)(iVar1 + 0xb) & 4) == 0) {
      uVar2 = *(undefined4 *)(*(int *)(iVar1 + 0xca) + 4);
    }
    else {
      uVar2 = *(undefined4 *)(*(int *)(iVar1 + 0xd2) + 0x5c);
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2231 start=0x407d0f8 */

undefined4 _sdread(word param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = (param_1 & 0xff) >> 3;
  iVar1 = *(int *)(unk_40B4FDE + uVar2 * 4);
  if ((uVar2 < 0x10) && (iVar1 != 0)) {
    if (((param_1 & 7) == 7) || ((*(byte *)(iVar1 + 0xb) & 4) == 0)) {
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0xca) + 4);
    }
    else {
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0xd2) + 0x5c);
    }
    uVar3 = _physio(_sdstrategy,**(int **)(unk_40B4FDE + uVar2 * 4) + 0x1c,(int)(sword)param_1,1,
                    _scminphys,param_2,uVar3);
  }
  else {
    uVar3 = 6;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2232 start=0x407d182 */

undefined4 _sdwrite(word param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = (param_1 & 0xff) >> 3;
  iVar1 = *(int *)(unk_40B4FDE + uVar2 * 4);
  if ((uVar2 < 0x10) && (iVar1 != 0)) {
    if (((param_1 & 7) == 7) || ((*(byte *)(iVar1 + 0xb) & 4) == 0)) {
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0xca) + 4);
    }
    else {
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0xd2) + 0x5c);
    }
    uVar3 = _physio(_sdstrategy,**(int **)(unk_40B4FDE + uVar2 * 4) + 0x1c,(int)(sword)param_1,0,
                    _scminphys,param_2,uVar3);
  }
  else {
    uVar3 = 6;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2233 start=0x407d20a */

undefined4 _sdstrategy(uint *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar4 = (*(word *)((int)param_1 + 0x1e) & 0xff) >> 3;
  uVar3 = *(word *)((int)param_1 + 0x1e) & 7;
  iVar2 = *(int *)(unk_40B4FDE + uVar4 * 4);
  uVar6 = 0;
  if (((uVar4 == 0x10) || (iVar2 == 0)) || (0x11 < uVar4)) {
loc_407D2A8:
    *(undefined2 *)(param_1 + 7) = 6;
  }
  else {
    iVar5 = *(int *)(iVar2 + 0xd2);
    if ((uint *)(iVar2 + 0x18) == param_1) {
loc_407D306:
      if ((uint *)(iVar2 + 0x18) == param_1) {
        _disksort_enter_tail(iVar2 + 0x60,param_1);
      }
      else {
        _disksort_enter(iVar2 + 0x60,param_1);
      }
      if ((*(uint *)(iVar2 + 8) & 0x300) != 0) {
        return 0;
      }
      uVar6 = sub_407D376(iVar2);
      return uVar6;
    }
    uVar4 = param_1[9];
    param_1[0xe] = uVar4;
    if (((*param_1 & 1) != 0) || ((*(byte *)(iVar2 + 10) & 8) == 0)) {
      if ((*(word *)((int)param_1 + 0x1e) & 7) == 7) {
        uVar3 = **(int **)(iVar2 + 0xca) + 1;
        if ((int)uVar3 < (int)uVar4) {
loc_407D2D8:
          *(undefined2 *)(param_1 + 7) = 0x16;
          goto loc_407D35C;
        }
        if (uVar3 != uVar4) goto loc_407D306;
      }
      else {
        if (((*(byte *)(iVar2 + 0xb) & 4) == 0) || (7 < uVar3)) goto loc_407D2A8;
        piVar1 = (int *)(iVar5 + uVar3 * 0x2e + 0xbe);
        uVar3 = piVar1[1];
        if (((uVar3 == 0) || ((int)uVar4 < 0)) || ((int)uVar3 < (int)uVar4)) goto loc_407D2D8;
        if (uVar3 != uVar4) {
          uVar3 = *piVar1 + param_1[0xe];
          param_1[0xe] = uVar3;
          iVar5 = *(int *)(iVar5 + 0x60) * *(int *)(iVar5 + 100);
          if (0 < iVar5) {
            param_1[0xe] = (int)uVar3 / iVar5;
          }
          goto loc_407D306;
        }
      }
      param_1[10] = param_1[5];
      goto loc_407D362;
    }
    *(undefined2 *)(param_1 + 7) = 0x1e;
  }
loc_407D35C:
  *param_1 = *param_1 | 4;
  uVar6 = 0xffffffff;
loc_407D362:
  _biodone(param_1);
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=2234 start=0x407de86 */

int _sdioctl(undefined8 param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  word wVar5;
  uint uVar6;
  int iVar7;
  undefined2 uVar8;
  sword sVar9;
  uint uVar10;
  undefined *puVar11;
  undefined2 *puVar12;
  char *pcVar13;
  char *pcVar14;
  uint *puStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  iVar7 = (int)param_1;
  piVar3 = *(int **)(unk_40B4FDE + (param_1._3_4_ >> 0x1b) * 4);
  uVar6 = *param_2;
  if (0x10 < param_1._3_4_ >> 0x1b) {
    return 6;
  }
  if (iVar7 == 0x40046411) {
    if (dword_40B2088 == 0) {
      return 0x13;
    }
    uVar6 = 0;
    puVar11 = unk_40B4FDE;
    while ((*(int *)puVar11 != 0 && (*(char *)(*(int *)puVar11 + 0xb) < '\0'))) {
      puVar11 = (undefined *)((int)puVar11 + 4);
      uVar6 = uVar6 + 1;
      if (0xf < (int)uVar6) {
        *param_2 = 0xffffffff;
        return 0;
      }
    }
    *param_2 = uVar6;
    return 0;
  }
  if (piVar3 == (int *)0x0) {
    return 6;
  }
  iVar1 = *piVar3;
  if (iVar7 == 0x20006415) {
    if ((*(byte *)((int)piVar3 + 0xb) & 2) == 0) {
      return 0;
    }
    iVar7 = _suser();
    if ((iVar7 == 0) &&
       (*(sword *)((int)piVar3 + 0x16) != *(sword *)(*(int *)(_active_u + 0x1a) + 6))) {
      return (int)*(char *)(dword_40B57D4 + 100);
    }
    if (*(char *)(*(int *)(*piVar3 + 0xb2) + 1) < '\0') {
      _update((int)(sword)((sword)piVar3[1] << 3 | (sword)dword_40B5026 << 8),0xfffffff8);
      iVar7 = sub_407CD5C(piVar3);
      return iVar7;
    }
    return 0;
  }
  if (0x20006415 < iVar7) {
    if (iVar7 == 0x40046419) {
      *param_2 = **(int **)((int)piVar3 + 0xca) + 1;
      return 0;
    }
    if (iVar7 < 0x4004641a) {
      if (iVar7 == 0x40046417) {
        *param_2 = (*(uint *)((int)piVar3 + 10) & 0x7ffffff) >> 0x1a;
        return 0;
      }
      if (iVar7 == 0x40046418) {
        *param_2 = *(uint *)(*(int *)((int)piVar3 + 0xca) + 4);
        return 0;
      }
    }
    else {
      if (iVar7 == 0x40087305) {
        iVar7 = sub_407E572(piVar3,*(undefined4 *)((int)piVar3 + 0xca),0);
        uVar6 = (*(uint **)((int)piVar3 + 0xca))[1];
        *param_2 = **(uint **)((int)piVar3 + 0xca);
        param_2[1] = uVar6;
        return iVar7;
      }
      if (iVar7 == 0x40306405) {
        _bzero(param_2,0x18);
        puStack_10 = param_2;
        iVar7 = *(int *)(iVar1 + 0xb2);
        pcVar13 = (char *)(iVar7 + 8);
        if (pcVar13 < (char *)(iVar7 + 0x20)) {
          do {
            if (param_2 + 6 <= puStack_10) break;
            *(char *)puStack_10 = *pcVar13;
            puStack_10 = (uint *)((int)puStack_10 + 1);
            pcVar14 = pcVar13 + 1;
            if (*pcVar13 == ' ') {
              cVar4 = *pcVar14;
              while (cVar4 == ' ') {
                pcVar14 = pcVar14 + 1;
                cVar4 = *pcVar14;
              }
            }
            pcVar13 = pcVar14;
          } while (pcVar14 < (char *)(*(int *)(iVar1 + 0xb2) + 0x20));
        }
        while (puStack_10 = (uint *)((int)puStack_10 + -1), *(char *)puStack_10 == ' ') {
          *(undefined *)puStack_10 = 0;
        }
        param_2[10] = *(uint *)(*(int *)((int)piVar3 + 0xca) + 4);
        uVar6 = *(uint *)(*(int *)((int)piVar3 + 0xca) + 4);
        uVar6 = (uVar6 + 0x1c47) / uVar6;
        iVar7 = 3;
        uVar10 = uVar6 * 3;
        do {
          do {
            param_2[iVar7 + 6] = uVar10;
            uVar10 = uVar10 - uVar6;
            wVar5 = (word)((uint)iVar7 >> 0x10);
            sVar9 = (sword)iVar7 + -1;
            iVar7 = CONCAT22(wVar5,sVar9);
          } while (sVar9 != -1);
          iVar7 = (uint)wVar5 * 0x10000 + -1;
        } while (wVar5 != 0);
        param_2[0xb] = *(int *)(*(int *)((int)piVar3 + 0xca) + 4) << 8;
        return 0;
      }
    }
    return 0x16;
  }
  if (iVar7 != -0x3fad8cff) {
    if (iVar7 < -0x3fad8cfe) {
      if (iVar7 != -0x7ffb9be9) {
        return 0x16;
      }
      if (uVar6 == 0) {
        *(word *)((int)piVar3 + 10) = *(word *)((int)piVar3 + 10) & 0xfbff;
      }
      else {
        *(word *)((int)piVar3 + 10) = *(word *)((int)piVar3 + 10) | 0x400;
      }
      piVar3[2] = piVar3[2] & 0xfffffffb;
      return 0;
    }
    if (iVar7 == 0x20006400) {
      if ((*(byte *)((int)piVar3 + 0xb) & 4) == 0) {
        return 6;
      }
      iVar7 = _copyoutmsg(*(undefined4 *)((int)piVar3 + 0xd2),uVar6,0x1c48);
      return iVar7;
    }
    if (iVar7 != 0x20006401) {
      return 0x16;
    }
    iVar7 = _suser();
    if (iVar7 != 0) {
      iVar7 = _copyinmsg(uVar6,*(undefined4 *)((int)piVar3 + 0xd2),0x1c48);
      if (iVar7 != 0) {
        return iVar7;
      }
      piVar2 = *(int **)((int)piVar3 + 0xd2);
      if ((*piVar2 == 0x4e655854) || (*piVar2 == 0x646c5632)) {
        wVar5 = 0x1c48;
        puVar12 = (undefined2 *)((int)piVar2 + 0x1c46);
      }
      else {
        wVar5 = 0x230;
        puVar12 = (undefined2 *)((int)piVar2 + 0x22e);
      }
      uStack_c = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
                 0xfffff;
      if ((((uStack_c ^ *_event_middle) & 0x80000) != 0) &&
         (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
        *_event_high = *_event_high + 1;
      }
      uStack_8 = *_event_high;
      uStack_c = uStack_c | *_event_middle;
      *(uint *)(*(int *)((int)piVar3 + 0xd2) + 0x28) = uStack_c;
      *(undefined4 *)(*(int *)((int)piVar3 + 0xd2) + 4) = 0;
      *puVar12 = 0;
      uVar8 = _checksum_16(*(undefined4 *)((int)piVar3 + 0xd2),wVar5 >> 1);
      *puVar12 = uVar8;
      iVar7 = _sdchecklabel(*(undefined4 *)((int)piVar3 + 0xd2),0);
      if (iVar7 == 0) {
        return 0x16;
      }
      iVar7 = sub_407E4A4(piVar3);
      if (iVar7 != 0) {
        return 5;
      }
      return 0;
    }
loc_407E1CC:
    return (int)*(char *)(dword_40B57D4 + 100);
  }
  iVar7 = _suser();
  if (iVar7 == 0) goto loc_407E1CC;
  if (param_2[5] == 0) {
    puStack_10 = (uint *)0x0;
  }
  else {
    iVar7 = _kmem_alloc_wired(_kernel_map,&puStack_10,param_2[5]);
    if (iVar7 != 0) {
      param_2[7] = 8;
      return 0xc;
    }
    if ((param_2[3] == 1) && (iVar7 = _copyinmsg(param_2[4],puStack_10,param_2[5]), iVar7 != 0)) {
      param_2[7] = 9;
      goto loc_407E278;
    }
  }
  uVar6 = param_2[4];
  param_2[4] = (uint)puStack_10;
  iVar7 = sub_407E678(piVar3,param_2,0);
  param_2[4] = uVar6;
  if ((param_2[3] == 0) && (param_2[0xf] != 0)) {
    iVar7 = _copyoutmsg(puStack_10,uVar6,param_2[0xf]);
  }
loc_407E278:
  if (param_2[5] != 0) {
    _kmem_free(_kernel_map,puStack_10,param_2[5]);
    return iVar7;
  }
  return iVar7;
}
/* GHIDRADEC_FUNCTION index=2235 start=0x407e5de */

undefined4 _sdchecklabel(int *param_1,int param_2)

{
  int iVar1;
  sword sVar2;
  word wVar3;
  sword sVar4;
  sword *psVar5;
  
  iVar1 = *param_1;
  if ((iVar1 == 0x4e655854) || (iVar1 == 0x646c5632)) {
    wVar3 = 0x1c48;
    psVar5 = (sword *)((int)param_1 + 0x1c46);
  }
  else {
    if (iVar1 != 0x646c5633) {
      return 0;
    }
    wVar3 = 0x230;
    psVar5 = (sword *)((int)param_1 + 0x22e);
  }
  if (param_1[1] == param_2) {
    param_1[1] = 0;
    sVar2 = *psVar5;
    *psVar5 = 0;
    sVar4 = _checksum_16(param_1,wVar3 >> 1);
    if (sVar2 == sVar4) {
      *psVar5 = sVar4;
      return 1;
    }
    _printf(aLabelChecksumE,sVar4,sVar2);
  }
  else {
    _printf(aLabelInWrongLo);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2236 start=0x407f3c4 */

undefined4 _sfa_arbitrate(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if ((param_2[4] & 1) == 0) {
    if ((*(int *)(param_1 + 0x1a) != 0) &&
       ((((*(byte *)((int)param_2 + 0x13) & 4) != 0 || ((*(byte *)(param_1 + 0x11) & 1) != 0)) ||
        (*(int *)(param_1 + 0x16) != 0)))) {
      puVar1 = *(undefined4 **)(param_1 + 10);
      if (puVar1 == (undefined4 *)(param_1 + 6)) {
        *puVar1 = param_2;
      }
      else {
        puVar1[2] = param_2;
      }
      param_2[3] = puVar1;
      param_2[2] = param_1 + 6;
      *(undefined4 **)(param_1 + 10) = param_2;
      *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
      if ((*(byte *)((int)param_2 + 0x13) & 4) != 0) {
        *(int *)(param_1 + 0x16) = *(int *)(param_1 + 0x16) + 1;
      }
      return 1;
    }
    *(int *)(param_1 + 0x1a) = *(int *)(param_1 + 0x1a) + 1;
    if ((*(byte *)((int)param_2 + 0x13) & 4) != 0) {
      *(uint *)(param_1 + 0xe) = *(uint *)(param_1 + 0xe) | 1;
    }
    param_2[4] = param_2[4] | 1;
  }
  else if (((param_2[4] & 4) != 0) && ((*(byte *)(param_1 + 0x11) & 1) == 0)) {
                    /* WARNING: Subroutine does not return */
    _panic(aSfaArbitrateOn);
  }
  (*(code *)*param_2)(param_2[1]);
  return 0;
}
/* GHIDRADEC_FUNCTION index=2237 start=0x407f492 */

uint _sfa_relinquish(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  byte bVar6;
  uint uVar7;
  char in_XF;
  bool bVar8;
  
  uVar7 = *(uint *)(param_2 + 0x10);
  if ((uVar7 & 1) != 0) {
    uVar7 = uVar7 & 0xfffffffe;
    *(uint *)(param_2 + 0x10) = uVar7;
    bVar6 = in_XF << 4 | ((int)uVar7 < 0) << 3 | (uVar7 == 0) << 2;
    if (param_3 != 0) {
      *(int *)(param_1 + 0x12) = param_3;
    }
    iVar2 = *(int *)(param_1 + 0x1a);
    *(int *)(param_1 + 0x1a) = iVar2 + -1;
    if ((*(byte *)(param_2 + 0x13) & 4) != 0) {
      *(uint *)(param_1 + 0xe) = *(uint *)(param_1 + 0xe) & 0xfffffffe;
    }
    if (*(char *)(param_1 + 4) == '\0') {
      uVar7 = (uint)(byte)((iVar2 == 0) << 4 | (*(char *)(param_1 + 4) < '\0') << 3 | 4);
    }
    else {
      puVar5 = (undefined4 *)(param_1 + 6);
      puVar1 = (undefined4 *)*puVar5;
      while (uVar7 = (uint)bVar6, puVar5 != puVar1) {
        puVar3 = *(undefined4 **)(param_1 + 6);
        if ((*(byte *)((int)puVar3 + 0x13) & 4) != 0) {
          bVar8 = *(int *)(param_1 + 0x1a) == 0;
          if (!bVar8) {
            return (uint)(byte)((puVar5 < puVar1) << 4 | (*(int *)(param_1 + 0x1a) < 0) << 3 |
                               bVar8 << 2);
          }
        }
        *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + -1;
        *(int *)(param_1 + 0x1a) = *(int *)(param_1 + 0x1a) + 1;
        if ((*(byte *)((int)puVar3 + 0x13) & 4) != 0) {
          *(int *)(param_1 + 0x16) = *(int *)(param_1 + 0x16) + -1;
          *(uint *)(param_1 + 0xe) = *(uint *)(param_1 + 0xe) | 1;
        }
        puVar1 = (undefined4 *)puVar3[2];
        puVar4 = (undefined4 *)puVar3[3];
        if (puVar1 == puVar5) {
          *(undefined4 **)(param_1 + 10) = puVar4;
        }
        else {
          puVar1[3] = puVar4;
        }
        if (puVar4 == puVar5) {
          *puVar5 = puVar1;
        }
        else {
          puVar4[2] = puVar1;
        }
        puVar3[4] = puVar3[4] | 1;
        uVar7 = (*(code *)*puVar3)(puVar3[1]);
        if ((*(byte *)((int)puVar3 + 0x13) & 4) != 0) {
          return uVar7;
        }
        puVar1 = (undefined4 *)*puVar5;
        if (puVar5 == puVar1) {
          return uVar7;
        }
        bVar6 = (puVar5 < puVar1) << 4 | ((int)puVar5 - (int)puVar1 < 0) << 3 |
                SBORROW4((int)puVar5,(int)puVar1) << 1 | puVar5 < puVar1;
        puVar1 = (undefined4 *)*puVar5;
      }
    }
  }
  return uVar7;
}
/* GHIDRADEC_FUNCTION index=2238 start=0x407f584 */

word _sfa_abort(int param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  word wVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  if ((*(byte *)((int)param_2 + 0x13) & 1) == 0) {
    piVar1 = *(int **)(param_1 + 6);
    piVar4 = (int *)(param_1 + 6);
    iVar5 = (int)piVar1 - (int)piVar4;
    while( true ) {
      bVar7 = iVar5 < 0;
      bVar9 = SBORROW4((int)piVar1,(int)piVar4);
      bVar10 = piVar1 < piVar4;
      bVar8 = true;
      if (piVar1 == piVar4) break;
      if (param_2 == piVar1) {
        piVar2 = (int *)piVar1[2];
        piVar1 = (int *)piVar1[3];
        if (piVar2 == piVar4) {
          *(int **)(param_1 + 10) = piVar1;
        }
        else {
          piVar2[3] = (int)piVar1;
        }
        if (piVar1 == piVar4) {
          *piVar4 = (int)piVar2;
        }
        else {
          piVar1[2] = (int)piVar2;
        }
        bVar3 = *(byte *)(param_1 + 4);
        bVar10 = bVar3 == 0;
        bVar9 = SBORROW1(bVar3,'\x01');
        *(byte *)(param_1 + 4) = bVar3 - 1;
        bVar7 = (int)((uint)(byte)(bVar3 - 1) << 0x18) < 0;
        bVar8 = (*(byte *)((int)param_2 + 0x13) & 4) == 0;
        if (!bVar8) {
          iVar5 = *(int *)(param_1 + 0x16);
          bVar10 = iVar5 == 0;
          bVar9 = SBORROW4(iVar5,1);
          iVar5 = iVar5 + -1;
          *(int *)(param_1 + 0x16) = iVar5;
          bVar7 = iVar5 < 0;
          bVar8 = iVar5 == 0;
        }
        break;
      }
      piVar1 = (int *)piVar1[2];
      iVar5 = (int)piVar1 - (int)piVar4;
    }
    wVar6 = (word)(byte)(bVar10 << 4 | bVar7 << 3 | bVar8 << 2 | bVar9 << 1 | bVar10);
  }
  else {
    wVar6 = _sfa_relinquish(param_1,param_2,param_3);
  }
  return wVar6;
}
/* GHIDRADEC_FUNCTION index=2239 start=0x407f70e */

undefined4 _sgopen(byte param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (uint)param_1 * 0x42;
  if ((param_1 < 4) && (*(int *)(_sg_sgd + iVar1) != 0)) {
    if (_sg_sgd[iVar1 + 0x16] == '\0') {
      sub_407F682(*(int *)(_sg_sgd + iVar1));
      _sg_sgd[iVar1 + 0x16] = 1;
      _sg_sgd[iVar1 + 0x17] = 0;
      _scsi_ndevices = _scsi_ndevices + 1;
      uVar2 = 0;
    }
    else {
      uVar2 = 0x10;
    }
  }
  else {
    uVar2 = 6;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2240 start=0x407f76a */

undefined4 _sgclose(byte param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  iVar1 = (uint)param_1 * 0x42;
  piVar2 = (int *)(_sg_sgd + iVar1);
  if ((param_1 < 4) && (_sg_sgd[iVar1 + 0x16] != '\0')) {
    _sg_sgd[iVar1 + 0x16] = 0;
    iVar1 = *piVar2;
    if (*(byte *)(iVar1 + 0x1c) != 0xff) {
      pcVar3 = (char *)(*(int *)(iVar1 + 0x18) + (uint)*(byte *)(iVar1 + 0x1c) * 8 + 0x18 +
                       (uint)*(byte *)(iVar1 + 0x1d));
      *pcVar3 = *pcVar3 + -1;
      *(undefined *)(*piVar2 + 0x1c) = 0xff;
      *(undefined *)(*piVar2 + 0x1d) = 0xff;
    }
    _scsi_ndevices = _scsi_ndevices + -1;
    uVar4 = 0;
  }
  else {
    uVar4 = 6;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=2241 start=0x407fb84 */

int _sgioctl(byte param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = (sword)(word)param_1 * 0x42;
  puVar3 = (undefined4 *)(_sg_sgd + iVar1);
  iVar2 = 0;
  if (_sg_sgd[iVar1 + 0x16] == '\0') {
    param_3[7] = 0xb;
    iVar2 = 0xd;
  }
  else if (param_2 == 0x20007302) {
    _sg_sgd[iVar1 + 0x17] = 1;
  }
  else {
    if (param_2 < 0x20007303) {
      if (param_2 == -0x7ffd8d00) {
        iVar1 = sub_407FC78(puVar3,param_3);
        return iVar1;
      }
      if (param_2 == -0x3fad8cff) {
        iVar1 = sub_407FD2C(puVar3,param_3);
        return iVar1;
      }
    }
    else {
      if (param_2 == 0x20007304) {
        iVar1 = _suser();
        if (iVar1 == 0) {
          return (int)*(char *)(dword_40B57D4 + 100);
        }
        iVar1 = _scsi_ioctl(*puVar3,0x20006409,0,0);
        return iVar1;
      }
      if (param_2 < 0x20007304) {
        _sg_sgd[iVar1 + 0x17] = 0;
        return 0;
      }
      if (param_2 == 0x40047307) {
        *param_3 = (int)(char)_sg_sgd[iVar1 + 0x17];
        return 0;
      }
    }
    iVar2 = 0x16;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2242 start=0x407ff14 */

void _snd_device_init(int param_1)

{
  bool bVar1;
  undefined2 uStack_24;
  undefined uStack_22;
  byte bStack_21;
  
  if ((param_1 == 0) && (_vol_r == 0xffffffff)) {
    _nvram_check(&uStack_24);
    _vol_r = (CONCAT31(CONCAT21(uStack_24,uStack_22),bStack_21) & 0x3ffffff) >> 0x14;
    _vol_l = (CONCAT11(uStack_22,bStack_21) & 0x3ff) >> 4;
    dword_40B5088 = 0xffffffff;
    dword_40B508C = 0xffffffff;
    _gpflags = 0;
    bVar1 = (bStack_21 & 8) == 0;
    if (!bVar1) {
      _gpflags = 0x10;
    }
    dword_40B5080 = (uint)bVar1;
    bVar1 = (bStack_21 & 4) == 0;
    if (!bVar1) {
      _gpflags = _gpflags | 8;
    }
    dword_40B5084 = (uint)bVar1;
    sub_40800CC();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2243 start=0x407ffc0 */

void _snd_device_set_parms(uint param_1)

{
  if ((param_1 & 2) == 0) {
    _gpflags = _gpflags | 0x10;
  }
  else {
    _gpflags = _gpflags & 0xffffffef;
  }
  if ((param_1 & 1) == 0) {
    _gpflags = _gpflags & 0xfffffff7;
  }
  else {
    _gpflags = _gpflags | 8;
  }
  if (_gpflags != byte_40C6CED) {
    sub_40800CC();
    sub_4080388();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2244 start=0x4080038 */

uint _snd_device_get_parms(void)

{
  uint uVar1;
  
  uVar1 = (_gpflags & 0xf) >> 3;
  if ((_gpflags & 0x10) == 0) {
    uVar1 = uVar1 | 2;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2245 start=0x4080062 */

void _snd_device_set_volume(uint param_1)

{
  _vol_l = 0x2b - ((param_1 & 0xffff) >> 8);
  _vol_r = 0x2b - (param_1 & 0xff);
  sub_40800CC();
  sub_4080388();
  return;
}
/* GHIDRADEC_FUNCTION index=2246 start=0x40800a2 */

uint _snd_device_get_volume(void)

{
  return 0x2bU - _vol_r | (0x2b - _vol_l) * 0x100;
}
/* GHIDRADEC_FUNCTION index=2247 start=0x408036e */

void _snd_device_vol_set(void)

{
  _callout_dispatch(4,sub_40800CC,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2248 start=0x40803ea */

void _snd_device_vol_save(void)

{
  _callout_dispatch(4,sub_4080388,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2249 start=0x4080404 */

void _snd_dev_intr(void)

{
  _printf(aSounddspSndDev);
  _mon_csr_and(0xffffff7f);
  _mon_csr_or(0x20);
  _mon_csr_and(0xfffffff7);
  _mon_csr_or(2);
  _mon_send(3,0);
  _mon_send(7,0);
  _mon_send(0xc4,0xff);
  return;
}

