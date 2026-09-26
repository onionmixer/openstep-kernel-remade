/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00115068 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _sosend(int param_1,int param_2,int param_3,uint param_4,int param_5)

{
  ushort uVar1;
  bool bVar2;
  int *piVar3;
  bool bVar4;
  undefined4 *puVar5;
  int *piVar6;
  ushort uVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  uint local_14;
  int local_10;
  int local_8;
  
  local_8 = 0;
  local_10 = 0;
  local_14 = 0;
  bVar4 = true;
  if (((*(byte *)(*(int *)(param_1 + 0xc) + 10) & 1) != 0) &&
     ((int)(uint)*(ushort *)(param_1 + 0x3e) < *(int *)(param_3 + 0x14))) {
    return 0x28;
  }
  bVar2 = false;
  if (((param_4 & 4) != 0) &&
     (((*(byte *)(param_1 + 2) & 0x10) == 0 && ((*(byte *)(*(int *)(param_1 + 0xc) + 10) & 1) != 0))
     )) {
    bVar2 = true;
  }
  _active_u[0x69] = _active_u[0x69] + 1;
  if (param_5 != 0) {
    local_10 = (int)*(short *)(param_5 + 8);
  }
LAB_0011512b:
  uVar7 = *(ushort *)(param_1 + 0x50);
  if ((uVar7 & 1) != 0) {
    do {
      *(ushort *)(param_1 + 0x50) = uVar7 | 2;
      _sleep(param_1 + 0x50);
      uVar7 = *(ushort *)(param_1 + 0x50);
    } while ((uVar7 & 1) != 0);
  }
  *(byte *)(param_1 + 0x50) = *(byte *)(param_1 + 0x50) | 1;
  do {
    uVar8 = _splnet();
    uVar7 = *(ushort *)(param_1 + 6);
    if ((uVar7 & 0x10) != 0) {
      local_14 = 0x20;
      goto LAB_0011526b;
    }
    uVar1 = *(ushort *)(param_1 + 0x56);
    if (uVar1 != 0) {
      *(undefined2 *)(param_1 + 0x56) = 0;
      local_14 = (uint)uVar1;
      goto LAB_0011526b;
    }
    if ((uVar7 & 2) == 0) {
      if ((*(byte *)(*(int *)(param_1 + 0xc) + 10) & 4) != 0) {
        local_14 = 0x39;
        goto LAB_0011526b;
      }
      if (param_2 == 0) {
        local_14 = 0x27;
        goto LAB_0011526b;
      }
    }
    if ((param_4 & 1) == 0) {
      iVar11 = (uint)*(ushort *)(param_1 + 0x42) - (uint)*(ushort *)(param_1 + 0x40);
      iVar12 = (uint)*(ushort *)(param_1 + 0x3e) - (uint)*(ushort *)(param_1 + 0x3c);
      if (iVar11 < iVar12) {
        iVar12 = iVar11;
      }
      if (((iVar12 <= local_10) ||
          (((*(byte *)(*(int *)(param_1 + 0xc) + 10) & 1) != 0 &&
           (iVar12 < local_10 + *(int *)(param_3 + 0x14))))) ||
         ((0x3ff < *(int *)(param_3 + 0x14) &&
          (((iVar12 < 0x400 && (0x3ff < *(ushort *)(param_1 + 0x3c))) && ((uVar7 & 0x100) == 0))))))
      break;
    }
    else {
      iVar12 = 0x400;
    }
    _splx(uVar8);
    iVar12 = iVar12 - local_10;
    piVar3 = &local_8;
    do {
      if (iVar12 < 1) break;
      uVar8 = _splimp();
      piVar9 = _mfree;
      if (_mfree == (int *)0x0) {
        piVar9 = (int *)_m_more(1,1);
      }
      else {
        if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(&DAT_001db30b);
        }
        *(undefined2 *)((int)_mfree + 10) = 1;
        _DAT_001e917c = _DAT_001e917c + -1;
        _DAT_001e917e = _DAT_001e917e + 1;
        piVar6 = (int *)*_mfree;
        *_mfree = 0;
        _mfree = piVar6;
        piVar9[1] = 0xc;
      }
      _splx(uVar8);
      if ((*(int *)(param_3 + 0x14) < 0x200) || (iVar12 < 0x400)) {
LAB_001153f8:
        iVar11 = iVar12;
        if (*(int *)(param_3 + 0x14) < 0x71) {
          if (*(int *)(param_3 + 0x14) < iVar12) {
LAB_00115411:
            iVar11 = 0x70;
            if (*(int *)(param_3 + 0x14) < 0x71) {
              iVar11 = *(int *)(param_3 + 0x14);
            }
          }
        }
        else if (0x70 < iVar12) goto LAB_00115411;
        iVar12 = iVar12 - iVar11;
      }
      else {
        uVar8 = _splimp();
        if (_mclfree == (undefined4 *)0x0) {
          _m_clalloc(1,1,0);
        }
        puVar5 = _mclfree;
        if (_mclfree != (undefined4 *)0x0) {
          (&_mclrefcnt)[(int)_mclfree - __mbutl >> 10] =
               (&_mclrefcnt)[(int)_mclfree - __mbutl >> 10] + '\x01';
          _DAT_001e916c = _DAT_001e916c + -1;
          _mclfree = (undefined4 *)*_mclfree;
        }
        _splx(uVar8);
        if (puVar5 == (undefined4 *)0x0) {
          *(undefined2 *)(piVar9 + 2) = 0x70;
        }
        else {
          piVar9[1] = (int)puVar5 - (int)piVar9;
          *(undefined2 *)(piVar9 + 2) = 0x400;
          *(undefined2 *)(piVar9 + 3) = 1;
        }
        if ((short)piVar9[2] != 0x400) goto LAB_001153f8;
        iVar11 = 0x400;
        if (*(int *)(param_3 + 0x14) < 0x401) {
          iVar11 = *(int *)(param_3 + 0x14);
        }
        iVar12 = iVar12 + -0x400;
      }
      local_14 = _uiomove((int)piVar9 + piVar9[1],iVar11,1,param_3);
      *(short *)(piVar9 + 2) = (short)iVar11;
      *piVar3 = (int)piVar9;
      if (local_14 != 0) goto LAB_001154f3;
      piVar3 = piVar9;
    } while (0 < *(int *)(param_3 + 0x14));
    if (bVar2) {
      *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) | 0x10;
    }
    uVar8 = _splnet();
    uVar10 = 9;
    if ((param_4 & 1) != 0) {
      uVar10 = 0xe;
    }
    local_14 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,uVar10,local_8,param_2,param_5)
    ;
    _splx(uVar8);
    if (bVar2) {
      *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0xef;
    }
    param_5 = 0;
    local_10 = 0;
    local_8 = 0;
    bVar4 = false;
    if ((local_14 != 0) || (*(int *)(param_3 + 0x14) == 0)) goto LAB_001154f3;
  } while( true );
  if ((*(byte *)(param_1 + 7) & 1) != 0) {
    if (((bVar4) && (local_14 = 0x23, (*(byte *)(*_active_u + 0x16) & 2) != 0)) &&
       ((*(byte *)(param_3 + 0x11) & 0x20) != 0)) {
      local_14 = 0xb;
    }
LAB_0011526b:
    _splx(uVar8);
LAB_001154f3:
    uVar7 = *(ushort *)(param_1 + 0x50);
    *(ushort *)(param_1 + 0x50) = uVar7 & 0xfffe;
    if ((uVar7 & 2) != 0) {
      *(ushort *)(param_1 + 0x50) = uVar7 & 0xfffc;
      _wakeup(param_1 + 0x50);
    }
    if (local_8 != 0) {
      _m_freem(local_8);
    }
    if (local_14 != 0x20) {
      return local_14;
    }
    _exception_from_kernel(5,0x10001,0);
    return 0x20;
  }
  uVar7 = *(ushort *)(param_1 + 0x50);
  *(ushort *)(param_1 + 0x50) = uVar7 & 0xfffe;
  if ((uVar7 & 2) != 0) {
    *(ushort *)(param_1 + 0x50) = uVar7 & 0xfffc;
    _wakeup(param_1 + 0x50);
  }
  _sbwait(param_1 + 0x3c);
  _splx(uVar8);
  goto LAB_0011512b;
}

