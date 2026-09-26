
void _nosys(void)

{
  if ((*(int *)(_active_u + 0x5a) == 1) || (*(int *)(_active_u + 0x5a) == 3)) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  _exception_from_kernel(5,0x10000,0);
  return;
}

