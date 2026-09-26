
void ovf_res(void)

{
  int in_D0;
  int unaff_A6;
  
                    /* WARNING: Could not recover jumptable at 0x040a41a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&loc_40A4078 + ((*(uint *)(unaff_A6 + -0x7d) & 0x3fffffff) >> 0x1c | in_D0 << 2) * 4)
  )();
  return;
}

