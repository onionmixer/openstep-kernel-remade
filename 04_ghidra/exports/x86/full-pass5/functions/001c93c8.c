/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c93c8 */

void FUN_001c93c8(undefined4 param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  cVar1 = *param_2;
  uVar3 = param_3;
  if (cVar1 == '@') {
    param_3 = _objc_msgSend(param_3,PTR_s_name_001f9228,param_3);
    pcVar2 = "%s[0x%x]";
LAB_001c9413:
    _NXPrintf(param_1,pcVar2,param_3,uVar3);
    return;
  }
  if (cVar1 < 'A') {
    if ((cVar1 == '%') || (cVar1 == '*')) {
      pcVar2 = "\"%s\"";
      goto LAB_001c942a;
    }
  }
  else if (cVar1 == 'i') {
    pcVar2 = "%d[0x%x]";
    goto LAB_001c9413;
  }
  pcVar2 = "0x%x";
LAB_001c942a:
  _NXPrintf(param_1,pcVar2,param_3);
  return;
}

