/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aec08 */

undefined4 FUN_001aec08(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_14;
  char local_10 [12];
  
  if (*(int *)(param_1 + 0x118) == param_3) {
    uVar1 = 0;
  }
  else {
    _objc_msgSend(param_1,PTR_s_clearReservation_001f9a54);
    _sprintf(local_10,"sc%d",param_3);
    iVar2 = _IOGetObjectForDeviceName(local_10,&local_14);
    if (iVar2 == 0) {
      *(int *)(param_1 + 0x118) = param_3;
      *(undefined4 *)(param_1 + 0x128) = local_14;
      *(byte *)(param_1 + 0x124) = *(byte *)(param_1 + 0x124) & 0xfe;
      uVar1 = 0;
    }
    else {
      uVar1 = 0xfffffd40;
    }
  }
  return uVar1;
}

