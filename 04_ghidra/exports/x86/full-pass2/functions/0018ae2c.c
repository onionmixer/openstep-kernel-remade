/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018ae2c */

undefined4 _getargs(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined **ppuVar4;
  char *pcVar5;
  undefined **ppuVar6;
  undefined4 local_8;
  
  _strncpy(&_boot_file,(char *)0x110b8,0x40);
  if (*param_1 == '\0') {
    uVar2 = 1;
  }
  else {
    while (iVar3 = _isargsep((int)*param_1), iVar3 != 0) {
      param_1 = param_1 + 1;
    }
LAB_0018b00e:
    if (*param_1 != '\0') {
      pcVar5 = param_1;
      if (*param_1 == '-') {
        pcVar5 = &_init_args;
        _argstrcpy(param_1,&_init_args);
        do {
          cVar1 = *pcVar5;
          if (cVar1 == 'd') {
            _boothowto = _boothowto | 4;
          }
          else if (cVar1 < 'e') {
            if (cVar1 == 'a') {
              _boothowto = _boothowto | 1;
            }
          }
          else if (cVar1 == 'f') {
            _boothowto = _boothowto | 0x200000;
          }
          else if (cVar1 == 's') {
            _boothowto = _boothowto | 2;
          }
          cVar1 = *pcVar5;
          if (cVar1 == '\0') break;
          pcVar5 = pcVar5 + 1;
          iVar3 = _isargsep((int)cVar1);
        } while (iVar3 == 0);
      }
      else {
        while (iVar3 = _isargsep((int)*pcVar5), iVar3 == 0) {
          if (*pcVar5 == '=') goto LAB_0018af29;
          pcVar5 = pcVar5 + 1;
        }
        if (*pcVar5 == '=') {
LAB_0018af29:
          cVar1 = *pcVar5;
          ppuVar6 = &_kernargs;
          if (_kernargs != (undefined *)0x0) {
            ppuVar4 = &PTR__nbuf_001e19b8;
            do {
              iVar3 = _strncmp(param_1,*ppuVar6,(int)pcVar5 - (int)param_1);
              if (iVar3 == 0) goto LAB_0018af64;
              ppuVar4 = ppuVar4 + 2;
              ppuVar6 = ppuVar6 + 2;
            } while (*ppuVar6 != (undefined *)0x0);
          }
        }
      }
      goto LAB_0018afdc;
    }
LAB_0018b017:
    uVar2 = 0;
  }
  return uVar2;
LAB_0018af64:
  while (iVar3 = _isargsep((int)*pcVar5), iVar3 != 0) {
    pcVar5 = pcVar5 + 1;
  }
  if ((*pcVar5 == '=') && (cVar1 != '=')) {
    param_1 = pcVar5 + 1;
  }
  else {
    iVar3 = _getval(pcVar5,&local_8);
    if (iVar3 == 0) {
      *(undefined4 *)*ppuVar4 = local_8;
    }
    else if (iVar3 == 1) {
      _argstrcpy(pcVar5 + 1,*ppuVar4);
    }
  }
LAB_0018afdc:
  while (iVar3 = _isargsep((int)*param_1), iVar3 == 0) {
    param_1 = param_1 + 1;
  }
  if (*param_1 == '\0') goto LAB_0018b017;
  do {
    iVar3 = _isargsep((int)*param_1);
    if (iVar3 == 0) break;
    param_1 = param_1 + 1;
  } while (*param_1 != '\0');
  goto LAB_0018b00e;
}

