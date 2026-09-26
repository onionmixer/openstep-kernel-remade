
undefined4 _processor_set_max_priority(int param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (0x1f < param_2)) {
    uVar2 = 4;
  }
  else {
    *(uint *)(param_1 + 0x154) = param_2;
    if (param_3 != 0) {
      for (puVar1 = *(undefined4 **)(param_1 + 0x130); puVar1 != (undefined4 *)(param_1 + 0x130);
          puVar1 = (undefined4 *)puVar1[6]) {
        if ((int)puVar1[0x14] < (int)param_2) {
          _thread_max_priority(puVar1,param_1,param_2);
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}
