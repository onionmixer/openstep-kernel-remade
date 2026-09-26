/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001353b0 */

int _clntkudp_create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  boolean_t bVar4;
  char *pcVar5;
  undefined1 local_3c [4];
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  *(undefined4 *)(_active_threads + 0x188) = 1;
  pvVar1 = (void *)_kalloc(0x78);
  _bzero(pvVar1,0x78);
  if (_clntkudpxid == 0) {
    _getthetime(local_3c);
    _clntkudpxid = local_38;
  }
  *(undefined ***)((int)pvVar1 + 8) = &_udp_ops;
  *(void **)((int)pvVar1 + 0xc) = pvVar1;
  uVar2 = _authkern_create();
  *(undefined4 *)((int)pvVar1 + 4) = uVar2;
  local_34 = 0;
  local_30 = 0;
  local_2c = 2;
  local_28 = param_2;
  local_24 = param_3;
  _clntkudp_init((int)pvVar1 + 4,param_1,param_4,param_5);
  uVar2 = _kalloc(0x2260);
  *(undefined4 *)((int)pvVar1 + 0x68) = uVar2;
  iVar3 = _mclgetx(FUN_00135d8c,0,uVar2,0x2260,1);
  if (iVar3 != 0) {
    _xdrmbuf_init((int)pvVar1 + 0x34,iVar3,0);
    bVar4 = _xdr_callhdr();
    if (bVar4 == 0) {
      _printf(s_clntkudp_create___Fatal_header_s_001dcddc);
      _m_freem(iVar3);
    }
    else {
      uVar2 = (**(code **)(*(int *)((int)pvVar1 + 0x38) + 0x10))((int)pvVar1 + 0x34);
      *(undefined4 *)((int)pvVar1 + 100) = uVar2;
      _m_free(iVar3);
      iVar3 = _socreate(2,(int)pvVar1 + 0x14,2,0x11);
      if (iVar3 == 0) {
        iVar3 = FUN_00135cb4(*(undefined4 *)((int)pvVar1 + 0x14));
        if (iVar3 == 0) {
          *(undefined4 *)(_active_threads + 0x188) = 0;
          return (int)pvVar1 + 4;
        }
        pcVar5 = s_clntkudp_create__socket_bind_pro_001dce3d;
      }
      else {
        pcVar5 = s_clntkudp_create__socket_creation_001dce10;
      }
      _printf(pcVar5,iVar3);
    }
  }
  *(undefined4 *)(_active_threads + 0x188) = 0;
  _kfree(*(undefined4 *)((int)pvVar1 + 0x68),0x2260);
  _crfree(*(undefined4 *)((int)pvVar1 + 0x74));
  _kfree(pvVar1,0x78);
  return 0;
}

