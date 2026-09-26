/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00126e90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ip_forward(byte *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_ESI;
  int local_c;
  undefined4 local_8;
  
  local_c = 0;
  local_8 = 0;
  if (_ipprintfs != 0) {
    _printf(s_forward__src__x_dst__x_ttl__x_001dbddc,*(undefined4 *)(param_1 + 0xc),
            *(undefined4 *)(param_1 + 0x10),(uint)param_1[8]);
  }
  *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) >> 8 | *(ushort *)(param_1 + 4) << 8;
  if ((_ipforwarding == 0) || (_in_interfaces < 2)) {
    _DAT_001eaad8 = _DAT_001eaad8 + 1;
LAB_00126f04:
    _m_freem((uint)param_1 & 0xffffff80);
    return;
  }
  iVar3 = _in_canforward(*(undefined4 *)(param_1 + 0x10));
  if (iVar3 == 0) goto LAB_00126f04;
  if (param_1[8] < 2) {
    local_c = 0xb;
    unaff_ESI = 0;
    goto switchD_00127110_caseD_2;
  }
  param_1[8] = param_1[8] - 1;
  uVar4 = _imin((int)*(short *)(param_1 + 2),0x40);
  iVar3 = _m_copy((uint)param_1 & 0xffffff80,0,uVar4);
  if (_ipforward_rt == 0) {
LAB_00126f90:
    DAT_001eacf4 = 2;
    DAT_001eacf8 = *(int *)(param_1 + 0x10);
    _rtalloc(&_ipforward_rt);
  }
  else if (*(int *)(param_1 + 0x10) != DAT_001eacf8) {
    if (_ipforward_rt != 0) {
      if (*(short *)(_ipforward_rt + 0x26) == 1) {
        _rtfree(_ipforward_rt);
      }
      else {
        *(short *)(_ipforward_rt + 0x26) = *(short *)(_ipforward_rt + 0x26) + -1;
      }
      _ipforward_rt = 0;
    }
    goto LAB_00126f90;
  }
  if (((((_ipforward_rt != 0) && (*(int *)(_ipforward_rt + 0x2c) == param_2)) &&
       ((*(byte *)(_ipforward_rt + 0x24) & 0x30) == 0)) &&
      ((*(int *)(_ipforward_rt + 8) != 0 && (_ipsendredirects != 0)))) && ((*param_1 & 0xf) == 5)) {
    uVar1 = *(uint *)(param_1 + 0xc);
    uVar2 = *(uint *)(param_1 + 0x10);
    iVar5 = _ifptoia(param_2);
    if ((iVar5 != 0) &&
       (*(uint *)(iVar5 + 0x30) ==
        ((uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
        *(uint *)(iVar5 + 0x34)))) {
      if ((*(byte *)(_ipforward_rt + 0x24) & 2) == 0) {
        local_8 = *(undefined4 *)(param_1 + 0x10);
      }
      else {
        local_8 = *(undefined4 *)(_ipforward_rt + 0x18);
      }
      local_c = 5;
      unaff_ESI = 0;
      iVar5 = _in_ifaddr;
      if ((*(ushort *)(_ipforward_rt + 0x24) & 6) == 2) {
        do {
          iVar5 = *(int *)(iVar5 + 0x40);
          if (iVar5 == 0) goto LAB_00127087;
        } while (*(uint *)(iVar5 + 0x28) !=
                 ((uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18)
                 & *(uint *)(iVar5 + 0x2c)));
        if (*(uint *)(iVar5 + 0x34) != *(uint *)(iVar5 + 0x2c)) goto LAB_00127076;
      }
      else {
LAB_00127076:
        unaff_ESI = 1;
      }
LAB_00127087:
      if (_ipprintfs != 0) {
        _printf(s_redirect___d__to__x_001dbdfb,unaff_ESI,local_8);
      }
    }
  }
  iVar5 = _ip_output((uint)param_1 & 0xffffff80,0,&_ipforward_rt,1);
  if (iVar5 == 0) {
    if (local_c == 0) {
      if (iVar3 != 0) {
        _m_freem(iVar3);
      }
      _DAT_001eaad4 = _DAT_001eaad4 + 1;
      return;
    }
    _DAT_001eaadc = _DAT_001eaadc + 1;
  }
  else {
    _DAT_001eaad8 = _DAT_001eaad8 + 1;
  }
  if (iVar3 == 0) {
    return;
  }
  param_1 = (byte *)(iVar3 + *(int *)(iVar3 + 4));
  local_c = 3;
  switch(iVar5) {
  case 0:
    local_c = 5;
    break;
  case 1:
    unaff_ESI = 3;
    break;
  case 0x28:
    unaff_ESI = 4;
    break;
  case 0x32:
  case 0x33:
    iVar3 = _in_localaddr(*(undefined4 *)(param_1 + 0x10));
    unaff_ESI = 0;
    if (iVar3 == 0) break;
  case 0x40:
  case 0x41:
    unaff_ESI = 1;
    break;
  case 0x37:
    local_c = 4;
  }
switchD_00127110_caseD_2:
  _icmp_error(param_1,local_c,unaff_ESI,param_2,&local_8);
  return;
}

