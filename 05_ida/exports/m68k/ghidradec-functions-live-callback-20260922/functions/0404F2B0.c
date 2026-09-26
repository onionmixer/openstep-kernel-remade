
void _pset_deallocate(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x13c);
    *(int *)(param_1 + 0x13c) = iVar1 + -1;
    if (iVar1 == 1 || iVar1 + -1 < 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aPsetDeallocate);
    }
  }
  return;
}

