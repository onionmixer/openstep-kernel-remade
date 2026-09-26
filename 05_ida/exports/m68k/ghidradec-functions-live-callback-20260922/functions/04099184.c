
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _setconf(void)

{
  undefined (*pauVar1) [50];
  char cVar2;
  int iVar3;
  undefined5 *puVar4;
  int iVar5;
  sword sVar6;
  char *pcVar7;
  undefined *puVar8;
  char acStack_84 [128];
  
  sVar6 = 0;
  if ((__boothowto & 1) != 0) goto loc_40991AC;
  if (_rootdevice == '\0') {
    iVar5 = 0;
    if (_boot_dev != '\0') {
      if (_boot_info != '\0') {
        iVar5 = byte_40C8ED5 + -0x30;
      }
      dword_40B5644 = &off_40B2BDE;
      pauVar1 = off_40B2BDE;
      while (pauVar1 != (undefined (*) [50])0x0) {
        iVar3 = _strcmp(&_boot_dev,dword_40B5644[1]);
        if (iVar3 == 0) {
          puVar8 = _bus_dinit;
          iVar3 = _bus_dinit._0_4_;
          while (iVar3 != 0) {
            if ((((*(sword *)((int)puVar8 + 0x1a) != 0) && (iVar5 == *(sword *)((int)puVar8 + 4)))
                && (*(undefined (**) [50])puVar8 == *dword_40B5644)) &&
               (iVar3 = _strcmp(*(undefined4 *)((int)puVar8 + 0x16),dword_40B5644[1]), iVar3 == 0))
            {
              iVar3 = _printf(aRootOnSD,*(undefined4 *)((int)puVar8 + 0x16),iVar5);
              goto loc_40993F4;
            }
            puVar8 = (undefined *)((int)puVar8 + 0x2a);
            iVar3 = *(int *)puVar8;
          }
        }
        pauVar1 = *(undefined (**) [50])((int)dword_40B5644 + 10);
        dword_40B5644 = (undefined (**) [50])((int)dword_40B5644 + 10);
      }
      _printf(aRootDeviceSDNo,&_boot_dev,iVar5);
    }
    _printf(aNoSuitableRoot);
    iVar3 = _mon_boot(&aH);
loc_40993F4:
    if (*(sword *)(dword_40B5644 + 2) == -1) {
loc_4099402:
      _rootfs = 0x6e;
      byte_40B6A8D = 0x66;
      byte_40B6A8E = 0x73;
      byte_40B6A8F = 0;
    }
    else {
      _rootfs = 0x34;
      byte_40B6A8D = 0x2e;
      byte_40B6A8E = 0x33;
      byte_40B6A8F = 0;
      _rootdev = sVar6 + (sword)(iVar5 << 3);
      iVar3 = CONCAT22((sword)((uint)(iVar5 << 3) >> 0x10),_rootdev);
      _rootdev = _rootdev | (word)*(byte *)(dword_40B5644 + 2) << 8;
      *(word *)(dword_40B5644 + 2) = _rootdev;
    }
    return iVar3;
  }
  do {
    if ((__boothowto & 1) == 0) {
      pcVar7 = &_rootdevice;
      iVar3 = _printf(aRootOnS,&_rootdevice);
    }
    else {
loc_40991AC:
      _printf(aRootDevice);
      pcVar7 = acStack_84;
      iVar3 = _gets(pcVar7,pcVar7);
    }
    dword_40B5644 = &off_40B2BDE;
    pauVar1 = off_40B2BDE;
    while (pauVar1 != (undefined (*) [50])0x0) {
      if (((*dword_40B5644[1])[0] == *pcVar7) && ((*dword_40B5644[1])[1] == pcVar7[1])) {
        if (*(sword *)(dword_40B5644 + 2) == -1) goto loc_4099402;
        if (pcVar7[3] == '*') {
          pcVar7[3] = pcVar7[4];
        }
        if ((byte)(pcVar7[2] - 0x30U) < 8) {
          cVar2 = pcVar7[3];
          if ((byte)(cVar2 + 0x9fU) < 8) {
            sVar6 = cVar2 + -0x61;
          }
          else {
            sVar6 = 0;
            if (cVar2 != '\0') {
              puVar8 = aBadPartitionNu;
              goto loc_4099280;
            }
          }
          iVar3 = (int)pcVar7[2];
          iVar5 = iVar3 + -0x30;
          goto loc_40993F4;
        }
        puVar8 = aBadMissingUnit;
loc_4099280:
        _printf(puVar8);
        break;
      }
      pauVar1 = *(undefined (**) [50])((int)dword_40B5644 + 10);
      dword_40B5644 = (undefined (**) [50])((int)dword_40B5644 + 10);
    }
    dword_40B5644 = &off_40B2BDE;
    pauVar1 = off_40B2BDE;
    while (pauVar1 != (undefined (*) [50])0x0) {
      if (dword_40B5644 == &off_40B2BDE) {
        puVar4 = &aUse;
      }
      else {
        puVar4 = &aOr;
        if (*(int *)((int)dword_40B5644 + 10) != 0) {
          puVar4 = (undefined5 *)&DAT_40aca03;
        }
      }
      _printf(&aSSD,puVar4,dword_40B5644[1]);
      pauVar1 = *(undefined (**) [50])((int)dword_40B5644 + 10);
      dword_40B5644 = (undefined (**) [50])((int)dword_40B5644 + 10);
    }
    _printf(&asc_40A6049);
    __boothowto = __boothowto | 1;
  } while( true );
}

