
int _mmrw(byte param_1,int *param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint unaff_D2;
  int iVar5;
  
  iVar5 = 0;
  if (*(int *)((int)param_2 + 0x12) < 1) {
    return 0;
  }
  do {
    piVar1 = (int *)*param_2;
    uVar3 = piVar1[1];
    if (uVar3 == 0) {
      *param_2 = (int)(piVar1 + 2);
      iVar4 = param_2[1];
      param_2[1] = iVar4 + -1;
      uVar3 = unaff_D2;
      if (iVar4 + -1 < 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMmrw);
      }
    }
    else if (param_1 == 1) {
      iVar5 = param_2[2];
loc_40723C2:
      iVar5 = _uiomove(iVar5,uVar3,param_3,param_2);
    }
    else {
      if (param_1 < 2) {
        if (param_1 == 0) {
          uVar2 = ~_page_mask & param_2[2];
          iVar5 = param_2[2] - uVar2;
          uVar3 = _min(_page_size - iVar5,uVar3);
          if (iVar5 < 0) {
            return 0xe;
          }
          if (_dma_chip == 0x139) {
            if (_machine_type == '\x03') {
              iVar4 = _slot_id + 0x6000000;
            }
            else {
              iVar4 = _slot_id + 0x8000000;
            }
          }
          else {
            iVar4 = _slot_id + 0xc000000;
          }
          if (iVar4 < iVar5) {
            return 0xe;
          }
          iVar5 = iVar5 + uVar2;
          goto loc_40723C2;
        }
      }
      else if (param_1 == 2) {
        unaff_D2 = uVar3;
        if (param_3 == 0) {
          return 0;
        }
      }
      else if (param_1 == 3) {
        unaff_D2 = 8;
        if (8 < uVar3) {
          unaff_D2 = uVar3;
        }
        uVar3 = param_2[2];
        param_2[2] = uVar3 & 7;
        iVar5 = _slot_id_bmap + (uVar3 & 7) + 0x2008000;
        param_2[2] = iVar5;
        iVar5 = _uiomove(iVar5,unaff_D2,param_3,param_2);
      }
      if (iVar5 != 0) {
        return iVar5;
      }
      *piVar1 = unaff_D2 + *piVar1;
      piVar1[1] = piVar1[1] - unaff_D2;
      param_2[2] = unaff_D2 + param_2[2];
      *(int *)((int)param_2 + 0x12) = *(int *)((int)param_2 + 0x12) - unaff_D2;
      uVar3 = unaff_D2;
    }
    if (*(int *)((int)param_2 + 0x12) < 1) {
      return iVar5;
    }
    unaff_D2 = uVar3;
    if (iVar5 != 0) {
      return iVar5;
    }
  } while( true );
}
