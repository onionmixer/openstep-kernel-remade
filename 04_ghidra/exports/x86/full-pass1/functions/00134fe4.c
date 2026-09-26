/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00134fe4 */

undefined4 _authkern_marshal(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  short *psVar8;
  short *psVar9;
  uint local_24 [2];
  XDR local_1c;
  
  psVar9 = (short *)(*(int *)(_active_u + 0x1c) + 10);
  for (psVar8 = (short *)(*(int *)(_active_u + 0x1c) + 0x2a);
      (psVar9 < psVar8 && (psVar8[-1] == -1)); psVar8 = psVar8 + -1) {
  }
  uVar6 = (int)psVar8 - (int)psVar9 >> 1;
  uVar2 = _hostnamelen + 3;
  if ((int)uVar2 < 0) {
    uVar2 = _hostnamelen + 6;
  }
  uVar2 = (uVar2 & 0xfffffffc) + 0x14 + uVar6 * 4;
  puVar1 = (undefined4 *)(**(code **)(*(int *)(param_2 + 4) + 0x18))(param_2,uVar2 + 0x10);
  if (puVar1 == (undefined4 *)0x0) {
    pcVar4 = (char *)_kalloc(400);
    _xdrmem_create(&local_1c,pcVar4,400,XDR_ENCODE);
    iVar5 = _xdr_authkern(&local_1c);
    if (iVar5 == 0) {
      _printf(s_authkern_marshal__xdr_authkern_f_001dcd9c);
      uVar3 = 0;
    }
    else {
      uVar2 = (*(local_1c.x_ops)->x_getpostn)(&local_1c);
      *(uint *)(param_1 + 8) = uVar2;
      *(char **)(param_1 + 4) = pcVar4;
      iVar5 = _xdr_opaque_auth(param_2,param_1);
      if ((iVar5 == 0) || (iVar5 = _xdr_opaque_auth(param_2,param_1 + 0xc), iVar5 == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
    }
    _kfree(pcVar4,400);
  }
  else {
    _getthetime(local_24);
    *puVar1 = 0x1000000;
    puVar1[1] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 * 0x1000000;
    puVar1[2] = local_24[0] >> 0x18 | (local_24[0] & 0xff0000) >> 8 | (local_24[0] & 0xff00) << 8 |
                local_24[0] << 0x18;
    puVar1[3] = _hostnamelen >> 0x18 | (_hostnamelen & 0xff0000) >> 8 | (_hostnamelen & 0xff00) << 8
                | _hostnamelen << 0x18;
    _bcopy(&_hostname,puVar1 + 4,_hostnamelen);
    uVar2 = _hostnamelen + 3;
    if ((int)uVar2 < 0) {
      uVar2 = _hostnamelen + 6;
    }
    puVar7 = (uint *)((int)(puVar1 + 4) + (uVar2 & 0xfffffffc));
    uVar2 = (uint)*(short *)(*(int *)(_active_u + 0x1c) + 2);
    *puVar7 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = (uint)*(short *)(*(int *)(_active_u + 0x1c) + 4);
    puVar7[1] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    puVar7 = puVar7 + 2;
    while( true ) {
      *puVar7 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
      if (psVar8 <= psVar9) break;
      uVar6 = (uint)*psVar9;
      psVar9 = psVar9 + 1;
      puVar7 = puVar7 + 1;
    }
    puVar7[1] = 0;
    puVar7[2] = 0;
    uVar3 = 1;
  }
  return uVar3;
}

