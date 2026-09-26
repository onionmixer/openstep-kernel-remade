
void _sun4m_set_diagled(word param_1)

{
  int iVar1;
  
  iVar1 = segment(0x2f);
  *(word *)(iVar1 + -0xea00000) = param_1 ^ 0xffff;
  return;
}

