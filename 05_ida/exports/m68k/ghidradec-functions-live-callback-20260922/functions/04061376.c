
undefined4 * _vm_page_alloc_sequential(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  byte *pbVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  
  puVar4 = _vm_page_queue_free;
  if ((undefined4 **)_vm_page_queue_free == &_vm_page_queue_free) {
    puVar4 = (undefined4 *)0x0;
  }
  else if ((_vm_page_free_count < _vm_page_free_reserved) && (*(int *)(_active_threads + 0x74) == 0)
          ) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)*_vm_page_queue_free;
    if ((undefined4 **)puVar1 == &_vm_page_queue_free) {
      dword_40C2C1C = &_vm_page_queue_free;
    }
    else {
      puVar1[1] = &_vm_page_queue_free;
    }
    pbVar2 = (byte *)((int)_vm_page_queue_free + 0x1e);
    _vm_page_queue_free = puVar1;
    *pbVar2 = *pbVar2 & 0xef;
    _vm_page_free_count = _vm_page_free_count + -1;
    _vm_page_remove(puVar4);
    *puVar4 = _vm_page_template;
    puVar4[1] = dword_40C3294;
    puVar4[2] = dword_40C3298;
    puVar4[3] = dword_40C329C;
    puVar4[4] = dword_40C32A0;
    puVar4[5] = dword_40C32A4;
    puVar4[6] = dword_40C32A8;
    puVar4[7] = dword_40C32AC;
    puVar4[8] = dword_40C32B0;
    puVar4[9] = dword_40C32B4;
    puVar4[10] = dword_40C32B8;
    *(undefined2 *)(puVar4 + 0xb) = word_40C32BC;
    *(undefined4 *)((int)puVar4 + 0x22) = *(undefined4 *)((int)puVar4 + 0x22);
    _vm_page_insert(puVar4,param_1,param_2);
    if ((_vm_page_free_count < _vm_page_free_min) ||
       ((_vm_page_free_count < _vm_page_free_target &&
        (_vm_page_inactive_count < _vm_page_inactive_target)))) {
      _thread_wakeup_prim(&_vm_pages_needed,0,0);
    }
    if (((*(uint *)(param_1 + 0x45) & 0x3fffffff) >> 0x1c != 0) && (param_3 != 0)) {
      iVar5 = param_2 - *(int *)(param_1 + 0x4e);
      if (iVar5 < 0) {
        iVar5 = -iVar5;
      }
      if (iVar5 == _page_size) {
        iVar5 = _vm_page_lookup(param_1,*(int *)(param_1 + 0x4e));
        if (iVar5 != 0) {
          uVar3 = *(uint *)(param_1 + 0x44) >> 0x14 | (*(byte *)(param_1 + 0x43) & 0xf) << 0xc;
          uVar6 = 0;
          if ((uVar3 != 1) && (uVar3 == 2)) {
            uVar6 = 1;
          }
          _vm_policy_apply(param_1,iVar5,uVar6);
        }
      }
    }
    *(int *)(param_1 + 0x4e) = param_2;
  }
  return puVar4;
}

