
void _uprintf(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(_active_u + 0x15e);
  if (iVar1 != 0) {
    _ttycheckoutq(iVar1,1);
    _prf(param_1,&stack0x00000008,2,iVar1);
  }
  return;
}

