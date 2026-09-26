/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1abf58. */
int __cdecl -[IOSCSIController returnFromScStatus:](IOSCSIController *self, SEL a2, int a3)
{
  int result; // eax

  switch ( a3 ) /*0x1abf67*/
  {
    case 0: /*0x1abf67*/
      result = 0; /*0x1abfd0*/
      break; /*0x1abfd5*/
    case 7: /*0x1abf67*/
      result = -706; /*0x1abfe4*/
      break; /*0x1abfec*/
    case 8: /*0x1abf67*/
      result = -702; /*0x1ac014*/
      break; /*0x1ac01c*/
    case 9: /*0x1abf67*/
      result = -712; /*0x1ac008*/
      break; /*0x1ac010*/
    case 14: /*0x1abf67*/
      result = -713; /*0x1abffc*/
      break; /*0x1ac004*/
    case 17: /*0x1abf67*/
      result = -719; /*0x1ac02c*/
      break; /*0x1ac034*/
    case 18: /*0x1abf67*/
      result = -720; /*0x1abfd8*/
      break; /*0x1abfe0*/
    case 19: /*0x1abf67*/
      result = -703; /*0x1abff0*/
      break; /*0x1abff8*/
    case 23: /*0x1abf67*/
      result = -724; /*0x1ac020*/
      break; /*0x1ac028*/
    default:
      result = -714; /*0x1ac038*/
      break; /*0x1ac038*/
  }
  return result; /*0x1abfd4*/
}
