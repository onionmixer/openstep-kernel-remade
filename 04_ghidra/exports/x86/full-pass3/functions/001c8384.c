/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c8384 */

int FUN_001c8384(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_IOFrameBufferDisplay_001fa658;
  iVar1 = _objc_msgSendSuper(&local_c,PTR_s_initFromDeviceDescription__001f9560,param_3);
  if (iVar1 == 0) {
    local_c = param_1;
    local_8 = PTR_s_IOFrameBufferDisplay_001fa658;
    param_1 = _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  }
  else {
    *(undefined1 *)(param_1 + 0x250) = 0;
    puVar2 = (undefined4 *)_objc_msgSend(param_3,PTR_s_memoryRangeList_001f9580);
    if (puVar2 == (undefined4 *)0x0) {
      uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228);
      _IOLog("%s: No memory range set.\n",uVar3);
      local_c = param_1;
      local_8 = PTR_s_IOFrameBufferDisplay_001fa658;
      param_1 = _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
    }
    else {
      *(undefined4 *)(param_1 + 0x248) = *puVar2;
      *(undefined4 *)(param_1 + 0x24c) = puVar2[1];
      *(undefined4 *)(param_1 + 0x230) = 0;
      *(undefined4 *)(param_1 + 0x22c) = 0;
      *(undefined4 *)(param_1 + 0x228) = 0;
      *(undefined4 *)(param_1 + 0x234) = 0;
      *(undefined4 *)(param_1 + 0x238) = 0x40;
      iVar1 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
      iVar4 = _objc_msgSend(param_1,PTR_s_mapFrameBufferAtPhysicalAddress__001f957c,0,0);
      *(int *)(iVar1 + 0x14) = iVar4;
      if (iVar4 == 0) {
        param_1 = _objc_msgSend(param_1,PTR_s_free_001f921c);
      }
      else if (*(char *)(param_1 + 0x250) != '\0') {
        _IOLog("Video Ram Address = 0x%08x\n",*(undefined4 *)(param_1 + 0x248));
        _IOLog("Framebuffer Address = 0x%08x\n",*(undefined4 *)(iVar1 + 0x14));
      }
    }
  }
  return param_1;
}

