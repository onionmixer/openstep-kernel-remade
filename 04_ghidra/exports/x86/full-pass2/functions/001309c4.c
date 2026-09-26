/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001309c4 */

int FUN_001309c4(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  char *pcVar6;
  int local_194;
  undefined4 local_190;
  undefined1 local_18c [4];
  undefined4 local_188;
  undefined4 local_184;
  uint local_180;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  undefined4 local_16c;
  int local_168;
  uint local_164;
  int local_160;
  uint local_15c;
  undefined4 local_158;
  undefined1 local_154 [256];
  undefined1 local_54 [32];
  short local_34 [8];
  undefined1 local_24 [32];
  
  local_194 = 0;
  if ((*(byte *)(param_1 + 0xc) & 0x40) != 0) {
    return 0;
  }
  iVar3 = _copyin(param_3,&local_188,0x34);
  if (iVar3 != 0) goto LAB_00130ce1;
  iVar3 = _copyin(local_188,local_34,0x10);
  if (iVar3 != 0) goto LAB_00130ce1;
  if (local_34[0] != 2) {
    iVar3 = 0x2e;
    goto LAB_00130ce1;
  }
  iVar3 = _copyin(local_184,local_24,0x20);
  if (iVar3 != 0) goto LAB_00130ce1;
  if ((local_180 & 0x20) == 0) {
    FUN_001310d8(local_34,local_54);
  }
  else {
    iVar3 = _copyinstr(local_16c,local_54,0x20,local_18c);
    if (iVar3 != 0) goto LAB_00130ce1;
  }
  if ((local_180 & 0x1000) == 0) {
    local_190 = 0xffffffff;
  }
  else {
    _copyinstr(local_158,local_154,0x100,&local_190);
  }
  iVar3 = FUN_00130d00(&local_194,param_1,local_34,local_24,local_54,local_154,local_190,local_180);
  if (iVar3 != 0) {
    return iVar3;
  }
  iVar2 = *(int *)(*(int *)(local_194 + 0x24) + 0x128);
  bVar5 = ((byte)(local_180 >> 7) & 1) << 4;
  bVar1 = *(byte *)(iVar2 + 0x14);
  *(byte *)(iVar2 + 0x14) = bVar1 & 0xef | bVar5;
  *(byte *)(iVar2 + 0x14) = bVar1 & 0xcf | bVar5 | ((byte)(local_180 >> 0xd) & 1) << 5;
  if ((((local_180 & 0x10) != 0) && (*(int *)(iVar2 + 0x30) = local_170, local_170 < 0)) ||
     (((local_180 & 8) != 0 && (*(int *)(iVar2 + 0x2c) = local_174, local_174 < 1)))) {
LAB_00130bb5:
    iVar3 = 0x16;
    goto LAB_00130ce1;
  }
  if ((local_180 & 4) != 0) {
    if (local_178 < 1) goto LAB_00130bb5;
    iVar3 = *(int *)(iVar2 + 0x1c);
    if (local_178 < *(int *)(iVar2 + 0x1c)) {
      iVar3 = local_178;
    }
    *(int *)(iVar2 + 0x1c) = iVar3;
  }
  if ((local_180 & 2) != 0) {
    if (local_17c < 1) goto LAB_00130bb5;
    iVar3 = *(int *)(iVar2 + 0x20);
    if (local_17c < *(int *)(iVar2 + 0x20)) {
      iVar3 = local_17c;
    }
    *(int *)(iVar2 + 0x20) = iVar3;
  }
  if ((local_180 & 0x100) == 0) {
LAB_00130c0d:
    if ((local_180 & 0x200) != 0) {
      if ((int)local_164 < 0) {
        *(undefined4 *)(iVar2 + 100) = 36000;
      }
      else {
        if (local_164 < *(uint *)(iVar2 + 0x60)) {
          pcVar6 = s_nfs_mount__acregmax_<_acregmin_001dc9ab;
          goto LAB_00130cbf;
        }
        uVar4 = _min(local_164,36000);
        *(undefined4 *)(iVar2 + 100) = uVar4;
      }
    }
    if ((local_180 & 0x400) != 0) {
      if (local_160 < 0) {
        *(undefined4 *)(iVar2 + 0x68) = 0xe10;
      }
      else {
        if (local_160 == 0) {
          pcVar6 = s_nfs_mount__acdirmin____0_001dc9cb;
          goto LAB_00130cbf;
        }
        uVar4 = _min(local_160,0xe10);
        *(undefined4 *)(iVar2 + 0x68) = uVar4;
      }
    }
    iVar3 = 0;
    if ((local_180 & 0x800) != 0) {
      if ((int)local_15c < 0) {
        *(undefined4 *)(iVar2 + 0x6c) = 36000;
      }
      else {
        if (local_15c < *(uint *)(iVar2 + 0x68)) {
          pcVar6 = s_nfs_mount__acdirmax_<_acdirmin_001dc9e5;
          goto LAB_00130cbf;
        }
        uVar4 = _min(local_15c,36000);
        *(undefined4 *)(iVar2 + 0x6c) = uVar4;
      }
    }
  }
  else {
    if (local_168 < 0) {
      *(undefined4 *)(iVar2 + 0x60) = 0xe10;
      goto LAB_00130c0d;
    }
    if (local_168 != 0) {
      uVar4 = _min(local_168,0xe10);
      *(undefined4 *)(iVar2 + 0x60) = uVar4;
      goto LAB_00130c0d;
    }
    pcVar6 = s_nfs_mount__acregmin____0_001dc991;
LAB_00130cbf:
    iVar3 = 0x16;
    _printf(pcVar6);
  }
  if (iVar3 == 0) {
    return 0;
  }
LAB_00130ce1:
  if (local_194 != 0) {
    _vn_rele(local_194);
  }
  return iVar3;
}

