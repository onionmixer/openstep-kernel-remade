
undefined4
_thread_entrypoint(undefined4 param_1,int param_2,int param_3,uint param_4,undefined4 *param_5)

{
  if (param_2 == 1) {
    if (param_4 < 0x12) {
      return 4;
    }
    *param_5 = *(undefined4 *)(param_3 + 0x44);
  }
  return 0;
}

