/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00181730 */

undefined4 FUN_00181730(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char *pcVar1;
  undefined4 uVar2;
  char local_84 [128];
  
  _sprintf(local_84,s_Share__s_001e100b,param_3);
  pcVar1 = (char *)_objc_msgSend(param_1,PTR_s_stringForKey__001f932c,local_84);
  if ((pcVar1 == (char *)0x0) || ((*pcVar1 != 'y' && (*pcVar1 != 'Y')))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

