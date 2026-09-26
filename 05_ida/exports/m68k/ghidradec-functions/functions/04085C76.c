
void sub_4085C76(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)_kalloc(0x10);
  *puVar2 = param_2;
  puVar2[1] = 0;
  piVar1 = (int *)param_1[1];
  if (piVar1 == param_1) {
    *param_1 = (int)puVar2;
  }
  else {
    piVar1[2] = (int)puVar2;
  }
  puVar2[3] = piVar1;
  puVar2[2] = param_1;
  param_1[1] = (int)puVar2;
  return;
}
