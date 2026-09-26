
/* WARNING: Removing unreachable block (ram,0xf00bcb48) */
/* WARNING: Removing unreachable block (ram,0xf00bcb38) */

sqword -[kmDevice dumpMsgBuf](int param_1,uint param_2)

{
  char cVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  if (((*(int *)(param_1 + 0x114) == 1) || (*(int *)(param_1 + 0x114) == 3)) &&
     (*_pmsgbuf == 0x63061)) {
    piVar2 = (int *)((int)_pmsgbuf + _pmsgbuf[1] + 0xc);
    cVar1 = *(char *)piVar2;
    while( true ) {
      if (cVar1 != '\0') {
        if (cVar1 == '\n') {
          _objc_msgSend(param_1,paKmputc,0xd);
        }
        _objc_msgSend(param_1,paKmputc,(int)*(char *)piVar2);
      }
      piVar2 = (int *)((int)piVar2 + 1);
      if (_pmsgbuf + 0x400 <= piVar2) {
        piVar2 = _pmsgbuf + 3;
      }
      if (piVar2 == (int *)((int)_pmsgbuf + _pmsgbuf[1] + 0xc)) break;
      cVar1 = *(char *)piVar2;
    }
  }
  return (qword)param_2 << 0x20;
}
