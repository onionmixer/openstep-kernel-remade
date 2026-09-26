
undefined4 _probe_2(uint param_1)

{
  int iVar1;
  
  iVar1 = segment(3);
  return *(undefined4 *)((param_1 & 0xfffff000 | 0x200) + iVar1);
}

