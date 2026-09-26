/* GHIDRADEC_FUNCTION index=1725 start=0x405917e */

undefined4 _mach_host_server(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  *param_2 = (uint)*(byte *)(param_1 + 2);
  param_2[1] = 0x20;
  param_2[2] = *(uint *)(param_1 + 0xc);
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = *(int *)(param_1 + 0x14) + 100;
  param_2[6] = dword_40B0104;
  if ((*(int *)(param_1 + 0x14) - 0xa28U < 0x2a) &&
     (*(code **)(unk_40AD7BC + *(int *)(param_1 + 0x14) * 4) != (code *)0x0)) {
    (**(code **)(unk_40AD7BC + *(int *)(param_1 + 0x14) * 4))(param_1,param_2);
    uVar1 = 1;
  }
  else {
    param_2[7] = 0xfffffed1;
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1726 start=0x40591f8 */

undefined4 _mach_host_server_routine(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(int *)(param_1 + 0x14) - 0xa28;
  if (uVar1 < 0x2a) {
    uVar2 = *(undefined4 *)(unk_40B005C + uVar1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1727 start=0x4059bf0 */

undefined4 _mach_port_server(int param_1,uint *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  *param_2 = (uint)*(byte *)(param_1 + 2);
  param_2[1] = 0x20;
  param_2[2] = *(uint *)(param_1 + 0xc);
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = *(int *)(param_1 + 0x14) + 100;
  param_2[6] = dword_40B020C;
  if ((*(int *)(param_1 + 0x14) - 0xc80U < 0x13) &&
     (pcVar1 = *(code **)(*(int *)(param_1 + 0x14) * 4 + 0x40acfc0), pcVar1 != (code *)0x0)) {
    (*pcVar1)(param_1,param_2);
    uVar2 = 1;
  }
  else {
    param_2[7] = 0xfffffed1;
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1728 start=0x4059c6a */

undefined4 _mach_port_server_routine(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(int *)(param_1 + 0x14) - 0xc80;
  if (uVar1 < 0x13) {
    uVar2 = *(undefined4 *)(unk_40B01C0 + uVar1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1729 start=0x405b72e */

undefined4 _mach_server(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  *param_2 = (uint)*(byte *)(param_1 + 2);
  param_2[1] = 0x20;
  param_2[2] = *(uint *)(param_1 + 0xc);
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = *(int *)(param_1 + 0x14) + 100;
  param_2[6] = dword_40B0590;
  if ((*(int *)(param_1 + 0x14) - 2000U < 0x68) &&
     (*(code **)(unk_40AE4B0 + *(int *)(param_1 + 0x14) * 4) != (code *)0x0)) {
    (**(code **)(unk_40AE4B0 + *(int *)(param_1 + 0x14) * 4))(param_1,param_2);
    uVar1 = 1;
  }
  else {
    param_2[7] = 0xfffffed1;
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1730 start=0x405b7a8 */

undefined4 _mach_server_routine(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(int *)(param_1 + 0x14) - 2000;
  if (uVar1 < 0x68) {
    uVar2 = *(undefined4 *)(unk_40B03F0 + uVar1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1731 start=0x405c08a */

undefined4 _mach_debug_server(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  *param_2 = (uint)*(byte *)(param_1 + 2);
  param_2[1] = 0x20;
  param_2[2] = *(uint *)(param_1 + 0xc);
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = *(int *)(param_1 + 0x14) + 100;
  param_2[6] = dword_40B06B4;
  if ((*(int *)(param_1 + 0x14) - 3000U < 0x16) &&
     (*(code **)(unk_40AD77C + *(int *)(param_1 + 0x14) * 4) != (code *)0x0)) {
    (**(code **)(unk_40AD77C + *(int *)(param_1 + 0x14) * 4))(param_1,param_2);
    uVar1 = 1;
  }
  else {
    param_2[7] = 0xfffffed1;
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1732 start=0x405c104 */

undefined4 _mach_debug_server_routine(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(int *)(param_1 + 0x14) - 3000;
  if (uVar1 < 0x16) {
    uVar2 = *(undefined4 *)(unk_40B065C + uVar1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1733 start=0x405c28a */

void _ux_handler_init(void)

{
  undefined4 uVar1;
  
  _ux_exception_port = 0;
  uVar1 = _kernel_task_create(_kernel_task,0);
  _kernel_thread(uVar1,sub_405C12E,0);
  if (_ux_exception_port == 0) {
    _thread_sleep(&_ux_exception_port,0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1734 start=0x405c2d2 */

undefined4
_catch_exception_raise
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_c;
  undefined4 uStack_8;
  
  uVar2 = 0;
  iStack_c = 0;
  iVar1 = _object_copyin(*(undefined4 *)(_active_threads + 0xc),param_2,6,0,&uStack_8);
  if (iVar1 != 0) {
    iVar1 = _convert_port_to_thread(uStack_8);
    _port_release(uStack_8);
    if (iVar1 != 0) {
      sub_405C390(param_4,param_5,param_6,&iStack_c,*(int *)(iVar1 + 0x80) + 0x6c);
      if (iStack_c != 0) {
        _thread_psignal(iVar1,iStack_c);
      }
      _thread_deallocate(iVar1);
      goto loc_405C368;
    }
  }
  uVar2 = 4;
loc_405C368:
  _port_deallocate_EXTERNAL(dword_40B4DF0,param_3);
  _port_deallocate_EXTERNAL(dword_40B4DF0,param_2);
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1735 start=0x405c43c */

/* WARNING: Removing unreachable block (ram,0x0405cdc6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _vm_fault(int param_1,uint param_2,uint param_3,int param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  sword *psVar2;
  byte bVar3;
  bool bVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined4 *puVar16;
  uint uStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  uint uStack_14;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  uVar12 = 0x2000000;
  dword_40C2404 = dword_40C2404 + 1;
  uVar13 = param_3;
loc_405C454:
  iVar6 = _vm_map_lookup(&param_1,param_2,uVar13,&uStack_8,&iStack_c,&iStack_10,&uStack_14,
                         &iStack_18,&iStack_1c);
  if (iVar6 != 0) {
    return iVar6;
  }
  bVar4 = true;
  if (iStack_18 != 0) {
    uVar13 = uStack_14;
  }
  puVar16 = (undefined4 *)0x0;
  *(sword *)(iStack_c + 0x14) = *(sword *)(iStack_c + 0x14) + 1;
  *(sword *)(iStack_c + 0x40) = *(sword *)(iStack_c + 0x40) + 1;
  iVar6 = iStack_10;
  iVar15 = iStack_c;
loc_405C4CC:
  while (puVar7 = (undefined4 *)_vm_page_lookup(iVar15,iVar6), puVar7 == (undefined4 *)0x0) {
    if ((((*(int *)(iVar15 + 0x24) != 0) && ((param_4 == 0 || (iStack_18 != 0)))) ||
        (iVar15 == iStack_c)) &&
       (puVar7 = (undefined4 *)_vm_page_alloc_sequential(iVar15,iVar6,1),
       puVar7 == (undefined4 *)0x0)) {
      *(sword *)(iVar15 + 0x40) = *(sword *)(iVar15 + 0x40) + -1;
      goto loc_405CB1C;
    }
    if ((*(int *)(iVar15 + 0x24) != 0) && ((param_4 == 0 || (iStack_18 != 0)))) {
      if (bVar4) {
        _vm_map_lookup_done(param_1,uStack_8);
        bVar4 = false;
      }
      uVar12 = uVar12 | 0x10;
      iVar8 = _vm_pager_get(*(undefined4 *)(iVar15 + 0x24),puVar7,param_5);
      if (iVar8 != 0) {
        if (iVar8 == 2) {
          bVar3 = *(byte *)(puVar7 + 8);
          goto loc_405C766;
        }
        if (iVar15 != iStack_c) {
          bVar3 = *(byte *)(puVar7 + 8);
          *(byte *)(puVar7 + 8) = bVar3 & 0x7f;
          if ((bVar3 & 0x40) != 0) {
            *(byte *)(puVar7 + 8) = bVar3 & 0x3f;
            _thread_wakeup_prim(puVar7,0,0);
          }
          _vm_page_free(puVar7);
          goto loc_405C840;
        }
        goto loc_405C846;
      }
      puVar7 = (undefined4 *)_vm_page_lookup(iVar15,iVar6);
      dword_40C23FC = dword_40C23FC + 1;
      _pmap_clear_modify(*(undefined4 *)((int)puVar7 + 0x22));
      goto loc_405C894;
    }
loc_405C840:
    if (iVar15 == iStack_c) {
loc_405C846:
      puVar16 = puVar7;
    }
    iVar6 = *(int *)(iVar15 + 0x20) + iVar6;
    iVar8 = *(int *)(iVar15 + 0x1c);
    if (iVar8 == 0) {
      if (iStack_c != iVar15) {
        *(sword *)(iVar15 + 0x40) = *(sword *)(iVar15 + 0x40) + -1;
        puVar7 = puVar16;
        iVar15 = iStack_c;
      }
      puVar16 = (undefined4 *)0x0;
      _vm_page_zero_fill(puVar7);
      uVar12 = uVar12 | 8;
      dword_40C23F4 = dword_40C23F4 + 1;
      *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) & 0xfb;
      goto loc_405C894;
    }
    if (iVar15 != iStack_c) {
      *(sword *)(iVar15 + 0x40) = *(sword *)(iVar15 + 0x40) + -1;
    }
loc_405C88A:
    *(sword *)(iVar8 + 0x40) = *(sword *)(iVar8 + 0x40) + 1;
    iVar15 = iVar8;
  }
  bVar3 = *(byte *)(puVar7 + 8);
  if ((bVar3 & 2) != 0) {
loc_405C766:
    *(byte *)(puVar7 + 8) = bVar3 & 0x7f;
    if ((bVar3 & 0x40) != 0) {
      *(byte *)(puVar7 + 8) = bVar3 & 0x3f;
      _thread_wakeup_prim(puVar7,0,0);
    }
    _vm_page_free(puVar7);
    *(sword *)(iVar15 + 0x40) = *(sword *)(iVar15 + 0x40) + -1;
    goto loc_405C79C;
  }
  if (-1 < (char)bVar3) {
    if ((bVar3 & 4) != 0) {
      iVar6 = *(int *)(iVar15 + 0x20) + iVar6;
      iVar8 = *(int *)(iVar15 + 0x1c);
      if (iVar8 != 0) {
        if (iVar15 == iStack_c) {
          *(byte *)(puVar7 + 8) = bVar3 & 0xfb;
          puVar16 = puVar7;
        }
        else {
          *(sword *)(iVar15 + 0x40) = *(sword *)(iVar15 + 0x40) + -1;
          bVar3 = *(byte *)(puVar7 + 8);
          *(byte *)(puVar7 + 8) = bVar3 & 0x7f;
          if ((bVar3 & 0x40) != 0) {
            *(byte *)(puVar7 + 8) = bVar3 & 0x3f;
            _thread_wakeup_prim(puVar7,0,0);
          }
          _vm_page_free(puVar7);
        }
        goto loc_405C88A;
      }
      if (iVar15 != iStack_c) {
        *(byte *)(puVar7 + 8) = bVar3 & 0x7b;
        *(byte *)(puVar7 + 8) = bVar3 & 0x7b;
        if ((bVar3 & 0x40) != 0) {
          *(byte *)(puVar7 + 8) = bVar3 & 0x3b;
          _thread_wakeup_prim(puVar7,0,0);
        }
        _vm_page_free(puVar7);
        *(sword *)(iVar15 + 0x40) = *(sword *)(iVar15 + 0x40) + -1;
        puVar7 = puVar16;
        iVar15 = iStack_c;
      }
      puVar16 = (undefined4 *)0x0;
      uVar12 = uVar12 | 8;
      _vm_page_zero_fill(puVar7);
      dword_40C23F4 = dword_40C23F4 + 1;
      *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) & 0xfb;
    }
    if ((*(uint *)((int)puVar7 + 0x26) & uVar13) != 0) {
      *(sword *)(iVar15 + 0x40) = *(sword *)(iVar15 + 0x40) + -1;
loc_405C79C:
      if (iVar15 != iStack_c) {
        bVar3 = *(byte *)(puVar16 + 8);
        *(byte *)(puVar16 + 8) = bVar3 & 0x7f;
        if ((bVar3 & 0x40) != 0) {
          *(byte *)(puVar16 + 8) = bVar3 & 0x3f;
          _thread_wakeup_prim(puVar16,0,0);
        }
        _vm_page_free(puVar16);
        *(sword *)(iStack_c + 0x40) = *(sword *)(iStack_c + 0x40) + -1;
      }
      if (bVar4) {
        _vm_map_lookup_done(param_1,uStack_8);
      }
      _vm_object_deallocate(iStack_c);
      return 10;
    }
    if (*(char *)((int)puVar7 + 0x1e) < '\0') {
      puVar14 = (undefined4 *)*puVar7;
      puVar1 = (undefined4 *)puVar7[1];
      puVar5 = puVar1;
      if (puVar14 != &_vm_page_queue_inactive) {
        puVar14[1] = puVar1;
        puVar5 = dword_40C23DC;
      }
      dword_40C23DC = puVar5;
      *puVar1 = puVar14;
      *(byte *)((int)puVar7 + 0x1e) = *(byte *)((int)puVar7 + 0x1e) & 0x7f;
      _vm_page_inactive_count = _vm_page_inactive_count - 1;
      dword_40C23F8 = dword_40C23F8 + 1;
      uVar12 = uVar12 | 1;
    }
    if ((*(byte *)((int)puVar7 + 0x1e) & 0x40) != 0) {
      puVar14 = (undefined4 *)*puVar7;
      puVar1 = (undefined4 *)puVar7[1];
      puVar5 = puVar1;
      if (puVar14 != &_vm_page_queue_active) {
        puVar14[1] = puVar1;
        puVar5 = dword_40C2C14;
      }
      dword_40C2C14 = puVar5;
      *puVar1 = puVar14;
      *(byte *)((int)puVar7 + 0x1e) = *(byte *)((int)puVar7 + 0x1e) & 0xbf;
      _vm_page_active_count = _vm_page_active_count + -1;
    }
    if ((*(byte *)((int)puVar7 + 0x1e) & 0x10) != 0) {
      puVar14 = (undefined4 *)*puVar7;
      puVar1 = (undefined4 *)puVar7[1];
      puVar5 = puVar1;
      if (puVar14 != &_vm_page_queue_free) {
        puVar14[1] = puVar1;
        puVar5 = dword_40C2C1C;
      }
      dword_40C2C1C = puVar5;
      *puVar1 = puVar14;
      *(byte *)((int)puVar7 + 0x1e) = *(byte *)((int)puVar7 + 0x1e) & 0xef;
      _vm_page_free_count = _vm_page_free_count - 1;
      dword_40C23F8 = dword_40C23F8 + 1;
      uVar12 = uVar12 | 2;
    }
    *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) & 0xfb | 0x80;
loc_405C894:
    if ((((*(byte *)(puVar7 + 8) & 4) != 0) || ((*(byte *)((int)puVar7 + 0x1e) & 0xc0) != 0)) ||
       (-1 < (char)*(byte *)(puVar7 + 8))) {
                    /* WARNING: Subroutine does not return */
      _panic(aVmFaultAbsentO);
    }
    puVar14 = puVar7;
    if (iVar15 != iStack_c) {
      if ((uVar13 & 2) == 0) {
        uStack_14 = uStack_14 & 0xfffffffd;
        *(byte *)((int)puVar7 + 0x21) = *(byte *)((int)puVar7 + 0x21) | 0x20;
      }
      else {
        uVar12 = uVar12 | 0x20;
        _vm_page_copy(puVar7,puVar16);
        *(byte *)(puVar16 + 8) = *(byte *)(puVar16 + 8) & 0xfb;
        _vm_page_activate(puVar7);
        _vm_page_deactivate(puVar7);
        if (iStack_1c == 0) {
          _pmap_remove_all(*(undefined4 *)((int)puVar7 + 0x22));
        }
        bVar3 = *(byte *)(puVar7 + 8);
        *(byte *)(puVar7 + 8) = bVar3 & 0x7f;
        if ((bVar3 & 0x40) != 0) {
          *(byte *)(puVar7 + 8) = bVar3 & 0x3f;
          _thread_wakeup_prim(puVar7,0,0);
        }
        iVar6 = iStack_c;
        *(sword *)(iVar15 + 0x40) = *(sword *)(iVar15 + 0x40) + -1;
        dword_40C2408 = dword_40C2408 + 1;
        *(sword *)(iStack_c + 0x40) = *(sword *)(iStack_c + 0x40) + -1;
        _vm_object_collapse(iStack_c);
        psVar2 = (sword *)(iVar6 + 0x40);
        *psVar2 = *psVar2 + 1;
        puVar14 = puVar16;
        iVar15 = iVar6;
      }
    }
    if ((*(byte *)((int)puVar14 + 0x1e) & 0xc0) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aVmFaultActiveO);
    }
    goto loc_405C97C;
  }
  *(byte *)(puVar7 + 8) = bVar3 | 0x40;
  _assert_wait(puVar7,-(int)-(param_4 == 0));
  if (bVar4) {
    _vm_map_lookup_done(param_1,uStack_8);
    bVar4 = false;
  }
  _thread_block();
  if (*(int *)(_active_threads + 0x40) != 4) {
    if (*(int *)(_active_threads + 0x40) != 0) goto loc_405D00C;
    goto loc_405C4CC;
  }
  *(sword *)(iVar15 + 0x40) = *(sword *)(iVar15 + 0x40) + -1;
  goto loc_405CE62;
loc_405C97C:
  iVar6 = *(int *)(iStack_c + 0x18);
  if (iVar6 == 0) goto loc_405CCF0;
  uVar12 = uVar12 | 0x40;
  if ((uVar13 & 2) == 0) {
    uStack_14 = uStack_14 & 0xfffffffd;
    *(byte *)((int)puVar14 + 0x21) = *(byte *)((int)puVar14 + 0x21) | 0x20;
    goto loc_405CCF0;
  }
  *(sword *)(iVar6 + 0x14) = *(sword *)(iVar6 + 0x14) + 1;
  iVar8 = iStack_10 - *(int *)(iVar6 + 0x20);
  iVar9 = _vm_page_lookup(iVar6,iVar8);
  iVar10 = -(int)-(iVar9 != 0);
  if (iVar10 != 0) {
    if ((char)*(byte *)(iVar9 + 0x20) < '\0') {
      *(byte *)(iVar9 + 0x20) = *(byte *)(iVar9 + 0x20) | 0x40;
      _assert_wait(iVar9,-(int)-(param_4 == 0));
      bVar3 = *(byte *)(puVar14 + 8);
      *(byte *)(puVar14 + 8) = bVar3 & 0x7f;
      if ((bVar3 & 0x40) != 0) {
        *(byte *)(puVar14 + 8) = bVar3 & 0x3f;
        _thread_wakeup_prim(puVar14,0,0);
      }
      _vm_page_activate(puVar14);
      *(sword *)(iVar6 + 0x14) = *(sword *)(iVar6 + 0x14) + -1;
      *(sword *)(iVar15 + 0x40) = *(sword *)(iVar15 + 0x40) + -1;
      if (iVar15 != iStack_c) {
        bVar3 = *(byte *)(puVar16 + 8);
        *(byte *)(puVar16 + 8) = bVar3 & 0x7f;
        if ((bVar3 & 0x40) != 0) {
          *(byte *)(puVar16 + 8) = bVar3 & 0x3f;
          _thread_wakeup_prim(puVar16,0,0);
        }
        _vm_page_free(puVar16);
        *(sword *)(iStack_c + 0x40) = *(sword *)(iStack_c + 0x40) + -1;
      }
      if (bVar4) {
        _vm_map_lookup_done(param_1,uStack_8);
      }
      _thread_block();
      iVar6 = *(int *)(_active_threads + 0x40);
      _vm_object_deallocate(iStack_c);
      if (iVar6 != 0) {
        return 0;
      }
      goto loc_405C454;
    }
    if (iVar10 == 0) goto loc_405CAC0;
loc_405CCE4:
    *(sword *)(iVar6 + 0x14) = *(sword *)(iVar6 + 0x14) + -1;
    *(byte *)((int)puVar14 + 0x21) = *(byte *)((int)puVar14 + 0x21) & 0xdf;
    goto loc_405CCF0;
  }
loc_405CAC0:
  iVar9 = _vm_page_alloc_sequential(iVar6,iVar8,1);
  if (iVar9 != 0) {
    if (*(int *)(iVar6 + 0x24) == 0) {
loc_405CC7A:
      if (iVar10 == 0) {
loc_405CC7E:
        _vm_page_copy(puVar14,iVar9);
        *(byte *)(iVar9 + 0x20) = *(byte *)(iVar9 + 0x20) & 0xfb;
        _pmap_remove_all(*(undefined4 *)((int)puVar7 + 0x22));
        *(byte *)(iVar9 + 0x1e) = *(byte *)(iVar9 + 0x1e) & 0xfb;
        _vm_page_activate(iVar9);
        bVar3 = *(byte *)(iVar9 + 0x20);
        *(byte *)(iVar9 + 0x20) = bVar3 & 0x7f;
        if ((bVar3 & 0x40) != 0) {
          *(byte *)(iVar9 + 0x20) = bVar3 & 0x3f;
          _thread_wakeup_prim(iVar9,0,0);
        }
      }
      goto loc_405CCE4;
    }
    if (bVar4) {
      _vm_map_lookup_done(param_1,uStack_8);
      bVar4 = false;
    }
    iVar10 = _vm_pager_has_page(*(undefined4 *)(iVar6 + 0x24),*(int *)(iVar6 + 0x28) + iVar8);
    if ((iVar15 == *(int *)(iVar6 + 0x1c)) && (*(sword *)(iVar6 + 0x14) != 1)) {
      if (iVar10 != 0) {
        bVar3 = *(byte *)(iVar9 + 0x20);
        *(byte *)(iVar9 + 0x20) = bVar3 & 0x7f;
        if ((bVar3 & 0x40) != 0) {
          *(byte *)(iVar9 + 0x20) = bVar3 & 0x3f;
          _thread_wakeup_prim(iVar9,0,0);
        }
        _vm_page_free(iVar9);
        goto loc_405CC7A;
      }
      goto loc_405CC7E;
    }
    bVar3 = *(byte *)(iVar9 + 0x20);
    *(byte *)(iVar9 + 0x20) = bVar3 & 0x7f;
    if ((bVar3 & 0x40) != 0) {
      *(byte *)(iVar9 + 0x20) = bVar3 & 0x3f;
      _thread_wakeup_prim(iVar9,0,0);
    }
    _vm_page_free(iVar9);
    _vm_object_deallocate(iVar6);
    goto loc_405C97C;
  }
  bVar3 = *(byte *)(puVar14 + 8);
  *(byte *)(puVar14 + 8) = bVar3 & 0x7f;
  if ((bVar3 & 0x40) != 0) {
    *(byte *)(puVar14 + 8) = bVar3 & 0x3f;
    _thread_wakeup_prim(puVar14,0,0);
  }
  _vm_page_activate(puVar14);
  *(sword *)(iVar6 + 0x14) = *(sword *)(iVar6 + 0x14) + -1;
  *(sword *)(iVar15 + 0x40) = *(sword *)(iVar15 + 0x40) + -1;
loc_405CB1C:
  if (iVar15 != iStack_c) {
    bVar3 = *(byte *)(puVar16 + 8);
    *(byte *)(puVar16 + 8) = bVar3 & 0x7f;
    if ((bVar3 & 0x40) != 0) {
      *(byte *)(puVar16 + 8) = bVar3 & 0x3f;
      _thread_wakeup_prim(puVar16,0,0);
    }
    _vm_page_free(puVar16);
    *(sword *)(iStack_c + 0x40) = *(sword *)(iStack_c + 0x40) + -1;
  }
  if (bVar4) {
    _vm_map_lookup_done(param_1,uStack_8);
  }
  _vm_object_deallocate(iStack_c);
  _thread_wakeup_prim(&_vm_pages_needed,0,0);
  _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
  goto loc_405C454;
loc_405CCF0:
  if ((*(byte *)((int)puVar14 + 0x1e) & 0xc0) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmFaultActiveO_0);
  }
  if (!bVar4) {
    iVar6 = _vm_map_lookup(&param_1,param_2,uVar13 & 0xfffffffd,&uStack_8,&iStack_20,&iStack_24,
                           &uStack_28,&iStack_18,&iStack_1c);
    if (iVar6 != 0) {
      bVar3 = *(byte *)(puVar14 + 8);
      *(byte *)(puVar14 + 8) = bVar3 & 0x7f;
      if ((bVar3 & 0x40) != 0) {
        *(byte *)(puVar14 + 8) = bVar3 & 0x3f;
        _thread_wakeup_prim(puVar14,0,0);
      }
      _vm_page_activate(puVar14);
      *(sword *)(iVar15 + 0x40) = *(sword *)(iVar15 + 0x40) + -1;
      if (iVar15 != iStack_c) {
        bVar3 = *(byte *)(puVar16 + 8);
        *(byte *)(puVar16 + 8) = bVar3 & 0x7f;
        if ((bVar3 & 0x40) != 0) {
          *(byte *)(puVar16 + 8) = bVar3 & 0x3f;
          _thread_wakeup_prim(puVar16,0,0);
        }
        _vm_page_free(puVar16);
        *(sword *)(iStack_c + 0x40) = *(sword *)(iStack_c + 0x40) + -1;
      }
      _vm_object_deallocate(iStack_c);
      return iVar6;
    }
    bVar4 = true;
    if ((iStack_20 == iStack_c) && (iStack_24 == iStack_10)) {
      uStack_14 = uStack_28 & uStack_14;
      if ((*(byte *)((int)puVar14 + 0x21) & 0x20) != 0) {
        uStack_14 = uStack_14 & 0xfffffffd;
      }
      if ((iStack_18 == 0) || (uVar13 == uStack_14)) goto loc_405CECA;
    }
    bVar3 = *(byte *)(puVar14 + 8);
    *(byte *)(puVar14 + 8) = bVar3 & 0x7f;
    if ((bVar3 & 0x40) != 0) {
      *(byte *)(puVar14 + 8) = bVar3 & 0x3f;
      _thread_wakeup_prim(puVar14,0,0);
    }
    _vm_page_activate(puVar14);
    *(sword *)(iVar15 + 0x40) = *(sword *)(iVar15 + 0x40) + -1;
loc_405CE62:
    if (iVar15 != iStack_c) {
      bVar3 = *(byte *)(puVar16 + 8);
      *(byte *)(puVar16 + 8) = bVar3 & 0x7f;
      if ((bVar3 & 0x40) != 0) {
        *(byte *)(puVar16 + 8) = bVar3 & 0x3f;
        _thread_wakeup_prim(puVar16,0,0);
      }
      _vm_page_free(puVar16);
      *(sword *)(iStack_c + 0x40) = *(sword *)(iStack_c + 0x40) + -1;
    }
    if (bVar4) {
      _vm_map_lookup_done(param_1,uStack_8);
    }
    _vm_object_deallocate(iStack_c);
    goto loc_405C454;
  }
loc_405CECA:
  bVar4 = true;
  if ((uStack_14 & 2) != 0) {
    *(byte *)((int)puVar14 + 0x21) = *(byte *)((int)puVar14 + 0x21) & 0xdf;
  }
  if ((*(byte *)((int)puVar14 + 0x1e) & 0xc0) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmFaultActiveO_1);
  }
  if ((uStack_14 & 2) != 0) {
    uVar12 = uVar12 | 0x100;
  }
  uVar13 = _vmlog_send & 1;
  _vmlog_send = _vmlog_send + 1;
  uVar11 = _vm_page_free_count;
  if (uVar13 == 0) {
    uVar11 = _vm_page_inactive_count | 0x8000;
  }
  if ((_byte_40B60C0 & 0x1000000) != 0) {
    _pmonlogcontextflush(0x11,0x1000000);
  }
  if ((uVar12 & _byte_40B60C0) != 0) {
    _pmonlogevent(0x11,uVar12,
                  *(uint *)((int)puVar14 + 0x22) >> (_page_shift & 0x3f) |
                  (param_2 >> (_page_shift & 0x3f)) << 0x10,
                  uVar11 | *(int *)(*(int *)(param_1 + 0x20) + 0x10) << 0x10,_active_threads);
  }
  _pmap_enter(*(undefined4 *)(param_1 + 0x20),param_2,*(undefined4 *)((int)puVar14 + 0x22),
              uStack_14 & ~*(uint *)((int)puVar14 + 0x26),iStack_18);
  if (param_4 == 0) {
    _vm_page_activate(puVar14);
  }
  else if (iStack_18 == 0) {
    _vm_page_unwire(puVar14);
  }
  else {
    _vm_page_wire(puVar14);
  }
  bVar3 = *(byte *)(puVar14 + 8);
  *(byte *)(puVar14 + 8) = bVar3 & 0x7f;
  if ((bVar3 & 0x40) != 0) {
    *(byte *)(puVar14 + 8) = bVar3 & 0x3f;
    _thread_wakeup_prim(puVar14,0,0);
  }
loc_405D00C:
  *(sword *)(iVar15 + 0x40) = *(sword *)(iVar15 + 0x40) + -1;
  if (iVar15 != iStack_c) {
    bVar3 = *(byte *)(puVar16 + 8);
    *(byte *)(puVar16 + 8) = bVar3 & 0x7f;
    if ((bVar3 & 0x40) != 0) {
      *(byte *)(puVar16 + 8) = bVar3 & 0x3f;
      _thread_wakeup_prim(puVar16,0,0);
    }
    _vm_page_free(puVar16);
    *(sword *)(iStack_c + 0x40) = *(sword *)(iStack_c + 0x40) + -1;
  }
  if (bVar4) {
    _vm_map_lookup_done(param_1,uStack_8);
  }
  _vm_object_deallocate(iStack_c);
  return 0;
}
/* GHIDRADEC_FUNCTION index=1736 start=0x405d07e */

void _vm_fault_wire(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = *(uint *)(param_2 + 0xc);
  _pmap_pageable(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_2 + 8),uVar1,0);
  for (uVar2 = *(uint *)(param_2 + 8); uVar2 < uVar1; uVar2 = _page_size + uVar2) {
    iVar3 = _vm_fault_wire_fast(param_1,uVar2,param_2);
    if (iVar3 != 0) {
      _vm_fault(param_1,uVar2,0,1,0);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1737 start=0x405d0ee */

void _vm_fault_unwire(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar1 = *(uint *)(param_2 + 0xc);
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  uVar3 = *(uint *)(param_2 + 8);
  while( true ) {
    if (uVar1 <= uVar3) {
      _pmap_pageable(uVar2,*(undefined4 *)(param_2 + 8),uVar1,1);
      return;
    }
    iVar4 = _pmap_extract(uVar2,uVar3);
    if (iVar4 == 0) break;
    _pmap_change_wiring(uVar2,uVar3,0);
    uVar5 = _vm_phys_to_vm_page(iVar4);
    _vm_page_unwire(uVar5);
    uVar3 = _page_size + uVar3;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aUnwirePageNotI);
}
/* GHIDRADEC_FUNCTION index=1738 start=0x405d172 */

void _vm_fault_copy_entry(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  uVar1 = *(undefined4 *)(param_4 + 0x10);
  iVar2 = *(int *)(param_4 + 0x14);
  uVar5 = _vm_object_allocate(*(int *)(param_3 + 0xc) - *(int *)(param_3 + 8));
  *(undefined4 *)(param_3 + 0x10) = uVar5;
  *(undefined4 *)(param_3 + 0x14) = 0;
  uVar3 = *(undefined4 *)(param_3 + 0x1e);
  uVar8 = *(uint *)(param_3 + 8);
  iVar9 = 0;
  if (uVar8 < *(uint *)(param_3 + 0xc)) {
    do {
      while( true ) {
        iVar6 = _vm_page_alloc_sequential(uVar5,iVar9,1);
        if (iVar6 != 0) break;
        _thread_wakeup_prim(&_vm_pages_needed,0,0);
        _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
      }
      iVar7 = _vm_page_lookup(uVar1,iVar2 + iVar9);
      if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aVmFaultCopyWir);
      }
      _vm_page_copy(iVar7,iVar6);
      _pmap_enter(*(undefined4 *)(param_1 + 0x20),uVar8,*(undefined4 *)(iVar6 + 0x22),uVar3,0);
      _vm_page_activate(iVar6);
      bVar4 = *(byte *)(iVar6 + 0x20);
      *(byte *)(iVar6 + 0x20) = bVar4 & 0x7f;
      if ((bVar4 & 0x40) != 0) {
        *(byte *)(iVar6 + 0x20) = bVar4 & 0x3f;
        _thread_wakeup_prim(iVar6,0,0);
      }
      uVar8 = _page_size + uVar8;
      iVar9 = _page_size + iVar9;
    } while (uVar8 < *(uint *)(param_3 + 0xc));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1739 start=0x405d292 */

undefined4 _vm_fault_wire_fast(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iStack_1c;
  
  dword_40C2404 = dword_40C2404 + 1;
  if ((*(byte *)(param_3 + 0x18) & 0xa0) != 0) {
    return 5;
  }
  iVar1 = *(int *)(param_3 + 0x10);
  iStack_1c = *(int *)(param_3 + 0x14) + (param_2 - *(int *)(param_3 + 8));
  uVar2 = *(uint *)(param_3 + 0x1a);
  *(sword *)(iVar1 + 0x14) = *(sword *)(iVar1 + 0x14) + 1;
  *(sword *)(iVar1 + 0x40) = *(sword *)(iVar1 + 0x40) + 1;
  iVar4 = _vm_page_lookup(iVar1);
  piVar6 = (int *)&stack0xffffffe8;
  if (((iVar4 == 0) || (piVar6 = (int *)&stack0xffffffe8, (*(byte *)(iVar4 + 0x20) & 0x84) != 0)) ||
     (piVar6 = (int *)&stack0xffffffe8, (*(uint *)(iVar4 + 0x26) & uVar2) != 0)) {
loc_405D35A:
    *(sword *)(iVar1 + 0x40) = *(sword *)(iVar1 + 0x40) + -1;
    *(int *)((int)piVar6 + -4) = iVar1;
    *(undefined4 *)((int)piVar6 + -8) = 0x405d366;
    _vm_object_deallocate();
    uVar5 = 5;
  }
  else {
    iStack_1c = iVar4;
    _vm_page_wire();
    bVar3 = *(byte *)(iVar4 + 0x20);
    *(byte *)(iVar4 + 0x20) = bVar3 & 0xfb | 0x80;
    if (*(int *)(iVar1 + 0x18) != 0) {
      if ((uVar2 & 2) != 0) {
        *(byte *)(iVar4 + 0x20) = bVar3 & 0x7b;
        if ((bVar3 & 0x40) != 0) {
          *(byte *)(iVar4 + 0x20) = bVar3 & 0x3b;
          iStack_1c = 0;
          _thread_wakeup_prim(iVar4,0);
        }
        piVar6 = &iStack_1c;
        iStack_1c = iVar4;
        _vm_page_unwire();
        goto loc_405D35A;
      }
      *(byte *)(iVar4 + 0x21) = *(byte *)(iVar4 + 0x21) | 0x20;
    }
    if ((uVar2 & 2) != 0) {
      *(byte *)(iVar4 + 0x21) = *(byte *)(iVar4 + 0x21) & 0xdf;
    }
    iStack_1c = 1;
    _pmap_enter(*(undefined4 *)(param_1 + 0x20),param_2,*(undefined4 *)(iVar4 + 0x22),uVar2);
    bVar3 = *(byte *)(iVar4 + 0x20);
    *(byte *)(iVar4 + 0x20) = bVar3 & 0x7f;
    if ((bVar3 & 0x40) != 0) {
      *(byte *)(iVar4 + 0x20) = bVar3 & 0x3f;
      iStack_1c = 0;
      _thread_wakeup_prim(iVar4,0);
    }
    *(sword *)(iVar1 + 0x40) = *(sword *)(iVar1 + 0x40) + -1;
    iStack_1c = iVar1;
    _vm_object_deallocate();
    uVar5 = 0;
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=1740 start=0x405d3d4 */

void _vm_mem_init(void)

{
  _virtual_avail = _vm_page_startup(_mem_region,_num_regions,_virtual_avail);
  _zone_bootstrap();
  _vm_object_init();
  _vm_map_init();
  _kmem_init(_virtual_avail,_virtual_end);
  _pmap_init(_mem_region,_num_regions);
  _zone_init();
  _kalloc_init();
  _vm_pager_init();
  _vm_user_init();
  return;
}
/* GHIDRADEC_FUNCTION index=1741 start=0x405d592 */

void _kmem_alloc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = _vm_object_allocate(param_3);
  sub_405D448(param_1,param_2,param_3,1,uVar1,1);
  return;
}
/* GHIDRADEC_FUNCTION index=1742 start=0x405d5ce */

int _kmem_realloc(undefined4 param_1,uint param_2,int param_3,int *param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  uVar3 = ~_page_mask;
  iVar2 = (uVar3 & _page_mask + param_3 + param_2) - (uVar3 & param_2);
  uVar1 = param_5 + _page_mask & uVar3;
  iVar4 = _vm_map_find(param_1,0,0,&iStack_8,uVar1,1);
  iVar4 = -(int)-(iVar4 != 0);
  if (iVar4 == 0) {
    _vm_map_lookup_entry(param_1,iStack_8,&iStack_c);
    iVar4 = _vm_map_lookup_entry(param_1,uVar3 & param_2,&iStack_10);
    if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aKmemRealloc);
    }
    iVar4 = *(int *)(iStack_10 + 0x10);
    _vm_object_reference(iVar4);
    if (iVar2 != *(int *)(iVar4 + 0x10)) {
                    /* WARNING: Subroutine does not return */
      _panic(aKmemRealloc);
    }
    *(uint *)(iVar4 + 0x10) = uVar1;
    *(int *)(iStack_c + 0x10) = iVar4;
    *(undefined4 *)(iStack_c + 0x14) = 0;
    _lock_done(param_1);
    sub_405D774(iVar4,iVar2,uVar1,1);
    _vm_map_pageable(param_1,iStack_8,iStack_8 + uVar1,0);
    *param_4 = iStack_8;
    iVar4 = 0;
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=1743 start=0x405d6cc */

void _kmem_alloc_wired(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  sub_405D448(param_1,param_2,param_3,1,_kernel_object,1);
  return;
}
/* GHIDRADEC_FUNCTION index=1744 start=0x405d6f4 */

int _kmem_alloc_pageable(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  uStack_8 = *(undefined4 *)(param_1 + 0x10);
  iVar1 = _vm_map_find(param_1,0,0,&uStack_8,~_page_mask & _page_mask + param_3,1);
  if (iVar1 == 0) {
    *param_2 = uStack_8;
    iVar1 = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1745 start=0x405d740 */

void _kmem_free(undefined4 param_1,uint param_2,int param_3)

{
  _vm_map_remove(param_1,~_page_mask & param_2,~_page_mask & _page_mask + param_3 + param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=1746 start=0x405d804 */

int _kmem_suballoc(int param_1,int *param_2,int *param_3,int param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_8;
  
  uVar1 = ~_page_mask & _page_mask + param_4;
  _vm_object_reference(_vm_submap_object);
  iStack_8 = *(int *)(param_1 + 0x10);
  iVar2 = _vm_map_find(param_1,_vm_submap_object,0,&iStack_8,uVar1,1);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aKmemSuballoc1);
  }
  _pmap_reference(*(undefined4 *)(param_1 + 0x20));
  iVar2 = _vm_map_create(*(undefined4 *)(param_1 + 0x20),iStack_8,iStack_8 + uVar1,param_5);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aKmemSuballoc2);
  }
  iVar3 = _vm_map_submap(param_1,iStack_8,iStack_8 + uVar1,iVar2);
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aKmemSuballoc3);
  }
  *param_2 = iStack_8;
  *param_3 = iStack_8 + uVar1;
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=1747 start=0x405d8e2 */

void _kmem_init(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uStack_8;
  
  uVar1 = _pmap_kernel(0x10000000,param_2,0);
  _kernel_map = _vm_map_create(uVar1);
  uStack_8 = 0x10000000;
  _vm_map_find(_kernel_map,0,0,&uStack_8,param_1 + -0x10000000,0);
  return;
}
/* GHIDRADEC_FUNCTION index=1748 start=0x405d936 */

undefined4 _copyinmap(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x20) == _kernel_pmap) {
    _bcopy(param_2,param_3,param_4);
    uVar1 = 0;
  }
  else if (param_1 == *(int *)(*(int *)(_active_threads + 0xc) + 8)) {
    uVar1 = _copyinmsg(param_2,param_3,param_4);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1749 start=0x405d996 */

undefined4 _copyoutmap(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x20) == _kernel_pmap) {
    _bcopy(param_2,param_3,param_4);
    uVar1 = 0;
  }
  else if (param_1 == *(int *)(*(int *)(_active_threads + 0xc) + 8)) {
    uVar1 = _copyoutmsg(param_2,param_3,param_4);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

