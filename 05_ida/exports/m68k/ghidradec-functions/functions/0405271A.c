
undefined4 _task_priority(int param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((param_1 == 0) || (0x1f < param_2)) {
    uVar3 = 4;
  }
  else {
    *(uint *)(param_1 + 0x40) = param_2;
    if (param_3 != 0) {
      for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)(param_1 + 0x18);
          puVar1 = (undefined4 *)puVar1[4]) {
        iVar2 = _thread_priority(puVar1,param_2,0);
        if (iVar2 != 0) {
          uVar3 = 5;
        }
      }
    }
  }
  return uVar3;
}
