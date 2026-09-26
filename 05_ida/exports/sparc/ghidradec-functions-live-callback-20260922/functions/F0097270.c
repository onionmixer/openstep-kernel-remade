
undefined4 _sun4m_get_diagmesg(void)

{
  int iVar1;
  
  iVar1 = segment(0x2f);
  return *(undefined4 *)(iVar1 + 0x1000);
}

