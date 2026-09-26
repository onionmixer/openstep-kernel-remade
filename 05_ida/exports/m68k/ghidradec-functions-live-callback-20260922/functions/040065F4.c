
void _uzone_init(void)

{
  _u_task_zone = _zinit(0x28a,0x51400,0xa280,0,&aUtasks);
  _u_thread_zone = _zinit(0x14e,0x29c00,0x5380,0,aUthreads);
  return;
}

