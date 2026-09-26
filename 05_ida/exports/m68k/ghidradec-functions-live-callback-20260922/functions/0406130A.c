
void _vm_page_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = _vm_page_template;
  param_1[1] = dword_40C3294;
  param_1[2] = dword_40C3298;
  param_1[3] = dword_40C329C;
  param_1[4] = dword_40C32A0;
  param_1[5] = dword_40C32A4;
  param_1[6] = dword_40C32A8;
  param_1[7] = dword_40C32AC;
  param_1[8] = dword_40C32B0;
  param_1[9] = dword_40C32B4;
  param_1[10] = dword_40C32B8;
  *(undefined2 *)(param_1 + 0xb) = word_40C32BC;
  *(undefined4 *)((int)param_1 + 0x22) = param_4;
  _vm_page_insert(param_1,param_2,param_3);
  return;
}

