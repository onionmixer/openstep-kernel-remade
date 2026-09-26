/* GHIDRADEC_FUNCTION index=825 start=0x402a920 */

void _nfs_badop(void)

{
                    /* WARNING: Subroutine does not return */
  _panic(aNfsBadop);
}
/* GHIDRADEC_FUNCTION index=826 start=0x402aeec */

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
/* GHIDRADEC_FUNCTION index=827 start=0x402c268 */

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
/* GHIDRADEC_FUNCTION index=828 start=0x402c4d2 */

void _sync_vp(int param_1)

{
  _mfs_fsync(param_1);
  if ((*(byte *)(*(int *)(param_1 + 0x2e) + 0x5f) & 0x10) != 0) {
    sub_402C536(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=829 start=0x402c502 */

void _sync_vp_invalidate(int param_1,undefined4 param_2)

{
  _mfs_fsync_invalidate(param_1,param_2);
  if ((*(byte *)(*(int *)(param_1 + 0x2e) + 0x5f) & 0x10) != 0) {
    sub_402C536(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=830 start=0x402cc8c */

bool _xdr_fhandle(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _xdr_opaque(param_1,param_2,0x20);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=831 start=0x402ccb0 */

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
/* GHIDRADEC_FUNCTION index=832 start=0x402cf0e */

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
/* GHIDRADEC_FUNCTION index=833 start=0x402d182 */

bool _xdr_rdresult(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_union(param_1,param_2,param_2 + 4,_rdres_discrim,_xdr_void);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=834 start=0x402d230 */

bool _xdr_attrstat(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_union(param_1,param_2,param_2 + 4,_attrstat_discrim,_xdr_void);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=835 start=0x402d28c */

bool _xdr_rdlnres(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_union(param_1,param_2,param_2 + 4,_rdlnres_discrim,_xdr_void);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=836 start=0x402d2be */

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
/* GHIDRADEC_FUNCTION index=837 start=0x402d30e */

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
/* GHIDRADEC_FUNCTION index=838 start=0x402d458 */

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
/* GHIDRADEC_FUNCTION index=839 start=0x402d56a */

undefined4 _xdr_diropargs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_fhandle(param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = _xdr_string(param_1,param_2 + 0x20,0xff), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=840 start=0x402d5f2 */

bool _xdr_diropres(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_union(param_1,param_2,param_2 + 4,_diropres_discrim,_xdr_void);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=841 start=0x402d662 */

undefined4 _xdr_saargs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_fhandle(param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = sub_402D1B4(param_1,param_2 + 0x20), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=842 start=0x402d6a4 */

undefined4 _xdr_creatargs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_diropargs(param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = sub_402D1B4(param_1,param_2 + 0x24), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=843 start=0x402d6e6 */

undefined4 _xdr_linkargs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_fhandle(param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = _xdr_diropargs(param_1,param_2 + 0x20), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=844 start=0x402d728 */

undefined4 _xdr_rnmargs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_diropargs(param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = _xdr_diropargs(param_1,param_2 + 0x24), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=845 start=0x402d766 */

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
/* GHIDRADEC_FUNCTION index=846 start=0x402d828 */

bool _xdr_statfs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_union(param_1,param_2,param_2 + 4,_statfs_discrim,_xdr_void);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=847 start=0x402d85a */

//Decompiler native message:  Marshaling error: Attribute metatype is not present
//Decompiling function: _authkern_create @ 0x402d85a
/* GHIDRADEC_FUNCTION index=848 start=0x402d8a6 */

void _authkern_nextverf(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=849 start=0x402d8ae */

undefined4 _authkern_marshal(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  sword *psVar8;
  sword *psVar9;
  undefined4 auStack_24 [2];
  undefined auStack_1c [4];
  int iStack_18;
  
  psVar8 = (sword *)(*(int *)(_active_u + 0x1a) + 10);
  for (psVar9 = (sword *)(*(int *)(_active_u + 0x1a) + 0x2a);
      (psVar8 < psVar9 && (psVar9[-1] == -1)); psVar9 = psVar9 + -1) {
  }
  iVar6 = (int)psVar9 - (int)psVar8 >> 1;
  uVar3 = _hostnamelen + 3;
  if ((int)uVar3 < 0) {
    uVar3 = _hostnamelen + 6;
  }
  iVar1 = (uVar3 & 0xfffffffc) + 0x14 + iVar6 * 4;
  puVar2 = (undefined4 *)(**(code **)(*(int *)(param_2 + 4) + 0x18))(param_2,iVar1 + 0x10);
  if (puVar2 == (undefined4 *)0x0) {
    uVar5 = _kalloc(400);
    _xdrmem_create(auStack_1c,uVar5,400,0);
    iVar6 = _xdr_authkern(auStack_1c);
    if (iVar6 == 0) {
      _printf(aAuthkernMarsha);
      uVar4 = 0;
    }
    else {
      uVar4 = (**(code **)(iStack_18 + 0x10))(auStack_1c);
      *(undefined4 *)(param_1 + 8) = uVar4;
      *(undefined4 *)(param_1 + 4) = uVar5;
      iVar6 = _xdr_opaque_auth(param_2,param_1);
      if ((iVar6 == 0) || (iVar6 = _xdr_opaque_auth(param_2,param_1 + 0xc), iVar6 == 0)) {
        uVar4 = 0;
      }
      else {
        uVar4 = 1;
      }
    }
    _kfree(uVar5,400);
  }
  else {
    _getthetime(auStack_24);
    *puVar2 = 1;
    puVar2[1] = iVar1;
    puVar2[2] = auStack_24[0];
    puVar2[3] = _hostnamelen;
    _bcopy(_hostname,puVar2 + 4,_hostnamelen);
    uVar3 = _hostnamelen + 3;
    if ((int)uVar3 < 0) {
      uVar3 = _hostnamelen + 6;
    }
    piVar7 = (int *)((uVar3 & 0xfffffffc) + (int)(puVar2 + 4));
    *piVar7 = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 2);
    piVar7[1] = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 4);
    piVar7[2] = iVar6;
    piVar7 = piVar7 + 3;
    for (; psVar8 < psVar9; psVar8 = psVar8 + 1) {
      *piVar7 = (int)*psVar8;
      piVar7 = piVar7 + 1;
    }
    *piVar7 = 0;
    piVar7[1] = 0;
    uVar4 = 1;
  }
  return uVar4;
}

