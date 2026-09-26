/* GHIDRADEC_FUNCTION index=2200 start=0x407a3f6 */

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
/* GHIDRADEC_FUNCTION index=2201 start=0x407a470 */

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
/* GHIDRADEC_FUNCTION index=2202 start=0x407a4fc */

void _od_label_alloc(void)

{
  do {
    if (_od_label == 0) {
      _od_buf_alloc();
    }
    _sleep(&_od_label,0x14);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2203 start=0x407a524 */

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
/* GHIDRADEC_FUNCTION index=2204 start=0x407a5c8 */

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
/* GHIDRADEC_FUNCTION index=2205 start=0x407a67e */

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
/* GHIDRADEC_FUNCTION index=2206 start=0x407a704 */

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
/* GHIDRADEC_FUNCTION index=2207 start=0x407a796 */

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
/* GHIDRADEC_FUNCTION index=2208 start=0x407a962 */

void _od_alert(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
              undefined4 param_9,undefined4 param_10)

{
  _alert(0x3c,8,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  _printf(aLPressNKeyIfDi);
  return;
}
/* GHIDRADEC_FUNCTION index=2209 start=0x407a9b0 */

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
/* GHIDRADEC_FUNCTION index=2210 start=0x407aa4c */

void _od_panel_abort(undefined4 param_1)

{
  _od_alert_abort = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2211 start=0x407aaca */

void _oddump(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2212 start=0x407aad2 */

undefined4 _odsize(void)

{
  return 0x400;
}
/* GHIDRADEC_FUNCTION index=2213 start=0x407bb06 */

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
/* GHIDRADEC_FUNCTION index=2214 start=0x407bd9c */

void _scsi_init(void)

{
  if (dword_40B4FDA == 0) {
    dword_40B4FD6 = &dword_40B4FD2;
    dword_40B4FD2 = &dword_40B4FD2;
    dword_40B4FDA = 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2215 start=0x407bdc2 */

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
/* GHIDRADEC_FUNCTION index=2216 start=0x407be62 */

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
/* GHIDRADEC_FUNCTION index=2217 start=0x407bfb0 */

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
/* GHIDRADEC_FUNCTION index=2218 start=0x407bff8 */

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
/* GHIDRADEC_FUNCTION index=2219 start=0x407c070 */

void _scsi_docmd(int param_1)

{
  if (_scsi_ndevices == 1) {
    *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) & 0xef;
  }
  (*(code *)**(undefined4 **)(*(int *)(param_1 + 0x18) + 0x14))(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2220 start=0x407c09a */

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
/* GHIDRADEC_FUNCTION index=2221 start=0x407c1b4 */

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
/* GHIDRADEC_FUNCTION index=2222 start=0x407c246 */

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
/* GHIDRADEC_FUNCTION index=2223 start=0x407c2a8 */

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
/* GHIDRADEC_FUNCTION index=2224 start=0x407c48a */

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

