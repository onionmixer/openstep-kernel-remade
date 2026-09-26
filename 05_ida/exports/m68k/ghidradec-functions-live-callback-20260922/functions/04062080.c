
undefined4
_vm_object_special(sword param_1,code *param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  uVar1 = ~_page_mask & _page_mask + param_5;
  uVar6 = uVar1 >> (_page_shift & 0x3f);
  uVar2 = _vm_object_allocate(uVar1);
  iVar5 = uVar6 * 0x2e + 0x10;
  puVar3 = (undefined4 *)_kalloc(iVar5);
  _bzero(puVar3,iVar5);
  *puVar3 = 1;
  puVar3[1] = uVar2;
  puVar3[2] = puVar3;
  puVar3[3] = iVar5;
  puVar7 = puVar3 + 4;
  iVar5 = 0;
  if (0 < (int)uVar6) {
    do {
      *(undefined2 *)(puVar7 + 7) = 1;
      iVar4 = (*param_2)((int)param_1,param_4 + (iVar5 << (_page_shift & 0x3f)),param_3);
      uVar1 = _page_shift;
      *(int *)((int)puVar7 + 0x22) = iVar4 << (_page_shift & 0x3f);
      _vm_page_insert(puVar7,uVar2,iVar5 << (uVar1 & 0x3f));
      iVar5 = iVar5 + 1;
      puVar7 = (undefined4 *)((int)puVar7 + 0x2e);
    } while (iVar5 < (int)uVar6);
  }
  _vm_object_setpager(uVar2,puVar3,0,0);
  return uVar2;
}

