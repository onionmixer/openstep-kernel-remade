
int _vm_object_lookup(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(&_vm_object_hashtable)[(param_1 & 0x7f) * 2];
  while( true ) {
    if (puVar1 == &_vm_object_hashtable + (param_1 & 0x7f) * 2) {
      return 0;
    }
    iVar2 = puVar1[2];
    if (param_1 == *(uint *)(iVar2 + 0x24)) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  if (*(sword *)(iVar2 + 0x14) == 0) {
    puVar1 = *(undefined4 **)(iVar2 + 0x46);
    puVar3 = *(undefined4 **)(iVar2 + 0x4a);
    puVar4 = puVar3;
    if ((undefined4 **)puVar1 != &_vm_object_cached_list) {
      *(undefined4 **)((int)puVar1 + 0x4a) = puVar3;
      puVar4 = dword_40C2DA4;
    }
    dword_40C2DA4 = puVar4;
    if ((undefined4 **)puVar3 != &_vm_object_cached_list) {
      *(undefined4 **)((int)puVar3 + 0x46) = puVar1;
      puVar1 = _vm_object_cached_list;
    }
    _vm_object_cached_list = puVar1;
    _vm_object_cached = _vm_object_cached + -1;
  }
  *(sword *)(iVar2 + 0x14) = *(sword *)(iVar2 + 0x14) + 1;
  return iVar2;
}

