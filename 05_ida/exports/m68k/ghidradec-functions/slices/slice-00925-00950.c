/* GHIDRADEC_FUNCTION index=925 start=0x403032a */

int _xdr_array(int *param_1,int *param_2,uint *param_3,uint param_4,int param_5,code *param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  undefined *puVar7;
  
  iVar3 = *param_2;
  iVar5 = 1;
  iVar2 = _xdr_u_int(param_1,param_3);
  if (iVar2 == 0) {
    puVar7 = aXdrArraySizeFa;
  }
  else {
    uVar1 = *param_3;
    if ((uVar1 <= param_4) || (*param_1 == 2)) {
      iVar2 = param_5 * uVar1;
      if (iVar3 == 0) {
        if (*param_1 == 1) {
          if (uVar1 == 0) {
            return 1;
          }
          iVar3 = _kalloc(iVar2);
          *param_2 = iVar3;
          _bzero(iVar3,iVar2);
        }
        else if (*param_1 == 2) {
          return 1;
        }
      }
      uVar4 = 0;
      if (uVar1 != 0) {
        do {
          bVar6 = iVar5 == 0;
          iVar5 = 0;
          if (bVar6) break;
          iVar5 = (*param_6)(param_1,iVar3,0xffffffff);
          iVar3 = param_5 + iVar3;
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar1);
      }
      if (*param_1 == 2) {
        _kfree(*param_2,iVar2);
        *param_2 = 0;
        return iVar5;
      }
      return iVar5;
    }
    puVar7 = aXdrArrayBadSiz;
  }
  _printf(puVar7);
  return 0;
}
/* GHIDRADEC_FUNCTION index=926 start=0x40303fc */

void _xdrmbuf_init(undefined4 *param_1,int param_2,undefined4 param_3)

{
  *param_1 = param_3;
  param_1[1] = _xdrmbuf_ops;
  param_1[4] = param_2;
  param_1[3] = *(int *)(param_2 + 4) + param_2;
  param_1[2] = 0;
  param_1[5] = (int)*(sword *)(param_2 + 8);
  return;
}
/* GHIDRADEC_FUNCTION index=927 start=0x4030432 */

void _xdrmbuf_destroy(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=928 start=0x403043a */

undefined4 _xdrmbuf_getlong(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x14) + -4;
  *(int *)(param_1 + 0x14) = iVar1;
  if (iVar1 < 0) {
    if (iVar1 != -4) {
      _printf(aXdrMbufLongCro);
    }
    if (*(int **)(param_1 + 0x10) != (int *)0x0) {
      iVar1 = **(int **)(param_1 + 0x10);
      *(int *)(param_1 + 0x10) = iVar1;
      if (iVar1 != 0) {
        *(int *)(param_1 + 0xc) = *(int *)(iVar1 + 4) + iVar1;
        *(int *)(param_1 + 0x14) = *(sword *)(iVar1 + 8) + -4;
        goto loc_4030490;
      }
    }
    uVar2 = 0;
  }
  else {
loc_4030490:
    *param_2 = **(undefined4 **)(param_1 + 0xc);
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 4;
    uVar2 = 1;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=929 start=0x40304a8 */

undefined4 _xdrmbuf_putlong(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x14) + -4;
  *(int *)(param_1 + 0x14) = iVar1;
  if (iVar1 < 0) {
    if (iVar1 != -4) {
      _printf(aXdrMbufPutlong);
    }
    if (*(int **)(param_1 + 0x10) != (int *)0x0) {
      iVar1 = **(int **)(param_1 + 0x10);
      *(int *)(param_1 + 0x10) = iVar1;
      if (iVar1 != 0) {
        *(int *)(param_1 + 0xc) = *(int *)(iVar1 + 4) + iVar1;
        *(int *)(param_1 + 0x14) = *(sword *)(iVar1 + 8) + -4;
        goto loc_40304FE;
      }
    }
    uVar2 = 0;
  }
  else {
loc_40304FE:
    **(undefined4 **)(param_1 + 0xc) = *param_2;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 4;
    uVar2 = 1;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=930 start=0x4030516 */

undefined4 _xdrmbuf_getbytes(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  while( true ) {
    iVar1 = *(int *)(param_1 + 0x14) - param_3;
    *(int *)(param_1 + 0x14) = iVar1;
    if (-1 < iVar1) {
      _bcopy(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
      *(int *)(param_1 + 0xc) = param_3 + *(int *)(param_1 + 0xc);
      return 1;
    }
    iVar1 = param_3 + *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1;
    if (0 < iVar1) {
      _bcopy(*(undefined4 *)(param_1 + 0xc),param_2,iVar1);
      param_2 = *(int *)(param_1 + 0x14) + param_2;
      param_3 = param_3 - *(int *)(param_1 + 0x14);
    }
    if (*(int **)(param_1 + 0x10) == (int *)0x0) break;
    iVar1 = **(int **)(param_1 + 0x10);
    *(int *)(param_1 + 0x10) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
    *(int *)(param_1 + 0xc) = *(int *)(iVar1 + 4) + iVar1;
    *(int *)(param_1 + 0x14) = (int)*(sword *)(iVar1 + 8);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=931 start=0x40305a2 */

undefined4 _xdrmbuf_getmbuf(int param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = _xdr_u_int(param_1,param_3);
  if (iVar2 != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0x10);
    iVar2 = (int)*(sword *)(puVar1 + 2) - *(int *)(param_1 + 0x14);
    puVar1[1] = iVar2 + puVar1[1];
    *(sword *)(puVar1 + 2) = *(sword *)(puVar1 + 2) - (sword)iVar2;
    *param_2 = puVar1;
    uVar3 = 0;
    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      uVar3 = (int)*(sword *)(puVar1 + 2) + uVar3;
    }
    if (*param_3 <= uVar3) {
      return 1;
    }
    _printf(aXdrmbufGetmbuf);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=932 start=0x4030610 */

undefined4 _xdrmbuf_putbytes(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  while( true ) {
    iVar1 = *(int *)(param_1 + 0x14) - param_3;
    *(int *)(param_1 + 0x14) = iVar1;
    if (-1 < iVar1) {
      _bcopy(param_2,*(undefined4 *)(param_1 + 0xc),param_3);
      *(int *)(param_1 + 0xc) = param_3 + *(int *)(param_1 + 0xc);
      return 1;
    }
    iVar1 = param_3 + *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1;
    if (0 < iVar1) {
      _bcopy(param_2,*(undefined4 *)(param_1 + 0xc),iVar1);
      param_2 = *(int *)(param_1 + 0x14) + param_2;
      param_3 = param_3 - *(int *)(param_1 + 0x14);
    }
    if (*(int **)(param_1 + 0x10) == (int *)0x0) break;
    iVar1 = **(int **)(param_1 + 0x10);
    *(int *)(param_1 + 0x10) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
    *(int *)(param_1 + 0xc) = *(int *)(iVar1 + 4) + iVar1;
    *(int *)(param_1 + 0x14) = (int)*(sword *)(iVar1 + 8);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=933 start=0x403069c */

undefined4
_xdrmbuf_putbuf(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  sword *psVar1;
  int iVar2;
  uint uStack_8;
  
  uStack_8 = param_3;
  if (((param_3 & 3) == 0) && (iVar2 = _xdrmbuf_putlong(param_1,&uStack_8), iVar2 != 0)) {
    psVar1 = (sword *)(*(int *)(param_1 + 0x10) + 8);
    *psVar1 = *psVar1 - *(sword *)(param_1 + 0x16);
    iVar2 = _mclgetx(param_4,param_5,param_2,param_3,1);
    if (iVar2 != 0) {
      **(int **)(param_1 + 0x10) = iVar2;
      *(undefined4 *)(param_1 + 0x14) = 0;
      return 1;
    }
    _printf(aXdrmbufPutbufM);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=934 start=0x403071c */

int _xdrmbuf_getpos(int param_1)

{
  return *(int *)(param_1 + 0xc) -
         (*(int *)(*(int *)(param_1 + 0x10) + 4) + *(int *)(param_1 + 0x10));
}
/* GHIDRADEC_FUNCTION index=935 start=0x4030736 */

bool _xdrmbuf_setpos(int param_1,int param_2)

{
  int iVar1;
  
  param_2 = param_2 + *(int *)(*(int *)(param_1 + 0x10) + 4) + *(int *)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc);
  if (param_2 <= iVar1) {
    *(int *)(param_1 + 0xc) = param_2;
    *(int *)(param_1 + 0x14) = iVar1 - param_2;
  }
  return param_2 <= iVar1;
}
/* GHIDRADEC_FUNCTION index=936 start=0x403076c */

int _xdrmbuf_inline(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 <= *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - param_2;
    iVar1 = *(int *)(param_1 + 0xc);
    *(int *)(param_1 + 0xc) = iVar1 + param_2;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=937 start=0x4030796 */

void _xdrmem_create(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = param_4;
  param_1[1] = DAT_40af08e;
  param_1[4] = param_2;
  param_1[3] = param_2;
  param_1[5] = param_3;
  return;
}
/* GHIDRADEC_FUNCTION index=938 start=0x403091e */

undefined4 _xdr_reference(int *param_1,int *param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_2;
  if (iVar1 == 0) {
    if (*param_1 == 1) {
      iVar1 = _kalloc(param_3);
      *param_2 = iVar1;
      _bzero(iVar1,param_3);
    }
    else if (*param_1 == 2) {
      return 1;
    }
  }
  uVar2 = (*param_4)(param_1,iVar1,0xffffffff);
  if (*param_1 == 2) {
    _kfree(iVar1,param_3);
    *param_2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=939 start=0x4030994 */

bool _xdr_bp_machine_name_t(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _xdr_string(param_1,param_2,0xff);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=940 start=0x40309b8 */

bool _xdr_bp_path_t(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _xdr_string(param_1,param_2,0x400);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=941 start=0x40309dc */

bool _xdr_bp_fileid_t(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _xdr_string(param_1,param_2,0x20);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=942 start=0x4030a00 */

undefined4 _xdr_ip_addr_t(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_char(param_1,param_2);
  if (((iVar1 != 0) && (iVar1 = _xdr_char(param_1,param_2 + 1), iVar1 != 0)) &&
     (iVar1 = _xdr_char(param_1,param_2 + 2), iVar1 != 0)) {
    iVar1 = _xdr_char(param_1,param_2 + 3);
    if (iVar1 == 0) {
      return 0;
    }
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=943 start=0x4030a5e */

bool _xdr_bp_address(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_union(param_1,param_2,param_2 + 4,unk_40AF0AE,0);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=944 start=0x4030a8c */

bool _xdr_bp_whoami_arg(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _xdr_bp_address(param_1,param_2);
  return iVar1 != 0;
}
/* GHIDRADEC_FUNCTION index=945 start=0x4030aac */

undefined4 _xdr_bp_whoami_res(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_bp_machine_name_t(param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = _xdr_bp_machine_name_t(param_1,param_2 + 4), iVar1 != 0)) {
    iVar1 = _xdr_bp_address(param_1,param_2 + 8);
    if (iVar1 == 0) {
      return 0;
    }
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=946 start=0x4030b00 */

undefined4 _xdr_bp_getfile_arg(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _xdr_bp_machine_name_t(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = _xdr_bp_fileid_t(param_1,param_2 + 4);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=947 start=0x4030b46 */

undefined4 _xdr_bp_getfile_res(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_bp_machine_name_t(param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = _xdr_bp_address(param_1,param_2 + 4), iVar1 != 0)) {
    iVar1 = _xdr_bp_path_t(param_1,param_2 + 0xc);
    if (iVar1 == 0) {
      return 0;
    }
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=948 start=0x4030b9e */

undefined4 _xdr_fhstatus(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _xdr_int(param_1,param_2);
  if (iVar1 == 0) {
loc_4030BD2:
    uVar2 = 0;
  }
  else {
    if (*param_2 == 0) {
      iVar1 = _xdr_fhandle(param_1,param_2 + 1);
      if (iVar1 == 0) goto loc_4030BD2;
    }
    uVar2 = 1;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=949 start=0x403154c */

int _fifosp(int param_1)

{
  int iVar1;
  undefined auStack_3e [28];
  undefined4 uStack_22;
  undefined4 uStack_1e;
  undefined4 uStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  
  iVar1 = _kalloc(0x8a);
  _bzero(iVar1,0x8a);
  *(undefined **)(iVar1 + 0x20) = _fifo_vnodeops;
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
            (param_1,auStack_3e,*(undefined4 *)(_active_u + 0x1a));
  *(undefined4 *)(iVar1 + 0x4a) = uStack_22;
  *(undefined4 *)(iVar1 + 0x4e) = uStack_1e;
  *(undefined4 *)(iVar1 + 0x52) = uStack_1a;
  *(undefined4 *)(iVar1 + 0x56) = uStack_16;
  *(undefined4 *)(iVar1 + 0x5a) = uStack_12;
  *(undefined4 *)(iVar1 + 0x5e) = uStack_e;
  return iVar1;
}

