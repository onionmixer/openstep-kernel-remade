
uint * sub_408815A(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int iStack_8;
  
  puVar7 = (uint *)_kalloc(0x3e);
  *(byte *)(param_1 + 0xb) = *(byte *)(param_1 + 0xb) & 0xfd;
  _bcopy(param_1,puVar7,0x3e);
  *(byte *)((int)param_1 + 0x2d) = *(byte *)((int)param_1 + 0x2d) & 0xef;
  *(byte *)(param_1 + 0xb) = *(byte *)(param_1 + 0xb) & 0xdf;
  uVar1 = *param_1;
  uVar4 = param_1[4] - uVar1;
  *param_1 = uVar4 + uVar1;
  param_1[1] = param_1[2] - (uVar4 + uVar1);
  uVar2 = _page_mask;
  uVar6 = ~_page_mask;
  param_1[7] = uVar6 & *param_1;
  if (param_1[4] % _page_size == 0) {
    puVar7[2] = param_1[4];
    puVar7[1] = puVar7[2] - *puVar7;
    puVar7[8] = puVar7[2];
    puVar7[7] = puVar7[2];
  }
  else {
    iVar5 = (uVar6 & uVar2 + param_1[4]) - (uVar6 & uVar1);
    uVar2 = param_1[4];
    _vm_allocate(dword_40C6EBC,&iStack_8,iVar5,1);
    _vm_copy(dword_40C6EBC,uVar1 & ~_page_mask,iVar5,iStack_8);
    if ((*(byte *)((int)param_1 + 0x2d) & 8) != 0) {
      _vm_deallocate(dword_40C6EBC,iStack_8,iVar5);
      _kfree(puVar7,0x3e);
      *param_1 = uVar1;
      param_1[1] = param_1[2] - uVar1;
      return param_1;
    }
    if (_page_size <= uVar4) {
      _vm_deallocate(dword_40C6EBC,uVar1 & ~_page_mask,(uVar6 & uVar2) - (uVar6 & uVar1));
    }
    *puVar7 = iStack_8 + uVar1 % _page_size;
    puVar7[1] = uVar4;
    puVar7[2] = uVar4 + *puVar7;
    uVar1 = ~_page_mask & _page_mask + uVar4 + *puVar7;
    puVar7[7] = uVar1;
    puVar7[8] = uVar1;
  }
  puVar7[4] = puVar7[2];
  puVar7[3] = puVar7[4];
  *(byte *)((int)puVar7 + 0x2d) = *(byte *)((int)puVar7 + 0x2d) | 8;
  *(uint **)((int)puVar7 + 0x32) = param_1;
  *(uint **)((int)param_1 + 0x36) = puVar7;
  puVar3 = *(undefined4 **)((int)puVar7 + 0x36);
  if (puVar3 == (undefined4 *)(param_2 + 0xc)) {
    *puVar3 = puVar7;
  }
  else {
    *(uint **)((int)puVar3 + 0x32) = puVar7;
  }
  return puVar7;
}
