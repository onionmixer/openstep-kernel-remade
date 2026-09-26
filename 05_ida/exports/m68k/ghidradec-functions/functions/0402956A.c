
void _rflush(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = _rtable;
  do {
    for (iVar1 = *(int *)puVar2; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if (((-1 < *(char *)(iVar1 + 0x11)) && ((*(byte *)(*(int *)(iVar1 + 0x30) + 0xf) & 1) == 0))
         && ((param_1 == 0 || (param_1 == *(int *)(iVar1 + 0x30))))) {
        _sync_vp(iVar1 + 0xc);
      }
    }
    puVar2 = (undefined *)((int)puVar2 + 4);
  } while (puVar2 < _unixauthtab);
  return;
}
