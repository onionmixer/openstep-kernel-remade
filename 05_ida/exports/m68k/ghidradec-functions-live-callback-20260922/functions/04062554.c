
undefined4 _vm_statistics(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    _vm_stat = _page_size;
    unk_40C23E4 = _vm_page_free_count;
    unk_40C23E8 = _vm_page_active_count;
    unk_40C23EC = _vm_page_inactive_count;
    unk_40C23F0 = _vm_page_wire_count;
    *param_2 = _page_size;
    param_2[1] = unk_40C23E4;
    param_2[2] = unk_40C23E8;
    param_2[3] = unk_40C23EC;
    param_2[4] = unk_40C23F0;
    param_2[5] = dword_40C23F4;
    param_2[6] = dword_40C23F8;
    param_2[7] = dword_40C23FC;
    param_2[8] = dword_40C2400;
    param_2[9] = dword_40C2404;
    param_2[10] = dword_40C2408;
    param_2[0xb] = dword_40C240C;
    param_2[0xc] = dword_40C2410;
    uVar1 = 0;
  }
  return uVar1;
}

