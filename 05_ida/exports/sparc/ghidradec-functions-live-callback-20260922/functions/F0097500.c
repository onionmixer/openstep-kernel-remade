
void _SMbuf_syncmode(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = segment(0x2f);
  iVar2 = segment(0x2f);
  *(uint *)(iVar2 + -0x1fffeff8) = *(uint *)(iVar1 + -0x1fffeff8) & 0x7fffffff;
  return;
}

