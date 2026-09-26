
void sub_409630E(void)

{
  int iVar1;
  
  iVar1 = _get_vbr();
  dword_40B5614 = *(undefined4 *)(iVar1 + 8);
  dword_40B5618 = *(undefined4 *)(iVar1 + 0xc);
  *(code **)(iVar1 + 8) = __dbg_trap;
  *(code **)(iVar1 + 0xc) = __dbg_trap;
  return;
}
