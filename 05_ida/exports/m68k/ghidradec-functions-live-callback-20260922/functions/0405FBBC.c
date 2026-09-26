
void _vm_object_terminate(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar2 = param_1[7];
  if (iVar2 != 0) {
    if (param_1 == *(undefined4 **)(iVar2 + 0x18)) {
      *(undefined4 *)(iVar2 + 0x18) = 0;
    }
    else if (*(undefined4 **)(iVar2 + 0x18) != (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(aVmObjectTermin);
    }
  }
  while (*(sword *)(param_1 + 0x10) != 0) {
    _thread_sleep(param_1,0,0);
  }
  puVar1 = (undefined4 *)*param_1;
  while (puVar4 = puVar1, puVar4 != param_1) {
    if ((*(byte *)((int)puVar4 + 0x1e) & 0x40) != 0) {
      puVar1 = (undefined4 *)*puVar4;
      puVar3 = (undefined4 *)puVar4[1];
      puVar5 = puVar3;
      if (puVar1 != &_vm_page_queue_active) {
        puVar1[1] = puVar3;
        puVar5 = dword_40C2C14;
      }
      dword_40C2C14 = puVar5;
      *puVar3 = puVar1;
      *(byte *)((int)puVar4 + 0x1e) = *(byte *)((int)puVar4 + 0x1e) & 0xbf;
      _vm_page_active_count = _vm_page_active_count + -1;
    }
    if (*(char *)((int)puVar4 + 0x1e) < '\0') {
      puVar1 = (undefined4 *)*puVar4;
      puVar3 = (undefined4 *)puVar4[1];
      puVar5 = puVar3;
      if (puVar1 != &_vm_page_queue_inactive) {
        puVar1[1] = puVar3;
        puVar5 = dword_40C23DC;
      }
      dword_40C23DC = puVar5;
      *puVar3 = puVar1;
      *(byte *)((int)puVar4 + 0x1e) = *(byte *)((int)puVar4 + 0x1e) & 0x7f;
      _vm_page_inactive_count = _vm_page_inactive_count + -1;
    }
    puVar1 = (undefined4 *)puVar4[2];
    if ((*(byte *)((int)puVar4 + 0x1e) & 0x10) != 0) {
      _vm_page_free(puVar4);
    }
  }
  if (param_1[9] != 0) {
    _vm_pager_deallocate(param_1[9]);
  }
  if (*(sword *)(param_1 + 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmObjectDeallo);
  }
  while (param_1 != (undefined4 *)*param_1) {
    _vm_page_free(*param_1);
  }
  puVar1 = (undefined4 *)param_1[2];
  puVar4 = (undefined4 *)param_1[3];
  puVar3 = puVar4;
  if ((undefined4 **)puVar1 != &_vm_object_list) {
    puVar1[3] = puVar4;
    puVar3 = dword_40C31B0;
  }
  dword_40C31B0 = puVar3;
  if ((undefined4 **)puVar4 != &_vm_object_list) {
    puVar4[2] = puVar1;
    puVar1 = _vm_object_list;
  }
  _vm_object_list = puVar1;
  _vm_object_count = _vm_object_count + -1;
  _zfree(_vm_object_zone,param_1);
  return;
}

