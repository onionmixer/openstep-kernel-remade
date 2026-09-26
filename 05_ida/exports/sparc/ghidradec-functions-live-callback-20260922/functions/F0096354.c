
void _vik_mxcc_init_asm(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = segment(2);
  *(undefined4 *)(iVar1 + 0x1c00e00) = 0xffffffff;
  iVar1 = segment(2);
  iVar2 = segment(2);
  *(uint *)(iVar2 + 0x1c00a04) = *(uint *)(iVar1 + 0x1c00a04) & ~param_1 | param_2;
  return;
}

