
undefined4 _processor_set_policy_disable(int param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (((param_1 == 0) || (param_2 == 1)) || (3 < param_2 - 1)) {
    uVar2 = 4;
  }
  else {
    if (((param_2 & *(uint *)(param_1 + 0x158)) != 0) &&
       (*(uint *)(param_1 + 0x158) = ~param_2 & *(uint *)(param_1 + 0x158), param_3 != 0)) {
      for (puVar1 = *(undefined4 **)(param_1 + 0x130); puVar1 != (undefined4 *)(param_1 + 0x130);
          puVar1 = (undefined4 *)puVar1[6]) {
        if (param_2 == puVar1[0x17]) {
          _thread_policy(puVar1,1,0);
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}

