
undefined4 _probe_pte_0(uint param_1)

{
  int iVar1;
  
  iVar1 = segment(3);
  return *(undefined4 *)((param_1 & 0xfffff000) + iVar1);
}

