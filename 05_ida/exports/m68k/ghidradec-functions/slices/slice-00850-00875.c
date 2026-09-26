/* GHIDRADEC_FUNCTION index=850 start=0x402da3a */

undefined4 _authkern_validate(void)

{
  return 1;
}
/* GHIDRADEC_FUNCTION index=851 start=0x402da44 */

undefined4 _authkern_refresh(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=852 start=0x402da4e */

void _authkern_destroy(undefined4 param_1)

{
  _kfree(param_1,0x28);
  return;
}
/* GHIDRADEC_FUNCTION index=853 start=0x402da64 */

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
/* GHIDRADEC_FUNCTION index=854 start=0x402daec */

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
/* GHIDRADEC_FUNCTION index=855 start=0x402dbd2 */

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
/* GHIDRADEC_FUNCTION index=856 start=0x402dbf2 */

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
/* GHIDRADEC_FUNCTION index=857 start=0x402dc16 */

void _clntkudp_realloc(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  _bcopy(*(undefined4 *)(iVar1 + 0x68),param_2,0x2260);
  _kfree(*(undefined4 *)(iVar1 + 0x68),0x2260);
  *(undefined4 *)(iVar1 + 0x68) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=858 start=0x402dc8a */

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
/* GHIDRADEC_FUNCTION index=859 start=0x402de2a */

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
/* GHIDRADEC_FUNCTION index=860 start=0x402de68 */

void _clntkudp_freecred(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  _crfree(*(undefined4 *)(iVar1 + 0x74));
  *(undefined4 *)(iVar1 + 0x74) = 0xefefefef;
  return;
}
/* GHIDRADEC_FUNCTION index=861 start=0x402de90 */

//Decompiler native message:  Marshaling error: Attribute metatype is not present
//Decompiling function: _clntkudp_callit_addr @ 0x402de90
/* GHIDRADEC_FUNCTION index=862 start=0x402e46c */

void _clntkudp_callit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  _clntkudp_callit_addr(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,0);
  return;
}
/* GHIDRADEC_FUNCTION index=863 start=0x402e49c */

void _ckuwakeup(uint *param_1)

{
  *param_1 = *param_1 | 1;
  _sbwakeup(param_1[5] + 0x22);
  return;
}
/* GHIDRADEC_FUNCTION index=864 start=0x402e4ba */

void _clntkudp_error(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  *param_2 = *(undefined4 *)(iVar1 + 0x28);
  param_2[1] = *(undefined4 *)(iVar1 + 0x2c);
  param_2[2] = *(undefined4 *)(iVar1 + 0x30);
  return;
}
/* GHIDRADEC_FUNCTION index=865 start=0x402e4da */

void _clntkudp_freeres(int param_1,code *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(int *)(param_1 + 8) + 0x34);
  *puVar1 = 2;
  (*param_2)(puVar1,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=866 start=0x402e4fe */

void _clntkudp_abort(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=867 start=0x402e506 */

undefined4 _clntkudp_control(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=868 start=0x402e510 */

void _clntkudp_destroy(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  _soclose(*(undefined4 *)(iVar1 + 0x14));
  _kfree(*(undefined4 *)(iVar1 + 0x68),0x2260);
  _kfree(iVar1,0x78);
  return;
}
/* GHIDRADEC_FUNCTION index=869 start=0x402e612 */

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
/* GHIDRADEC_FUNCTION index=870 start=0x402e652 */

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
/* GHIDRADEC_FUNCTION index=871 start=0x402e750 */

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
/* GHIDRADEC_FUNCTION index=872 start=0x402e804 */

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
/* GHIDRADEC_FUNCTION index=873 start=0x402e858 */

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
/* GHIDRADEC_FUNCTION index=874 start=0x402e92c */

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

