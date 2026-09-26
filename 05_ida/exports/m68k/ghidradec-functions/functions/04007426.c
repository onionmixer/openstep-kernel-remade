
void _getgid(void)

{
  *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 8);
  *(int *)(dword_40B57D4 + 0x60) = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 4);
  return;
}
