/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aefd4 */

void FUN_001aefd4(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x120) != 0) {
    if ((*(byte *)(param_1 + 0x124) & 1) == 0) {
      uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
      _IOLog("%s: clearReservation, no valid target\n",uVar1);
    }
    else {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_releaseSCSI3Target_lun_forOwner__001f9af0
                    ,*(undefined4 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x10c),
                    *(undefined4 *)(param_1 + 0x110),*(undefined4 *)(param_1 + 0x114),param_1);
      *(byte *)(param_1 + 0x124) = *(byte *)(param_1 + 0x124) & 0xfe;
    }
    *(undefined4 *)(param_1 + 0x120) = 0;
  }
  *(byte *)(param_1 + 0x124) = *(byte *)(param_1 + 0x124) & 0xfe;
  return;
}

