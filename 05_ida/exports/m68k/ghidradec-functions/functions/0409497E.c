
void _halt_cpu(void)

{
  dword_40B5DD4 = 0;
  stop();
  return;
}
