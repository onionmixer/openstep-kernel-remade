
void ovf_r_x2(void)

{
  word wVar1;
  undefined4 in_D0;
  uint uVar2;
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) == 0) {
    wVar1 = *(word *)(unaff_A6 + -0xe4) & 0x44;
    if (wVar1 == 0x40) goto loc_40A416C;
    if (wVar1 == 0x44) goto loc_40A4174;
    wVar1 = *(word *)(unaff_A6 + -0xe4) & 0x7f;
    if ((wVar1 == 0x27) || (wVar1 == 0x24)) goto loc_40A4164;
  }
  else {
    uVar2 = CONCAT22((sword)((uint)in_D0 >> 0x10),*(undefined2 *)(unaff_A6 + -0xf0)) & 0xffff0060;
    if (uVar2 == 0x40) {
loc_40A416C:
      ovf_res();
      return;
    }
    if (uVar2 == 0x60) {
loc_40A4174:
      ovf_res();
      return;
    }
    wVar1 = *(word *)(unaff_A6 + -0xf0) & 0x7f;
    if ((wVar1 == 0x33) || (wVar1 == 0x30)) {
loc_40A4164:
      ovf_res();
      return;
    }
  }
  ovf_res();
  return;
}
