
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

