
void _p4m35_enable_dvma(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = segment(0x20);
  iVar2 = segment(0x20);
  *(uint *)(iVar2 + 0x10002000) = *(uint *)(iVar1 + 0x10002000) | 0x1f0000;
  return;
}

