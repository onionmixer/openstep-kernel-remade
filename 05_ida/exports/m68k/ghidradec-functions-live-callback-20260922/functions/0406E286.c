
int _fd_new_fv(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _kalloc(0x19a);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aFdNewFvCouldnT);
  }
  _bzero(iVar1,0x19a);
  *(undefined4 *)(iVar1 + 4) = 1;
  *(undefined4 *)(iVar1 + 0x10) = param_1;
  iVar2 = (*(code *)&loc_406F0A2)();
  iVar3 = (*(code *)&loc_406F0A2)();
  iVar2 = _kalloc(-iVar3 & iVar2 + 0x1c47U);
  *(int *)(iVar1 + 0x14) = iVar2;
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aFdNewFvCouldnT_0);
  }
  *(undefined4 *)(iVar1 + 0x17a) = 0;
  *(undefined4 *)(iVar1 + 0x176) = 0;
  _disksort_init(iVar1 + 0xba);
  return iVar1;
}

