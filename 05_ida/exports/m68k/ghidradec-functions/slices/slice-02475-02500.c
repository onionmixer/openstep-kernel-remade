/* GHIDRADEC_FUNCTION index=2475 start=0x4092d2c */

/* WARNING: Control flow encountered bad instruction data */

void _bcopy(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  word wVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  
  if (0 < (int)param_3) {
    if (param_1 < param_2) {
      puVar6 = (undefined *)(param_3 + (int)param_1);
      puVar9 = (undefined *)(param_3 + (int)param_2);
      uVar2 = (uint)puVar9 & 3;
      uVar1 = uVar2;
      while ((uVar1 != 0 && (wVar3 = (sword)uVar2 - 1, uVar2 = (uint)wVar3, wVar3 != 0xffff))) {
        puVar6 = puVar6 + -1;
        puVar9 = puVar9 + -1;
        *puVar9 = *puVar6;
        param_3 = param_3 - 1;
        uVar1 = param_3;
      }
      switch(param_3 & 0x1c) {
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
    if (param_2 != param_1) {
      uVar2 = -(int)param_2 & 3;
      uVar1 = uVar2;
      while ((uVar1 != 0 && (wVar3 = (sword)uVar2 - 1, uVar2 = (uint)wVar3, wVar3 != 0xffff))) {
        *(undefined *)param_2 = *(undefined *)param_1;
        param_3 = param_3 - 1;
        param_1 = (undefined4 *)((int)param_1 + 1);
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = param_3;
      }
      uVar2 = param_3;
      puVar4 = param_1;
      puVar7 = param_2;
      switch(param_3 & 0x1c) {
      case :
        goto loc_4092d80;
      case :
        goto loc_4092d7e;
      case :
        goto loc_4092d7c;
      case :
        goto loc_4092d7a;
      case :
        goto loc_4092d78;
      case :
        goto loc_4092d76;
      case :
        goto loc_4092d74;
      }
      while (param_3 = uVar2 - 0x20, 0x1f < (int)uVar2) {
        param_1 = puVar4 + 1;
        param_2 = puVar7 + 1;
        *puVar7 = *puVar4;
loc_4092d74:
        puVar4 = param_1 + 1;
        puVar7 = param_2 + 1;
        *param_2 = *param_1;
loc_4092d76:
        param_1 = puVar4 + 1;
        param_2 = puVar7 + 1;
        *puVar7 = *puVar4;
loc_4092d78:
        puVar4 = param_1 + 1;
        puVar7 = param_2 + 1;
        *param_2 = *param_1;
loc_4092d7a:
        param_1 = puVar4 + 1;
        param_2 = puVar7 + 1;
        *puVar7 = *puVar4;
loc_4092d7c:
        puVar4 = param_1 + 1;
        puVar7 = param_2 + 1;
        *param_2 = *param_1;
loc_4092d7e:
        param_1 = puVar4 + 1;
        param_2 = puVar7 + 1;
        *puVar7 = *puVar4;
loc_4092d80:
        puVar4 = param_1 + 1;
        puVar7 = param_2 + 1;
        *param_2 = *param_1;
        uVar2 = param_3;
      }
      puVar5 = puVar4;
      puVar8 = puVar7;
      if ((param_3 & 2) != 0) {
        puVar5 = (undefined4 *)((int)puVar4 + 2);
        puVar8 = (undefined4 *)((int)puVar7 + 2);
        *(undefined2 *)puVar7 = *(undefined2 *)puVar4;
      }
      if ((param_3 & 1) != 0) {
        *(undefined *)puVar8 = *(undefined *)puVar5;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2476 start=0x4092df6 */

void _bytecopy(undefined *param_1,undefined *param_2,sword param_3)

{
  param_3 = param_3 + -1;
  do {
    *param_2 = *param_1;
    param_3 = param_3 + -1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (param_3 != -1);
  return;
}
/* GHIDRADEC_FUNCTION index=2477 start=0x4092e12 */

void _bzero(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  word wVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (0 < (int)param_2) {
    uVar2 = -(int)param_1 & 3;
    uVar1 = uVar2;
    while ((uVar1 != 0 && (wVar3 = (sword)uVar2 - 1, uVar2 = (uint)wVar3, wVar3 != 0xffff))) {
      *(undefined *)param_1 = 0;
      param_2 = param_2 - 1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      uVar1 = param_2;
    }
    uVar2 = param_2;
    puVar4 = param_1;
    switch(param_2 & 0x1c) {
    case :
      goto loc_4092e58;
    case :
      goto loc_4092e56;
    case :
      goto loc_4092e54;
    case :
      goto loc_4092e52;
    case :
      goto loc_4092e50;
    case :
      goto loc_4092e4e;
    case :
      goto loc_4092e4c;
    }
    while (param_2 = uVar2 - 0x20, 0x1f < (int)uVar2) {
      param_1 = puVar4 + 1;
      *puVar4 = 0;
loc_4092e4c:
      puVar4 = param_1 + 1;
      *param_1 = 0;
loc_4092e4e:
      param_1 = puVar4 + 1;
      *puVar4 = 0;
loc_4092e50:
      puVar4 = param_1 + 1;
      *param_1 = 0;
loc_4092e52:
      param_1 = puVar4 + 1;
      *puVar4 = 0;
loc_4092e54:
      puVar4 = param_1 + 1;
      *param_1 = 0;
loc_4092e56:
      param_1 = puVar4 + 1;
      *puVar4 = 0;
loc_4092e58:
      puVar4 = param_1 + 1;
      *param_1 = 0;
      uVar2 = param_2;
    }
    puVar5 = puVar4;
    if ((param_2 & 2) != 0) {
      puVar5 = (undefined4 *)((int)puVar4 + 2);
      *(undefined2 *)puVar4 = 0;
    }
    if ((param_2 & 1) != 0) {
      *(undefined *)puVar5 = 0;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2478 start=0x4092e76 */

char _ffs(uint param_1)

{
  char cVar1;
  
  cVar1 = '\0';
  if (param_1 != 0) {
    if ((sword)param_1 == 0) {
      param_1 = param_1 >> 0x10;
      cVar1 = '\x10';
    }
    if ((char)param_1 == '\0') {
      param_1 = param_1 >> 8;
      cVar1 = cVar1 + '\b';
    }
    cVar1 = *(char *)((int)&word_4092EAA + (param_1 & 0xff)) + cVar1;
  }
  return cVar1;
}
/* GHIDRADEC_FUNCTION index=2479 start=0x4092faa */

char _msb(uint param_1)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  
  cVar2 = '\0';
  if (param_1 != 0) {
    cVar2 = '\x18';
    uVar3 = param_1 >> 0x18;
    if ((char)(param_1 >> 0x18) == '\0') {
      cVar2 = '\x10';
      uVar3 = (param_1 & 0xffffff) >> 0x10;
      if ((char)((param_1 & 0xffffff) >> 0x10) == '\0') {
        cVar2 = '\b';
        uVar1 = param_1 << 8 & 0xffffff;
        uVar3 = uVar1 >> 0x10;
        if ((char)(uVar1 >> 0x10) == '\0') {
          cVar2 = '\0';
          uVar3 = (param_1 << 8 & 0xffff) >> 8;
        }
      }
    }
    if (0xf < (word)uVar3) {
      cVar2 = cVar2 + '\x04';
      uVar3 = uVar3 >> 4;
    }
    cVar2 = *(char *)((int)&word_4092FF6 + (uVar3 & 0xf)) + cVar2;
  }
  return cVar2;
}
/* GHIDRADEC_FUNCTION index=2480 start=0x4093006 */

char * _index(char *param_1,int param_2)

{
  char *pcVar1;
  
  if (param_2 == 0) {
    do {
      pcVar1 = param_1;
      param_1 = pcVar1 + 1;
    } while (*pcVar1 != '\0');
    return pcVar1;
  }
  do {
    pcVar1 = param_1;
    if (*pcVar1 == '\0') {
      return (char *)0x0;
    }
    param_1 = pcVar1 + 1;
  } while ((char)param_2 != *pcVar1);
  return pcVar1;
}
/* GHIDRADEC_FUNCTION index=2481 start=0x4093036 */

char * _strncpy(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar3 = param_1;
  do {
    iVar2 = param_3 + -1;
    if (param_3 < 1) {
      return param_1;
    }
    cVar1 = *param_2;
    pcVar4 = pcVar3 + 1;
    *pcVar3 = cVar1;
    param_3 = iVar2;
    pcVar3 = pcVar4;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  while (0 < iVar2) {
    *pcVar4 = '\0';
    iVar2 = iVar2 + -1;
    pcVar4 = pcVar4 + 1;
  }
  return param_1;
}
/* GHIDRADEC_FUNCTION index=2482 start=0x409305c */

char * _strcat(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = param_1;
  do {
    pcVar3 = pcVar2;
    pcVar2 = pcVar3 + 1;
  } while (*pcVar3 != '\0');
  do {
    cVar1 = *param_2;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return param_1;
}
/* GHIDRADEC_FUNCTION index=2483 start=0x4093078 */

int _strcmp(char *param_1,char *param_2)

{
  char cVar1;
  
  do {
    if (*param_1 != *param_2) {
      return (int)*param_1 - (int)*param_2;
    }
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return 0;
}
/* GHIDRADEC_FUNCTION index=2484 start=0x40930a0 */

char * _strcpy(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  do {
    cVar1 = *param_2;
    *pcVar2 = cVar1;
    pcVar2 = pcVar2 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return param_1;
}
/* GHIDRADEC_FUNCTION index=2485 start=0x40930b6 */

int _strncmp(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  
  while( true ) {
    if (param_3 < 1) {
      return 0;
    }
    cVar1 = *param_1;
    if (cVar1 != *param_2) break;
    param_3 = param_3 + -1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    if (cVar1 == '\0') {
      return 0;
    }
  }
  return (int)cVar1 - (int)*param_2;
}
/* GHIDRADEC_FUNCTION index=2486 start=0x40930e6 */

int _strlen(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = -1;
  do {
    iVar2 = iVar2 + 1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2487 start=0x40930fa */

undefined8 __lshldi3(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  if (param_4 != 0) {
    uVar1 = 0x20 - param_4;
    if ((int)uVar1 < 1) {
      param_1 = param_2 << (-uVar1 & 0x3f);
      param_2 = 0;
    }
    else {
      uVar1 = param_2 >> (uVar1 & 0x3f);
      param_2 = param_2 << (param_4 & 0x3f);
      param_1 = uVar1 | param_1 << (param_4 & 0x3f);
    }
  }
  return CONCAT44(param_1,param_2);
}
/* GHIDRADEC_FUNCTION index=2488 start=0x4093146 */

undefined8 __lshrdi3(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  if (param_4 != 0) {
    uVar1 = 0x20 - param_4;
    if ((int)uVar1 < 1) {
      param_2 = param_1 >> (-uVar1 & 0x3f);
      param_1 = 0;
    }
    else {
      uVar1 = param_1 << (uVar1 & 0x3f);
      param_1 = param_1 >> (param_4 & 0x3f);
      param_2 = uVar1 | param_2 >> (param_4 & 0x3f);
    }
  }
  return CONCAT44(param_1,param_2);
}
/* GHIDRADEC_FUNCTION index=2489 start=0x4093192 */

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
/* GHIDRADEC_FUNCTION index=2490 start=0x40934ae */

undefined4 _isargsep(char param_1)

{
  undefined4 uVar1;
  
  if ((((param_1 == ' ') || (param_1 == '\0')) || (param_1 == '\t')) || (param_1 == ',')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2491 start=0x40934d6 */

int _argstrcpy(char *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    iVar1 = _isargsep((int)*param_1);
    if (iVar1 != 0) break;
    iVar2 = iVar2 + 1;
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2492 start=0x409350c */

undefined4 _getval(char *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  byte *pbVar8;
  
  iVar6 = 1;
  if (*param_1 == '=') {
    pcVar7 = param_1 + 1;
    if (*pcVar7 == '-') {
      iVar6 = -1;
      pcVar7 = param_1 + 2;
    }
    pbVar8 = (byte *)(pcVar7 + 1);
    iVar4 = *pcVar7 + -0x30;
    uVar5 = 10;
    if (iVar4 != 0) goto loc_4093586;
    bVar3 = *pbVar8;
    if ('/' < (char)bVar3) {
      if ((char)bVar3 < '8') {
        iVar4 = (char)bVar3 + -0x30;
        pbVar8 = (byte *)(pcVar7 + 2);
        uVar5 = 8;
        goto loc_4093586;
      }
      if (bVar3 == 0x62) {
        uVar5 = 2;
        pbVar8 = (byte *)(pcVar7 + 2);
        goto loc_4093586;
      }
      if (bVar3 == 0x78) {
        uVar5 = 0x10;
        pbVar8 = (byte *)(pcVar7 + 2);
        goto loc_4093586;
      }
    }
    iVar1 = _isargsep((int)(char)*pbVar8);
    if (iVar1 != 0) {
loc_4093586:
      do {
        bVar3 = *pbVar8;
        if ((bVar3 < 0x30) || (0x39 < bVar3)) {
          if ((byte)(bVar3 + 0x9f) < 6) {
            bVar3 = bVar3 + 0xa9;
          }
          else {
            if (5 < (byte)(bVar3 + 0xbf)) {
              iVar1 = _isargsep(bVar3);
              if (iVar1 != 0) {
                *param_2 = iVar6 * iVar4;
                goto loc_40935EC;
              }
              break;
            }
            bVar3 = bVar3 - 0x37;
          }
        }
        else {
          bVar3 = bVar3 - 0x30;
        }
        if (uVar5 <= bVar3) break;
        iVar4 = (uint)bVar3 + uVar5 * iVar4;
        pbVar8 = pbVar8 + 1;
      } while( true );
    }
    uVar2 = 1;
  }
  else {
    *param_2 = 1;
loc_40935EC:
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2493 start=0x40935f8 */

void _machparam(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined uVar4;
  undefined4 *puVar5;
  undefined auStack_28 [4];
  undefined auStack_24 [32];
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar3 = _suser();
  if (iVar3 != 0) {
    uVar4 = _copyinstr(*puVar1,auStack_24,0x20,auStack_28);
    *(undefined *)(dword_40B57D4 + 100) = uVar4;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      for (puVar5 = &_kernargs; *(char *)*puVar5 != '\0'; puVar5 = puVar5 + 3) {
        iVar3 = _strcmp((char *)*puVar5,auStack_24);
        if (iVar3 == 0) {
          piVar2 = (int *)puVar5[1];
          if (piVar2 != (int *)0x0) {
            *piVar2 = puVar1[1] + *piVar2;
            return;
          }
          *(char *)(_slot_id_bmap + puVar5[2]) =
               *(char *)((int)puVar1 + 7) + *(char *)(_slot_id_bmap + puVar5[2]);
          return;
        }
      }
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2494 start=0x40936a4 */

void _mon_boot(int param_1)

{
  _strcat(_boot_param,&_boot_dev);
  _strcat(_boot_param,&asc_40AC3DC);
  if (_boot_info != '\0') {
    _strcat(_boot_param,&_boot_info);
    _strcat(_boot_param,&asc_40AC3DC);
  }
  _strcat(_boot_param,&_boot_file);
  _strcat(_boot_param,&asc_40AC3DC);
  if (param_1 != 0) {
    _strcat(_boot_param,param_1);
    _strcat(_boot_param,&asc_40AC3DC);
  }
  _strcat(_boot_param,_boot_args);
  _mon_call(_boot_param);
  return;
}
/* GHIDRADEC_FUNCTION index=2495 start=0x4093762 */

void _mon_call(undefined4 param_1)

{
  _adb_watchdog(0);
  _boot_action = param_1;
  __m68k_trap(0xd);
  _adb_watchdog(1);
  return;
}
/* GHIDRADEC_FUNCTION index=2496 start=0x40937ac */

void _kernel_thread_noblock(undefined4 param_1,undefined4 param_2)

{
  _callout_dispatch(4,sub_4093792,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=2497 start=0x40937c8 */

void _halt_thread(void)

{
  _boot(1,_reboot_how,&unk_40A62E7);
  return;
}
/* GHIDRADEC_FUNCTION index=2498 start=0x40937e6 */

void _reboot_mach(uint param_1)

{
  if (_kernel_task == 0) {
    _boot(1,param_1 | 4,&unk_40A62E7);
  }
  else {
    _reboot_how = param_1;
    _kernel_thread_noblock(_kernel_task,_halt_thread);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2499 start=0x409382c */

void _nmi(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
         undefined4 param_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined6 *puVar4;
  uint uVar5;
  
  bVar1 = false;
  bVar2 = false;
  if ((_dma_chip == 0x139) || ((*(uint *)(_slot_id + 0x2200020) & 1) == 0)) {
    uVar5 = *(uint *)(_slot_id + 0x200e008);
    *(byte *)(_slot_id + 0x200e001) = *(byte *)(_slot_id + 0x200e001) | 0x10;
    if (-1 < (char)uVar5) {
      if (((byte)(uVar5 >> 8) & 0x18) == 0x18) {
        bVar1 = true;
      }
      else if (((uVar5 & 0xffff) >> 8 & 8) == 0) {
        bVar2 = true;
      }
    }
  }
  else {
    *(undefined4 *)(_slot_id + 0x2200020) = 0;
    bVar1 = true;
  }
  iVar3 = _slot_id;
  if ((_dma_chip != 0x139) && ((*_intrstat & 0x40000000) != 0)) {
    *(undefined4 *)(_slot_id + 0x2200004) = 0;
    *(undefined4 *)(iVar3 + 0x2200004) = 0;
    uVar5 = (uint)(*(int *)(iVar3 + 0x2200008) - (iVar3 + 0x4000000)) /
            (uint)(0x8000000 / _num_regions);
    puVar4 = &aFront;
    if ((uVar5 & 1) != 0) {
      puVar4 = (undefined6 *)&aBack;
    }
    uVar5 = uVar5 & 0xfffffffe;
    _printf(aParityErrorAtA,*(undefined4 *)(iVar3 + 0x2200008),uVar5,uVar5 | 1,puVar4);
                    /* WARNING: Subroutine does not return */
    _panic(aParityError);
  }
  if (bVar1) {
    _mini_mon(&aNmi,aNmiMiniMonitor,param_1,param_2,param_3,param_4,param_5);
  }
  else if (bVar2) {
    _mini_mon(&aRestart,aRestartPowerOf);
  }
  return;
}

