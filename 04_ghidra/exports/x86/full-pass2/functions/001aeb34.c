/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aeb34 */

undefined4
FUN_001aeb34(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,int param_6,
            char param_7)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_numberOfTargets_001f9410);
  if ((((param_4 < (uint)((int)uVar1 >> 0x1f)) ||
       (((int)uVar1 >> 0x1f == param_4 && (param_3 < uVar1)))) && (param_6 == 0)) && (param_5 < 9))
  {
    _objc_msgSend(param_1,PTR_s_clearReservation_001f9a54);
    iVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),
                          PTR_s_reserveSCSI3Target_lun_forOwner__001f9af4,param_3,param_4,param_5,0,
                          param_1);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x120) = 1;
    }
    else if (param_7 == '\0') {
      return 0xfffffd2b;
    }
    *(uint *)(param_1 + 0x108) = param_3;
    *(uint *)(param_1 + 0x10c) = param_4;
    *(uint *)(param_1 + 0x110) = param_5;
    *(undefined4 *)(param_1 + 0x114) = 0;
    *(byte *)(param_1 + 0x124) = *(byte *)(param_1 + 0x124) | 1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffd3e;
  }
  return uVar2;
}

