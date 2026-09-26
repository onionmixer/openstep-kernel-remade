
void sub_4057042(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = ~_page_mask & _page_mask + param_2 * 0x20;
  iVar2 = _kalloc(uVar1);
  *param_1 = iVar2;
  param_1[2] = (uVar1 & 0xffffffe0) + iVar2;
  param_1[1] = *param_1;
  _printf(aKernServLogIni,param_1,param_1[2],*param_1);
  return;
}
