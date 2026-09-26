
void _fc_motor_off(int *param_1)

{
  *(byte *)(*param_1 + 2) =
       ~(byte)(0x10 << (*(byte *)(param_1[7] + 0x58) & 0x3f)) & *(byte *)(*param_1 + 2);
  return;
}

