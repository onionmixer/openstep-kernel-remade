/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b89b8 */

int FUN_001b89b8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 *param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_Object_001fa4c8;
  _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
  *(undefined4 *)(param_1 + 4) = param_3;
  uVar1 = _objc_msgSend(param_3,PTR_s_audioDevice_001f990c);
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 0x18) = param_4;
  *(undefined4 *)(param_1 + 100) = 0x5622;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 2;
  *(int *)(param_1 + 0x30) = param_1 + 0x2c;
  *(int *)(param_1 + 0x2c) = param_1 + 0x2c;
  uVar1 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
  uVar1 = _objc_msgSend(uVar1);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = _task_self(param_5);
  iVar2 = _port_allocate_EXTERNAL(uVar1);
  if (iVar2 == 0) {
    uVar1 = *param_5;
    *(undefined4 *)(param_1 + 0xc) = uVar1;
    uVar1 = _IOConvertPort(uVar1,2,0);
    *(undefined4 *)(param_1 + 0x10) = uVar1;
    *(undefined4 *)(param_1 + 0x14) = param_6;
    *(undefined4 *)(param_1 + 0x1c) = param_7;
  }
  else {
    _IOLog("Audio: initChannel: stream port_allocate: %s\n","MACH ERR");
    _objc_msgSend(param_1,PTR_s_free_001f921c);
    param_1 = 0;
  }
  return param_1;
}

