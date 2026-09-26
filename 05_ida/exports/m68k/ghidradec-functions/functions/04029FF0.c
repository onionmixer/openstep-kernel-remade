
undefined4
sub_4029FF0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)_clntkudp_create(param_1,param_2,param_3,5,*(undefined4 *)(_active_u + 0x1a));
  uVar2 = (**(code **)piVar1[1])(piVar1,param_4,param_5,param_6,param_7,param_8,3,0);
  (**(code **)(*(int *)(*piVar1 + 0x20) + 0x10))(*piVar1);
  (**(code **)(piVar1[1] + 0x10))(piVar1);
  return uVar2;
}
