/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00180704 */

int FUN_00180704(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_acquire_001f92b8);
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 4) = param_3;
    _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_release_001f92bc);
    _objc_msgSend(param_3,PTR_s_suspend_001f92f4);
    iVar1 = _objc_msgSend(param_3,PTR_s_attachDeviceInterrupt__001f92c8,param_1);
    if (iVar1 == 0) {
      _objc_msgSend(param_3,PTR_s_resume_001f92f8);
      _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_acquire_001f92b8);
      *(undefined4 *)(param_1 + 4) = 0;
      _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_release_001f92bc);
      param_1 = 0;
    }
    else {
      _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_acquire_001f92b8);
      *(code **)(param_1 + 0xc) = _IOSendInterrupt;
      *(undefined4 *)(param_1 + 0x10) = param_4;
      _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_release_001f92bc);
      _objc_msgSend(param_3,PTR_s_resume_001f92f8);
    }
  }
  else {
    _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_release_001f92bc);
    param_1 = 0;
  }
  return param_1;
}

