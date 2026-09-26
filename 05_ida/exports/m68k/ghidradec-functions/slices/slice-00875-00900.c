/* GHIDRADEC_FUNCTION index=875 start=0x402e990 */

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
/* GHIDRADEC_FUNCTION index=876 start=0x402ec64 */

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
/* GHIDRADEC_FUNCTION index=877 start=0x402eca8 */

void _xdr_des_block(undefined4 param_1,undefined4 param_2)

{
  _xdr_opaque(param_1,param_2,8);
  return;
}
/* GHIDRADEC_FUNCTION index=878 start=0x402ecc2 */

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
/* GHIDRADEC_FUNCTION index=879 start=0x402ed3e */

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
/* GHIDRADEC_FUNCTION index=880 start=0x402ed9c */

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
/* GHIDRADEC_FUNCTION index=881 start=0x402f016 */

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
/* GHIDRADEC_FUNCTION index=882 start=0x402f126 */

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
/* GHIDRADEC_FUNCTION index=883 start=0x402f1ba */

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
/* GHIDRADEC_FUNCTION index=884 start=0x402f2a0 */

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
/* GHIDRADEC_FUNCTION index=885 start=0x402f378 */

void _xprt_register(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=886 start=0x402f380 */

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
/* GHIDRADEC_FUNCTION index=887 start=0x402f3e6 */

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
/* GHIDRADEC_FUNCTION index=888 start=0x402f468 */

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
/* GHIDRADEC_FUNCTION index=889 start=0x402f4b0 */

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
/* GHIDRADEC_FUNCTION index=890 start=0x402f4ee */

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
/* GHIDRADEC_FUNCTION index=891 start=0x402f52c */

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
/* GHIDRADEC_FUNCTION index=892 start=0x402f55c */

void _svcerr_weakauth(undefined4 param_1)

{
  _svcerr_auth(param_1,5);
  return;
}
/* GHIDRADEC_FUNCTION index=893 start=0x402f572 */

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
/* GHIDRADEC_FUNCTION index=894 start=0x402f5ae */

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
/* GHIDRADEC_FUNCTION index=895 start=0x402f5f8 */

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
/* GHIDRADEC_FUNCTION index=896 start=0x402f75c */

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
/* GHIDRADEC_FUNCTION index=897 start=0x402f7a0 */

//Decompiler native message:  Marshaling error: Attribute metatype is not present
//Decompiling function: __authenticate @ 0x402f7a0
/* GHIDRADEC_FUNCTION index=898 start=0x402f7fa */

undefined4 __svcauth_null(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=899 start=0x402f804 */

undefined4 __svcauth_unix(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uStack_1c;
  int iStack_18;
  
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  puVar1[1] = puVar1 + 6;
  puVar1[5] = puVar1 + 0x46;
  uVar2 = *(uint *)(param_2 + 0x20);
  _xdrmem_create(&uStack_1c,*(undefined4 *)(param_2 + 0x1c),uVar2,1);
  puVar3 = (undefined4 *)(**(code **)(iStack_18 + 0x18))(&uStack_1c,uVar2);
  if (puVar3 == (undefined4 *)0x0) {
    iVar6 = _xdr_authunix_parms(&uStack_1c,puVar1);
    if (iVar6 == 0) {
      uStack_1c = 2;
      _xdr_authunix_parms(&uStack_1c,puVar1);
      uVar7 = 1;
      goto loc_402F926;
    }
loc_402F912:
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x1e) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x26) = 0;
    uVar7 = 0;
  }
  else {
    *puVar1 = *puVar3;
    iVar6 = puVar3[1];
    if (iVar6 < 0x100) {
      _bcopy(puVar3 + 2,puVar1[1],iVar6);
      *(undefined *)(iVar6 + puVar1[1]) = 0;
      uVar4 = iVar6 + 3;
      if ((int)uVar4 < 0) {
        uVar4 = iVar6 + 6;
      }
      puVar3 = (undefined4 *)((uVar4 & 0xfffffffc) + (int)(puVar3 + 2));
      puVar1[2] = *puVar3;
      puVar1[3] = puVar3[1];
      iVar6 = puVar3[2];
      if (iVar6 < 0x11) {
        puVar1[4] = iVar6;
        iVar5 = 0;
        puVar3 = puVar3 + 3;
        if (0 < iVar6) {
          do {
            *(undefined4 *)(puVar1[5] + iVar5 * 4) = *puVar3;
            iVar5 = iVar5 + 1;
            puVar3 = puVar3 + 1;
          } while (iVar5 < iVar6);
        }
        if (uVar2 < (uVar4 & 0xfffffffc) + 0x14 + iVar6 * 4) {
          _printf(aBadAuthLenGidD,iVar6,uVar2,uVar2);
          uVar7 = 1;
          goto loc_402F926;
        }
        goto loc_402F912;
      }
    }
    uVar7 = 1;
  }
loc_402F926:
  (**(code **)(iStack_18 + 0x1c))(&uStack_1c);
  return uVar7;
}

