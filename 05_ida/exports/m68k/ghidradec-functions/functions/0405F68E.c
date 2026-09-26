
int _vm_move(undefined4 param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5,
            int *param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_8;
  
  if (param_4 == 0) {
    *param_6 = 0;
    iVar3 = 0;
  }
  else {
    uVar1 = ~_page_mask & param_2;
    iVar2 = (~_page_mask & _page_mask + param_2 + param_4) - uVar1;
    iStack_8 = 0;
    iVar3 = _vm_allocate(param_3,&iStack_8,iVar2,1);
    if (iVar3 == 0) {
      iVar3 = _vm_map_copy(param_3,param_1,iStack_8,iVar2,uVar1,0,param_5);
      if (iVar3 == 0) {
        *param_6 = iStack_8 + (param_2 - uVar1);
      }
      else {
        _vm_deallocate(param_3,iStack_8,iVar2);
      }
    }
  }
  return iVar3;
}
