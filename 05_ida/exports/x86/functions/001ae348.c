/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ae348. */
void __cdecl -[SCSIDisk logOpInfo:sense:](
        SCSIDisk *self,
        SEL a2,
        $BB0ECD142E749ABD0946980FC80D177E *a3,
        $55B996686E2E2C4974FEF7D53845AF12 *a4)
{
  unsigned __int16 v4; // dx
  int var0; // eax
  int v6; // edx
  int v7; // edx
  char *v8; // eax
  char v9[80]; // [esp+Ch] [ebp-78h] BYREF
  char __dst[40]; // [esp+5Ch] [ebp-28h] BYREF

  v9[0] = 0; /*0x1ae35a*/
  var0 = a3->var0; /*0x1ae35e*/
  switch ( a3->var0 ) /*0x1ae369*/
  {
    case 0: /*0x1ae369*/
      strcpy(__dst, "Read"); /*0x1ae38a*/
      goto LABEL_4; /*0x1ae396*/
    case 1: /*0x1ae369*/
      strcpy(__dst, "Write"); /*0x1ae39e*/
LABEL_4:
      if ( a4 && *(_BYTE *)a4 < 0 ) /*0x1ae3b3*/
      {
        LOBYTE(var0) = a4->var9; /*0x1ae3b5*/
        v6 = (a4->var10 << 16) | (var0 << 24) | v4; /*0x1ae3d0*/
        BYTE1(v6) = 0; /*0x1ae3d9*/
        v7 = (a4->var11 << 8) | v6; /*0x1ae3db*/
        LOBYTE(v7) = a4->var12; /*0x1ae3dd*/
        sprintf(v9, "block:%d", v7); /*0x1ae3ea*/
      }
      else
      {
        sprintf(v9, "block:%d blockCount:%d", a3->var1, a3->var2); /*0x1ae405*/
      }
      break; /*0x1ae3f2*/
    case 2: /*0x1ae369*/
    case 3: /*0x1ae369*/
      v8 = IOFindNameForValue(*((unsigned __int8 *)a3->var5 + 2), IOSCSIOpcodeStrings); /*0x1ae41d*/
      strcpy(__dst, v8); /*0x1ae427*/
      break; /*0x1ae42f*/
    case 4: /*0x1ae369*/
      strcpy(__dst, "Eject"); /*0x1ae43a*/
      break; /*0x1ae448*/
    default:
      panic("Bogus op in logOpInfo"); /*0x1ae451*/
      return; /*0x1ae451*/
  }
  IOLog((int)"   target:%d lun:%d op:%s %s\n", self->_target, self->_lun, __dst, v9); /*0x1ae476*/
}
