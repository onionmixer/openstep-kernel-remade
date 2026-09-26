/* GHIDRADEC_FUNCTION index=2825 start=0x402637e */

undefined4 sub_402637E(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iStack_c;
  int iStack_8;
  
  iVar1 = *(int *)((int)param_1 + 0x2e);
  _getthetime(&iStack_c);
  if ((iStack_c < *(int *)(iVar1 + 0xb6)) ||
     ((*(int *)(iVar1 + 0xb6) == iStack_c && (iStack_8 < *(int *)(iVar1 + 0xba))))) {
    _bcopy(iVar1 + 0x7c,param_2,0x3a);
    *(uint *)(param_2 + 10) = *(uint *)(*(int *)(param_1[9] + 0x126) + 0x26) | 0xff00;
    uVar2 = *(uint *)(*param_1 + 0x14);
    if ((*(uint *)(param_2 + 0x14) < uVar2) &&
       (((*(byte *)(*param_1 + 0x34) & 0x40) != 0 || ((*(byte *)(iVar1 + 0x5f) & 0x10) != 0)))) {
      *(uint *)(param_2 + 0x14) = uVar2;
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2826 start=0x40277c0 */

void sub_40277C0(undefined4 *param_1,int *param_2)

{
  for (; param_1 != (undefined4 *)0x0; param_1 = (undefined4 *)*param_1) {
    *param_2 = param_1[1] + (int)param_1;
    param_2[1] = (int)*(sword *)(param_1 + 2);
    param_2 = param_2 + 2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2827 start=0x4028224 */

undefined4 * sub_4028224(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (_rfssize == 0) {
    iVar3 = 0;
    puVar2 = &_nfs_portmon;
    do {
      puVar1 = (undefined4 *)(_rfsdisptab + iVar3);
      if (puVar1 < puVar2) {
        do {
          if (_rfssize < (int)puVar1[2]) {
            _rfssize = puVar1[2];
          }
          if (_rfssize < (int)puVar1[4]) {
            _rfssize = puVar1[4];
          }
          puVar1 = puVar1 + 6;
        } while (puVar1 < (undefined4 *)((int)&_nfs_portmon + iVar3));
      }
      iVar3 = iVar3 + 0x1b0;
      puVar2 = puVar2 + 0x6c;
    } while ((int)puVar2 < 0x40aedd5);
  }
  if (_rfsfreesp == (undefined4 *)0x0) {
    iVar3 = _kalloc(_rfssize + 4);
    puVar2 = (undefined4 *)(iVar3 + 4);
  }
  else {
    puVar2 = _rfsfreesp;
    _rfsfreesp = (undefined4 *)*_rfsfreesp;
  }
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=2828 start=0x40282c0 */

void sub_40282C0(undefined4 *param_1)

{
  *param_1 = _rfsfreesp;
  _rfsfreesp = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2829 start=0x4028544 */

void sub_4028544(int param_1,int param_2)

{
  _vattr_null(param_2);
  *(undefined2 *)(param_2 + 4) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(param_2 + 6) = *(undefined2 *)(param_1 + 6);
  *(undefined2 *)(param_2 + 8) = *(undefined2 *)(param_1 + 10);
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0x1c);
  return;
}
/* GHIDRADEC_FUNCTION index=2830 start=0x4028598 */

int sub_4028598(int param_1,int param_2)

{
  int iVar1;
  int iStack_8;
  
  if ((((param_2 != 0) && (iVar1 = _getvfs(param_1), iVar1 != 0)) &&
      (iVar1 = (**(code **)(*(int *)(iVar1 + 4) + 0x14))(iVar1,&iStack_8,param_1 + 8), iVar1 == 0))
     && (iStack_8 != 0)) {
    return iStack_8;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2831 start=0x40285e0 */

int sub_40285E0(sword *param_1,sword *param_2)

{
  int iVar1;
  
  if ((*param_1 == *param_2) && (*param_1 == 2)) {
    iVar1 = -(int)-(*(int *)(param_1 + 2) == *(int *)(param_2 + 2));
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2832 start=0x402860e */

undefined4 sub_402860E(undefined4 param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*param_2 != 0) {
    do {
      iVar1 = sub_40285E0(param_1,param_2[1] + uVar2 * 0x10);
      if (iVar1 != 0) {
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *param_2);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2833 start=0x4028652 */

int sub_4028652(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  
  if ((_nfs_portmon == 0) || (*(word *)(*(int *)(param_2 + 0x1c) + 0x10) < 0x400)) {
    iVar2 = *(int *)(param_2 + 0xc);
    if (iVar2 != *(int *)(param_1 + 8)) {
      iVar2 = 0;
    }
    if (iVar2 == 0) {
loc_40286CE:
      *(undefined2 *)(param_3 + 2) = *(undefined2 *)(param_1 + 6);
      *(undefined2 *)(param_3 + 4) = *(undefined2 *)(param_1 + 6);
      puVar4 = (undefined2 *)(param_3 + 10);
    }
    else {
      if (iVar2 != 1) goto loc_4028692;
      iVar2 = *(int *)(param_2 + 0x18);
      if ((*(int *)(iVar2 + 8) == 0) &&
         (iVar3 = sub_402860E(*(int *)(param_2 + 0x1c) + 0xe,param_1 + 0xc), iVar3 == 0))
      goto loc_40286CE;
      *(undefined2 *)(param_3 + 2) = *(undefined2 *)(iVar2 + 10);
      *(undefined2 *)(param_3 + 4) = *(undefined2 *)(iVar2 + 0xe);
      puVar5 = *(undefined4 **)(iVar2 + 0x14);
      for (puVar4 = (undefined2 *)(param_3 + 10);
          puVar4 < (undefined2 *)(param_3 + 10 + *(int *)(iVar2 + 0x10) * 2); puVar4 = puVar4 + 1) {
        *puVar4 = (sword)*puVar5;
        puVar5 = puVar5 + 1;
      }
    }
    for (; puVar4 < (undefined2 *)(param_3 + 0x2a); puVar4 = puVar4 + 1) {
      *puVar4 = 0xffff;
    }
    iVar2 = -(int)-(*(sword *)(param_3 + 2) != -1);
  }
  else {
    uVar1 = _inet_ntoa(*(int *)(param_2 + 0x1c) + 0x12);
    _printf(aNfsRequestFrom,uVar1);
loc_4028692:
    iVar2 = 0;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2834 start=0x402872e */

undefined4 sub_402872E(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(param_1 + 0x5a);
  while ((1 < iVar2 || (uVar3 = _MAXCLIENTS, iVar2 < 0))) {
    _printf(aAuthgetUnknown,iVar2);
    iVar2 = 0;
  }
  do {
    iVar2 = _nextunixvictim * 6;
    _nextunixvictim = (_nextunixvictim + 1) % _MAXCLIENTS;
    if (*(sword *)(_unixauthtab + iVar2) == 0) {
      if (*(int *)(_unixauthtab + iVar2 + 2) == 0) {
        uVar1 = _authkern_create();
        *(undefined4 *)(_unixauthtab + iVar2 + 2) = uVar1;
      }
      *(sword *)(_unixauthtab + iVar2) = 1;
      return *(undefined4 *)(_unixauthtab + iVar2 + 2);
    }
    uVar3 = uVar3 - 1;
  } while (0 < (int)uVar3);
  uVar1 = _authkern_create();
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2835 start=0x40287c4 */

void sub_40287C4(int *param_1)

{
  undefined *puVar1;
  
  if ((*param_1 < 2) && (-1 < *param_1)) {
    for (puVar1 = _unixauthtab; puVar1 < _unixauthtab + _MAXCLIENTS * 6;
        puVar1 = (undefined *)((int)puVar1 + 6)) {
      if (param_1 == *(int **)((int)puVar1 + 2)) {
        *(undefined2 *)puVar1 = 0;
        return;
      }
    }
    (**(code **)(param_1[8] + 0x10))(param_1);
  }
  else {
    _printf(aAuthfreeUnknow,*param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2836 start=0x4028828 */

int * sub_4028828(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined *puVar4;
  int *piVar5;
  
  if ((*(byte *)(param_1 + 0x14) & 0x90) == 0x10) {
    uVar2 = 1;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x2e);
  }
  dword_40BBF18 = dword_40BBF18 + 1;
  piVar5 = &_chtable;
  if (&_chtable < &_chtable + _MAXCLIENTS * 3) {
    puVar4 = unk_40BBED4;
    piVar3 = &unk_40BBED0;
    do {
      if (*piVar3 == 0) {
        *piVar3 = 1;
        if (*(int *)puVar4 == 0) {
          iVar1 = _clntkudp_create(param_1,0x186a3,2,uVar2,param_2);
          *(int *)puVar4 = iVar1;
          if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(aClgetNullClien);
          }
          (**(code **)(*(int *)(**(int **)puVar4 + 0x20) + 0x10))(**(int **)puVar4);
        }
        else {
          _clntkudp_init(*(int *)puVar4,param_1,uVar2,param_2);
        }
        uVar2 = sub_402872E(param_1,param_2);
        **(undefined4 **)puVar4 = uVar2;
        if (**(int **)puVar4 != 0) {
          *piVar5 = *piVar5 + 1;
          if ((*(byte *)(param_1 + 0x14) & 0xa0) == 0xa0) {
            _clntkudp_interruptable(*(int *)puVar4,1);
          }
          return *(int **)puVar4;
        }
                    /* WARNING: Subroutine does not return */
        _panic(aClgetNullAuth);
      }
      puVar4 = (undefined *)((int)puVar4 + 0xc);
      piVar3 = piVar3 + 3;
      piVar5 = piVar5 + 3;
    } while (piVar5 < &_chtable + _MAXCLIENTS * 3);
  }
  _cltoomany = _cltoomany + 1;
  piVar5 = (int *)_clntkudp_create(param_1,0x186a3,2,uVar2,param_2);
  if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aClgetNullClien);
  }
  (**(code **)(*(int *)(*piVar5 + 0x20) + 0x10))(*piVar5);
  iVar1 = sub_402872E(param_1,param_2);
  *piVar5 = iVar1;
  if (iVar1 != 0) {
    if ((*(byte *)(param_1 + 0x14) & 0xa0) == 0xa0) {
      _clntkudp_interruptable(piVar5,1);
    }
    return piVar5;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aClgetNullAuth);
}
/* GHIDRADEC_FUNCTION index=2837 start=0x4028a8c */

void sub_4028A8C(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  sub_40287C4(*param_1);
  _clntkudp_freecred(param_1);
  *param_1 = 0;
  puVar1 = &_chtable;
  while( true ) {
    if (&_chtable + _MAXCLIENTS * 3 <= puVar1) {
      (**(code **)(param_1[1] + 0x10))(param_1);
      return;
    }
    if (param_1 == (undefined4 *)puVar1[2]) break;
    puVar1 = puVar1 + 3;
  }
  puVar1[1] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2838 start=0x4029110 */

void sub_4029110(int param_1)

{
  *(undefined4 *)(param_1 + 8) =
       *(undefined4 *)
        (_rtable +
        ((byte)(*(byte *)(param_1 + 0x59) ^
               *(byte *)(param_1 + 0x58) ^
               *(byte *)(param_1 + 0x57) ^
               *(byte *)(param_1 + 0x56) ^
               *(byte *)(param_1 + 0x55) ^
               *(byte *)(param_1 + 0x54) ^
               *(byte *)(param_1 + 0x53) ^
               *(byte *)(param_1 + 0x52) ^
               *(byte *)(param_1 + 0x4f) ^
               *(byte *)(param_1 + 0x4e) ^
               *(byte *)(param_1 + 0x4d) ^
               *(byte *)(param_1 + 0x4c) ^
               *(byte *)(param_1 + 0x4b) ^
               *(byte *)(param_1 + 0x4a) ^ *(byte *)(param_1 + 0x49) ^ *(byte *)(param_1 + 0x48)) &
        0x3f) * 4);
  *(int *)(_rtable +
          ((byte)(*(byte *)(param_1 + 0x59) ^
                 *(byte *)(param_1 + 0x58) ^
                 *(byte *)(param_1 + 0x57) ^
                 *(byte *)(param_1 + 0x56) ^
                 *(byte *)(param_1 + 0x55) ^
                 *(byte *)(param_1 + 0x54) ^
                 *(byte *)(param_1 + 0x53) ^
                 *(byte *)(param_1 + 0x52) ^
                 *(byte *)(param_1 + 0x4f) ^
                 *(byte *)(param_1 + 0x4e) ^
                 *(byte *)(param_1 + 0x4d) ^
                 *(byte *)(param_1 + 0x4c) ^
                 *(byte *)(param_1 + 0x4b) ^
                 *(byte *)(param_1 + 0x4a) ^ *(byte *)(param_1 + 0x49) ^ *(byte *)(param_1 + 0x48))
          & 0x3f) * 4) = param_1;
  _rnhash = _rnhash + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=2839 start=0x402930e */

void sub_402930E(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = _rpfreelist;
  if (*param_1 != 0) {
    return;
  }
  if (_rpfreelist == (int *)0x0) {
    *param_1 = (int)param_1;
    param_1[1] = (int)param_1;
  }
  else {
    *param_1 = (int)_rpfreelist;
    param_1[1] = piVar1[1];
    *(int **)piVar1[1] = param_1;
    piVar1[1] = (int)param_1;
    if (param_2 == 0) goto loc_402934C;
  }
  _rpfreelist = param_1;
loc_402934C:
  _rnfree = _rnfree + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=2840 start=0x402935a */

void sub_402935A(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    if (param_1 == piVar1) {
      _rpfreelist = (int *)0x0;
    }
    else {
      if (param_1 == _rpfreelist) {
        _rpfreelist = piVar1;
      }
      *(int *)param_1[1] = *param_1;
      *(int *)(*param_1 + 4) = param_1[1];
    }
    param_1[1] = 0;
    *param_1 = 0;
    _rnfree = _rnfree + -1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2841 start=0x40293f4 */

int sub_40293F4(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  sword sVar3;
  int iVar4;
  
  iVar2 = *(int *)(_rtable +
                  ((byte)(*(byte *)(param_1 + 0x1b) ^
                         *(byte *)(param_1 + 0x1a) ^
                         *(byte *)(param_1 + 0x19) ^
                         *(byte *)(param_1 + 0x18) ^
                         *(byte *)(param_1 + 0x17) ^
                         *(byte *)(param_1 + 0x16) ^
                         *(byte *)(param_1 + 0x15) ^
                         *(byte *)(param_1 + 0x14) ^
                         *(byte *)(param_1 + 0x11) ^
                         *(byte *)(param_1 + 0x10) ^
                         *(byte *)(param_1 + 0xf) ^
                         *(byte *)(param_1 + 0xe) ^
                         *(byte *)(param_1 + 0xd) ^
                         *(byte *)(param_1 + 0xc) ^
                         *(byte *)(param_1 + 0xb) ^ *(byte *)(param_1 + 10)) & 0x3f) * 4);
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar4 = _bcmp(iVar2 + 0x3e,param_1,0x20);
    if ((iVar4 == 0) && (param_2 == *(int *)(iVar2 + 0x30))) break;
    iVar2 = *(int *)(iVar2 + 8);
  }
  sVar3 = *(sword *)(iVar2 + 0x12);
  *(sword *)(iVar2 + 0x12) = sVar3 + 1;
  if (sVar3 == 0) {
    sub_402935A(iVar2);
    piVar1 = (int *)(*(int *)(*(int *)(iVar2 + 0x30) + 0x126) + 0x16);
    *piVar1 = *piVar1 + 1;
    _rreactive = _rreactive + 1;
  }
  else {
    _ractive = _ractive + 1;
  }
  sub_402935A(iVar2);
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2842 start=0x40296f8 */

void sub_40296F8(int param_1)

{
  _rlock_awaken_count = _rlock_awaken_count + 1;
  if (param_1 != 0) {
    _wakeup(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2843 start=0x40297da */

int * sub_40297DA(int param_1,int *param_2,int *param_3)

{
  sword *psVar1;
  byte *pbVar2;
  bool bVar3;
  int *piVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  undefined *puVar9;
  int **ppiVar10;
  int *piStack_18c;
  int iStack_16a;
  int iStack_166;
  char acStack_162 [32];
  int iStack_142;
  int *piStack_13e;
  int aiStack_136 [8];
  undefined auStack_116 [258];
  undefined auStack_14 [16];
  
  piStack_18c = param_3;
  _getfsname(&aRoot);
  _pn_alloc(&iStack_142);
  piVar7 = piStack_13e;
  bVar3 = false;
  ppiVar10 = (int **)&stack0xfffffe78;
  while( true ) {
    piStack_18c = piVar7;
    piVar4 = (int *)&aRoot;
    if (*(char *)param_3 != '\0') {
      piVar4 = param_3;
    }
    piVar4 = (int *)sub_402A078(piVar4,auStack_116,auStack_14);
    if (piVar4 != (int *)0x3c) break;
    if (!bVar3) {
      piStack_18c = (int *)&aRoot;
      if (*(char *)param_3 != '\0') {
        piStack_18c = param_3;
      }
      _printf(off_40AEE7A);
      bVar3 = true;
    }
  }
  if (piVar4 == (int *)0x0) {
    if (bVar3) {
      piStack_18c = (int *)aBootparamRespo;
      _printf();
    }
    piStack_18c = aiStack_136;
    piVar4 = (int *)sub_402A1E8(auStack_14,auStack_116,piVar7);
    if (piVar4 == (int *)0x0) {
      piStack_18c = (int *)0x0;
      piVar4 = (int *)sub_402A56C(&iStack_166,param_1,auStack_14,aiStack_136,auStack_116,0,
                                  0xffffffff);
      if (piVar4 == (int *)0x0) {
        piStack_18c = (int *)0x0;
        piVar4 = (int *)_vfs_add(0,param_1);
        if (piVar4 == (int *)0x0) {
          *(undefined4 *)(*(int *)(param_1 + 0x126) + 0x5e) = 0xe10;
          *(undefined4 *)(*(int *)(param_1 + 0x126) + 0x62) = 36000;
          *(undefined4 *)(*(int *)(param_1 + 0x126) + 0x66) = 0xe10;
          *(undefined4 *)(*(int *)(param_1 + 0x126) + 0x6a) = 36000;
          pbVar2 = (byte *)(*(int *)(param_1 + 0x126) + 0x14);
          *pbVar2 = *pbVar2 | 4;
          piStack_18c = *(int **)(iStack_166 + 0x24);
          _vfs_unlock();
          *param_2 = iStack_166;
          puVar5 = (undefined *)_strcpy(param_3,auStack_116);
          *puVar5 = 0x3a;
          _strcpy(puVar5 + 1,piVar7);
          acStack_162[0] = '\0';
          _getfsname(&aPrivate,acStack_162);
          bVar3 = false;
          while( true ) {
            piStack_18c = piVar7;
            pcVar8 = "private";
            if (acStack_162[0] != '\0') {
              pcVar8 = acStack_162;
            }
            piVar4 = (int *)sub_402A078(pcVar8,auStack_116,auStack_14);
            if (piVar4 != (int *)0x3c) break;
            if (!bVar3) {
              piStack_18c = (int *)&aPrivate;
              if (acStack_162[0] != '\0') {
                piStack_18c = (int *)acStack_162;
              }
              _printf(off_40AEE7A);
              bVar3 = true;
            }
          }
          if (piVar4 == (int *)0x0) {
            if (bVar3) {
              piStack_18c = (int *)aBootparamRespo;
              _printf();
            }
            piStack_18c = (int *)0x40;
            puVar5 = (undefined *)_index(piVar7);
            if (puVar5 == (undefined *)0x0) {
              puVar9 = aPrivate_0;
            }
            else {
              puVar9 = puVar5 + 1;
              *puVar5 = 0;
            }
            piStack_18c = aiStack_136;
            piVar4 = (int *)sub_402A1E8(auStack_14,auStack_116,piVar7);
            if (piVar4 == (int *)0x0) {
              piStack_18c = &_rootdir;
              iVar6 = (**(code **)(*(int *)(_rootvfs + 4) + 8))(_rootvfs);
              if (iVar6 != 0) {
                piStack_18c = (int *)aNfsMountrootCa;
                    /* WARNING: Subroutine does not return */
                _panic();
              }
              *(undefined4 *)(_active_u + 0x156) = _rootdir;
              psVar1 = (sword *)(*(int *)(_active_u + 0x156) + 6);
              *psVar1 = *psVar1 + 1;
              *(undefined4 *)(_active_u + 0x15a) = 0;
              piStack_18c = &iStack_16a;
              piVar4 = (int *)_lookupname(puVar9,1,1,0);
              if ((piVar4 == (int *)0x0) && (iStack_16a != 0)) {
                piStack_18c = *(int **)(_active_u + 0x156);
                _vn_rele();
                _vn_rele(_rootdir);
                _dnlc_purge();
                piVar7 = (int *)_kalloc(0x12a);
                *piVar7 = 0;
                piVar7[1] = (int)_nfs_vfsops;
                piVar7[3] = 0;
                piVar7[7] = 0;
                *(undefined4 *)((int)piVar7 + 0x126) = 0;
                piVar7[0x48] = 0;
                *(undefined2 *)(piVar7 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 2);
                piVar4 = (int *)sub_402A56C(&iStack_166,piVar7,auStack_14,aiStack_136,auStack_116,0,
                                            0xffffffff,0);
                if (piVar4 == (int *)0x0) {
                  piStack_18c = (int *)0x0;
                  piVar4 = (int *)_vfs_add(iStack_16a,piVar7);
                  if (piVar4 == (int *)0x0) {
                    *(undefined4 *)(*(int *)(param_1 + 0x126) + 0x62) = 6000;
                    *(undefined4 *)(*(int *)(param_1 + 0x126) + 0x6a) = 6000;
                    piStack_18c = (int *)0xff;
                    _strncpy(param_1 + 0x20,piStack_13e);
                    _vfs_unlock(*(undefined4 *)(iStack_166 + 0x24));
                    _nfs_netboot_prealloc(*(undefined4 *)(param_1 + 0x126));
                    _pn_free(&iStack_142);
                    return (int *)0;
                  }
                  ppiVar10 = &piStack_18c;
                  piStack_18c = piVar7;
                  sub_402A788();
                }
                *(int **)((int)ppiVar10 + -4) = &iStack_142;
                *(undefined4 *)((int)ppiVar10 + -8) = 0x4029c5c;
                _pn_free();
                *(undefined4 *)((int)ppiVar10 + -8) = 0x12a;
                *(int **)((int)ppiVar10 + -0xc) = piVar7;
                *(undefined4 *)((int)ppiVar10 + -0x10) = 0x4029c68;
                _kfree();
              }
              else {
                piStack_18c = (int *)aNfsMountrootNo;
                _printf();
                _vn_rele(*(undefined4 *)(_active_u + 0x156));
                _pn_free(&iStack_142);
              }
            }
            else {
              piStack_18c = &iStack_142;
              _pn_free();
              _printf(aMountPrivateSS,auStack_116,piVar7,piVar4);
            }
          }
          else {
            if (piVar4 == (int *)0x16) {
              piStack_18c = (int *)aUsingPrivateFr;
              _printf();
              piVar4 = (int *)0x0;
            }
            else {
              piStack_18c = piVar4;
              _printf(aRpcErrorDuring);
            }
            piStack_18c = &iStack_142;
            _pn_free();
          }
        }
        else {
          piStack_18c = &iStack_142;
          _pn_free();
        }
      }
      else {
        piStack_18c = &iStack_142;
        _pn_free();
      }
    }
    else {
      piStack_18c = &iStack_142;
      _pn_free();
      _printf(aMountRootSSFai,auStack_116,piVar7,piVar4);
    }
  }
  else {
    piStack_18c = piVar4;
    _printf(aRpcErrorDuring);
    _pn_free(&iStack_142);
  }
  return piVar4;
}
/* GHIDRADEC_FUNCTION index=2844 start=0x4029c74 */

undefined4
sub_4029C74(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
           undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
           undefined4 param_10,int param_11)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_30 [2];
  undefined2 uStack_2e;
  undefined *apuStack_2c [2];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  *(undefined2 *)(param_1 + 2) = 0x6f;
  iVar1 = _clntkudp_create(param_1,100000,2,5,*(undefined4 *)(_active_u + 0x1a));
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aPmapRmtcallCln);
  }
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  uStack_c = param_6;
  uStack_8 = param_5;
  apuStack_2c[0] = auStack_30;
  uStack_24 = param_8;
  uStack_20 = param_7;
  uVar2 = _clntkudp_callit_addr
                    (iVar1,5,_xdr_rmtcall_args,&uStack_1c,_xdr_rmtcallres,apuStack_2c,param_9,
                     param_10,param_11);
  if (param_11 != 0) {
    *(undefined2 *)(param_11 + 2) = uStack_2e;
  }
  (**(code **)(*(int *)(iVar1 + 4) + 0x10))(iVar1);
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2845 start=0x4029d46 */

int sub_4029D46(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uStack_50;
  undefined auStack_4c [16];
  undefined auStack_3c [4];
  undefined4 uStack_38;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_1c;
  undefined auStack_18 [4];
  undefined auStack_14 [16];
  
  if (dword_40AEE7E != 0) {
    return 0;
  }
  dword_40AEE7E = 1;
  _bzero(auStack_14,0x10);
  iVar2 = _ifb_ifwithaf(2);
  if (iVar2 == 0) {
    _printf(aWhoamiZeroIfp);
    return 0x41;
  }
  iVar3 = _initrootnet();
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aWhoamiInitroot);
  }
  iVar3 = _in_control(0,0xc0206912,auStack_4c,iVar2);
  if (iVar3 != 0) {
    _printf(aWhoamiInContro,iVar3,(int)*(sword *)(iVar2 + 0xc));
                    /* WARNING: Subroutine does not return */
    _panic(aBadSiocgifbrda);
  }
  _bcopy(auStack_3c,auStack_14,0x10);
  _bcopy(auStack_3c,unk_40B3554,0x10);
  uStack_1c = 1;
  iVar2 = _in_control(0,0xc020690d,auStack_4c,iVar2);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aBadSiocgifaddr);
  }
  uStack_50 = uStack_38;
  _bcopy(&uStack_50,auStack_18,4);
  uVar4 = 3;
  uStack_2c = _kalloc(0x100);
  uStack_28 = _kalloc(0x100);
  bVar1 = false;
  do {
    iVar2 = sub_4029C74(auStack_14,0x186ba,1,1,_xdr_bp_whoami_arg,&uStack_1c,_xdr_bp_whoami_res,
                        &uStack_2c,uVar4,0,0);
    if ((iVar2 == 5) && (!bVar1)) {
      _printf(aNoBootparamSer_0);
      _printf(aWhoamiPmapRmtc,5);
      bVar1 = true;
    }
    uVar4 = 0x14;
  } while (iVar2 == 5);
  if (bVar1) {
    _printf(aBootparamRespo);
  }
  if (iVar2 != 0) {
    _printf(aWhoamiRpcCallF,iVar2);
    goto loc_4029FCA;
  }
  _hostnamelen = _strlen(uStack_2c);
  if (_hostnamelen < 0x101) {
    if ((int)_hostnamelen < 1) {
      _printf(aWhoamiNoHostNa);
      iVar2 = 6;
      goto loc_4029FCA;
    }
    _bcopy(uStack_2c,_hostname,_hostnamelen);
    _printf(aHostnameS,_hostname);
    _domainnamelen = _strlen(uStack_28);
    if (_domainnamelen < 0x101) {
      iVar2 = 0;
      if (0 < (int)_domainnamelen) {
        _bcopy(uStack_28,_domainname,_domainnamelen);
        _printf(aDomainnameS,_domainname);
      }
      goto loc_4029FCA;
    }
    _printf(aWhoamiDomainna);
  }
  else {
    _printf(aWhoamiHostname);
  }
  iVar2 = 0x3f;
loc_4029FCA:
  _kfree(uStack_2c,0x100);
  _kfree(uStack_28,0x100);
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2846 start=0x4029ff0 */

undefined4
sub_4029FF0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)_clntkudp_create(param_1,param_2,param_3,5,*(undefined4 *)(_active_u + 0x1a));
  uVar2 = (**(code **)piVar1[1])(piVar1,param_4,param_5,param_6,param_7,param_8,3,0);
  (**(code **)(*(int *)(*piVar1 + 0x20) + 0x10))(*piVar1);
  (**(code **)(piVar1[1] + 0x10))(piVar1);
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2847 start=0x402a078 */

int sub_402A078(undefined4 param_1,char *param_2,undefined2 *param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  int iStack_20;
  undefined *puStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined auStack_c [4];
  undefined4 uStack_8;
  
  puStack_1c = _hostname;
  uStack_18 = param_1;
  _bzero(&uStack_14,0x10);
  iVar1 = sub_4029D46();
  if (iVar1 == 0) {
    uStack_14 = _kalloc(0x100);
    uStack_8 = _kalloc(0x100);
    iVar1 = 0;
    do {
      iVar2 = sub_4029C74(unk_40B3554,0x186ba,1,2,_xdr_bp_getfile_arg,&puStack_1c,
                          _xdr_bp_getfile_res,&uStack_14,5,0,0);
      if (iVar2 != 5) break;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 5);
    if (iVar2 == 0) {
      _strcpy(param_2,uStack_14);
      _strcpy(param_4,uStack_8);
    }
    _kfree(uStack_14,0x100);
    _kfree(uStack_8,0x100);
    if (iVar2 == 0) {
      _bcopy(auStack_c,&iStack_20,4);
      if (((*param_2 == '\0') || (*param_4 == '\0')) || (iStack_20 == 0)) {
        iVar1 = 0x16;
      }
      else if (iStack_10 == 1) {
        _bzero(param_3,0x10);
        *param_3 = 2;
        *(int *)(param_3 + 2) = iStack_20;
        _printf(aNfsMountingSFr,param_1,param_2,param_4);
        iVar1 = 0;
      }
      else {
        _printf(aGetfileUnknown,iStack_10);
        iVar1 = 0x2b;
      }
    }
    else {
      iVar1 = 0x3c;
      if (iVar2 != 5) {
        iVar1 = iVar2;
      }
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2848 start=0x402a1e8 */

int sub_402A1E8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = param_4;
  while( true ) {
    iVar2 = _pmap_kgetport(param_1,0x186a5,1,0x11);
    if (iVar2 == -1) {
      return 0xf;
    }
    if (iVar2 != 1) break;
    _printf(aMountnfsSSPort,param_2,param_3);
  }
  while (iVar2 = sub_4029FF0(param_1,0x186a5,1,1,_xdr_bp_path_t,&param_3,_xdr_fhstatus,&iStack_28),
        iVar2 == 5) {
    _printf(aMountnfsSSMoun,param_2,param_3);
  }
  if (iVar2 != 0) {
    return iVar2;
  }
  *(undefined2 *)(param_1 + 2) = 0x801;
  *puVar1 = uStack_24;
  puVar1[1] = uStack_20;
  puVar1[2] = uStack_1c;
  puVar1[3] = uStack_18;
  puVar1[4] = uStack_14;
  puVar1[5] = uStack_10;
  puVar1[6] = uStack_c;
  puVar1[7] = uStack_8;
  return iStack_28;
}
/* GHIDRADEC_FUNCTION index=2849 start=0x402a2c6 */

int sub_402A2C6(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined *puVar7;
  int iStack_194;
  undefined4 uStack_190;
  undefined auStack_18c [4];
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined2 uStack_180;
  byte bStack_17e;
  byte bStack_17d;
  undefined2 uStack_17c;
  undefined uStack_17a;
  undefined uStack_179;
  int iStack_178;
  int iStack_174;
  int iStack_170;
  undefined4 uStack_16c;
  int iStack_168;
  uint uStack_164;
  int iStack_160;
  uint uStack_15c;
  undefined4 uStack_158;
  undefined auStack_154 [256];
  undefined auStack_54 [32];
  sword asStack_34 [8];
  undefined auStack_24 [32];
  
  iStack_194 = 0;
  if ((*(byte *)(param_1 + 0xf) & 0x40) != 0) {
    return 0;
  }
  iVar4 = _copyinmsg(param_3,&uStack_188,0x34);
  if (iVar4 != 0) goto loc_402A552;
  iVar4 = _copyinmsg(uStack_188,asStack_34,0x10);
  if (iVar4 != 0) goto loc_402A552;
  if (asStack_34[0] != 2) {
    iVar4 = 0x2e;
    goto loc_402A552;
  }
  iVar4 = _copyinmsg(uStack_184,auStack_24,0x20);
  if (iVar4 != 0) goto loc_402A552;
  if ((bStack_17d & 0x20) == 0) {
    sub_402A990(asStack_34,auStack_54);
  }
  else {
    iVar4 = _copyinstr(uStack_16c,auStack_54,0x20,auStack_18c);
    if (iVar4 != 0) goto loc_402A552;
  }
  if ((bStack_17e & 0x10) == 0) {
    uStack_190 = 0xffffffff;
  }
  else {
    _copyinstr(uStack_158,auStack_154,0x100,&uStack_190);
  }
  iVar4 = sub_402A56C(&iStack_194,param_1,asStack_34,auStack_24,auStack_54,auStack_154,uStack_190,
                      CONCAT31(CONCAT21(uStack_180,bStack_17e),bStack_17d));
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar1 = *(int *)(*(int *)(iStack_194 + 0x24) + 0x126);
  bVar2 = *(byte *)(iVar1 + 0x14);
  bVar3 = (bStack_17d >> 7) << 3;
  *(byte *)(iVar1 + 0x14) = bVar2 & 0xf7 | bVar3;
  *(byte *)(iVar1 + 0x14) =
       bVar2 & 0xf3 | bVar3 |
       (byte)(((CONCAT22(CONCAT11(bStack_17e,bStack_17d),uStack_17c) & 0x3fffffff) >> 0x1d) << 2);
  if ((((bStack_17d & 0x10) != 0) && (*(int *)(iVar1 + 0x2e) = iStack_170, iStack_170 < 0)) ||
     (((bStack_17d & 8) != 0 && (*(int *)(iVar1 + 0x2a) = iStack_174, iStack_174 < 1)))) {
loc_402A448:
    iVar4 = 0x16;
    goto loc_402A552;
  }
  if ((bStack_17d & 4) != 0) {
    if (iStack_178 < 1) goto loc_402A448;
    iVar4 = *(int *)(iVar1 + 0x1a);
    if (iStack_178 < *(int *)(iVar1 + 0x1a)) {
      iVar4 = iStack_178;
    }
    *(int *)(iVar1 + 0x1a) = iVar4;
  }
  if ((bStack_17d & 2) != 0) {
    iVar4 = CONCAT31(CONCAT21(uStack_17c,uStack_17a),uStack_179);
    if (iVar4 < 1) goto loc_402A448;
    iVar5 = *(int *)(iVar1 + 0x1e);
    if (iVar4 < *(int *)(iVar1 + 0x1e)) {
      iVar5 = iVar4;
    }
    *(int *)(iVar1 + 0x1e) = iVar5;
  }
  if ((bStack_17e & 1) == 0) {
loc_402A496:
    if ((bStack_17e & 2) != 0) {
      if ((int)uStack_164 < 0) {
        *(undefined4 *)(iVar1 + 0x62) = 36000;
      }
      else {
        if (uStack_164 < *(uint *)(iVar1 + 0x5e)) {
          puVar7 = aNfsMountAcregm_0;
          goto loc_402A530;
        }
        uVar6 = _min(uStack_164,36000);
        *(undefined4 *)(iVar1 + 0x62) = uVar6;
      }
    }
    if ((bStack_17e & 4) != 0) {
      if (iStack_160 < 0) {
        *(undefined4 *)(iVar1 + 0x66) = 0xe10;
      }
      else {
        if (iStack_160 == 0) {
          puVar7 = aNfsMountAcdirm;
          goto loc_402A530;
        }
        uVar6 = _min(iStack_160,0xe10);
        *(undefined4 *)(iVar1 + 0x66) = uVar6;
      }
    }
    iVar4 = 0;
    if ((bStack_17e & 8) != 0) {
      if ((int)uStack_15c < 0) {
        *(undefined4 *)(iVar1 + 0x6a) = 36000;
      }
      else {
        if (uStack_15c < *(uint *)(iVar1 + 0x66)) {
          puVar7 = aNfsMountAcdirm_0;
          goto loc_402A530;
        }
        uVar6 = _min(uStack_15c,36000);
        *(undefined4 *)(iVar1 + 0x6a) = uVar6;
      }
    }
  }
  else {
    if (iStack_168 < 0) {
      *(undefined4 *)(iVar1 + 0x5e) = 0xe10;
      goto loc_402A496;
    }
    if (iStack_168 != 0) {
      uVar6 = _min(iStack_168,0xe10);
      *(undefined4 *)(iVar1 + 0x5e) = uVar6;
      goto loc_402A496;
    }
    puVar7 = aNfsMountAcregm;
loc_402A530:
    iVar4 = 0x16;
    _printf(puVar7);
  }
  if (iVar4 == 0) {
    return 0;
  }
loc_402A552:
  if (iStack_194 != 0) {
    _vn_rele(iStack_194);
  }
  return iVar4;
}

