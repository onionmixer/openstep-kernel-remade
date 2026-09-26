/* GHIDRADEC_FUNCTION index=800 start=0x4026734 */

uint _exportfs(void)

{
  undefined4 *puVar1;
  word wVar2;
  int iVar3;
  uint uVar4;
  undefined uVar6;
  uint *puVar5;
  int *piVar7;
  word *pwStack_c;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar3 = _suser();
  if (iVar3 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 1;
    return 0;
  }
  uVar4 = _lookupname(*puVar1,0,1,0,&iStack_8);
  *(char *)(dword_40B57D4 + 100) = (char)uVar4;
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return uVar4;
  }
  uVar6 = (**(code **)(*(int *)(iStack_8 + 0x1c) + 100))(iStack_8,&pwStack_c);
  *(undefined *)(dword_40B57D4 + 100) = uVar6;
  iVar3 = *(int *)(iStack_8 + 0x24);
  uVar4 = _vn_rele(iStack_8);
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return uVar4;
  }
  if (puVar1[1] == 0) {
    uVar6 = _unexport(iVar3 + 0x14,pwStack_c);
    *(undefined *)(dword_40B57D4 + 100) = uVar6;
    uVar4 = _kfree(pwStack_c,*pwStack_c + 2);
    return uVar4;
  }
  puVar5 = (uint *)_kalloc(0x30);
  puVar5[8] = *(uint *)(iVar3 + 0x14);
  puVar5[9] = *(uint *)(iVar3 + 0x18);
  puVar5[10] = (uint)pwStack_c;
  uVar6 = _copyinmsg(puVar1[1],puVar5,0x20);
  *(undefined *)(dword_40B57D4 + 100) = uVar6;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    if ((*puVar5 & 0xfffffffc) == 0) {
      uVar4 = 0;
      if ((*puVar5 & 2) != 0) {
        uVar4 = _loadaddrs(puVar5 + 6);
        *(char *)(dword_40B57D4 + 100) = (char)uVar4;
        if (*(char *)(dword_40B57D4 + 100) != '\0') goto loc_4026938;
      }
      if (puVar5[2] == 1) {
        uVar4 = _loadaddrs(puVar5 + 3);
        *(char *)(dword_40B57D4 + 100) = (char)uVar4;
      }
      else {
        *(undefined *)(dword_40B57D4 + 100) = 0x16;
      }
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        piVar7 = &_exported;
        iVar3 = _exported;
        do {
          if (iVar3 == 0) {
            puVar5[0xb] = 0;
            *piVar7 = (int)puVar5;
            return uVar4;
          }
          uVar4 = _bcmp(*piVar7 + 0x20,puVar5 + 8,8);
          if (uVar4 == 0) {
            wVar2 = **(word **)(*piVar7 + 0x28);
            uVar4 = (uint)wVar2;
            if ((wVar2 != *(word *)puVar5[10]) ||
               (uVar4 = _bcmp(*(word **)(*piVar7 + 0x28) + 1,(word *)puVar5[10] + 1,wVar2),
               uVar4 != 0)) goto loc_4026926;
            iVar3 = *piVar7;
            *piVar7 = *(int *)(iVar3 + 0x2c);
            uVar4 = _exportfree(iVar3);
          }
          else {
loc_4026926:
            piVar7 = (int *)(*piVar7 + 0x2c);
          }
          iVar3 = *piVar7;
        } while( true );
      }
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
loc_4026938:
  _kfree((word *)puVar5[10],*(word *)puVar5[10] + 2);
  uVar4 = _kfree(puVar5,0x30);
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=801 start=0x4026962 */

undefined4 _unexport(undefined4 param_1,sword *param_2)

{
  sword sVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = &_exported;
  iVar2 = _exported;
  do {
    if (iVar2 == 0) {
      return 0x16;
    }
    iVar2 = _bcmp(*piVar3 + 0x20,param_1,8);
    if (iVar2 == 0) {
      sVar1 = **(sword **)(*piVar3 + 0x28);
      if ((sVar1 == *param_2) &&
         (iVar2 = _bcmp(*(sword **)(*piVar3 + 0x28) + 1,param_2 + 1,sVar1), iVar2 == 0)) {
        iVar2 = *piVar3;
        *piVar3 = *(int *)(iVar2 + 0x2c);
        _exportfree(iVar2);
        return 0;
      }
    }
    piVar3 = (int *)(*piVar3 + 0x2c);
    iVar2 = *piVar3;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=802 start=0x40269e4 */

void _nfs_getfh(void)

{
  uint uVar1;
  uint *puVar2;
  bool bVar3;
  int iVar4;
  undefined uVar5;
  undefined4 uStack_30;
  int iStack_2c;
  int iStack_28;
  undefined auStack_24 [32];
  
  puVar2 = *(uint **)(dword_40B57D4 + 0x24);
  bVar3 = false;
  iVar4 = _suser();
  if (iVar4 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 1;
    return;
  }
  uVar1 = *puVar2;
  if (uVar1 < 0x100) {
    bVar3 = true;
    iVar4 = _getf(uVar1);
    if ((iVar4 == 0) || (*(undefined **)(iVar4 + 0x12) != _vnodefops)) {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
      return;
    }
    iStack_2c = *(int *)(iVar4 + 0x16);
    iStack_28 = 0;
  }
  else {
    uVar5 = _lookupname(uVar1,0,1,&iStack_28,&iStack_2c);
    *(undefined *)(dword_40B57D4 + 100) = uVar5;
    if (*(char *)(dword_40B57D4 + 100) == '\x11') {
      uVar5 = _lookupname(*puVar2,0,1,0,&iStack_2c);
      *(undefined *)(dword_40B57D4 + 100) = uVar5;
      iStack_28 = 0;
    }
    if (*(char *)(dword_40B57D4 + 100) != '\0') {
      return;
    }
    if (iStack_2c == 0) {
      if (iStack_28 != 0) {
        _vn_rele(iStack_28);
      }
      *(undefined *)(dword_40B57D4 + 100) = 2;
    }
    if (*(char *)(dword_40B57D4 + 100) != '\0') {
      return;
    }
  }
  iVar4 = _findexivp(&uStack_30,iStack_28,iStack_2c);
  if (iVar4 == 0) {
    iVar4 = _makefh(auStack_24,iStack_2c,uStack_30);
    if (iVar4 == 0) {
      iVar4 = _copyoutmsg(auStack_24,puVar2[1],0x20);
    }
  }
  if ((!bVar3) && (_vn_rele(iStack_2c), iStack_28 != 0)) {
    _vn_rele(iStack_28);
  }
  *(char *)(dword_40B57D4 + 100) = (char)iVar4;
  return;
}
/* GHIDRADEC_FUNCTION index=803 start=0x4026b64 */

int _findexivp(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  word *pwStack_8;
  
  *(sword *)(param_3 + 6) = *(sword *)(param_3 + 6) + 1;
  iVar3 = param_3;
  if (param_2 != 0) {
    *(sword *)(param_2 + 6) = *(sword *)(param_2 + 6) + 1;
  }
  do {
    iVar1 = (**(code **)(*(int *)(iVar3 + 0x1c) + 100))(iVar3,&pwStack_8);
    if (iVar1 != 0) {
loc_4026C22:
      _vn_rele(iVar3);
      if (param_2 != 0) {
        _vn_rele(param_2);
      }
      return iVar1;
    }
    iVar2 = _findexport(*(int *)(iVar3 + 0x24) + 0x14,pwStack_8);
    *param_1 = iVar2;
    _kfree(pwStack_8,*pwStack_8 + 2);
    if (*param_1 != 0) goto loc_4026C22;
    if ((*(byte *)(iVar3 + 5) & 1) != 0) {
      iVar1 = 0x16;
      goto loc_4026C22;
    }
    if (param_2 == 0) {
      iVar1 = (**(code **)(*(int *)(iVar3 + 0x1c) + 0x20))
                        (iVar3,&asc_40A6712,&param_2,*(undefined4 *)(_active_u + 0x1a),0,0);
      if (iVar1 != 0) goto loc_4026C22;
    }
    _vn_rele(iVar3);
    iVar3 = param_2;
    param_2 = 0;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=804 start=0x4026c44 */

undefined4 _makefh(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  word *pwStack_8;
  
  iVar1 = (**(code **)(*(int *)(param_2 + 0x1c) + 100))(param_2,&pwStack_8);
  if ((iVar1 == 0) && (pwStack_8 != (word *)0x0)) {
    if (*pwStack_8 + 8 + (uint)**(word **)(param_3 + 0x28) < 0x21) {
      _bzero(param_1,0x20);
      *param_1 = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x14);
      param_1[1] = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x18);
      *(word *)(param_1 + 2) = *pwStack_8;
      _bcopy(pwStack_8 + 1,(int)param_1 + 10,*pwStack_8);
      *(undefined2 *)(param_1 + 5) = **(undefined2 **)(param_3 + 0x28);
      _bcopy(*(int *)(param_3 + 0x28) + 2,(int)param_1 + 0x16,*(undefined2 *)(param_1 + 5));
      _kfree(pwStack_8,*pwStack_8 + 2);
      return 0;
    }
    _kfree(pwStack_8,*pwStack_8 + 2);
  }
  return 0x47;
}
/* GHIDRADEC_FUNCTION index=805 start=0x4026d26 */

int _findexport(undefined4 param_1,sword *param_2)

{
  int iVar1;
  sword sVar2;
  int iVar3;
  
  iVar1 = _exported;
  do {
    if (iVar1 == 0) {
      return 0;
    }
    iVar3 = _bcmp(iVar1 + 0x20,param_1,8);
    if (iVar3 == 0) {
      sVar2 = **(sword **)(iVar1 + 0x28);
      if ((sVar2 == *param_2) &&
         (iVar3 = _bcmp(*(sword **)(iVar1 + 0x28) + 1,param_2 + 1,sVar2), iVar3 == 0)) {
        return iVar1;
      }
    }
    iVar1 = *(int *)(iVar1 + 0x2c);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=806 start=0x4026d94 */

int _loadaddrs(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (*param_1 < 0x401) {
    iVar2 = *param_1 << 4;
    uVar1 = param_1[1];
    if (iVar2 == 0) {
      param_1[1] = 0;
      iVar3 = 0;
    }
    else {
      uVar4 = _kalloc(iVar2);
      param_1[1] = uVar4;
      iVar3 = _copyinmsg(uVar1,uVar4,iVar2);
      if (iVar3 != 0) {
        _kfree(param_1[1],iVar2);
      }
    }
  }
  else {
    iVar3 = 0x16;
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=807 start=0x4026dfa */

void _exportfree(int param_1)

{
  if ((*(int *)(param_1 + 8) == 1) && (*(int *)(param_1 + 0xc) != 0)) {
    _kfree(*(undefined4 *)(param_1 + 0x10),*(int *)(param_1 + 0xc) << 4);
  }
  if (((*(byte *)(param_1 + 3) & 2) != 0) && (*(int *)(param_1 + 0x18) != 0)) {
    _kfree(*(undefined4 *)(param_1 + 0x1c),*(int *)(param_1 + 0x18) << 4);
  }
  _kfree(*(word **)(param_1 + 0x28),**(word **)(param_1 + 0x28) + 2);
  _kfree(param_1,0x30);
  return;
}
/* GHIDRADEC_FUNCTION index=808 start=0x4026e70 */

void _nfs_svc(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined uStack_19;
  uint uStack_18;
  
  iVar2 = _getsock(**(undefined4 **)(dword_40B57D4 + 0x24));
  if (iVar2 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 9;
  }
  else {
    uVar1 = *(undefined4 *)(iVar2 + 0x16);
    iVar2 = _soreserve(uVar1,_nfs_chars,_nfs_chars + 0x20);
    if (iVar2 == 0) {
      iVar2 = _svckudp_create(uVar1,0x801);
      uStack_18 = 2;
      do {
        _svc_register(iVar2,0x186a3,uStack_18,&loc_40282D8,0);
        uStack_18 = uStack_18 + 1;
      } while (uStack_18 < 3);
      iVar3 = _setjmp(dword_40B57D4 + 0x28);
      if (iVar3 != 0) {
        iVar3 = _nfsd_count + -1;
        bVar4 = _nfsd_count == 1;
        _nfsd_count = iVar3;
        if (bVar4) {
          uStack_18 = 2;
          do {
            _svc_unregister(0x186a3,uStack_18);
            uStack_18 = uStack_18 + 1;
          } while (uStack_18 < 3);
        }
        (**(code **)(*(int *)(iVar2 + 6) + 0x14))(iVar2);
        *(undefined *)(dword_40B57D4 + 100) = 4;
                    /* WARNING: Subroutine does not return */
        _exit(0);
      }
      _nfsd_count = _nfsd_count + 1;
                    /* WARNING: Subroutine does not return */
      _svc_run(iVar2);
    }
    uStack_19 = (undefined)iVar2;
    *(undefined *)(dword_40B57D4 + 100) = uStack_19;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=809 start=0x40289ce */

void _nfs_netboot_prealloc(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int aiStack_1c [6];
  
  _MAXCLIENTS = _MAXCLIENTS + 3;
  uVar2 = 0;
  if (_MAXCLIENTS != 0) {
    do {
      iVar1 = sub_4028828(param_1,*(undefined4 *)(_active_u + 0x1a));
      aiStack_1c[uVar2] = iVar1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < _MAXCLIENTS);
  }
  uVar2 = 0;
  if (_MAXCLIENTS != 0) {
    do {
      if (aiStack_1c[uVar2] != 0) {
        sub_4028A8C(aiStack_1c[uVar2]);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < _MAXCLIENTS);
  }
  iVar1 = _kalloc(_MAXCLIENTS * 0x2260);
  uVar2 = 0;
  if (_MAXCLIENTS != 0) {
    iVar3 = 0;
    do {
      _clntkudp_realloc(*(undefined4 *)(unk_40BBED4 + iVar3),iVar1);
      iVar1 = iVar1 + 0x2260;
      iVar3 = iVar3 + 0xc;
      uVar2 = uVar2 + 1;
    } while (uVar2 < _MAXCLIENTS);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=810 start=0x4028aec */

int _rfscall(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int *param_6,int param_7)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int iStack_10;
  int iStack_c;
  
  dword_40BBF1C = dword_40BBF1C + 1;
  *(int *)(unk_40BBF24 + param_2 * 4) = *(int *)(unk_40BBF24 + param_2 * 4) + 1;
  iStack_c = 0;
  iStack_10 = 0;
  iVar9 = 0;
  iVar6 = *(int *)(param_1 + 0x2a) << ((int)*(sword *)(unk_40AEE2C + param_2 * 2) & 0x3fU);
  bVar3 = false;
  do {
    iVar4 = sub_4028828(param_1,param_7);
    if (param_2 == 9) {
      _clntkudp_once(iVar4,1);
    }
loc_4028B56:
    do {
      uVar8 = 0;
      iVar5 = (*(code *)**(undefined4 **)(iVar4 + 4))
                        (iVar4,param_2,param_3,param_4,param_5,param_6,iVar6 / 10,
                         (iVar6 % 10) * 100000);
      switch(iVar5) {
      case :
      case :
      case :
      case :
      case :
      case :
      case :
        break;
      :
        if (iVar5 == 0x12) {
          if ((*(byte *)(param_1 + 0x14) & 0xa0) == 0x80) goto loc_4028B56;
          iStack_10 = 0x12;
          iStack_c = 4;
          uVar8 = 0;
        }
        else {
          uVar8 = *(uint *)(param_1 + 0x14) >> 0x1f;
        }
        if (uVar8 == 0) goto loc_4028C92;
        iVar2 = iVar6 * 4;
        iVar6 = 300;
        if (iVar2 < 0x12d) {
          iVar6 = iVar2;
        }
        if ((*(byte *)(param_1 + 0x14) & 0x40) == 0) {
          *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x40;
          _printf(aNfsServerSNotR,param_1 + 0x32);
        }
        if ((!bVar3) && (*(int *)(_active_u + 0x15e) != 0)) {
          bVar3 = true;
          _uprintf(aNfsServerSNotR,param_1 + 0x32);
        }
      }
    } while (uVar8 != 0);
loc_4028C92:
    _clntkudp_once(iVar4,0);
    if (iVar5 != 0) {
      dword_40BBF20 = dword_40BBF20 + 1;
      *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x10;
      if (iVar5 != 0x12) {
        iStack_c = 0x16;
        uVar7 = _clnt_sperrno(iVar5);
        _printf(aNfsSFailedForS,*(undefined4 *)(_rfsnames + param_2 * 4),param_1 + 0x32,uVar7);
        iStack_10 = iVar5;
        if (*(int *)(_active_u + 0x15e) != 0) {
          uVar7 = _clnt_sperrno(iVar5);
          _uprintf(aNfsSFailedForS,*(undefined4 *)(_rfsnames + param_2 * 4),param_1 + 0x32,uVar7);
        }
      }
      goto loc_4028DAA;
    }
    if ((((param_6 == (int *)0x0) || (*param_6 != 0xd)) || (iVar9 != 0)) ||
       ((*(sword *)(param_7 + 2) != 0 || (*(sword *)(param_7 + 6) == 0)))) {
      bVar1 = *(byte *)(param_1 + 0x14);
      if ((char)bVar1 < '\0') {
        if ((bVar1 & 0x40) != 0) {
          _printf(aNfsServerSOk,param_1 + 0x32);
          *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) & 0xbf;
        }
        if (bVar3) {
          _uprintf(aNfsServerSOk,param_1 + 0x32);
        }
      }
      else {
        *(byte *)(param_1 + 0x14) = bVar1 & 0xef;
      }
loc_4028DAA:
      sub_4028A8C(iVar4);
      if (iVar9 != 0) {
        _crfree(iVar9);
      }
      if ((iStack_10 != 0) && (iStack_c == 0)) {
        _printf(aRfscallReStatu,iStack_10);
                    /* WARNING: Subroutine does not return */
        _panic(&aRfscall);
      }
      return iStack_c;
    }
    iVar9 = _crdup(param_7);
    *(undefined2 *)(iVar9 + 2) = *(undefined2 *)(iVar9 + 6);
    sub_4028A8C(iVar4);
    param_7 = iVar9;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=811 start=0x4028df6 */

void _vattr_to_sattr(int param_1,undefined4 *param_2)

{
  sword sVar1;
  
  sVar1 = *(sword *)(param_1 + 4);
  if (sVar1 == -1) {
    *param_2 = 0xffffffff;
  }
  else {
    *(undefined2 *)param_2 = 0;
    *(sword *)((int)param_2 + 2) = sVar1;
  }
  if (*(sword *)(param_1 + 6) == -1) {
    param_2[1] = 0xffffffff;
  }
  else {
    param_2[1] = (int)*(sword *)(param_1 + 6);
  }
  if (*(sword *)(param_1 + 8) == -1) {
    param_2[2] = 0xffffffff;
  }
  else {
    param_2[2] = (int)*(sword *)(param_1 + 8);
  }
  param_2[3] = *(undefined4 *)(param_1 + 0x14);
  param_2[4] = *(undefined4 *)(param_1 + 0x1c);
  param_2[5] = *(undefined4 *)(param_1 + 0x20);
  param_2[6] = *(undefined4 *)(param_1 + 0x24);
  param_2[7] = *(undefined4 *)(param_1 + 0x28);
  return;
}
/* GHIDRADEC_FUNCTION index=812 start=0x4028e70 */

void _setdiropargs(int param_1,undefined4 param_2,int param_3)

{
  _bcopy(*(int *)(param_3 + 0x2e) + 0x3e,param_1,0x20);
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=813 start=0x4028ea8 */

int _setdirgid(int param_1)

{
  sword sVar1;
  
  if (((*(byte *)(*(int *)(param_1 + 0x24) + 0xf) & 0x10) == 0) &&
     ((*(byte *)(*(int *)(param_1 + 0x2e) + 0x80) & 4) == 0)) {
    sVar1 = *(sword *)(*(int *)(_active_u + 0x1a) + 4);
  }
  else {
    sVar1 = *(sword *)(*(int *)(param_1 + 0x2e) + 0x84);
  }
  return (int)sVar1;
}
/* GHIDRADEC_FUNCTION index=814 start=0x4028ee6 */

uint _setdirmode(int param_1,uint param_2)

{
  param_2 = param_2 & 0xfffffbff;
  if ((*(byte *)(*(int *)(param_1 + 0x2e) + 0x80) & 4) != 0) {
    param_2 = param_2 | 0x400;
  }
  return param_2;
}
/* GHIDRADEC_FUNCTION index=815 start=0x4028f0a */

void _rnode_cache_clear(void)

{
  undefined4 *puVar1;
  
  puVar1 = _rpfreelist;
  while (puVar1 != (undefined4 *)0x0) {
    _rpfreelist = (undefined4 *)*puVar1;
    sub_402935A(puVar1);
    _rp_rmhash(puVar1);
    _rinactive(puVar1);
    _mfs_uncache(puVar1 + 3);
    _zfree(_vm_info_zone,puVar1[3]);
    _zfree(_rnode_zone,puVar1);
    puVar1 = _rpfreelist;
  }
  _rpfreelist = puVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=816 start=0x4028f7e */

undefined4 * _makenfsnode(undefined4 param_1,int *param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined2 uVar6;
  
  bVar2 = false;
  puVar3 = (undefined4 *)sub_40293F4(param_1,param_3);
  puVar4 = _rpfreelist;
  if (puVar3 == (undefined4 *)0x0) {
    if ((_rpfreelist == (undefined4 *)0x0) || (_rnew < _nrnode)) {
      if (_rnode_zone == 0) {
        _rnode_zone = _zinit(0xbe,1900000,0,0,aRnodeStructure);
      }
      puVar4 = (undefined4 *)_zalloc(_rnode_zone);
      puVar4[3] = 0;
      _vm_info_init(puVar4 + 3);
      _rnew = _rnew + 1;
    }
    else {
      _rpfreelist = (undefined4 *)*_rpfreelist;
      sub_402935A(puVar4);
      _rp_rmhash(puVar4);
      _rinactive(puVar4);
      _rreuse = _rreuse + 1;
    }
    piVar1 = puVar4 + 3;
    iVar5 = *piVar1;
    _bzero(puVar4,0xbe);
    *piVar1 = iVar5;
    _mfs_uncache(piVar1);
    *(undefined4 *)*piVar1 = 0;
    *(undefined4 *)(*piVar1 + 0x14) = puVar4[0x24];
    _bcopy(param_1,(int)puVar4 + 0x3e,0x20);
    *(undefined2 *)((int)puVar4 + 0x12) = 1;
    puVar4[10] = _nfs_vnodeops;
    if (param_2 != (int *)0x0) {
      iVar5 = *param_2;
      if ((iVar5 == 4) && (param_2[7] == -1)) {
        iVar5 = 8;
      }
      puVar4[0xd] = iVar5;
      if ((*param_2 == 4) && (param_2[7] == -1)) {
        uVar6 = 0;
      }
      else {
        uVar6 = *(undefined2 *)((int)param_2 + 0x1e);
      }
      *(undefined2 *)(puVar4 + 0xe) = uVar6;
    }
    *(undefined4 **)((int)puVar4 + 0x3a) = puVar4;
    puVar4[0xc] = param_3;
    sub_4029110(puVar4);
    piVar1 = (int *)(*(int *)(param_3 + 0x126) + 0x16);
    *piVar1 = *piVar1 + 1;
    bVar2 = true;
    puVar3 = puVar4;
  }
  puVar3 = puVar3 + 3;
  if (param_2 != (int *)0x0) {
    if (!bVar2) {
      _nfs_cache_check(puVar3,param_2[0xd],param_2[0xe],param_2[5],0);
    }
    _nfs_attrcache(puVar3,param_2);
  }
  return puVar3;
}
/* GHIDRADEC_FUNCTION index=817 start=0x40291f6 */

void _rp_rmhash(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = *(int *)(_rtable +
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
                         *(byte *)(param_1 + 0x4a) ^
                         *(byte *)(param_1 + 0x49) ^ *(byte *)(param_1 + 0x48)) & 0x3f) * 4);
  while( true ) {
    if (iVar2 == 0) {
      return;
    }
    if (param_1 == iVar2) break;
    iVar1 = iVar2;
    iVar2 = *(int *)(iVar2 + 8);
  }
  if (iVar1 == 0) {
    *(undefined4 *)
     (_rtable +
     ((byte)(*(byte *)(iVar2 + 0x59) ^
            *(byte *)(iVar2 + 0x58) ^
            *(byte *)(iVar2 + 0x57) ^
            *(byte *)(iVar2 + 0x56) ^
            *(byte *)(iVar2 + 0x55) ^
            *(byte *)(iVar2 + 0x54) ^
            *(byte *)(iVar2 + 0x53) ^
            *(byte *)(iVar2 + 0x52) ^
            *(byte *)(iVar2 + 0x4f) ^
            *(byte *)(iVar2 + 0x4e) ^
            *(byte *)(iVar2 + 0x4d) ^
            *(byte *)(iVar2 + 0x4c) ^
            *(byte *)(iVar2 + 0x4b) ^
            *(byte *)(iVar2 + 0x4a) ^ *(byte *)(iVar2 + 0x49) ^ *(byte *)(iVar2 + 0x48)) & 0x3f) * 4
     ) = *(undefined4 *)(iVar2 + 8);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar2 + 8);
  }
  _rnhash = _rnhash + -1;
  return;
}
/* GHIDRADEC_FUNCTION index=818 start=0x402939e */

void _rinactive(int param_1)

{
  if (*(int *)(param_1 + 0x6c) != 0) {
    _crfree(*(int *)(param_1 + 0x6c));
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=819 start=0x40293c2 */

void _rfree(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x30) + 0x126) + 0x16);
  *piVar1 = *piVar1 + -1;
  _rinactive(param_1);
  sub_402930E(param_1,1);
  return;
}
/* GHIDRADEC_FUNCTION index=820 start=0x40294e6 */

void _rinval(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar4 = _rtable;
  do {
    iVar1 = *(int *)puVar4;
    while (iVar3 = iVar1, iVar3 != 0) {
      iVar1 = *(int *)(iVar3 + 8);
      iVar2 = iVar3 + 0xc;
      if (param_1 == *(int *)(iVar3 + 0x30)) {
        _rp_rmhash(iVar3);
        *(sword *)(iVar3 + 0x12) = *(sword *)(iVar3 + 0x12) + 1;
        _binvalfree(iVar2);
        _dnlc_purge_vp(iVar2);
        if (1 < *(word *)(iVar3 + 0x12)) {
          sub_4029110(iVar3);
        }
        _vn_rele(iVar2);
      }
    }
    puVar4 = (undefined *)((int)puVar4 + 4);
  } while (puVar4 < _unixauthtab);
  return;
}
/* GHIDRADEC_FUNCTION index=821 start=0x402956a */

void _rflush(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = _rtable;
  do {
    for (iVar1 = *(int *)puVar2; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if (((-1 < *(char *)(iVar1 + 0x11)) && ((*(byte *)(*(int *)(iVar1 + 0x30) + 0xf) & 1) == 0))
         && ((param_1 == 0 || (param_1 == *(int *)(iVar1 + 0x30))))) {
        _sync_vp(iVar1 + 0xc);
      }
    }
    puVar2 = (undefined *)((int)puVar2 + 4);
  } while (puVar2 < _unixauthtab);
  return;
}
/* GHIDRADEC_FUNCTION index=822 start=0x40295ce */

undefined * _newname(void)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined5 *puVar4;
  undefined *puVar6;
  undefined auStack_c [2];
  word wStack_a;
  undefined5 *puVar5;
  undefined *puVar7;
  
  puVar3 = (undefined *)_kalloc(0xff);
  puVar5 = &aNfs_0;
  puVar7 = puVar3;
  do {
    puVar4 = (undefined5 *)((int)puVar5 + 1);
    puVar6 = puVar7 + 1;
    *puVar7 = *(undefined *)puVar5;
    puVar5 = puVar4;
    puVar7 = puVar6;
  } while (puVar4 < (undefined5 *)((int)&aNfs_0 + 4));
  if (dword_40B352C == 0) {
    _getthetime(auStack_c);
    dword_40B352C = (uint)wStack_a;
  }
  iVar2 = dword_40B352C + 1;
  for (uVar1 = dword_40B352C; dword_40B352C = iVar2, uVar1 != 0; uVar1 = (int)uVar1 >> 4) {
    *puVar6 = a0123456789abcd_0[uVar1 & 0xf];
    puVar6 = puVar6 + 1;
    iVar2 = dword_40B352C;
  }
  *puVar6 = 0;
  return puVar3;
}
/* GHIDRADEC_FUNCTION index=823 start=0x402964c */

void _rlock(int param_1)

{
  while (((*(word *)(param_1 + 0x5e) & 1) != 0 && (*(int *)(param_1 + 0x66) != _active_threads))) {
    *(word *)(param_1 + 0x5e) = *(word *)(param_1 + 0x5e) | 2;
    _sleep(param_1,10);
  }
  *(int *)(param_1 + 0x66) = _active_threads;
  *(sword *)(param_1 + 0x6a) = *(sword *)(param_1 + 0x6a) + 1;
  *(word *)(param_1 + 0x5e) = *(word *)(param_1 + 0x5e) | 1;
  return;
}
/* GHIDRADEC_FUNCTION index=824 start=0x402969e */

word _runlock(int param_1)

{
  sword sVar1;
  word wVar2;
  
  sVar1 = *(sword *)(param_1 + 0x6a);
  *(sword *)(param_1 + 0x6a) = sVar1 + -1;
  wVar2 = sVar1 - 1;
  if ((sword)wVar2 < 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aRunlock);
  }
  if (*(sword *)(param_1 + 0x6a) == 0) {
    wVar2 = *(word *)(param_1 + 0x5e);
    *(word *)(param_1 + 0x5e) = wVar2 & 0xffde;
    if ((wVar2 & 2) != 0) {
      *(word *)(param_1 + 0x5e) = wVar2 & 0xffdc;
      wVar2 = _wakeup(param_1);
    }
  }
  return wVar2;
}
/* GHIDRADEC_FUNCTION index=825 start=0x4029716 */

undefined4 _rlock_timeout(int param_1,int param_2)

{
  word wVar1;
  int iVar2;
  
  do {
    wVar1 = *(word *)(param_1 + 0x5e);
    if (((wVar1 & 1) == 0) || (*(int *)(param_1 + 0x66) == _active_threads)) {
      *(int *)(param_1 + 0x66) = _active_threads;
      *(sword *)(param_1 + 0x6a) = *(sword *)(param_1 + 0x6a) + 1;
      *(word *)(param_1 + 0x5e) = *(word *)(param_1 + 0x5e) | 1;
      return 0;
    }
    if ((wVar1 & 0x20) != 0) {
      _rlockretimeout = _rlockretimeout + 1;
      return 1;
    }
    *(word *)(param_1 + 0x5e) = wVar1 | 2;
    _timeout(sub_40296F8,param_1,_hz * param_2);
    _sleep(param_1,10);
    iVar2 = _untimeout(sub_40296F8,param_1);
  } while (iVar2 != 0);
  _rlocktimeout = _rlocktimeout + 1;
  *(word *)(param_1 + 0x5e) = *(word *)(param_1 + 0x5e) | 0x20;
  return 1;
}
/* GHIDRADEC_FUNCTION index=826 start=0x402a920 */

void _nfs_badop(void)

{
                    /* WARNING: Subroutine does not return */
  _panic(aNfsBadop);
}
/* GHIDRADEC_FUNCTION index=827 start=0x402aeec */

int _nfswrite(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iStack_84;
  undefined auStack_80 [68];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  
  do {
    iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x1e);
    if (param_4 < iVar2) {
      iVar2 = param_4;
    }
    iVar1 = *(int *)(param_1 + 0x2e);
    uStack_3c = *(undefined4 *)(iVar1 + 0x3e);
    uStack_38 = *(undefined4 *)(iVar1 + 0x42);
    uStack_34 = *(undefined4 *)(iVar1 + 0x46);
    uStack_30 = *(undefined4 *)(iVar1 + 0x4a);
    uStack_2c = *(undefined4 *)(iVar1 + 0x4e);
    uStack_28 = *(undefined4 *)(iVar1 + 0x52);
    uStack_24 = *(undefined4 *)(iVar1 + 0x56);
    uStack_20 = *(undefined4 *)(iVar1 + 0x5a);
    iStack_1c = param_3;
    iStack_18 = param_3;
    iStack_14 = iVar2;
    iStack_10 = iVar2;
    iStack_c = param_2;
    iVar1 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x126),8,_xdr_writeargs,&uStack_3c,
                     _xdr_attrstat,&iStack_84,param_5);
    if ((iVar1 == 0) && (iVar1 = iStack_84, iStack_84 == 0x46)) {
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
    param_4 = param_4 - iVar2;
    param_2 = iVar2 + param_2;
    param_3 = iVar2 + param_3;
    if (iVar1 != 0) goto loc_402AFCC;
  } while (param_4 != 0);
  _nfs_attrcache(param_1,auStack_80);
loc_402AFCC:
  if (iVar1 == 0x1c) {
    _printf(aNfsWriteErrorO,*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x32);
  }
  else {
    if (iVar1 < 0x1d) {
      if (iVar1 == 0) {
        return 0;
      }
    }
    else if (iVar1 == 0x45) {
      return 0x45;
    }
    _printf(aNfsWriteErrorD,iVar1,*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x32);
    sub_402B03A(*(int *)(param_1 + 0x2e) + 0x3e);
    _printf(&asc_40A6049);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=828 start=0x402c268 */

void _async_daemon(void)

{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  
  *(undefined4 *)(_active_threads + 0x74) = 1;
  _stack_privilege(_active_threads);
  dword_40B3568 = dword_40B3568 + 1;
  iVar2 = _setjmp(dword_40B57D4 + 0x28);
  if (iVar2 == 0) {
    do {
      dword_40B3564 = dword_40B3564 + 1;
      while (_async_bufhead == (uint *)0x0) {
        _sleep(&_async_bufhead,0x1a);
      }
      dword_40B3564 = dword_40B3564 + -1;
      puVar1 = _async_bufhead;
      _async_bufhead = (uint *)_async_bufhead[3];
      sub_402C364(puVar1);
    } while( true );
  }
  if (dword_40B3568 == 0) {
    dword_40B3568 = 0;
    puVar1 = _async_bufhead;
    while (_async_bufhead = puVar1, puVar1 != (uint *)0x0) {
      *puVar1 = *puVar1 | 4;
      _async_bufhead = (uint *)puVar1[3];
      _biodone(puVar1);
      puVar1 = _async_bufhead;
    }
  }
  else {
    iVar2 = dword_40B3568 + -1;
    dword_40B3564 = dword_40B3564 + -1;
    bVar3 = dword_40B3568 == 1;
    dword_40B3568 = iVar2;
    puVar1 = _async_bufhead;
    if (bVar3) {
      while (_async_bufhead = puVar1, puVar1 != (uint *)0x0) {
        _async_bufhead = (uint *)puVar1[3];
        sub_402C364(puVar1);
        puVar1 = _async_bufhead;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=829 start=0x402c4d2 */

void _sync_vp(int param_1)

{
  _mfs_fsync(param_1);
  if ((*(byte *)(*(int *)(param_1 + 0x2e) + 0x5f) & 0x10) != 0) {
    sub_402C536(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=830 start=0x402c502 */

void _sync_vp_invalidate(int param_1,undefined4 param_2)

{
  _mfs_fsync_invalidate(param_1,param_2);
  if ((*(byte *)(*(int *)(param_1 + 0x2e) + 0x5f) & 0x10) != 0) {
    sub_402C536(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=831 start=0x402cc8c */

bool _xdr_fhandle(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _xdr_opaque(param_1,param_2,0x20);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=832 start=0x402ccb0 */

undefined4 _xdr_writeargs(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_fhandle(param_1,param_2);
  if ((((iVar1 != 0) && (iVar1 = _xdr_long(param_1,param_2 + 0x20), iVar1 != 0)) &&
      (iVar1 = _xdr_long(param_1,param_2 + 0x24), iVar1 != 0)) &&
     (iVar1 = _xdr_long(param_1,param_2 + 0x28), iVar1 != 0)) {
    if (((undefined *)param_1[1] == _xdrmbuf_ops) && (*param_1 == 1)) {
      iVar1 = _xdrmbuf_getmbuf(param_1,param_2 + 0x34,param_2 + 0x2c);
    }
    else {
      iVar1 = _xdr_bytes(param_1,param_2 + 0x30,param_2 + 0x2c,0x2000);
    }
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=833 start=0x402cf0e */

undefined4 _xdr_readargs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_fhandle(param_1,param_2);
  if ((((iVar1 != 0) && (iVar1 = _xdr_long(param_1,param_2 + 0x20), iVar1 != 0)) &&
      (iVar1 = _xdr_long(param_1,param_2 + 0x24), iVar1 != 0)) &&
     (iVar1 = _xdr_long(param_1,param_2 + 0x28), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=834 start=0x402d182 */

bool _xdr_rdresult(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_union(param_1,param_2,param_2 + 4,_rdres_discrim,_xdr_void);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=835 start=0x402d230 */

bool _xdr_attrstat(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_union(param_1,param_2,param_2 + 4,_attrstat_discrim,_xdr_void);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=836 start=0x402d28c */

bool _xdr_rdlnres(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_union(param_1,param_2,param_2 + 4,_rdlnres_discrim,_xdr_void);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=837 start=0x402d2be */

undefined4 _xdr_rddirargs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_fhandle(param_1,param_2);
  if (((iVar1 != 0) && (iVar1 = _xdr_u_long(param_1,param_2 + 0x20), iVar1 != 0)) &&
     (iVar1 = _xdr_u_long(param_1,param_2 + 0x24), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=838 start=0x402d30e */

undefined4 _xdr_putrddirres(int *param_1,uint *param_2)

{
  uint uVar1;
  word *pwVar2;
  word wVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uStack_18;
  uint uStack_14;
  uint uStack_10;
  int *piStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 1;
  uStack_18 = 0;
  if (*param_1 == 0) {
    iVar4 = _xdr_enum(param_1,param_2 + 1);
    if (iVar4 != 0) {
      if (param_2[1] == 0) {
        iVar4 = (**(code **)(param_1[1] + 0x10))(param_1);
        uStack_14 = param_2[2];
        piVar6 = (int *)param_2[5];
        for (uVar1 = param_2[3]; 0 < (int)uVar1; uVar1 = uVar1 - *pwVar2) {
          wVar3 = *(word *)(piVar6 + 1);
          if (wVar3 == 0) {
            return 0;
          }
          if ((uint)wVar3 < *(word *)((int)piVar6 + 6) + 9) {
            return 0;
          }
          uStack_14 = wVar3 + uStack_14;
          if (*piVar6 != 0) {
            piStack_c = piVar6 + 2;
            uStack_10 = (uint)*(word *)((int)piVar6 + 6);
            iVar5 = _xdr_bool(param_1,&uStack_8);
            if (iVar5 == 0) {
              return 0;
            }
            iVar5 = _xdr_u_long(param_1,piVar6);
            if (iVar5 == 0) {
              return 0;
            }
            iVar5 = _xdr_bytes(param_1,&piStack_c,&uStack_10,0xff);
            if (iVar5 == 0) {
              return 0;
            }
            iVar5 = _xdr_u_long(param_1,&uStack_14);
            if (iVar5 == 0) {
              return 0;
            }
            iVar5 = (**(code **)(param_1[1] + 0x10))(param_1);
            if (*param_2 <= (uint)(iVar5 - iVar4)) {
              param_2[4] = 0;
              break;
            }
          }
          pwVar2 = (word *)(piVar6 + 1);
          piVar6 = (int *)((uint)*pwVar2 + (int)piVar6);
        }
        iVar4 = _xdr_bool(param_1,&uStack_18);
        if (iVar4 == 0) {
          return 0;
        }
        iVar4 = _xdr_bool(param_1,param_2 + 4);
        if (iVar4 == 0) {
          return 0;
        }
      }
      return 1;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=839 start=0x402d458 */

undefined4 _xdr_getrddirres(undefined4 param_1,int param_2)

{
  word *pwVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uStack_c;
  int iStack_8;
  
  uStack_c = 0xffffffff;
  iVar2 = _xdr_enum(param_1,(int *)(param_2 + 4));
  if (iVar2 != 0) {
    if (*(int *)(param_2 + 4) != 0) {
      return 1;
    }
    uVar4 = *(uint *)(param_2 + 0xc);
    iVar2 = *(int *)(param_2 + 0x14);
    while (iVar3 = _xdr_bool(param_1,&iStack_8), iVar3 != 0) {
      if (iStack_8 == 0) {
        iVar3 = _xdr_bool(param_1,param_2 + 0x10);
        if (iVar3 == 0) {
          return 0;
        }
        *(int *)(param_2 + 0xc) = iVar2 - *(int *)(param_2 + 0x14);
        *(undefined4 *)(param_2 + 8) = uStack_c;
        return 1;
      }
      if ((int)uVar4 < 6) {
        return 0;
      }
      iVar3 = _xdr_u_long(param_1,iVar2);
      if (iVar3 == 0) {
        return 0;
      }
      pwVar1 = (word *)(iVar2 + 6);
      iVar3 = _xdr_u_short(param_1,pwVar1);
      if (iVar3 == 0) {
        return 0;
      }
      if (uVar4 < (*pwVar1 + 0xc & 0xfffffffc)) {
        return 0;
      }
      iVar3 = _xdr_opaque(param_1,iVar2 + 8,(uint)*pwVar1);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = _xdr_u_long(param_1,&uStack_c);
      if (iVar3 == 0) {
        return 0;
      }
      *(word *)(iVar2 + 4) = *pwVar1 + 0xc & 0xfffc;
      *(undefined *)(iVar2 + 8 + (uint)*pwVar1) = 0;
      uVar4 = uVar4 - *(word *)(iVar2 + 4);
      if ((int)uVar4 < 0) {
        return 0;
      }
      iVar2 = (uint)*(word *)(iVar2 + 4) + iVar2;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=840 start=0x402d56a */

undefined4 _xdr_diropargs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_fhandle(param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = _xdr_string(param_1,param_2 + 0x20,0xff), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=841 start=0x402d5f2 */

bool _xdr_diropres(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_union(param_1,param_2,param_2 + 4,_diropres_discrim,_xdr_void);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=842 start=0x402d662 */

undefined4 _xdr_saargs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_fhandle(param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = sub_402D1B4(param_1,param_2 + 0x20), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=843 start=0x402d6a4 */

undefined4 _xdr_creatargs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_diropargs(param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = sub_402D1B4(param_1,param_2 + 0x24), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=844 start=0x402d6e6 */

undefined4 _xdr_linkargs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_fhandle(param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = _xdr_diropargs(param_1,param_2 + 0x20), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=845 start=0x402d728 */

undefined4 _xdr_rnmargs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_diropargs(param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = _xdr_diropargs(param_1,param_2 + 0x24), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=846 start=0x402d766 */

undefined4 _xdr_slargs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_diropargs(param_1,param_2);
  if (((iVar1 != 0) && (iVar1 = _xdr_string(param_1,param_2 + 0x24,0x400), iVar1 != 0)) &&
     (iVar1 = sub_402D1B4(param_1,param_2 + 0x28), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=847 start=0x402d828 */

bool _xdr_statfs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_union(param_1,param_2,param_2 + 4,_statfs_discrim,_xdr_void);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=848 start=0x402d85a */

//Decompiler native message:  Marshaling error: Attribute metatype is not present
//Decompiling function: _authkern_create @ 0x402d85a
/* GHIDRADEC_FUNCTION index=849 start=0x402d8a6 */

void _authkern_nextverf(void)

{
  return;
}

