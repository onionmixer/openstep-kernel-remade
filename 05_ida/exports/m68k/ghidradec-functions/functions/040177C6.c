
void sub_40177C6(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  
  param_5[0x10] = 0;
  sub_4018552(param_5,param_1);
  *(undefined2 *)((int)param_5 + 0x1e) = *(undefined2 *)(param_1 + 0x2c);
  *param_5 = 0x2000001;
  param_5[9] = param_3;
  param_5[6] = _page_size;
  param_5[5] = _page_size;
  *(undefined2 *)(param_5 + 7) = 0;
  param_5[10] = 0;
  param_5[8] = *(undefined4 *)(param_2 + 0x22);
  param_5[0xf] = 0;
  *(int *)(_active_u + 0x192) = *(int *)(_active_u + 0x192) + 1;
  if (param_3 < 0) {
    param_3 = param_3 + 7;
  }
  iVar1 = (param_1 + (param_3 >> 3) & 0xfU) * 0xc;
  param_5[1] = *(undefined4 *)(_bufhash + iVar1 + 4);
  param_5[2] = _bufhash + iVar1;
  *(undefined4 **)(*(int *)(_bufhash + iVar1 + 4) + 8) = param_5;
  *(undefined4 **)(_bufhash + iVar1 + 4) = param_5;
  (**(code **)(*(int *)(param_5[0x10] + 0x1c) + 0x54))(param_5);
  return;
}
