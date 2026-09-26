/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001122cc */

int _ptcread(byte param_1,int param_2)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_84;
  undefined1 local_83;
  undefined1 local_82;
  undefined1 local_81;
  undefined2 local_80;
  undefined1 local_7e [6];
  undefined1 local_78 [8];
  undefined4 local_70;
  uint local_6c;
  undefined1 local_68 [100];
  
  iVar3 = *(int *)(&DAT_001e56d0 + (uint)param_1 * 0x10);
  pbVar1 = *(byte **)(&DAT_001e56d4 + (uint)param_1 * 0x10);
  iVar5 = 0;
  do {
    if ((*(byte *)(iVar3 + 0x40) & 4) != 0) {
      if (((*pbVar1 & 8) != 0) && (pbVar1[0xc] != 0)) {
        iVar5 = _ureadc(pbVar1[0xc],param_2);
        if (iVar5 != 0) {
          return iVar5;
        }
        if ((pbVar1[0xc] & 0x40) != 0) {
          local_84 = *(undefined1 *)(iVar3 + 0x49);
          local_83 = *(undefined1 *)(iVar3 + 0x4a);
          local_82 = *(undefined1 *)(iVar3 + 0x4d);
          local_81 = *(undefined1 *)(iVar3 + 0x4e);
          local_80 = *(undefined2 *)(iVar3 + 0x3c);
          _bcopy((void *)(iVar3 + 0x4f),local_7e,6);
          _bcopy((void *)(iVar3 + 0x55),local_78,6);
          local_70 = *(undefined4 *)(iVar3 + 0x40);
          local_6c = (uint)*(ushort *)(iVar3 + 0x3e);
          uVar2 = 0x1c;
          if (*(uint *)(param_2 + 0x14) < 0x1c) {
            uVar2 = *(uint *)(param_2 + 0x14);
          }
          _uiomove(&local_84,uVar2,0,param_2);
        }
        pbVar1[0xc] = 0;
        return 0;
      }
      if (((char)*pbVar1 < '\0') && (pbVar1[0xd] != 0)) {
        iVar3 = _ureadc(pbVar1[0xd],param_2);
        if (iVar3 != 0) {
          return iVar3;
        }
        pbVar1[0xd] = 0;
        return 0;
      }
      if ((*(int *)(iVar3 + 0x18) != 0) && ((*(byte *)(iVar3 + 0x41) & 1) == 0)) {
        if ((*pbVar1 & 0x88) != 0) {
          iVar5 = _ureadc(0,param_2);
        }
        iVar4 = *(int *)(param_2 + 0x14);
        if ((iVar4 < 1) || (iVar5 != 0)) goto LAB_001124a4;
        break;
      }
    }
    if ((*(byte *)(iVar3 + 0x40) & 0x10) == 0) {
      return 5;
    }
    if ((*pbVar1 & 4) != 0) {
      if ((*(byte *)(*_active_u + 0x16) & 2) == 0) {
        iVar3 = 0x23;
      }
      else {
        iVar3 = 0xb;
      }
      return iVar3;
    }
    _sleep(iVar3 + 0x1c);
  } while( true );
LAB_00112468:
  if (100 < iVar4) {
    iVar4 = 100;
  }
  iVar4 = _q_to_b(iVar3 + 0x18,local_68,iVar4);
  if (iVar4 < 1) {
LAB_001124a4:
    if ((int)*(short *)(&_ttlowat + (*(byte *)(iVar3 + 0x4a) & 0x1f) * 2) < *(int *)(iVar3 + 0x18))
    {
      return iVar5;
    }
    if ((*(uint *)(iVar3 + 0x40) & 0x40) != 0) {
      *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xffffffbf;
      _wakeup(iVar3 + 0x18);
    }
    if (*(int *)(iVar3 + 0x2c) == 0) {
      return iVar5;
    }
    _selwakeup(*(int *)(iVar3 + 0x2c),*(uint *)(iVar3 + 0x40) & 0x1000);
    _thread_deallocate(*(undefined4 *)(iVar3 + 0x2c));
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xffffefff;
    return iVar5;
  }
  iVar5 = _uiomove(local_68,iVar4,0,param_2);
  iVar4 = *(int *)(param_2 + 0x14);
  if ((iVar4 < 1) || (iVar5 != 0)) goto LAB_001124a4;
  goto LAB_00112468;
}

