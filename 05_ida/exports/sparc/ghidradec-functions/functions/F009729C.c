
void _sun4m_disable_dvma(void)

{
  int iVar1;
  
  iVar1 = segment(0x2f);
  *(undefined4 *)(iVar1 + -0x1fffeff8) = 0;
  return;
}
