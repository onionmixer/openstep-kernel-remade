/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016e30c */

void FUN_0016e30c(int *param_1,int param_2)

{
  processor_t processor;
  kern_return_t kVar1;
  int *processor_cmd;
  mach_msg_type_number_t processor_cmdCnt;
  
  if (((((uint)param_1[1] < 0x24) || (*param_1 < 0)) ||
      ((*(byte *)((int)param_1 + 0x1b) & 0x30) != 0x30)) ||
     (((char *)param_1[7] != s__62I__00200002 ||
      (processor_cmdCnt = param_1[8], param_1[1] != processor_cmdCnt * 4 + 0x24)))) {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  else {
    processor_cmd = param_1 + 9;
    processor = _convert_port_to_processor(param_1[2]);
    kVar1 = _processor_control(processor,processor_cmd,processor_cmdCnt);
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
  }
  return;
}

