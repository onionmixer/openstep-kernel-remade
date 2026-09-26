/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00194c24 */

int _mmrw(byte param_1,undefined4 *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int unaff_EDI;
  int local_8;
  
  iVar5 = 0;
  if ((int)param_2[5] < 1) {
    return 0;
  }
  do {
    piVar1 = (int *)*param_2;
    iVar4 = piVar1[1];
    if (iVar4 == 0) {
      *param_2 = piVar1 + 2;
      iVar2 = param_2[1];
      param_2[1] = iVar2 + -1;
      iVar4 = unaff_EDI;
      if (iVar2 + -1 < 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&DAT_001e36a0);
      }
    }
    else if (param_1 == 1) {
      iVar5 = _kernacc(param_2[2],iVar4,param_3 == 0);
      if (iVar5 == 0) {
        return 0xe;
      }
      iVar5 = _uiomove(param_2[2],iVar4,param_3,param_2);
    }
    else {
      if (param_1 < 2) {
        if (param_1 == 0) {
          uVar6 = ~_page_mask & param_2[2];
          if (_mem_size <= (uint)param_2[2]) {
            return 0xe;
          }
          uVar3 = _splvm();
          local_8 = *(int *)(_kernel_map + 0x14);
          iVar5 = _vm_map_find(_kernel_map,0,0,&local_8,_page_size,1);
          if (iVar5 != 0) {
            _splx(uVar3);
            return 0xe;
          }
          _pmap_enter(*(undefined4 *)(_kernel_map + 0x24),local_8,uVar6,3,1);
          iVar5 = param_2[2] - uVar6;
          iVar4 = _min(_page_size - iVar5,piVar1[1]);
          iVar5 = _uiomove(iVar5 + local_8,iVar4,param_3,param_2);
          _vm_map_remove(_kernel_map,local_8,local_8 + _page_size);
          _splx(uVar3);
          goto LAB_00194dca;
        }
      }
      else if ((param_1 == 2) && (unaff_EDI = iVar4, param_3 == 0)) {
        return 0;
      }
      iVar4 = unaff_EDI;
      if (iVar5 != 0) {
        return iVar5;
      }
      *piVar1 = *piVar1 + iVar4;
      piVar1[1] = piVar1[1] - iVar4;
      param_2[2] = param_2[2] + iVar4;
      param_2[5] = param_2[5] - iVar4;
    }
LAB_00194dca:
    if ((int)param_2[5] < 1) {
      return iVar5;
    }
    unaff_EDI = iVar4;
    if (iVar5 != 0) {
      return iVar5;
    }
  } while( true );
}

