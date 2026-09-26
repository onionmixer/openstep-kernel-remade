
undefined8 _light_on(void)

{
  uint uVar1;
  uint uVar2;
  int unaff_D2;
  char in_XF;
  
  uVar1 = *_scr2;
  uVar2 = uVar1 | 1;
  *_scr2 = uVar2;
  return CONCAT44(CONCAT22((sword)(uVar1 >> 0x10),
                           (word)(byte)(((int)uVar2 < 0) << 3 | (uVar2 == 0) << 2)),
                  (int)(sword)(word)(byte)(in_XF << 4 | (unaff_D2 < 0) << 3 | (unaff_D2 == 0) << 2))
  ;
}

