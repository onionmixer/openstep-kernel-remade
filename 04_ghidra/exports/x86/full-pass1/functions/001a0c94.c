/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a0c94 */

undefined4 FUN_001a0c94(int param_1,undefined4 param_2,char *param_3,char *param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  iVar3 = 0xb;
  bVar6 = true;
  pcVar4 = param_4;
  pcVar5 = s_Resolution_001e4b62;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    *(undefined4 *)(param_1 + 300) = *(undefined4 *)param_3;
    uVar2 = _objc_msgSend(param_1,PTR_s_getResolution_001f9554);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_setResolution__001f9568,uVar2);
    uVar2 = 0;
  }
  else {
    iVar3 = 9;
    bVar6 = true;
    pcVar4 = s_Inverted_001e4b6d;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *param_4 == *pcVar4;
      param_4 = param_4 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar6);
    if (bVar6) {
      cVar1 = *param_3;
      *(char *)(param_1 + 0x130) = cVar1;
      _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_setInverted__001f956c,(int)cVar1);
      uVar2 = 0;
    }
    else {
      uVar2 = 0xfffffd39;
    }
  }
  return uVar2;
}

