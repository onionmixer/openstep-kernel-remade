
void _sigcont(void)

{
  _unix_syscall_return(4);
  return;
}

