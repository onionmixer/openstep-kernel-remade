/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00124e60 */

undefined4 _in_pcbbind(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_10;
  
  iVar6 = *(int *)(param_1 + 0x1c);
  iVar2 = *(int *)(param_1 + 8);
  uVar3 = 0;
  if (_in_ifaddr == 0) {
    return 0x31;
  }
  if ((*(short *)(param_1 + 0x18) == 0) && (*(int *)(param_1 + 0x14) == 0)) {
    if (param_2 != 0) {
      iVar7 = param_2 + *(int *)(param_2 + 4);
      if (*(short *)(param_2 + 8) != 0x10) goto LAB_00124eaa;
      if (*(int *)(iVar7 + 4) != 0) {
        uVar1 = *(undefined2 *)(iVar7 + 2);
        *(undefined2 *)(iVar7 + 2) = 0;
        iVar5 = _ifa_ifwithaddr(iVar7);
        if (iVar5 == 0) {
          return 0x31;
        }
        *(undefined2 *)(iVar7 + 2) = uVar1;
      }
      uVar3 = *(ushort *)(iVar7 + 2);
      if (uVar3 != 0) {
        local_10 = 0;
        if ((((ushort)(uVar3 >> 8 | uVar3 << 8) < 0x400) &&
            (*(short *)(*(int *)(_active_u + 0x1c) + 2) != 0)) && (-1 < *(char *)(iVar6 + 6))) {
          return 0xd;
        }
        if (((*(ushort *)(iVar6 + 2) & 4) == 0) &&
           (((*(byte *)(*(int *)(iVar6 + 0xc) + 10) & 4) == 0 || ((*(ushort *)(iVar6 + 2) & 2) == 0)
            ))) {
          local_10 = 1;
        }
        iVar6 = _in_pcblookup(iVar2,_zeroin_addr,0,*(undefined4 *)(iVar7 + 4),uVar3,local_10);
        if (iVar6 != 0) {
          return 0x30;
        }
      }
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar7 + 4);
    }
    if (uVar3 == 0) {
      do {
        uVar3 = *(ushort *)(iVar2 + 0x18);
        *(short *)(iVar2 + 0x18) = *(short *)(iVar2 + 0x18) + 1;
        if ((uVar3 < 0xa00) || (5000 < *(ushort *)(iVar2 + 0x18))) {
          *(undefined2 *)(iVar2 + 0x18) = 0xa00;
        }
        uVar3 = *(ushort *)(iVar2 + 0x18) >> 8 | *(ushort *)(iVar2 + 0x18) << 8;
        iVar6 = _in_pcblookup(iVar2,_zeroin_addr,0,*(undefined4 *)(param_1 + 0x14),uVar3,0);
      } while (iVar6 != 0);
    }
    *(ushort *)(param_1 + 0x18) = uVar3;
    uVar4 = 0;
  }
  else {
LAB_00124eaa:
    uVar4 = 0x16;
  }
  return uVar4;
}

