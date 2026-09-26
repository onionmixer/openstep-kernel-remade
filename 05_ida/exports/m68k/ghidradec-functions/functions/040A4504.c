
void unf_sub(void)

{
  int in_D0;
  int unaff_A6;
  
                    /* WARNING: Could not recover jumptable at 0x040a4518. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(((*(uint *)(unaff_A6 + -0x7d) & 0x3fffffff) >> 0x1c | in_D0 << 2) * 4 + 0x40a44c4))()
  ;
  return;
}
