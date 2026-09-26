
undefined8 _light_off(void)

{
  uint uVar1;
  int unaff_D2;
  char in_XF;
  
  uVar1 = *_scr2 & 0xfffffffe;
  *_scr2 = uVar1;
  return CONCAT44(CONCAT22((sword)(uVar1 >> 0x10),
                           (word)(byte)(((int)uVar1 < 0) << 3 | (uVar1 == 0) << 2)),
                  (int)(sword)(word)(byte)(in_XF << 4 | (unaff_D2 < 0) << 3 | (unaff_D2 == 0) << 2))
  ;
}

