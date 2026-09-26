
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

