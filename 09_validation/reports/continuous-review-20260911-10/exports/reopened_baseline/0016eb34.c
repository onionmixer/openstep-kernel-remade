
void FUN_0016eb34(int *param_1,int param_2)

{
  thread_act_t thr_act;
  kern_return_t kVar1;
  boolean_t unaff_EBX;
  mach_msg_type_number_t baseCnt;
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == DAT_001e0184)) &&
     (param_1[8] == DAT_001e0188)) {
    baseCnt = param_1[2];
    thr_act = _convert_port_to_thread();
    kVar1 = _thread_policy(thr_act,param_1[7],(policy_base_t)param_1[9],baseCnt,unaff_EBX);
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    _thread_deallocate(thr_act);
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

