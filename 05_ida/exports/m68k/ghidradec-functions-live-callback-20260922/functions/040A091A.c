
float10 sintdo(void)

{
  byte bVar1;
  uint uVar2;
  undefined (*in_A0) [12];
  undefined (*extraout_A0) [12];
  int unaff_A6;
  float10 fVar3;
  
  *(uint *)(unaff_A6 + -0x54) = (*(uint *)(unaff_A6 + -0x7d) & 0x3fffffff) >> 0x1c;
  bVar1 = (*in_A0)[0];
  (*in_A0)[0] = bVar1 & 0x7f;
  (*in_A0)[2] = -((bVar1 & 0x80) != 0);
  if (0x403e < *(sword *)*in_A0) {
    uVar2 = *(uint *)(*in_A0 + 2) >> 0x18;
    *(uint *)(*in_A0 + 2) = uVar2;
    if (uVar2 != 0) {
      (*in_A0)[0] = (*in_A0)[0] | 0x80;
    }
    return (float10)*in_A0;
  }
  if (0x3ffd < *(sword *)*in_A0) {
    dnrm_lp();
    round();
    nrm_set();
    uVar2 = *(uint *)(*extraout_A0 + 2) >> 0x18;
    *(uint *)(*extraout_A0 + 2) = uVar2;
    if (uVar2 != 0) {
      (*extraout_A0)[0] = (*extraout_A0)[0] | 0x80;
    }
    return (float10)*extraout_A0;
  }
  if ((*(byte *)(unaff_A6 + -0x51) & 2) == 0) {
    if ((*in_A0)[2] == '\0') {
      ld_pzero();
      fVar3 = (float10)t_inx2();
      return fVar3;
    }
    ld_mzero();
    fVar3 = (float10)t_inx2();
    return fVar3;
  }
  if ((*in_A0)[2] == '\0') {
    if (*(char *)(unaff_A6 + -0x51) != '\x03') {
      ld_pzero();
      fVar3 = (float10)t_inx2();
      return fVar3;
    }
    ld_pone();
    fVar3 = (float10)t_inx2();
    return fVar3;
  }
  if (*(char *)(unaff_A6 + -0x51) != '\x02') {
    ld_mzero();
    fVar3 = (float10)t_inx2();
    return fVar3;
  }
  ld_mone();
  fVar3 = (float10)t_inx2();
  return fVar3;
}

