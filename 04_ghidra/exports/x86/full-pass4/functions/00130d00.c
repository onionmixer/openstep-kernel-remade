/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00130d00 */

int FUN_00130d00(int *param_1,int param_2,undefined4 *param_3,undefined4 param_4,void *param_5,
                void *param_6,size_t param_7,uint param_8)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  byte local_d4;
  undefined1 local_c8 [64];
  undefined1 local_88 [68];
  undefined1 local_44 [64];
  
  iVar5 = 0;
  puVar1 = (undefined4 *)_kalloc(0x70);
  _bzero(puVar1,0x70);
  local_d4 = (byte)(param_8 >> 6);
  *(byte *)(puVar1 + 5) =
       *(byte *)(puVar1 + 5) & 0xfa | ((byte)param_8 ^ 1) & 1 | (local_d4 & 1) << 2;
  *puVar1 = *param_3;
  puVar1[1] = param_3[1];
  puVar1[2] = param_3[2];
  puVar1[3] = param_3[3];
  puVar1[0xc] = 5;
  puVar1[0xb] = 0xb;
  uVar2 = _vfs_getnum(&DAT_001e59b8,0x20);
  puVar1[10] = uVar2;
  _bcopy(param_5,puVar1 + 0xd,0x20);
  puVar1[0x18] = 3;
  puVar1[0x19] = 0x3c;
  puVar1[0x1a] = 0x1e;
  puVar1[0x1b] = 0x3c;
  if ((param_8 & 0x1000) == 0) {
    puVar1[0x17] = 1;
    puVar1[0x16] = param_7;
    if (-1 < (int)param_7) {
      pvVar3 = (void *)_kalloc(param_7);
      puVar1[0x15] = pvVar3;
      _bcopy(param_6,pvVar3,param_7);
    }
    *(undefined4 *)(param_2 + 0x14) = puVar1[10];
    *(undefined4 *)(param_2 + 0x18) = 1;
    *(undefined4 **)(param_2 + 0x128) = puVar1;
    iVar5 = _makenfsnode(param_4,0,param_2);
    if ((*(ushort *)(iVar5 + 4) & 1) == 0) {
      *(ushort *)(iVar5 + 4) = *(ushort *)(iVar5 + 4) | 1;
      iVar4 = (**(code **)(*(int *)(iVar5 + 0x1c) + 0x14))
                        (iVar5,local_44,*(undefined4 *)(_active_u + 0x1c));
      if (iVar4 == 0) {
        _vn_rele(iVar5);
        _vattr_to_nattr(local_44,local_88);
        iVar5 = _makenfsnode(param_4,local_88,param_2);
        *(byte *)(iVar5 + 4) = *(byte *)(iVar5 + 4) | 1;
        puVar1[4] = iVar5;
        iVar4 = (**(code **)(*(int *)(param_2 + 4) + 0xc))(param_2,local_c8);
        if (iVar4 == 0) {
          uVar2 = _nfstsize();
          uVar2 = _min(0x2000,uVar2);
          puVar1[7] = uVar2;
          puVar1[9] = 0x2000;
          *(undefined4 *)(param_2 + 0x10) = 0x2000;
          **(short **)(_active_u + 0x1c) = **(short **)(_active_u + 0x1c) + 1;
          *(undefined4 *)(*(int *)(iVar5 + 0x30) + 0x70) = *(undefined4 *)(_active_u + 0x1c);
          *param_1 = iVar5;
          return 0;
        }
      }
      goto LAB_00130ef1;
    }
  }
  iVar4 = 0x16;
LAB_00130ef1:
  if (puVar1 != (undefined4 *)0x0) {
    if (-1 < (int)puVar1[0x16]) {
      _kfree(puVar1[0x15],puVar1[0x16]);
    }
    _kfree(puVar1,0x70);
  }
  if (iVar5 != 0) {
    _vn_rele(iVar5);
  }
  *param_1 = 0;
  return iVar4;
}

