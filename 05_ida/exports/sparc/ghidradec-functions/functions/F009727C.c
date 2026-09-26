
void _sun4m_set_diagmesg(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = segment(0x2f);
  *(undefined4 *)(iVar1 + 0x1000) = param_1;
  return;
}
