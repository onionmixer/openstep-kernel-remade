
void _p4m50_set_diagled(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = segment(0x2f);
  iVar2 = segment(0x2f);
  *(byte *)(iVar2 + -0xe800000) = *(byte *)(iVar1 + -0xe800000) | 0xc1;
  return;
}
