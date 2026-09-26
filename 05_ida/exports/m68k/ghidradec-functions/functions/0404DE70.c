
void _vmp_push_all(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte bVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) & 0xbf;
  puVar2 = *(undefined4 **)(param_1 + 0x20);
  if (puVar2 == (undefined4 *)0x0) {
    return;
  }
loc_404DE8C:
  puVar7 = (undefined4 *)*puVar2;
  if (puVar7 == puVar2) {
    return;
  }
  do {
    if ((*(byte *)((int)puVar7 + 0x21) & 0x10) == 0) {
      if ((char)*(byte *)(puVar7 + 8) < '\0') break;
      if ((*(byte *)((int)puVar7 + 0x1e) & 0x40) == 0) {
        _vm_page_activate(puVar7);
      }
      _vm_page_deactivate(puVar7);
      puVar1 = (undefined4 *)*puVar7;
      puVar3 = (undefined4 *)puVar7[1];
      puVar5 = puVar3;
      if (puVar1 != &_vm_page_queue_inactive) {
        puVar1[1] = puVar3;
        puVar5 = dword_40C23DC;
      }
      dword_40C23DC = puVar5;
      *puVar3 = puVar1;
      *(byte *)((int)puVar7 + 0x1e) = *(byte *)((int)puVar7 + 0x1e) & 0x7f;
      _vm_page_inactive_count = _vm_page_inactive_count + -1;
      *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) | 0x80;
      if ((*(byte *)((int)puVar7 + 0x1e) & 0x20) != 0) {
        _pmap_remove_all(*(undefined4 *)((int)puVar7 + 0x22));
        *(sword *)(puVar2 + 0x10) = *(sword *)(puVar2 + 0x10) + 1;
        iVar6 = _vnode_pageout(puVar7);
        *(sword *)(puVar2 + 0x10) = *(sword *)(puVar2 + 0x10) + -1;
        if (iVar6 == 0) {
          *(byte *)((int)puVar7 + 0x1e) = *(byte *)((int)puVar7 + 0x1e) & 0xdf;
        }
      }
      _vm_page_activate(puVar7);
      bVar4 = *(byte *)(puVar7 + 8);
      *(byte *)(puVar7 + 8) = bVar4 & 0x7f;
      *(byte *)(puVar7 + 8) = bVar4 & 0x7f;
      if ((bVar4 & 0x40) != 0) {
        *(byte *)(puVar7 + 8) = bVar4 & 0x3f;
        _thread_wakeup_prim(puVar7,0,0);
      }
    }
    puVar7 = (undefined4 *)puVar7[2];
    if (puVar7 == puVar2) {
      return;
    }
  } while( true );
  *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) | 0x40;
  _assert_wait(puVar7,0);
  _thread_block();
  goto loc_404DE8C;
}
