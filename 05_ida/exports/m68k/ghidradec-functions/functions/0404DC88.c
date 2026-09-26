
void _vmp_invalidate(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    while (puVar4 = puVar2, puVar4 != puVar1) {
      puVar2 = (undefined4 *)puVar4[2];
      if ((*(byte *)((int)puVar4 + 0x21) & 0x10) == 0) {
        if ((char)*(byte *)(puVar4 + 8) < '\0') {
          *(byte *)(puVar4 + 8) = *(byte *)(puVar4 + 8) | 0x40;
          _assert_wait(puVar4,0);
          _thread_block();
          puVar2 = puVar4;
        }
        else if (*(sword *)(puVar4 + 7) == 0) {
          _pmap_remove_all(*(undefined4 *)((int)puVar4 + 0x22));
          if (((*(byte *)((int)puVar4 + 0x1e) & 4) == 0) ||
             (iVar3 = _pmap_is_modified(*(undefined4 *)((int)puVar4 + 0x22)), iVar3 != 0)) {
            _mfs_mdirty = _mfs_mdirty + 1;
          }
          else {
            _mfs_mclean = _mfs_mclean + 1;
            _vm_page_free(puVar4);
          }
        }
      }
    }
  }
  return;
}
