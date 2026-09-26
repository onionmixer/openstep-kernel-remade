/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1540dc. */
int __cdecl msg_return_translate(int a1)
{
  int v1; // eax

  v1 = a1; /*0x1540e2*/
  BYTE1(v1) = BYTE1(a1) & 0xC3; /*0x1540e4*/
  if ( v1 > 268435470 ) /*0x1540ec*/
  {
    if ( v1 == 268451845 ) /*0x15418d*/
      return -207; /*0x154284*/
    if ( v1 > 268451845 ) /*0x154193*/
    {
      if ( v1 > 268451850 ) /*0x1541d1*/
        goto LABEL_47; /*0x1541d1*/
      if ( v1 < 268451849 ) /*0x1541dc*/
      {
        if ( v1 == 268451847 ) /*0x1541e3*/
          goto LABEL_47; /*0x1541e3*/
        if ( v1 > 268451847 ) /*0x1541e9*/
          return -201; /*0x154294*/
        else
          return -208; /*0x154288*/
      }
    }
    else
    {
      if ( v1 == 268451841 ) /*0x15419a*/
        goto LABEL_47; /*0x15419a*/
      if ( v1 <= 268451841 ) /*0x1541a0*/
      {
        if ( v1 == 268435471 ) /*0x1541a7*/
          return -102; /*0x1541a7*/
        goto LABEL_47; /*0x1541a7*/
      }
      if ( v1 == 268451843 ) /*0x1541b9*/
        return -203; /*0x154278*/
      if ( v1 > 268451843 ) /*0x1541bf*/
        return -204; /*0x15426c*/
    }
    return -202; /*0x154260*/
  }
  if ( v1 >= 268435469 )
  {
    printf("msg_return_translate: %x -> interrupted\n", a1);
    return -108; /*0x154202*/
  }
  if ( v1 == 268435462 ) /*0x154102*/
    return -106; /*0x154254*/
  if ( v1 > 268435462 ) /*0x154108*/
  {
    if ( v1 <= 268435466 ) /*0x154141*/
    {
      if ( v1 >= 268435465 ) /*0x154148*/
        return -102; /*0x154148*/
      if ( v1 != 268435463 ) /*0x154153*/
      {
        if ( v1 == 268435464 ) /*0x15415e*/
          return -110; /*0x154218*/
        goto LABEL_47; /*0x15415e*/
      }
      return -108; /*0x15420f*/
    }
    if ( v1 == 268435468 ) /*0x154171*/
      return -101; /*0x154171*/
LABEL_47:
    panic(aMsgReturnTrans_0); /*0x1542a0*/
  }
  if ( v1 == 268435458 ) /*0x15410f*/
    return -101; /*0x154224*/
  if ( v1 > 268435458 ) /*0x154115*/
  {
    if ( v1 == 268435460 ) /*0x154129*/
      return -103; /*0x154230*/
    if ( v1 > 268435460 ) /*0x15412f*/
      return -105; /*0x154248*/
    return -102; /*0x15423c*/
  }
  if ( v1 ) /*0x154119*/
    goto LABEL_47; /*0x154119*/
  return 0; /*0x1541f8*/
}
