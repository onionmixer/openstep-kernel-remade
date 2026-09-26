
void _getuid(void)

{
  *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 6);
  *(int *)(dword_40B57D4 + 0x60) = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 2);
  return;
}

