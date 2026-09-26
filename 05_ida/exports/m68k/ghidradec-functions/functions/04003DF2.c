
void _dupit(int param_1,int param_2,byte param_3)

{
  _expand_fdlist(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x30),param_1);
  *(int *)(*(int *)(_active_u + 0x146) + param_1 * 4) = param_2;
  *(byte *)(param_1 + *(int *)(_active_u + 0x14a)) = param_3 & 0xfe;
  *(sword *)(param_2 + 0xe) = *(sword *)(param_2 + 0xe) + 1;
  if (*(int *)(_active_u + 0x14e) < param_1) {
    *(int *)(_active_u + 0x14e) = param_1;
  }
  return;
}
