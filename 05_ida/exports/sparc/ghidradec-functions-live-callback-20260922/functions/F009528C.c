
void _fp_dumpregs(undefined8 *param_1)

{
  undefined8 in_fd0;
  undefined8 in_fd2;
  undefined8 in_fd4;
  undefined8 in_fd6;
  undefined8 in_fd8;
  undefined8 in_fd10;
  undefined8 in_fd12;
  undefined8 in_fd14;
  undefined8 in_fd16;
  undefined8 in_fd18;
  undefined8 in_fd20;
  undefined8 in_fd22;
  undefined8 in_fd24;
  undefined8 in_fd26;
  undefined8 in_fd28;
  undefined8 in_fd30;
  undefined4 in_fsr;
  
  *(undefined4 *)(param_1 + 0x10) = in_fsr;
  *param_1 = in_fd0;
  param_1[1] = in_fd2;
  param_1[2] = in_fd4;
  param_1[3] = in_fd6;
  param_1[4] = in_fd8;
  param_1[5] = in_fd10;
  param_1[6] = in_fd12;
  param_1[7] = in_fd14;
  param_1[8] = in_fd16;
  param_1[9] = in_fd18;
  param_1[10] = in_fd20;
  param_1[0xb] = in_fd22;
  param_1[0xc] = in_fd24;
  param_1[0xd] = in_fd26;
  param_1[0xe] = in_fd28;
  param_1[0xf] = in_fd30;
  return;
}

