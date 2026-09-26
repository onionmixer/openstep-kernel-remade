
undefined4 _piconnect(int param_1,int param_2)

{
  *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(*(int *)(param_2 + 8) + 0xc) = *(undefined4 *)(param_1 + 8);
  *(undefined2 *)(param_1 + 0x3a) = 0x1000;
  *(undefined2 *)(param_1 + 0x3e) = 0x2000;
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | 0x22;
  *(undefined2 *)(param_2 + 0x24) = 0;
  *(undefined2 *)(param_2 + 0x28) = 0;
  *(word *)(param_2 + 6) = *(word *)(param_2 + 6) | 0x12;
  return 1;
}
