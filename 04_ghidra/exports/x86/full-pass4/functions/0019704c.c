/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019704c */

undefined4 _kmputc(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (_kmId == 0) {
    iVar2 = _kmAlertConsole;
    if (_kmAlertConsole == 0) {
      iVar2 = _basicConsole;
    }
    if (param_2 == 10) {
      (**(code **)(iVar2 + 0x14))(iVar2,0xd);
    }
    (**(code **)(iVar2 + 0x14))(iVar2,(int)(char)param_2);
    uVar1 = 0;
  }
  else {
    if (param_2 == 10) {
      _objc_msgSend(_kmId,PTR_s_kmPutc__001f94a0,0xd);
    }
    uVar1 = _objc_msgSend(_kmId,PTR_s_kmPutc__001f94a0,param_2);
  }
  return uVar1;
}

