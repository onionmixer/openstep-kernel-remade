/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b334c */

int FUN_001b334c(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x168);
  if ((*(uint *)(iVar1 + 8) & 4) != (param_3 & 4)) {
    if ((param_3 & 4) == 0) {
      _objc_msgSend(param_1,PTR_s_postEvent_at_atTime_withData__001f9a00,2,iVar1 + 0x18,param_4,0);
      uVar2 = *(uint *)(iVar1 + 8) & 0xfffffffb;
    }
    else {
      _objc_msgSend(param_1,PTR_s_postEvent_at_atTime_withData__001f9a00,1,iVar1 + 0x18,param_4,0);
      uVar2 = *(uint *)(iVar1 + 8) | 4;
    }
    *(uint *)(iVar1 + 8) = uVar2;
    *(byte *)(iVar1 + 0x33) =
         *(byte *)(iVar1 + 0x33) & 0xbf | *(char *)(iVar1 + 0x33) * '\x02' & 0x40U;
    if ((*(byte *)(iVar1 + 0x33) & 0x40) == 0) {
      uVar2 = *(uint *)(iVar1 + 0xc) & 0xfffffeff;
    }
    else {
      uVar2 = *(uint *)(iVar1 + 0xc) | 0x100;
    }
    *(uint *)(iVar1 + 0xc) = uVar2;
  }
  if ((*(uint *)(iVar1 + 8) & 1) != (param_3 & 1)) {
    if ((param_3 & 1) == 0) {
      _objc_msgSend(param_1,PTR_s_postEvent_at_atTime_withData__001f9a00,4,iVar1 + 0x18,param_4,0);
      uVar2 = *(uint *)(iVar1 + 8) & 0xfffffffe;
    }
    else {
      _objc_msgSend(param_1,PTR_s_postEvent_at_atTime_withData__001f9a00,3,iVar1 + 0x18,param_4,0);
      uVar2 = *(uint *)(iVar1 + 8) | 1;
    }
    *(uint *)(iVar1 + 8) = uVar2;
  }
  return param_1;
}

