/* GHIDRADEC_FUNCTION index=900 start=0x402f940 */

undefined4 __svcauth_short(void)

{
  return 2;
}
/* GHIDRADEC_FUNCTION index=901 start=0x402f94a */

undefined4 * _svckudp_create(undefined4 param_1,undefined2 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)_kalloc(0x32);
  uVar2 = _kalloc(0x2260);
  *(undefined4 *)((int)puVar1 + 0x2a) = uVar2;
  iVar3 = _kalloc(0x1cc);
  _bzero(iVar3,0x1cc);
  *(undefined4 *)((int)puVar1 + 10) = 0;
  *(int *)((int)puVar1 + 0x2e) = iVar3;
  *(int *)((int)puVar1 + 0x22) = iVar3 + 0x3c;
  *(undefined **)((int)puVar1 + 6) = _svckudp_op;
  *(undefined2 *)(puVar1 + 1) = param_2;
  *puVar1 = param_1;
  _xprt_register(puVar1);
  return puVar1;
}
/* GHIDRADEC_FUNCTION index=902 start=0x402f9b8 */

void _svckudp_destroy(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  iVar2 = *(int *)(iVar1 + 8);
  if (iVar2 != 0) {
    _m_freem(iVar2);
  }
  _kfree(iVar1,0x1cc);
  _kfree(*(undefined4 *)(param_1 + 0x2a),0x2260);
  _kfree(param_1,0x32);
  return;
}
/* GHIDRADEC_FUNCTION index=903 start=0x402fa04 */

undefined4 _svckudp_recv(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)((int)param_1 + 0x2e);
  _rsstat = _rsstat + 1;
  iVar2 = _ku_recvfrom(*param_1,(int)param_1 + 0xe);
  if (iVar2 == 0) {
    dword_40BC1F4 = dword_40BC1F4 + 1;
  }
  else {
    if (*(word *)(iVar2 + 8) < 0x10) {
      dword_40BC1F8 = dword_40BC1F8 + 1;
    }
    else {
      _xdrmbuf_init(iVar1 + 0xc,iVar2,1);
      iVar3 = _xdr_callmsg(iVar1 + 0xc,param_2);
      if (iVar3 != 0) {
        *(undefined4 *)(iVar1 + 4) = *param_2;
        *(int *)(iVar1 + 8) = iVar2;
        return 1;
      }
      dword_40BC1FC = dword_40BC1FC + 1;
    }
    _m_freem(iVar2);
    *(undefined4 *)(iVar1 + 8) = 0;
    dword_40BC1F0 = dword_40BC1F0 + 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=904 start=0x402fad2 */

undefined4 _svckudp_send(undefined4 *param_1,uint *param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  
  puVar1 = *(uint **)((int)param_1 + 0x2e);
  uVar6 = 0;
  while ((*puVar1 & 1) != 0) {
    *puVar1 = *puVar1 | 2;
    _sleep(puVar1,0x17);
  }
  *puVar1 = *puVar1 | 1;
  piVar3 = (int *)_mclgetx(sub_402FAAA,puVar1,*(undefined4 *)((int)param_1 + 0x2a),0x2260,1);
  if (piVar3 == (int *)0x0) {
    sub_402FAAA(puVar1);
  }
  else {
    _xdrmbuf_init(puVar1 + 9,piVar3,0);
    *param_2 = puVar1[1];
    iVar4 = _xdr_replymsg(puVar1 + 9,param_2);
    if (iVar4 == 0) {
      _printf(aSvckudpSendXdr);
      _m_freem(piVar3);
    }
    else {
      uVar5 = (**(code **)(puVar1[10] + 0x10))(puVar1 + 9);
      if (*piVar3 == 0) {
        *(undefined2 *)(piVar3 + 2) = uVar5;
      }
      iVar4 = _ku_sendto_mbuf(*param_1,piVar3,(int)param_1 + 0xe);
      if (iVar4 == 0) {
        uVar6 = 1;
      }
    }
    puVar2 = (undefined4 *)puVar1[0xb];
    if (puVar2 != (undefined4 *)0x0) {
      (*(code *)*puVar2)(puVar2);
    }
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=905 start=0x402fbd0 */

undefined4 _svckudp_stat(void)

{
  return 2;
}
/* GHIDRADEC_FUNCTION index=906 start=0x402fbda */

void _svckudp_getargs(int param_1,code *param_2,undefined4 param_3)

{
  (*param_2)(*(int *)(param_1 + 0x2e) + 0xc,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=907 start=0x402fbf8 */

undefined4 _svckudp_freeargs(int param_1,code *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  if (*(int *)(iVar1 + 8) != 0) {
    _m_freem(*(int *)(iVar1 + 8));
  }
  *(undefined4 *)(iVar1 + 8) = 0;
  if (param_3 == 0) {
    uVar2 = 1;
  }
  else {
    *(undefined4 *)(iVar1 + 0xc) = 2;
    uVar2 = (*param_2)((undefined4 *)(iVar1 + 0xc),param_3);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=908 start=0x402fc44 */

void _svckudp_dupsave(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  
  if (_ndupreqs < 400) {
    puVar2 = (uint *)_kalloc(0x28);
    if (_drmru == (uint *)0x0) {
      puVar2[8] = (uint)puVar2;
    }
    else {
      puVar2[8] = *(uint *)((int)_drmru + 0x20);
      *(uint **)((int)_drmru + 0x20) = puVar2;
    }
    _ndupreqs = _ndupreqs + 1;
  }
  else {
    puVar2 = *(uint **)((int)_drmru + 0x20);
    sub_402FD84(puVar2);
  }
  _drmru = puVar2;
  *puVar2 = *(uint *)(*(int *)(param_1[7] + 0x2e) + 4);
  puVar2[7] = *param_1;
  puVar2[6] = param_1[1];
  puVar2[5] = param_1[2];
  uVar1 = param_1[7];
  puVar2[1] = *(uint *)(uVar1 + 0xe);
  puVar2[2] = *(uint *)(uVar1 + 0x12);
  puVar2[3] = *(uint *)(uVar1 + 0x16);
  puVar2[4] = *(uint *)(uVar1 + 0x1a);
  puVar2[9] = *(uint *)(_drhashtbl + (*puVar2 & 0x1f) * 4);
  *(uint **)(_drhashtbl + (*puVar2 & 0x1f) * 4) = puVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=909 start=0x402fcfa */

undefined4 _svckudp_dup(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  _dupchecks = _dupchecks + 1;
  uVar1 = *(uint *)(*(int *)(param_1[7] + 0x2e) + 4);
  puVar3 = *(uint **)(_drhashtbl + (uVar1 & 0x1f) * 4);
  while( true ) {
    if (puVar3 == (uint *)0x0) {
      return 0;
    }
    if ((((uVar1 == *puVar3) && (puVar3[7] == *param_1)) && (puVar3[6] == param_1[1])) &&
       ((puVar3[5] == param_1[2] && (iVar2 = _bcmp(puVar3 + 1,param_1[7] + 0xe,0x10), iVar2 == 0))))
    break;
    puVar3 = (uint *)puVar3[9];
  }
  _dupreqs = _dupreqs + 1;
  return 1;
}
/* GHIDRADEC_FUNCTION index=910 start=0x402fdd6 */

undefined4 _xdr_void(void)

{
  return 1;
}
/* GHIDRADEC_FUNCTION index=911 start=0x402fde0 */

void _xdr_int(undefined4 param_1,undefined4 param_2)

{
  _xdr_long(param_1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=912 start=0x402fdf6 */

void _xdr_u_int(undefined4 param_1,undefined4 param_2)

{
  _xdr_u_long(param_1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=913 start=0x402fe0c */

undefined4 _xdr_long(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    uVar2 = (**(code **)(param_1[1] + 4))(param_1,param_2);
  }
  else if (iVar1 == 1) {
    uVar2 = (**(code **)param_1[1])(param_1,param_2);
  }
  else if (iVar1 == 2) {
    uVar2 = 1;
  }
  else {
    _printf(aXdrLongFailed);
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=914 start=0x402fe62 */

undefined4 _xdr_u_long(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 1) {
    uVar2 = (**(code **)param_1[1])(param_1,param_2);
  }
  else if (iVar1 == 0) {
    uVar2 = (**(code **)(param_1[1] + 4))(param_1,param_2);
  }
  else if (iVar1 == 2) {
    uVar2 = 1;
  }
  else {
    _printf(aXdrULongFailed);
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=915 start=0x402feba */

undefined4 _xdr_short(int *param_1,sword *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_8;
  
  iVar2 = *param_1;
  if (iVar2 == 1) {
    iVar2 = (**(code **)param_1[1])(param_1,&uStack_8);
    if (iVar2 != 0) {
      *param_2 = uStack_8._2_2_;
      return 1;
    }
  }
  else {
    if (iVar2 == 0) {
      uStack_8 = (int)*param_2;
      uVar1 = (**(code **)(param_1[1] + 4))(param_1,&uStack_8);
      return uVar1;
    }
    if (iVar2 == 2) {
      return 1;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=916 start=0x402ff16 */

undefined4 _xdr_u_short(int *param_1,word *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uStack_8;
  
  iVar2 = *param_1;
  if (iVar2 == 1) {
    iVar2 = (**(code **)param_1[1])(param_1,&uStack_8);
    if (iVar2 != 0) {
      *param_2 = uStack_8._2_2_;
      return 1;
    }
    puVar3 = aXdrUShortDecod;
  }
  else {
    if (iVar2 == 0) {
      uStack_8 = (uint)*param_2;
      uVar1 = (**(code **)(param_1[1] + 4))(param_1,&uStack_8);
      return uVar1;
    }
    if (iVar2 == 2) {
      return 1;
    }
    puVar3 = aXdrUShortBadOp;
  }
  _printf(puVar3);
  return 0;
}
/* GHIDRADEC_FUNCTION index=917 start=0x402ff8c */

bool _xdr_char(undefined4 param_1,char *param_2)

{
  int iVar1;
  undefined4 uStack_8;
  
  uStack_8 = (int)*param_2;
  iVar1 = _xdr_int(param_1,&uStack_8);
  if (iVar1 != 0) {
    *param_2 = (char)uStack_8;
  }
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=918 start=0x402ffc2 */

undefined4 _xdr_bool(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  int iStack_8;
  
  iVar2 = *param_1;
  if (iVar2 == 1) {
    iVar2 = (**(code **)param_1[1])(param_1,&iStack_8);
    if (iVar2 != 0) {
      *param_2 = -(int)-(iStack_8 != 0);
      return 1;
    }
    puVar3 = aXdrBoolDecodeF;
  }
  else {
    if (iVar2 == 0) {
      iStack_8 = -(int)-(*param_2 != 0);
      uVar1 = (**(code **)(param_1[1] + 4))(param_1,&iStack_8);
      return uVar1;
    }
    if (iVar2 == 2) {
      return 1;
    }
    puVar3 = aXdrBoolBadOpFa;
  }
  _printf(puVar3);
  return 0;
}
/* GHIDRADEC_FUNCTION index=919 start=0x4030042 */

void _xdr_enum(undefined4 param_1,undefined4 param_2)

{
  _xdr_long(param_1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=920 start=0x4030058 */

undefined4 _xdr_opaque(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  if (param_3 != 0) {
    iVar3 = 0;
    if ((param_3 & 3) != 0) {
      iVar3 = 4 - (param_3 & 3);
    }
    iVar1 = *param_1;
    if (iVar1 == 1) {
      iVar1 = (**(code **)(param_1[1] + 8))(param_1,param_2,param_3);
      if (iVar1 == 0) {
        puVar4 = aXdrOpaqueDecod;
        goto loc_4030108;
      }
      if (iVar3 != 0) {
        uVar2 = (**(code **)(param_1[1] + 8))(param_1,unk_40B359A,iVar3);
        return uVar2;
      }
    }
    else if (iVar1 == 0) {
      iVar1 = (**(code **)(param_1[1] + 0xc))(param_1,param_2,param_3);
      if (iVar1 == 0) {
        puVar4 = aXdrOpaqueEncod;
loc_4030108:
        _printf(puVar4);
        return 0;
      }
      if (iVar3 != 0) {
        uVar2 = (**(code **)(param_1[1] + 0xc))(param_1,&unk_40AF06A,iVar3);
        return uVar2;
      }
    }
    else if (iVar1 != 2) {
      puVar4 = aXdrOpaqueBadOp;
      goto loc_4030108;
    }
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=921 start=0x403011e */

undefined4 _xdr_bytes(int *param_1,int *param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  
  iVar3 = *param_2;
  iVar2 = _xdr_u_int(param_1,param_3);
  if (iVar2 == 0) {
    puVar5 = aXdrBytesSizeFa;
  }
  else {
    uVar1 = *param_3;
    if ((uVar1 <= param_4) || (*param_1 == 2)) {
      iVar2 = *param_1;
      if (iVar2 == 1) {
        if (uVar1 == 0) {
          return 1;
        }
        if (iVar3 == 0) {
          iVar3 = _kalloc(uVar1);
          *param_2 = iVar3;
        }
      }
      else if (iVar2 != 0) {
        if (iVar2 == 2) {
          if (iVar3 == 0) {
            return 1;
          }
          _kfree(iVar3,uVar1);
          *param_2 = 0;
          return 1;
        }
        puVar5 = aXdrBytesBadOpF;
        goto loc_40301B4;
      }
      uVar4 = _xdr_opaque(param_1,iVar3,uVar1);
      return uVar4;
    }
    puVar5 = aXdrBytesBadSiz;
  }
loc_40301B4:
  _printf(puVar5);
  return 0;
}
/* GHIDRADEC_FUNCTION index=922 start=0x40301c6 */

void _xdr_netobj(undefined4 param_1,int param_2)

{
  _xdr_bytes(param_1,param_2 + 4,param_2,0x400);
  return;
}
/* GHIDRADEC_FUNCTION index=923 start=0x40301e6 */

undefined4 _xdr_union(undefined4 param_1,int *param_2,undefined4 param_3,int *param_4,code *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _xdr_enum(param_1,param_2);
  if (iVar1 == 0) {
    _printf(aXdrEnumDscmpFa);
    uVar2 = 0;
  }
  else {
    iVar1 = param_4[1];
    while (iVar1 != 0) {
      if (*param_2 == *param_4) {
        uVar2 = (*(code *)param_4[1])(param_1,param_3,0xffffffff);
        return uVar2;
      }
      iVar1 = param_4[3];
      param_4 = param_4 + 2;
    }
    if (param_5 == (code *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (*param_5)(param_1,param_3,0xffffffff);
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=924 start=0x4030262 */

undefined4 _xdr_string(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  uint uStack_8;
  
  iVar2 = *param_2;
  if (*param_1 == 0) {
loc_4030288:
    uStack_8 = _strlen(iVar2);
  }
  else if (*param_1 == 2) {
    if (iVar2 == 0) {
      return 1;
    }
    goto loc_4030288;
  }
  iVar1 = _xdr_u_int(param_1,&uStack_8);
  if (iVar1 == 0) {
    puVar4 = aXdrStringSizeF;
  }
  else {
    if (uStack_8 <= param_3) {
      iVar1 = *param_1;
      if (iVar1 == 1) {
        if (iVar2 == 0) {
          iVar2 = _kalloc(uStack_8 + 1);
          *param_2 = iVar2;
        }
        *(undefined *)(iVar2 + uStack_8) = 0;
      }
      else if (iVar1 != 0) {
        if (iVar1 == 2) {
          _kfree(iVar2,uStack_8 + 1);
          *param_2 = 0;
          return 1;
        }
        puVar4 = aXdrStringBadOp;
        goto loc_4030318;
      }
      uVar3 = _xdr_opaque(param_1,iVar2,uStack_8);
      return uVar3;
    }
    puVar4 = aXdrStringBadSi;
  }
loc_4030318:
  _printf(puVar4);
  return 0;
}

