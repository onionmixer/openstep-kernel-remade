
void _vidGetFBAddrAndSize(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined auStack_84 [64];
  undefined4 uStack_44;
  
  if ((dword_40B2282 == -1) && (iVar1 = _vidProbeForFB(), iVar1 == -1)) {
    *param_1 = 0;
    *param_2 = 0;
    return;
  }
  (**(code **)((int)&DAT_40b2290 + dword_40B2282 * 0x2c))(auStack_84);
  *param_1 = uStack_44;
  *param_2 = dword_40B6990 + dword_40B6984;
  return;
}

