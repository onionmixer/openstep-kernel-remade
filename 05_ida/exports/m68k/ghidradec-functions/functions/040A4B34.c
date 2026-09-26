
void sub_40A4B34(void)

{
  undefined4 in_D0;
  uint uVar1;
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x54) = in_D0;
  uVar1 = get_fline();
  if ((uVar1 & 0x3f) >> 3 != 0) {
    mem_write();
    return;
  }
  reg_dest();
  return;
}
