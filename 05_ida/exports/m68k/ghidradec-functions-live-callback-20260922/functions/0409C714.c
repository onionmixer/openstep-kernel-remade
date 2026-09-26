
qword sub_409C714(void)

{
  word wVar1;
  undefined2 uVar2;
  undefined2 extraout_D1u;
  undefined2 extraout_D1u_00;
  uint uVar3;
  int iVar4;
  int unaff_A6;
  float10 fVar5;
  
  if ((*(word *)(unaff_A6 + -0xe4) & 0x3b) == 0) {
    if (((sword)(((uint)*(word *)(unaff_A6 + -0xcc) << 0x14) >> 0x10) == -0x10) &&
       (uVar2 = 0, (word)(((uint)*(word *)(unaff_A6 + -0xcc) << 0x11) >> 0x1d) == 7)) {
      if ((*(int *)(unaff_A6 + -200) == 0) && (*(int *)(unaff_A6 + -0xc4) == 0)) {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2000000;
        if (*(int *)(unaff_A6 + -0xcc) < 0) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
        }
      }
      else {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1000000;
        *(undefined *)(unaff_A6 + -0xe8) = 0x60;
        if (((*(byte *)(unaff_A6 + -200) & 0x40) == 0) &&
           (*(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1004080,
           (*(byte *)(unaff_A6 + -0x7e) & 0x40) == 0)) {
          *(byte *)(unaff_A6 + -200) = *(byte *)(unaff_A6 + -200) | 0x40;
        }
        if (*(int *)(unaff_A6 + -0xcc) < 0) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
        }
      }
    }
    else {
      uVar2 = 0;
      if (((*(word *)(unaff_A6 + -0xca) & 0xf) == 0) &&
         ((*(int *)(unaff_A6 + -200) == 0 && (*(int *)(unaff_A6 + -0xc4) == 0)))) {
        if (*(int *)(unaff_A6 + -0xcc) < 0) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xc000000;
          *(undefined4 *)(unaff_A6 + -0xcc) = 0x80000000;
          *(undefined4 *)(unaff_A6 + -200) = 0;
          *(undefined4 *)(unaff_A6 + -0xc4) = 0;
        }
        else {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x4000000;
          *(undefined4 *)(unaff_A6 + -0xcc) = 0;
          *(undefined4 *)(unaff_A6 + -200) = 0;
          *(undefined4 *)(unaff_A6 + -0xc4) = 0;
        }
      }
      else {
        fVar5 = (float10)decbin();
        *(undefined (*) [12])(unaff_A6 + -0xcc) = (undefined  [12])fVar5;
        uVar2 = extraout_D1u_00;
      }
    }
  }
  else if (((sword)(((uint)*(word *)(unaff_A6 + -0xcc) << 0x14) >> 0x10) == -0x10) &&
          (uVar2 = 0, (word)(((uint)*(word *)(unaff_A6 + -0xcc) << 0x11) >> 0x1d) == 7)) {
    if (((*(int *)(unaff_A6 + -200) != 0) || (*(int *)(unaff_A6 + -0xc4) != 0)) &&
       ((*(byte *)(unaff_A6 + -200) & 0x40) == 0)) {
      *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1004080;
    }
  }
  else {
    uVar2 = 0;
    if (((*(word *)(unaff_A6 + -0xca) & 0xf) == 0) &&
       ((*(int *)(unaff_A6 + -200) == 0 && (*(int *)(unaff_A6 + -0xc4) == 0)))) {
      if (*(int *)(unaff_A6 + -0xcc) < 0) {
        *(undefined4 *)(unaff_A6 + -0xcc) = 0x80000000;
        *(undefined4 *)(unaff_A6 + -200) = 0;
        *(undefined4 *)(unaff_A6 + -0xc4) = 0;
      }
      else {
        *(undefined4 *)(unaff_A6 + -0xcc) = 0;
        *(undefined4 *)(unaff_A6 + -200) = 0;
        *(undefined4 *)(unaff_A6 + -0xc4) = 0;
      }
    }
    else {
      fVar5 = (float10)decbin();
      *(undefined (*) [12])(unaff_A6 + -0xcc) = (undefined  [12])fVar5;
      uVar2 = extraout_D1u;
    }
  }
  *(word *)(unaff_A6 + -0xe4) = *(word *)(unaff_A6 + -0xe4) & 0xfbff;
  wVar1 = *(word *)(unaff_A6 + -0xcc) & 0x7fff;
  uVar3 = CONCAT22(uVar2,*(word *)(unaff_A6 + -0xcc)) & 0xffff7fff;
  if (wVar1 != 0x7fff) {
    if (wVar1 != 0) {
      if (wVar1 < 0x4000) {
        *(undefined *)(unaff_A6 + -0xe8) = 0x10;
      }
      else {
        *(undefined *)(unaff_A6 + -0xe8) = 0;
      }
      return (qword)uVar3;
    }
    *(undefined *)(unaff_A6 + -0xe8) = 0x30;
    return CONCAT44(0x20,uVar3);
  }
  iVar4 = *(int *)(unaff_A6 + -200);
  if ((iVar4 == 0) && (iVar4 = *(int *)(unaff_A6 + -0xc4), iVar4 == 0)) {
    *(undefined *)(unaff_A6 + -0xe8) = 0x40;
    return 0x4000000000;
  }
  *(undefined *)(unaff_A6 + -0xe8) = 0x60;
  return CONCAT44(0x60,iVar4);
}

