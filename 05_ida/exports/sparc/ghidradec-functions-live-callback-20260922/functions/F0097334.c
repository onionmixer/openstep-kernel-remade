
void _sun4m_init_all_fsr(void)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  
  segment(0x2f);
  segment(0x2f);
  iVar1 = segment(0x2f);
  *(undefined4 *)(iVar1 + -0x1ffff000) = 0;
  segment(0x2f);
  segment(0x2f);
  segment(0x2f);
  iVar1 = segment(0x2f);
  *(undefined4 *)(iVar1 + 8) = 0;
  puVar2 = (uint *)segment(0x2f);
  puVar3 = (uint *)segment(0x2f);
  *puVar3 = *puVar2 | 1;
  iVar1 = segment(0x2f);
  iVar4 = segment(0x2f);
  *(uint *)(iVar4 + -0x1fffeff8) = *(uint *)(iVar1 + -0x1fffeff8) | 0x80100000;
  return;
}

