
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

