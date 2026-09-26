
void _sun4m_set_sysctl(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = segment(0x2f);
  *(undefined4 *)(iVar1 + -0xe100000) = param_1;
  return;
}

