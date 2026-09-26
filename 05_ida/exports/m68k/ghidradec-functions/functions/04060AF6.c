
void sub_4060AF6(undefined4 *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    for (puVar1 = (undefined4 *)*param_1; puVar1 != param_1; puVar1 = (undefined4 *)puVar1[2]) {
      if ((param_2 <= (uint)puVar1[6]) && ((uint)puVar1[6] < param_3)) {
        _vm_policy_apply(param_1,puVar1,param_4);
      }
    }
    param_3 = param_3 - param_2;
    uVar2 = param_1[4];
    if ((uVar2 != 0) && (uVar2 < param_3)) {
      param_3 = uVar2;
    }
    sub_4060AF6(param_1[7],param_1[8] + param_2,param_3 + param_1[8] + param_2,param_4);
    _thread_wakeup_prim(param_1,0,0);
  }
  return;
}
