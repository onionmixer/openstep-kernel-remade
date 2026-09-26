
undefined8 _cpu_down(int param_1)

{
  int iVar1;
  char in_XF;
  bool bVar2;
  
  iVar1 = (&_processor_ptr)[param_1];
  (&dword_40B5DD4)[param_1 * 8] = 0;
  bVar2 = dword_40C22D4 == 0;
  dword_40C22D4 = dword_40C22D4 + -1;
  *(undefined4 *)(iVar1 + 300) = 0;
  *(undefined4 *)(iVar1 + 0x110) = 0;
  return CONCAT44(CONCAT22((sword)((uint)(param_1 * 0x20) >> 0x10),(word)(byte)(bVar2 << 4 | 4)),
                  (int)(sword)(word)(byte)(in_XF << 4 | (param_1 < 0) << 3 | (param_1 == 0) << 2));
}
