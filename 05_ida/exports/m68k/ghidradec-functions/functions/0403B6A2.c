
undefined4
_rdwri(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
      undefined4 param_6,int *param_7)

{
  undefined4 uVar1;
  undefined4 uStack_22;
  int iStack_1e;
  undefined4 *puStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  int iStack_8;
  
  uStack_22 = param_3;
  iStack_1e = param_4;
  puStack_1a = &uStack_22;
  uStack_16 = 1;
  uStack_12 = param_5;
  uStack_e = param_6;
  iStack_8 = param_4;
  uVar1 = sub_403A0F2(param_2 + 0xc,&puStack_1a,param_1,0,*(undefined4 *)(_active_u + 0x1a));
  if (param_7 == (int *)0x0) {
    if (iStack_8 != 0) {
      uVar1 = 5;
    }
  }
  else {
    *param_7 = iStack_8;
  }
  return uVar1;
}
