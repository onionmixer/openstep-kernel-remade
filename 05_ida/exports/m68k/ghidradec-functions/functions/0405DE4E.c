
int __vm_map_entry_create(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = _vm_map_kentry_zone;
  if (*(int *)(param_1 + 0x14) != 0) {
    uVar1 = _vm_map_entry_zone;
  }
  iVar2 = _zalloc(uVar1);
  if (iVar2 != 0) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVmMapEntryCrea);
}
