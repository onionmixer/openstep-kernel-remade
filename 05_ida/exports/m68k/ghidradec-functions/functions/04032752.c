
uint sub_4032752(int *param_1,uint param_2,uint *param_3,int *param_4)

{
  uint uVar1;
  
  uVar1 = param_2 / _page_size;
  if (uVar1 < (uint)param_1[1]) {
    if ((*(byte *)(param_1[3] + 3 + uVar1 * 4) & 0xf0) != 0) {
      *param_3 = _page_size * (*(uint *)(param_1[3] + uVar1 * 4) >> 8);
      *param_4 = *param_1 * (*(byte *)(param_1[3] + 3 + uVar1 * 4) & 0xf);
      return *param_1 * (*(uint *)(param_1[3] + 3 + uVar1 * 4) >> 0x1c);
    }
    _printf(aPageinFromUnin);
  }
  else if (_swapfs_cangrow == 1) {
                    /* WARNING: Subroutine does not return */
    _panic(aPagingInBeyond);
  }
  *param_3 = param_2;
  *param_4 = 0;
  return _page_size;
}
