
int _initrootnet(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined (**ppauVar5) [50];
  int iStack_28;
  undefined uStack_24;
  undefined uStack_23;
  undefined uStack_22;
  undefined uStack_21;
  undefined2 uStack_14;
  undefined auStack_10 [12];
  
  iStack_28 = 0;
  bVar1 = false;
  if ((_in_ifaddr != 0) && ((*(byte *)(*(int *)(_in_ifaddr + 0x20) + 0xd) & 8) == 0)) {
    return 0;
  }
  ppauVar5 = dword_40B5644;
  if (*(sword *)(dword_40B5644 + 2) != -1) {
    ppauVar5 = &off_40B2BDE;
    if (off_40B2BDE == (undefined (*) [50])0x0) {
      return 0x13;
    }
    do {
      if (*(sword *)(ppauVar5 + 2) == -1) {
        puVar4 = _bus_dinit;
        iVar2 = _bus_dinit._0_4_;
        while ((iVar2 != 0 &&
               (((*(sword *)((int)puVar4 + 0x1a) == 0 || (*(sword *)((int)puVar4 + 4) != 0)) ||
                (*(undefined (**) [50])puVar4 != *dword_40B5644))))) {
          puVar4 = (undefined *)((int)puVar4 + 0x2a);
          iVar2 = *(int *)puVar4;
        }
      }
      ppauVar5 = (undefined (**) [50])((int)ppauVar5 + 10);
    } while (*ppauVar5 != (undefined (*) [50])0x0);
  }
  if (*ppauVar5 == (undefined (*) [50])0x0) {
    return 0x13;
  }
  uStack_24 = (*ppauVar5[1])[0];
  uStack_23 = (*ppauVar5[1])[1];
  uStack_22 = 0x30;
  uStack_21 = 0;
  iVar2 = _socreate(2,&iStack_28,2,0);
  if (iVar2 == 0) {
    uStack_14 = 2;
    while (iVar2 = _ifioctl(iStack_28,0xc0206921,&uStack_24), iVar2 != 0) {
      if (iVar2 != 0x3c) {
        puVar4 = aInitrootnetAut;
        goto loc_4099660;
      }
      if (!bVar1) {
        _printf(aInitrootnetBoo);
        bVar1 = true;
      }
    }
    if (bVar1) {
      _printf(aInitrootnetBoo_0);
    }
    uVar3 = _inet_ntoa(auStack_10);
    _printf(aPrimaryNetwork,&uStack_24,uVar3);
  }
  else {
    puVar4 = aInitrootnetSoc;
loc_4099660:
    _printf(puVar4);
  }
  if (iStack_28 != 0) {
    _soclose(iStack_28);
    return iVar2;
  }
  return iVar2;
}

