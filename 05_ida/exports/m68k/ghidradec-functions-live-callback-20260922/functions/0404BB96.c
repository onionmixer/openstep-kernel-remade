
int _load_machfile(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 auStack_16 [4];
  
  iVar1 = *(int *)(*(int *)(_active_threads + 0xc) + 8);
  uVar2 = *(undefined4 *)(iVar1 + 0x20);
  _pmap_reference(uVar2);
  uVar2 = _vm_map_create(uVar2,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),
                         *(undefined4 *)(iVar1 + 0x1c));
  if (param_5 == (undefined4 *)0x0) {
    param_5 = auStack_16;
  }
  _bzero(param_5,0x12);
  *param_5 = 0;
  iVar3 = sub_404BC42(param_1,uVar2,param_2,param_3,param_4,0,0,param_5);
  if (iVar3 == 0) {
    *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8) = uVar2;
    _vm_map_deallocate(iVar1);
    iVar3 = 0;
  }
  else {
    _vm_map_deallocate(uVar2);
  }
  return iVar3;
}

