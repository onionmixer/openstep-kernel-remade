
undefined4 sub_402872E(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(param_1 + 0x5a);
  while ((1 < iVar2 || (uVar3 = _MAXCLIENTS, iVar2 < 0))) {
    _printf(aAuthgetUnknown,iVar2);
    iVar2 = 0;
  }
  do {
    iVar2 = _nextunixvictim * 6;
    _nextunixvictim = (_nextunixvictim + 1) % _MAXCLIENTS;
    if (*(sword *)(_unixauthtab + iVar2) == 0) {
      if (*(int *)(_unixauthtab + iVar2 + 2) == 0) {
        uVar1 = _authkern_create();
        *(undefined4 *)(_unixauthtab + iVar2 + 2) = uVar1;
      }
      *(sword *)(_unixauthtab + iVar2) = 1;
      return *(undefined4 *)(_unixauthtab + iVar2 + 2);
    }
    uVar3 = uVar3 - 1;
  } while (0 < (int)uVar3);
  uVar1 = _authkern_create();
  return uVar1;
}
