
void round(void)

{
  int unaff_A6;
  undefined8 uVar1;
  
  uVar1 = sub_409E736();
  if ((int)((qword)uVar1 >> 0x20) == 0) {
                    /* WARNING: Could not recover jumptable at 0x0409e89c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(&loc_409E882 + (sword)((qword)uVar1 >> 0x10) * 4))();
    return;
  }
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x208;
                    /* WARNING: Could not recover jumptable at 0x0409e6d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(sub_409E6D4 + (sword)uVar1 * 4))();
  return;
}

