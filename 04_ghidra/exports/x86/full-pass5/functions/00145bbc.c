/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00145bbc */

undefined4 FUN_00145bbc(int *param_1,int param_2,uint param_3,uint param_4)

{
  undefined1 uVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  uint local_20;
  int local_8;
  
  uVar3 = param_1[0xc];
  while ((*(ushort *)(uVar3 + 0x44) & 1) != 0) {
    *(ushort *)(uVar3 + 0x44) = *(ushort *)(uVar3 + 0x44) | 0x10;
    _sleep(uVar3);
  }
  *(byte *)(uVar3 + 0x44) = *(byte *)(uVar3 + 0x44) | 1;
  local_8 = 0;
  uVar4 = *(undefined4 *)(uVar3 + 0x40);
  iVar5 = *(int *)(uVar3 + 0x50);
  uVar6 = *(uint *)(iVar5 + 0x30);
  do {
    uVar11 = param_4 >> ((byte)*(undefined4 *)(iVar5 + 0x50) & 0x1f);
    uVar7 = ~*(uint *)(iVar5 + 0x48) & param_4;
    local_20 = param_3;
    if (uVar6 - uVar7 < param_3) {
      local_20 = uVar6 - uVar7;
    }
    uVar1 = *(undefined1 *)(DAT_001e875c + 0x68);
    *(undefined1 *)(DAT_001e875c + 0x68) = 0;
    iVar8 = _bmap(uVar3,uVar11,0x20,uVar7 + local_20,0);
    iVar8 = iVar8 << ((byte)*(undefined4 *)(iVar5 + 100) & 0x1f);
    iVar10 = (int)*(char *)(DAT_001e875c + 0x68);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
    if ((iVar10 != 0) || (iVar8 < 0)) {
      *(int *)(*param_1 + 0x34) = iVar10;
      _printf(s_IO_error_on_pageout__error____d__001de591,iVar10);
LAB_00145d31:
      uVar2 = *(ushort *)(uVar3 + 0x44);
      *(ushort *)(uVar3 + 0x44) = uVar2 & 0xfffe;
      if ((uVar2 & 0x10) != 0) {
        *(ushort *)(uVar3 + 0x44) = uVar2 & 0xffee;
        _wakeup(uVar3);
      }
      return 2;
    }
    if (*(uint *)(uVar3 + 0x6c) < param_4 + local_20) {
      *(uint *)(uVar3 + 0x6c) = param_4 + local_20;
    }
    if (((int)uVar11 < 0xc) &&
       (*(uint *)(uVar3 + 0x6c) < uVar11 + 1 << ((byte)*(undefined4 *)(iVar5 + 0x50) & 0x1f))) {
      uVar11 = ((~*(uint *)(iVar5 + 0x48) & *(uint *)(uVar3 + 0x6c)) + *(int *)(iVar5 + 0x34)) - 1 &
               *(uint *)(iVar5 + 0x4c);
    }
    else {
      uVar11 = *(uint *)(iVar5 + 0x30);
    }
    if (local_20 == uVar6) {
      puVar9 = (uint *)_getblk(uVar4,iVar8,uVar11);
    }
    else {
      puVar9 = (uint *)_bread(uVar4,iVar8,uVar11);
    }
    if ((int)(uVar11 - puVar9[10]) < (int)local_20) {
      local_20 = uVar11 - puVar9[10];
    }
    if ((*puVar9 & 4) != 0) {
      *(int *)(*param_1 + 0x34) = (int)(short)puVar9[7];
      _brelse(puVar9);
      _printf(s_IO_error_on_pageout__bread__001de5b3);
      goto LAB_00145d31;
    }
    _copy_from_phys(param_2 + local_8,uVar7 + puVar9[8],local_20);
    param_3 = param_3 - local_20;
    local_8 = local_8 + local_20;
    param_4 = param_4 + local_20;
    if (uVar6 == local_20 + uVar7) {
      *puVar9 = *puVar9 | 0x400000;
      _bawrite(puVar9);
    }
    else {
      _bdwrite(puVar9);
    }
    *(byte *)(uVar3 + 0x44) = *(byte *)(uVar3 + 0x44) | 0x42;
    *(ushort *)(uVar3 + 100) = *(ushort *)(uVar3 + 100) & 0xf3ff;
    _microtime(&_iuniqtime);
    if ((*(byte *)(uVar3 + 0x44) & 4) != 0) {
      *(undefined4 *)(uVar3 + 0x74) = _iuniqtime;
    }
    if ((*(byte *)(uVar3 + 0x44) & 2) != 0) {
      *(undefined4 *)(uVar3 + 0x7c) = _iuniqtime;
    }
    if ((*(byte *)(uVar3 + 0x44) & 0x40) != 0) {
      *(undefined4 *)(uVar3 + 0x4c) = 0;
      *(undefined4 *)(uVar3 + 0x84) = _iuniqtime;
    }
    if ((param_3 == 0) || (local_20 == 0)) {
      uVar2 = *(ushort *)(uVar3 + 0x44);
      *(ushort *)(uVar3 + 0x44) = uVar2 & 0xfffe;
      if ((uVar2 & 0x10) != 0) {
        *(ushort *)(uVar3 + 0x44) = uVar2 & 0xffee;
        _wakeup(uVar3);
      }
      return 0;
    }
  } while( true );
}

