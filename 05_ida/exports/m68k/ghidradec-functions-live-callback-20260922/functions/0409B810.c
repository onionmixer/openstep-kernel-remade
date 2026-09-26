
void do_func(void)

{
  word wVar1;
  int unaff_A6;
  
  *(undefined *)(unaff_A6 + -0x46) = 0;
  if (*(uint *)(unaff_A6 + -0xe4) >> 0x1a == 0x17) {
    smovcr();
    return;
  }
  wVar1 = *(word *)(unaff_A6 + -0xe4) & 0x7f;
  if (wVar1 < 0x38) {
                    /* WARNING: Could not recover jumptable at 0x0409b86c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(tblpre + (sword)((word)((uint)*(undefined4 *)(unaff_A6 + -0xe8) >> 0x1d) +
                                 wVar1 * 8) * 4))();
    return;
  }
  return;
}

