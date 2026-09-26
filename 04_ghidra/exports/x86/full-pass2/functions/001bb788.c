/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bb788 */

undefined4 __NXAudioGetSndoutOptions(int param_1,byte *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = 0xca;
  }
  else {
    param_2[0] = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    uVar1 = _objc_msgSend(param_1,PTR_s_audioDevice_001f990c);
    iVar2 = _objc_msgSend(uVar1,PTR_s__intValueForParameter_forObject__001f97e0,5,param_1);
    if (iVar2 != 0) {
      *param_2 = *param_2 | 1;
    }
    iVar2 = _objc_msgSend(uVar1,PTR_s__intValueForParameter_forObject__001f97e0,3,param_1);
    if (iVar2 != 0) {
      *param_2 = *param_2 | 2;
    }
    iVar2 = _objc_msgSend(uVar1,PTR_s__intValueForParameter_forObject__001f97e0,4,param_1);
    if (iVar2 != 0) {
      *param_2 = *param_2 | 4;
    }
    iVar2 = _objc_msgSend(uVar1,PTR_s__intValueForParameter_forObject__001f97e0,6,param_1);
    if (iVar2 != 0) {
      *param_2 = *param_2 | 8;
    }
    iVar2 = _objc_msgSend(uVar1,PTR_s__intValueForParameter_forObject__001f97e0,7,param_1);
    if (iVar2 == 0) {
      *param_2 = *param_2 | 0x10;
    }
    uVar1 = 0;
  }
  return uVar1;
}

