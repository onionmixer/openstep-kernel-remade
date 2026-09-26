
void _dbg_longjmp(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[8] = param_1[0x10];
                    /* WARNING: Could not recover jumptable at 0x040967bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_1[8])();
  return;
}

