
int _engetbuf(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _enbuf_get();
  if (iVar1 != 0) {
    iVar2 = _nb_alloc_wrapper(iVar1,0x5ea,sub_408D9AA,iVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    sub_408D9AA(iVar1);
  }
  return 0;
}
