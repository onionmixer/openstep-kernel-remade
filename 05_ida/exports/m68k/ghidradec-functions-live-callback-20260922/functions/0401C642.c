
int sub_401C642(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _if_private(param_1);
  iVar1 = _if_getbuf(*(undefined4 *)(iVar1 + 10));
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    _nb_shrink_top(iVar1,0xe);
  }
  return iVar1;
}

