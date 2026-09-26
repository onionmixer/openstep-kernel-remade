/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c4dec */

int FUN_001c4dec(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int local_20;
  undefined *local_1c;
  char local_18 [20];
  
  local_20 = param_1;
  local_1c = PTR_s_IODisplay_001fa608;
  iVar1 = _objc_msgSendSuper(&local_20,PTR_s_initFromDeviceDescription__001f9560,param_3);
  if (iVar1 == 0) {
    local_20 = param_1;
    local_1c = PTR_s_IODisplay_001fa608;
    param_1 = _objc_msgSendSuper(&local_20,PTR_s_free_001f921c);
  }
  else {
    *(undefined4 *)(param_1 + 0x214) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x210) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x218) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x21c) = 0;
    _sprintf(local_18,"Display%d",DAT_001e53d4);
    iVar1 = DAT_001e53d4;
    DAT_001e53d4 = DAT_001e53d4 + 1;
    _objc_msgSend(param_1,PTR_s_setUnit__001f9478,iVar1);
    _objc_msgSend(param_1,PTR_s_setName__001f947c,local_18);
  }
  return param_1;
}

