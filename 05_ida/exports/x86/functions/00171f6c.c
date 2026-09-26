/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x171f6c. */
int __cdecl sub_171F6C(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  int result; // eax

  result = machine_exception(a1, a2, a3, a4, a5); /*0x171f86*/
  if ( !result ) /*0x171f8d*/
  {
    result = a1 - 1; /*0x171f93*/
    switch ( a1 ) /*0x171f9f*/
    {
      case 1: /*0x171f9f*/
        if ( a2 == 1 ) /*0x171fc3*/
          *a4 = 11; /*0x171fc5*/
        else
          *a4 = 10; /*0x171fd0*/
        break; /*0x171fcb*/
      case 2: /*0x171f9f*/
        *a4 = 4; /*0x171fd8*/
        break; /*0x171fde*/
      case 3: /*0x171f9f*/
        *a4 = 8; /*0x171fe0*/
        break; /*0x171fe6*/
      case 4: /*0x171f9f*/
        *a4 = 7; /*0x171fe8*/
        break; /*0x171fee*/
      case 5: /*0x171f9f*/
        if ( a2 == 65537 ) /*0x171ff6*/
        {
          *a4 = 13; /*0x172018*/
        }
        else if ( a2 > 65537 ) /*0x171ff8*/
        {
          if ( a2 == 65538 ) /*0x17200a*/
            *a4 = 6; /*0x172020*/
        }
        else if ( a2 == 0x10000 ) /*0x172000*/
        {
          *a4 = 12; /*0x172010*/
        }
        break; /*0x172016*/
      case 6: /*0x171f9f*/
        *a4 = 5; /*0x172028*/
        break; /*0x172028*/
      default:
        return result;
    }
  }
  return result; /*0x172031*/
}
