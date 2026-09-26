
void _mach_port_gst_helper(int param_1,int param_2,uint param_3,int param_4,uint *param_5)

{
  uint uVar1;
  
  if (param_1 == *(int *)(param_2 + 0x2c)) {
    uVar1 = *param_5;
    if (uVar1 < param_3) {
      *(undefined4 *)(param_4 + uVar1 * 4) = *(undefined4 *)(param_2 + 0xc);
    }
    *param_5 = uVar1 + 1;
  }
  return;
}
