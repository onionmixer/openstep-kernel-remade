
undefined8 __dbg_trap(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  undefined auStack_46 [4];
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  dword_40B5640 = (undefined *)register0x0000003c;
  uStack_42 = in_D0;
  uStack_3e = in_D1;
  dword_40B563C = _dbg_trap(auStack_46);
  *(undefined4 *)(dword_40B5640 + -4) = dword_40B563C;
  return CONCAT44(uStack_42,uStack_3e);
}
