/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00122764 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _in_arpinput(uint param_1,uint *param_2,uint param_3,int param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  int local_4c;
  uint local_48;
  uint local_44;
  undefined2 local_40;
  undefined1 local_3e [14];
  undefined2 local_30 [2];
  uint local_2c;
  undefined1 local_20 [2];
  ushort local_1e;
  short local_1c;
  ushort local_1a;
  undefined1 local_18 [20];
  
  local_4c = 0;
  _bcopy((void *)(param_4 + *(int *)(param_4 + 4)),local_20,0x1c);
  local_40 = 0x806;
  uVar1 = local_1e >> 8 | local_1e << 8;
  uVar2 = local_1a >> 8 | local_1a << 8;
  if (local_1c != _DAT_001db968) goto LAB_00122bd4;
  _bcopy(local_18 + DAT_001db968,&local_44,4);
  _bcopy(local_20 + DAT_001db969 + 8 + (uint)DAT_001db968 * 2,&local_48,4);
  iVar3 = _bcmp(local_18,param_2,(uint)DAT_001db968);
  if (iVar3 == 0) goto LAB_00122bd4;
  iVar3 = _bcmp(local_18,&_etherbroadcastaddr,6);
  if (iVar3 == 0) {
    _log(3,s_arp__ether_address_is_broadcast_f_001db9b2,
         local_44 >> 0x18 | (local_44 & 0xff0000) >> 8 | (local_44 & 0xff00) << 8 | local_44 << 0x18
        );
    goto LAB_00122bd4;
  }
  if (local_44 == param_3) {
    uVar4 = _ether_sprintf(local_18);
    _log(3,s__s___s_001dba18,s_duplicate_IP_address___sent_from_001db9e6,uVar4);
    local_48 = param_3;
    if (uVar2 != 1) goto LAB_00122bd4;
    puVar5 = (uint *)0x0;
  }
  else {
    uVar4 = _splimp();
    puVar5 = (uint *)(&_arptab + (local_44 % 0x13) * 0xb4);
    iVar3 = 0;
    do {
      if ((*puVar5 == local_44) && ((param_1 == 0 || (puVar5[4] == param_1)))) break;
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 5;
    } while (iVar3 < 9);
    if (8 < iVar3) {
      puVar5 = (uint *)0x0;
    }
    if (puVar5 == (uint *)0x0) {
      if (local_48 == param_3) {
        puVar5 = (uint *)_arptnew(param_1,&local_44);
        _bcopy(local_18,puVar5 + 1,(uint)DAT_001db968);
        if (DAT_001db968 < 6) {
          _bzero((undefined *)((int)puVar5 + DAT_001db968 + 4),6 - DAT_001db968);
        }
        *(byte *)((int)puVar5 + 0xb) = *(byte *)((int)puVar5 + 0xb) | 2;
      }
    }
    else {
      _bcopy(local_18,puVar5 + 1,(uint)DAT_001db968);
      if (DAT_001db968 < 6) {
        _bzero((undefined *)((int)puVar5 + DAT_001db968 + 4),6 - DAT_001db968);
      }
      *(byte *)((int)puVar5 + 0xb) = *(byte *)((int)puVar5 + 0xb) | 2;
      if (puVar5[3] != 0) {
        local_30[0] = 2;
        local_2c = local_44;
        _if_output_mbuf(param_1,puVar5[3],local_30);
        puVar5[3] = 0;
      }
    }
    _splx(uVar4);
  }
  if (uVar1 == 0x800) {
    if (uVar2 != 1) goto LAB_001229d6;
  }
  else if (uVar1 == 0x1000) {
    if (puVar5 != (uint *)0x0) {
      *(byte *)((int)puVar5 + 0xb) = *(byte *)((int)puVar5 + 0xb) | 0x10;
    }
    if (uVar2 != 1) goto LAB_00122bd4;
LAB_001229d6:
    if ((*(byte *)(param_1 + 0xc) & 0x20) != 0) goto LAB_00122bd4;
  }
  if (param_3 == local_48) {
    _bcopy(local_18,local_20 + DAT_001db969 + 8 + (uint)DAT_001db968,(uint)DAT_001db968);
  }
  else {
    param_2 = (uint *)(&_arptab + (local_48 % 0x13) * 0xb4);
    iVar3 = 0;
    do {
      if ((*param_2 == local_48) && ((param_1 == 0 || (param_2[4] == param_1)))) break;
      iVar3 = iVar3 + 1;
      param_2 = param_2 + 5;
    } while (iVar3 < 9);
    if (8 < iVar3) {
      param_2 = (uint *)0x0;
    }
    if ((param_2 == (uint *)0x0) || ((*(byte *)((int)param_2 + 0xb) & 8) == 0)) {
LAB_00122bd4:
      _m_freem(param_4);
      return;
    }
    _bcopy(local_18,local_20 + DAT_001db969 + 8 + (uint)DAT_001db968,(uint)DAT_001db968);
    param_2 = param_2 + 1;
  }
  _bcopy(param_2,local_18,(uint)DAT_001db968);
  _bcopy(local_18 + DAT_001db968,local_20 + DAT_001db969 + 8 + (uint)DAT_001db968 * 2,
         (uint)DAT_001db969);
  _bcopy(&local_48,local_18 + DAT_001db968,(uint)DAT_001db969);
  local_1a = 2;
  _bcopy(local_20 + DAT_001db969 + 8 + (uint)DAT_001db968,local_3e,(uint)DAT_001db968);
  _bcopy(&local_40,local_3e + (uint)DAT_001db968 * 2,2);
  if (uVar2 == 2) {
    local_1e = 0x10;
  }
  else if ((uVar1 == 0x800) && ((*(byte *)(param_1 + 0xc) & 0x20) == 0)) {
    local_4c = _m_copy(param_4,0,1000000000);
  }
  local_1a = local_1a >> 8 | local_1a << 8;
  _bcopy(local_20,(void *)(param_4 + *(int *)(param_4 + 4)),0x1c);
  local_40 = 0;
  _if_output_mbuf(param_1,param_4,&local_40);
  if (local_4c == 0) {
    return;
  }
  local_1e = 0x10;
  _bcopy(local_20,(void *)(local_4c + *(int *)(local_4c + 4)),0x1c);
  _if_output_mbuf(param_1,local_4c,&local_40);
  return;
}

