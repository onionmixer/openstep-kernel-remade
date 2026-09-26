/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011c760 */

int FUN_0011c760(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined **ppuVar4;
  char local_130;
  char local_12f [255];
  undefined4 local_30 [3];
  int local_24 [2];
  int *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_8;
  
  iVar3 = 0;
  _pn_alloc(param_4);
  iVar1 = _dnlc_lookupSymLink(param_2,param_3);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 0x44) == '\0')) {
    local_24[0] = *param_4;
    local_24[1] = 0x400;
    local_1c = local_24;
    local_18 = 1;
    local_14 = 0;
    local_10 = 1;
    local_8 = 0x400;
    iVar3 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x44))
                      (param_1,&local_1c,*(undefined4 *)(_active_u + 0x1c));
    param_4[2] = 0x400 - local_8;
    if (iVar3 != 0) goto LAB_0011c967;
    _dnlc_enterSymLink(param_2,param_3,param_4);
  }
  else {
    _bcopy(*(void **)(iVar1 + 0x40),(void *)*param_4,(int)*(short *)(iVar1 + 0x46));
    param_4[2] = (int)*(short *)(iVar1 + 0x46);
  }
  *(undefined1 *)(param_4[2] + *param_4) = 0;
  pcVar2 = (char *)*param_4;
  while (pcVar2 = _index(pcVar2,0x24), pcVar2 != (char *)0x0) {
    if (((char *)*param_4 == pcVar2) || (pcVar2[-1] == '/')) {
      if (pcVar2 != (char *)0x0) {
        _pn_alloc(local_30);
        if (param_4[2] == 0) goto LAB_0011c944;
        goto LAB_0011c884;
      }
      break;
    }
    pcVar2 = pcVar2 + 1;
  }
  goto LAB_0011c963;
LAB_0011c884:
  do {
    if (*(char *)param_4[1] == '/') {
      iVar3 = _pn_append(local_30,&DAT_001db784);
      if (iVar3 != 0) goto LAB_0011c957;
      _pn_skipslash(param_4);
    }
    iVar3 = _pn_getcomponent(param_4,&local_130);
    if (iVar3 != 0) goto LAB_0011c957;
    pcVar2 = &local_130;
    if (local_130 == '$') {
      ppuVar4 = &_metalinks;
      if (_metalinks != (undefined *)0x0) {
        do {
          iVar1 = _strcmp(local_12f,*ppuVar4);
          if (iVar1 == 0) break;
          ppuVar4 = ppuVar4 + 3;
        } while (*ppuVar4 != (undefined *)0x0);
        if ((*ppuVar4 != (undefined *)0x0) &&
           ((pcVar2 = ppuVar4[1], *pcVar2 != '\0' || (pcVar2 = ppuVar4[2], pcVar2 != (char *)0x0))))
        goto LAB_0011c92b;
      }
      iVar3 = 2;
      goto LAB_0011c957;
    }
LAB_0011c92b:
    iVar3 = _pn_append(local_30,pcVar2);
    if (iVar3 != 0) goto LAB_0011c957;
  } while (param_4[2] != 0);
LAB_0011c944:
  if (iVar3 == 0) {
    iVar3 = _pn_set(param_4,local_30[0]);
  }
LAB_0011c957:
  _pn_free(local_30);
LAB_0011c963:
  if (iVar3 == 0) {
    return 0;
  }
LAB_0011c967:
  _pn_free(param_4);
  return iVar3;
}

