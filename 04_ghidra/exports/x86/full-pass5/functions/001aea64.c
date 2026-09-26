/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aea64 */

undefined4 FUN_001aea64(int param_1,undefined4 param_2,byte param_3,byte param_4,char param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_numberOfTargets_001f9410);
  if (((int)(uint)param_3 < iVar1) && (param_4 < 9)) {
    _objc_msgSend(param_1,PTR_s_clearReservation_001f9a54);
    iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),
                          PTR_s_reserveSCSI3Target_lun_forOwner__001f9af4,(uint)param_3,0,param_4,0,
                          param_1);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x120) = 1;
    }
    else if (param_5 == '\0') {
      return 0xfffffd2b;
    }
    *(uint *)(param_1 + 0x108) = (uint)param_3;
    *(undefined4 *)(param_1 + 0x10c) = 0;
    *(uint *)(param_1 + 0x110) = (uint)param_4;
    *(undefined4 *)(param_1 + 0x114) = 0;
    *(byte *)(param_1 + 0x124) = *(byte *)(param_1 + 0x124) | 1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffd3e;
  }
  return uVar2;
}

