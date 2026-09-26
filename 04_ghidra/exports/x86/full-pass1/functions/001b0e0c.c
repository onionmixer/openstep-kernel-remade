/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b0e0c */

int FUN_001b0e0c(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 *param_6)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_8;
  
  *param_6 = 0;
  if ((*(char *)(param_1 + 0x1d0) == '\0') || (*(int *)(param_1 + 0x114) != param_3)) {
    iVar2 = -0x2c2;
  }
  else {
    iVar2 = _IOGetObjectForDeviceName(param_4,&local_8);
    if ((iVar2 == 0) ||
       (((local_8 = _objc_getClass(param_5), local_8 != 0 &&
         (cVar1 = _objc_msgSend(local_8,PTR_s_respondsTo__001f9464,PTR_s_probe_001f9a2c),
         cVar1 != '\0')) && (local_8 = _objc_msgSend(local_8,PTR_s_probe_001f9a2c), local_8 != 0))))
    {
      cVar1 = _objc_msgSend(local_8,PTR_s_respondsTo__001f9464,PTR_s_devicePort_001f9a48);
      if (cVar1 == '\0') {
        iVar2 = -0x2c1;
      }
      else {
        uVar3 = _objc_msgSend(local_8,PTR_s_devicePort_001f9a48);
        *param_6 = uVar3;
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}

