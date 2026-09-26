/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cebb0 */

/* Entry confirmed from original binary metadata: original symbol __objc_msgForward */

undefined4 __objc_msgForward(undefined4 param_1,undefined *param_2)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  byte extraout_DL;
  byte bStackY_7b;
  
  if (param_2 != PTR_s_forward__001f9cf0) {
    uVar2 = _objc_msgSend(param_1,PTR_s_forward__001f9cf0,param_2,&param_1);
    return uVar2;
  }
  pcVar3 = (char *)___objc_error(param_1,"Does not recognize selector %s",s_forward___00207584);
  cVar1 = (char)pcVar3;
  *pcVar3 = *pcVar3 + cVar1;
  *pcVar3 = *pcVar3 + cVar1;
  *pcVar3 = *pcVar3 + cVar1;
  *pcVar3 = *pcVar3 + cVar1;
  *pcVar3 = *pcVar3 + cVar1;
  *pcVar3 = *pcVar3 + cVar1;
  uVar2 = in(0x8b);
  return CONCAT31((int3)((uint)uVar2 >> 8),(char)uVar2 + -0x7d + CARRY1(bStackY_7b,extraout_DL));
}

