/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c6b70 */

undefined4
FUN_001c6b70(undefined4 param_1,undefined4 param_2,undefined4 *param_3,char *param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  undefined4 local_c;
  undefined *local_8;
  
  iVar2 = 0x15;
  bVar5 = true;
  pcVar3 = param_4;
  pcVar4 = "IO_Framebuffer_Unmap";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    _objc_msgSend(param_1,PTR_s_revertToVGAMode_001f94a8);
    uVar1 = 0;
  }
  else {
    iVar2 = 0x1a;
    bVar5 = true;
    pcVar3 = param_4;
    pcVar4 = "IO_Framebuffer_Unregister";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      if (param_5 == 1) {
        uVar1 = _objc_msgSend(PTR_s_EventDriver_001f9dc8,PTR_s_instance_001f9964,
                              PTR_s_unregisterScreen__001f9618,*param_3);
        _objc_msgSend(uVar1);
        uVar1 = 0;
      }
      else {
        uVar1 = 0xfffffd3e;
      }
    }
    else {
      local_c = param_1;
      local_8 = PTR_s_IODisplay_001fa630;
      uVar1 = _objc_msgSendSuper(&local_c,PTR_s_setIntValues_forParameter_count__001f94bc,param_3,
                                 param_4,param_5);
    }
  }
  return uVar1;
}

