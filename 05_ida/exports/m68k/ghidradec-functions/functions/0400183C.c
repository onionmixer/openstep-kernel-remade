
undefined4 _fast_setjmp(undefined4 *param_1)

{
  undefined4 unaff_A6;
  undefined4 in_stack_00000000;
  
  *param_1 = in_stack_00000000;
  param_1[0xb] = unaff_A6;
  param_1[0xc] = register0x0000003c;
  return 0;
}
