/* GHIDRADEC_FUNCTION index=2500 start=0x409382c */

void _nmi(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
         undefined4 param_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined6 *puVar4;
  uint uVar5;
  
  bVar1 = false;
  bVar2 = false;
  if ((_dma_chip == 0x139) || ((*(uint *)(_slot_id + 0x2200020) & 1) == 0)) {
    uVar5 = *(uint *)(_slot_id + 0x200e008);
    *(byte *)(_slot_id + 0x200e001) = *(byte *)(_slot_id + 0x200e001) | 0x10;
    if (-1 < (char)uVar5) {
      if (((byte)(uVar5 >> 8) & 0x18) == 0x18) {
        bVar1 = true;
      }
      else if (((uVar5 & 0xffff) >> 8 & 8) == 0) {
        bVar2 = true;
      }
    }
  }
  else {
    *(undefined4 *)(_slot_id + 0x2200020) = 0;
    bVar1 = true;
  }
  iVar3 = _slot_id;
  if ((_dma_chip != 0x139) && ((*_intrstat & 0x40000000) != 0)) {
    *(undefined4 *)(_slot_id + 0x2200004) = 0;
    *(undefined4 *)(iVar3 + 0x2200004) = 0;
    uVar5 = (uint)(*(int *)(iVar3 + 0x2200008) - (iVar3 + 0x4000000)) /
            (uint)(0x8000000 / _num_regions);
    puVar4 = &aFront;
    if ((uVar5 & 1) != 0) {
      puVar4 = (undefined6 *)&aBack;
    }
    uVar5 = uVar5 & 0xfffffffe;
    _printf(aParityErrorAtA,*(undefined4 *)(iVar3 + 0x2200008),uVar5,uVar5 | 1,puVar4);
                    /* WARNING: Subroutine does not return */
    _panic(aParityError);
  }
  if (bVar1) {
    _mini_mon(&aNmi,aNmiMiniMonitor,param_1,param_2,param_3,param_4,param_5);
  }
  else if (bVar2) {
    _mini_mon(&aRestart,aRestartPowerOf);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2501 start=0x4093e4a */

void _nmi_prf(undefined4 param_1)

{
  _prf(param_1,&stack0x00000008,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2502 start=0x4093e66 */

void _softint_sched(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _callout_dispatch(param_1,param_2,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=2503 start=0x4093e80 */

uint _callout_dispatch(uint param_1,code *param_2,uint param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  byte bVar11;
  
  puVar4 = _softint_free;
  if (5 < param_1) {
    _printf(aCalloutDispatc,param_1,param_2,param_3);
                    /* WARNING: Subroutine does not return */
    _panic(aCalloutDispatc_0);
  }
  if (param_1 == 5) {
    uVar6 = (*param_2)(param_3);
  }
  else {
    piVar1 = (int *)(_softint_head + param_1 * 4);
    for (puVar2 = (undefined4 *)*piVar1; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2
        ) {
      if (param_2 == (code *)puVar2[1]) {
        uVar6 = puVar2[2];
        cVar10 = param_3 < uVar6;
        cVar9 = SBORROW4(param_3,uVar6);
        cVar7 = (int)(param_3 - uVar6) < 0;
        cVar8 = '\x01';
        bVar11 = cVar10;
        if (param_3 == uVar6) goto loc_4093FAA;
      }
    }
    if (_softint_free == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(aOutOfSoftints);
    }
    puVar2 = (undefined4 *)(_softint_tail + param_1 * 4);
    if (*piVar1 == 0) {
      puVar5 = (undefined4 *)*_softint_free;
      *puVar2 = _softint_free;
      _softint_free = puVar5;
      *piVar1 = (int)puVar4;
      if (param_1 == 2) {
        _vidInterruptEnable(_softint_run,2);
      }
    }
    else {
      puVar5 = (undefined4 *)*_softint_free;
      *(undefined4 **)*puVar2 = _softint_free;
      _softint_free = puVar5;
      *puVar2 = puVar4;
    }
    *puVar4 = 0;
    puVar4[1] = param_2;
    puVar4[2] = param_3;
    if (param_1 == 3) {
      cVar9 = '\0';
      bVar11 = 0;
      bVar3 = *(byte *)(_slot_id_bmap + 0x2008000) | 2;
      *(byte *)(_slot_id_bmap + 0x2008000) = bVar3;
      cVar7 = (int)((uint)bVar3 << 0x18) < 0;
      cVar8 = bVar3 == 0;
      cVar10 = '\0';
    }
    else if ((int)param_1 < 4) {
      cVar10 = 1 < param_1;
      cVar9 = SBORROW4(1,param_1);
      cVar7 = (int)(1 - param_1) < 0;
      cVar8 = param_1 == 1;
      bVar11 = cVar10;
      if ((int)param_1 < 2) {
        cVar9 = '\0';
        bVar11 = 0;
        cVar7 = (int)param_1 < 0;
        cVar8 = param_1 == 0;
        if (!(bool)cVar7) {
          cVar10 = (param_1 + 1 >> 8 & 1) != 0;
          uVar6 = (param_1 + 1) * 0x1000000 | *_scr2;
          *_scr2 = uVar6;
          cVar7 = (int)uVar6 < 0;
          cVar8 = uVar6 == 0;
          cVar9 = '\0';
          bVar11 = 0;
        }
      }
    }
    else {
      cVar10 = 4 < param_1;
      cVar9 = SBORROW4(4,param_1);
      cVar7 = (int)(4 - param_1) < 0;
      if (param_1 == 4) {
        cVar7 = '\0';
        cVar8 = '\x01';
        cVar9 = '\0';
        bVar11 = 0;
        _callout_dispatch(0,_thread_wakeup,_softint_thread);
      }
      else {
        cVar8 = '\0';
        bVar11 = cVar10;
      }
    }
loc_4093FAA:
    uVar6 = (uint)(byte)(cVar10 << 4 | cVar7 << 3 | cVar8 << 2 | cVar9 << 1 | bVar11);
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=2504 start=0x4093fb8 */

undefined8 _callout_remove(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined *puVar6;
  undefined *puVar7;
  char in_XF;
  
  iVar3 = 0;
  puVar7 = _softint_tail;
  puVar6 = _softint_head;
  do {
    piVar2 = *(int **)puVar6;
    piVar5 = *(int **)puVar6;
    while (piVar1 = piVar2, piVar1 != (int *)0x0) {
      if ((param_1 == piVar1[1]) && (param_2 == piVar1[2])) {
        if (piVar1 == *(int **)puVar6) {
          *(int *)puVar6 = *piVar1;
          piVar5 = (int *)0x0;
        }
        else {
          *piVar5 = *piVar1;
        }
        if (piVar1 == *(int **)puVar7) {
          *(int **)puVar7 = piVar5;
        }
        *piVar1 = (int)_softint_free;
        uVar4 = 1;
        _softint_free = piVar1;
        goto loc_4094034;
      }
      piVar5 = piVar1;
      piVar2 = (int *)*piVar1;
    }
    puVar7 = (undefined *)((int)puVar7 + 4);
    puVar6 = (undefined *)((int)puVar6 + 4);
    iVar3 = iVar3 + 1;
    if (5 < iVar3) {
      uVar4 = 0;
loc_4094034:
      return CONCAT44(uVar4,(int)(sword)(word)(byte)(in_XF << 4 | (param_2 < 0) << 3 |
                                                    (param_2 == 0) << 2));
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2505 start=0x409403e */

void _softint_th(void)

{
  do {
    do {
      _softint_run(4);
    } while (dword_40C957C != 0);
    _thread_sleep(_softint_thread,0,1);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2506 start=0x4094080 */

void _softint_run(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int unaff_D2;
  int *piVar6;
  code *unaff_D3;
  int *piVar7;
  int *piVar8;
  
  if (_nmi_big != 0) {
    _nmi_big = 0;
    _callout_dispatch(4,_km_big,0);
  }
  switch(param_1) {
  case :
  case :
    *_scr2 = ~((param_1 + 1) * 0x1000000) & *_scr2;
  case :
  case :
    piVar7 = (int *)(_softint_head + param_1 * 4);
    while( true ) {
      piVar6 = (int *)*piVar7;
      if (piVar6 != (int *)0x0) {
        unaff_D3 = (code *)piVar6[1];
        unaff_D2 = piVar6[2];
        *piVar7 = *piVar6;
        *piVar6 = (int)_softint_free;
        _softint_free = piVar6;
        if (*piVar7 == 0) {
          *(undefined4 *)(_softint_tail + param_1 * 4) = 0;
        }
      }
      if (piVar6 == (int *)0x0) break;
      (*unaff_D3)(unaff_D2);
    }
    break;
  case :
    piVar8 = (int *)(_softint_head + param_1 * 4);
    puVar2 = (undefined4 *)(_softint_tail + param_1 * 4);
    piVar6 = (int *)*piVar8;
    piVar7 = (int *)*puVar2;
    *puVar2 = 0;
    *piVar8 = 0;
    piVar1 = piVar6;
    piVar4 = (int *)0x0;
    while (piVar3 = piVar1, piVar3 != (int *)0x0) {
      iVar5 = (*(code *)piVar3[1])(piVar3[2]);
      if (iVar5 == 0) {
        if (piVar4 == (int *)0x0) {
          piVar6 = (int *)*piVar3;
          if (piVar6 == (int *)0x0) {
            piVar7 = (int *)0x0;
          }
        }
        else {
          *piVar4 = *piVar3;
          if (piVar3 == piVar7) {
            piVar7 = piVar4;
          }
        }
        piVar1 = (int *)*piVar3;
        *piVar3 = (int)_softint_free;
        _softint_free = piVar3;
      }
      else {
        piVar1 = (int *)*piVar3;
        piVar4 = piVar3;
      }
    }
    if (*piVar8 == 0) {
      *piVar8 = (int)piVar6;
      *puVar2 = piVar7;
    }
    else {
      *piVar7 = *piVar8;
      *piVar8 = (int)piVar6;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2507 start=0x4094202 */

void _startup_early(void)

{
  int iVar1;
  uint uVar2;
  
  _cfree = dword_40C2C40;
  _ns_callout = _nclist * 0x40 + dword_40C2C40;
  _softint = _ns_callout + _ncallout * 0x18;
  _ncache = _softint + _nsoftint * 0xc;
  _buf = _ncache + _ncsize * 0x46;
  if (_bufpages == 0) {
    _bufpages = _mem_size / 0x14 >> (_page_shift & 0x3f) & 0xfffffffe;
  }
  if ((_nbuf == 0) && (_nbuf = _bufpages, (int)_bufpages < 0x10)) {
    _nbuf = 0x10;
  }
  if (0xfe < (int)_nbuf) {
    _nbuf = 0xfe;
  }
  uVar2 = _nbuf * (0x2000 / _page_size);
  if (uVar2 < _bufpages) {
    _bufpages = uVar2;
  }
  iVar1 = _buf + _nbuf * 0x44;
  if (_nmfsbuf == 0) {
    uVar2 = _nbuf;
    if ((int)_nbuf < 0) {
      uVar2 = _nbuf + 1;
    }
    _nmfsbuf = (int)uVar2 >> 1;
  }
  _bzero(dword_40C2C40,iVar1 - dword_40C2C40);
  dword_40C2C40 = iVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=2508 start=0x4094332 */

void _startup(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined auStack_8 [4];
  
  iVar2 = _mon_global;
  _km_switch_to_vm();
  _panic_init();
  _printf(_version);
  _printf(aFpuVersion0xX,_fpu_version._0_1_);
  uVar5 = _mem_size + 0xfffff;
  uVar8 = uVar5 & 0xfff00000;
  iVar6 = (uVar8 + ((int)(sword)((sword)((int)uVar8 / 0x19999) + (sword)((int)uVar5 >> 0x1f)) -
                   ((int)uVar5 >> 0x1f)) * -0x19999) * 100;
  if (iVar6 < 0) {
    iVar6 = iVar6 + 0xfffff;
  }
  uVar5 = uVar8;
  if ((int)uVar8 < 0) {
    uVar5 = uVar8 + 0xfffff;
  }
  iVar7 = (uVar8 + ((int)uVar5 >> 0x14) * -0x100000) * 10;
  if (iVar7 < 0) {
    iVar7 = iVar7 + 0xfffff;
  }
  _printf(aPhysicalMemory,(int)uVar5 >> 0x14,iVar7 >> 0x14,iVar6 >> 0x14);
  param_1 = ~_page_mask & _page_mask + param_1;
  uVar3 = _vm_object_allocate(0,0,&param_1,0x800000,1);
  _vm_map_find(_kernel_map,uVar3);
  _vm_map_remove(_kernel_map,param_1,param_1 + 0x800000);
  _buffers = param_1;
  uVar8 = _bufpages % (int)_nbuf;
  iVar7 = _bufpages / (int)_nbuf;
  iVar6 = (~_page_mask & _page_mask + _nbuf * 0x2000 + param_1) - param_1;
  _buffer_map = _kmem_suballoc(_kernel_map,&param_1,auStack_8,iVar6,1);
  uVar3 = _vm_object_allocate(iVar6,0,&param_1,iVar6,0);
  _vm_map_find(_buffer_map,uVar3);
  uVar5 = 0;
  if (_nbuf != 0) {
    iVar6 = 0;
    do {
      iVar4 = iVar7;
      if (uVar5 < uVar8) {
        iVar4 = iVar7 + 1;
      }
      _vm_map_pageable(_buffer_map,iVar6 + _buffers,iVar6 + _buffers + iVar4 * _page_size,0);
      iVar6 = iVar6 + 0x2000;
      uVar5 = uVar5 + 1;
    } while (uVar5 < _nbuf);
  }
  iVar7 = _vm_page_free_count << (_page_shift & 0x3f);
  iVar6 = (iVar7 + ((int)(sword)((sword)(iVar7 / 0x19999) + (sword)(iVar7 >> 0x1f)) -
                   (iVar7 >> 0x1f)) * -0x19999) * 100;
  if (iVar6 < 0) {
    iVar6 = iVar6 + 0xfffff;
  }
  iVar4 = iVar7;
  if (iVar7 < 0) {
    iVar4 = iVar7 + 0xfffff;
  }
  iVar7 = (iVar7 + (iVar4 >> 0x14) * -0x100000) * 10;
  if (iVar7 < 0) {
    iVar7 = iVar7 + 0xfffff;
  }
  _printf(aAvailableMemor,iVar4 >> 0x14,iVar7 >> 0x14,iVar6 >> 0x14);
  iVar7 = _bufpages << (_page_shift & 0x3f);
  iVar6 = (iVar7 + ((int)(sword)((sword)(iVar7 / 0x19999) + (sword)(iVar7 >> 0x1f)) -
                   (iVar7 >> 0x1f)) * -0x19999) * 100;
  if (iVar6 < 0) {
    iVar6 = iVar6 + 0xfffff;
  }
  iVar4 = iVar7;
  if (iVar7 < 0) {
    iVar4 = iVar7 + 0xfffff;
  }
  iVar7 = (iVar7 + (iVar4 >> 0x14) * -0x100000) * 10;
  if (iVar7 < 0) {
    iVar7 = iVar7 + 0xfffff;
  }
  _printf(aUsingDBuffersC,_nbuf,iVar4 >> 0x14,iVar7 >> 0x14,iVar6 >> 0x14);
  _ns_callout_init();
  uVar8 = _nsoftint;
  _softint_free = _softint;
  uVar5 = 1;
  piVar1 = _softint;
  if (1 < _nsoftint) {
    do {
      *piVar1 = (int)(piVar1 + 3);
      uVar5 = uVar5 + 1;
      piVar1 = piVar1 + 3;
    } while (uVar5 < uVar8);
  }
  _softint[_nsoftint * 3 + -3] = 0;
  _mb_map = _kmem_suballoc(_kernel_map,&_mbutl,_embutl,_nmbclusters << 10,0);
  if (((((unk_40B6904 & 8) == 0) && (_console_o == 0)) && (0x17 < *(sword *)(iVar2 + 0x30c))) &&
     (iVar6 = *(int *)(iVar2 + 0x30e), iVar6 != 0)) {
    _callout_dispatch(2,iVar6,0);
  }
  if (_bmap_chip != 0) {
    if (_astune_rate == 0) {
      _astune_rate = 1;
    }
    _timeout(_as_tune,0,_hz * _astune_rate);
  }
  if (_dma_chip != 0x139) {
    _adb_initialize();
  }
  _configure();
  return;
}
/* GHIDRADEC_FUNCTION index=2509 start=0x4094758 */

void _as_tune(int param_1)

{
  if ((0x3b < *(sword *)(_mon_global + 0x30c)) && (*(int *)(_mon_global + 0x3aa) != 0)) {
    (**(code **)(_mon_global + 0x3aa))();
  }
  if (param_1 + 1 < _astune_calls) {
    _timeout(_as_tune,param_1 + 1,_hz * _astune_rate);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2510 start=0x40947be */

void _sendsig(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  puVar1 = (undefined4 *)*dword_40B57D4;
  iVar4 = *(int *)((int)_active_u + 0x142);
  if ((iVar4 == 0) && (*(int *)((int)_active_u + 0x132) << 0x20 - param_2 < 0)) {
    iVar2 = *(int *)((int)_active_u + 0x13e);
    *(undefined4 *)((int)_active_u + 0x142) = 1;
  }
  else {
    iVar2 = puVar1[0xf];
  }
  iStack_10 = param_2;
  if ((param_2 == 4) || (param_2 - 7U < 2)) {
    iStack_c = dword_40B57D4[0x1b];
    dword_40B57D4[0x1b] = 0;
  }
  else {
    iStack_c = 0;
  }
  iStack_8 = iVar2 + -0x18;
  iVar3 = _copyoutmsg(&iStack_10,iVar2 + -0x24,0xc);
  if (iVar3 == 0) {
    uStack_24 = param_3;
    uStack_20 = puVar1[0xf];
    uStack_1c = *(undefined4 *)((int)puVar1 + 0x42);
    iStack_18 = (int)*(sword *)(puVar1 + 0x10);
    uStack_14 = *puVar1;
    iStack_28 = iVar4;
    iVar4 = _copyoutmsg(&iStack_28,iVar2 + -0x18,0x18);
    if (iVar4 == 0) {
      puVar1[0xf] = iVar2 + -0x24;
      *(undefined4 *)((int)puVar1 + 0x42) = param_1;
      return;
    }
  }
  *(undefined4 *)((int)_active_u + 0x3a) = 0;
  *(uint *)(*_active_u + 0x20) = *(uint *)(*_active_u + 0x20) & 0xfffffff7;
  *(uint *)(*_active_u + 0x24) = *(uint *)(*_active_u + 0x24) & 0xfffffff7;
  *(uint *)(*_active_u + 0x1c) = *(uint *)(*_active_u + 0x1c) & 0xfffffff7;
  _psignal(*_active_u,4);
  return;
}
/* GHIDRADEC_FUNCTION index=2511 start=0x40948de */

void _sigreturn(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uStack_20;
  uint uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  uStack_20 = 0;
  puVar1 = (undefined4 *)*dword_40B57D4;
  iVar2 = _copyinmsg(puVar1[0xf] + 4,&uStack_20,4);
  if (iVar2 == 0) {
    iVar2 = _copyinmsg(uStack_20,&uStack_1c,0x18);
    if (iVar2 == 0) {
      *(undefined *)((int)dword_40B57D4 + 0x65) = 1;
      *(uint *)((int)_active_u + 0x142) = uStack_1c & 1;
      *(uint *)(*_active_u + 0x1c) = uStack_18 & 0xfffafeff;
      puVar1[0xf] = uStack_14;
      *(undefined4 *)((int)puVar1 + 0x42) = uStack_10;
      *(undefined2 *)(puVar1 + 0x10) = uStack_a;
      *puVar1 = uStack_8;
      *(word *)(puVar1 + 0x10) = *(word *)(puVar1 + 0x10) & 0xc0ff;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2512 start=0x409497e */

void _halt_cpu(void)

{
  dword_40B5DD4 = 0;
  stop();
  return;
}
/* GHIDRADEC_FUNCTION index=2513 start=0x4094990 */

undefined8 _light_on(void)

{
  uint uVar1;
  uint uVar2;
  int unaff_D2;
  char in_XF;
  
  uVar1 = *_scr2;
  uVar2 = uVar1 | 1;
  *_scr2 = uVar2;
  return CONCAT44(CONCAT22((sword)(uVar1 >> 0x10),
                           (word)(byte)(((int)uVar2 < 0) << 3 | (uVar2 == 0) << 2)),
                  (int)(sword)(word)(byte)(in_XF << 4 | (unaff_D2 < 0) << 3 | (unaff_D2 == 0) << 2))
  ;
}
/* GHIDRADEC_FUNCTION index=2514 start=0x40949b8 */

undefined8 _light_off(void)

{
  uint uVar1;
  int unaff_D2;
  char in_XF;
  
  uVar1 = *_scr2 & 0xfffffffe;
  *_scr2 = uVar1;
  return CONCAT44(CONCAT22((sword)(uVar1 >> 0x10),
                           (word)(byte)(((int)uVar1 < 0) << 3 | (uVar1 == 0) << 2)),
                  (int)(sword)(word)(byte)(in_XF << 4 | (unaff_D2 < 0) << 3 | (unaff_D2 == 0) << 2))
  ;
}
/* GHIDRADEC_FUNCTION index=2515 start=0x40949e0 */

void _addupc(int param_1,int param_2,sword param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  sword sStack_6;
  
  if (param_2 != 0) {
    iVar3 = param_2;
    do {
      uVar2 = param_1 - *(int *)(iVar3 + 0x10);
      uVar1 = *(uint *)(iVar3 + 8);
      uVar2 = ((*(int *)(iVar3 + 0x14) * (uVar2 & 0xffff) >> 0x10) +
               *(int *)(iVar3 + 0x14) * (uVar2 >> 0x10) & 0xfffffffe) + uVar1;
      if ((uVar1 <= uVar2) && (uVar2 < *(int *)(iVar3 + 0xc) + uVar1)) {
        iVar3 = _copyinmsg(uVar2,&sStack_6,2);
        if (iVar3 != 0) {
          *(undefined4 *)(param_2 + 0x14) = 0;
          return;
        }
        sStack_6 = param_3 + sStack_6;
        _copyoutmsg(&sStack_6,uVar2,2);
        return;
      }
      iVar3 = *(int *)(iVar3 + 4);
    } while (iVar3 != 0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2516 start=0x4094a7c */

undefined4 _miniMonReboot(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2517 start=0x4094a86 */

undefined4 _miniMonHalt(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2518 start=0x4094a90 */

undefined4 _miniMonGdb(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2519 start=0x4094a9a */

void _miniMonTryGetchar(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2520 start=0x4094aa2 */

void _miniMonGetchar(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2521 start=0x4094aaa */

void _miniMonPutchar(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2522 start=0x4094ab2 */

undefined4
_machine_exception(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                  undefined4 *param_5)

{
  undefined4 uVar1;
  
  if (param_1 == 3) {
    uVar1 = 8;
loc_4094AEA:
    *param_4 = uVar1;
    *param_5 = param_2;
    uVar1 = 1;
  }
  else {
    if (param_1 < 4) {
      if (param_1 == 2) {
        uVar1 = 4;
        goto loc_4094AEA;
      }
    }
    else if (param_1 == 4) {
      uVar1 = 7;
      goto loc_4094AEA;
    }
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2523 start=0x4094afe */

void _m68k_init(int param_1)

{
  char cVar1;
  uint uVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  char *pcVar14;
  int iVar15;
  int iStack_28;
  undefined auStack_24 [32];
  
  iVar11 = *(int *)(param_1 + 4);
  _slot_id = *(int *)(param_1 + 0x1c);
  _slot_id_bmap = *(int *)(param_1 + 0x1c);
  puVar6 = (undefined4 *)_get_vbr();
  _scb = *puVar6;
  off_40ADA18 = (void *)puVar6[1];
  _reboot_vector = puVar6[0x2d];
  off_40ADAC8 = _mon_exit;
  _set_vbr(&_scb);
  uVar10 = *(uint *)(_slot_id + 0x200c000);
  if ((byte)((byte)(uVar10 >> 8) >> 4) == 4) {
    uVar10 = *(uint *)(_slot_id + 0x2200000);
  }
  _cpu_rev = (byte)(uVar10 >> 8);
  _machine_type = _cpu_rev >> 4;
  _board_rev = _cpu_rev & 0xf;
  _cpu_clk = (&byte_40B2BAD)[(uVar10 & 7) * 4];
  switch(_machine_type) {
  case :
    _cpu_type = '\0';
    _dma_chip = 0x139;
    break;
  case :
  case :
  case :
    _cpu_type = '\x01';
    _slot_id_bmap = _slot_id_bmap + 0x100000;
    _dma_chip = 0x139;
    _bmap_chip = _slot_id + 0x20c0000;
    break;
  :
    _cpu_type = '\x01';
    _dma_chip = (word)*(byte *)(_slot_id + 0x200c001);
    _cpu_clk = (&byte_40B2BAD)[(uVar10 & 7 ^ 4) * 4];
    iVar7 = _probe_rl(_slot_id + 0x2210000);
    if (iVar7 != 0) {
      _ncc_chip = 1;
      _cpu_clk = 0x28;
    }
  }
  if (_cpu_type == '\0') {
    _cache = 0x1919;
  }
  else {
    _cache = 0x80008000;
  }
  _intrmask = (undefined4 *)(_slot_id + 0x2007800);
  _intrstat = _slot_id + 0x2007000;
  *_intrmask = 0;
  _intr_mask = 0;
  _eventc_latch = _slot_id_bmap + 0x201a000;
  _eventc_h = _slot_id_bmap + 0x201a001;
  _eventc_m = _slot_id_bmap + 0x201a002;
  _eventc_l = _slot_id_bmap + 0x201a003;
  _scr2 = (uint *)(_slot_id + 0x200d000);
  *_scr2 = *_scr2 & 0x7ffffffe;
  _brightness = _slot_id_bmap + 0x2010000;
  _timer_csr = _slot_id_bmap + 0x2016004;
  _timer_high = _slot_id_bmap + 0x2016000;
  _timer_low = _slot_id_bmap + 0x2016001;
  _mon_global = *(undefined4 *)(param_1 + 4);
  _bcopy(*(undefined4 *)(param_1 + 0x2c),&_etheraddr,6);
  _hostid = CONCAT31(byte_40C9468 | 0x10000 | (uint3)(((uint)byte_40C9467 << 0x10) >> 8),
                     byte_40C9469);
  _strncpy(&_boot_dev,*(undefined4 *)(param_1 + 0x10),8);
  _strncpy(&_boot_file,*(undefined4 *)(param_1 + 0x30),0x40);
  pcVar14 = *(char **)(param_1 + 0x14);
  if (pcVar14 != (char *)0x0) {
    cVar1 = *pcVar14;
    while (cVar1 != '\0') {
      iVar7 = _strncmp(aPagesize_0,pcVar14,9);
      if (iVar7 == 0) {
        _getval(pcVar14 + 8,&_pagesize);
        break;
      }
      iVar7 = _strncmp(&aMem_0,pcVar14,4);
      if (iVar7 == 0) {
        _getval(pcVar14 + 3,&_mem);
        _mem = _mem << 10;
        break;
      }
      pcVar14 = pcVar14 + 1;
      cVar1 = *pcVar14;
    }
  }
  if ((_pagesize == 0x1000) || (_pagesize == 0x2000)) {
    _m68k_page_size = _pagesize;
  }
  else {
    _m68k_page_size = _default_page_size;
  }
  _pmap_set_page_size();
  if (_page_size < _m68k_page_size) {
    _page_size = _m68k_page_size;
  }
  _vm_set_page_size();
  uVar10 = _mem;
  _num_regions = *(int *)(param_1 + 0x24);
  iVar7 = 0;
  bVar3 = false;
  if (0 < _num_regions) {
    uVar2 = -_m68k_page_size;
    iVar15 = 0;
    do {
      if (bVar3) {
        *(undefined4 *)((int)&dword_40C2C40 + iVar15) = 0;
        *(undefined4 *)(DAT_40c2c44 + iVar15) = 0;
        iVar8 = 0;
      }
      else {
        *(undefined4 *)((int)&dword_40C2C40 + iVar15) =
             *(undefined4 *)(*(int *)(param_1 + 0x28) + iVar7 * 8);
        *(undefined4 *)(DAT_40c2c44 + iVar15) =
             *(undefined4 *)(*(int *)(param_1 + 0x28) + 4 + iVar7 * 8);
        iVar8 = *(int *)(DAT_40c2c44 + iVar15) - *(int *)((int)&dword_40C2C40 + iVar15);
      }
      if (((uVar10 != 0) && (!bVar3)) && (uVar10 <= (uint)(_mem_size + iVar8))) {
        *(uint *)(DAT_40c2c44 + iVar15) =
             *(int *)((int)&dword_40C2C40 + iVar15) + (uVar10 - _mem_size);
        bVar3 = true;
      }
      _mem_size = (*(int *)(DAT_40c2c44 + iVar15) - *(int *)((int)&dword_40C2C40 + iVar15)) +
                  _mem_size;
      if (*(int *)(*(int *)(param_1 + 0x28) + iVar7 * 8) != 0) {
        _pmsgbuf = (uVar2 & *(uint *)(*(int *)(param_1 + 0x28) + 4 + iVar7 * 8)) + 0x100;
      }
      iVar15 = iVar15 + 0x1c;
      iVar7 = iVar7 + 1;
    } while (iVar7 < _num_regions);
  }
  _cons_tp = _cons;
  _console_i = *(undefined4 *)(param_1 + 8);
  _console_o = *(int *)(param_1 + 0xc);
  if ((_console_o == 0) || (_console_o != 1)) {
    word_40B6834 = 0xc00;
    bVar3 = false;
    pcVar14 = *(char **)(param_1 + 0x14);
    if (pcVar14 != (char *)0x0) {
      while (iVar7 = _isargsep((int)*pcVar14), iVar7 != 0) {
        pcVar14 = pcVar14 + 1;
      }
      if (*pcVar14 == '-') {
        do {
          cVar1 = *pcVar14;
          if (cVar1 == 's') {
loc_4094FDC:
            bVar3 = true;
          }
          else if (cVar1 < 't') {
            if (cVar1 == 'a') goto loc_4094FDC;
          }
          else if (cVar1 == 'w') goto loc_4094FDC;
          cVar1 = *pcVar14;
          if (cVar1 == '\0') break;
          pcVar14 = pcVar14 + 1;
          iVar7 = _isargsep((int)cVar1);
        } while (iVar7 == 0);
      }
    }
    if ((*(byte *)(iVar11 + 0x171) & 8) != 0) {
      bVar3 = true;
    }
    _kminit();
    if (bVar3) {
      _kmpopup(_mach_title,2,0,0,0);
    }
  }
  else {
    word_40B6834 = 0xb00;
  }
  _boot_args = *(undefined4 *)(param_1 + 0x14);
  _getargs(*(undefined4 *)(param_1 + 0x14),0);
  _printf(aNextRomMonitor,(int)*(sword *)(iVar11 + 0x312),(int)*(sword *)(iVar11 + 0x30a),
          (int)*(sword *)(iVar11 + 0x30c));
  _tick = 1000000 / _hz;
  _tickadj = 240000 / (_hz * 0x3c);
  _mon_reset();
  if (_dma_chip != 0x139) {
    _km_send(0xc5,0xf0000000);
    _mon_rev = (undefined)((uint)*(undefined4 *)(_slot_id + 0x200e008) >> 0x10);
  }
  bVar5 = _cpu_clk;
  bVar4 = _machine_type;
  _master_cpu = 0;
  dword_40B5DD4 = 1;
  iVar11 = 0;
  pcVar9 = _intstacks;
  puVar13 = &_machine_slot;
  puVar6 = &_interrupt_stack;
  do {
    *puVar13 = 1;
    (&DAT_40b5de4)[iVar11 * 8] = (uint)bVar5;
    if (bVar4 == 0) {
      (&dword_40B5DCC)[iVar11 * 8] = 6;
      uVar12 = 1;
    }
    else {
      (&dword_40B5DCC)[iVar11 * 8] = 6;
      uVar12 = 2;
    }
    (&dword_40B5DD0)[iVar11 * 8] = uVar12;
    *puVar6 = pcVar9;
    pcVar9 = pcVar9 + 0x1000;
    puVar13 = puVar13 + 8;
    iVar11 = iVar11 + 1;
    puVar6 = puVar6 + 1;
  } while (iVar11 < 1);
  dword_40C2C40 = _getlastaddr();
  _pmap_bootstrap(_mem_region,_num_regions,&_virtual_avail,&_virtual_end,_pmsgbuf + -0x100);
  _en_bufalloc(0);
  if (_breakpoint != 0) {
    if (_kdb_ipaddr == 0) {
      do {
        _printf(aIpAddress);
        _gets(auStack_24,auStack_24);
        iVar11 = _inet_aton(auStack_24,&iStack_28);
      } while (iVar11 == 0);
      _kdb_ipaddr = iStack_28;
    }
    _printf(aWaitingForConn);
    while (dword_40C9474 == 0) {
      _kdbg_connect(0);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2524 start=0x40951ec */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
_machine_table(int param_1,int param_2,undefined4 param_3,int param_4,uint param_5,int param_6)

{
  undefined uVar2;
  undefined4 uVar1;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined auStack_58 [4];
  undefined4 auStack_54 [8];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  char acStack_20 [8];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  int iStack_8;
  
  if (param_1 != 0x10) {
    if (param_1 < 0x11) {
      if (param_1 == 0xd) {
        if ((param_2 == 0) && (param_4 == 1)) {
          uStack_18 = _tk_nin;
          uStack_14 = _tk_nout;
          uStack_10 = _dk_busy;
          iStack_c = 0;
          if (_bus_dinit._0_4_ != 0) {
            puVar4 = _bus_dinit;
            iVar6 = 0;
            do {
              if (-1 < *(sword *)(_bus_dinit + iVar6 + 0xc)) {
                iStack_c = iStack_c + 1;
              }
              puVar4 = (undefined *)((int)puVar4 + 0x2a);
              iVar6 = iVar6 + 0x2a;
            } while (*(int *)puVar4 != 0);
          }
          iStack_8 = 0;
          for (iVar6 = _ifnet; iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x5a)) {
            iStack_8 = iStack_8 + 1;
          }
          puVar7 = &uStack_18;
          uVar5 = 0x14;
          goto loc_40953DE;
        }
      }
      else {
        if (param_1 != 0xe) {
          return 0;
        }
        iVar6 = 0;
        if (_bus_dinit._0_4_ != 0) {
          puVar4 = _bus_dinit;
          iVar3 = 0;
          do {
            if (param_2 == *(sword *)(_bus_dinit + iVar3 + 0xc)) break;
            puVar4 = (undefined *)((int)puVar4 + 0x2a);
            iVar3 = iVar3 + 0x2a;
            iVar6 = iVar6 + 1;
          } while (*(int *)puVar4 != 0);
          iVar6 = iVar6 * 0x2a;
          if (*(int *)(_bus_dinit + iVar6) != 0) {
            puVar7 = &uStack_34;
            _strncpy(acStack_20,*(undefined4 *)(_bus_dinit + iVar6 + 0x16),6);
            iVar3 = _strlen(acStack_20);
            acStack_20[iVar3] = _bus_dinit[iVar6 + 5] + '0';
            acStack_20[iVar3 + 1] = '\0';
            if (param_2 < _dk_ndrive) {
              uStack_34 = *(undefined4 *)(_dk_time + param_2 * 4);
              uStack_30 = *(undefined4 *)(_dk_seek + param_2 * 4);
              uStack_2c = *(undefined4 *)(_dk_xfer + param_2 * 4);
              uStack_28 = *(undefined4 *)(_dk_wds + param_2 * 4);
              uStack_24 = *(undefined4 *)(_dk_bps + param_2 * 4);
              uVar5 = 0x1c;
              goto loc_40953DE;
            }
          }
        }
      }
      return 0xffffffff;
    }
    if (param_1 == 0x4002) {
      puVar7 = (undefined4 *)&_cpu_clk;
      uVar5 = 1;
    }
    else if (param_1 < 0x4003) {
      if (param_1 != 0x4000) {
        return 0;
      }
      puVar7 = (undefined4 *)&_cpu_rev;
      uVar5 = 1;
    }
    else {
      if (param_1 != 0x4003) {
        return 0;
      }
      puVar7 = &_nbic_present;
      uVar5 = 4;
    }
    goto loc_40953DE;
  }
  uVar5 = __cpu_rev >> 0x1c;
  if (uVar5 == 5) {
loc_40953C4:
    auStack_54[0] = 0;
  }
  else {
    if (uVar5 < 6) {
      if (uVar5 == 3) goto loc_40953C4;
    }
    else if (uVar5 == 9) goto loc_40953C4;
    auStack_54[0] = 1;
  }
  puVar7 = auStack_54;
  uVar5 = 0x20;
loc_40953DE:
  if (param_5 < uVar5) {
    uVar5 = param_5;
  }
  if (uVar5 != 0) {
    if (param_6 == 0) {
      uVar2 = _copyoutmsg(puVar7,param_3,uVar5);
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
    }
    else {
      uVar2 = _copyinmsg(param_3,auStack_58,uVar5);
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        _bcopy(auStack_58,puVar7,uVar5);
      }
    }
  }
  uVar1 = 0xffffffff;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    uVar1 = 1;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2525 start=0x4095456 */

undefined4 _machine_table_setokay(void)

{
  return 0xffffffff;
}
/* GHIDRADEC_FUNCTION index=2526 start=0x4095460 */

void _m68k_dbginit(void)

{
  int iVar1;
  
  iVar1 = _get_vbr();
  dword_40B5620 = *(undefined4 *)(iVar1 + 0xbc);
  *(code **)(iVar1 + 0xbc) = __dbg_trap;
  _dbg_kresume();
  _adb_watchdog(0);
  _dbg_process(_dbg_connect_pkt);
  _adb_watchdog(1);
  return;
}
/* GHIDRADEC_FUNCTION index=2527 start=0x40954b2 */

int _dbg_kresume(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  iVar2 = _dbg_setjmp(unk_40B55CC);
  puVar1 = dword_40C9714;
  if (iVar2 == 0) {
    dword_40C9714 = dword_40C9714 + -4;
    *dword_40C9714 = word_40C971A;
    *(undefined4 *)(puVar1 + -3) = dword_40C971C;
    *(byte *)(puVar1 + -1) = *(byte *)(puVar1 + -1) & 0xf;
    dword_40B5610 = unk_40B55CC;
    iVar2 = __dbg_kresume();
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2528 start=0x409552a */

void _dbg_panic(undefined4 param_1)

{
  _nmi_prf(aDbgPanicS,param_1);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2529 start=0x409554a */

undefined4 _dbg_trap(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  _adb_watchdog(0);
  _get_vbr();
  if (_client_running == 0) {
    dword_40B5630 = 5;
  }
  else {
    if ((*(word *)(param_1 + 0x46) & 0x2000) == 0) {
      iVar1 = (*(int *)(param_1 + 0x4c) << 4) >> 0x16;
      if (iVar1 == 9) {
        _adb_watchdog(1);
        uVar2 = dword_40B561C;
      }
      else {
        if (iVar1 != 0x2f) {
          _nmi_prf(aDbgTrapReturni,(*(int *)(param_1 + 0x4c) << 4) >> 0x14);
                    /* WARNING: Subroutine does not return */
          _dbg_panic(aDbgTrapBadUser);
        }
        _adb_watchdog(1);
        uVar2 = dword_40B5620;
      }
      return uVar2;
    }
    _client_running = 0;
    _bcopy(param_1,&_client_pcb,0xa2);
    dword_40B5634 = 0;
    dword_40B5638 = (*(int *)(param_1 + 0x4c) << 4) >> 0x14;
    switch(*(int *)(param_1 + 0x4c) >> 0x1c) {
    case :
    case :
      dword_40C9714 = dword_40C9714 + 8;
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0xc;
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0xc;
      break;
    :
                    /* WARNING: Subroutine does not return */
      _dbg_panic(aStackFrameScre);
    case :
      dword_40C9714 = dword_40C9714 + 0x3c;
      dword_40B5634 = dword_40C972A;
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0x14;
      dword_40B5634 = CONCAT22(dword_40C9722._0_2_,dword_40C9722._2_2_);
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0x20;
      dword_40B5634 = dword_40C972A;
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0x5c;
      dword_40B5634 = dword_40C972A;
    }
    switch((CONCAT22(word_40C9720,dword_40C9722._0_2_) << 4) >> 0x16) {
    case :
    case :
      dword_40B5630 = 1;
      break;
    case :
      dword_40B5630 = 2;
      break;
    :
      dword_40B5630 = 5;
      break;
    case :
      if ((dword_40B5610 != 0) && (dword_40B5624 != 0)) {
        iVar1 = _get_vbr();
        *(undefined4 *)(iVar1 + 0x24) = dword_40B561C;
        word_40C971A = word_40C971A & 0x7fff;
        dword_40B5624 = 0;
      }
    case :
      dword_40B5630 = 6;
    }
  }
  _adb_watchdog(1);
                    /* WARNING: Subroutine does not return */
  _dbg_dispatch();
}
/* GHIDRADEC_FUNCTION index=2530 start=0x4095890 */

void _dbg_dispatch(void)

{
  int iVar1;
  
  iVar1 = dword_40B5610;
  if (dword_40B5610 != 0) {
    dword_40B5610 = 0;
    _dbg_longjmp(iVar1,dword_40B5630);
  }
                    /* WARNING: Subroutine does not return */
  _dbg_panic(aDebuggerScrewU);
}
/* GHIDRADEC_FUNCTION index=2531 start=0x40958d4 */

undefined4 _kdbg_connect(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (dword_40C9474 == 0) {
    _kdb_net._0_4_ = 0;
    _kdb_net._4_4_ = 0;
    _en_bufalloc(param_1);
    _dbg_connect_pkt = sub_40963BC(1);
    if (_dbg_connect_pkt == 0) {
      uVar1 = 0;
    }
    else if (*(int *)(_dbg_connect_pkt + 0x2e) == 8) {
      dword_40C9474 = 1;
      if (dword_40B5628 != 0) {
                    /* WARNING: Subroutine does not return */
        _dbg_dispatch();
      }
      __m68k_trap(0xf);
      uVar1 = 1;
    }
    else {
      _nmi_prf(aOldDebuggingIn,*(undefined4 *)(_dbg_connect_pkt + 0x2e));
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2532 start=0x409597a */

void _gdb_from_trap(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  dword_40B5628 = dword_40B5628 + 1;
  if (dword_40B5628 == 1) {
    word_40C9720 = word_40C9720 & 0xf000 | 8;
    dword_40B5630 = 1;
    dword_40B5634 = param_4;
    _bcopy(param_1,&dword_40C96D8,0x48);
    dword_40C971C = param_3;
    word_40C971A = (undefined2)param_2;
    if (dword_40C9474 != 0) {
      _nmi_prf(aGdbFromTrapPcX,param_3,dword_40C9714,param_2,param_4);
                    /* WARNING: Subroutine does not return */
      _dbg_dispatch();
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2533 start=0x4095a30 */

void _dbg_from_ether(int param_1)

{
  if ((dword_40C9474 != 0) && (*(int *)(param_1 + 0x2e) == 0x11)) {
    _dbg_connect_pkt = param_1;
    dword_40B562C = 1;
    __m68k_trap(0xf);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2534 start=0x4095a66 */

/* WARNING: Restarted to delay deadcode elimination for space: ram */

void _dbg_process(int param_1)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int *piStack_28;
  int iStack_10;
  
  iVar2 = dword_40C8F00;
  iVar1 = dword_40C8F00 + 0x2a;
  if ((dword_40C9474 == 0) || (param_1 == 0)) {
    return;
  }
  _nmi_prf(aConnectingToDe);
loc_4095AAE:
  do {
    switch(*(undefined4 *)(param_1 + 0x2e)) {
    case :
      puVar3 = (undefined *)_index(param_1 + 0x42,0x3a);
      if (puVar3 != (undefined *)0x0) {
        *puVar3 = 0;
      }
      _nmi_prf(aDebuggingConne,param_1 + 0x42,puVar3 + 1);
      DAT_40c9470 = 0;
      *(undefined4 *)(iVar2 + 0x2e) = 2;
      break;
    case :
      *(undefined4 *)(iVar2 + 0x3a) = 1;
      *(undefined4 *)(iVar2 + 0x2e) = 5;
      break;
    :
      _nmi_prf(aKdbgUnknownRqT,*(undefined4 *)(iVar2 + 0x2e));
loc_4096144:
      *(undefined4 *)(iVar2 + 0x2e) = 0x16;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      break;
    case :
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      *(int *)(iVar2 + 0x42) = _slot_id;
      *(undefined4 *)(iVar2 + 0x46) = 0x20000;
      *(undefined4 *)(iVar2 + 0x4a) = 1;
      *(int *)(iVar2 + 0x4e) = _slot_id + 0x1000000;
      *(undefined4 *)(iVar2 + 0x52) = 0x20000;
      *(undefined4 *)(iVar2 + 0x56) = 1;
      *(int *)(iVar2 + 0x5a) = _slot_id + 0x2000000;
      *(undefined4 *)(iVar2 + 0x5e) = 0xc0040;
      *(undefined4 *)(iVar2 + 0x62) = 3;
      *(int *)(iVar2 + 0x66) = _slot_id + 0x2100000;
      *(undefined4 *)(iVar2 + 0x6a) = 0x1e000;
      *(undefined4 *)(iVar2 + 0x6e) = 3;
      *(int *)(iVar2 + 0x72) = _slot_id + 0x4000000;
      if (_dma_chip == 0x139) {
        if (_machine_type == '\x03') {
          uVar4 = 0x2000000;
        }
        else {
          uVar4 = 0x4000000;
        }
      }
      else {
        uVar4 = 0x8000000;
      }
      *(undefined4 *)(iVar2 + 0x76) = uVar4;
      *(undefined4 *)(iVar2 + 0x7a) = 3;
      piStack_28 = (int *)(iVar2 + 0x7e);
      switch(_machine_type) {
      case :
      case :
        break;
      case :
        *piStack_28 = 0x4000000;
        *(undefined4 *)(iVar2 + 0x82) = 0x8000000;
        *(undefined4 *)(iVar2 + 0x86) = 3;
        *(undefined4 *)(iVar2 + 0x8a) = 0xc000000;
        *(undefined4 *)(iVar2 + 0x8e) = 0x10000000;
        *(undefined4 *)(iVar2 + 0x92) = 3;
        *(undefined4 *)(iVar2 + 0x96) = 0x24000000;
        *(undefined4 *)(iVar2 + 0x9a) = 0x28000000;
        *(undefined4 *)(iVar2 + 0x9e) = 3;
        *(undefined4 *)(iVar2 + 0xa2) = 0x2c000000;
        *(undefined4 *)(iVar2 + 0xa6) = 0x30000000;
        *(undefined4 *)(iVar2 + 0xaa) = 3;
        piStack_28 = (int *)(iVar2 + 0xae);
        break;
      :
        *piStack_28 = _slot_id + 0x2200000;
        *(undefined4 *)(iVar2 + 0x82) = 0x9000;
        *(undefined4 *)(iVar2 + 0x86) = 3;
        *(int *)(iVar2 + 0x8a) = _slot_id + 0x2210000;
        *(undefined4 *)(iVar2 + 0x8e) = 4;
        *(undefined4 *)(iVar2 + 0x92) = 3;
        *(int *)(iVar2 + 0x96) = _slot_id + 0x3e00000;
        *(undefined4 *)(iVar2 + 0x9a) = 0x80000;
        *(undefined4 *)(iVar2 + 0x9e) = 3;
        piStack_28 = (int *)(iVar2 + 0xa2);
      }
      *piStack_28 = 0x10000000;
      piStack_28[1] = 0x4000000;
      piStack_28[2] = 3;
      *(int *)(iVar2 + 0x3e) = (int)piStack_28 + (-0xc - iVar1);
      *(undefined4 *)(iVar2 + 0x2e) = 6;
      break;
    case :
      if (0x200 < *(int *)(param_1 + 0x3a)) {
                    /* WARNING: Subroutine does not return */
        _dbg_panic(aBadLengthOfDat);
      }
      for (iStack_10 = 0; iStack_10 < *(int *)(param_1 + 0x3a); iStack_10 = iStack_10 + 4) {
        iVar5 = _rdmem(iStack_10 + *(int *)(param_1 + 0x36),4,iStack_10 + 0x18 + iVar1);
        if (iVar5 != 0) goto loc_4096144;
      }
      *(undefined4 *)(iVar2 + 0x2e) = 3;
      *(undefined4 *)(iVar2 + 0x3e) = *(undefined4 *)(param_1 + 0x3a);
      break;
    case :
      if (*(int *)(param_1 + 0x3e) != 0x200) {
                    /* WARNING: Subroutine does not return */
        _dbg_panic(aBadLengthOfDat);
      }
      for (iStack_10 = 0; iStack_10 < 0x200; iStack_10 = iStack_10 + 4) {
        iVar5 = _wrmem(iStack_10 + *(int *)(param_1 + 0x36),4,
                       *(undefined4 *)(iStack_10 + 0x18 + param_1 + 0x2a));
        if (iVar5 != 0) goto loc_4096144;
      }
      *(undefined4 *)(iVar2 + 0x2e) = 1;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      break;
    case :
      _bcopy(&dword_40C96D8,iVar2 + 0x42,0x48);
      *(undefined4 *)(iVar2 + 0x3e) = 0x48;
      *(undefined4 *)(iVar2 + 0x2e) = 4;
      break;
    case :
      _bcopy(param_1 + 0x42,&dword_40C96D8,0x48);
      *(undefined4 *)(iVar2 + 0x2e) = 1;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      break;
    case :
    case :
      *(undefined4 *)(iVar2 + 0x2e) = 1;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      break;
    case :
    case :
      goto loc_4095eae;
    case :
      dword_40C9474 = 0;
      dword_40B562C = 1;
loc_4095eae:
      *(undefined4 *)(iVar2 + 0x2e) = 1;
      *(undefined4 *)(iVar2 + 0x3e) = 0;
      sub_40964C0();
      if ((word_40C971A & 0x8000) != 0) {
        iVar5 = _get_vbr();
        dword_40B561C = *(undefined4 *)(iVar5 + 0x24);
        *(code **)(iVar5 + 0x24) = __dbg_trap;
        dword_40B5624 = 1;
      }
      _dbg_kresume();
      if (dword_40B562C != 0) goto loc_4095f18;
      _SENDEXC();
      goto loc_409615C;
    case :
      if ((*(int *)(param_1 + 0x3e) == 0) || (0x1ff < *(int *)(param_1 + 0x3e))) {
        _mon_boot(0);
      }
      else {
        *(undefined *)(*(int *)(param_1 + 0x3e) + param_1 + 0x2a + 0x18) = 0;
        _mon_call(param_1 + 0x42);
      }
    }
    sub_40964C0();
loc_409615C:
    param_1 = sub_40963BC(0);
  } while( true );
loc_4095f18:
  dword_40B562C = 0;
  param_1 = _dbg_connect_pkt;
  _dbg_connect_pkt = 0;
  goto loc_4095AAE;
}
/* GHIDRADEC_FUNCTION index=2535 start=0x4096178 */

int _rdmem(uint *param_1,int param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = _dbg_setjmp(unk_40B55CC);
  if (iVar1 == 0) {
    dword_40B5610 = unk_40B55CC;
    sub_409630E();
    if (param_2 == 2) {
      *param_3 = (int)*(sword *)param_1;
      *param_3 = *param_3 & 0xffff;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) {
loc_409622C:
        dword_40B5610 = (undefined *)0x0;
                    /* WARNING: Subroutine does not return */
        _dbg_panic(aRdmemBadSize);
      }
      *param_3 = (int)*(char *)param_1;
      *param_3 = *param_3 & 0xff;
    }
    else {
      if (param_2 != 4) goto loc_409622C;
      *param_3 = *param_1;
    }
    sub_4096358();
    dword_40B5610 = (undefined *)0x0;
    iVar1 = 0;
  }
  else {
    sub_4096358();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2536 start=0x409625a */

int _wrmem(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = _dbg_setjmp(unk_40B55CC);
  if (iVar1 == 0) {
    dword_40B5610 = unk_40B55CC;
    sub_409630E();
    if (param_2 == 2) {
      *(sword *)param_1 = (sword)param_3;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) {
loc_40962D8:
        dword_40B5610 = (undefined *)0x0;
                    /* WARNING: Subroutine does not return */
        _dbg_panic(aWrmemBadSize);
      }
      *(char *)param_1 = (char)param_3;
    }
    else {
      if (param_2 != 4) goto loc_40962D8;
      *param_1 = param_3;
    }
    _cache_push();
    dword_40B5610 = (undefined *)0x0;
    sub_4096358();
    _cache_push();
    iVar1 = 0;
  }
  else {
    sub_4096358();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2537 start=0x4096386 */

void _kdebug_send(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = dword_40C8F00;
  *(undefined4 *)(dword_40C8F00 + 0x2a) = param_2;
  _en_send(param_1,iVar1,0x242);
  return;
}
/* GHIDRADEC_FUNCTION index=2538 start=0x40964f2 */

void _SENDEXC(void)

{
  int iVar1;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  undefined4 *puStack_10;
  int iStack_c;
  int *piStack_8;
  
  iVar1 = dword_40C8F04;
  piStack_8 = (int *)&_kdb_net;
  iStack_c = dword_40C8F04;
  puStack_10 = (undefined4 *)(dword_40C8F04 + 0x2a);
  *(undefined4 *)(dword_40C8F04 + 0x2e) = dword_40B5630;
  *(undefined4 *)(iVar1 + 0x3a) = dword_40B5638;
  *(undefined4 *)(iVar1 + 0x36) = dword_40B5634;
  *puStack_10 = DAT_40c9470;
  do {
    _en_send(0x474,iStack_c,0x242);
    for (iStack_18 = 0; iStack_18 < 50000; iStack_18 = iStack_18 + 1) {
      iStack_14 = _en_recv(&iStack_1c,0x242,piStack_8[2],_kdb_ipaddr);
      if (iStack_14 != 0) {
        if ((iStack_1c == 0x474) && (piStack_8[1] == *(int *)(iStack_14 + 0x2a))) {
          piStack_8[1] = piStack_8[1] + 1;
          return;
        }
        iStack_1c = 0x473;
        if (*piStack_8 + -1 == *(int *)(iStack_14 + 0x2a)) {
          _kdebug_send(0x473,*(int *)(iStack_14 + 0x2a));
        }
      }
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2539 start=0x409662a */

bool _inet_aton(char *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  int iStack_c;
  undefined4 uStack_8;
  
  puVar1 = &uStack_8;
  iStack_c = 0;
  do {
    if (*param_1 == '\0') {
      bVar2 = (undefined4 *)((int)&uStack_8 + 3) == puVar1;
      if (bVar2) {
        *(char *)puVar1 = (char)iStack_c;
        *param_2 = uStack_8;
      }
      return bVar2;
    }
    if (*param_1 == '.') {
      if ((undefined4 *)((int)&uStack_8 + 3U) <= puVar1) {
        return false;
      }
      *(char *)puVar1 = (char)iStack_c;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
      iStack_c = 0;
    }
    else {
      if ((*param_1 < '0') || ('9' < *param_1)) {
        return false;
      }
      iStack_c = iStack_c * 10 + -0x30 + (int)*param_1;
      if ((0xff < iStack_c) || (iStack_c < 0)) {
        return false;
      }
    }
    param_1 = param_1 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2540 start=0x4096700 */

void __m68k_dbginit(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  undefined4 unaff_D2;
  undefined4 unaff_D3;
  undefined4 unaff_D4;
  undefined4 unaff_D5;
  undefined4 unaff_D6;
  undefined4 unaff_D7;
  undefined4 in_A1;
  undefined4 unaff_A2;
  undefined4 unaff_A3;
  undefined4 unaff_A4;
  undefined4 unaff_A5;
  undefined4 unaff_A6;
  char in_XF;
  char in_NF;
  char in_ZF;
  char in_VF;
  byte in_CF;
  undefined4 in_stack_00000000;
  
  dword_40C9714 = &stack0x00000004;
  word_40C971A = (word)(byte)(in_XF << 4 | in_NF << 3 | in_ZF << 2 | in_VF << 1 | in_CF);
  word_40C9720 = 0;
  dword_40C96D8 = in_D0;
  DAT_40c96dc._0_4_ = in_D1;
  DAT_40c96dc._4_4_ = unaff_D2;
  DAT_40c96dc._8_4_ = unaff_D3;
  DAT_40c96dc._12_4_ = unaff_D4;
  DAT_40c96dc._16_4_ = unaff_D5;
  DAT_40c96dc._20_4_ = unaff_D6;
  DAT_40c96dc._24_4_ = unaff_D7;
  DAT_40c96dc._28_4_ = in_stack_00000000;
  DAT_40c96dc._32_4_ = in_A1;
  DAT_40c96dc._36_4_ = unaff_A2;
  DAT_40c96dc._40_4_ = unaff_A3;
  DAT_40c96dc._44_4_ = unaff_A4;
  DAT_40c96dc._48_4_ = unaff_A5;
  DAT_40c96dc._52_4_ = unaff_A6;
  dword_40C971C = in_stack_00000000;
  *(code **)(_dbgstack + 0x3fc) = __dbg_trap;
  _m68k_dbginit();
  return;
}
/* GHIDRADEC_FUNCTION index=2541 start=0x4096736 */

undefined8 __dbg_trap(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  undefined auStack_46 [4];
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  dword_40B5640 = (undefined *)register0x0000003c;
  uStack_42 = in_D0;
  uStack_3e = in_D1;
  dword_40B563C = _dbg_trap(auStack_46);
  *(undefined4 *)(dword_40B5640 + -4) = dword_40B563C;
  return CONCAT44(uStack_42,uStack_3e);
}
/* GHIDRADEC_FUNCTION index=2542 start=0x409677c */

undefined8 __dbg_kresume(void)

{
  _client_running = 1;
  return CONCAT44(dword_40C96D8,DAT_40c96dc._0_4_);
}
/* GHIDRADEC_FUNCTION index=2543 start=0x409679a */

undefined4 _dbg_setjmp(undefined4 *param_1)

{
  undefined4 in_D0;
  undefined4 in_D1;
  undefined4 unaff_D2;
  undefined4 unaff_D3;
  undefined4 unaff_D4;
  undefined4 unaff_D5;
  undefined4 unaff_D6;
  undefined4 unaff_D7;
  undefined4 in_A1;
  undefined4 unaff_A2;
  undefined4 unaff_A3;
  undefined4 unaff_A4;
  undefined4 unaff_A5;
  undefined4 unaff_A6;
  undefined4 in_stack_00000000;
  
  param_1[0x10] = in_stack_00000000;
  *param_1 = in_D0;
  param_1[1] = in_D1;
  param_1[2] = unaff_D2;
  param_1[3] = unaff_D3;
  param_1[4] = unaff_D4;
  param_1[5] = unaff_D5;
  param_1[6] = unaff_D6;
  param_1[7] = unaff_D7;
  param_1[8] = param_1;
  param_1[9] = in_A1;
  param_1[10] = unaff_A2;
  param_1[0xb] = unaff_A3;
  param_1[0xc] = unaff_A4;
  param_1[0xd] = unaff_A5;
  param_1[0xe] = unaff_A6;
  param_1[0xf] = register0x0000003c;
  return 0;
}
/* GHIDRADEC_FUNCTION index=2544 start=0x40967aa */

void _dbg_longjmp(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[8] = param_1[0x10];
                    /* WARNING: Could not recover jumptable at 0x040967bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_1[8])();
  return;
}
/* GHIDRADEC_FUNCTION index=2545 start=0x40967be */

void _stack_attach(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x24);
  *(int *)(param_1 + 0x28) = param_2;
  *(int *)(iVar1 + 0x38) = param_2 + 0xff4;
  *(int *)(iVar1 + 0x3c) = param_2 + 0xff4;
  *(code **)(iVar1 + 0x24) = __stack_attach;
  *(undefined4 *)(iVar1 + 0x28) = param_3;
  return;
}
/* GHIDRADEC_FUNCTION index=2546 start=0x40967f2 */

undefined4 _stack_detach(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x28) = 0;
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2547 start=0x4096806 */

void _stack_handoff(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = _stack_detach(param_1);
  _stack_attach(param_2,uVar2,0);
  _active_threads = param_2;
  if ((*(int *)(param_2 + 0xc) != *(int *)(param_1 + 0xc)) &&
     (iVar1 = *(int *)(*(int *)(*(int *)(param_2 + 0xc) + 8) + 0x20), iVar1 != _kernel_pmap)) {
    _pmove_crp(iVar1);
  }
  __stack_handoff(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 0x24));
  return;
}
/* GHIDRADEC_FUNCTION index=2548 start=0x4096872 */

void _switch_context(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  _active_threads = param_3;
  _active_stacks = *(undefined4 *)(param_3 + 0x28);
  _stack_pointers = *(int *)(param_3 + 0x28) + 0xff4;
  if ((*(int *)(param_3 + 0xc) != *(int *)(param_1 + 0xc)) &&
     (iVar1 = *(int *)(*(int *)(*(int *)(param_3 + 0xc) + 8) + 0x20), iVar1 != _kernel_pmap)) {
    _pmove_crp(iVar1);
  }
  *(int *)(param_1 + 0x30) = param_2;
  if (param_2 == 0) {
    __switch_context(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_3 + 0x24),param_1);
  }
  else {
    __switch_context_discard
              (*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_3 + 0x24),param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2549 start=0x40968fa */

void _pcb_module_init(void)

{
  _pcb_zone = _zinit(0x1a0,0x34000,0x6800,0,&aPcb);
  return;
}

