
void _getposix(void)

{
  *(uint *)(dword_40B57D4 + 0x5c) = (*(uint *)(*_active_u + 0x16) & 0x7fffffff) >> 0x1e;
  return;
}
