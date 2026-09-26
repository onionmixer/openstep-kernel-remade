
/* WARNING: Removing unreachable block (ram,0xf0004e8c) */

void level10(void)

{
  undefined4 *unaff_l6;
  
  _clk_intr = _clk_intr + 1;
  _sparc_hardclock(unaff_l6[1],*unaff_l6);
  func_0xf0003a94();
  return;
}

