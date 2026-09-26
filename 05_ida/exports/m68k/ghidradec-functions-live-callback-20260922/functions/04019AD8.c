
int _pn_get(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  _pn_alloc(param_3);
  if (param_2 == 0) {
    iVar1 = _copyinstr(param_1,*(undefined4 *)(param_3 + 4),0x400,param_3 + 8);
  }
  else {
    iVar1 = _copystr(param_1,*(undefined4 *)(param_3 + 4),0x400,param_3 + 8);
  }
  if (((iVar1 == 0) && (*(int *)(param_3 + 8) == 0x400)) &&
     (*(char *)(*(int *)(param_3 + 4) + 0x3ff) != '\0')) {
    iVar1 = 0x3f;
  }
  *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + -1;
  if (iVar1 != 0) {
    _pn_free(param_3);
  }
  return iVar1;
}

