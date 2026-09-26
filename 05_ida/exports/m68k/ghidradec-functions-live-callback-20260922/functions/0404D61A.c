
void _mfs_uncache(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (((*(byte *)(iVar1 + 0x34) & 8) != 0) && (*(sword *)(iVar1 + 4) == 0)) {
    _mfs_memfree(iVar1,0);
  }
  return;
}

