/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b9bf8 */

void FUN_001b9bf8(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  undefined *local_8;
  
  uVar1 = _kern_serv_kernel_task_port(*param_3,param_3[4]);
  iVar2 = _vm_deallocate_EXTERNAL(uVar1);
  if (iVar2 != 0) {
    _IOLog("Audio: stream vm_deallocate error %s\n","MACH ERR");
  }
  local_c = param_1;
  local_8 = PTR_s_AudioStream_001fa4f0;
  _objc_msgSendSuper(&local_c,PTR_s_freeRegion__001f9738,param_3);
  return;
}

