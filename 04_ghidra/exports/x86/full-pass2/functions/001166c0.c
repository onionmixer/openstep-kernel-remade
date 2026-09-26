/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001166c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _sbappendaddr(ushort *param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  ushort uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int local_c;
  
  local_c = 0x10;
  for (puVar2 = param_3; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    local_c = local_c + *(short *)(puVar2 + 2);
  }
  if (param_4 != 0) {
    local_c = local_c + *(short *)(param_4 + 8);
  }
  iVar7 = (uint)param_1[1] - (uint)*param_1;
  if ((int)((uint)param_1[3] - (uint)param_1[2]) < (int)((uint)param_1[1] - (uint)*param_1)) {
    iVar7 = (uint)param_1[3] - (uint)param_1[2];
  }
  if (local_c <= iVar7) {
    uVar5 = _splimp();
    piVar6 = _mfree;
    if (_mfree == (int *)0x0) {
      piVar6 = (int *)_m_more(0,8);
    }
    else {
      if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&DAT_001db35e);
      }
      *(undefined2 *)((int)_mfree + 10) = 8;
      _DAT_001e917c = _DAT_001e917c + -1;
      _DAT_001e918c = _DAT_001e918c + 1;
      piVar4 = (int *)*_mfree;
      *_mfree = 0;
      _mfree = piVar4;
      piVar6[1] = 0xc;
    }
    _splx(uVar5);
    if (piVar6 != (int *)0x0) {
      iVar7 = piVar6[1];
      *(undefined4 *)(iVar7 + (int)piVar6) = *param_2;
      *(undefined4 *)(iVar7 + 4 + (int)piVar6) = param_2[1];
      *(undefined4 *)(iVar7 + 8 + (int)piVar6) = param_2[2];
      *(undefined4 *)(iVar7 + 0xc + (int)piVar6) = param_2[3];
      *(undefined2 *)(piVar6 + 2) = 0x10;
      if ((param_4 != 0) && (*(short *)(param_4 + 8) != 0)) {
        iVar7 = _m_copy(param_4,0,(int)*(short *)(param_4 + 8));
        *piVar6 = iVar7;
        if (iVar7 == 0) {
          _m_freem(piVar6);
          return 0;
        }
        *param_1 = *param_1 + *(short *)(iVar7 + 8);
        uVar1 = param_1[2];
        param_1[2] = uVar1 + 0x80;
        if (0x7c < *(uint *)(*piVar6 + 4)) {
          param_1[2] = uVar1 + 0x480;
        }
      }
      *param_1 = *param_1 + (short)piVar6[2];
      uVar1 = param_1[2];
      param_1[2] = uVar1 + 0x80;
      if (0x7c < (uint)piVar6[1]) {
        param_1[2] = uVar1 + 0x480;
      }
      iVar7 = *(int *)(param_1 + 6);
      if (iVar7 == 0) {
        *(int **)(param_1 + 6) = piVar6;
      }
      else {
        iVar3 = *(int *)(iVar7 + 0x7c);
        while (iVar3 != 0) {
          iVar7 = *(int *)(iVar7 + 0x7c);
          iVar3 = *(int *)(iVar7 + 0x7c);
        }
        *(int **)(iVar7 + 0x7c) = piVar6;
      }
      if ((int *)*piVar6 != (int *)0x0) {
        piVar6 = (int *)*piVar6;
      }
      if (param_3 != (undefined4 *)0x0) {
        _sbcompress(param_1,param_3,piVar6);
      }
      return 1;
    }
  }
  return 0;
}

