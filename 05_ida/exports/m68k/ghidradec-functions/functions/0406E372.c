
void _fd_assign_dv(int param_1,int param_2)

{
  *(int *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 0xc) = (&dword_40C3710)[param_2 * 10];
  (&dword_40C3708)[param_2 * 10] = param_1;
  *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) & 0xffffffef;
  return;
}

