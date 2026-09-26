
int * _realloc(int param_1,uint param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  
  puVar1 = (uint *)(param_1 + -8);
  if (param_1 == 0) {
    piVar2 = (int *)_malloc(param_2);
  }
  else {
    piVar2 = (int *)_kalloc(param_2 + 8);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      *piVar2 = param_2 + 8;
      uVar3 = *puVar1;
      if (param_2 < uVar3) {
        uVar3 = param_2;
      }
      _bcopy(param_1,piVar2 + 2,uVar3);
      _kfree(puVar1,*puVar1);
      piVar2 = piVar2 + 2;
    }
  }
  return piVar2;
}

