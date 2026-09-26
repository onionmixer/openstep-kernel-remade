
void _od_sync(word param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = _getnewbuf_count();
  if (2 < iVar2) {
    _update((int)(sword)param_1,0xfffffff8);
    for (iVar2 = _mounttab; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1c)) {
      if (((((*(word *)(iVar2 + 4) & 0xfff8) == param_1) && (*(int *)(iVar2 + 10) != 0)) &&
          (*(word *)(iVar2 + 4) != 0xffff)) &&
         (iVar1 = *(int *)(*(int *)(iVar2 + 10) + 0x20),
         (*(uint *)(iVar1 + 0xd0) & 0xffff00) == 0x20000)) {
        *(undefined *)(iVar1 + 0xd1) = 1;
        _sbupdate(iVar2);
      }
    }
  }
  return;
}
