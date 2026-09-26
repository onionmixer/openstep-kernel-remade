/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018355c */

undefined4 _sdclose(ushort param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  iVar2 = FUN_001840ec((int)(short)param_1);
  if (iVar2 == 0) {
LAB_00183597:
    uVar3 = 6;
  }
  else {
    if ((param_1 & 7) != 7) {
      cVar1 = _objc_msgSend(iVar2,PTR_s_isInstanceOpen_001f9394);
      if (cVar1 == '\0') goto LAB_00183597;
      puVar4 = PTR_s_setRawDeviceOpen__001f9390;
      if (DAT_001e7564 == (short)(param_1 >> 8)) {
        puVar4 = PTR_s_setBlockDeviceOpen__001f938c;
      }
      _objc_msgSend(iVar2,puVar4,0);
    }
    uVar3 = 0;
  }
  return uVar3;
}

