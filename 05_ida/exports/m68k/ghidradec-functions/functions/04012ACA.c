
int _soclose(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((*(byte *)(param_1 + 3) & 2) != 0) {
    iVar1 = *(int *)(param_1 + 0x14);
    while (param_1 != iVar1) {
      _soabort(*(undefined4 *)(param_1 + 0x14));
      iVar1 = *(int *)(param_1 + 0x14);
    }
    while (param_1 != *(int *)(param_1 + 0x1a)) {
      _soabort(*(undefined4 *)(param_1 + 0x1a));
    }
  }
  if (*(int *)(param_1 + 8) != 0) {
    if (((*(word *)(param_1 + 6) & 2) != 0) &&
       (((((*(word *)(param_1 + 6) & 8) != 0 || (iVar2 = _sodisconnect(param_1), iVar2 == 0)) &&
         (*(char *)(param_1 + 3) < '\0')) &&
        (((*(word *)(param_1 + 6) & 0x108) != 0x108 && ((*(word *)(param_1 + 6) & 2) != 0)))))) {
      do {
        _sleep(param_1 + 0x4e,0x1a);
      } while ((*(byte *)(param_1 + 7) & 2) != 0);
    }
    if ((*(int *)(param_1 + 8) != 0) &&
       (iVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,1,0,0,0), iVar2 == 0)) {
      iVar2 = iVar1;
    }
  }
  if ((*(byte *)(param_1 + 7) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSocloseNofdref);
  }
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | 1;
  _sofree(param_1);
  return iVar2;
}
