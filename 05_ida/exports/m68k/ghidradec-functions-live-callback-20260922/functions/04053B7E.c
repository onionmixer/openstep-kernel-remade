
undefined4
_host_stack_usage(int param_1,undefined4 *param_2,int *param_3,uint *param_4,uint *param_5,
                 undefined4 *param_6,undefined4 *param_7)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  int iStack_8;
  
  if (param_1 == 0) {
    uVar2 = 0x16;
  }
  else {
    uStack_c = _stack_max_usage;
    _stack_statistics(&iStack_8,&uStack_c);
    *param_2 = 0;
    *param_3 = iStack_8;
    uVar1 = ~_page_mask & _page_mask + iStack_8 * 0xff4;
    *param_4 = uVar1;
    *param_5 = uVar1;
    *param_6 = uStack_c;
    *param_7 = 0;
    uVar2 = 0;
  }
  return uVar2;
}

