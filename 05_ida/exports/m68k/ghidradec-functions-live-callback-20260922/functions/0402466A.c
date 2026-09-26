
void _tcp_init(void)

{
  _tcp_iss = 1;
  dword_40B7DA4 = &_tcb;
  _tcb = &_tcb;
  return;
}

