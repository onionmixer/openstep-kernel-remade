
/* WARNING: Possible PIC construction at 0x0409cb26: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0409cb26) */

byte t_ovfl2(void)

{
  byte bVar1;
  byte bVar2;
  int unaff_A6;
  
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1048;
  *(undefined4 *)(unaff_A6 + -0x74) = *(undefined4 *)(unaff_A6 + -0xcc);
  *(undefined4 *)(unaff_A6 + -0x70) = *(undefined4 *)(unaff_A6 + -200);
  *(undefined4 *)(unaff_A6 + -0x6c) = *(undefined4 *)(unaff_A6 + -0xc4);
  bVar2 = *(byte *)(unaff_A6 + -0x7d) & 0xc0;
  bVar1 = *(byte *)(unaff_A6 + -0x7d) & 0xc0;
  if (bVar2 != 0) {
    if (bVar2 == 0x40) {
      if ((*(char *)(unaff_A6 + -0xc4) != '\0') || ((*(uint *)(unaff_A6 + -200) & 0xff) != 0)) {
loc_409CB3C:
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x200;
        bVar2 = func_0x0409cb52();
        return bVar2;
      }
      bVar1 = 0;
    }
    else {
      bVar1 = 0;
      if ((*(uint *)(unaff_A6 + -0xc4) & 0x7ff) != 0) goto loc_409CB3C;
    }
  }
  return bVar1;
}
