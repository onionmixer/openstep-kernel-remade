/* GHIDRADEC_FUNCTION index=2500 start=0x4093e4a */

void _nmi_prf(undefined4 param_1)

{
  _prf(param_1,&stack0x00000008,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2501 start=0x4093e66 */

void _softint_sched(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _callout_dispatch(param_1,param_2,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=2502 start=0x4093e80 */

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
/* GHIDRADEC_FUNCTION index=2503 start=0x4093fb8 */

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
/* GHIDRADEC_FUNCTION index=2504 start=0x409403e */

void _softint_th(void)

{
  do {
    do {
      _softint_run(4);
    } while (dword_40C957C != 0);
    _thread_sleep(_softint_thread,0,1);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2505 start=0x4094080 */

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
/* GHIDRADEC_FUNCTION index=2506 start=0x4094202 */

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
/* GHIDRADEC_FUNCTION index=2507 start=0x4094332 */

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
/* GHIDRADEC_FUNCTION index=2508 start=0x4094758 */

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
/* GHIDRADEC_FUNCTION index=2509 start=0x40947be */

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
/* GHIDRADEC_FUNCTION index=2510 start=0x40948de */

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
/* GHIDRADEC_FUNCTION index=2511 start=0x409497e */

void _halt_cpu(void)

{
  dword_40B5DD4 = 0;
  stop();
  return;
}
/* GHIDRADEC_FUNCTION index=2512 start=0x4094990 */

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
/* GHIDRADEC_FUNCTION index=2513 start=0x40949b8 */

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
/* GHIDRADEC_FUNCTION index=2514 start=0x40949e0 */

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
/* GHIDRADEC_FUNCTION index=2515 start=0x4094a7c */

undefined4 _miniMonReboot(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2516 start=0x4094a86 */

undefined4 _miniMonHalt(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2517 start=0x4094a90 */

undefined4 _miniMonGdb(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2518 start=0x4094a9a */

void _miniMonTryGetchar(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2519 start=0x4094aa2 */

void _miniMonGetchar(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2520 start=0x4094aaa */

void _miniMonPutchar(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2521 start=0x4094ab2 */

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
/* GHIDRADEC_FUNCTION index=2522 start=0x4094afe */

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
/* GHIDRADEC_FUNCTION index=2523 start=0x40951ec */

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
/* GHIDRADEC_FUNCTION index=2524 start=0x4095456 */

undefined4 _machine_table_setokay(void)

{
  return 0xffffffff;
}

