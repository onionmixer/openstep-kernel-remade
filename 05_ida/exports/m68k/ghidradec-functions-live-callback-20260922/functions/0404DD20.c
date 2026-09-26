
void _vmp_push(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  
  if ((*(byte *)(param_1 + 0x34) & 0x40) != 0) {
    *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) & 0xbf;
    iVar2 = *(int *)(param_1 + 0x20);
    if (iVar2 != 0) {
      uVar5 = _page_mask + *(uint *)(param_1 + 0x10) + *(int *)(param_1 + 0xc);
      uVar6 = ~_page_mask;
      uVar10 = uVar6 & *(uint *)(param_1 + 0x10);
      while (uVar10 < (uVar6 & uVar5)) {
        puVar8 = (undefined4 *)_vm_page_lookup(iVar2,uVar10);
        if ((puVar8 == (undefined4 *)0x0) || ((*(byte *)((int)puVar8 + 0x21) & 0x10) != 0)) {
loc_404DE5C:
          uVar10 = _page_size + uVar10;
        }
        else {
          if (-1 < (char)*(byte *)(puVar8 + 8)) {
            if ((*(byte *)((int)puVar8 + 0x1e) & 0x40) == 0) {
              _vm_page_activate(puVar8);
            }
            _vm_page_deactivate(puVar8);
            puVar1 = (undefined4 *)*puVar8;
            puVar3 = (undefined4 *)puVar8[1];
            puVar7 = puVar3;
            if (puVar1 != &_vm_page_queue_inactive) {
              puVar1[1] = puVar3;
              puVar7 = dword_40C23DC;
            }
            dword_40C23DC = puVar7;
            *puVar3 = puVar1;
            *(byte *)((int)puVar8 + 0x1e) = *(byte *)((int)puVar8 + 0x1e) & 0x7f;
            _vm_page_inactive_count = _vm_page_inactive_count + -1;
            *(byte *)(puVar8 + 8) = *(byte *)(puVar8 + 8) | 0x80;
            if ((*(byte *)((int)puVar8 + 0x1e) & 0x20) != 0) {
              _pmap_remove_all(*(undefined4 *)((int)puVar8 + 0x22));
              *(sword *)(iVar2 + 0x40) = *(sword *)(iVar2 + 0x40) + 1;
              iVar9 = _vnode_pageout(puVar8);
              *(sword *)(iVar2 + 0x40) = *(sword *)(iVar2 + 0x40) + -1;
              if (iVar9 == 0) {
                *(byte *)((int)puVar8 + 0x1e) = *(byte *)((int)puVar8 + 0x1e) & 0xdf;
              }
            }
            _vm_page_activate(puVar8);
            bVar4 = *(byte *)(puVar8 + 8);
            *(byte *)(puVar8 + 8) = bVar4 & 0x7f;
            *(byte *)(puVar8 + 8) = bVar4 & 0x7f;
            if ((bVar4 & 0x40) != 0) {
              *(byte *)(puVar8 + 8) = bVar4 & 0x3f;
              _thread_wakeup_prim(puVar8,0,0);
            }
            goto loc_404DE5C;
          }
          *(byte *)(puVar8 + 8) = *(byte *)(puVar8 + 8) | 0x40;
          _assert_wait(puVar8,0);
          _thread_block();
        }
      }
    }
  }
  return;
}

