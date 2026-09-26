
void reg_dest(void)

{
  int in_D1;
  
                    /* WARNING: Could not recover jumptable at 0x040a471c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&loc_40A46B2 + in_D1 * 4))();
  return;
}
