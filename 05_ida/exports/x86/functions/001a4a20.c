/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4a20. */
int __cdecl -[IODevice errnoFromReturn:](IODevice *self, SEL a2, int a3)
{
  if ( a3 == -711 ) /*0x1a4a2b*/
    return 45; /*0x1a4b1c*/
  if ( a3 <= -711 ) /*0x1a4a31*/
  {
    if ( a3 == -721 ) /*0x1a4a38*/
      return 5; /*0x1a4a38*/
    if ( a3 <= -721 ) /*0x1a4a3e*/
    {
      if ( a3 != -724 ) /*0x1a4a45*/
      {
        if ( a3 > -724 ) /*0x1a4a4b*/
        {
          if ( a3 != -722 ) /*0x1a4a65*/
            return 5; /*0x1a4a65*/
        }
        else if ( a3 != -725 ) /*0x1a4a52*/
        {
          return 5; /*0x1a4a52*/
        }
        return 16; /*0x1a4b40*/
      }
      return 5; /*0x1a4b28*/
    }
    if ( a3 > -716 ) /*0x1a4a75*/
    {
      if ( a3 != -714 ) /*0x1a4a95*/
        return 5; /*0x1a4a95*/
      return 5; /*0x1a4a95*/
    }
    if ( a3 < -718 ) /*0x1a4a7c*/
    {
      if ( a3 == -719 ) /*0x1a4a83*/
        return 30; /*0x1a4b34*/
      return 5; /*0x1a4a83*/
    }
    return 13; /*0x1a4b04*/
  }
  if ( a3 == -705 ) /*0x1a4aa5*/
    return 13; /*0x1a4aa5*/
  if ( a3 > -705 ) /*0x1a4aa7*/
  {
    if ( a3 > -701 ) /*0x1a4ac5*/
    {
      if ( !a3 ) /*0x1a4ada*/
        return 0; /*0x1a4ae1*/
    }
    else
    {
      if ( a3 >= -702 ) /*0x1a4acc*/
        return 12; /*0x1a4aec*/
      if ( a3 == -704 ) /*0x1a4ad3*/
        return 6; /*0x1a4af8*/
    }
    return 5; /*0x1a4ad3*/
  }
  if ( a3 >= -709 ) /*0x1a4aae*/
  {
    if ( a3 > -707 ) /*0x1a4ab9*/
      return 22; /*0x1a4b10*/
    return 13; /*0x1a4ab9*/
  }
  return 5; /*0x1a4ae0*/
}
