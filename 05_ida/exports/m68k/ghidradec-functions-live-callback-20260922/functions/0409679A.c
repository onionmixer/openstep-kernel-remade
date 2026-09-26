
undefined4 _dbg_setjmp(undefined4 *param_1)

{
  undefined4 in_D0;
  undefined4 in_D1;
  undefined4 unaff_D2;
  undefined4 unaff_D3;
  undefined4 unaff_D4;
  undefined4 unaff_D5;
  undefined4 unaff_D6;
  undefined4 unaff_D7;
  undefined4 in_A1;
  undefined4 unaff_A2;
  undefined4 unaff_A3;
  undefined4 unaff_A4;
  undefined4 unaff_A5;
  undefined4 unaff_A6;
  undefined4 in_stack_00000000;
  
  param_1[0x10] = in_stack_00000000;
  *param_1 = in_D0;
  param_1[1] = in_D1;
  param_1[2] = unaff_D2;
  param_1[3] = unaff_D3;
  param_1[4] = unaff_D4;
  param_1[5] = unaff_D5;
  param_1[6] = unaff_D6;
  param_1[7] = unaff_D7;
  param_1[8] = param_1;
  param_1[9] = in_A1;
  param_1[10] = unaff_A2;
  param_1[0xb] = unaff_A3;
  param_1[0xc] = unaff_A4;
  param_1[0xd] = unaff_A5;
  param_1[0xe] = unaff_A6;
  param_1[0xf] = register0x0000003c;
  return 0;
}

