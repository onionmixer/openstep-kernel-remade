
/* WARNING: Removing unreachable block (ram,0xf0089334) */
/* WARNING: Removing unreachable block (ram,0xf0089298) */
/* WARNING: Removing unreachable block (ram,0xf0089210) */
/* WARNING: Removing unreachable block (ram,0xf0089154) */
/* WARNING: Removing unreachable block (ram,0xf00891b4) */
/* WARNING: Removing unreachable block (ram,0xf0089218) */
/* WARNING: Removing unreachable block (ram,0xf00892f0) */
/* WARNING: Removing unreachable block (ram,0xf0089364) */
/* WARNING: Removing unreachable block (ram,0xf0089130) */

undefined8 _vm_page_alloc_sequential(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  word wVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar3 = param_1;
  _spltty();
  do {
    do {
    } while (_vm_page_queue_free_lock != 0);
    puVar5 = &_vm_page_queue_free_lock;
    _simple_lock_try();
    puVar7 = _vm_page_queue_free;
  } while (puVar5 == (undefined4 *)0x0);
  if (((undefined4 **)_vm_page_queue_free == &_vm_page_queue_free) ||
     ((_vm_page_free_count < _vm_page_free_reserved && (*(int *)(_active_threads + 0x78) == 0)))) {
    _vm_page_queue_free_lock = 0;
    _splx(iVar3);
    puVar7 = (undefined4 *)0x0;
    goto locret_F0089370;
  }
  puVar5 = (undefined4 *)*_vm_page_queue_free;
  if ((undefined4 **)puVar5 == &_vm_page_queue_free) {
    dword_F013CC14 = &_vm_page_queue_free;
  }
  else {
    puVar5[1] = &_vm_page_queue_free;
  }
  puVar1 = _vm_page_queue_free + 7;
  puVar2 = _vm_page_queue_free + 7;
  _vm_page_queue_free = puVar5;
  *puVar2 = *puVar1 & 0xffffefff;
  _vm_page_queue_free_lock = 0;
  _vm_page_free_count = _vm_page_free_count + -1;
  _splx(iVar3);
  _vm_page_remove(puVar7);
  *puVar7 = _vm_page_template;
  puVar7[1] = DAT_f013d954._0_4_;
  puVar7[2] = DAT_f013d954._4_4_;
  puVar7[3] = DAT_f013d954._8_4_;
  puVar7[4] = DAT_f013d954._12_4_;
  puVar7[5] = DAT_f013d954._16_4_;
  puVar7[6] = DAT_f013d954._20_4_;
  puVar7[7] = DAT_f013d954._24_4_;
  uVar6 = puVar7[9];
  puVar7[8] = DAT_f013d954._28_4_;
  puVar7[9] = DAT_f013d954._32_4_;
  puVar7[10] = DAT_f013d954._36_4_;
  puVar7[0xb] = DAT_f013d954._40_4_;
  puVar7[9] = uVar6;
  _vm_page_insert(puVar7,param_1,param_2);
  if (_vm_page_free_count < _vm_page_free_min) {
loc_F00892E4:
    _thread_wakeup_prim(&_vm_pages_needed,0,0);
    wVar4 = *(word *)(param_1 + 0x48);
  }
  else if (_vm_page_free_count < _vm_page_free_target) {
    if (_vm_page_inactive_count < _vm_page_inactive_target) goto loc_F00892E4;
    wVar4 = *(word *)(param_1 + 0x48);
  }
  else {
    wVar4 = *(word *)(param_1 + 0x48);
  }
  if ((wVar4 & 3) != 0) {
    if (param_3 == 0) {
      *(int *)(param_1 + 0x54) = param_2;
      goto locret_F0089370;
    }
    iVar3 = param_2 - *(int *)(param_1 + 0x54);
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 != _page_size) {
      *(int *)(param_1 + 0x54) = param_2;
      goto locret_F0089370;
    }
    iVar3 = param_1;
    _vm_page_lookup();
    if (iVar3 == 0) {
      *(int *)(param_1 + 0x54) = param_2;
      goto locret_F0089370;
    }
    _vm_policy_apply(param_1,iVar3,*(sword *)(param_1 + 0x48) == 2);
  }
  *(int *)(param_1 + 0x54) = param_2;
locret_F0089370:
  return CONCAT44(param_2,puVar7);
}
