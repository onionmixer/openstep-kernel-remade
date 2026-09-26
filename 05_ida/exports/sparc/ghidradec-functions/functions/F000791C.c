
/* WARNING: Control flow encountered unimplemented instructions */

void _strncpy(uint *param_1,uint *param_2,int param_3)

{
  word wVar1;
  uint uVar2;
  char cVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar4;
  undefined4 unaff_i3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_i4;
  undefined2 uVar8;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (param_3 < 9) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  uVar2 = (uint)param_2 & 3;
  if (uVar2 != 0) {
    if (uVar2 != 2) {
      cVar3 = *(char *)param_2;
      param_2 = (uint *)((int)param_2 + 1);
      param_3 = param_3 + -1;
      *(char *)param_1 = cVar3;
      if (uVar2 == 3) {
        param_1 = (uint *)((int)param_1 + 1);
        if (cVar3 == '\0') {
          halt_unimplemented();
        }
        goto loc_F00079AC;
      }
      param_1 = (uint *)((int)param_1 + 1);
      if (cVar3 == '\0') {
        halt_unimplemented();
      }
    }
    wVar1 = *(word *)param_2;
    param_2 = (uint *)((int)param_2 + 2);
    param_3 = param_3 + -2;
    *(char *)param_1 = (char)(wVar1 >> 8);
    if (wVar1 >> 8 == 0) {
      halt_unimplemented();
    }
    *(char *)((int)param_1 + 1) = (char)wVar1;
    param_1 = (uint *)((int)param_1 + 2);
    if ((wVar1 & 0xff) == 0) {
      halt_unimplemented();
    }
  }
loc_F00079AC:
  uVar2 = (uint)param_1 & 3;
  if (uVar2 == 0) {
    do {
      while( true ) {
        iVar4 = param_3 + -4;
        if (iVar4 == 0 || param_3 < 4) {
          halt_unimplemented();
        }
        uVar2 = *param_2;
        param_2 = param_2 + 1;
        param_3 = iVar4;
        if (((uVar2 + 0x7efefeff ^ uVar2) & 0x81010100) != 0x81010100) break;
        *param_1 = uVar2;
        param_1 = param_1 + 1;
      }
      if ((uVar2 & 0xff000000) == 0) {
        *(char *)param_1 = '\0';
        halt_unimplemented();
      }
      uVar8 = (undefined2)(uVar2 >> 0x10);
      if ((uVar2 & 0xff0000) == 0) {
        *(undefined2 *)param_1 = uVar8;
        halt_unimplemented();
      }
      if ((uVar2 & 0xff00) == 0) {
        *(undefined2 *)param_1 = uVar8;
        *(char *)((int)param_1 + 2) = '\0';
        halt_unimplemented();
      }
      *param_1 = uVar2;
      param_1 = param_1 + 1;
    } while ((uVar2 & 0xff) != 0);
  }
  else if (uVar2 == 2) {
    uVar2 = *param_2;
    param_2 = param_2 + 1;
    if ((uVar2 & 0xff000000) == 0) {
      *(char *)param_1 = '\0';
    }
    else {
      uVar8 = (undefined2)(uVar2 >> 0x10);
      if ((uVar2 & 0xff0000) == 0) {
        *(undefined2 *)param_1 = uVar8;
      }
      else if ((uVar2 & 0xff00) == 0) {
        *(undefined2 *)param_1 = uVar8;
        *(char *)((int)param_1 + 2) = '\0';
      }
      else if ((uVar2 & 0xff) == 0) {
        *(undefined2 *)param_1 = uVar8;
        *(sword *)((int)param_1 + 2) = (sword)uVar2;
      }
      else {
        *(undefined2 *)param_1 = uVar8;
        param_1 = (uint *)((int)param_1 + 2);
        iVar4 = param_3 + -2;
        do {
          while( true ) {
            if (iVar4 < 4) {
              halt_unimplemented();
            }
            uVar5 = uVar2 << 0x10;
            if ((uVar5 & 0xff000000) == 0) {
              *(char *)param_1 = '\0';
              halt_unimplemented();
            }
            uVar8 = (undefined2)uVar2;
            if ((uVar5 & 0xff0000) == 0) {
              *(undefined2 *)param_1 = uVar8;
              halt_unimplemented();
            }
            uVar2 = *param_2;
            param_2 = param_2 + 1;
            uVar6 = uVar2 >> 0x10;
            uVar7 = uVar6 | uVar5;
            if (((uVar7 + 0x7efefeff ^ uVar7) & 0x81010100) != 0x81010100) break;
            *param_1 = uVar7;
            param_1 = param_1 + 1;
            iVar4 = iVar4 + -4;
          }
          if ((uVar5 & 0xff000000) == 0) {
            *(char *)param_1 = '\0';
            halt_unimplemented();
          }
          if ((uVar5 & 0xff0000) == 0) {
            *(undefined2 *)param_1 = uVar8;
            halt_unimplemented();
          }
          if ((uVar6 & 0xff00) == 0) {
            *(undefined2 *)param_1 = uVar8;
            *(char *)((int)param_1 + 2) = '\0';
            halt_unimplemented();
          }
          *param_1 = uVar7;
          param_1 = param_1 + 1;
          iVar4 = iVar4 + -4;
        } while ((uVar6 & 0xff) != 0);
      }
    }
  }
  else {
    uVar5 = *param_2;
    param_2 = param_2 + 1;
    bVar9 = (uVar5 & 0xff000000) != 0;
    uVar8 = (undefined2)(uVar5 >> 8);
    cVar3 = (char)(uVar5 >> 0x18);
    if (uVar2 == 3) {
      if (bVar9) {
        if ((uVar5 & 0xff0000) == 0) {
          *(char *)param_1 = cVar3;
          *(char *)((int)param_1 + 1) = '\0';
        }
        else if ((uVar5 & 0xff00) == 0) {
          *(undefined2 *)((int)param_1 + 1) = uVar8;
          *(char *)param_1 = cVar3;
        }
        else if ((uVar5 & 0xff) == 0) {
          *(char *)param_1 = cVar3;
          *(undefined2 *)((int)param_1 + 1) = uVar8;
          *(char *)((int)param_1 + 3) = '\0';
        }
        else {
          *(char *)param_1 = cVar3;
          param_1 = (uint *)((int)param_1 + 1);
          iVar4 = param_3 + -1;
          do {
            while( true ) {
              uVar2 = uVar5 << 8;
              if (iVar4 < 4) {
                halt_unimplemented();
              }
              if ((uVar2 & 0xff000000) == 0) {
                *(char *)param_1 = '\0';
                halt_unimplemented();
              }
              uVar8 = (undefined2)(uVar5 >> 8);
              if ((uVar2 & 0xff0000) == 0) {
                *(undefined2 *)param_1 = uVar8;
                halt_unimplemented();
              }
              if ((uVar2 & 0xff00) == 0) {
                *(undefined2 *)param_1 = uVar8;
                *(char *)((int)param_1 + 2) = '\0';
                halt_unimplemented();
              }
              uVar5 = *param_2;
              param_2 = param_2 + 1;
              uVar6 = uVar5 >> 0x18 | uVar2;
              if (((uVar6 + 0x7efefeff ^ uVar6) & 0x81010100) != 0x81010100) break;
              *param_1 = uVar6;
              param_1 = param_1 + 1;
              iVar4 = iVar4 + -4;
            }
            if ((uVar2 & 0xff000000) == 0) {
              *(char *)param_1 = '\0';
              halt_unimplemented();
            }
            if ((uVar2 & 0xff0000) == 0) {
              *(undefined2 *)param_1 = uVar8;
              halt_unimplemented();
            }
            if ((uVar2 & 0xff00) == 0) {
              *(undefined2 *)param_1 = uVar8;
              *(char *)((int)param_1 + 2) = '\0';
              halt_unimplemented();
            }
            *param_1 = uVar6;
            param_1 = param_1 + 1;
            iVar4 = iVar4 + -4;
          } while (uVar5 >> 0x18 != 0);
        }
      }
      else {
        *(char *)param_1 = '\0';
      }
    }
    else if (bVar9) {
      if ((uVar5 & 0xff0000) == 0) {
        *(char *)param_1 = cVar3;
        *(char *)((int)param_1 + 1) = '\0';
      }
      else if ((uVar5 & 0xff00) == 0) {
        *(undefined2 *)((int)param_1 + 1) = uVar8;
        *(char *)param_1 = cVar3;
      }
      else if ((uVar5 & 0xff) == 0) {
        *(char *)param_1 = cVar3;
        *(undefined2 *)((int)param_1 + 1) = uVar8;
        *(char *)((int)param_1 + 3) = '\0';
      }
      else {
        *(char *)param_1 = cVar3;
        *(undefined2 *)((int)param_1 + 1) = uVar8;
        param_1 = (uint *)((int)param_1 + 3);
        iVar4 = param_3 + -3;
        do {
          while( true ) {
            uVar2 = uVar5 << 0x18;
            if (iVar4 < 4) {
              halt_unimplemented();
            }
            if (uVar2 == 0) {
              *(char *)param_1 = '\0';
              halt_unimplemented();
            }
            uVar5 = *param_2;
            param_2 = param_2 + 1;
            uVar6 = uVar5 >> 8;
            uVar7 = uVar6 | uVar2;
            if (((uVar7 + 0x7efefeff ^ uVar7) & 0x81010100) != 0x81010100) break;
            *param_1 = uVar7;
            param_1 = param_1 + 1;
            iVar4 = iVar4 + -4;
          }
          if (uVar2 == 0) {
            *(char *)param_1 = '\0';
            halt_unimplemented();
          }
          uVar8 = (undefined2)(uVar7 >> 0x10);
          if ((uVar6 & 0xff0000) == 0) {
            *(undefined2 *)param_1 = uVar8;
            halt_unimplemented();
          }
          if ((uVar6 & 0xff00) == 0) {
            *(undefined2 *)param_1 = uVar8;
            *(char *)((int)param_1 + 2) = '\0';
            halt_unimplemented();
          }
          *param_1 = uVar7;
          param_1 = param_1 + 1;
          iVar4 = iVar4 + -4;
        } while ((uVar6 & 0xff) != 0);
      }
    }
    else {
      *(char *)param_1 = '\0';
    }
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
