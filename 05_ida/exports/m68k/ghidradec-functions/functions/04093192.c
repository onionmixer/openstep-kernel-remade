
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _getargs(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  char *pcVar7;
  int *piVar8;
  undefined *puVar9;
  undefined4 uStack_8;
  
  uVar6 = 0;
  if (*param_1 == '\0') {
    uVar6 = 1;
  }
  else {
    while (iVar2 = _isargsep((int)*param_1), iVar2 != 0) {
      param_1 = param_1 + 1;
    }
    while (*param_1 != '\0') {
      pcVar7 = param_1;
      if (*param_1 == '-') {
        pcVar7 = (char *)&_init_args;
        _argstrcpy(param_1,&_init_args);
        _printf(aInitArgS,&_init_args);
        do {
          switch(*pcVar7) {
          case :
            __boothowto = __boothowto | 1;
            break;
          case :
            __boothowto = __boothowto | 0x20000;
            break;
          case :
            __boothowto = __boothowto | 0x10;
            break;
          case :
            __boothowto = __boothowto | 0x40000;
            break;
          case :
            __boothowto = __boothowto | 2;
          }
          cVar1 = *pcVar7;
          if (cVar1 == '\0') break;
          pcVar7 = pcVar7 + 1;
          iVar2 = _isargsep((int)cVar1);
        } while (iVar2 == 0);
      }
      else {
        for (; (iVar2 = _isargsep((int)*pcVar7), iVar2 == 0 && (*pcVar7 != '='));
            pcVar7 = pcVar7 + 1) {
        }
        cVar1 = *pcVar7;
        *pcVar7 = '\0';
        piVar8 = &_kernargs;
        if (_kernargs != 0) {
          puVar9 = unk_40B28F2;
          piVar4 = (int *)(unk_40B28F2 + 4);
loc_4093310:
          uVar3 = _strlen(param_1);
          iVar2 = _strncmp(param_1,*piVar8,uVar3);
          if (iVar2 != 0) goto loc_4093448;
          *pcVar7 = cVar1;
          while (iVar2 = _isargsep((int)*pcVar7), iVar2 != 0) {
            pcVar7 = pcVar7 + 1;
          }
          if ((*pcVar7 == '=') && (cVar1 != '=')) {
            _printf(aNoSpacesSurrou);
            param_1 = pcVar7 + 1;
          }
          else {
            if (param_2 == 0) {
loc_40933AC:
              _printf(aKernelFlagS,*piVar8);
            }
            else {
              if ((*pcVar7 == '=') && (iVar2 = _isargsep((int)pcVar7[1]), iVar2 != 0)) {
                if (*(uint **)puVar9 == (uint *)0x0) {
                  uVar5 = (uint)*(byte *)(_slot_id_bmap + *piVar4);
                }
                else {
                  uVar5 = **(uint **)puVar9;
                }
                _printf(aKernelFlagS0xX,*piVar8,uVar5);
                goto loc_409346C;
              }
              if (param_2 == 0) goto loc_40933AC;
            }
            iVar2 = _getval(pcVar7,&uStack_8);
            if (iVar2 == 0) {
              if (*(undefined4 **)puVar9 == (undefined4 *)0x0) {
                *(undefined *)(_slot_id_bmap + *piVar4) = (undefined)uStack_8;
              }
              else {
                **(undefined4 **)puVar9 = uStack_8;
              }
              if (param_2 == 0) {
                if (*(undefined4 **)puVar9 == (undefined4 *)0x0) {
                  _printf(&a0xX,*(undefined *)(_slot_id_bmap + *piVar4));
                }
                else {
                  _printf(&a0xX,**(undefined4 **)puVar9);
                }
              }
            }
            else if ((iVar2 == 1) && (_argstrcpy(pcVar7 + 1,*(int *)puVar9), param_2 == 0)) {
              _printf(&aS_4,*(int *)puVar9);
            }
          }
          goto loc_409346C;
        }
loc_409345A:
        _printf(aKernelFlagSUnk,param_1);
        uVar6 = 1;
      }
loc_409346C:
      while (iVar2 = _isargsep((int)*param_1), iVar2 == 0) {
        param_1 = param_1 + 1;
      }
      while (iVar2 = _isargsep((int)*param_1), iVar2 != 0) {
        if (*param_1 == '\0') {
          return uVar6;
        }
        param_1 = param_1 + 1;
      }
    }
  }
  return uVar6;
loc_4093448:
  puVar9 = (undefined *)((int)puVar9 + 0xc);
  piVar4 = piVar4 + 3;
  piVar8 = piVar8 + 3;
  if (*piVar8 == 0) goto loc_409345A;
  goto loc_4093310;
}
