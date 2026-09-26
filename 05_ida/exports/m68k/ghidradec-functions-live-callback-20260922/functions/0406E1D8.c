
void _fd_gen_seek(undefined param_1,undefined *param_2,undefined param_3,byte param_4)

{
  param_2[10] = 0xf;
  param_2[0xb] = (param_4 & 1) << 2 | param_2[0xb] & 3;
  param_2[0xc] = param_3;
  *param_2 = param_1;
  *(undefined4 *)(param_2 + 2) = 10000;
  *(undefined4 *)(param_2 + 6) = 1;
  *(undefined4 *)(param_2 + 0x1a) = 3;
  *(undefined4 *)(param_2 + 0x1e) = 0;
  *(undefined4 *)(param_2 + 0x22) = 0;
  *(undefined4 *)(param_2 + 0x36) = 2;
  return;
}

