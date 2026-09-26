/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00183488 */

undefined4 _sdopen(ushort param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 local_8;
  
  iVar1 = FUN_001840ec((int)(short)param_1);
  if ((iVar1 == 0) ||
     (iVar2 = _objc_msgSend(iVar1,PTR_s_isDiskReady__001f9384,(param_2 & 4) == 0), iVar2 != 0)) {
    uVar3 = 6;
  }
  else {
    if (DAT_001e756c == 0) {
      iVar2 = _IOGetObjectForDeviceName(&DAT_001e134c,&local_8);
      if (iVar2 != 0) {
        _IOPanic(s_sdopen__can_t_find_controller_ob_001e1350);
      }
      DAT_001e756c = _objc_msgSend(local_8,PTR_s_maxTransfer_001f9388);
    }
    if ((param_1 & 7) != 7) {
      puVar4 = PTR_s_setRawDeviceOpen__001f9390;
      if (DAT_001e7564 == (short)(param_1 >> 8)) {
        puVar4 = PTR_s_setBlockDeviceOpen__001f938c;
      }
      _objc_msgSend(iVar1,puVar4,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}

