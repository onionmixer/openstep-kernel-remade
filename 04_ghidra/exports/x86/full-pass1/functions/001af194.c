/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001af194 */

undefined4
FUN_001af194(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,uint *param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 local_c;
  undefined *local_8;
  
  uVar2 = _objc_msgSend(param_1,PTR_s_deviceDescription_001f9378,PTR_s_configTable_001f9cdc);
  iVar3 = _objc_msgSend(uVar2);
  if ((iVar3 != 0) &&
     (pcVar4 = (char *)_objc_msgSend(iVar3,PTR_s_valueForStringKey__001f9308,param_4),
     pcVar4 != (char *)0x0)) {
    uVar5 = 0xffffffff;
    pcVar6 = pcVar4;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (~uVar5 <= *param_5) {
      _strcpy(param_3,pcVar4);
      *param_5 = ~uVar5;
      return 0;
    }
  }
  local_c = param_1;
  local_8 = PTR_s_IODirectDevice_001fa3d8;
  uVar2 = _objc_msgSendSuper(&local_c,PTR_s_getCharValues_forParameter_count_001f9530,param_3,
                             param_4,param_5);
  return uVar2;
}

