
undefined4 _kern_serv_get_log(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined auStack_c [4];
  undefined4 uStack_8;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x30) == 0) {
    _port_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),param_2);
    uVar4 = 0x65;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x24);
    if (iVar2 == *(int *)(iVar1 + 0x28)) {
      *(undefined4 *)(iVar1 + 0x18) = param_2;
    }
    else {
      uVar3 = ~_page_mask & _page_mask + (*(int *)(iVar1 + 0x28) - iVar2);
      _vm_read_EXTERNAL(*(undefined4 *)(iVar1 + 0x4cc),iVar2,uVar3,&uStack_8,auStack_c);
      _kern_serv_log_data(param_2,uStack_8,*(int *)(iVar1 + 0x28) - *(int *)(iVar1 + 0x24) >> 5);
      _port_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),param_2);
      _vm_deallocate_EXTERNAL(*(undefined4 *)(iVar1 + 8),uStack_8,uVar3);
      *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(iVar1 + 0x24);
    }
    uVar4 = 0;
  }
  return uVar4;
}
