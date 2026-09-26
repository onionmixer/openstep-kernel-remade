/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00125d70 */

undefined4 _icmp_sendMaskPacket(int param_1,char param_2,int param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uVar7;
  int local_1c;
  undefined2 local_14;
  undefined2 local_12;
  undefined4 local_10;
  
  iVar6 = 0;
  if (((*(ushort *)(param_1 + 0xc) & 1) == 0) ||
     (local_1c = _in_ifaddr, (*(ushort *)(param_1 + 0xc) & 8) != 0)) {
    return 0;
  }
  for (; local_1c != 0; local_1c = *(int *)(local_1c + 0x40)) {
    if (*(int *)(local_1c + 0x20) == param_1) goto LAB_00125dbf;
  }
  local_1c = 0;
LAB_00125dbf:
  if (local_1c == 0) {
    uVar7 = 0x33;
  }
  else {
    iVar6 = _m_get(1,2);
    if (iVar6 == 0) {
      uVar7 = 0x37;
    }
    else {
      *(undefined2 *)(iVar6 + 8) = 0x20;
      *(undefined4 *)(iVar6 + 4) = 0x5c;
      _bzero((void *)(iVar6 + 0x5c),(int)*(short *)(iVar6 + 8));
      *(short *)(iVar6 + 8) = *(short *)(iVar6 + 8) + -0x14;
      iVar3 = *(int *)(iVar6 + 4) + 0x14;
      *(int *)(iVar6 + 4) = iVar3;
      puVar5 = (undefined1 *)(iVar3 + iVar6);
      if (param_2 == '\x12') {
        *puVar5 = 0x12;
        uVar4 = *(uint *)(local_1c + 0x34);
        uVar4 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
        *(uint *)(puVar5 + 8) = uVar4;
        if (uVar4 == 0) {
          uVar7 = 0x16;
          goto LAB_00125f3e;
        }
      }
      else {
        *puVar5 = 0x11;
      }
      puVar5[1] = 0;
      *(undefined2 *)(puVar5 + 2) = 0;
      *(undefined4 *)(puVar5 + 4) = 0;
      uVar2 = _in_cksum(iVar6,0xc);
      *(undefined2 *)(puVar5 + 2) = uVar2;
      *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + -0x14;
      *(short *)(iVar6 + 8) = *(short *)(iVar6 + 8) + 0x14;
      puVar5 = (undefined1 *)(iVar6 + *(int *)(iVar6 + 4));
      *puVar5 = 0x45;
      uVar1 = _ip_id;
      _ip_id = _ip_id + 1;
      *(ushort *)(puVar5 + 4) = uVar1 >> 8 | uVar1 << 8;
      puVar5[8] = 0xff;
      puVar5[9] = 1;
      *(undefined4 *)(puVar5 + 0xc) = *(undefined4 *)(local_1c + 4);
      *(undefined4 *)(puVar5 + 0x10) = 0xffffffff;
      *(undefined2 *)(puVar5 + 2) = 0x2000;
      *(undefined2 *)(puVar5 + 10) = 0;
      uVar2 = _in_cksum(iVar6,0x14);
      *(undefined2 *)(puVar5 + 10) = uVar2;
      local_14 = 2;
      local_12 = 0;
      local_10 = 0xffffffff;
      if (0 < param_3) {
        _timeout(0x10ab38);
        _sleep(local_1c + 0x34);
      }
      uVar7 = _if_output_mbuf(param_1,iVar6,&local_14);
      iVar6 = 0;
      if (param_2 == '\x11') {
        _timeout(0x10ab38);
        _sleep(local_1c + 0x34);
      }
    }
  }
LAB_00125f3e:
  if (iVar6 != 0) {
    _m_freem(iVar6);
  }
  return uVar7;
}

