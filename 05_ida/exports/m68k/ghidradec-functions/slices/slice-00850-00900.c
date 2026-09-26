/* GHIDRADEC_FUNCTION index=850 start=0x402d8ae */

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
/* GHIDRADEC_FUNCTION index=851 start=0x402da3a */

undefined4 _authkern_validate(void)

{
  return 1;
}
/* GHIDRADEC_FUNCTION index=852 start=0x402da44 */

undefined4 _authkern_refresh(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=853 start=0x402da4e */

void _authkern_destroy(undefined4 param_1)

{
  _kfree(param_1,0x28);
  return;
}
/* GHIDRADEC_FUNCTION index=854 start=0x402da64 */

undefined4 _xdr_authunix_parms(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_u_long(param_1,param_2);
  if ((((iVar1 != 0) && (iVar1 = _xdr_string(param_1,param_2 + 4,0xff), iVar1 != 0)) &&
      (iVar1 = _xdr_int(param_1,param_2 + 8), iVar1 != 0)) &&
     ((iVar1 = _xdr_int(param_1,param_2 + 0xc), iVar1 != 0 &&
      (iVar1 = _xdr_array(param_1,param_2 + 0x14,param_2 + 0x10,0x10,4,_xdr_int), iVar1 != 0)))) {
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=855 start=0x402daec */

undefined4 _xdr_authkern(int *param_1)

{
  int iVar1;
  sword *psVar2;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  undefined *puStack_50;
  undefined auStack_4c [8];
  int aiStack_44 [16];
  
  psVar2 = (sword *)(*(int *)(_active_u + 0x1a) + 10);
  iStack_54 = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 2);
  iStack_58 = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 4);
  puStack_50 = _hostname;
  if (*param_1 == 0) {
    iStack_5c = 0;
    do {
      if (*psVar2 == -1) break;
      aiStack_44[iStack_5c] = (int)*psVar2;
      psVar2 = psVar2 + 1;
      iStack_5c = iStack_5c + 1;
    } while (iStack_5c < 0x10);
    _getthetime(auStack_4c);
    iVar1 = _xdr_u_long(param_1,auStack_4c);
    if ((((iVar1 != 0) && (iVar1 = _xdr_string(param_1,&puStack_50,0xff), iVar1 != 0)) &&
        (iVar1 = _xdr_int(param_1,&iStack_54), iVar1 != 0)) &&
       ((iVar1 = _xdr_int(param_1,&iStack_58), iVar1 != 0 &&
        (iVar1 = _xdr_array(param_1,aiStack_44,&iStack_5c,0x10,4,_xdr_int), iVar1 != 0)))) {
      return 1;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=856 start=0x402dbd2 */

void _clntkudp_once(int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 8);
  if (param_2 == 0) {
    *puVar1 = *puVar1 & 0xffffffdf;
  }
  else {
    *puVar1 = *puVar1 | 0x20;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=857 start=0x402dbf2 */

void _clntkudp_interruptable(int param_1,int param_2)

{
  word *pwVar1;
  
  if (param_2 == 0) {
    pwVar1 = (word *)(*(int *)(param_1 + 8) + 2);
    *pwVar1 = *pwVar1 & 0xf7ff;
  }
  else {
    pwVar1 = (word *)(*(int *)(param_1 + 8) + 2);
    *pwVar1 = *pwVar1 | 0x800;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=858 start=0x402dc16 */

void _clntkudp_realloc(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  _bcopy(*(undefined4 *)(iVar1 + 0x68),param_2,0x2260);
  _kfree(*(undefined4 *)(iVar1 + 0x68),0x2260);
  *(undefined4 *)(iVar1 + 0x68) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=859 start=0x402dc8a */

undefined4 *
_clntkudp_create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  undefined auStack_3c [4];
  int iStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  *(undefined4 *)(_active_threads + 0x180) = 1;
  iVar3 = _kalloc(0x78);
  _bzero(iVar3,0x78);
  puVar1 = (undefined4 *)(iVar3 + 4);
  if (_clntkudpxid == 0) {
    _getthetime(auStack_3c);
    _clntkudpxid = iStack_38;
  }
  *(undefined **)(iVar3 + 8) = _udp_ops;
  *(int *)(iVar3 + 0xc) = iVar3;
  uVar4 = _authkern_create();
  *puVar1 = uVar4;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 2;
  uStack_28 = param_2;
  uStack_24 = param_3;
  _clntkudp_init(puVar1,param_1,param_4,param_5);
  uVar4 = _kalloc(0x2260);
  *(undefined4 *)(iVar3 + 0x68) = uVar4;
  iVar5 = _mclgetx(sub_402DC58,0,uVar4,0x2260,1);
  if (iVar5 != 0) {
    iVar2 = iVar3 + 0x34;
    _xdrmbuf_init(iVar2,iVar5,0);
    iVar6 = _xdr_callhdr(iVar2,&uStack_34);
    if (iVar6 == 0) {
      _printf(aClntkudpCreate);
      _m_freem(iVar5);
    }
    else {
      uVar4 = (**(code **)(*(int *)(iVar3 + 0x38) + 0x10))(iVar2);
      *(undefined4 *)(iVar3 + 100) = uVar4;
      _m_free(iVar5);
      iVar5 = _socreate(2,(undefined4 *)(iVar3 + 0x14),2,0x11);
      if (iVar5 == 0) {
        iVar5 = sub_402E54E(*(undefined4 *)(iVar3 + 0x14));
        if (iVar5 == 0) {
          *(undefined4 *)(_active_threads + 0x180) = 0;
          return puVar1;
        }
        puVar7 = aClntkudpCreate_1;
      }
      else {
        puVar7 = aClntkudpCreate_0;
      }
      _printf(puVar7,iVar5);
    }
  }
  *(undefined4 *)(_active_threads + 0x180) = 0;
  _kfree(*(undefined4 *)(iVar3 + 0x68),0x2260);
  _crfree(*(undefined4 *)(iVar3 + 0x74));
  _kfree(iVar3,0x78);
  return (undefined4 *)0x0;
}
/* GHIDRADEC_FUNCTION index=860 start=0x402de2a */

void _clntkudp_init(int param_1,uint *param_2,uint param_3,sword *param_4)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 8);
  puVar1[4] = param_3;
  puVar1[6] = *param_2;
  puVar1[7] = param_2[1];
  puVar1[8] = param_2[2];
  puVar1[9] = param_2[3];
  puVar1[0x1d] = (uint)param_4;
  *param_4 = *param_4 + 1;
  *puVar1 = *puVar1 & 0x18;
  return;
}
/* GHIDRADEC_FUNCTION index=861 start=0x402de68 */

void _clntkudp_freecred(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  _crfree(*(undefined4 *)(iVar1 + 0x74));
  *(undefined4 *)(iVar1 + 0x74) = 0xefefefef;
  return;
}
/* GHIDRADEC_FUNCTION index=862 start=0x402de90 */

//Decompiler native message:  Marshaling error: Attribute metatype is not present
//Decompiling function: _clntkudp_callit_addr @ 0x402de90
/* GHIDRADEC_FUNCTION index=863 start=0x402e46c */

void _clntkudp_callit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  _clntkudp_callit_addr(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,0);
  return;
}
/* GHIDRADEC_FUNCTION index=864 start=0x402e49c */

void _ckuwakeup(uint *param_1)

{
  *param_1 = *param_1 | 1;
  _sbwakeup(param_1[5] + 0x22);
  return;
}
/* GHIDRADEC_FUNCTION index=865 start=0x402e4ba */

void _clntkudp_error(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  *param_2 = *(undefined4 *)(iVar1 + 0x28);
  param_2[1] = *(undefined4 *)(iVar1 + 0x2c);
  param_2[2] = *(undefined4 *)(iVar1 + 0x30);
  return;
}
/* GHIDRADEC_FUNCTION index=866 start=0x402e4da */

void _clntkudp_freeres(int param_1,code *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(int *)(param_1 + 8) + 0x34);
  *puVar1 = 2;
  (*param_2)(puVar1,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=867 start=0x402e4fe */

void _clntkudp_abort(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=868 start=0x402e506 */

undefined4 _clntkudp_control(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=869 start=0x402e510 */

void _clntkudp_destroy(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  _soclose(*(undefined4 *)(iVar1 + 0x14));
  _kfree(*(undefined4 *)(iVar1 + 0x68),0x2260);
  _kfree(iVar1,0x78);
  return;
}
/* GHIDRADEC_FUNCTION index=870 start=0x402e612 */

undefined * _clnt_sperrno(int param_1)

{
  uint uVar1;
  undefined *puVar2;
  
  uVar1 = 0;
  puVar2 = unk_40AEF96;
  do {
    if (param_1 == *(int *)puVar2) {
      return *(undefined **)(unk_40AEF96 + uVar1 * 8 + 4);
    }
    puVar2 = (undefined *)((int)puVar2 + 8);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x11);
  return aRpcUnknownErro;
}
/* GHIDRADEC_FUNCTION index=871 start=0x402e652 */

undefined4
_pmap_kgetport(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  word wVar1;
  int iVar2;
  sword sVar4;
  int *piVar3;
  undefined4 uVar5;
  undefined2 *puVar6;
  sword sStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  sStack_26 = 0;
  uVar5 = 0;
  if (word_40B356C == 0) {
    iVar2 = 0xf;
    puVar6 = &unk_40B3594;
    do {
      do {
        *puVar6 = 0xffff;
        puVar6 = puVar6 + -1;
        wVar1 = (word)((uint)iVar2 >> 0x10);
        sVar4 = (sword)iVar2 + -1;
        iVar2 = CONCAT22(wVar1,sVar4);
      } while (sVar4 != -1);
      iVar2 = (uint)wVar1 * 0x10000 + -1;
    } while (wVar1 != 0);
    word_40B356C = word_40B356C + 1;
  }
  uStack_20 = param_1[1];
  uStack_1c = param_1[2];
  uStack_18 = param_1[3];
  _uStack_24 = CONCAT22((sword)((uint)*param_1 >> 0x10),0x6f);
  piVar3 = (int *)_clntkudp_create(&uStack_24,100000,2,4,&word_40B356C);
  if (piVar3 != (int *)0x0) {
    uStack_14 = param_2;
    uStack_10 = param_3;
    uStack_c = param_4;
    uStack_8 = 0;
    iVar2 = (**(code **)piVar3[1])
                      (piVar3,3,_xdr_pmap,&uStack_14,_xdr_u_short,&sStack_26,dword_40AF01E,
                       dword_40AF022);
    if (iVar2 == 0) {
      if (sStack_26 == 0) {
        uVar5 = 0xffffffff;
      }
      else {
        *(sword *)((int)param_1 + 2) = sStack_26;
      }
    }
    else {
      uVar5 = 1;
    }
    (**(code **)(*(int *)(*piVar3 + 0x20) + 0x10))(*piVar3);
    (**(code **)(piVar3[1] + 0x10))(piVar3);
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=872 start=0x402e750 */

int _getport_loop(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  
  iVar4 = 0;
  do {
    iVar2 = _pmap_kgetport(param_1,param_2,param_3,param_4);
    if (iVar2 < 1) {
      if (iVar4 != 0) {
        puVar5 = aPortmapperOk;
loc_402E7F2:
        _printf(puVar5);
      }
      return iVar2;
    }
    if ((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) {
loc_402E7C8:
      puVar5 = aPortmapperNotR;
      goto loc_402E7F2;
    }
    iVar3 = *_active_u;
    uVar1 = *(uint *)(*(int *)(_active_threads + 0x80) + 0x72) | *(uint *)(iVar3 + 0x18);
    if ((uVar1 != 0) &&
       (((*(byte *)(iVar3 + 0x2b) & 0x10) != 0 ||
        ((uVar1 & ~(*(uint *)(iVar3 + 0x1c) | *(uint *)(iVar3 + 0x20))) != 0)))) {
      iVar3 = _issig(0);
      if (iVar3 != 0) goto loc_402E7C8;
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 1) {
      _printf(aPortmapperNotR_0);
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=873 start=0x402e804 */

undefined4 _xdr_pmap(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _xdr_u_long(param_1,param_2);
  if (((iVar1 != 0) && (iVar1 = _xdr_u_long(param_1,param_2 + 4), iVar1 != 0)) &&
     (iVar1 = _xdr_u_long(param_1,param_2 + 8), iVar1 != 0)) {
    uVar2 = _xdr_u_long(param_1,param_2 + 0xc);
    return uVar2;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=874 start=0x402e858 */

undefined4 _xdr_rmtcall_args(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = _xdr_u_long(param_1,param_2);
  if (((iVar2 != 0) && (iVar2 = _xdr_u_long(param_1,param_2 + 4), iVar2 != 0)) &&
     (iVar2 = _xdr_u_long(param_1,param_2 + 8), iVar2 != 0)) {
    uVar3 = (**(code **)(*(int *)(param_1 + 4) + 0x10))(param_1);
    piVar1 = (int *)(param_2 + 0xc);
    iVar2 = _xdr_u_long(param_1,piVar1);
    if (iVar2 != 0) {
      iVar2 = (**(code **)(*(int *)(param_1 + 4) + 0x10))(param_1);
      iVar4 = (**(code **)(param_2 + 0x14))(param_1,*(undefined4 *)(param_2 + 0x10));
      if (iVar4 != 0) {
        iVar4 = (**(code **)(*(int *)(param_1 + 4) + 0x10))(param_1);
        *piVar1 = iVar4 - iVar2;
        (**(code **)(*(int *)(param_1 + 4) + 0x14))(param_1,uVar3);
        iVar2 = _xdr_u_long(param_1,piVar1);
        if (iVar2 != 0) {
          (**(code **)(*(int *)(param_1 + 4) + 0x14))(param_1,iVar4);
          return 1;
        }
      }
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=875 start=0x402e92c */

undefined4 _xdr_rmtcallres(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_8;
  
  uStack_8 = *param_2;
  iVar1 = _xdr_reference(param_1,&uStack_8,4,_xdr_u_long);
  if ((iVar1 != 0) && (iVar1 = _xdr_u_long(param_1,param_2 + 1), iVar1 != 0)) {
    *param_2 = uStack_8;
    uVar2 = (*(code *)param_2[3])(param_1,param_2[2]);
    return uVar2;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=876 start=0x402e990 */

undefined4 _xdr_callmsg(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  if (*param_1 == 0) {
    if (400 < (uint)param_2[8]) {
      return 0;
    }
    if (400 < (uint)param_2[0xb]) {
      return 0;
    }
    puVar2 = (undefined4 *)
             (**(code **)(param_1[1] + 0x18))
                       (param_1,(param_2[0xb] + 3 & 0xfffffffc) + 0x28 +
                                (param_2[8] + 3 & 0xfffffffc));
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = *param_2;
      iVar4 = param_2[1];
      puVar2[1] = iVar4;
      if (iVar4 != 0) {
        return 0;
      }
      puVar2[2] = param_2[2];
      if (param_2[2] != 2) {
        return 0;
      }
      puVar2[3] = param_2[3];
      puVar2[4] = param_2[4];
      puVar2[5] = param_2[5];
      puVar2[6] = param_2[6];
      puVar5 = puVar2 + 8;
      puVar2[7] = param_2[8];
      if (param_2[8] != 0) {
        _bcopy(param_2[7],puVar5,param_2[8]);
        puVar5 = (undefined4 *)((param_2[8] + 3 & 0xfffffffc) + (int)puVar5);
      }
      *puVar5 = param_2[9];
      puVar2 = puVar5 + 2;
      puVar5[1] = param_2[0xb];
      iVar6 = param_2[0xb];
      if (iVar6 == 0) {
        return 1;
      }
      iVar4 = param_2[10];
      goto loc_402EBC4;
    }
  }
  if ((*param_1 != 1) ||
     (puVar2 = (undefined4 *)(**(code **)(param_1[1] + 0x18))(param_1,0x20),
     puVar2 == (undefined4 *)0x0)) {
    iVar4 = _xdr_u_long(param_1,param_2);
    if (iVar4 != 0) {
      iVar4 = _xdr_enum(param_1,param_2 + 1);
      if ((iVar4 != 0) && (param_2[1] == 0)) {
        iVar4 = _xdr_u_long(param_1,param_2 + 2);
        if (((iVar4 != 0) &&
            (((param_2[2] == 2 && (iVar4 = _xdr_u_long(param_1,param_2 + 3), iVar4 != 0)) &&
             (iVar4 = _xdr_u_long(param_1,param_2 + 4), iVar4 != 0)))) &&
           ((iVar4 = _xdr_u_long(param_1,param_2 + 5), iVar4 != 0 &&
            (iVar4 = _xdr_opaque_auth(param_1,param_2 + 6), iVar4 != 0)))) {
          uVar3 = _xdr_opaque_auth(param_1,param_2 + 9);
          return uVar3;
        }
      }
    }
    return 0;
  }
  *param_2 = *puVar2;
  iVar4 = puVar2[1];
  param_2[1] = iVar4;
  if (iVar4 != 0) {
    return 0;
  }
  param_2[2] = puVar2[2];
  if (param_2[2] != 2) {
    return 0;
  }
  param_2[3] = puVar2[3];
  param_2[4] = puVar2[4];
  param_2[5] = puVar2[5];
  param_2[6] = puVar2[6];
  param_2[8] = puVar2[7];
  uVar1 = param_2[8];
  if (uVar1 != 0) {
    if (400 < uVar1) {
      return 0;
    }
    if (param_2[7] == 0) {
      uVar3 = _kalloc(uVar1);
      param_2[7] = uVar3;
    }
    iVar4 = (**(code **)(param_1[1] + 0x18))(param_1,param_2[8] + 3 & 0xfffffffc);
    if (iVar4 == 0) {
      iVar4 = _xdr_opaque(param_1,param_2[7],param_2[8]);
      if (iVar4 == 0) {
        return 0;
      }
    }
    else {
      _bcopy(iVar4,param_2[7],param_2[8]);
    }
  }
  puVar2 = (undefined4 *)(**(code **)(param_1[1] + 0x18))(param_1,8);
  if (puVar2 == (undefined4 *)0x0) {
    iVar4 = _xdr_enum(param_1,param_2 + 9);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = _xdr_u_int(param_1,param_2 + 0xb);
    if (iVar4 == 0) {
      return 0;
    }
  }
  else {
    param_2[9] = *puVar2;
    param_2[0xb] = puVar2[1];
  }
  uVar1 = param_2[0xb];
  if (uVar1 == 0) {
    return 1;
  }
  if (400 < uVar1) {
    return 0;
  }
  if (param_2[10] == 0) {
    uVar3 = _kalloc(uVar1);
    param_2[10] = uVar3;
  }
  iVar4 = (**(code **)(param_1[1] + 0x18))(param_1,param_2[0xb] + 3 & 0xfffffffc);
  if (iVar4 == 0) {
    iVar4 = _xdr_opaque(param_1,param_2[10],param_2[0xb]);
    if (iVar4 == 0) {
      return 0;
    }
    return 1;
  }
  iVar6 = param_2[0xb];
  puVar2 = (undefined4 *)param_2[10];
loc_402EBC4:
  _bcopy(iVar4,puVar2,iVar6);
  return 1;
}
/* GHIDRADEC_FUNCTION index=877 start=0x402ec64 */

undefined4 _xdr_opaque_auth(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _xdr_enum(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = _xdr_bytes(param_1,param_2 + 4,param_2 + 8,400);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=878 start=0x402eca8 */

void _xdr_des_block(undefined4 param_1,undefined4 param_2)

{
  _xdr_opaque(param_1,param_2,8);
  return;
}
/* GHIDRADEC_FUNCTION index=879 start=0x402ecc2 */

undefined4 _xdr_accepted_reply(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _xdr_opaque_auth(param_1,param_2);
  if (iVar1 != 0) {
    iVar1 = _xdr_enum(param_1,(int *)(param_2 + 0xc));
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_2 + 0xc);
      if (iVar1 == 0) {
        uVar2 = (**(code **)(param_2 + 0x14))(param_1,*(undefined4 *)(param_2 + 0x10));
        return uVar2;
      }
      if (iVar1 != 2) {
        return 1;
      }
      iVar1 = _xdr_u_long(param_1,param_2 + 0x10);
      if (iVar1 != 0) {
        uVar2 = _xdr_u_long(param_1,param_2 + 0x14);
        return uVar2;
      }
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=880 start=0x402ed3e */

undefined4 _xdr_rejected_reply(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  pcVar3 = _xdr_enum;
  iVar1 = _xdr_enum(param_1,param_2);
  if (iVar1 != 0) {
    if (*param_2 == 0) {
      pcVar3 = _xdr_u_long;
      iVar1 = _xdr_u_long(param_1,param_2 + 1);
      if (iVar1 != 0) {
        param_2 = param_2 + 2;
        goto loc_402ED8A;
      }
    }
    else if (*param_2 == 1) {
      param_2 = param_2 + 1;
loc_402ED8A:
      uVar2 = (*pcVar3)(param_1,param_2);
      return uVar2;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=881 start=0x402ed9c */

undefined4 _xdr_replymsg(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  if ((((*param_1 == 0) && (param_2[2] == 0)) && (param_2[1] == 1)) &&
     (puVar2 = (undefined4 *)(**(code **)(param_1[1] + 0x18))(param_1,param_2[5] + 0x18),
     puVar2 != (undefined4 *)0x0)) {
    *puVar2 = *param_2;
    puVar2[1] = param_2[1];
    puVar2[2] = param_2[2];
    puVar2[3] = param_2[3];
    puVar5 = puVar2 + 5;
    puVar2[4] = param_2[5];
    if (param_2[5] != 0) {
      _bcopy(param_2[4],puVar5,param_2[5]);
      puVar5 = (undefined4 *)((param_2[5] + 3 & 0xfffffffc) + (int)puVar5);
    }
    *puVar5 = param_2[6];
    if (param_2[6] == 0) {
      uVar4 = (*(code *)param_2[8])(param_1,param_2[7]);
      return uVar4;
    }
    if (param_2[6] != 2) {
      return 1;
    }
    iVar3 = _xdr_u_long(param_1,param_2 + 7);
  }
  else {
    if ((*param_1 != 1) ||
       (puVar2 = (undefined4 *)(**(code **)(param_1[1] + 0x18))(param_1,0xc),
       puVar2 == (undefined4 *)0x0)) {
      iVar3 = _xdr_u_long(param_1,param_2);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = _xdr_enum(param_1,param_2 + 1);
      if (iVar3 == 0) {
        return 0;
      }
      if (param_2[1] != 1) {
        return 0;
      }
      uVar4 = _xdr_union(param_1,param_2 + 2,param_2 + 3,unk_40AF026,0);
      return uVar4;
    }
    *param_2 = *puVar2;
    param_2[1] = puVar2[1];
    if (param_2[1] != 1) {
      return 0;
    }
    param_2[2] = puVar2[2];
    if (param_2[2] != 0) {
      if (param_2[2] != 1) {
        return 0;
      }
      uVar4 = _xdr_rejected_reply(param_1,param_2 + 3);
      return uVar4;
    }
    puVar2 = (undefined4 *)(**(code **)(param_1[1] + 0x18))(param_1,8);
    if (puVar2 == (undefined4 *)0x0) {
      iVar3 = _xdr_enum(param_1,param_2 + 3);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = _xdr_u_int(param_1,param_2 + 5);
      if (iVar3 == 0) {
        return 0;
      }
    }
    else {
      param_2[3] = *puVar2;
      param_2[5] = puVar2[1];
    }
    uVar1 = param_2[5];
    if (uVar1 != 0) {
      if (400 < uVar1) {
        return 0;
      }
      if (param_2[4] == 0) {
        uVar4 = _kalloc(uVar1);
        param_2[4] = uVar4;
      }
      iVar3 = (**(code **)(param_1[1] + 0x18))(param_1,param_2[5] + 3 & 0xfffffffc);
      if (iVar3 == 0) {
        iVar3 = _xdr_opaque(param_1,param_2[4],param_2[5]);
        if (iVar3 == 0) {
          return 0;
        }
      }
      else {
        _bcopy(iVar3,param_2[4],param_2[5]);
      }
    }
    iVar3 = _xdr_enum(param_1,param_2 + 6);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = param_2[6];
    if (iVar3 == 0) {
      uVar4 = (*(code *)param_2[8])(param_1,param_2[7]);
      return uVar4;
    }
    if (iVar3 != 2) {
      return 1;
    }
    iVar3 = _xdr_u_long(param_1,param_2 + 7);
  }
  if (iVar3 == 0) {
    return 0;
  }
  uVar4 = _xdr_u_long(param_1,param_2 + 8);
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=882 start=0x402f016 */

undefined4 _xdr_callhdr(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 8) = 2;
  if ((((*param_1 == 0) && (iVar1 = _xdr_u_long(param_1,param_2), iVar1 != 0)) &&
      (iVar1 = _xdr_enum(param_1,param_2 + 4), iVar1 != 0)) &&
     ((iVar1 = _xdr_u_long(param_1,param_2 + 8), iVar1 != 0 &&
      (iVar1 = _xdr_u_long(param_1,param_2 + 0xc), iVar1 != 0)))) {
    uVar2 = _xdr_u_long(param_1,param_2 + 0x10);
    return uVar2;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=883 start=0x402f126 */

void __seterr_reply(int param_1,uint *param_2)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    if (*(int *)(param_1 + 0x18) == 0) {
      *param_2 = 0;
      return;
    }
    sub_402F08A(*(int *)(param_1 + 0x18),param_2);
  }
  else if (*(int *)(param_1 + 8) == 1) {
    sub_402F0F2(*(undefined4 *)(param_1 + 0xc),param_2);
  }
  else {
    *param_2 = 0x10;
    param_2[1] = *(uint *)(param_1 + 8);
  }
  uVar1 = *param_2;
  if (uVar1 == 7) {
    param_2[1] = *(uint *)(param_1 + 0x10);
  }
  else if (uVar1 < 8) {
    if (uVar1 == 6) {
      param_2[1] = *(uint *)(param_1 + 0x10);
      param_2[2] = *(uint *)(param_1 + 0x14);
    }
  }
  else if (uVar1 == 9) {
    param_2[1] = *(uint *)(param_1 + 0x1c);
    param_2[2] = *(uint *)(param_1 + 0x20);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=884 start=0x402f1ba */

int * _ku_recvfrom(int param_1,undefined4 *param_2)

{
  int iVar1;
  sword sVar2;
  sword *psVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  
  psVar3 = (sword *)(param_1 + 0x22);
  iVar5 = 0;
  piVar4 = *(int **)(param_1 + 0x2e);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    iVar1 = piVar4[0x1f];
    puVar6 = (undefined4 *)(piVar4[1] + (int)piVar4);
    *param_2 = *puVar6;
    param_2[1] = puVar6[1];
    param_2[2] = puVar6[2];
    param_2[3] = puVar6[3];
    do {
      if (*(sword *)((int)piVar4 + 10) == 1) break;
      *psVar3 = *psVar3 - *(sword *)(piVar4 + 2);
      sVar2 = *(sword *)(param_1 + 0x26);
      *(sword *)(param_1 + 0x26) = sVar2 + -0x80;
      if (0x7c < (uint)piVar4[1]) {
        *(sword *)(param_1 + 0x26) = sVar2 + -0x480;
      }
      piVar4 = (int *)_m_free(piVar4);
    } while (piVar4 != (int *)0x0);
    piVar7 = piVar4;
    if (piVar4 == (int *)0x0) {
      _printf(aKuRecvfromNoBo);
      *(int *)(param_1 + 0x2e) = iVar1;
      piVar4 = (int *)0x0;
    }
    else {
      do {
        *psVar3 = *psVar3 - *(sword *)(piVar7 + 2);
        sVar2 = *(sword *)(param_1 + 0x26);
        *(sword *)(param_1 + 0x26) = sVar2 + -0x80;
        if (0x7c < (uint)piVar7[1]) {
          *(sword *)(param_1 + 0x26) = sVar2 + -0x480;
        }
        iVar5 = *(sword *)(piVar7 + 2) + iVar5;
        piVar7 = (int *)*piVar7;
      } while (piVar7 != (int *)0x0);
      *(int *)(param_1 + 0x2e) = iVar1;
      if (0x2260 < iVar5) {
        _printf(aKuRecvfromLenD,iVar5);
      }
    }
  }
  return piVar4;
}
/* GHIDRADEC_FUNCTION index=885 start=0x402f2a0 */

int _ku_sendto_mbuf(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = *(int *)(param_1 + 8);
  _Sendtries = _Sendtries + 1;
  iVar3 = _m_get(1,8);
  if (iVar3 == 0) {
    _m_freem(param_2);
    iVar4 = 0x37;
  }
  else {
    *(undefined2 *)(iVar3 + 8) = 0x10;
    puVar5 = (undefined4 *)(*(int *)(iVar3 + 4) + iVar3);
    *puVar5 = *param_3;
    puVar5[1] = param_3[1];
    puVar5[2] = param_3[2];
    puVar5[3] = param_3[3];
    uVar2 = *(undefined4 *)(iVar1 + 0x12);
    iVar4 = _in_pcbconnect(iVar1,iVar3);
    if (iVar4 == 0) {
      iVar4 = _udp_output(iVar1,param_2);
      _in_pcbdisconnect(iVar1);
      *(undefined4 *)(iVar1 + 0x12) = uVar2;
      _m_free(iVar3);
      _Sendok = _Sendok + 1;
    }
    else {
      _printf(aPcbsetaddrFail,iVar4);
      _m_freem(param_2);
      _m_free(iVar3);
    }
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=886 start=0x402f378 */

void _xprt_register(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=887 start=0x402f380 */

undefined4 _svc_register(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined auStack_8 [4];
  
  iVar1 = sub_402F42A(param_2,param_3,auStack_8);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)_kalloc(0x10);
    puVar2[1] = param_2;
    puVar2[2] = param_3;
    puVar2[3] = param_4;
    *puVar2 = dword_40B3596;
    dword_40B3596 = puVar2;
  }
  else if (param_4 != *(int *)(iVar1 + 0xc)) {
    return 0;
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=888 start=0x402f3e6 */

void _svc_unregister(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puStack_8;
  
  puVar1 = (undefined4 *)sub_402F42A(param_1,param_2,&puStack_8);
  if (puVar1 != (undefined4 *)0x0) {
    if (puStack_8 == (undefined4 *)0x0) {
      dword_40B3596 = *puVar1;
    }
    else {
      *puStack_8 = *puVar1;
    }
    *puVar1 = 0;
    _kfree(puVar1,0x10);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=889 start=0x402f468 */

void _svc_sendreply(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined auStack_34 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_30 = 1;
  uStack_2c = 0;
  uStack_28 = *(undefined4 *)(param_1 + 0x1e);
  uStack_24 = *(undefined4 *)(param_1 + 0x22);
  uStack_20 = *(undefined4 *)(param_1 + 0x26);
  uStack_1c = 0;
  uStack_18 = param_3;
  uStack_14 = param_2;
  (**(code **)(*(int *)(param_1 + 6) + 0xc))(param_1,auStack_34);
  return;
}
/* GHIDRADEC_FUNCTION index=890 start=0x402f4b0 */

void _svcerr_noproc(int param_1)

{
  undefined auStack_34 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uStack_30 = 1;
  uStack_2c = 0;
  uStack_28 = *(undefined4 *)(param_1 + 0x1e);
  uStack_24 = *(undefined4 *)(param_1 + 0x22);
  uStack_20 = *(undefined4 *)(param_1 + 0x26);
  uStack_1c = 3;
  (**(code **)(*(int *)(param_1 + 6) + 0xc))(param_1,auStack_34);
  return;
}
/* GHIDRADEC_FUNCTION index=891 start=0x402f4ee */

void _svcerr_decode(int param_1)

{
  undefined auStack_34 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uStack_30 = 1;
  uStack_2c = 0;
  uStack_28 = *(undefined4 *)(param_1 + 0x1e);
  uStack_24 = *(undefined4 *)(param_1 + 0x22);
  uStack_20 = *(undefined4 *)(param_1 + 0x26);
  uStack_1c = 4;
  (**(code **)(*(int *)(param_1 + 6) + 0xc))(param_1,auStack_34);
  return;
}
/* GHIDRADEC_FUNCTION index=892 start=0x402f52c */

void _svcerr_auth(int param_1,undefined4 param_2)

{
  undefined auStack_34 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_30 = 1;
  uStack_2c = 1;
  uStack_28 = 1;
  uStack_24 = param_2;
  (**(code **)(*(int *)(param_1 + 6) + 0xc))(param_1,auStack_34);
  return;
}
/* GHIDRADEC_FUNCTION index=893 start=0x402f55c */

void _svcerr_weakauth(undefined4 param_1)

{
  _svcerr_auth(param_1,5);
  return;
}
/* GHIDRADEC_FUNCTION index=894 start=0x402f572 */

void _svcerr_noprog(int param_1)

{
  undefined auStack_34 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uStack_30 = 1;
  uStack_2c = 0;
  uStack_28 = *(undefined4 *)(param_1 + 0x1e);
  uStack_24 = *(undefined4 *)(param_1 + 0x22);
  uStack_20 = *(undefined4 *)(param_1 + 0x26);
  uStack_1c = 1;
  (**(code **)(*(int *)(param_1 + 6) + 0xc))(param_1,auStack_34);
  return;
}
/* GHIDRADEC_FUNCTION index=895 start=0x402f5ae */

void _svcerr_progvers(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined auStack_34 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_30 = 1;
  uStack_2c = 0;
  uStack_28 = *(undefined4 *)(param_1 + 0x1e);
  uStack_24 = *(undefined4 *)(param_1 + 0x22);
  uStack_20 = *(undefined4 *)(param_1 + 0x26);
  uStack_1c = 2;
  uStack_18 = param_2;
  uStack_14 = param_3;
  (**(code **)(*(int *)(param_1 + 6) + 0xc))(param_1,auStack_34);
  return;
}
/* GHIDRADEC_FUNCTION index=896 start=0x402f5f8 */

void _svc_getreq(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 *puStack_44;
  undefined4 uStack_40;
  undefined4 *puStack_3c;
  int iStack_38;
  undefined auStack_34 [12];
  int iStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 *puStack_18;
  undefined4 uStack_14;
  undefined4 *puStack_c;
  
  if (_rqcred_head == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)_kalloc(0x4b0);
  }
  else {
    puVar4 = _rqcred_head;
    _rqcred_head = (undefined4 *)*_rqcred_head;
  }
  puStack_c = puVar4 + 100;
  puStack_3c = puVar4 + 200;
  puStack_18 = puVar4;
  do {
    iVar5 = (*(code *)**(undefined4 **)(param_1 + 6))(param_1,auStack_34);
    if (iVar5 != 0) {
      iStack_38 = param_1;
      iStack_54 = iStack_28;
      uStack_50 = uStack_24;
      uStack_4c = uStack_20;
      uStack_48 = uStack_1c;
      puStack_44 = puStack_18;
      uStack_40 = uStack_14;
      iVar5 = __authenticate(&iStack_54,auStack_34);
      if (iVar5 == 0) {
        bVar3 = false;
        uVar7 = 0xffffffff;
        uVar6 = 0;
        for (puVar1 = dword_40B3596; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
          if (iStack_54 == puVar1[1]) {
            uVar2 = puVar1[2];
            if (uStack_50 == uVar2) {
              (*(code *)puVar1[3])(&iStack_54,param_1);
              goto loc_402F72A;
            }
            bVar3 = true;
            if (uVar2 < uVar7) {
              uVar7 = uVar2;
            }
            if (uVar6 < uVar2) {
              uVar6 = uVar2;
            }
          }
        }
        if (bVar3) {
          _svcerr_progvers(param_1,uVar7,uVar6);
        }
        else {
          _svcerr_noprog(param_1);
        }
        (**(code **)(*(int *)(param_1 + 6) + 0x10))(param_1,0,0);
      }
      else {
        _svcerr_auth(param_1,iVar5);
      }
    }
loc_402F72A:
    iVar5 = (**(code **)(*(int *)(param_1 + 6) + 4))(param_1);
    if (iVar5 == 0) {
      (**(code **)(*(int *)(param_1 + 6) + 0x14))(param_1);
      goto loc_402F746;
    }
    if (iVar5 != 1) {
loc_402F746:
      *puVar4 = _rqcred_head;
      _rqcred_head = puVar4;
      return;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=897 start=0x402f75c */

void _svc_run(int *param_1)

{
  do {
    while (*(sword *)(*param_1 + 0x22) != 0) {
      _svc_getreq(param_1);
      _Rpccnt = _Rpccnt + 1;
    }
    _sbwait(*param_1 + 0x22);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=898 start=0x402f7a0 */

//Decompiler native message:  Marshaling error: Attribute metatype is not present
//Decompiling function: __authenticate @ 0x402f7a0
/* GHIDRADEC_FUNCTION index=899 start=0x402f7fa */

undefined4 __svcauth_null(void)

{
  return 0;
}

