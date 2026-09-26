
undefined4 * _object_getClassName(int *param_1)

{
  undefined4 *puVar1;
  
  if (param_1 == (int *)0x0) {
    puVar1 = &aNil;
  }
  else {
    puVar1 = *(undefined4 **)(*param_1 + 8);
  }
  return puVar1;
}
