/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cd9a4. */
int __cdecl sub_1CD9A4(char *a1)
{
  int v2; // eax
  int v3; // eax
  int result; // eax

  while ( 2 ) /*0x1cd9b0*/
  {
    v2 = (char)(*a1++ - 40); /*0x1cd9b0*/
    switch ( v2 ) /*0x1cd9bd*/
    {
      case 0: /*0x1cd9bd*/
        v3 = sub_1CD92C(a1, 41); /*0x1cdb2b*/
        goto LABEL_7; /*0x1cdb2b*/
      case 38: /*0x1cd9bd*/
      case 39: /*0x1cd9bd*/
      case 46: /*0x1cd9bd*/
      case 54: /*0x1cd9bd*/
      case 70: /*0x1cd9bd*/
      case 71: /*0x1cd9bd*/
      case 74: /*0x1cd9bd*/
        continue;
      case 51: /*0x1cd9bd*/
        while ( (unsigned __int8)(*a1 - 48) <= 9u ) /*0x1cdb1b*/
          ++a1; /*0x1cdb14*/
        v3 = sub_1CD92C(a1, 93); /*0x1cdb1f*/
        goto LABEL_7; /*0x1cdb1f*/
      case 83: /*0x1cd9bd*/
        v3 = sub_1CD92C(a1, 125); /*0x1cdb26*/
LABEL_7:
        result = (int)&a1[v3 + 1]; /*0x1cdb30*/
        break; /*0x1cdb34*/
      default:
        result = (int)a1; /*0x1cdb38*/
        break; /*0x1cdb38*/
    }
    return result; /*0x1cdb3a*/
  }
}
