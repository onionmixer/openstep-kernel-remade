/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b3604 */

undefined4
_EvSetParameterChar(int param_1,undefined4 param_2,char *param_3,undefined4 param_4,
                   undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = _objc_msgSend(PTR_s_EventDriver_001f9dc8,PTR_s_instance_001f9964);
  if (iVar1 == 0) {
    uVar2 = 0xfffffd27;
  }
  else {
    iVar3 = _strncmp(param_3,"Ev_",3);
    if ((iVar3 == 0) && (iVar3 = _objc_msgSend(iVar1,PTR_s_ev_port_001f9960), param_1 != iVar3)) {
      return 0xfffffd3f;
    }
    uVar2 = _objc_msgSend(iVar1,PTR_s_setCharValues_forParameter_count_001f9538,param_4,param_3,
                          param_5);
  }
  return uVar2;
}

