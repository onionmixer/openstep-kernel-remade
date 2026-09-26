
int _nb_alloc(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)_kalloc(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_1 + 4;
    iVar2 = _nb_alloc_wrapper(piVar1 + 1,param_1,sub_401C8EA,piVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    sub_401C8EA(piVar1);
  }
  return 0;
}

