/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ae488. */
// local variable allocation has failed, the output may be wrong!
void __cdecl -[SCSIDisk genRwCdb:readFlag:block:blockCnt:](
        SCSIDisk *self,
        SEL a2,
        {cdb_6 *a3,
        cdb_6s a4,
        cdb_10 a5,
        cdb_12 a6)
{
  unsigned __int8 lun; // al

  lun = self->_lun; /*0x1ae4a3*/
  if ( a4.var0 ) /*0x1ae4a1*/
    *(_BYTE *)a3 = 40; /*0x1ae4b3*/
  else
    *(_BYTE *)a3 = 42; /*0x1ae4c8*/
  *((_BYTE *)a3 + 1) = (32 * lun) | *((_BYTE *)a3 + 1) & 0x1F; /*0x1ae4d7*/
  *((_BYTE *)a3 + 2) = *((_BYTE *)&a4 + 7); /*0x1ae4df*/
  *((_BYTE *)a3 + 3) = *((_BYTE *)&a4 + 6); /*0x1ae4e7*/
  *((_BYTE *)a3 + 4) = a4.var7; /*0x1ae4ef*/
  *((_BYTE *)a3 + 5) = a4.var6; /*0x1ae4f4*/
  *((_BYTE *)a3 + 7) = *((_BYTE *)&a5 + 1); /*0x1ae4fd*/
  *((_BYTE *)a3 + 8) = a5.var0; /*0x1ae503*/
}
