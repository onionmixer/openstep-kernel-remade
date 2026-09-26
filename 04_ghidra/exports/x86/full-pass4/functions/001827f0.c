/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001827f0 */

void FUN_001827f0(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_10c;
  int local_108;
  int local_104;
  int local_100;
  undefined1 local_fc [72];
  undefined1 local_b4 [160];
  undefined1 local_14 [16];
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    local_100 = 7;
    local_104 = 4;
    local_108 = 0x14;
    local_10c = 9;
    uVar1 = _convert_port_to_dev
                      (param_1[2],param_2 + 0x24,&local_100,local_14,&local_104,local_b4,&local_108,
                       local_fc,&local_10c);
    iVar2 = _kern_IOGetEISADeviceConfig(uVar1);
    *(int *)(param_2 + 0x1c) = iVar2;
    if (iVar2 == 0) {
      *(undefined4 *)(param_2 + 0x20) = DAT_001e1164;
      *(ushort *)(param_2 + 0x22) = *(ushort *)(param_2 + 0x22) & 0xf000 | (ushort)local_100 & 0xfff
      ;
      iVar2 = local_100 * 4;
      iVar3 = iVar2 + param_2;
      *(undefined4 *)(iVar3 + 0x24) = DAT_001e1168;
      _memcpy((void *)(iVar3 + 0x28),local_14,local_104 * 4);
      *(ushort *)(iVar3 + 0x26) = *(ushort *)(iVar3 + 0x26) & 0xf000 | (ushort)local_104 & 0xfff;
      iVar4 = local_104 * 4;
      iVar5 = iVar4 + iVar3 + -0x1c;
      *(undefined4 *)(iVar5 + 0x44) = DAT_001e116c;
      _memcpy((void *)(iVar5 + 0x48),local_b4,local_108 * 8);
      *(ushort *)(iVar5 + 0x46) = *(ushort *)(iVar5 + 0x46) & 0xf000 | (short)local_108 * 2 & 0xfffU
      ;
      iVar3 = local_108 * 8;
      iVar5 = iVar3 + iVar5 + -0x10;
      *(undefined4 *)(iVar5 + 0x58) = DAT_001e1170;
      _memcpy((void *)(iVar5 + 0x5c),local_fc,local_10c * 8);
      *(ushort *)(iVar5 + 0x5a) = *(ushort *)(iVar5 + 0x5a) & 0xf000 | (short)local_10c * 2 & 0xfffU
      ;
      *(int *)(param_2 + 4) = iVar2 + 0x30 + iVar4 + iVar3 + local_10c * 8;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

